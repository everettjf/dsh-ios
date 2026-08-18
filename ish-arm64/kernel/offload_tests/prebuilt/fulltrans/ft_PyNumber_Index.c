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

void ft_PyNumber_Index(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x14e5b0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14e5cc;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_14e5dc;
L_14e5cc:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_14e5dc:
    cpu->regs[30] = PB_BASE + 0x14e5e0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x170a04ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_14e5f4;
L_14e5ec:
    cpu->regs[19] = cpu->regs[20];
    goto L_14e5cc;
L_14e5f4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14e5ec;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14e60cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14e5cc;
    SP = SP - 128ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[3];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[25] = SP + 20ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x14e660ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x129708ULL);
    PB_LDRW(cpu->regs[1], (SP + 20));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_14e848;
    cpu->regs[24] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14e838;
L_14e674:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x14e680ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 20));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_14e848;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14e7d0;
L_14e694:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14e6a0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 20));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_14e848;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14e79c;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) { FLAG_CMP(cpu->regs[24], cpu->regs[19]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GE) goto L_14e7a4;
    cpu->regs[19] = cpu->regs[19] - cpu->regs[24];
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[19] = (cpu->regs[0] ? cpu->regs[19] / cpu->regs[0] : 0);
    cpu->regs[0] = cpu->regs[19] + 1ULL;
L_14e6d0:
    cpu->regs[24] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_14e848;
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_HI) goto L_14e774;
L_14e6e4:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] + 5ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[24] = ((cpu->regs[24] & 0xffffffffULL) << 5);
    cpu->regs[24] = cpu->regs[24] + 3048ULL;
    cpu->regs[24] = cpu->regs[24] + cpu->regs[0];
L_14e6fc:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    if (((cpu->regs[1] >> 63) & 1)) goto L_14e974;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 176)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 176) + 8);
    cpu->regs[30] = PB_BASE + 0x14e714ULL; PB_CALL(7, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_14e974;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 168));
    PB_STR((cpu->regs[0] + 8), cpu->regs[20]);
    if (((cpu->regs[1] >> 9) & 1)) goto L_14e824;
L_14e724:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 2708));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_14e9ec;
L_14e72c:
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[22]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[23]);
    PB_STR((cpu->regs[0] + 32), cpu->regs[21]); PB_STR((cpu->regs[0] + 32) + 8, cpu->regs[24]);
L_14e73c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_14e94c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_14e774:
    cpu->regs[1] = 1073741823ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = 2147483646ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HI) goto L_14e7e0;
    cpu->regs[30] = PB_BASE + 0x14e78cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe3e84ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14e6fc;
L_14e794:
    cpu->regs[0] = 0ULL;
    goto L_14e73c;
L_14e79c:
    cpu->regs[30] = PB_BASE + 0x14e7a0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_14e794;
L_14e7a4:
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_LT) { FLAG_CMP(cpu->regs[24], cpu->regs[19]); } else { FLAG_CMP(0, 0); }
    if (FLAG_LE) goto L_14e7c8;
    cpu->regs[24] = cpu->regs[24] - 1ULL;
    cpu->regs[3] = (uint64_t)(-(int64_t)cpu->regs[3]);
    cpu->regs[0] = cpu->regs[24] - cpu->regs[19];
    cpu->regs[0] = (cpu->regs[3] ? cpu->regs[0] / cpu->regs[3] : 0);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_14e6d0;
L_14e7c8:
    cpu->regs[24] = 0ULL;
    goto L_14e6e4;
L_14e7d0:
    cpu->regs[30] = PB_BASE + 0x14e7d4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_14e694;
    cpu->regs[0] = 0ULL;
    goto L_14e73c;
L_14e7e0:
    FLAG_CMP(0ULL, cpu->regs[0]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[25] = (FLAG_NE) ? 1 : 0;
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] + 2ULL));
    cpu->regs[25] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[25]));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x14e7fcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14e794;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[25] = cpu->regs[25] << 3;
    PB_STR((cpu->regs[24] + 16), cpu->regs[25]);
L_14e810:
    cpu->regs[1] = ((uint32_t)(cpu->regs[19] & 1073741823ULL));
    PB_STRW(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 4;
    cpu->regs[19] = cpu->regs[19] >> 30;
    if ((cpu->regs[19])!=0) goto L_14e810;
    goto L_14e6fc;
L_14e824:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_14e724;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
    goto L_14e724;
L_14e838:
    cpu->regs[30] = PB_BASE + 0x14e83cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_14e674;
    cpu->regs[0] = 0ULL;
    goto L_14e73c;
L_14e848:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 4ULL;
    cpu->regs[1] = cpu->regs[19] + 3208ULL;
    cpu->regs[30] = PB_BASE + 0x14e860ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14e794;
    PB_STR((SP + 112), cpu->regs[27]); PB_STR((SP + 112) + 8, cpu->regs[28]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14ea44;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_14ea3c;
L_14e880:
    cpu->regs[26] = cpu->regs[23];
    cpu->regs[27] = cpu->regs[22];
    cpu->regs[25] = cpu->regs[21];
L_14e88c:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x14e89cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14ea08;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x14e8b0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1b06e0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14e9ac;
    cpu->regs[1] = cpu->regs[19] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0x14e8c0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1b06e0ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14e9ac;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x14e8d0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1508a0ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14e9b4;
    cpu->regs[1] = cpu->regs[19] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0x14e8e0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11a700ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14e9b4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14e904;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14e904;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x14e904ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_14e904:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14e920;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14e920;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x14e920ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_14e920:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_14e95c;
L_14e928:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14e954;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14e954;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x14e944ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    goto L_14e6fc;
L_14e94c:
    PB_STR((SP + 112), cpu->regs[27]); PB_STR((SP + 112) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x14e954ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_14e954:
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    goto L_14e6fc;
L_14e95c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14e928;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x14e970ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14e928;
L_14e974:
    cpu->regs[30] = PB_BASE + 0x14e978ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x22d780ULL);
    if ((cpu->regs[0])==0) goto L_14e988;
    PB_STR((cpu->regs[0] + 16), cpu->regs[22]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[23]);
    PB_STR((cpu->regs[0] + 32), cpu->regs[21]); PB_STR((cpu->regs[0] + 32) + 8, cpu->regs[24]);
    goto L_14e73c;
L_14e988:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14e794;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14e794;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x14e9a4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_14e73c;
L_14e9ac:
    cpu->regs[27] = 0ULL;
    cpu->regs[26] = 0ULL;
L_14e9b4:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14e9c8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_14e9fc;
L_14e9c8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x14e9d0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x14e9d8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x14e9e0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    goto L_14e73c;
L_14e9ec:
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x14e9f4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    goto L_14e72c;
L_14e9fc:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x14ea04ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14e9c8;
L_14ea08:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14ea1c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_14ea60;
L_14ea1c:
    if (((cpu->regs[24] >> 31) & 1)) goto L_14ea6c;
L_14ea20:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 3208));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14ea30;
    PB_STRW((cpu->regs[19] + 3208), cpu->regs[0]);
