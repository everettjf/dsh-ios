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

void ft_PyObject_SelfIter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_137390;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_137390:
    return;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 48ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[2] = SP;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1373d4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x137460ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_13740c;
L_1373d8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_137404;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
L_137404:
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x13740cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c170ULL);
L_13740c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((SP + 32), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (SP + 0));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_137430;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13742cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x252128ULL);
    if ((cpu->regs[19])==0) goto L_13743c;
L_137430:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((SP + 0), 0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_137444;
L_13743c:
    PB_LDR(cpu->regs[19], (SP + 32));
    goto L_1373d8;
L_137444:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_13743c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x137458ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 32));
    goto L_1373d8;
L_137460:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x137490ULL; PB_CALL(5, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[20], (cpu->regs[5] + cpu->regs[0]));
    PB_STR((cpu->regs[21] + 0), 0ULL);
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[19] + 72ULL;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[19] + 67),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_137584;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_137758;
    if (FLAG_GT) goto L_137608;
    if ((cpu->regs[22])!=0) goto L_1375c4;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    cpu->regs[4] = cpu->regs[3];
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_13759c;
L_1374d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 64));
    cpu->regs[3] = cpu->regs[19] + 40ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 104));
    cpu->regs[6] = ((uint32_t)(cpu->regs[0] + 1ULL));
    cpu->regs[0] = cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3);
    PB_STR((cpu->regs[0] + 72), cpu->regs[4]);
    PB_STRW((cpu->regs[1] + 64), cpu->regs[6]);
    PB_STR((cpu->regs[19] + 48), cpu->regs[5]);
    PB_STR((cpu->regs[20] + 104), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1375cc;
    PB_STRB((cpu->regs[19] + 67), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 1744));
    if ((cpu->regs[3])!=0) goto L_1375f4;
L_13750c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x137514ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xf7304ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_137570;
L_13751c:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[19] + 67),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_137540;
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[20]);
L_137530:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_137540:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_NE) goto L_137680;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2800));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_137730;
    if ((cpu->regs[22])!=0) goto L_137670;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_137720;
L_137570:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_1375a4;
    PB_STR((cpu->regs[21] + 0), 0ULL);
L_13757c:
    cpu->regs[0] = 4294967295ULL;
    goto L_137530;
L_137584:
    if ((cpu->regs[22])!=0) goto L_137694;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
L_137590:
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1374d4;
L_13759c:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[0]);
    goto L_1374d4;
L_1375a4:
    cpu->regs[20] = 0ULL;
L_1375a8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_13765c;
L_1375b4:
    FLAG_CMP(cpu->regs[20], 0ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[20]);
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
    goto L_137530;
L_1375c4:
    cpu->regs[4] = cpu->regs[22];
    goto L_137590;
L_1375cc:
    cpu->regs[0] = 0ULL;
    PB_STRW((SP + 52), cpu->regs[2]);
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1375dcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1b8480ULL);
    PB_STRB((cpu->regs[19] + 67), 0ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDRW(cpu->regs[2], (SP + 52));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 1744));
    if ((cpu->regs[3])==0) goto L_13750c;
L_1375f4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1375fcULL; PB_CALL(8, cpu, tlb, cpu->regs[3]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_13751c;
    goto L_137570;
L_137608:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] ^ 1ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2816));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[4]))) & (((uint32_t)(cpu->regs[0]))), 0);
    if (FLAG_NE) goto L_137700;
    FLAG_CMP(cpu->regs[22], 0ULL);
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] ^ 1ULL));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(cpu->regs[0]))), 0);
    if (FLAG_EQ) goto L_13757c;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_13773c;
    PB_STR((cpu->regs[21] + 0), cpu->regs[3]);
L_137654:
    cpu->regs[0] = 0ULL;
    goto L_137530;
L_13765c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1375b4;
    cpu->regs[30] = PB_BASE + 0x13766cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1375b4;
L_137670:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_1375a8;
    PB_STR((cpu->regs[21] + 0), cpu->regs[3]);
    goto L_137654;
L_137680:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_1375a8;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[20]);
    goto L_137530;
L_137694:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[4] = cpu->regs[22];
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_EQ) goto L_137590;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2816));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_1376f4;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2800));
    cpu->regs[0] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[0] + 3640ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] + 3696ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
L_1376dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1376ecULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_137530;
L_1376f4:
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 3584ULL;
    goto L_1376dc;
L_137700:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x137718ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_137530;
L_137720:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_137748;
    cpu->regs[20] = 0ULL;
L_137730:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_1375b4;
    goto L_1375a8;
L_13773c:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[21] + 0), cpu->regs[3]);
    goto L_137654;
L_137748:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x137754ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_137730;
L_137758:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2816));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_1377a4;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2800));
    cpu->regs[0] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[0] + 3792ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] + 3824ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
L_13778c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x13779cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_137530;
L_1377a4:
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 3760ULL;
    goto L_13778c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + -16)); PB_LDR(cpu->regs[2], (cpu->regs[0] + -16) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    PB_STR((cpu->regs[3] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[0] + -16), 0ULL); PB_STR((cpu->regs[0] + -16) + 8, cpu->regs[1]);
    if ((cpu->regs[4])!=0) goto L_137994;
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x137804ULL; PB_CALL(14, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + cpu->regs[0]));
L_13780c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[4] | cpu->regs[1];
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[19] + -16), cpu->regs[3]); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x137830ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1379e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1379c0;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -16)); PB_LDR(cpu->regs[1], (cpu->regs[19] + -16) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    PB_STR((cpu->regs[2] + 8), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2800));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_137950;
L_137870:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[19] + 67),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_LE) goto L_137908;
L_13787c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 48));
    if (((cpu->regs[1] >> 7) & 1)) goto L_137920;
L_137888:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_13789c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_137978;
L_13789c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1378b0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_137980;
L_1378b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_1378d0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 32), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1378d0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1379cc;
L_1378d0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_1378e8;
L_1378d8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
L_1378e8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1378d8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1378d8;
    cpu->regs[30] = PB_BASE + 0x137904ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1378d8;
L_137908:
    cpu->regs[0] = cpu->regs[19] + 72ULL;
    cpu->regs[1] = 4ULL;
    PB_STRB((cpu->regs[19] + 67), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), 0ULL);
    cpu->regs[30] = PB_BASE + 0x13791cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1136c0ULL);
    goto L_13787c;
L_137920:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 56));
    if ((cpu->regs[2])==0) goto L_137888;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[19] + 56), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_137888;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_137888;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x137948ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    goto L_137888;
L_137950:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_137870;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 56), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_137870;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_137870;
    cpu->regs[30] = PB_BASE + 0x137974ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_137870;
L_137978:
    cpu->regs[30] = PB_BASE + 0x13797cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13789c;
L_137980:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1378b0;
    cpu->regs[30] = PB_BASE + 0x137990ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1378b0;
L_137994:
    cpu->regs[30] = PB_BASE + 0x137998ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x13f6ecULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1379a8ULL; PB_CALL(24, cpu, tlb, cpu->regs[1]);
    cpu->regs[3] = cpu->tls_ptr;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[2] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    goto L_13780c;
L_1379c0:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1379cc:
    cpu->regs[30] = PB_BASE + 0x1379d0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1378d0;
    /* nop */
    /* nop */
    /* nop */
}
