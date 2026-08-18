/* AUTO-GENERATED prebuilt-gadget spec_fn for guest `_PyToken_OneChar` — DO NOT EDIT.
 * Source: /tmp/pyroot/fs/usr/lib/debug/usr/lib/libpython3.12.so.1.0.debug  addr 0xef9ab4e0
 * Produced by tools/prebuilt_gadget_gen/gen.sh (guest asm -> equivalent C).
 * Compiled only with -Doffload_test_prebuilt=true. */
#include <stdint.h>
#include "emu/arch/arm64/cpu.h"
#include "emu/tlb.h"
#include "kernel/native_offload.h"  /* prebuilt_call for bl/blr sites */

static uint64_t ror64(uint64_t v, unsigned r) { return (v >> r) | (v << (64 - r)); }
static uint64_t g_fa, g_fb;
static double fr[32];   /* float/double register file (s/d regs) */
/* FCMP: encode float ordering into g_fa/g_fb so the integer FLAG_* macros
 * that follow a fcmp read the right branch. sign(lhs-rhs) → (1,0)/(0,1)/(0,0);
 * NaN (unordered) → (0,1): gt/ge false, matching AArch64 fcmp semantics. */
#define FCMP(x,y) do { double _dx=(x), _dy=(y); \
    if (_dx < _dy) { g_fa=0; g_fb=1; } \
    else if (_dx > _dy) { g_fa=1; g_fb=0; } \
    else if (_dx == _dy) { g_fa=0; g_fb=0; } \
    else { g_fa=0; g_fb=1; } } while(0)   /* NaN */
#define FLAG_CMP(x,y) do { g_fa=(x); g_fb=(y); } while(0)
#define FLAG_EQ (g_fa == g_fb)
#define FLAG_NE (g_fa != g_fb)
#define FLAG_GT ((int64_t)g_fa >  (int64_t)g_fb)   /* signed */
#define FLAG_LT ((int64_t)g_fa <  (int64_t)g_fb)
#define FLAG_GE ((int64_t)g_fa >= (int64_t)g_fb)
#define FLAG_LE ((int64_t)g_fa <= (int64_t)g_fb)
#define FLAG_HI (g_fa >  g_fb)                     /* unsigned */
#define FLAG_LO (g_fa <  g_fb)
#define FLAG_HS (g_fa >= g_fb)
#define FLAG_LS (g_fa <= g_fb)
#define SP (cpu->sp)                               /* stack pointer */
/* PB_BASE: library load base = runtime addr (0xef9ab4e0) - file offset (0x00000000000874e0).
 * adrp/adr targets (file-absolute in the disassembly) resolve to
 * PB_BASE + target at runtime. No-ASLR makes this constant. */
extern uint64_t g_ft_base;
#define PB_BASE g_ft_base
/* Memory ops go through the guest TLB (fork/CoW safe). 64/32-bit + byte. */
#define PB_LDR(dst, addr)  do { uint64_t _v=0; tlb_read (tlb,(addr),&_v,8); (dst)=_v; } while(0)
#define PB_STR(addr, val)  do { uint64_t _v=(val); tlb_write(tlb,(addr),&_v,8); } while(0)
#define PB_LDRW(dst, addr) do { uint32_t _v=0; tlb_read (tlb,(addr),&_v,4); (dst)=_v; } while(0)
#define PB_STRW(addr, val) do { uint32_t _v=(uint32_t)(val); tlb_write(tlb,(addr),&_v,4); } while(0)
#define PB_LDRB(dst, addr) do { uint8_t  _b=0; tlb_read (tlb,(addr),&_b,1); (dst)=_b; } while(0)
#define PB_STRB(addr, val) do { uint8_t  _b=(uint8_t)(val); tlb_write(tlb,(addr),&_b,1); } while(0)
#define PB_LDRH(dst, addr) do { uint16_t _h=0; tlb_read (tlb,(addr),&_h,2); (dst)=_h; } while(0)
#define PB_STRH(addr, val) do { uint16_t _h=(uint16_t)(val); tlb_write(tlb,(addr),&_h,2); } while(0)
/* Inline-cache call: if the callee (guest addr `tgt`) has a translated
 * spec_fn, call it directly (stays in host code, no interpreter round-
 * trip); otherwise fall back to prebuilt_call (nested dispatch). Each
 * call site has its own static IC slot keyed by the last target. */
