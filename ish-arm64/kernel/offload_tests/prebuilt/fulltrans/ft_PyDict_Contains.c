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

void ft_PyDict_Contains(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 48), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_dd314;
L_dd294:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 120));
    if ((cpu->regs[1])==0) goto L_dd328;
L_dd29c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xdd2a4ULL; PB_CALL(1, cpu, tlb, cpu->regs[1]);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dd33c;
L_dd2b0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = SP;
    cpu->regs[30] = PB_BASE + 0xdd2c0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdd360ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_EQ) goto L_dd33c;
    cpu->regs[0] = 0ULL;
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dd2e4;
    PB_LDR(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
L_dd2e4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_dd324;
    PB_LDR(cpu->regs[21], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_dd314:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dd2b0;
    goto L_dd294;
L_dd324:
    cpu->regs[30] = PB_BASE + 0xdd328ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_dd328:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xdd330ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])==0) goto L_dd344;
L_dd334:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xdd33cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x23d444ULL);
L_dd33c:
    cpu->regs[0] = 4294967295ULL;
    goto L_dd2e4;
L_dd344:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xdd34cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18e404ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_dd33c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 120));
    if ((cpu->regs[1])!=0) goto L_dd29c;
    goto L_dd334;
    /* nop */
L_dd360:
    SP += -144; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[3];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
L_dd384:
    cpu->regs[24] = cpu->regs[0];
    PB_LDRB(cpu->regs[20], (cpu->regs[0] + 10));
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_dd41c;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_NE) goto L_dd580;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xdd3acULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdd82cULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd3e0;
L_dd3b8:
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 144;
    return;
L_dd3d4:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    /* nop */
L_dd3e0:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_dd574;
    PB_LDRB(cpu->regs[1], (cpu->regs[24] + 9));
    cpu->regs[0] = 1ULL;
    cpu->regs[24] = cpu->regs[24] + (cpu->regs[19] << 4);
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[1] & 63);
    cpu->regs[24] = cpu->regs[24] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 40));
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 144;
    return;
L_dd41c:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[3] = 1ULL;
    cpu->regs[5] = cpu->regs[21];
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[28] = cpu->regs[24] + 32ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 9));
    cpu->regs[4] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[20] = cpu->regs[21] & cpu->regs[4];
    cpu->regs[27] = cpu->regs[3] << (cpu->regs[0] & 63);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_dd49c;
L_dd450:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[28] + cpu->regs[20]),&_s,1); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[19] >> 63) & 1)) goto L_dd4ac;
L_dd458:
    cpu->regs[0] = cpu->regs[19] + (cpu->regs[19] << 1);
    cpu->regs[25] = cpu->regs[19] << 1;
    cpu->regs[0] = cpu->regs[27] + (cpu->regs[0] << 3);
    cpu->regs[3] = cpu->regs[28] + cpu->regs[0];
    PB_LDR(cpu->regs[26], (cpu->regs[3] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[26]);
    if (FLAG_EQ) goto L_dd4dc;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_dd508;
L_dd480:
    cpu->regs[20] = cpu->regs[20] + (cpu->regs[20] << 2);
    cpu->regs[5] = cpu->regs[5] >> 5;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[5];
    cpu->regs[20] = cpu->regs[4] & cpu->regs[20];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(7ULL)));
    if (FLAG_LE) goto L_dd450;
L_dd49c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_dd5c8;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[28] + (cpu->regs[20] << 1)),&_s,2); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd458;
L_dd4ac:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dd480;
L_dd4b4:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 144;
    return;
L_dd4dc:
    if (((cpu->regs[19] >> 63) & 1)) goto L_dd780;
    cpu->regs[0] = cpu->regs[25] + cpu->regs[19];
    PB_LDRB(cpu->regs[2], (cpu->regs[24] + 9));
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[28] + (cpu->regs[0] << 3);
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[2] & 63);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_dd3b8;
L_dd508:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_dd518;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
L_dd518:
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 104), cpu->regs[1]); PB_STR((SP + 104) + 8, cpu->regs[4]);
    PB_STR((SP + 120), cpu->regs[5]); PB_STR((SP + 120) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xdd52cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[6] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 0));
    PB_LDR(cpu->regs[1], (SP + 104)); PB_LDR(cpu->regs[4], (SP + 104) + 8);
    PB_LDR(cpu->regs[5], (SP + 120)); PB_LDR(cpu->regs[3], (SP + 120) + 8);
    if (((cpu->regs[2] >> 31) & 1)) goto L_dd54c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_dd754;
