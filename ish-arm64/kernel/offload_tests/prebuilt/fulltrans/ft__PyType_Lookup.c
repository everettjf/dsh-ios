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

void ft__PyType_Lookup(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[4] = 24ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe3200ULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[22] = (uint64_t)((int64_t)cpu->regs[1] >> 3);
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 384));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] ^ cpu->regs[22]));
    PB_LDR(cpu->regs[20], (cpu->regs[3] + 16));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 4095ULL));
    PB_STR((SP + 64), cpu->regs[23]);
    cpu->regs[3] = cpu->regs[20] + (uint64_t)(uint32_t)cpu->regs[3] * (uint64_t)(uint32_t)cpu->regs[4];
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = cpu->regs[3] + (64ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 13248));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_e32a0;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 13256));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_e32a0;
    cpu->regs[2] = cpu->regs[2] & 4095ULL;
    cpu->regs[20] = cpu->regs[20] + (67ULL << 12);
    cpu->regs[20] = cpu->regs[20] + 960ULL;
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[2] << 1);
    cpu->regs[2] = cpu->regs[20] + (cpu->regs[2] << 3);
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 16));
L_e3268:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_e3370;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[23], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_e32a0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe32b0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe3390ULL);
    PB_LDRW(cpu->regs[1], (SP + 4));
    cpu->regs[23] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_e3374;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_e3268;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], 100ULL);
    if (FLAG_GT) goto L_e3268;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe32e8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe366cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e3268;
    PB_LDRW(cpu->regs[4], (cpu->regs[21] + 384));
    cpu->regs[6] = 24ULL;
    cpu->regs[5] = cpu->regs[20] + (67ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[22] = ((uint32_t)(cpu->regs[4] ^ cpu->regs[22]));
    cpu->regs[5] = cpu->regs[5] + 960ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[22] & 4095ULL));
    cpu->regs[1] = cpu->regs[22] & 4095ULL;
    cpu->regs[22] = ((cpu->regs[22] & 0xfffULL) << 1);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[2] = cpu->regs[20] + (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[6];
    cpu->regs[1] = cpu->regs[5] + (cpu->regs[1] << 3);
    cpu->regs[2] = cpu->regs[2] + (64ULL << 12);
    PB_STRW((cpu->regs[2] + 13248), cpu->regs[4]);
    PB_STR((cpu->regs[1] + 16), cpu->regs[23]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 13256));
    if (FLAG_EQ) goto L_e3360;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[3]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[2] + 13256), cpu->regs[19]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_e3268;
L_e3344:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e3268;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe335cULL; PB_CALL(4, cpu, tlb, cpu->regs[1]);
    goto L_e3268;
L_e3360:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[2] + 13256), cpu->regs[19]);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_e3344;
    goto L_e3268;
L_e3370:
    cpu->regs[30] = PB_BASE + 0xe3374ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e3374:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e3384;
    cpu->regs[23] = 0ULL;
    goto L_e3268;
L_e3384:
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xe338cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_e3268;
L_e3390:
    SP = SP - 112ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_e3570;
    PB_LDR(cpu->regs[28], (cpu->regs[26] + 24));
    FLAG_CMP(cpu->regs[28], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e3570;
L_e33ec:
    PB_LDR(cpu->regs[25], (cpu->regs[19] + 344));
    if ((cpu->regs[25])==0) goto L_e35bc;
L_e33f4:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    PB_LDR(cpu->regs[21], (cpu->regs[25] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e3594;
    PB_STRW((cpu->regs[25] + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_LE) goto L_e3484;
L_e3410:
    cpu->regs[22] = SP;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[25] + 24ULL;
    cpu->regs[24] = cpu->tls_ptr;
    cpu->regs[19] = 0ULL;
L_e3424:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (((cpu->regs[0] >> 1) & 1)) goto L_e34e0;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 264));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 29) & 1)) goto L_e35a8;
L_e3440:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0xe3450ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[27], (SP + 0));
    if ((cpu->regs[27])!=0) goto L_e3564;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe3468ULL; PB_CALL(8, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_e354c;
L_e3474:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_NE) goto L_e3424;
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
L_e3484:
    cpu->regs[0] = 0ULL;
    cpu->regs[27] = 0ULL;
L_e348c:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e34a4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e35b0;
L_e34a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_e35a0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_e34e0:
    cpu->regs[27] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe34f4ULL; PB_CALL(9, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 360));
    PB_LDR(cpu->regs[0], (cpu->regs[27] + cpu->regs[0]));
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    cpu->regs[3] = cpu->regs[3] + (cpu->regs[3] << 2);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[3] << 3);
    cpu->regs[3] = cpu->regs[3] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 13272));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 29) & 1)) goto L_e3440;
L_e3520:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[1] = 1738ULL;
    cpu->regs[30] = PB_BASE + 0xe3530ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe3540ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[27] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])==0) goto L_e3474;
L_e354c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_e3474;
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    cpu->regs[27] = 0ULL;
    cpu->regs[0] = 4294967295ULL;
    goto L_e348c;
L_e3564:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    goto L_e348c;
L_e3570:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0xe3578ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[28] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_e33ec;
L_e3584:
    cpu->regs[0] = 4294967295ULL;
L_e3588:
    cpu->regs[27] = 0ULL;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_e34a4;
L_e3594:
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_GT) goto L_e3410;
    goto L_e3484;
L_e35a0:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0xe35a8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e35a8:
    cpu->regs[27] = cpu->tls_ptr;
    goto L_e3520;
L_e35b0:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xe35b8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e34a4;
L_e35bc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe35c4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x865c0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e35d0;
    cpu->regs[0] = 1ULL;
    goto L_e3588;
L_e35d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe35d8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e3584;
    PB_LDR(cpu->regs[25], (cpu->regs[19] + 344));
    if ((cpu->regs[25])!=0) goto L_e33f4;
    cpu->regs[0] = 1ULL;
    goto L_e3588;
}
