#!/bin/bash
# prebuilt_gadget_gen — generate a prebuilt-gadget spec_fn from a guest binary.
#
# Given a guest ARM64 binary in a rootfs and a leaf function name, this:
#   1. disassembles the function (objdump)
#   2. resolves its address (nm) and checks PIE-ness
#   3. auto-translates it to an equivalent C spec_fn (translate.py)
#   4. emits kernel/offload_tests/prebuilt/spec_<fn>.c + a register entry
#
# The spec_fn stays entirely in guest semantics (reads/writes cpu_state regs +
# guest memory via the TLB), so it works for any function, and is compiled into
# iSH only with -Doffload_test_prebuilt=true.
#
# Usage:  tools/prebuilt_gadget_gen/gen.sh <guest-binary> <function> [runtime-addr]
#   <guest-binary>  path to the ELF (e.g. a libpython in the rootfs)
#   <function>      symbol name (must be a leaf: no bl / unsupported insns)
#   [runtime-addr]  optional 0x… guest runtime address (default: symbol offset,
#                   correct for non-PIE; for PIE/shared libs pass the load-base+
#                   offset you observed in /proc/self/maps).
#
# On success writes the spec + prints the exact native_offload_add_prebuilt line
# to add to kernel/offload_tests/prebuilt/register.c.
set -u
cd "$(dirname "$0")/../.."                       # repo root
HERE="tools/prebuilt_gadget_gen"
OUT="kernel/offload_tests/prebuilt"

BIN="${1:?usage: gen.sh <guest-binary> <function> [runtime-addr]}"
FN="${2:?usage: gen.sh <guest-binary> <function> [runtime-addr]}"
[ -f "$BIN" ] || { echo "no such binary: $BIN" >&2; exit 2; }