L_dd54c:
    if (((cpu->regs[6] >> 31) & 1)) goto L_dd780;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_NE) goto L_dd794;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 8));
    FLAG_CMP(cpu->regs[26], cpu->regs[2]);
    if (FLAG_NE) goto L_dd794;
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_dd4dc;
    PB_LDRB(cpu->regs[2], (cpu->regs[24] + 8));
    goto L_dd480;
L_dd574:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[19] << 3)));
    goto L_dd3b8;
L_dd580:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[2] = 1ULL;
    cpu->regs[4] = cpu->regs[24] + 32ULL;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDRB(cpu->regs[3], (cpu->regs[24] + 9));
    cpu->regs[25] = cpu->regs[2] << (cpu->regs[0] & 63);
    cpu->regs[25] = cpu->regs[25] - 1ULL;
    cpu->regs[28] = cpu->regs[21] & cpu->regs[25];
    cpu->regs[27] = cpu->regs[2] << (cpu->regs[3] & 63);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_dd5dc;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[4] + cpu->regs[28]),&_s,1); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
L_dd5b4:
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd5ec;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dd660;
L_dd5c0:
    cpu->regs[19] = 18446744073709551615ULL;
    goto L_dd4b4;
L_dd5c8:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_dd818;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[28] + (cpu->regs[20] << 2)),&_s,4); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd458;
    goto L_dd4ac;
L_dd5dc:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_dd6a4;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[4] + (cpu->regs[28] << 1)),&_s,2); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    goto L_dd5b4;
L_dd5ec:
    cpu->regs[2] = cpu->regs[27] + (cpu->regs[19] << 4);
    PB_STR((SP + 104), cpu->regs[2]);
    PB_LDR(cpu->regs[26], (cpu->regs[4] + cpu->regs[2]));
    FLAG_CMP(cpu->regs[1], cpu->regs[26]);
    if (FLAG_EQ) goto L_dd3d4;
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 24));
    FLAG_CMP(cpu->regs[21], cpu->regs[2]);
    if (FLAG_NE) goto L_dd660;
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_dd810;
L_dd618:
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 112), cpu->regs[1]); PB_STR((SP + 112) + 8, cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0xdd628ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[5] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 0));
    PB_LDR(cpu->regs[1], (SP + 112)); PB_LDR(cpu->regs[4], (SP + 112) + 8);
    if (!((cpu->regs[2] >> 31) & 1)) goto L_dd7a8;
L_dd638:
    if (((cpu->regs[5] >> 31) & 1)) goto L_dd7d0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_NE) goto L_dd794;
    PB_LDR(cpu->regs[2], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[4] + cpu->regs[2]));
    FLAG_CMP(cpu->regs[26], cpu->regs[2]);
    if (FLAG_NE) goto L_dd794;
    if ((((uint32_t)(cpu->regs[5])))!=0) goto L_dd3d4;
    PB_LDRB(cpu->regs[0], (cpu->regs[24] + 8));
L_dd660:
    cpu->regs[26] = cpu->regs[21] >> 5;
    cpu->regs[28] = cpu->regs[28] + (cpu->regs[28] << 2);
    cpu->regs[2] = cpu->regs[26] + 1ULL;
    cpu->regs[28] = cpu->regs[2] + cpu->regs[28];
    cpu->regs[28] = cpu->regs[25] & cpu->regs[28];
L_dd674:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_dd6b4;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[4] + cpu->regs[28]),&_s,1); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
L_dd680:
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd6d4;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dd5c0;
L_dd68c:
    cpu->regs[28] = cpu->regs[28] + (cpu->regs[28] << 2);
    cpu->regs[26] = cpu->regs[26] >> 5;
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    cpu->regs[28] = cpu->regs[28] + cpu->regs[26];
    cpu->regs[28] = cpu->regs[25] & cpu->regs[28];
    goto L_dd674;
