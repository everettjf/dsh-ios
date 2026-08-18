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

void ft_PyUnstable_Object_GC_NewWithExtraData(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[2] = 9223372036854775807ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    FLAG_CMP((cpu->regs[19]) & (24ULL), 0);
    cpu->regs[4] = (FLAG_NE) ? 1 : 0;
    cpu->regs[19] = ((cpu->regs[19] >> 14) & 0x1ULL);
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[4] = ((cpu->regs[4] & 0x1ULL) << 1);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x98368ULL; PB_CALL(1, cpu, tlb, cpu->regs[5]);
    cpu->regs[19] = cpu->regs[4] + (cpu->regs[19] << 1);
    PB_LDR(cpu->regs[22], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] - (cpu->regs[19] << 3);
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HI) goto L_9838c;
    cpu->regs[19] = cpu->regs[19] << 3;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x98388ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd8e60ULL);
    if ((cpu->regs[0])!=0) goto L_9839c;
L_9838c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x98398ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x22d7a8ULL);
    goto L_983d0;
L_9839c:
    PB_STR((cpu->regs[0] + 0), 0ULL); PB_STR((cpu->regs[0] + 0) + 8, 0ULL);
    cpu->regs[19] = cpu->regs[0] + cpu->regs[19];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x983acULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd9340ULL);
    if ((cpu->regs[19])==0) goto L_983d0;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x983c4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x983d0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xd93e0ULL);
L_983d0:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(9ULL)));
    if (FLAG_EQ) goto L_9842c;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_EQ) goto L_98414;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(10ULL)));
    if (FLAG_EQ) goto L_98430;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 2640ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x1d5940ULL); return; };
L_98414:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 2600ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    { PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL); return; };
L_9842c:
    { PB_CALL(9, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_98430:
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[8], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[8]);
    if (FLAG_LO) goto L_98468;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1880ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x98460ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_98510;
L_98468:
    if ((cpu->regs[2])!=0) goto L_98474;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x2428c0ULL); return; };
L_98474:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 40));
    cpu->regs[9] = cpu->regs[8] + 1ULL;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[3] + cpu->regs[1];
    cpu->regs[9] = (uint64_t)((int64_t)cpu->regs[9] >> 1);
    cpu->regs[7] = cpu->regs[4] & 63ULL;
    cpu->regs[4] = cpu->regs[4] >> 6;
    FLAG_CMP(cpu->regs[9], cpu->regs[1]);
    if (FLAG_LT) goto L_984b4;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 24));
    cpu->regs[0] = cpu->regs[4];
L_984a0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_984d8;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 520));
    goto L_984a0;
L_984b4:
    cpu->regs[0] = cpu->regs[3] + cpu->regs[8];
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 32));
    cpu->regs[0] = cpu->regs[0] >> 6;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[4];
L_984c8:
    cpu->regs[0] = cpu->regs[0] - 1ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_LT) goto L_984d8;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    goto L_984c8;
L_984d8:
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[7] << 3);
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 8));
    if (FLAG_EQ) goto L_984f0;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_984f0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_9850c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9850c;
    cpu->regs[30] = PB_BASE + 0x9850cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9850c:
    cpu->regs[0] = 0ULL;
L_98510:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x98524ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x20ae80ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_98534:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 40));
    if ((cpu->regs[2])!=0) goto L_9856c;
    cpu->regs[30] = PB_BASE + 0x98554ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1facacULL);
    if ((cpu->regs[0])==0) goto L_985d0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[0] + 520), cpu->regs[1]);
    cpu->regs[2] = 64ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
L_9856c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 16) + 8);
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 40), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[1] + (cpu->regs[2] << 3);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 64));
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
    PB_STR((cpu->regs[2] + 8), cpu->regs[20]);
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_985c0;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x985a0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x2329e0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_985b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_985b8;
    cpu->regs[30] = PB_BASE + 0x985b8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_985b8:
    cpu->regs[0] = 0ULL;
    goto L_985d4;
L_985c0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    goto L_985b8;
L_985d0:
    cpu->regs[0] = 4294967295ULL;
L_985d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_985e0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_985f8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
L_985f8:
    cpu->regs[30] = PB_BASE + 0x985fcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x98534ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_98610;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_98614;
L_98610:
    cpu->regs[0] = 0ULL;
L_98614:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[4] = SP + 8ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[2] = PB_BASE + 0x2a2000ULL;
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[2] = cpu->regs[2] + 2688ULL;
    cpu->regs[30] = PB_BASE + 0x98664ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x93130ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_98690;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 64));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_98698;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 2704ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x98690ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_98690:
    cpu->regs[0] = 0ULL;
    goto L_98734;
L_98698:
    PB_LDR(cpu->regs[1], (SP + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_LT) goto L_986b4;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x986b0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x2328e0ULL);
    goto L_98734;
L_986b4:
    cpu->regs[20] = (uint64_t)(-(int64_t)cpu->regs[20]);
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_LE) goto L_986c4;
    if ((cpu->regs[1])!=0) goto L_986d4;
L_986c4:
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x986d0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x985e0ULL);
    goto L_98734;
L_986d4:
    cpu->regs[1] = (uint64_t)(-(int64_t)cpu->regs[1]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x986e0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x242940ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_98690;
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[0], (SP + 8) + 8);
    if (!((cpu->regs[0] >> 63) & 1)) goto L_986f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x986f4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x2328e0ULL);
    goto L_98700;
L_986f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x98700ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x985e0ULL);
L_98700:
    if ((cpu->regs[0])==0) goto L_98690;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9871c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9871c;
    cpu->regs[30] = PB_BASE + 0x9871cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9871c:
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x98728ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x242940ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_98690;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_98734:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_98754;
    cpu->regs[30] = PB_BASE + 0x98754ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7c170ULL);
L_98754:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x98774ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x87da4ULL);
    cpu->regs[30] = PB_BASE + 0x98778ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x17aba0ULL);
    if ((cpu->regs[0])!=0) goto L_98788;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(30, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_98788:
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x98794ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x17f520ULL);
    cpu->regs[0] = PB_BASE + 0x91000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3828ULL;
    cpu->regs[30] = PB_BASE + 0x987a4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x2267e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_987d4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x987b4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1c208cULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 2744ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x987ccULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_987f8;
L_987d4:
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x987e0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x17f520ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x987e8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x17faa0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x987f0ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1c208cULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_987f8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