# 1. Resolve symbol offset + PIE-ness.
OFF=$(nm "$BIN" 2>/dev/null | awk -v f="$FN" '$3==f && $2 ~ /[Tt]/ {print $1; exit}')
[ -n "$OFF" ] || OFF=$(nm -D "$BIN" 2>/dev/null | awk -v f="$FN" '$3==f && $2 ~ /[Tt]/ {print $1; exit}')
[ -n "$OFF" ] || { echo "symbol '$FN' not found (T/t) in $BIN" >&2; exit 2; }
PIE=no; file "$BIN" | grep -qiE 'pie|shared object' && PIE=yes
ADDR="${3:-0x$OFF}"
echo "== $FN in $BIN =="
echo "  symbol offset: 0x$OFF   PIE: $PIE   runtime addr: $ADDR"
[ "$PIE" = yes ] && [ $# -lt 3 ] && \
  echo "  WARNING: binary is PIE — 0x$OFF is a file offset, not a runtime addr;" \
       "pass the observed load-base+offset as the 3rd argument."

# 2. Disassemble the whole function. A function can have several return paths,
#    so stopping at the first `ret` would drop later branch targets. Stripped
#    libs don't label the *next* function, so we stop at the function boundary
#    heuristically: the last `ret` whose following instruction is a function
#    prologue (`sub sp, sp` / `stp x29, x30`). We emit up to (not including)
#    that prologue. Also stop at an explicit next `<symbol>:` if present.
ASM="$HERE/$FN.asm"
objdump -d "$BIN" 2>/dev/null | awk -v f="<$FN>:" '
  $0 ~ f {p=1; print; next}
  !p {next}
  /^[0-9a-f]+ </ {exit}                 # explicit next symbol → stop
  # prologue of the following (unlabelled) function → stop before it
  prev_ret && ($0 ~ /\tsub\tsp, sp,/ || $0 ~ /\tstp\tx29, x30,/) {exit}
  {print; prev_ret = ($0 ~ /\tret$/)}
' > "$ASM"
[ -s "$ASM" ] || { echo "failed to disassemble $FN" >&2; exit 2; }

# 3. Auto-translate. translate.py exits non-zero + prints UNSUPPORTED on any
#    instruction it can't safely handle (bl / unknown), so we never emit a
#    silently-wrong spec.
BODY=$(python3 "$HERE/translate.py" "$ASM" 2>"$HERE/$FN.err")
if [ $? -ne 0 ]; then
    echo "  TRANSLATION FAILED — not a supported leaf function:" >&2
    sed 's/^/    /' "$HERE/$FN.err" >&2
    echo "  (bl/call or unsupported insn; this function needs the call-boundary" >&2
    echo "   handling that isn't implemented yet. Pick a pure leaf.)" >&2
    exit 1
fi

# 4. Emit spec_<fn>.c.
SPEC="$OUT/spec_$FN.c"
{
  echo "/* AUTO-GENERATED prebuilt-gadget spec_fn for guest \`$FN\` — DO NOT EDIT."
  echo " * Source: $BIN  addr $ADDR"
  echo " * Produced by tools/prebuilt_gadget_gen/gen.sh (guest asm -> equivalent C)."
  echo " * Compiled only with -Doffload_test_prebuilt=true. */"
  echo '#include <stdint.h>'
  echo '#include "emu/arch/arm64/cpu.h"'
  echo '#include "emu/tlb.h"'
  echo '#include "kernel/native_offload.h"  /* prebuilt_call for bl/blr sites */'
  echo ''
  echo 'static uint64_t ror64(uint64_t v, unsigned r) { return (v >> r) | (v << (64 - r)); }'
  echo 'static uint64_t g_fa, g_fb;'
  echo '#define FLAG_CMP(x,y) do { g_fa=(x); g_fb=(y); } while(0)'
  echo '#define FLAG_EQ (g_fa == g_fb)'
  echo '#define FLAG_NE (g_fa != g_fb)'
  echo '#define FLAG_GT ((int64_t)g_fa >  (int64_t)g_fb)   /* signed */'
  echo '#define FLAG_LT ((int64_t)g_fa <  (int64_t)g_fb)'
  echo '#define FLAG_GE ((int64_t)g_fa >= (int64_t)g_fb)'
  echo '#define FLAG_LE ((int64_t)g_fa <= (int64_t)g_fb)'
  echo '#define FLAG_HI (g_fa >  g_fb)                     /* unsigned */'
  echo '#define FLAG_LO (g_fa <  g_fb)'
  echo '#define FLAG_HS (g_fa >= g_fb)'
  echo '#define FLAG_LS (g_fa <= g_fb)'
  echo '#define SP (cpu->sp)                               /* stack pointer */'
  echo "/* PB_BASE: library load base = runtime addr ($ADDR) - file offset (0x$OFF)."
  echo " * adrp/adr targets (file-absolute in the disassembly) resolve to"
  echo " * PB_BASE + target at runtime. No-ASLR makes this constant. */"
  echo "#define PB_BASE 0x$(printf '%x' $(( ADDR - 0x$OFF )))ULL"
  echo '/* Memory ops go through the guest TLB (fork/CoW safe). 64/32-bit + byte. */'
  echo '#define PB_LDR(dst, addr)  do { uint64_t _v=0; tlb_read (tlb,(addr),&_v,8); (dst)=_v; } while(0)'
  echo '#define PB_STR(addr, val)  do { uint64_t _v=(val); tlb_write(tlb,(addr),&_v,8); } while(0)'
  echo '#define PB_LDRW(dst, addr) do { uint32_t _v=0; tlb_read (tlb,(addr),&_v,4); (dst)=_v; } while(0)'
  echo '#define PB_STRW(addr, val) do { uint32_t _v=(uint32_t)(val); tlb_write(tlb,(addr),&_v,4); } while(0)'
  echo '#define PB_LDRB(dst, addr) do { uint8_t  _b=0; tlb_read (tlb,(addr),&_b,1); (dst)=_b; } while(0)'
  echo '#define PB_STRB(addr, val) do { uint8_t  _b=(uint8_t)(val); tlb_write(tlb,(addr),&_b,1); } while(0)'
  echo '#define PB_LDRH(dst, addr) do { uint16_t _h=0; tlb_read (tlb,(addr),&_h,2); (dst)=_h; } while(0)'
  echo '#define PB_STRH(addr, val) do { uint16_t _h=(uint16_t)(val); tlb_write(tlb,(addr),&_h,2); } while(0)'
  echo '/* Inline-cache call: if the callee (guest addr `tgt`) has a translated'
  echo ' * spec_fn, call it directly (stays in host code, no interpreter round-'
  echo ' * trip); otherwise fall back to prebuilt_call (nested dispatch). Each'
  echo ' * call site has its own static IC slot keyed by the last target. */'
  echo '#define PB_CALL(id, cpu, tlb, tgt) do {                       \'
  echo '    static addr_t _ic_tgt##id = 0; static prebuilt_fn _ic_fn##id = 0; \'
  echo '    addr_t _t = (tgt);                                        \'
  echo '    if (_t == _ic_tgt##id && _ic_fn##id) { _ic_fn##id(cpu, tlb); } \'
  echo '    else { prebuilt_fn _f = native_offload_prebuilt_lookup(_t);\'
  echo '           if (_f) { _ic_tgt##id = _t; _ic_fn##id = _f; _f(cpu, tlb); } \'
  echo '           else { prebuilt_call(cpu, tlb, _t); } }            \'
  echo '  } while(0)'
  echo ''
  echo "void spec_$FN(struct cpu_state *cpu, struct tlb *tlb) {"
  echo "    (void)tlb;"
  echo "$BODY" | grep -v "auto-generated"
  echo "}"
} > "$SPEC"
echo "  wrote $SPEC"

# 5. Print the register line + binary basename.
BASE=$(basename "$BIN")
echo ""
echo "== add to $OUT/register.c =="
echo "    void spec_$FN(struct cpu_state*, struct tlb*);"
echo "    native_offload_add_prebuilt(\"$BASE\", \"$FN\", $ADDR, spec_$FN);"
echo ""
echo "then: meson configure <build> -Doffload_test_prebuilt=true && ninja -C <build> ish"