L_14ea30:
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    cpu->regs[24] = cpu->regs[19] + 3208ULL;
    goto L_14e6fc;
L_14ea3c:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_14e880;
L_14ea44:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14ea4cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1347c0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14ea6c;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[27] = cpu->regs[23];
    goto L_14e88c;
L_14ea60:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x14ea68ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if (!((cpu->regs[24] >> 31) & 1)) goto L_14ea20;
L_14ea6c:
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    cpu->regs[0] = 0ULL;
    goto L_14e73c;
    /* nop */
    /* nop */
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3];
    if ((cpu->regs[3])!=0) goto L_14eba8;
    if (((cpu->regs[2] >> 63) & 1)) goto L_14ec30;
    FLAG_CMP(cpu->regs[5], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_14ecb8;
L_14eac4:
    if ((cpu->regs[2])==0) goto L_14eb28;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 0));
    if ((cpu->regs[1])==0) goto L_14eb54;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_NE) goto L_14eb5c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_14eb28;
    cpu->regs[2] = 18446744073709551615ULL;
L_14eaec:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 168));
    if (!((cpu->regs[3] >> 28) & 1)) goto L_14ebf4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[4], (SP + 56));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    if (FLAG_NE) goto L_14ec2c;
L_14eb18:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 96ULL;
    goto L_14ece0;
L_14eb28:
    cpu->regs[2] = 18446744073709551615ULL;
L_14eb2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_14ec2c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    goto L_14eb18;
L_14eb54:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
L_14eb5c:
    PB_STR((SP + 16), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 8));
    cpu->regs[30] = PB_BASE + 0x14eb68ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 16));
    if ((cpu->regs[0])==0) goto L_14eca0;
    PB_STR((SP + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14eb7cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[1], (SP + 16));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_14ec80;
L_14eb8c:
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14eca0;
L_14eb94:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_14eaec;
    goto L_14eb2c;
L_14eba8:
    PB_LDR(cpu->regs[20], (cpu->regs[3] + 16));
    cpu->regs[20] = cpu->regs[2] + cpu->regs[20];
L_14ebb0:
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[4] + 712ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14ebe4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14ec10;
    cpu->regs[2] = cpu->regs[20];
    goto L_14eac4;
L_14ebf4:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x14ec10ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x11f220ULL);
L_14ec10:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_14ecc0;
L_14ec2c:
    cpu->regs[30] = PB_BASE + 0x14ec30ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7c170ULL);
L_14ec30:
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 712ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14ec60ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14ec10;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[1] : cpu->regs[0];
    goto L_14eb5c;
L_14ec80:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14eb8c;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x14ec98ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 16)); PB_LDR(cpu->regs[2], (SP + 16) + 8);
    goto L_14eb8c;
L_14eca0:
    PB_STR((SP + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14eca8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_14ec10;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[2] = 18446744073709551615ULL;
    goto L_14eb94;
L_14ecb8:
    cpu->regs[20] = cpu->regs[2];
    goto L_14ebb0;
L_14ecc0:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
    /* nop */
    /* nop */
    /* nop */
L_14ece0:
    SP += -128; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[20], (cpu->regs[23] + 16));
    cpu->regs[24] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if ((cpu->regs[1])==0) goto L_14f12c;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[28], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[25] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[2] >> 63) & 1)) goto L_14ed44;
    if ((cpu->regs[28])==0) goto L_150034;
    FLAG_CMP(cpu->regs[28], 2ULL);
    if (FLAG_NE) goto L_14f04c;
    cpu->regs[19] = cpu->regs[20] + (cpu->regs[20] >> 63);
    cpu->regs[19] = (uint64_t)((int64_t)cpu->regs[19] >> 1);
    cpu->regs[19] = cpu->regs[19] + 1ULL; FLAG_CMP(cpu->regs[19], 0);
    cpu->regs[19] = (FLAG_GE) ? cpu->regs[19] : cpu->regs[20];
L_14ed44:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_GE) { FLAG_CMP(cpu->regs[20], cpu->regs[28]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_14f2fc;
    if (!((cpu->regs[0] >> 5) & 1)) goto L_150008;
    if (!((cpu->regs[0] >> 6) & 1)) goto L_14f560;
    cpu->regs[26] = cpu->regs[23] + 40ULL;
    if (!((cpu->regs[1] >> 5) & 1)) goto L_14f568;
L_14ed60:
    if (!((cpu->regs[1] >> 6) & 1)) goto L_14f51c;
    cpu->regs[2] = cpu->regs[21] + 40ULL;
    PB_STR((SP + 104), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_NE) goto L_14f52c;
L_14ed74:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14f574;
    if (!((cpu->regs[0] >> 6) & 1)) goto L_14f5fc;
L_14ed80:
    if (!((cpu->regs[1] >> 6) & 1)) goto L_14f5fc;
    if ((cpu->regs[28])==0) goto L_14ffe8;
    FLAG_CMP(cpu->regs[19], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_EQ) goto L_14eea8;
    cpu->regs[30] = PB_BASE + 0x14eda4ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fadc;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_14edd8;
    PB_LDR(cpu->regs[2], (SP + 104));
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x14edd0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1236a4ULL);
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[0] >> 63) & 1)) goto L_14ee34;
L_14edd8:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_150014;
L_14edec:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14edfc;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_14edfc:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[23]);
    PB_STR((cpu->regs[22] + 16), cpu->regs[0]);
L_14ee0c:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_NE) goto L_14f448;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_14ee1c:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 128;
    return;
L_14ee34:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x14ee40ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe9b80ULL);
    if ((cpu->regs[0])==0) goto L_14fac8;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    cpu->regs[21] = cpu->regs[28] + cpu->regs[21];
    cpu->regs[27] = cpu->regs[26] + cpu->regs[21];
    cpu->regs[6] = cpu->regs[20] - cpu->regs[21];
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_14ee8c;
    PB_LDR(cpu->regs[2], (SP + 104));
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    PB_STR((SP + 112), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x14ee80ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1236a4ULL);
    PB_LDR(cpu->regs[6], (SP + 112));
    cpu->regs[23] = cpu->regs[0];
    if (!((cpu->regs[0] >> 63) & 1)) goto L_14f05c;
L_14ee8c:
    cpu->regs[23] = 1ULL;
L_14ee90:
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x14ee9cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f0e0;
    goto L_14fac8;