L_dd6a4:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_dd7d8;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[4] + (cpu->regs[28] << 2)),&_s,4); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    goto L_dd5b4;
L_dd6b4:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_dd6c4;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[4] + (cpu->regs[28] << 1)),&_s,2); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    goto L_dd680;
L_dd6c4:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_dd824;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[4] + (cpu->regs[28] << 2)),&_s,4); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    goto L_dd680;
L_dd6d4:
    cpu->regs[2] = cpu->regs[27] + (cpu->regs[19] << 4);
    PB_STR((SP + 104), cpu->regs[2]);
    PB_LDR(cpu->regs[3], (cpu->regs[4] + cpu->regs[2]));
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_EQ) goto L_dd3d4;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    FLAG_CMP(cpu->regs[21], cpu->regs[2]);
    if (FLAG_NE) goto L_dd68c;
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_dd7a0;
L_dd700:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 112), cpu->regs[3]); PB_STR((SP + 112) + 8, cpu->regs[1]);
    PB_STR((SP + 128), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0xdd714ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    PB_LDR(cpu->regs[3], (SP + 112)); PB_LDR(cpu->regs[1], (SP + 112) + 8);
    cpu->regs[6] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 128));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_dd7e0;
L_dd728:
    if (((cpu->regs[6] >> 31) & 1)) goto L_dd7d0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_NE) goto L_dd794;
    PB_LDR(cpu->regs[2], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[4] + cpu->regs[2]));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_dd794;
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_dd3d4;
    PB_LDRB(cpu->regs[0], (cpu->regs[24] + 8));
    goto L_dd68c;
L_dd754:
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 104), cpu->regs[4]); PB_STR((SP + 104) + 8, cpu->regs[5]);
    PB_STR((SP + 120), cpu->regs[3]);
    PB_STRW((SP + 128), cpu->regs[6]);
    PB_STR((SP + 136), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xdd76cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[3], (SP + 120));
    PB_LDR(cpu->regs[1], (SP + 136));
    PB_LDR(cpu->regs[4], (SP + 104)); PB_LDR(cpu->regs[5], (SP + 104) + 8);
    PB_LDRW(cpu->regs[6], (SP + 128));
    goto L_dd54c;
L_dd780:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    cpu->regs[19] = 18446744073709551613ULL;
    goto L_dd3b8;
L_dd794:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_dd384;
L_dd7a0:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    goto L_dd700;
L_dd7a8:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_dd638;
    cpu->regs[0] = cpu->regs[26];
    PB_STRW((SP + 112), cpu->regs[5]);
    PB_STR((SP + 120), cpu->regs[4]); PB_STR((SP + 120) + 8, cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xdd7c4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[5], (SP + 112));
    PB_LDR(cpu->regs[4], (SP + 120)); PB_LDR(cpu->regs[1], (SP + 120) + 8);
    goto L_dd638;
L_dd7d0:
    cpu->regs[19] = 18446744073709551613ULL;
    goto L_dd4b4;
L_dd7d8:
    PB_LDR(cpu->regs[19], (cpu->regs[4] + (cpu->regs[28] << 3)));
    goto L_dd5b4;
L_dd7e0:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_dd728;
    cpu->regs[0] = cpu->regs[3];
    PB_STR((SP + 120), cpu->regs[4]);
    PB_STRW((SP + 128), cpu->regs[6]);
    PB_STR((SP + 136), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xdd800ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 136));
    PB_LDR(cpu->regs[3], (SP + 112)); PB_LDR(cpu->regs[4], (SP + 112) + 8);
    PB_LDRW(cpu->regs[6], (SP + 128));
    goto L_dd728;
L_dd810:
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    goto L_dd618;
L_dd818:
    PB_LDR(cpu->regs[19], (cpu->regs[28] + (cpu->regs[20] << 3)));
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd458;
    goto L_dd4ac;
L_dd824:
    PB_LDR(cpu->regs[19], (cpu->regs[4] + (cpu->regs[28] << 3)));
    goto L_dd680;
