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

void ft_PyUnicode_Translate(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xc813cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c8160;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x1ff168ULL); return; };
L_c8160:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x2a7000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 512ULL;
    cpu->regs[1] = SP;
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xc81b4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x201040ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_c81d4;
    cpu->regs[30] = PB_BASE + 0xc81d4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c81d4:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 96ULL;
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 0); }
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if (FLAG_LE) goto L_c8224;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_c8254;
L_c8224:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x523000ULL;
    cpu->regs[4] = cpu->regs[4] + 784ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[6] = 2ULL;
    cpu->regs[4] = cpu->regs[4] + 640ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc8250ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_c8274;
L_c8254:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[3], (cpu->regs[0] + 0) + 8);
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[0] = cpu->regs[1] + 528ULL;
    cpu->regs[1] = SP + 32ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[4]);
    PB_STR((SP + 48), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xc8274ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x201040ULL);
L_c8274:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_c8294;
    cpu->regs[30] = PB_BASE + 0xc8294ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c8294:
    PB_LDR(cpu->regs[19], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
    SP = SP - 96ULL;
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 0); }
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if (FLAG_LE) goto L_c82e8;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_c8318;
L_c82e8:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x523000ULL;
    cpu->regs[4] = cpu->regs[4] + 784ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[6] = 2ULL;
    cpu->regs[4] = cpu->regs[4] + 712ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc8314ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_c8338;
L_c8318:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[3], (cpu->regs[0] + 0) + 8);
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[0] = cpu->regs[1] + 560ULL;
    cpu->regs[1] = SP + 32ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[4]);
    PB_STR((SP + 48), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xc8338ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x201040ULL);
L_c8338:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_c8358;
    cpu->regs[30] = PB_BASE + 0xc8358ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c8358:
    PB_LDR(cpu->regs[19], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
    SP = SP - 96ULL;
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[2], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if (FLAG_LE) goto L_c83ac;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_c83dc;
L_c83ac:
    cpu->regs[1] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x523000ULL;
    cpu->regs[4] = cpu->regs[4] + 784ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[6] = 1ULL;
    cpu->regs[4] = cpu->regs[4] + 784ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc83d8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_c83f8;
L_c83dc:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x2a7000ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 592ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xc83f8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x201040ULL);
L_c83f8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_c8418;
    cpu->regs[30] = PB_BASE + 0xc8418ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c8418:
    PB_LDR(cpu->regs[19], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
    SP = SP - 144ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]);
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[2])==0) goto L_c846c;
    PB_LDR(cpu->regs[19], (cpu->regs[2] + 16));
    goto L_c8470;
L_c846c:
    cpu->regs[19] = 0ULL;
L_c8470:
    cpu->regs[19] = cpu->regs[19] + cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[24] = cpu->regs[19] - 1ULL;
    if (FLAG_LE) goto L_c8498;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_c8498;
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c84c8;
L_c8498:
    cpu->regs[3] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[4] = PB_BASE + 0x523000ULL;
    cpu->regs[4] = cpu->regs[4] + 784ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[4] = cpu->regs[4] + 856ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc84c0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c84f8;
L_c84c8:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_c8500;
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = PB_BASE + 0x2a7000ULL;
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2920ULL;
    cpu->regs[0] = cpu->regs[0] + 616ULL;
    cpu->regs[30] = PB_BASE + 0xc84f8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x23b310ULL);
L_c84f8:
    cpu->regs[19] = 0ULL;
    goto L_c86ec;
L_c8500:
    if ((cpu->regs[24])==0) goto L_c857c;
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 8));
    if ((cpu->regs[23])==0) goto L_c8518;
    cpu->regs[24] = cpu->regs[19] - 2ULL; FLAG_CMP(cpu->regs[24], 0);
    if (FLAG_NE) goto L_c8520;
    goto L_c8594;