L_14eea8:
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDRB(cpu->regs[27], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x14eeb4ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fadc;
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_14effc;
    cpu->regs[28] = 0ULL;
    cpu->regs[1] = 0ULL;
L_14eed0:
    cpu->regs[0] = cpu->regs[19] - cpu->regs[28];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_14f2f4;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_LE) goto L_14f2f4;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[26] + cpu->regs[1];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c0;
    cpu->regs[21] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 2ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 3ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 4ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 5ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 6ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 7ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 8ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 9ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[1] + 10ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14eff8;
    /* nop */
    /* nop */
L_14efe0:
    PB_LDRB(cpu->regs[2], (cpu->regs[26] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[27])));
    if (FLAG_EQ) goto L_14f2c4;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_GT) goto L_14efe0;
L_14eff8:
    if ((cpu->regs[28])!=0) goto L_14f020;
L_14effc:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_14edec;
    cpu->regs[28] = 0ULL;
L_14f014:
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_LT) goto L_14f044;
    cpu->regs[0] = cpu->regs[26] + cpu->regs[1];
L_14f020:
    cpu->regs[1] = cpu->regs[20] - cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x14f028ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[28], 11ULL);
    if (FLAG_GT) goto L_14f3fc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[28] << 3)), cpu->regs[19]);
L_14f040:
    cpu->regs[28] = cpu->regs[28] + 1ULL;
L_14f044:
    PB_STR((cpu->regs[22] + 16), cpu->regs[28]);
    goto L_14ee0c;
L_14f04c:
    cpu->regs[19] = (cpu->regs[28] ? (uint64_t)((int64_t)cpu->regs[20] / (int64_t)cpu->regs[28]) : 0);
    cpu->regs[19] = cpu->regs[19] + 1ULL; FLAG_CMP(cpu->regs[19], 0);
    cpu->regs[19] = (FLAG_GE) ? cpu->regs[19] : cpu->regs[20];
    goto L_14ed44;
L_14f05c:
    cpu->regs[21] = cpu->regs[28] + cpu->regs[21];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x14f06cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe9b80ULL);
    if ((cpu->regs[0])==0) goto L_14fac8;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[23];
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_14f45c;
    cpu->regs[23] = 2ULL;
L_14f088:
    PB_LDR(cpu->regs[2], (SP + 104));
    cpu->regs[6] = cpu->regs[20] - cpu->regs[21];
    cpu->regs[27] = cpu->regs[26] + cpu->regs[21];
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    PB_STR((SP + 112), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x14f0b0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1236a4ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[6], (SP + 112));
    cpu->regs[21] = cpu->regs[1] + cpu->regs[21];
    if (!((cpu->regs[1] >> 63) & 1)) goto L_14f0f4;
L_14f0c4:
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x14f0d0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[23], 11ULL);
    if (FLAG_GT) goto L_14f35c;
L_14f0e0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (((uint64_t)(uint32_t)(cpu->regs[23])) << 3)), cpu->regs[19]);
L_14f0e8:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    PB_STR((cpu->regs[22] + 16), cpu->regs[23]);
    goto L_14ee0c;
L_14f0f4:
    cpu->regs[30] = PB_BASE + 0x14f0f8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[23], 11ULL);
    if (FLAG_GT) goto L_14f32c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (((uint64_t)(uint32_t)(cpu->regs[23])) << 3)), cpu->regs[27]);
L_14f110:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[21] = cpu->regs[28] + cpu->regs[21];
    FLAG_CMP(cpu->regs[19], cpu->regs[23]);
    if (FLAG_NE) goto L_14f088;
    cpu->regs[27] = cpu->regs[26] + cpu->regs[21];
    cpu->regs[6] = cpu->regs[20] - cpu->regs[21];
    goto L_14f0c4;
L_14f12c:
    if (!((cpu->regs[2] >> 63) & 1)) goto L_14f140;
    cpu->regs[19] = cpu->regs[20] - 1ULL;
    cpu->regs[1] = 2ULL;
    cpu->regs[19] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[19] / (int64_t)cpu->regs[1]) : 0);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_14f140:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14f474;
    cpu->regs[1] = ((uint32_t)(((cpu->regs[0] >> 5) & 0x1ULL)));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_14fce8;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_14fce0;
    cpu->regs[24] = cpu->regs[23] + 40ULL;
L_14f158:
    FLAG_CMP(cpu->regs[19], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x14f16cULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14f6d8;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = 0ULL;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2568));
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = 0ULL;
L_14f18c:
    cpu->regs[0] = cpu->regs[19] - cpu->regs[27];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_14f4f0;
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_LE) goto L_14f20c;
    PB_LDRB(cpu->regs[0], (cpu->regs[24] + cpu->regs[26]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_14f4e8;
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
L_14f1b0:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14f214;
    cpu->regs[21] = cpu->regs[26] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14f208;
    PB_LDRB(cpu->regs[0], (cpu->regs[24] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_14f4dc;
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14f208;
L_14f1d4:
    cpu->regs[21] = cpu->regs[26] + 2ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14f208;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2568));
L_14f1e8:
    PB_LDRB(cpu->regs[0], (cpu->regs[24] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_14f46c;
    PB_LDRB(cpu->regs[0], (cpu->regs[26] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
L_14f1f8:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14f208;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_GT) goto L_14f1e8;
L_14f208:
    cpu->regs[26] = cpu->regs[21];
L_14f20c:
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_EQ) goto L_14f2b0;
L_14f214:
    cpu->regs[21] = cpu->regs[26] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_GT) goto L_14f230;
    goto L_14f244;
L_14f224:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14f244;
L_14f230:
    PB_LDRB(cpu->regs[0], (cpu->regs[24] + cpu->regs[21]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_14f3f0;
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14f224;
L_14f244:
    FLAG_CMP(cpu->regs[26], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[20], cpu->regs[21]); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_14f280;
L_14f250:
    cpu->regs[1] = cpu->regs[21] - cpu->regs[26];
    cpu->regs[0] = cpu->regs[24] + cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x14f25cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14f6bc;
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_14f38c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[26]);
L_14f274:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[26] = cpu->regs[21];
    goto L_14f18c;
L_14f280:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_14f250;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14f2a4;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_14f2a4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
L_14f2b0:
    PB_STR((cpu->regs[22] + 16), cpu->regs[27]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_14ee1c;
L_14f2c0:
    cpu->regs[21] = cpu->regs[1];
L_14f2c4:
    cpu->regs[1] = cpu->regs[21] - cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x14f2ccULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[28], 11ULL);
    if (FLAG_GT) goto L_14f3bc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[28] << 3)), cpu->regs[1]);
L_14f2e4:
    cpu->regs[1] = cpu->regs[21] + 1ULL;
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_GT) goto L_14eed0;
L_14f2f4:
    if ((cpu->regs[28])==0) goto L_14effc;
    goto L_14f014;
