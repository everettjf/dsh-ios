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

void ft__PyThreadState_DeleteCurrent(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    if ((cpu->regs[0])==0) goto L_242ce4;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x242c98ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1f66c0ULL);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x242cacULL; PB_CALL(2, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[2] + cpu->regs[0]), 0ULL);
    cpu->regs[0] = cpu->regs[3] + 368ULL;
    cpu->regs[30] = PB_BASE + 0x242cc0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x14770cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 2336ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_242cfc;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0xd7784ULL); return; };
L_242ce4:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 2000ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x242cfcULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x91ebcULL);
L_242cfc:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x242d20ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1ac4c4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_242d3c;
L_242d28:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_242d30:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_242d3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_242d60;
    cpu->regs[30] = PB_BASE + 0x242d54ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_242d60;
L_242d58:
    cpu->regs[0] = 0ULL;
    goto L_242d30;
L_242d60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x242d70ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_242d58;
    cpu->regs[30] = PB_BASE + 0x242d78ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2592));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x242d88ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe7640ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_242d58;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x242d9cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1ac4c4ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_242dbc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_242dbc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x242dbcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_242dbc:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_242d28;
    cpu->regs[0] = 0ULL;
    goto L_242d30;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 40));
    if (((cpu->regs[1] >> 0) & 1)) goto L_242de8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 16));
    if (((cpu->regs[1] >> 0) & 1)) goto L_242de8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    { PB_CALL(13, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_242de8:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x242df4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x21c6c0ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x242e18ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x228fc0ULL); return; };
    cpu->regs[5] = cpu->regs[1] & 18446744073709551612ULL;
    cpu->regs[6] = cpu->regs[0] + cpu->regs[1];
    PB_LDR(cpu->regs[7], (cpu->regs[2] + 0));
    cpu->regs[5] = cpu->regs[0] + cpu->regs[5];
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_242ee8;
    cpu->regs[3] = cpu->regs[7];
    cpu->regs[1] = cpu->regs[0];
    goto L_242e78;
L_242e50:
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    PB_STRH((cpu->regs[3] + -8), cpu->regs[4]);
    cpu->regs[1] = cpu->regs[1] + 4ULL;
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + -3));
    PB_STRH((cpu->regs[3] + -6), cpu->regs[4]);
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + -2));
    PB_STRH((cpu->regs[3] + -4), cpu->regs[4]);
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + -1));
    PB_STRH((cpu->regs[3] + -2), cpu->regs[4]);
L_242e78:
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    if (FLAG_LO) goto L_242e50;
    cpu->regs[1] = cpu->regs[5] - cpu->regs[0];
    cpu->regs[3] = cpu->regs[0] - 3ULL;
    cpu->regs[1] = cpu->regs[1] + 3ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[3]);
    cpu->regs[3] = cpu->regs[1] & 18446744073709551612ULL;
    cpu->regs[1] = cpu->regs[1] >> 2;
    cpu->regs[3] = (FLAG_HS) ? cpu->regs[3] : 0ULL;
    cpu->regs[3] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : 0ULL;
    cpu->regs[1] = cpu->regs[7] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[1];
L_242eb4:
    cpu->regs[5] = cpu->regs[4];
    FLAG_CMP(cpu->regs[6], cpu->regs[4]);
    if (FLAG_HI) goto L_242ed8;
    cpu->regs[0] = cpu->regs[6] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[0] = cpu->regs[0] << 1;
    cpu->regs[0] = (FLAG_HS) ? cpu->regs[0] : 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_242ed0:
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    return;
L_242ed8:
    PB_LDRB(cpu->regs[4], cpu->regs[5]); cpu->regs[5] += 1;
    PB_STRH(cpu->regs[0], cpu->regs[4]); cpu->regs[0] += 2;
    cpu->regs[4] = cpu->regs[5];
    goto L_242eb4;
L_242ee8:
    cpu->regs[3] = cpu->regs[7];
    cpu->regs[1] = cpu->regs[0];
    goto L_242f2c;
L_242ef4:
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    cpu->regs[1] = cpu->regs[1] + 4ULL;
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] & 0xffULL) << 8)));
    PB_STRH((cpu->regs[3] + -8), cpu->regs[4]);
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + -3));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] & 0xffULL) << 8)));
    PB_STRH((cpu->regs[3] + -6), cpu->regs[4]);
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + -2));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] & 0xffULL) << 8)));
    PB_STRH((cpu->regs[3] + -4), cpu->regs[4]);
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + -1));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] & 0xffULL) << 8)));
    PB_STRH((cpu->regs[3] + -2), cpu->regs[4]);
L_242f2c:
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    if (FLAG_LO) goto L_242ef4;
    cpu->regs[1] = cpu->regs[5] - cpu->regs[0];
    cpu->regs[3] = cpu->regs[0] - 3ULL;
    cpu->regs[1] = cpu->regs[1] + 3ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[3]);
    cpu->regs[3] = cpu->regs[1] & 18446744073709551612ULL;
    cpu->regs[1] = cpu->regs[1] >> 2;
    cpu->regs[3] = (FLAG_HS) ? cpu->regs[3] : 0ULL;
    cpu->regs[3] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] << 3;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = (FLAG_HS) ? cpu->regs[0] : 0ULL;
    cpu->regs[7] = cpu->regs[7] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[7];
L_242f68:
    cpu->regs[4] = cpu->regs[1];
    FLAG_CMP(cpu->regs[6], cpu->regs[1]);
    if (FLAG_HI) goto L_242f88;
    cpu->regs[0] = cpu->regs[6] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[0] = cpu->regs[0] << 1;
    cpu->regs[0] = (FLAG_HS) ? cpu->regs[0] : 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[7];
    goto L_242ed0;
L_242f88:
    PB_LDRB(cpu->regs[5], cpu->regs[4]); cpu->regs[4] += 1;
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[4] = ((uint32_t)(((cpu->regs[5] & 0xffULL) << 8)));
    PB_STRH(cpu->regs[0], cpu->regs[4]); cpu->regs[0] += 2;
    goto L_242f68;
    /* nop */
}