L_c8518:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
L_c8520:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_c8540;
    cpu->regs[30] = PB_BASE + 0xc852cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_c84f8;
    cpu->regs[24] = cpu->regs[24] - 1ULL; FLAG_CMP(cpu->regs[24], 0);
    if (FLAG_NE) goto L_c8544;
    goto L_c85a4;
L_c8540:
    cpu->regs[19] = 0ULL;
L_c8544:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    if ((cpu->regs[0])==0) goto L_c8564;
    cpu->regs[30] = PB_BASE + 0xc8550ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_c84f8;
    FLAG_CMP(cpu->regs[24], 1ULL);
    if (FLAG_NE) goto L_c8568;
    goto L_c85b0;
L_c8564:
    cpu->regs[21] = 0ULL;
L_c8568:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[30] = PB_BASE + 0xc8570ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c85b4;
    goto L_c84f8;
L_c857c:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[20] = 0ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_c85b4;
L_c8594:
    cpu->regs[20] = 0ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_c85b4;
L_c85a4:
    cpu->regs[20] = 0ULL;
    cpu->regs[21] = 0ULL;
    goto L_c85b4;
L_c85b0:
    cpu->regs[20] = 0ULL;
L_c85b4:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    cpu->regs[25] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    cpu->regs[24] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[24], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_c85ec;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc85e8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c84f8;
L_c85ec:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_c8614;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] | cpu->regs[21]));
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_c8614;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3888ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc8610ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c84f8;
L_c8614:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xc861cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x200f68ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c84f8;
    cpu->regs[30] = PB_BASE + 0xc8628ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x200b2cULL);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[23] = (FLAG_NE) ? 1 : 0;
    cpu->regs[30] = PB_BASE + 0xc8638ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22624));
    cpu->regs[30] = PB_BASE + 0xc8644ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c8654;
L_c864c:
    cpu->regs[19] = 0ULL;
    goto L_c86c8;
L_c8654:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c8664;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_c8664:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[22]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c8678;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_c8678:
    PB_STR((cpu->regs[19] + 24), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[19];
    PB_STRB((cpu->regs[19] + 32), cpu->regs[25]);
    PB_STRB((cpu->regs[19] + 33), cpu->regs[24]);
    PB_STRB((cpu->regs[19] + 34), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0xc8690ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xd9444ULL);
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    cpu->regs[30] = PB_BASE + 0xc86a4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x18fab0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c86c8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c864c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c864c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc86c4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c864c;
L_c86c8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc86d0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c86ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c86ec;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc86ecULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c86ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_c870c;
    cpu->regs[30] = PB_BASE + 0xc870cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c870c:
    PB_LDR(cpu->regs[25], (SP + 128));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_c872c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] + 3760ULL;
    cpu->regs[30] = PB_BASE + 0xc874cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1c7c60ULL);
    if ((cpu->regs[0])==0) goto L_c8784;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[1] = cpu->regs[1] + 632ULL;
    cpu->regs[30] = PB_BASE + 0xc8760ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c878c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c8784;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c8784;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc8784ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c8784:
    cpu->regs[21] = 0ULL;
    goto L_c87d0;
L_c878c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc8794ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_c87b4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c87b4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc87b4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c87b4:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c87d0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c87d0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc87d0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c87d0:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0xc87f8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xc872cULL);
    if ((cpu->regs[0])==0) goto L_c8830;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xc880cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe13e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c8838;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c8830;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c8830;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc8830ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c8830:
    cpu->regs[21] = 0ULL;
    goto L_c8878;
L_c8838:
    cpu->regs[30] = PB_BASE + 0xc883cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c885c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c885c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc885cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c885c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c8878;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c8878;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc8878ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c8878:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_c8898;
    { PB_CALL(43, cpu, tlb, PB_BASE + 0xdb548ULL); return; };
L_c8898:
    { PB_CALL(44, cpu, tlb, PB_BASE + 0x201ca0ULL); return; };
}