L_14f2fc:
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x14f304ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14f6d0;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_14f514;
L_14f318:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_14ee1c;
L_14f32c:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14f338ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fd64;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f110;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f110;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x14f358ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f110;
L_14f35c:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14f368ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fca8;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f0e8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f0e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14f388ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f0e8;
L_14f38c:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14f398ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fd48;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f274;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f274;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x14f3b8ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f274;
L_14f3bc:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 112), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14f3c8ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (SP + 112));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fbb4;
    if (((cpu->regs[2] >> 31) & 1)) goto L_14f2e4;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_14f2e4;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x14f3ecULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f2e4;
L_14f3f0:
    cpu->regs[30] = PB_BASE + 0x14f3f4ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x2546c0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14f224;
    goto L_14f244;
L_14f3fc:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14f408ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fca8;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f040;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f040;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x14f42cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f044;
L_14f430:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_14f444;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_14f70c;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_14f588;
L_14f444:
    cpu->regs[22] = 0ULL;
L_14f448:
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[30] = PB_BASE + 0x14f450ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_14ee1c;
L_14f45c:
    cpu->regs[23] = cpu->regs[19];
    cpu->regs[27] = cpu->regs[26] + cpu->regs[21];
    cpu->regs[6] = cpu->regs[20] - cpu->regs[21];
    goto L_14ee90;
L_14f46c:
    cpu->regs[30] = PB_BASE + 0x14f470ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x2546c0ULL);
    goto L_14f1f8;
L_14f474:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_150050;
    if (((cpu->regs[0] >> 5) & 1)) goto L_15003c;
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 56));
L_14f488:
    FLAG_CMP(cpu->regs[19], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x14f49cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fe20;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2520));
    cpu->regs[24] = 0ULL;
    cpu->regs[21] = 0ULL;
L_14f4b4:
    cpu->regs[0] = cpu->regs[19] - cpu->regs[24];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1500c0;
L_14f4c0:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_150190;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + (cpu->regs[21] << 2)));
    cpu->regs[30] = PB_BASE + 0x14f4d0ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_150194;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_14f4c0;
L_14f4dc:
    cpu->regs[30] = PB_BASE + 0x14f4e0ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x2546c0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14f1d4;
    goto L_14f208;
L_14f4e8:
    cpu->regs[30] = PB_BASE + 0x14f4ecULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x2546c0ULL);
    goto L_14f1b0;
L_14f4f0:
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_LE) goto L_14f2b0;
L_14f4f8:
    PB_LDRB(cpu->regs[0], (cpu->regs[24] + cpu->regs[26]));
    cpu->regs[30] = PB_BASE + 0x14f500ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14f6e0;
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_NE) goto L_14f4f8;
    goto L_14f2b0;
L_14f514:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_14f318;
L_14f51c:
    cpu->regs[2] = cpu->regs[21] + 56ULL;
    PB_STR((SP + 104), cpu->regs[2]);
L_14f524:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_EQ) goto L_14ed74;
L_14f52c:
    PB_LDR(cpu->regs[1], (SP + 104));
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x14f540ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x22e06cULL);
    PB_STR((SP + 104), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_14f6d0;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14f430;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_14f5fc;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    goto L_14ed80;
L_14f560:
    cpu->regs[26] = cpu->regs[23] + 56ULL;
    if (((cpu->regs[1] >> 5) & 1)) goto L_14ed60;
L_14f568:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 56));
    PB_STR((SP + 104), cpu->regs[2]);
    goto L_14f524;
L_14f574:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_14f6d0;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_14f70c;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_14f6d0;
L_14f588:
    if ((cpu->regs[28])==0) goto L_14ffe8;
    FLAG_CMP(cpu->regs[19], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_NE) goto L_14f89c;
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    PB_STRW((SP + 112), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14f5b4ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fadc;
    cpu->regs[21] = 0ULL;
    cpu->regs[27] = 0ULL;
    cpu->regs[0] = 0ULL;
L_14f5c8:
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_LE) goto L_14f878;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_14f878;
L_14f5d8:
    PB_LDRW(cpu->regs[1], (cpu->regs[26] + (cpu->regs[27] << 2)));
    PB_LDRW(cpu->regs[2], (SP + 112));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_14f780;
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_NE) goto L_14f5d8;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    goto L_14f5c8;
L_14f5fc:
    if ((cpu->regs[28])==0) goto L_14ffe8;
    FLAG_CMP(cpu->regs[19], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_NE) goto L_14fb28;
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + 0));
    PB_STRW((SP + 112), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14f628ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fadc;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = 0ULL;
L_14f638:
    cpu->regs[27] = cpu->regs[0];
L_14f63c:
    cpu->regs[1] = cpu->regs[19];
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_LE) goto L_14f940;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_GT) goto L_14f664;
    goto L_14f940;
L_14f658:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_EQ) goto L_14f63c;
L_14f664:
    PB_LDRB(cpu->regs[1], (cpu->regs[26] + cpu->regs[27]));
    PB_LDRW(cpu->regs[2], (SP + 112));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_14f658;
    cpu->regs[1] = cpu->regs[27] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[26] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x14f680ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[21], 11ULL);
    if (FLAG_GT) goto L_14fa9c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[21] << 3)), cpu->regs[28]);
L_14f698:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[0] = cpu->regs[27] + 1ULL;
    goto L_14f638;
L_14f6a4:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f6bc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f6bc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14f6bcULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_14f6bc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14f6d0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_14fc64;
L_14f6d0:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_14f6d8:
    cpu->regs[22] = 0ULL;
    goto L_14ee1c;
L_14f6e0:
    cpu->regs[1] = cpu->regs[20] - cpu->regs[26];
    cpu->regs[0] = cpu->regs[24] + cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x14f6ecULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14f6bc;
    FLAG_CMP(cpu->regs[27], 11ULL);
    if (FLAG_GT) goto L_14fbd0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[27] << 3)), cpu->regs[19]);
L_14f704:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    goto L_14f2b0;
L_14f70c:
    if ((cpu->regs[28])==0) goto L_14ffe8;
    FLAG_CMP(cpu->regs[19], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_NE) goto L_14f7f4;
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDRH(cpu->regs[1], (cpu->regs[1] + 0));
    PB_STRW((SP + 112), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14f738ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fadc;
    cpu->regs[21] = 0ULL;
    cpu->regs[27] = 0ULL;
    cpu->regs[0] = 0ULL;
L_14f74c:
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_LE) goto L_14f7b8;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_14f7b8;
L_14f75c:
    PB_LDRH(cpu->regs[1], (cpu->regs[26] + (cpu->regs[27] << 1)));
    PB_LDRW(cpu->regs[2], (SP + 112));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_14f9cc;
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_NE) goto L_14f75c;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    goto L_14f74c;
L_14f780:
    cpu->regs[1] = cpu->regs[27] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[0] << 2);
    cpu->regs[30] = PB_BASE + 0x14f78cULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[21], 11ULL);
    if (FLAG_GT) goto L_14fa04;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[21] << 3)), cpu->regs[28]);