#define PB_CALL(id, cpu, tlb, tgt) do {                       \
    static addr_t _ic_tgt##id = 0; static prebuilt_fn _ic_fn##id = 0; \
    addr_t _t = (tgt);                                        \
    if (_t == _ic_tgt##id && _ic_fn##id) { _ic_fn##id(cpu, tlb); } \
    else { prebuilt_fn _f = native_offload_prebuilt_lookup(_t);\
           if (_f) { _ic_tgt##id = _t; _ic_fn##id = _f; _f(cpu, tlb); } \
           else { prebuilt_call(cpu, tlb, _t); } }            \
  } while(0)

void ft__PyTrash_end(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_dcec0;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 152), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_dceb4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 160));
    cpu->regs[20] = cpu->regs[19] + 152ULL;
    if ((cpu->regs[0])!=0) goto L_dcee4;
L_dceb4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_dcec0:
    cpu->regs[30] = PB_BASE + 0xdcec4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7c39cULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_dceb4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    if ((cpu->regs[0])==0) goto L_dcf20;
L_dcee4:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_dcee8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_dcf10;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 48));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    PB_STR((cpu->regs[20] + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xdcf0cULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    goto L_dcee8;
L_dcf10:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[19])!=0) goto L_dceb4;
L_dcf20:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 1552));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_dceb4;
    cpu->regs[0] = cpu->regs[20] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0xdcf38ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x182a60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_dceb4;
    cpu->regs[0] = cpu->regs[20] + 1552ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xdcf4cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x182ae0ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0xd7784ULL); return; };
    /* nop */
    SP = SP - 80ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3216));
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_NE) goto L_dd098;
L_dcfa4:
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[5], 0ULL);
    if (FLAG_LE) goto L_dd040;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 344));
    cpu->regs[19] = cpu->regs[19] + 24ULL;
    cpu->regs[4] = 0ULL;
L_dcfbc:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 3)));
    if ((cpu->regs[1])==0) goto L_dd12c;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
L_dcfc8:
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_dd02c;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_dd070;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_dd02c;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_dd084;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_EQ) goto L_dd02c;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_dd070;
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_EQ) goto L_dd02c;
    cpu->regs[7] = cpu->regs[1] + 24ULL;
    cpu->regs[0] = 3ULL;
L_dd014:
    PB_LDR(cpu->regs[6], (cpu->regs[7] + (cpu->regs[0] << 3)));
    FLAG_CMP(cpu->regs[6], cpu->regs[3]);
    if (FLAG_EQ) goto L_dd070;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_dd014;
L_dd02c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    PB_STRW((cpu->regs[20] + 384), 0ULL);
    cpu->regs[1] = cpu->regs[0] & 18446744073709027327ULL;
    PB_STR((cpu->regs[20] + 168), cpu->regs[1]);
    if (((cpu->regs[0] >> 9) & 1)) goto L_dd160;
L_dd040:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_dd114;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_dd070:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[4]);
    if (FLAG_EQ) goto L_dd040;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 3)));
    goto L_dcfc8;
L_dd084:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[5]);
    if (FLAG_EQ) goto L_dd040;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 3)));
    goto L_dcfc8;
L_dd098:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = SP + 4ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[1] = 50768ULL;
    cpu->regs[1] = cpu->regs[23] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xdd0b8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x122b00ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_dd190;
    cpu->regs[0] = 50768ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xdd0d4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x122b00ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if ((cpu->regs[0])==0) goto L_dd180;
    if (((cpu->regs[1] >> 31) & 1)) goto L_dd0f0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_dd174;
L_dd0f0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_dd104;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_dd168;
L_dd104:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_EQ) goto L_dcfa4;
    goto L_dd02c;
L_dd114:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0xdd11cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_dd11c:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[4]);
    if (FLAG_EQ) goto L_dd040;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 3)));
L_dd12c:
    cpu->regs[0] = cpu->regs[20];
L_dd130:
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_dd11c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 256));
    if ((cpu->regs[0])!=0) goto L_dd130;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3488));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_dd02c;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[5]);
    if (FLAG_NE) goto L_dcfbc;
    goto L_dd040;
L_dd160:
    PB_STR((cpu->regs[20] + 904), 0ULL);
    goto L_dd040;
L_dd168:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xdd170ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_dd104;
L_dd174:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xdd17cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_dd0f0;
L_dd180:
    if (((cpu->regs[1] >> 31) & 1)) goto L_dd190;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_dd198;
L_dd190:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_dd02c;
L_dd198:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xdd1a0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_dd02c;
}
