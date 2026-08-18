#!/usr/bin/env python3
"""
最小 ARM64→C 转译器 (阶段2 PoC).
输入: objdump 反汇编; 输出: 等价 C spec_fn (读写 cpu->regs[], 访存走 tlb).
支持 hash_bytes 用到的指令子集. 遇到不支持的指令 → 报错 (安全, 不静默出错).
"""
import re, sys

_ic_counter = [0]
def _next_ic_id():
    _ic_counter[0] += 1
    return _ic_counter[0]

# name → file-offset symbol map (optional). Loaded from a "name 0xoffset" file
# passed as argv[2]; used to resolve `X@plt` calls (and tail-call `b`s) to the
# real function body so the inline cache can hit a registered spec_fn. Symbols
# not in the map (e.g. libc frexp/__stack_chk_fail) fall through to prebuilt_call.
_symmap = {}
def _load_symmap(path):
    for ln in open(path):
        p = ln.split()
        if len(p) == 2:
            try: _symmap[p[0]] = int(p[1], 16)
            except ValueError: pass

def _resolve_plt(args_str):
    """If a branch target is `<name@plt>` or `<name>`, and `name` is in the
    symbol map, return the body's *file offset* (int); else None."""
    m = re.search(r'<([A-Za-z_][\w.]*?)(@plt)?>', args_str)
    if not m: return None
    return _symmap.get(m.group(1))

def reg(r):
    """x0/w0 → regs index; wzr/xzr → -1 (零寄存器)"""
    r = r.strip().rstrip(',')
    if r in ('xzr','wzr'): return -1
    if r in ('sp','wsp'): return 32   # sp 特殊
    m = re.match(r'[wx](\d+)', r)
    return int(m.group(1)) if m else None

def R(r):
    i = reg(r)
    if i == -1: return "0ULL"
    if i == 32: return "SP"
    return f"cpu->regs[{i}]"

def is_w(r):  # 32位寄存器?
    return r.strip().rstrip(',').startswith('w')

def w32(expr):  # 截断到32位
    return f"((uint32_t)({expr}))"

def freg(r):
    """s0/d0/q0 → float register index (a separate 32-entry file `fr[]`)."""
    r = r.strip().rstrip(',')
    m = re.match(r'[sdq](\d+)', r)
    return int(m.group(1)) if m else None

def FR(r):
    """Float register as a C lvalue. Single (s) vs double (d) handled at the op:
    values are stored as `double` in fr[]; the op width controls rounding."""
    i = freg(r)
    return f"fr[{i}]"

def is_s(r):  # single-precision (32-bit float) register?
    return r.strip().rstrip(',').startswith('s')

def translate(lines):
    _ic_counter[0] = 0
    out = []
    labels = {}   # addr → C label (only for IN-FUNCTION targets)
    body = []
    insns = []
    for ln in lines:
        m = re.match(r'\s*([0-9a-f]+):\s+[0-9a-f]+\s+(\S+)\s*(.*)', ln)
        if not m: continue
        addr, op, args = int(m.group(1),16), m.group(2), m.group(3).strip()
        insns.append((addr, op, args))
    # Function address range = [first insn, last insn + 4). A branch to a target
    # inside this range is a local jump (goto); a target OUTSIDE it is a tail
    # call to another function (set guest PC, return — the dispatch loop runs
    # the callee, which returns to our guest LR).
    lo = insns[0][0] if insns else 0
    hi = insns[-1][0] + 4 if insns else 0
    for addr, op, args in insns:
        bm = re.search(r'([0-9a-f]+)\s+<', args)
        if bm and (op.startswith('b') or op in ('cbz','cbnz','tbz','tbnz')):
            t = int(bm.group(1), 16)
            if lo <= t < hi:                 # only label in-function targets
                labels[t] = f"L_{bm.group(1)}"
    # Jump-table support: JUMPTABLE_TARGETS env = comma-separated in-function target
    # addresses (hex) that a computed `br` dispatches to. Force a label at each so
    # the dispatch can `goto` them. The emit() for the `br` idiom reads the same env
    # + JUMPTABLE_MAP to emit the switch. Resolving the table is done by the caller
    # (gen.sh reads the .rodata bytes); translate.py just needs the target labels.
    import os as _os
    _jt = _os.environ.get('JUMPTABLE_TARGETS', '')
    for _ts in _jt.split(','):
        _ts = _ts.strip()
        if not _ts: continue
        t = int(_ts, 16)
        if lo <= t < hi:
            labels[t] = f"L_{t:x}"

    # JUMPTABLE_SUPPRESS: comma-separated addresses whose instructions are dropped
    # (the jump-table-building prologue: adrp/add/ldrb/adr/add). With them gone the
    # index register stays intact for the switch emitted at the `br`.
    import os as _os2
    _suppress = set()
    for _s in _os2.environ.get('JUMPTABLE_SUPPRESS', '').split(','):
        _s = _s.strip()
        if _s: _suppress.add(int(_s, 16))

    for i, (addr, op, args) in enumerate(insns):
        if addr in labels:
            body.append(f"{labels[addr]}:")
        if addr in _suppress:
            continue
        # Strip objdump trailing "// ..." comments (e.g. "csel ..., ne  // ne = any")
        # so operands like the condition code aren't polluted. Branch targets use
        # the pre-comment hex + "<sym>" annotation, which this leaves intact.
        args_clean = args.split('//')[0].rstrip() if args else args
        a = [x.strip() for x in args_clean.split(',')] if args_clean else []
        next_pc = insns[i+1][0] if i+1 < len(insns) else addr+4  # for bl return addr
        c = emit(addr, op, a, labels, next_pc)
        if c is None:
            sys.stderr.write(f"UNSUPPORTED @ {addr:#x}: {op} {args}\n")
            return None
        body.append("    " + c if not c.endswith(":") else c)
    return body