L_14f7a4:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    goto L_14f5c8;
L_14f7b8:
    if ((cpu->regs[21])!=0) goto L_14f9ac;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_14f9ac;
L_14f7d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14f7e0;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_14f7e0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[21] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
L_14f7ec:
    PB_STR((cpu->regs[22] + 16), cpu->regs[21]);
    goto L_14ee0c;
L_14f7f4:
    cpu->regs[30] = PB_BASE + 0x14f7f8ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fadc;
    cpu->regs[21] = 0ULL;
    cpu->regs[27] = 0ULL;
L_14f808:
    cpu->regs[9] = cpu->regs[26] + (cpu->regs[27] << 1);
    cpu->regs[8] = cpu->regs[19] - cpu->regs[21];
    PB_LDR(cpu->regs[2], (SP + 104));
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[8], 0ULL);
    if (FLAG_LE) goto L_14f844;
    PB_STR((SP + 120), cpu->regs[9]);
    cpu->regs[30] = PB_BASE + 0x14f838ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x22e280ULL);
    PB_STR((SP + 112), cpu->regs[0]);
    PB_LDR(cpu->regs[9], (SP + 120));
    if (!((cpu->regs[0] >> 63) & 1)) goto L_14fa64;
L_14f844:
    if ((cpu->regs[21])==0) goto L_1500fc;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[27] << 1);
    cpu->regs[30] = PB_BASE + 0x14f854ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
L_14f85c:
    FLAG_CMP(cpu->regs[21], 11ULL);
    if (FLAG_GT) goto L_14fc94;
L_14f864:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[21] << 3)), cpu->regs[19]);
L_14f86c:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
L_14f870:
    PB_STR((cpu->regs[22] + 16), cpu->regs[21]);
    goto L_14ee0c;
L_14f878:
    if ((cpu->regs[21])==0) goto L_14fc7c;
L_14f87c:
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LT) goto L_14f7ec;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[0] << 2);
    cpu->regs[30] = PB_BASE + 0x14f890ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f85c;
    goto L_14fac8;
L_14f89c:
    cpu->regs[30] = PB_BASE + 0x14f8a0ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fadc;
    cpu->regs[21] = 0ULL;
    cpu->regs[27] = 0ULL;
L_14f8b0:
    cpu->regs[9] = cpu->regs[26] + (cpu->regs[27] << 2);
    cpu->regs[8] = cpu->regs[19] - cpu->regs[21];
    PB_LDR(cpu->regs[2], (SP + 104));
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[8], 0ULL);
    if (FLAG_LE) goto L_14f8ec;
    PB_STR((SP + 120), cpu->regs[9]);
    cpu->regs[30] = PB_BASE + 0x14f8e0ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x27b888ULL);
    PB_STR((SP + 112), cpu->regs[0]);
    PB_LDR(cpu->regs[9], (SP + 120));
    if (!((cpu->regs[0] >> 63) & 1)) goto L_14f908;
L_14f8ec:
    if ((cpu->regs[21])==0) goto L_150148;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[27] << 2);
    cpu->regs[30] = PB_BASE + 0x14f8fcULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f85c;
    goto L_14fac8;
L_14f908:
    PB_LDR(cpu->regs[1], (SP + 112));
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[27] = cpu->regs[28] + cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x14f918ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[21], 11ULL);
    if (FLAG_GT) goto L_14f978;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[21] << 3)), cpu->regs[1]);
L_14f930:
    PB_LDR(cpu->regs[0], (SP + 112));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[27] = cpu->regs[0] + cpu->regs[27];
    goto L_14f8b0;
L_14f940:
    if ((cpu->regs[21])!=0) goto L_14f958;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_14f7d0;
L_14f958:
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LT) goto L_14f7ec;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[26] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x14f96cULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f85c;
    goto L_14fac8;
L_14f978:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 120), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14f984ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (SP + 120));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fbb4;
    if (((cpu->regs[2] >> 31) & 1)) goto L_14f930;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_14f930;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x14f9a8ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f930;
L_14f9ac:
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LT) goto L_14f7ec;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[0] << 1);
    cpu->regs[30] = PB_BASE + 0x14f9c0ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f85c;
    goto L_14fac8;
L_14f9cc:
    cpu->regs[1] = cpu->regs[27] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[0] << 1);
    cpu->regs[30] = PB_BASE + 0x14f9d8ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[21], 11ULL);
    if (FLAG_GT) goto L_14fa34;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[21] << 3)), cpu->regs[28]);
L_14f9f0:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    goto L_14f74c;
L_14fa04:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14fa10ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fab0;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f7a4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f7a4;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x14fa30ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f7a4;
L_14fa34:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14fa40ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fab0;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f9f0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f9f0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x14fa60ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f9f0;
L_14fa64:
    PB_LDR(cpu->regs[1], (SP + 112));
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[27] = cpu->regs[28] + cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x14fa74ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[21], 11ULL);
    if (FLAG_GT) goto L_14fae4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[21] << 3)), cpu->regs[1]);
L_14fa8c:
    PB_LDR(cpu->regs[0], (SP + 112));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[27] = cpu->regs[0] + cpu->regs[27];
    goto L_14f808;
L_14fa9c:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14faa8ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_150174;
L_14fab0:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14fac8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14fac8;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x14fac8ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_14fac8:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14fadc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_14fb18;
L_14fadc:
    cpu->regs[22] = 0ULL;
    goto L_14ee0c;
L_14fae4:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 120), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14faf0ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (SP + 120));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fbb4;
    if (((cpu->regs[2] >> 31) & 1)) goto L_14fa8c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_14fa8c;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x14fb14ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14fa8c;
L_14fb18:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14fb24ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14ee0c;
L_14fb28:
    cpu->regs[30] = PB_BASE + 0x14fb2cULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fadc;
    cpu->regs[21] = 0ULL;
    cpu->regs[8] = 0ULL;
L_14fb3c:
    cpu->regs[27] = cpu->regs[26] + cpu->regs[8];
    cpu->regs[9] = cpu->regs[19] - cpu->regs[21];
    PB_LDR(cpu->regs[2], (SP + 104));
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[20] - cpu->regs[8];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[9], 0ULL);
    if (FLAG_LE) goto L_14fc04;
    PB_STR((SP + 112), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0x14fb6cULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x1236a4ULL);
    PB_LDR(cpu->regs[8], (SP + 112));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[28] + cpu->regs[8];
    PB_STR((SP + 112), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[27] = cpu->regs[1];
    if (((cpu->regs[1] >> 63) & 1)) goto L_14fc04;
    cpu->regs[30] = PB_BASE + 0x14fb8cULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fac8;
    FLAG_CMP(cpu->regs[21], 11ULL);
    if (FLAG_LE) goto L_14fc4c;
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 120), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14fba8ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (SP + 120));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14fcc4;
L_14fbb4:
    if (((cpu->regs[2] >> 31) & 1)) goto L_14fac8;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_14fac8;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x14fbccULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14fac8;