L_dd82c:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[0] + 32ULL;
    PB_STR((SP + 80), cpu->regs[27]);
    PB_LDRB(cpu->regs[25], (cpu->regs[0] + 8));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 9));
    cpu->regs[22] = cpu->regs[3] << (cpu->regs[25] & 63);
    cpu->regs[22] = cpu->regs[22] - 1ULL;
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[0] & 63);
    cpu->regs[27] = cpu->regs[22] & cpu->regs[2];
    cpu->regs[20] = cpu->regs[26] + cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_dd9a0;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[26] + cpu->regs[27]),&_s,1); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[19] >> 63) & 1)) goto L_dd974;
L_dd884:
    cpu->regs[0] = cpu->regs[19] << 4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_dd980;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_EQ) goto L_dda58;
L_dd8a0:
    cpu->regs[23] = cpu->regs[21] >> 5;
    cpu->regs[27] = cpu->regs[27] + (cpu->regs[27] << 2);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[23] = cpu->regs[23] + cpu->regs[27];
    cpu->regs[23] = cpu->regs[22] & cpu->regs[23];
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_ddad4;
L_dd8bc:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[26] + cpu->regs[23]),&_s,1); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[19] >> 63) & 1)) goto L_dd9e0;
L_dd8c4:
    cpu->regs[0] = cpu->regs[19] << 4;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[24], cpu->regs[1]);
    if (FLAG_EQ) goto L_dd980;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_ddaf0;
L_dd8e0:
    cpu->regs[27] = cpu->regs[21] >> 10;
    cpu->regs[23] = cpu->regs[23] + (cpu->regs[23] << 2);
    cpu->regs[0] = cpu->regs[27] + 1ULL;
    cpu->regs[23] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[23] = cpu->regs[22] & cpu->regs[23];
L_dd8f4:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_dda08;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[26] + cpu->regs[23]),&_s,1); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[19] >> 63) & 1)) goto L_ddab4;
L_dd904:
    cpu->regs[0] = cpu->regs[19] << 4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_dd980;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_EQ) goto L_ddb88;
L_dd920:
    cpu->regs[23] = cpu->regs[23] + (cpu->regs[23] << 2);
    cpu->regs[23] = cpu->regs[23] + (cpu->regs[27] >> 5);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[23] = cpu->regs[23] & cpu->regs[22];
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_dda30;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[26] + cpu->regs[23]),&_s,1); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
L_dd93c:
    if (((cpu->regs[19] >> 63) & 1)) goto L_ddb4c;
    cpu->regs[0] = cpu->regs[19] << 4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_dd980;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[21]);
    if (FLAG_EQ) goto L_ddbe4;
L_dd95c:
    cpu->regs[27] = cpu->regs[27] >> 10;
    cpu->regs[23] = cpu->regs[23] + (cpu->regs[23] << 2);
    cpu->regs[0] = cpu->regs[27] + 1ULL;
    cpu->regs[23] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[23] = cpu->regs[23] & cpu->regs[22];
    goto L_dd8f4;
L_dd974:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dda40;
L_dd97c:
    cpu->regs[19] = 18446744073709551615ULL;
L_dd980:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_dd9a0:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_ddb58;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[26] + (cpu->regs[27] << 1)),&_s,2); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd884;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dd97c;
    cpu->regs[23] = cpu->regs[2] >> 5;
    cpu->regs[27] = cpu->regs[27] + (cpu->regs[27] << 2);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[23] = cpu->regs[23] + cpu->regs[27];
    cpu->regs[23] = cpu->regs[22] & cpu->regs[23];
L_dd9cc:
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[26] + (cpu->regs[23] << 1)),&_s,2); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd8c4;
    /* nop */
    /* nop */
    /* nop */
L_dd9e0:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dd8e0;
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_dda08:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_ddc40;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[26] + (cpu->regs[23] << 1)),&_s,2); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
L_dda14:
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd904;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dd980;
    cpu->regs[23] = cpu->regs[23] + (cpu->regs[23] << 2);
    cpu->regs[23] = cpu->regs[23] + (cpu->regs[27] >> 5);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[23] = cpu->regs[22] & cpu->regs[23];
