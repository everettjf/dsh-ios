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

void ft_PyUnicode_DecodeUTF8(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xdea80ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_EQ) goto L_1082d0;
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[21] = cpu->regs[21] + 1664ULL;
L_1082a8:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[2] = cpu->regs[19] + 16ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 184));
    cpu->regs[30] = PB_BASE + 0x1082c0ULL; PB_CALL(2, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_NE) goto L_1082a8;
    PB_LDR(cpu->regs[21], (SP + 32));
L_1082d0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[20] + 0) + 8);
    cpu->regs[5] = cpu->regs[0] + 32ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[4]);
    if (FLAG_HI) goto L_10835c;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 24));
    PB_STR((cpu->regs[20] + 8), cpu->regs[5]);
    cpu->regs[4] = cpu->regs[4] + cpu->regs[0]; FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_EQ) goto L_1083a4;
L_10831c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])!=0) goto L_10839c;
L_108324:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_STR((cpu->regs[4] + 8), cpu->regs[3]);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    PB_STRW((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STRW((cpu->regs[4] + 16), cpu->regs[3]);
    PB_STR((cpu->regs[4] + 24), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 40), cpu->regs[4]);
    cpu->regs[0] = 0ULL;
L_10834c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_10835c:
    cpu->regs[0] = 8192ULL;
    PB_STRW((SP + 48), cpu->regs[1]); PB_STRW((SP + 48) + 4, cpu->regs[2]);
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x10836cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x193e20ULL);
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDRW(cpu->regs[1], (SP + 48)); PB_LDRW(cpu->regs[2], (SP + 48) + 4);
    if ((cpu->regs[0])==0) goto L_1083a4;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 24));
    PB_STR((cpu->regs[20] + 16), cpu->regs[0]);
    cpu->regs[6] = cpu->regs[5] + 32ULL;
    PB_STR((cpu->regs[0] + 8), cpu->regs[6]);
    cpu->regs[4] = cpu->regs[4] + cpu->regs[5]; FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_EQ) goto L_1083a4;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 8));
    goto L_10831c;
L_10839c:
    PB_STR((cpu->regs[21] + 8), cpu->regs[0]);
    goto L_108324;
L_1083a4:
    PB_STRW((SP + 48), cpu->regs[1]); PB_STRW((SP + 48) + 4, cpu->regs[2]);
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1083b0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[3], (SP + 56));
    cpu->regs[4] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 48)); PB_LDRW(cpu->regs[2], (SP + 48) + 4);
    if ((cpu->regs[0])!=0) goto L_108324;
    cpu->regs[0] = 4294967295ULL;
    goto L_10834c;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 16));
    cpu->regs[22] = cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_108460;
L_1083f8:
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_108438;
L_108400:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + (cpu->regs[19] << 3)));
    if ((cpu->regs[20])==0) goto L_1083f8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 14) & 1)) goto L_1083f8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_108474;
L_108420:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_1083f8;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[20] + -8), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_GE) goto L_108400;
L_108438:
    cpu->regs[0] = 0ULL;
L_10843c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_10844c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[19] << 3)));
    if ((cpu->regs[0])==0) goto L_108460;
    cpu->regs[30] = PB_BASE + 0x10845cULL; PB_CALL(5, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10843c;
L_108460:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_GE) goto L_10844c;
    cpu->regs[0] = 0ULL;
    goto L_10843c;
L_108474:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_108494;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_108420;
    goto L_1083f8;
L_108494:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10849cULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_108420;
    goto L_1083f8;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10858c;
L_1084cc:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 24));
    if ((cpu->regs[22])==0) goto L_1085b4;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_10853c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_108508;
L_1084f0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_108528;
L_1084f8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x108700ULL); return; };
L_108508:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10856c;
L_108510:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + -8));
    if (!((cpu->regs[1] >> 1) & 1)) goto L_1084f0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[1] - 4ULL;
    PB_STR((cpu->regs[22] + -8), cpu->regs[1]);
    if ((cpu->regs[0])!=0) goto L_1084f8;
L_108528:
    cpu->regs[0] = 0ULL;
L_10852c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_10853c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x108548ULL; PB_CALL(8, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10852c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_108528;
L_108554:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_10856c:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1085a4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_108510;
    goto L_1084f0;
L_10858c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_1084cc;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x10859cULL; PB_CALL(9, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1084cc;
    goto L_10852c;
L_1085a4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1085acULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_108510;
    goto L_1084f0;
L_1085b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_108528;
    cpu->regs[1] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[1] + 1664ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_108554;
    goto L_1084f8;
}
