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

void ft__PyModule_ClearDict(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 112ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = SP;
    cpu->regs[22] = SP + 8ULL;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = SP + 16ULL;
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
    cpu->regs[30] = PB_BASE + 0x1eb3acULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1915a0ULL);
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 208));
    PB_STR((SP + 16), 0ULL);
L_1eb3b4:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eb3c8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1eb438;
    PB_LDR(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_EQ) goto L_1eb3b4;
    PB_LDR(cpu->regs[5], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1eb3b4;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1eb3f4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x136544ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_NE) goto L_1eb3b4;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1eb408ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x136544ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_EQ) goto L_1eb3b4;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_GT) goto L_1eb530;
L_1eb418:
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eb428ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1eb3b4;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1eb434ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1eb3b4;
L_1eb438:
    cpu->regs[26] = PB_BASE + 0x28a000ULL;
    cpu->regs[26] = cpu->regs[26] + 1920ULL;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    PB_STR((SP + 16), 0ULL);
    goto L_1eb46c;
L_1eb450:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_GT) goto L_1eb510;
L_1eb458:
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eb468ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1eb504;
L_1eb46c:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eb480ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1eb4c8;
    PB_LDR(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_EQ) goto L_1eb46c;
    PB_LDR(cpu->regs[20], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1eb46c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1eb4acULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x136544ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_NE) goto L_1eb450;
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1eb4c0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1eb450;
    goto L_1eb46c;
L_1eb4c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1eb500;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_1eb500:
    cpu->regs[30] = PB_BASE + 0x1eb504ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1eb504:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1eb50cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1eb46c;
L_1eb510:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1eb518ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1eb550;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1352ULL;
    cpu->regs[30] = PB_BASE + 0x1eb52cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xa8500ULL);
    goto L_1eb458;
L_1eb530:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1eb538ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1eb558;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1328ULL;
    cpu->regs[30] = PB_BASE + 0x1eb54cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xa8500ULL);
    goto L_1eb418;
L_1eb550:
    cpu->regs[30] = PB_BASE + 0x1eb554ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1eb458;
L_1eb558:
    cpu->regs[30] = PB_BASE + 0x1eb55cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1eb418;
    SP = SP - 48ULL;
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_1eb5c4;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 16));
    if ((cpu->regs[5])==0) goto L_1eb5c4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 34928ULL;
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 0), cpu->regs[5]); PB_STR((SP + 0) + 8, cpu->regs[4]);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x1eb5b8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1eb5f4;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1eb600;
L_1eb5c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1eb5fc;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
L_1eb5f4:
    cpu->regs[30] = PB_BASE + 0x1eb5f8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1eb5c4;
L_1eb5fc:
    cpu->regs[30] = PB_BASE + 0x1eb600ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1eb600:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1eb5c4;
    cpu->regs[30] = PB_BASE + 0x1eb610ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb5c4;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1eb640;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 20));
    if (((cpu->regs[0] >> 6) & 1)) goto L_1eb654;
L_1eb640:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1eb654:
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1eb65cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x121f0cULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x294000ULL;
    cpu->regs[2] = cpu->regs[2] + 1376ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1eb67cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xab9c0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1eb68c;
L_1eb680:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1eb688ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x121f40ULL);
    goto L_1eb640;
L_1eb68c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2728));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1eb69cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1eb680;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eb6a8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1eb680;
L_1eb6ac:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_1eb6dc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb6dc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb74c;
L_1eb6dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_1eb6fc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 8), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb6fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb764;
L_1eb6fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_1eb71c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb71c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb75c;
L_1eb71c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1eb73c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb73c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb754;
L_1eb73c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1eb74c:
    cpu->regs[30] = PB_BASE + 0x1eb750ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb6dc;
L_1eb754:
    cpu->regs[30] = PB_BASE + 0x1eb758ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb73c;
L_1eb75c:
    cpu->regs[30] = PB_BASE + 0x1eb760ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb71c;
L_1eb764:
    cpu->regs[30] = PB_BASE + 0x1eb768ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb6fc;
    goto L_1eb6ac;