L_dda30:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_ddc50;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[26] + (cpu->regs[23] << 1)),&_s,2); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    goto L_dd93c;
L_dda40:
    cpu->regs[23] = cpu->regs[21] >> 5;
    cpu->regs[27] = cpu->regs[27] + (cpu->regs[27] << 2);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[23] = cpu->regs[23] + cpu->regs[27];
    cpu->regs[23] = cpu->regs[22] & cpu->regs[23];
    goto L_dd8bc;
L_dda58:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_dd8a0;
    if ((cpu->regs[2])==0) goto L_dd980;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 32));
    PB_LDRW(cpu->regs[1], (cpu->regs[24] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] ^ cpu->regs[3]));
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(28ULL))), 0);
    if (FLAG_NE) goto L_dd8a0;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32));
    if (!((cpu->regs[3] >> 5) & 1)) goto L_ddce0;
    if (!((cpu->regs[3] >> 6) & 1)) goto L_ddca8;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 32));
    cpu->regs[0] = cpu->regs[0] + 40ULL;
    if (!((cpu->regs[1] >> 5) & 1)) goto L_ddcb4;
L_dda98:
    if (!((cpu->regs[1] >> 6) & 1)) goto L_ddc60;
    cpu->regs[3] = ((cpu->regs[3] >> 2) & 0x7ULL);
    cpu->regs[1] = cpu->regs[24] + 40ULL;
    cpu->regs[2] = cpu->regs[3] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xddaacULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7ab70ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_dd980;
    goto L_dd8a0;
L_ddab4:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dd980;
    cpu->regs[23] = cpu->regs[23] + (cpu->regs[23] << 2);
    cpu->regs[23] = cpu->regs[23] + (cpu->regs[27] >> 5);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[23] = cpu->regs[22] & cpu->regs[23];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[26] + cpu->regs[23]),&_s,1); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    goto L_dd93c;
L_ddad4:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(15ULL)));
    if (FLAG_LE) goto L_dd9cc;
L_ddadc:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_ddcbc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[26] + (cpu->regs[23] << 2)),&_s,4); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd8c4;
    goto L_dd9e0;
L_ddaf0:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_dd8e0;
    if ((cpu->regs[2])==0) goto L_dd980;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 32));
    PB_LDRW(cpu->regs[3], (cpu->regs[24] + 32));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ cpu->regs[3]));
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(28ULL))), 0);
    if (FLAG_NE) goto L_dd8e0;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 32));
    if (!((cpu->regs[3] >> 5) & 1)) goto L_ddcf8;
    cpu->regs[0] = cpu->regs[1] + 40ULL;
    if (!((cpu->regs[3] >> 6) & 1)) goto L_ddc80;
L_ddb28:
    PB_LDR(cpu->regs[4], (cpu->regs[24] + 32));
    if (!((cpu->regs[4] >> 5) & 1)) goto L_ddcd0;
    cpu->regs[1] = cpu->regs[24] + 40ULL;
    if (!((cpu->regs[4] >> 6) & 1)) goto L_ddc78;
L_ddb38:
    cpu->regs[3] = ((cpu->regs[3] >> 2) & 0x7ULL);
    cpu->regs[2] = cpu->regs[3] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xddb44ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7ab70ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_dd980;
    goto L_dd8e0;
L_ddb4c:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dd980;
    goto L_dd95c;
L_ddb58:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_ddce8;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[26] + (cpu->regs[27] << 2)),&_s,4); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
L_ddb64:
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd884;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dd97c;
    cpu->regs[23] = cpu->regs[21] >> 5;
    cpu->regs[27] = cpu->regs[27] + (cpu->regs[27] << 2);
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[23] = cpu->regs[23] + cpu->regs[27];
    cpu->regs[23] = cpu->regs[22] & cpu->regs[23];
    goto L_ddadc;
L_ddb88:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_dd920;
    if ((cpu->regs[2])==0) goto L_dd980;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 32));
    PB_LDRW(cpu->regs[3], (cpu->regs[24] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] ^ cpu->regs[3]));
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(28ULL))), 0);
    if (FLAG_NE) goto L_dd920;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32));
    if (!((cpu->regs[3] >> 5) & 1)) goto L_ddcd8;
    if (!((cpu->regs[3] >> 6) & 1)) goto L_ddca0;
    cpu->regs[0] = cpu->regs[0] + 40ULL;