def emit(addr, op, a, labels, next_pc=None):
    """一条指令 → C 语句 (或 None=不支持)"""
    # ldur/stur are unscaled-offset ldr/str; identical semantics here. ldar/stlr
    # (load-acquire / store-release) and ldapr act as plain ldr/str in our model —
    # iSH issues real host barriers separately (gadget_dmb), so ordering is handled.
    _unscaled = {'ldur':'ldr','stur':'str','ldurb':'ldrb','sturb':'strb',
                 'ldurh':'ldrh','sturh':'strh',
                 'ldar':'ldr','stlr':'str','ldapr':'ldr','ldar':'ldr',
                 'ldarb':'ldrb','stlrb':'strb','ldarh':'ldrh','stlrh':'strh'}
    op = _unscaled.get(op, op)
    def branch_to(tgt_hex, args_str=""):
        """In-function target → 'goto L_x'; out-of-function → tail call.
        A tail-call `b` to a *known* function body becomes an inline-cache call
        (stay in host) followed by return: same net effect as jumping there and
        letting it return to our caller, but without leaving host code."""
        t = int(tgt_hex, 16)
        if t in labels:
            return f"goto L_{tgt_hex}"
        body = _resolve_plt(args_str)
        dst = f"0x{body:x}" if body is not None else f"0x{tgt_hex}"
        ic = _next_ic_id()
        return (f"{{ PB_CALL({ic}, cpu, tlb, PB_BASE + {dst}ULL); return; }}")
    # 立即数
    def imm(s):
        s = s.strip().lstrip('#')
        s = s.split()[0].split('//')[0].strip()  # 去注释
        return int(s, 0)
    # AArch64 condition codes → C flag macros (defined in the generated spec).
    COND = {'eq':'FLAG_EQ','ne':'FLAG_NE','gt':'FLAG_GT','le':'FLAG_LE',
            'ge':'FLAG_GE','lt':'FLAG_LT','hi':'FLAG_HI','lo':'FLAG_LO',
            'hs':'FLAG_HS','ls':'FLAG_LS','cs':'FLAG_HS','cc':'FLAG_LO',
            # N flag (sign of result): after subs/adds we FLAG_CMP(result, 0), so
            # mi (negative) == signed <, pl (non-negative) == signed >=.
            'mi':'FLAG_LT','pl':'FLAG_GE'}
    # ── adrp xD, <target>  (PC-relative page address of a global) ──
    #   objdump prints the file-absolute target; at runtime it's PB_BASE +
    #   that target (PB_BASE = library load base, set in the generated spec).
    if op == 'adrp' and len(a) == 2:
        # objdump prints the target as a bare hex ("2b4000") or "0x2b4000".
        tgt = re.match(r'(?:0x)?([0-9a-f]+)', a[1].split()[0])
        if tgt:
            return f"{R(a[0])} = PB_BASE + 0x{tgt.group(1)}ULL;"
    # ── adr xD, <target>  (PC-relative byte address) ──
    if op == 'adr' and len(a) == 2:
        tgt = re.match(r'(?:0x)?([0-9a-f]+)', a[1].split()[0])
        if tgt:
            return f"{R(a[0])} = PB_BASE + 0x{tgt.group(1)}ULL;"
    # ── 符号/零扩展 sxtw/sxth/sxtb, uxtw/uxth/uxtb ──
    if op in ('sxtw','sxth','sxtb','uxtw','uxth','uxtb') and len(a)==2:
        bits={'w':32,'h':16,'b':8}[op[3]]
        src=R(a[1])
        if op[0]=='s':
            res=f"((uint64_t)(int64_t)(int{bits}_t)({src}))"
        else:
            mask=(1<<bits)-1
            res=f"(({src}) & 0x{mask:x}ULL)"
        return f"{R(a[0])} = {res};"
    # ── mov / movz / movk ──
    if op == 'mov' and len(a)==2:
        if a[1].startswith('#'):
            return f"{R(a[0])} = {imm(a[1])}ULL;"
        return f"{R(a[0])} = {R(a[1])};"
    # ── neg rd, rm  (= -rm)  and  mvn rd, rm  (= ~rm) ──
    if op == 'neg' and len(a)==2:
        e = f"(uint64_t)(-(int64_t){R(a[1])})"
        return f"{R(a[0])} = {w32(e) if is_w(a[0]) else e};"
    if op == 'mvn' and len(a)==2:
        e = f"(~{R(a[1])})"
        return f"{R(a[0])} = {w32(e) if is_w(a[0]) else e};"
    # ── negs rd, rm  (= -rm, sets flags) ──
    if op == 'negs' and len(a)==2:
        return f"{R(a[0])} = (uint64_t)(-(int64_t){R(a[1])}); FLAG_CMP({R(a[0])}, 0);"
    if op == 'movk' and len(a)>=2:
        # movk xD, #imm, lsl #sh
        sh = 0
        m = re.search(r'lsl\s*#(\d+)', args_join(a))
        val = imm(a[1])
        shm = re.search(r'#(\d+)', a[2]) if len(a)>2 else None
        if shm: sh = int(shm.group(1))
        return f"{R(a[0])} = ({R(a[0])} & ~(0xffffULL << {sh})) | ((0x{val:x}ULL & 0xffff) << {sh});"
    # ── 算术. The *s forms (adds/subs/ands) also set flags; bic clears bits.
    #    Shifted register operand supported (e.g. eor x0,x0,x0,lsr #31). ──
    ARI = {'add':'+','sub':'-','eor':'^','orr':'|','and':'&','mul':'*',
           'adds':'+','subs':'-','ands':'&','bic':'&~','eon':'^~','bics':'&~'}
    if op in ARI and len(a) in (3,4):
        cop = ARI[op]
        if a[2].startswith('#'):
            rhs = f"{imm(a[2])}ULL"
        else:
            rhs = R(a[2])
        if len(a) == 4:                       # shifted or extended register operand
            sm = re.match(r'(lsl|lsr|asr|ror)\s*#(\d+)', a[3])
            em = re.match(r'(uxtw|sxtw|uxtx|sxtx|uxtb|sxtb|uxth|sxth)(?:\s*#(\d+))?', a[3])
            if sm:
                sop, sh = sm.group(1), int(sm.group(2))
                if sop == 'lsl': rhs = f"({rhs} << {sh})"
                elif sop == 'lsr': rhs = f"({rhs} >> {sh})"
                elif sop == 'ror': rhs = f"ror64({rhs}, {sh})"
                else: rhs = f"((uint64_t)((int64_t){rhs} >> {sh}))"
            elif em:                          # extend: {u,s}xt{b,h,w,x} #shift
                ext, sh = em.group(1), int(em.group(2)) if em.group(2) else 0
                bits = {'b':8,'h':16,'w':32,'x':64}[ext[3]]
                if ext[0]=='s' and bits<64: rhs = f"((uint64_t)(int64_t)(int{bits}_t)({rhs}))"
                elif bits<64:               rhs = f"(({rhs}) & 0x{(1<<bits)-1:x}ULL)"
                if sh: rhs = f"({rhs} << {sh})"
            else: return None
        if cop == '&~': expr = f"{R(a[1])} & ~({rhs})"
        elif cop == '^~': expr = f"{R(a[1])} ^ ~({rhs})"
        else: expr = f"{R(a[1])} {cop} {rhs}"
        if is_w(a[0]): expr = w32(expr)
        # Writing to the zero register (xzr/wzr) discards the result — only the
        # flags matter (e.g. `ands wzr, x, y` == `tst`; `bics xzr,...`). Emit the
        # flag compare against the computed value directly, no assignment.
        if reg(a[0]) == -1:
            if op in ('adds','subs','ands','bics'):
                return f"FLAG_CMP({w32(expr) if is_w(a[0]) else expr}, 0);"
            return "/* result discarded to xzr */"
        code = f"{R(a[0])} = {expr};"
        if op in ('adds','subs','ands','bics'):  # set flags from the result
            code += f" FLAG_CMP({R(a[0])}, 0);"
        return code
    # ── ror ──
    if op == 'ror' and len(a)==3:
        sh = imm(a[2])
        return f"{R(a[0])} = ror64({R(a[1])}, {sh});"
    # ── lsl / lsr / asr  (register or immediate shift) ──
    if op in ('lsl','lsr','asr') and len(a)==3:
        n = R(a[1])
        amt = f"{imm(a[2])}" if a[2].startswith('#') else f"({R(a[2])} & 63)"
        if op == 'lsl': res = f"{n} << {amt}"
        elif op == 'lsr': res = f"{n} >> {amt}"           # logical (unsigned)
        else: res = f"(uint64_t)((int64_t){n} >> {amt})"  # arithmetic
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── csel wD, wN, wM/wzr, cond  (D = cond ? N : M) ──
    if op == 'csel' and len(a)==4:
        cnd = a[3]
        if cnd not in COND: return None
        return f"{R(a[0])} = ({COND[cnd]}) ? {R(a[1])} : {R(a[2])};"
    # ── csinc wD, wN, wM, cond  (D = cond ? N : M+1) ──
    if op == 'csinc' and len(a)==4:
        cnd = a[3]
        if cnd not in COND: return None
        return f"{R(a[0])} = ({COND[cnd]}) ? {R(a[1])} : ({R(a[2])} + 1);"
    # ── csinv wD, wN, wM, cond  (D = cond ? N : ~M) ──
    if op == 'csinv' and len(a)==4 and a[3] in COND:
        res = f"({COND[a[3]]}) ? {R(a[1])} : (~{R(a[2])})"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── csneg wD, wN, wM, cond  (D = cond ? N : -M) ──
    if op == 'csneg' and len(a)==4 and a[3] in COND:
        res = f"({COND[a[3]]}) ? {R(a[1])} : ((uint64_t)(-(int64_t){R(a[2])}))"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── madd rd,rn,rm,ra = rn*rm+ra ──
    if op == 'madd' and len(a)==4:
        return f"{R(a[0])} = {R(a[1])} * {R(a[2])} + {R(a[3])};"
    # ── msub rd,rn,rm,ra = ra - rn*rm ──
    if op == 'msub' and len(a)==4:
        expr = f"{R(a[3])} - {R(a[1])} * {R(a[2])}"
        if is_w(a[0]): expr = w32(expr)
        return f"{R(a[0])} = {expr};"
    # ── umaddl xD, wN, wM, xA = xA + (uint32)wN * (uint32)wM ──
    if op == 'umaddl' and len(a)==4:
        return f"{R(a[0])} = {R(a[3])} + (uint64_t)(uint32_t){R(a[1])} * (uint64_t)(uint32_t){R(a[2])};"
    # ── umsubl xD, wN, wM, xA = xA - (uint32)wN * (uint32)wM ──
    if op == 'umsubl' and len(a)==4:
        return f"{R(a[0])} = {R(a[3])} - (uint64_t)(uint32_t){R(a[1])} * (uint64_t)(uint32_t){R(a[2])};"
    # ── smaddl xD, wN, wM, xA = xA + (int32)wN * (int32)wM ──
    if op == 'smaddl' and len(a)==4:
        return f"{R(a[0])} = {R(a[3])} + (uint64_t)((int64_t)(int32_t){R(a[1])} * (int64_t)(int32_t){R(a[2])});"
    # ── umull xD, wN, wM = (uint32)wN * (uint32)wM  (alias umaddl ...,xzr) ──
    if op == 'umull' and len(a)==3:
        return f"{R(a[0])} = (uint64_t)(uint32_t){R(a[1])} * (uint64_t)(uint32_t){R(a[2])};"
    if op == 'smull' and len(a)==3:
        return f"{R(a[0])} = (uint64_t)((int64_t)(int32_t){R(a[1])} * (int64_t)(int32_t){R(a[2])});"
    # ── umulh/smulh xD, xN, xM = high 64 bits of 128-bit product ──
    if op == 'umulh' and len(a)==3:
        return f"{R(a[0])} = (uint64_t)(((unsigned __int128){R(a[1])} * (unsigned __int128){R(a[2])}) >> 64);"
    if op == 'smulh' and len(a)==3:
        return f"{R(a[0])} = (uint64_t)(((__int128)(int64_t){R(a[1])} * (__int128)(int64_t){R(a[2])}) >> 64);"
    # ── sdiv/udiv rd,rn,rm  (div-by-zero → 0, per AArch64) ──
    if op == 'udiv' and len(a)==3:
        d = R(a[2]); e = f"({d} ? {R(a[1])} / {d} : 0)"
        return f"{R(a[0])} = {w32(e) if is_w(a[0]) else e};"
    if op == 'sdiv' and len(a)==3:
        d = R(a[2])
        e = f"({d} ? (uint64_t)((int64_t){R(a[1])} / (int64_t){d}) : 0)"
        return f"{R(a[0])} = {w32(e) if is_w(a[0]) else e};"
    # ── sbfiz wD, wN, #lsb, #width  (signed bitfield insert in zero) ──
    #   Wd = sign_extend(Wn[0+:width]) << lsb  (width bits, then shifted)
    if op == 'sbfiz' and len(a)==4:
        lsb, width = imm(a[2]), imm(a[3])
        sh = 64 - width
        field = f"((uint64_t)(((int64_t)({R(a[1])} << {sh})) >> {sh}) & 0x{(1<<width)-1:x}ULL)"
        res = f"({field} << {lsb})"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── cinc wD, wN, cond  (D = cond ? N+1 : N) ──
    if op == 'cinc' and len(a)==3 and a[2] in COND:
        res = f"({COND[a[2]]}) ? ({R(a[1])} + 1) : {R(a[1])}"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── cneg wD, wN, cond  (D = cond ? -N : N) ──
    if op == 'cneg' and len(a)==3 and a[2] in COND:
        res = f"({COND[a[2]]}) ? ((uint64_t)(-(int64_t){R(a[1])})) : {R(a[1])}"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── cinv wD, wN, cond  (D = cond ? ~N : N) ──
    if op == 'cinv' and len(a)==3 and a[2] in COND:
        res = f"({COND[a[2]]}) ? (~{R(a[1])}) : {R(a[1])}"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── ldrb/strb (byte) and ldrh/strh (halfword). Two forms: [Xn, Xm{,lsl#s}]
    #    (register offset, e.g. table lookup) and [Xn, #imm] (imm / pre / post). ──
    if op in ('ldrb','strb','ldrh','strh'):
        ld  = op.startswith('ldr')
        LD, ST = ('PB_LDRB','PB_STRB') if op[-1]=='b' else ('PB_LDRH','PB_STRH')
        m = re.match(r'\[(\w+),\s*([wx]\w+)(?:,\s*(lsl|uxtw|sxtw|uxtx|sxtx)\s*#?(\d+)?)?\]', args_join(a[1:]))
        if m:
            base = R(m.group(1)); ext = m.group(3); sh = int(m.group(4)) if m.group(4) else 0
            raw = R(m.group(2))
            if ext == 'sxtw':   idx = f"((uint64_t)(int64_t)(int32_t)({raw}))"
            elif ext == 'uxtw': idx = f"((uint64_t)(uint32_t)({raw}))"
            else:               idx = raw
            ea = f"({base} + ({idx} << {sh}))" if sh else f"({base} + {idx})"
            return f"{LD}({R(a[0])}, {ea});" if ld else f"{ST}({ea}, {R(a[0])});"
        r = _memop(a[1:])
        if r:
            base, off, pre, post = r
            code = f"{base} += {off}; " if pre else ""
            ea = base if (pre or post) else f"({base} + {off})"
            code += (f"{LD}({R(a[0])}, {ea});" if ld else f"{ST}({ea}, {R(a[0])});")
            if post: code += f" {base} += {off};"
            return code
    # ── ldr/str Xt/Wt, [Xn, Rm{, lsl|sxtw|uxtw #sh}]  (register-offset) ──
    #   The index may be a 64-bit reg (lsl) or a 32-bit reg sign/zero-extended
    #   (sxtw/uxtw) — common for array[i] with a 32-bit i. Build the byte offset
    #   with the correct extend before scaling.
    # Vector-register ldr/str (q/v/s/d/h/b regs) are SIMD — not yet modeled. Bail
    # to UNSUPPORTED instead of emitting regs[None] (silent miscompile).
    if op in ('ldr','str','ldur','stur') and a and re.match(r'[qvsdhb]\d', a[0].strip()):
        return None
    if op in ('ldr','str') and len(a) >= 2:
        mem = args_join(a[1:]).strip()
        m = re.match(r'\[(\w+),\s*(\w+)(?:,\s*(lsl|sxtw|uxtw|sxtx|uxtx)\s*#?(\d+)?)?\]', mem)
        if m and not m.group(2).startswith('#'):
            base = R(m.group(1)); ext = m.group(3); sh = int(m.group(4)) if m.group(4) else 0
            raw = R(m.group(2))
            if ext == 'sxtw':   idx = f"((uint64_t)(int64_t)(int32_t)({raw}))"
            elif ext == 'uxtw': idx = f"((uint64_t)(uint32_t)({raw}))"
            else:               idx = raw                      # lsl / sxtx / uxtx / none
            ea = f"({base} + ({idx} << {sh}))" if sh else f"({base} + {idx})"
            w = is_w(a[0])
            if op == 'ldr': return (f"PB_LDRW({R(a[0])}, {ea});" if w
                                    else f"PB_LDR({R(a[0])}, {ea});")
            else:           return (f"PB_STRW({ea}, {R(a[0])});" if w
                                    else f"PB_STR({ea}, {R(a[0])});")
    # ── ldr/str Xt/Wt, [Xn, #imm]   (64/32-bit load/store via TLB) ──
    #    Also handles the stack-frame stp/ldp below. mem is the guest address
    #    space; sp lives in cpu->sp (index 32 → "SP").
    if op in ('ldr','str') and len(a) >= 2:
        r = _memop(a[1:])
        if r:
            base, off, wb_pre, wb_post = r
            code = ""
            if wb_pre: code += f"{base} += {off}; "
            ea = base if (wb_pre or wb_post) else f"({base} + {off})"
            w = is_w(a[0])                      # 32-bit access?
            if op == 'ldr': code += (f"PB_LDRW({R(a[0])}, {ea});" if w
                                     else f"PB_LDR({R(a[0])}, {ea});")
            else:           code += (f"PB_STRW({ea}, {R(a[0])});" if w
                                     else f"PB_STR({ea}, {R(a[0])});")
            if wb_post: code += f" {base} += {off};"
            return code
    # ── stp/ldp Wt1/Xt1, Wt2/Xt2, [Xn, #imm]  (pair load/store; pre/post-index).
    #   Element size follows the register width: w-regs = 4-byte elements (second
    #   at +4), x-regs = 8-byte (second at +8). Using the wrong width silently
    #   corrupts adjacent fields (observed: ldp w3,w4 read as two 8-byte loads). ──
    if op in ('stp','ldp') and len(a) >= 3:
        # Vector-register pairs (ldp/stp q0,q1,...) are SIMD — bail, don't emit regs[None].
        if re.match(r'[qvsdhb]\d', a[0].strip()) or re.match(r'[qvsdhb]\d', a[1].strip()):
            return None
        r = _memop(a[2:])
        if r:
            base, off, wb_pre, wb_post = r
            code = ""
            if wb_pre: code += f"{base} += {off}; "
            ea = base if (wb_pre or wb_post) else f"({base} + {off})"
            w = is_w(a[0])                       # 32-bit pair?
            esz = 4 if w else 8
            LD, ST = ('PB_LDRW','PB_STRW') if w else ('PB_LDR','PB_STR')
            if op == 'ldp':
                code += f"{LD}({R(a[0])}, {ea}); {LD}({R(a[1])}, {ea} + {esz});"
            else:
                code += f"{ST}({ea}, {R(a[0])}); {ST}({ea} + {esz}, {R(a[1])});"
            if wb_post: code += f" {base} += {off};"
            return code
    # ── cmp (设 flag). Store both signed+unsigned operands so all conditions
    #    resolve correctly. w-regs zero-extend (unsigned 32-bit compare). ──
    if op == 'cmp' and len(a) >= 2:
        # cmp Rn, #imm[, lsl #sh]   or   cmp Rn, Rm
        if a[1].startswith('#'):
            v = imm(a[1])
            if len(a) >= 3:                       # optional  lsl #sh
                shm = re.search(r'lsl\s*#(\d+)', args_join(a[2:]))
                if shm: v <<= int(shm.group(1))
            rhs = f"{v}ULL"
        else:
            rhs = R(a[1])
        lhs = R(a[0])
        if is_w(a[0]): lhs, rhs = w32(lhs), w32(rhs)
        return f"FLAG_CMP({lhs}, {rhs});"
    # ── cmn Rn, #imm  (compare negative: flags of Rn + imm) ──
    if op == 'cmn' and len(a) == 2:
        rhs = f"{imm(a[1])}ULL" if a[1].startswith('#') else R(a[1])
        lhs = R(a[0])
        # Z/N of (lhs + rhs): model as compare of lhs against -rhs.
        return f"FLAG_CMP({lhs}, (uint64_t)(-(int64_t)({rhs})));"
    # ── tst Rn, Rm/#imm  (flags of Rn & op2; only Z/N meaningful) ──
    if op == 'tst' and len(a) >= 2:
        rhs = f"{imm(a[1])}ULL" if a[1].startswith('#') else R(a[1])
        lhs = R(a[0])
        if is_w(a[0]): lhs, rhs = w32(lhs), w32(rhs)
        return f"FLAG_CMP(({lhs}) & ({rhs}), 0);"
    # ── 条件分支 b.<cond> ──
    if op.startswith('b.') and op[2:] in COND:
        tgt = re.search(r'([0-9a-f]+)\s+<', args_join(a))
        if tgt: return f"if ({COND[op[2:]]}) " + branch_to(tgt.group(1), args_join(a)) + ";"
    # ── tbnz/tbz Rn, #bit, tgt  (test single bit and branch) ──
    if op in ('tbnz','tbz') and len(a) >= 3:
        bit = imm(a[1])
        tgt = re.search(r'([0-9a-f]+)\s+<', args_join(a[2:]))
        if tgt:
            cond = f"(({R(a[0])} >> {bit}) & 1)"
            if op == 'tbz': cond = f"!{cond}"
            return f"if ({cond}) " + branch_to(tgt.group(1), args_join(a)) + ";"
    # ── cset wD, <cond> (D = cond ? 1 : 0) ──
    if op == 'cset' and len(a)==2 and a[1] in COND:
        return f"{R(a[0])} = ({COND[a[1]]}) ? 1 : 0;"
    # ── csetm wD, <cond> (D = cond ? all-ones-mask : 0) ──
    if op == 'csetm' and len(a)==2 and a[1] in COND:
        mask = "0xffffffffULL" if is_w(a[0]) else "0xffffffffffffffffULL"
        return f"{R(a[0])} = ({COND[a[1]]}) ? {mask} : 0;"
    # ── ubfx/ubfiz  (unsigned bitfield extract / insert-in-zero) ──
    #   ubfx Wd, Wn, #lsb, #width  → Wd = (Wn >> lsb) & ((1<<width)-1)
    #   ubfiz Wd, Wn, #lsb, #width → Wd = (Wn & ((1<<width)-1)) << lsb
    if op in ('ubfx','ubfiz') and len(a) == 4:
        lsb, width = imm(a[2]), imm(a[3])
        mask = (1 << width) - 1
        if op == 'ubfx':
            res = f"(({R(a[1])} >> {lsb}) & 0x{mask:x}ULL)"
        else:
            res = f"(({R(a[1])} & 0x{mask:x}ULL) << {lsb})"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── sbfx Wd, Wn, #lsb, #width  (signed bitfield extract) ──
    if op == 'sbfx' and len(a) == 4:
        lsb, width = imm(a[2]), imm(a[3])
        # sign-extend the width-bit field
        sh = 64 - width
        res = f"((uint64_t)(((int64_t)({R(a[1])} << ({sh}-{lsb})) ) >> {sh}))"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── bfxil Wd, Wn, #lsb, #width  (insert Wn[lsb+:width] into Wd low bits) ──
    if op == 'bfxil' and len(a) == 4:
        lsb, width = imm(a[2]), imm(a[3])
        mask = (1 << width) - 1
        field = f"(({R(a[1])} >> {lsb}) & 0x{mask:x}ULL)"
        res = f"(({R(a[0])} & ~0x{mask:x}ULL) | {field})"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── bfi Wd, Wn, #lsb, #width  (insert Wn[0+:width] into Wd[lsb+:width]) ──
    if op == 'bfi' and len(a) == 4:
        lsb, width = imm(a[2]), imm(a[3])
        mask = (1 << width) - 1
        field = f"(({R(a[1])} & 0x{mask:x}ULL) << {lsb})"
        res = f"(({R(a[0])} & ~(0x{mask:x}ULL << {lsb})) | {field})"
        if is_w(a[0]): res = w32(res)
        return f"{R(a[0])} = {res};"
    # ── lsl/lsr by immediate can appear as ubfm; handled via lsl/lsr above ──
    if op == 'cbz' and len(a)>=2:
        tgt = re.search(r'([0-9a-f]+)\s+<', args_join(a))
        v = w32(R(a[0])) if is_w(a[0]) else R(a[0])
        if tgt: return f"if (({v})==0) " + branch_to(tgt.group(1), args_join(a)) + ";"
    if op == 'cbnz' and len(a)>=2:
        tgt = re.search(r'([0-9a-f]+)\s+<', args_join(a))
        v = w32(R(a[0])) if is_w(a[0]) else R(a[0])
        if tgt: return f"if (({v})!=0) " + branch_to(tgt.group(1), args_join(a)) + ";"
    if op == 'b':
        tgt = re.search(r'([0-9a-f]+)\s+<', args_join(a))
        if tgt: return branch_to(tgt.group(1), args_join(a)) + ";"
    # ── bl <target>  (direct call). PB_CALL does inline-cache dispatch: if the
    #   callee has a translated spec_fn, call it directly (stays in host code,
    #   no interpreter round-trip); otherwise fall back to prebuilt_call (nested
    #   dispatch). Each call site gets its own static IC slot (unique id). ──
    if op == 'bl':
        tgt = re.search(r'([0-9a-f]+)\s+<', args_join(a))
        if tgt and next_pc is not None:
            ic = _next_ic_id()
            # Prefer the real body offset when the target is a PLT stub whose
            # symbol we know; else use the literal branch target. Both become
            # PB_BASE + offset, so the IC keys on the *body* address we register.
            body = _resolve_plt(args_join(a))
            dst = f"0x{body:x}" if body is not None else f"0x{tgt.group(1)}"
            return (f"cpu->regs[30] = PB_BASE + 0x{next_pc:x}ULL; "
                    f"PB_CALL({ic}, cpu, tlb, PB_BASE + {dst}ULL);")
    # ── blr xN  (indirect call). Target is a runtime register value. Inline
    #    cache is most valuable here: the target is usually monomorphic (e.g. a
    #    fixed allocator hook), so the IC hits ~always and skips the interpreter. ──
    if op == 'blr' and len(a) == 1 and next_pc is not None:
        ic = _next_ic_id()
        return (f"cpu->regs[30] = PB_BASE + 0x{next_pc:x}ULL; "
                f"PB_CALL({ic}, cpu, tlb, {R(a[0])});")
    # ── br xN  (indirect branch = tail call; does not return here) ──
    #   Set guest PC to the target and return from the spec_fn; the dispatch
    #   loop continues at the target (gadget_prebuilt_entry will NOT overwrite
    #   PC with LR because we set it explicitly). We emulate this by pointing
    #   cpu->regs[30] (which the trampoline copies to PC on return) at the tgt.
    if op == 'br' and len(a) == 1:
        # Jump-table dispatch: JUMPTABLE_MAP = "idxreg;key0:tgt0,key1:tgt1,...,default:tgtd"
        # where idxreg is the guest reg holding the switch index (e.g. "0" for x0) and
        # each tgt is an in-function address (labeled above). Emit a real C switch so
        # the whole function stays in host code, instead of the (wrong for intra-
        # function tables) tail-call that clobbers LR.
        import os as _os
        jm = _os.environ.get('JUMPTABLE_MAP', '')
        if jm:
            idxreg, _, rest = jm.partition(';')
            cases = []
            default = None
            for pair in rest.split(','):
                k, _, v = pair.partition(':')
                k = k.strip(); v = v.strip()
                if k == 'default': default = int(v, 16)
                elif k: cases.append((int(k, 0), int(v, 16)))
            lines = [f"switch ((uint32_t)(cpu->regs[{idxreg}])) {{"]
            for k, t in cases:
                lines.append(f"    case {k}: goto L_{t:x};")
            if default is not None:
                lines.append(f"    default: goto L_{default:x};")
            lines.append("}")
            return "\n    ".join(lines)
        # Indirect `br xN` = tail call to regs[N]. The callee returns to the
        # CURRENT guest LR (regs[30], set up by the caller of this function).
        # Running it via prebuilt_call preserves that: it executes regs[N] to
        # completion (result in regs[0]) and returns here; we then `return` so
        # prebuilt_entry resumes at the real LR. Setting regs[30]=regs[N] would
        # WRONGLY clobber the return address → callee's ret loops on itself.
        return f"prebuilt_call(cpu, tlb, {R(a[0])}); return;"
    # ── ret ──
    if op == 'ret':
        return "return;"
    # ── ldrsb/ldrsh/ldrsw: sign-extended loads (reg offset may use lsl/uxtw/sxtw) ──
    if op in ('ldrsb','ldrsh','ldrsw'):
        sz = {'ldrsb':(1,'int8_t'),'ldrsh':(2,'int16_t'),'ldrsw':(4,'int32_t')}[op]
        n, ct = sz
        s = args_join(a[1:]).strip()
        # immediate-offset form: [Xn, #imm]  or  [Xn]
        im = re.match(r'\[(\w+)(?:,\s*#(-?\w+))?\]$', s)
        if im:
            base = R(im.group(1)); off = int(im.group(2), 0) if im.group(2) else 0
            ea = f"({base} + {off})" if off else base
            return (f"do {{ {ct} _s=0; tlb_read(tlb,{ea},&_s,{n}); "
                    f"{R(a[0])} = (uint64_t)(int64_t)_s; }} while(0);")
        # register-offset form: [Xn, Rm{, lsl|uxtw|sxtw #sh}]
        m = re.match(r'\[(\w+),\s*(\w+)(?:,\s*(lsl|uxtw|sxtw|uxtx|sxtx)\s*#?(\d+)?)?\]', s)
        if m and not m.group(2).startswith('#'):
            base = R(m.group(1)); ext = m.group(3); sh = int(m.group(4)) if m.group(4) else 0
            raw = R(m.group(2))
            if ext == 'sxtw':   idx = f"((uint64_t)(int64_t)(int32_t)({raw}))"
            elif ext == 'uxtw': idx = f"((uint64_t)(uint32_t)({raw}))"
            else:               idx = raw
            ea = f"({base} + ({idx} << {sh}))" if sh else f"({base} + {idx})"
            return (f"do {{ {ct} _s=0; tlb_read(tlb,{ea},&_s,{n}); "
                    f"{R(a[0])} = (uint64_t)(int64_t)_s; }} while(0);")
    # ── ccmp Rn, Rm/#imm, #nzcv, cond  (conditional compare) ──
    #   If cond holds, set flags from (Rn - op2); else set flags to #nzcv.
    #   FLAG_CMP(g_fa,g_fb) models Z (eq/ne) and C (unsigned hi/ls/lo/hs) — the
    #   only bits our downstream conditions read. Pick (g_fa,g_fb) to reproduce
    #   the nzcv fallback's C (bit1) and Z (bit2):
    #     Z=1        → (0,0): eq, hs, ls        (C set, as a real equal compare)
    #     Z=0, C=1   → (1,0): ne, hi, hs
    #     Z=0, C=0   → (0,1): ne, lo, ls
    if op == 'ccmp' and len(a) == 4 and a[3] in COND:
        rhs = f"{imm(a[1])}ULL" if a[1].startswith('#') else R(a[1])
        nzcv = imm(a[2])
        Z = bool(nzcv & 0x4); C = bool(nzcv & 0x2)
        pair = "0, 0" if Z else ("1, 0" if C else "0, 1")
        return (f"if ({COND[a[3]]}) {{ FLAG_CMP({R(a[0])}, {rhs}); }} "
                f"else {{ FLAG_CMP({pair}); }}")
    # ── mrs/msr TPIDR_EL0: guest thread-local storage pointer (cpu->tls_ptr) ──
    #   objdump prints the sysreg name lowercase ("tpidr_el0"); match case-insensitively.
    if op == 'mrs' and len(a) == 2 and 'tpidr_el0' in a[1].lower():
        return f"{R(a[0])} = cpu->tls_ptr;"
    if op == 'msr' and len(a) == 2 and 'tpidr_el0' in a[0].lower():
        return f"cpu->tls_ptr = {R(a[1])};"
    # ── ccmn Rn, #imm/Rm, #nzcv, cond  (conditional compare negative = cmp vs -op2) ──
    if op == 'ccmn' and len(a) == 4 and a[3] in COND:
        rhs = f"(-(int64_t){imm(a[1])}LL)" if a[1].startswith('#') else f"(-(int64_t){R(a[1])})"
        nzcv = imm(a[2])
        Z = bool(nzcv & 0x4); C = bool(nzcv & 0x2)
        pair = "0, 0" if Z else ("1, 0" if C else "0, 1")
        return (f"if ({COND[a[3]]}) {{ FLAG_CMP({R(a[0])}, (uint64_t){rhs}); }} "
                f"else {{ FLAG_CMP({pair}); }}")
    # ── clz rd, rn  (count leading zeros; width from register) ──
    if op == 'clz' and len(a) == 2:
        bits = 32 if is_w(a[0]) else 64
        src = w32(R(a[1])) if is_w(a[0]) else R(a[1])
        z = f"((uint{bits}_t)({src}))"
        return (f"{R(a[0])} = ({z} == 0) ? {bits} : "
                f"(uint64_t)__builtin_clz{'ll' if bits==64 else ''}({z});")
    # ── rev / rev16 / rev32  (byte reverse) ──
    if op in ('rev','rev32') and len(a) == 2:
        if is_w(a[0]):
            return f"{R(a[0])} = (uint64_t)__builtin_bswap32((uint32_t){R(a[1])});"
        return f"{R(a[0])} = __builtin_bswap64({R(a[1])});"
    if op == 'rev16' and len(a) == 2:
        # swap bytes within each 16-bit halfword
        return (f"{R(a[0])} = ({R(a[1])} & 0xff00ff00ff00ff00ULL) >> 8 | "
                f"({R(a[1])} & 0x00ff00ff00ff00ffULL) << 8;")
    # ── ldpsw xt1, xt2, [xn, #imm]  (load pair of 32-bit, sign-extend to 64) ──
    if op == 'ldpsw' and len(a) >= 3:
        s = args_join(a[2:]).strip()
        im = re.match(r'\[(\w+)(?:,\s*#(-?\w+))?\]', s)
        if im:
            base = R(im.group(1)); off = int(im.group(2), 0) if im.group(2) else 0
            e1 = f"({base} + {off})" if off else base
            e2 = f"({base} + {off+4})"
            return (f"do {{ int32_t _a=0,_b=0; tlb_read(tlb,{e1},&_a,4); "
                    f"tlb_read(tlb,{e2},&_b,4); {R(a[0])}=(uint64_t)(int64_t)_a; "
                    f"{R(a[1])}=(uint64_t)(int64_t)_b; }} while(0);")
    # ── brk: breakpoint / unreachable (abort path). Real code only reaches it
    #    on an assertion failure; emit a trap so any surprise is loud, not silent.
    if op == 'brk':
        return "__builtin_trap();"
    if op == 'nop':
        return "/* nop */"
    # ── Minimal floating-point (single/double) support ──
    #   Values live in a `double fr[32]` file. Enough for the hashtable load-
    #   factor idiom: ucvtf (int→float), fmov #imm, fdiv, fcmpe/fcmp.
    #   ucvtf sD, wN / xN  — unsigned int → float
    if op in ('ucvtf','scvtf') and len(a) == 2 and freg(a[0]) is not None:
        src = R(a[1])
        cast = "(double)" if op == 'ucvtf' else "(double)(int64_t)"
        v = w32(src) if is_w(a[1]) else src
        if op == 'ucvtf' and is_w(a[1]): v = f"(uint32_t)({src})"
        return f"{FR(a[0])} = {cast}({v});"
    #   fmov sD, #imm   (immediate float constant, e.g. #0.5)
    if op == 'fmov' and len(a) == 2 and freg(a[0]) is not None and a[1].startswith('#'):
        return f"{FR(a[0])} = {float(a[1].lstrip('#'))};"
    #   fmov sD, wN  /  fmov xD, sN  (bit-reinterpret int<->float register)
    if op == 'fmov' and len(a) == 2 and freg(a[0]) is not None and freg(a[1]) is None:
        return f"{FR(a[0])} = (double)({R(a[1])});"   # value move (not bitcast) — only used post-cvt
    #   fdiv / fmul / fadd / fsub  sD, sN, sM
    FBIN = {'fdiv':'/','fmul':'*','fadd':'+','fsub':'-'}
    if op in FBIN and len(a) == 3 and freg(a[0]) is not None:
        return f"{FR(a[0])} = {FR(a[1])} {FBIN[op]} {FR(a[2])};"
    #   fcmp / fcmpe sN, sM  or  sN, #0.0  — set flags from the float ordering.
    #   Encode the ordered result into g_fa/g_fb so the integer condition macros
    #   (FLAG_GT/GE/LT/LE/EQ/NE) that follow read the correct branch. We map the
    #   sign of (lhs-rhs) to (1,0)/(0,1)/(0,0); NaN (unordered) → (0,1) so gt/ge
    #   are false, matching AArch64 (unordered clears N/Z, sets C/V).
    if op in ('fcmp','fcmpe') and len(a) == 2 and freg(a[0]) is not None:
        rhs = "0.0" if a[1].startswith('#') else FR(a[1])
        return f"FCMP({FR(a[0])}, {rhs});"
    # Everything else — stp/ldp/str/ldr (stack/global spills), adrp (global
    # addresses), bl/blr (calls), tail-call `b` to another function — is NOT
    # safely translatable yet. Reject rather than emit a silently-wrong spec.
    return None

def args_join(a): return ', '.join(a)

def _memop(mem_args):
    """Parse a memory operand from the args after the value register(s).
    Returns (base_expr, offset_int, writeback_pre, writeback_post) or None.
    Forms:  [Xn]            [Xn, #imm]       [Xn, #imm]!   (pre-index)
            [Xn], #imm  (post-index)"""
    s = args_join(mem_args).strip()
    # post-index:  [Xn], #imm
    m = re.match(r'\[(\w+)\],\s*#(-?\w+)', s)
    if m: return (R(m.group(1)), int(m.group(2), 0), False, True)
    # pre-index:   [Xn, #imm]!
    m = re.match(r'\[(\w+),\s*#(-?\w+)\]!', s)
    if m: return (R(m.group(1)), int(m.group(2), 0), True, False)
    # offset:      [Xn, #imm]   or   [Xn]
    m = re.match(r'\[(\w+),\s*#(-?\w+)\]', s)
    if m: return (R(m.group(1)), int(m.group(2), 0), False, False)
    m = re.match(r'\[(\w+)\]', s)
    if m: return (R(m.group(1)), 0, False, False)
    return None

if __name__ == '__main__':
    lines = open(sys.argv[1]).readlines()
    if len(sys.argv) > 2 and sys.argv[2]:   # optional symbol map for @plt resolve
        _load_symmap(sys.argv[2])
    body = translate(lines)
    if body is None:
        sys.stderr.write("转译失败 (有不支持的指令)\n"); sys.exit(1)
    print("// auto-generated by translate.py")
    for l in body: print(l)