L_1eb770:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_1eb7a0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 8), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb7a0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb970;
L_1eb7a0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_1eb7c0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb7c0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9e0;
L_1eb7c0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1eb7e0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb7e0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9d8;
L_1eb7e0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_1eb800;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 32), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb800;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9d0;
L_1eb800:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_1eb820;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb820;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9c8;
L_1eb820:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_1eb840;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb840;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9c0;
L_1eb840:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_1eb860;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 56), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb860;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9b8;
L_1eb860:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    if ((cpu->regs[0])==0) goto L_1eb880;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 64), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb880;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9b0;
L_1eb880:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_1eb8a0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb8a0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9a8;
L_1eb8a0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_1eb8c0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb8c0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb9a0;
L_1eb8c0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])==0) goto L_1eb8e0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 88), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb8e0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb998;
L_1eb8e0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])==0) goto L_1eb900;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb900;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb990;
L_1eb900:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])==0) goto L_1eb920;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 104), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb920;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb988;
L_1eb920:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])==0) goto L_1eb940;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 112), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb940;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb980;
L_1eb940:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    if ((cpu->regs[0])==0) goto L_1eb960;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 120), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eb960;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eb978;
L_1eb960:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1eb970:
    cpu->regs[30] = PB_BASE + 0x1eb974ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb7a0;
L_1eb978:
    cpu->regs[30] = PB_BASE + 0x1eb97cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb960;
L_1eb980:
    cpu->regs[30] = PB_BASE + 0x1eb984ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb940;
L_1eb988:
    cpu->regs[30] = PB_BASE + 0x1eb98cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb920;
L_1eb990:
    cpu->regs[30] = PB_BASE + 0x1eb994ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb900;
L_1eb998:
    cpu->regs[30] = PB_BASE + 0x1eb99cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb8e0;
L_1eb9a0:
    cpu->regs[30] = PB_BASE + 0x1eb9a4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb8c0;
L_1eb9a8:
    cpu->regs[30] = PB_BASE + 0x1eb9acULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb8a0;
L_1eb9b0:
    cpu->regs[30] = PB_BASE + 0x1eb9b4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb880;
L_1eb9b8:
    cpu->regs[30] = PB_BASE + 0x1eb9bcULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb860;
L_1eb9c0:
    cpu->regs[30] = PB_BASE + 0x1eb9c4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb840;
L_1eb9c8:
    cpu->regs[30] = PB_BASE + 0x1eb9ccULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb820;
L_1eb9d0:
    cpu->regs[30] = PB_BASE + 0x1eb9d4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb800;
L_1eb9d8:
    cpu->regs[30] = PB_BASE + 0x1eb9dcULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb7e0;
L_1eb9e0:
    cpu->regs[30] = PB_BASE + 0x1eb9e4ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eb7c0;
    goto L_1eb770;
L_1eb9ec:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_1eba20;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eba20;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1eba20;
    cpu->regs[30] = PB_BASE + 0x1eba20ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1eba20:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_1eba40;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 8), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eba40;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebbc8;
L_1eba40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_1eba60;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eba60;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebbc0;
L_1eba60:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1eba80;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eba80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebbb8;
L_1eba80:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_1ebaa0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebaa0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebbb0;
L_1ebaa0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_1ebac0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebac0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebba8;
L_1ebac0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_1ebae0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 56), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebae0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebba0;
L_1ebae0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    if ((cpu->regs[0])==0) goto L_1ebb00;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 64), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebb00;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebb98;
L_1ebb00:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_1ebb20;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebb20;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebb90;
L_1ebb20:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_1ebb40;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebb40;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebb88;
L_1ebb40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])==0) goto L_1ebb64;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 88), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebb64;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ebb64;
    cpu->regs[30] = PB_BASE + 0x1ebb64ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ebb64:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])==0) goto L_1ebb78;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1ebbd0;
L_1ebb78:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1ebb88:
    cpu->regs[30] = PB_BASE + 0x1ebb8cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ebb40;
L_1ebb90:
    cpu->regs[30] = PB_BASE + 0x1ebb94ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ebb20;
L_1ebb98:
    cpu->regs[30] = PB_BASE + 0x1ebb9cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ebb00;
L_1ebba0:
    cpu->regs[30] = PB_BASE + 0x1ebba4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ebae0;
L_1ebba8:
    cpu->regs[30] = PB_BASE + 0x1ebbacULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ebac0;
L_1ebbb0:
    cpu->regs[30] = PB_BASE + 0x1ebbb4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ebaa0;
L_1ebbb8:
    cpu->regs[30] = PB_BASE + 0x1ebbbcULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eba80;
L_1ebbc0:
    cpu->regs[30] = PB_BASE + 0x1ebbc4ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eba60;
L_1ebbc8:
    cpu->regs[30] = PB_BASE + 0x1ebbccULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eba40;
L_1ebbd0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ebb78;
    cpu->regs[30] = PB_BASE + 0x1ebbe0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ebb78;
    goto L_1eb9ec;
}