L_ddbc0:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 32));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_ddd10;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_ddc98;
    cpu->regs[1] = cpu->regs[24] + 40ULL;
L_ddbd0:
    cpu->regs[3] = ((cpu->regs[3] >> 2) & 0x7ULL);
    cpu->regs[2] = cpu->regs[3] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xddbdcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7ab70ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_dd980;
    goto L_dd920;
L_ddbe4:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_dd95c;
    if ((cpu->regs[2])==0) goto L_dd980;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 32));
    PB_LDRW(cpu->regs[3], (cpu->regs[24] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] ^ cpu->regs[3]));
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(28ULL))), 0);
    if (FLAG_NE) goto L_dd95c;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32));
    if (!((cpu->regs[3] >> 5) & 1)) goto L_ddd08;
    if (!((cpu->regs[3] >> 6) & 1)) goto L_ddc90;
    cpu->regs[0] = cpu->regs[0] + 40ULL;
L_ddc1c:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 32));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_ddd00;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_ddc88;
    cpu->regs[1] = cpu->regs[24] + 40ULL;
L_ddc2c:
    cpu->regs[3] = ((cpu->regs[3] >> 2) & 0x7ULL);
    cpu->regs[2] = cpu->regs[3] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xddc38ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7ab70ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_dd980;
    goto L_dd95c;
L_ddc40:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_ddcf0;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[26] + (cpu->regs[23] << 2)),&_s,4); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    goto L_dda14;
L_ddc50:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_ddcc8;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[26] + (cpu->regs[23] << 2)),&_s,4); cpu->regs[19] = (uint64_t)(int64_t)_s; } while(0);
    goto L_dd93c;
L_ddc60:
    cpu->regs[1] = cpu->regs[24] + 56ULL;
L_ddc64:
    cpu->regs[3] = ((cpu->regs[3] >> 2) & 0x7ULL);
    cpu->regs[2] = cpu->regs[3] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xddc70ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7ab70ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_dd980;
    goto L_dd8a0;
L_ddc78:
    cpu->regs[1] = cpu->regs[24] + 56ULL;
    goto L_ddb38;
L_ddc80:
    cpu->regs[0] = cpu->regs[1] + 56ULL;
    goto L_ddb28;
L_ddc88:
    cpu->regs[1] = cpu->regs[24] + 56ULL;
    goto L_ddc2c;
L_ddc90:
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    goto L_ddc1c;
L_ddc98:
    cpu->regs[1] = cpu->regs[24] + 56ULL;
    goto L_ddbd0;
L_ddca0:
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    goto L_ddbc0;
L_ddca8:
    cpu->regs[0] = cpu->regs[0] + 56ULL;
L_ddcac:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 32));
    if (((cpu->regs[1] >> 5) & 1)) goto L_dda98;
L_ddcb4:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 56));
    goto L_ddc64;
L_ddcbc:
    PB_LDR(cpu->regs[19], (cpu->regs[26] + (cpu->regs[23] << 3)));
    if (!((cpu->regs[19] >> 63) & 1)) goto L_dd8c4;
    goto L_dd9e0;
L_ddcc8:
    PB_LDR(cpu->regs[19], (cpu->regs[26] + (cpu->regs[23] << 3)));
    goto L_dd93c;
L_ddcd0:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 56));
    goto L_ddb38;
L_ddcd8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    goto L_ddbc0;
L_ddce0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    goto L_ddcac;
L_ddce8:
    PB_LDR(cpu->regs[19], (cpu->regs[26] + (cpu->regs[27] << 3)));
    goto L_ddb64;
L_ddcf0:
    PB_LDR(cpu->regs[19], (cpu->regs[26] + (cpu->regs[23] << 3)));
    goto L_dda14;
L_ddcf8:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 56));
    goto L_ddb28;
L_ddd00:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 56));
    goto L_ddc2c;
L_ddd08:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    goto L_ddc1c;
L_ddd10:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 56));
    goto L_ddbd0;
    /* nop */
    /* nop */
}