L_14fbd0:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14fbdcULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14f6a4;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f704;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f704;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x14fc00ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f2b0;
L_14fc04:
    if ((cpu->regs[21])!=0) goto L_14fc34;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_14f7d0;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[8];
    cpu->regs[0] = cpu->regs[26] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x14fc28ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f864;
    goto L_14fac8;
L_14fc34:
    cpu->regs[1] = cpu->regs[20] - cpu->regs[8];
    cpu->regs[0] = cpu->regs[26] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x14fc40ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f85c;
    goto L_14fac8;
L_14fc4c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[21] << 3)), cpu->regs[1]);
L_14fc54:
    PB_LDR(cpu->regs[0], (SP + 112));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[8] = cpu->regs[27] + cpu->regs[0];
    goto L_14fb3c;
L_14fc64:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14fc70ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_14ee1c;
L_14fc7c:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_14f7d0;
    goto L_14f87c;
L_14fc94:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14fca0ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_150128;
L_14fca8:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14fac8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14fac8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14fcc0ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14fac8;
L_14fcc4:
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    if (((cpu->regs[2] >> 31) & 1)) goto L_14fc54;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14fc54;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x14fcdcULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14fc54;
L_14fce0:
    PB_LDR(cpu->regs[24], (cpu->regs[23] + 56));
    goto L_14f158;
L_14fce8:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_14fd80;
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 56));
L_14fcf4:
    FLAG_CMP(cpu->regs[19], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x14fd08ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fe20;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2520));
    cpu->regs[24] = 0ULL;
    cpu->regs[21] = 0ULL;
L_14fd20:
    cpu->regs[0] = cpu->regs[19] - cpu->regs[24];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_14fe2c;
L_14fd2c:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14fe58;
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + cpu->regs[21]));
    cpu->regs[30] = PB_BASE + 0x14fd3cULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14fe5c;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_14fd2c;
L_14fd48:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f6bc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f6bc;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x14fd60ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f6bc;
L_14fd64:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14fac8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14fac8;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x14fd7cULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14fac8;
L_14fd80:
    cpu->regs[25] = cpu->regs[23] + 56ULL;
    goto L_14fcf4;
L_14fd88:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + (cpu->regs[27] << 2)));
    cpu->regs[30] = PB_BASE + 0x14fd90ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fdb8;
    cpu->regs[27] = cpu->regs[27] + 1ULL;
L_14fd98:
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_GT) goto L_14fd88;
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[20], cpu->regs[27]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_14fdb8;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_EQ) goto L_14ff78;
L_14fdb8:
    cpu->regs[1] = cpu->regs[27] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[25] + (cpu->regs[21] << 2);
    cpu->regs[30] = PB_BASE + 0x14fdc4ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14ffb0;
    FLAG_CMP(cpu->regs[24], 11ULL);
    if (FLAG_LE) goto L_1501ec;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14fde0ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_150204;
L_14fde8:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14ffb0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14ffb0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14fe00ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_14fe04:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14fe20;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14fe20;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14fe20ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_14fe20:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[22] = 0ULL;
    goto L_14ee1c;
L_14fe2c:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14fe4c;
L_14fe34:
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + cpu->regs[21]));
    cpu->regs[30] = PB_BASE + 0x14fe3cULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14fecc;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_NE) goto L_14fe34;
L_14fe4c:
    PB_STR((cpu->regs[22] + 16), cpu->regs[24]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_14ee1c;
L_14fe58:
    if (FLAG_EQ) goto L_14fe4c;
L_14fe5c:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[21] + 1ULL;
L_14fe64:
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_LE) goto L_14fe80;
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + cpu->regs[27]));
    cpu->regs[30] = PB_BASE + 0x14fe74ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fe98;
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    goto L_14fe64;
L_14fe80:
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[20], cpu->regs[27]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_14fe98;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_EQ) goto L_14ff78;
L_14fe98:
    cpu->regs[1] = cpu->regs[27] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[25] + cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14fea4ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14ffb0;
    FLAG_CMP(cpu->regs[24], 11ULL);
    if (FLAG_GT) goto L_14ffb8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[24] << 3)), cpu->regs[21]);
L_14febc:
    cpu->regs[21] = cpu->regs[27];
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_14fd20;
L_14fecc:
    cpu->regs[1] = cpu->regs[20] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[25] + cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14fed8ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fe04;
L_14fee0:
    FLAG_CMP(cpu->regs[24], 11ULL);
    if (FLAG_GT) goto L_14fef8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[24] << 3)), cpu->regs[19]);
L_14fef0:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_14fe4c;
L_14fef8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14ff04ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14ff2c;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14fef0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14fef0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x14ff28ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14fe4c;
L_14ff2c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14fe04;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14fe04;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14ff44ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14fe04;
L_14ff48:
    PB_LDRH(cpu->regs[0], (cpu->regs[25] + (cpu->regs[27] << 1)));
    cpu->regs[30] = PB_BASE + 0x14ff50ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14ff9c;
    cpu->regs[27] = cpu->regs[27] + 1ULL;
L_14ff58:
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_GT) goto L_14ff48;
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[20], cpu->regs[27]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_14ff9c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_NE) goto L_14ff9c;
L_14ff78:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14ff88;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_14ff88:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_14fe4c;
L_14ff9c:
    cpu->regs[1] = cpu->regs[27] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[25] + (cpu->regs[21] << 1);
    cpu->regs[30] = PB_BASE + 0x14ffa8ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_150220;
L_14ffb0:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_14fe04;
L_14ffb8:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x14ffc4ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fde8;
    if (((cpu->regs[1] >> 31) & 1)) goto L_14febc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14febc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14ffe4ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14febc;
L_14ffe8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2736ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x150004ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_14ee0c;
L_150008:
    PB_LDR(cpu->regs[26], (cpu->regs[23] + 56));
    if (((cpu->regs[1] >> 5) & 1)) goto L_14ed60;
    goto L_14f568;
L_150014:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x150020ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xe9b80ULL);
    if ((cpu->regs[0])==0) goto L_14fac8;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    cpu->regs[23] = 0ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_14f0e8;
L_150034:
    cpu->regs[19] = 0ULL;
    goto L_14ed44;
L_15003c:
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[25] = cpu->regs[23] + 56ULL;
    cpu->regs[0] = cpu->regs[23] + 40ULL;
    cpu->regs[25] = (FLAG_EQ) ? cpu->regs[25] : cpu->regs[0];
    goto L_14f488;
