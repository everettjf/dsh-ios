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

void ft__PyLong_FromDigits(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    if ((cpu->regs[1])==0) goto L_221408;
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x221388ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2213fc;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    cpu->regs[0] = 4294967295ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : (0ULL + 1);
    cpu->regs[3] = 1ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - cpu->regs[0]));
    cpu->regs[2] = cpu->regs[19] << 2;
    cpu->regs[0] = cpu->regs[20] + 24ULL;
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    cpu->regs[19] = cpu->regs[3] | (cpu->regs[19] << 3);
    PB_STR((cpu->regs[20] + 16), cpu->regs[19]);
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_HS) goto L_2213e8;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_LO) goto L_2213f8;
L_2213cc:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2213d4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_2213d8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2213e8:
    if (FLAG_LS) goto L_2213cc;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_2213cc;
L_2213f8:
    __builtin_trap();
L_2213fc:
    cpu->regs[30] = PB_BASE + 0x221400ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2213d8;
L_221408:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 3208));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_221420;
    PB_STRW((cpu->regs[20] + 3208), cpu->regs[0]);
L_221420:
    cpu->regs[20] = cpu->regs[20] + 3208ULL;
    goto L_2213d8;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x221440ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_221548;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x22145cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_22145c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x221464ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2214f8;
    cpu->regs[30] = PB_BASE + 0x221470ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2215b8;
    cpu->regs[30] = PB_BASE + 0x22147cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2215ac;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22148cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_221574;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22149cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe8060ULL);
    if ((cpu->regs[0])!=0) goto L_221550;
    cpu->regs[30] = PB_BASE + 0x2214a4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_2214bc;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x2214b8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe97e4ULL);
    cpu->regs[24] = cpu->regs[0];
L_2214bc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_2214d8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2214d8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2214d8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2214d8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2214e0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2214e8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2214f0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[30] = PB_BASE + 0x2214f4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_22145c;
L_2214f8:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_221514;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_221514;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x221514ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_221514:
    if (((cpu->regs[24] >> 31) & 1)) goto L_22153c;
    cpu->regs[30] = PB_BASE + 0x22151cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_221530:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_22153c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_221548:
    cpu->regs[0] = 4294967295ULL;
    goto L_221530;
L_221550:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_221598;
L_221558:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 1344ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x221570ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2214bc;
L_221574:
    cpu->regs[30] = PB_BASE + 0x221578ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_2214bc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 1304ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x221594ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2214bc;
L_221598:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_221558;
    cpu->regs[30] = PB_BASE + 0x2215a8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221558;
L_2215ac:
    cpu->regs[30] = PB_BASE + 0x2215b0ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2215c4;
L_2215b8:
    cpu->regs[22] = 0ULL;
    cpu->regs[21] = 0ULL;
    goto L_2214bc;
L_2215c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1264ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2215e0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2214bc;
    if ((cpu->regs[2])==0) goto L_2216b0;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] ^ 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[4]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] >> 30));
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_2216b0;
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + 4));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] ^ 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + cpu->regs[3]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 4), cpu->regs[4]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] >> 30));
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_EQ) goto L_2216b0;
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + 8));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] ^ 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + cpu->regs[3]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 8), cpu->regs[4]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] >> 30));
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_EQ) goto L_2216b0;
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + 12));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] ^ 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + cpu->regs[3]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 12), cpu->regs[4]);
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] >> 30));
    FLAG_CMP(cpu->regs[2], 4ULL);
    if (FLAG_EQ) goto L_2216b0;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 16));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] ^ 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + cpu->regs[4]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 16), cpu->regs[4]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] >> 30));
    FLAG_CMP(cpu->regs[2], 5ULL);
    if (FLAG_EQ) goto L_2216b0;
    cpu->regs[4] = 5ULL;
L_22168c:
    PB_LDRW(cpu->regs[5], (cpu->regs[1] + (cpu->regs[4] << 2)));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] ^ 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[5] + cpu->regs[3]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + (cpu->regs[4] << 2)), cpu->regs[5]);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] >> 30));
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_NE) goto L_22168c;
L_2216b0:
    return;
    /* nop */
    /* nop */
    /* nop */
    if ((cpu->regs[2])==0) goto L_2216c8;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0x2216ccULL); return; };
L_2216c8:
    { PB_CALL(27, cpu, tlb, PB_BASE + 0x277490ULL); return; };
}