L_150050:
    if (((cpu->regs[0] >> 5) & 1)) goto L_1500ac;
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 56));
L_150058:
    FLAG_CMP(cpu->regs[19], 11ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x15006cULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14fe20;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2520));
    cpu->regs[24] = 0ULL;
    cpu->regs[21] = 0ULL;
L_150084:
    cpu->regs[0] = cpu->regs[19] - cpu->regs[24];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1501a0;
L_150090:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_1501c4;
    PB_LDRH(cpu->regs[0], (cpu->regs[25] + (cpu->regs[21] << 1)));
    cpu->regs[30] = PB_BASE + 0x1500a0ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1501c8;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_150090;
L_1500ac:
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[25] = cpu->regs[23] + 56ULL;
    cpu->regs[0] = cpu->regs[23] + 40ULL;
    cpu->regs[25] = (FLAG_EQ) ? cpu->regs[25] : cpu->regs[0];
    goto L_150058;
L_1500c0:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14fe4c;
L_1500c8:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + (cpu->regs[21] << 2)));
    cpu->regs[30] = PB_BASE + 0x1500d0ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1500e4;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_NE) goto L_1500c8;
    goto L_14fe4c;
L_1500e4:
    cpu->regs[1] = cpu->regs[20] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[25] + (cpu->regs[21] << 2);
    cpu->regs[30] = PB_BASE + 0x1500f0ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14fee0;
    goto L_14fe04;
L_1500fc:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_14f7d0;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[27] << 1);
    cpu->regs[30] = PB_BASE + 0x15011cULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f864;
    goto L_14fac8;
L_150128:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f86c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f86c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x150144ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f870;
L_150148:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_14f7d0;
    cpu->regs[1] = cpu->regs[20] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[27] << 2);
    cpu->regs[30] = PB_BASE + 0x150168ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14f864;
    goto L_14fac8;
L_150174:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14f698;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14f698;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15018cULL; PB_CALL(147, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14f698;
L_150190:
    if (FLAG_EQ) goto L_14fe4c;
L_150194:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[21] + 1ULL;
    goto L_14fd98;
L_1501a0:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LE) goto L_14fe4c;
L_1501a8:
    PB_LDRH(cpu->regs[0], (cpu->regs[25] + (cpu->regs[21] << 1)));
    cpu->regs[30] = PB_BASE + 0x1501b0ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0x1fca00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1501d4;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_NE) goto L_1501a8;
    goto L_14fe4c;
L_1501c4:
    if (FLAG_EQ) goto L_14fe4c;
L_1501c8:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[21] + 1ULL;
    goto L_14ff58;
L_1501d4:
    cpu->regs[1] = cpu->regs[20] - cpu->regs[21];
    cpu->regs[0] = cpu->regs[25] + (cpu->regs[21] << 1);
    cpu->regs[30] = PB_BASE + 0x1501e0ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14fee0;
    goto L_14fe04;
L_1501ec:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[24] << 3)), cpu->regs[21]);
L_1501f4:
    cpu->regs[21] = cpu->regs[27];
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_14f4b4;
L_150204:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1501f4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1501f4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15021cULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1501f4;
L_150220:
    FLAG_CMP(cpu->regs[24], 11ULL);
    if (FLAG_GT) goto L_150240;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[24] << 3)), cpu->regs[21]);
L_150230:
    cpu->regs[21] = cpu->regs[27];
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_150084;
L_150240:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15024cULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14fde8;
    if (((cpu->regs[1] >> 31) & 1)) goto L_150230;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_150230;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15026cULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_150230;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_1502c8;
    if ((cpu->regs[2])!=0) goto L_1502c0;
L_150298:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
L_1502a0:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = 2ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(153, cpu, tlb, PB_BASE + 0x14a3e0ULL); return; };
L_1502b8:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_150298;
L_1502c0:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    goto L_1502a0;
L_1502c8:
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 2904ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1502e0ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1502b8;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 16));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[20] = cpu->regs[20] >> 3;
    cpu->regs[19] = cpu->regs[19] >> 3;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_GT) goto L_15077c;
    cpu->regs[23] = 1ULL;
    if (FLAG_EQ) goto L_150604;
L_15033c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x150344ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_15088c;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_150810;
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 24));
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + 24));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - cpu->regs[1]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[1]);
    cpu->regs[3] = ((cpu->regs[3] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_150488;
L_150370:
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 28));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 28));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 28), cpu->regs[2]);
    cpu->regs[3] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_150488;
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 32));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 32), cpu->regs[2]);
    cpu->regs[3] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[19], 3ULL);
    if (FLAG_EQ) goto L_150488;
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 36));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 36), cpu->regs[2]);
    cpu->regs[3] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[19], 4ULL);
    if (FLAG_EQ) goto L_150488;
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 40));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 40));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 40), cpu->regs[2]);
    cpu->regs[3] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[19], 5ULL);
    if (FLAG_EQ) goto L_150488;
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 44));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 44));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 44), cpu->regs[2]);
    cpu->regs[3] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[19], 6ULL);
    if (FLAG_EQ) goto L_150488;
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 48));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 48), cpu->regs[2]);
    cpu->regs[3] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[19], 7ULL);
    if (FLAG_EQ) goto L_150488;
    cpu->regs[5] = cpu->regs[19] + 6ULL;
    cpu->regs[4] = 52ULL;
    cpu->regs[5] = cpu->regs[5] << 2;
    /* nop */
    /* nop */
    /* nop */
L_150460:
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + cpu->regs[4]));
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + cpu->regs[4]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[3]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + cpu->regs[4]), cpu->regs[1]);
    cpu->regs[4] = cpu->regs[4] + 4ULL;
    cpu->regs[3] = ((cpu->regs[2] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[4], cpu->regs[5]);
    if (FLAG_NE) goto L_150460;
L_150488:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_LE) goto L_1505c8;
L_150490:
    cpu->regs[2] = cpu->regs[21] + (cpu->regs[19] << 2);
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[19] << 2);
    cpu->regs[5] = cpu->regs[19] + 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 24));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[3]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[4] + 24), cpu->regs[3]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_LE) goto L_1505c8;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 28));
    cpu->regs[5] = cpu->regs[19] + 2ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - cpu->regs[1]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[4] + 28), cpu->regs[3]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[5], cpu->regs[20]);
    if (FLAG_GE) goto L_1505c8;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 32));
    cpu->regs[5] = cpu->regs[19] + 3ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - cpu->regs[1]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[4] + 32), cpu->regs[3]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_LE) goto L_1505c8;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 36));
    cpu->regs[5] = cpu->regs[19] + 4ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - cpu->regs[1]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[4] + 36), cpu->regs[3]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_LE) goto L_1505c8;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 40));
    cpu->regs[5] = cpu->regs[19] + 5ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - cpu->regs[1]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[4] + 40), cpu->regs[3]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_LE) goto L_1505c8;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 44));
    cpu->regs[5] = cpu->regs[19] + 6ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - cpu->regs[1]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[4] + 44), cpu->regs[3]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_LE) goto L_1505c8;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 48));
    cpu->regs[5] = cpu->regs[19] + 7ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - cpu->regs[1]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[4] + 48), cpu->regs[3]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_LE) goto L_1505c8;
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 52));
    cpu->regs[3] = cpu->regs[19] + 8ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[1]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[4] + 52), cpu->regs[1]);
    cpu->regs[2] = ((cpu->regs[2] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_LE) goto L_1505c8;
    cpu->regs[1] = cpu->regs[19] + 14ULL;
    cpu->regs[20] = cpu->regs[20] + 6ULL;
    cpu->regs[1] = cpu->regs[1] << 2;
    cpu->regs[20] = cpu->regs[20] << 2;
L_1505a8:
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] - cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + cpu->regs[1]), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 4ULL;
    cpu->regs[2] = ((cpu->regs[2] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_1505a8;
L_1505c8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[23], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_150760;
L_1505d4:
    cpu->regs[2] = cpu->regs[1] >> 3;
    if ((cpu->regs[2])==0) goto L_150704;
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[2] << 2);
    PB_LDRW(cpu->regs[4], (cpu->regs[3] + 20));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1506e4;
L_1505e8:
    FLAG_CMP(cpu->regs[1], 15ULL);
    if (FLAG_LS) goto L_150704;
L_1505f0:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_150604:
    cpu->regs[0] = cpu->regs[20] - 1ULL;
    if ((cpu->regs[20])==0) goto L_15087c;
    cpu->regs[2] = cpu->regs[21] + (cpu->regs[20] << 2);
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[20] << 2);
    PB_LDRW(cpu->regs[4], (cpu->regs[2] + 20));
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_1506bc;
    cpu->regs[5] = cpu->regs[20] - 2ULL;
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_15087c;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 16));
    PB_LDRW(cpu->regs[4], (cpu->regs[2] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_150824;
    cpu->regs[0] = cpu->regs[20] - 3ULL;
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_15087c;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 12));
    PB_LDRW(cpu->regs[4], (cpu->regs[2] + 12));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_150830;
    cpu->regs[5] = cpu->regs[20] - 4ULL;
    FLAG_CMP(cpu->regs[20], 3ULL);
    if (FLAG_EQ) goto L_15087c;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 8));
    PB_LDRW(cpu->regs[4], (cpu->regs[2] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_150824;
    cpu->regs[0] = cpu->regs[20] - 5ULL;
    FLAG_CMP(cpu->regs[20], 4ULL);
    if (FLAG_EQ) goto L_15087c;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 4));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_150830;
    cpu->regs[4] = cpu->regs[21] + 24ULL;
    cpu->regs[3] = cpu->regs[22] + 24ULL;
L_15069c:
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15087c;
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[3] + (cpu->regs[0] << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_15069c;
L_1506bc:
    cpu->regs[0] = cpu->regs[0] + 4ULL;
    cpu->regs[1] = cpu->regs[21] + (cpu->regs[0] << 2);
    cpu->regs[0] = cpu->regs[22] + (cpu->regs[0] << 2);
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LO) goto L_1507f0;
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[23] = 1ULL;
    goto L_15033c;
L_1506e4:
    cpu->regs[4] = cpu->regs[2] - 1ULL; FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_EQ) goto L_15086c;
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 16));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_1507cc;
L_1506f4:
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[1] | (cpu->regs[4] << 3);
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_1505e8;
L_150704:
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[19] = 1ULL;
    cpu->regs[19] = cpu->regs[19] - cpu->regs[1];
    cpu->regs[19] = cpu->regs[19] * cpu->regs[2];
    cpu->regs[1] = cpu->regs[19] + 5ULL;
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_HI) goto L_1505f0;
L_150724:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15073c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15073c;
    cpu->regs[30] = PB_BASE + 0x15073cULL; PB_CALL(156, cpu, tlb, PB_BASE + 0xdfce0ULL);
L_15073c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[19] + 5ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = ((cpu->regs[1] & 0xffffffffULL) << 5);
    cpu->regs[1] = cpu->regs[1] + 3048ULL;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    goto L_1505f0;
L_150758:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    /* nop */
L_150760:
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 3ULL));
    cpu->regs[2] = 2ULL;
    cpu->regs[1] = cpu->regs[1] & 18446744073709551608ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[3]));
    cpu->regs[1] = cpu->regs[2] | cpu->regs[1];
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_1505d4;
L_15077c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x150784ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_15088c;
    if ((cpu->regs[20])==0) goto L_150838;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 24));
    cpu->regs[23] = cpu->regs[20];
    PB_LDRW(cpu->regs[3], (cpu->regs[22] + 24));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - cpu->regs[1]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[1]);
    cpu->regs[3] = ((cpu->regs[3] >> 30) & 0x1ULL);
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_150850;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[20] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[22];
    cpu->regs[19] = cpu->regs[23];
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[23] = 4294967295ULL;
    goto L_150370;
L_1507cc:
    cpu->regs[4] = cpu->regs[2] - 2ULL;
    cpu->regs[6] = cpu->regs[0] + 24ULL;
L_1507d4:
    cpu->regs[3] = cpu->regs[4] - 1ULL;
    if ((cpu->regs[4])==0) goto L_15086c;
    PB_LDRW(cpu->regs[5], (cpu->regs[6] + (cpu->regs[3] << 2)));
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_150808;
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_NE) goto L_1506f4;
    goto L_1505f0;
L_1507f0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[21] = cpu->regs[22];
    cpu->regs[23] = 4294967295ULL;
    cpu->regs[22] = cpu->regs[0];
    goto L_15033c;
L_150808:
    cpu->regs[4] = cpu->regs[3];
    goto L_1507d4;
L_150810:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_1505c8;
    cpu->regs[3] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_150490;
L_150824:
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[5];
    goto L_1506bc;
L_150830:
    cpu->regs[20] = cpu->regs[5];
    goto L_1506bc;
L_150838:
    cpu->regs[20] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[22];
    cpu->regs[3] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[23] = 4294967295ULL;
    goto L_150490;
L_150850:
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_150758;
    cpu->regs[20] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[22];
    cpu->regs[19] = cpu->regs[23];
    cpu->regs[23] = 4294967295ULL;
    goto L_150490;
L_15086c:
    cpu->regs[1] = 1ULL;
    cpu->regs[19] = 0ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_150724;
L_15087c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 3208ULL;
    goto L_1505f0;
L_15088c:
    cpu->regs[0] = 0ULL;
    goto L_1505f0;
    /* nop */
    /* nop */
    /* nop */
}
