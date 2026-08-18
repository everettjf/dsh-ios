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

void ft__PyType_GetTextSignatureFromInternalDoc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x24592cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x18d1e0ULL);
    if ((cpu->regs[0])==0) goto L_245958;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x24593cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18d260ULL);
    if ((cpu->regs[0])==0) goto L_245968;
    cpu->regs[1] = cpu->regs[0] - 5ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe1ec0ULL); return; };
L_245958:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_245960:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_245968:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_245960;
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if ((cpu->regs[2])==0) goto L_246690;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GT) goto L_246674;
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(27ULL)));
    if (FLAG_LS) goto L_245aa0;
    cpu->regs[21] = 0ULL;
L_2459cc:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 64),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x2459d4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1616));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2459ecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_24665c;
L_2459f8:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 68),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x245a00ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1304));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245a18ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_246644;
L_245a24:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 72),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x245a2cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1392));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245a44ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_24662c;
L_245a50:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 76),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x245a58ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1384));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245a70ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_246a48;
L_245a7c:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_245a90:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_245aa0:
    cpu->regs[1] = PB_BASE + 0x2b5000ULL;
    cpu->regs[1] = cpu->regs[1] + 800ULL;
    PB_LDRH(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(uint32_t)(cpu->regs[0])) << 1)));
    cpu->regs[0] = PB_BASE + 0x245ab8ULL;
    cpu->regs[1] = cpu->regs[0] + (((uint64_t)(int64_t)(int16_t)(cpu->regs[1])) << 2);
    prebuilt_call(cpu, tlb, cpu->regs[1]); return;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 856));
    cpu->regs[30] = PB_BASE + 0x245ac0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_2459cc;
L_245ac8:
    cpu->regs[19] = 0ULL;
    cpu->regs[21] = 0ULL;
L_245ad0:
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x245ae4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245aecULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdce4cULL);
L_245aec:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_245a90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 368));
    cpu->regs[30] = PB_BASE + 0x245b04ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
L_245b0c:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_246398;
L_245b2c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1664));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245b3cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_2463a0;
L_245b4c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x245b5cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x246b0cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1192));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245b74ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245b90;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2463b8;
L_245b90:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x245000ULL;
    cpu->regs[3] = cpu->regs[3] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x245ba8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1248));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245bc0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245bdc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2463d0;
L_245bdc:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 32));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x16e000ULL;
    cpu->regs[3] = cpu->regs[3] + 3752ULL;
    cpu->regs[30] = PB_BASE + 0x245bf4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1352));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245c0cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245c28;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246374;
L_245c28:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 40));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x245c38ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1768));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245c50ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_246380;
L_245c60:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 48));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_245e64;
L_245c80:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1864));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245c90ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_246404;
L_245ca0:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 56));
L_245ca4:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x9f000ULL;
    cpu->regs[3] = cpu->regs[3] + 2908ULL;
    cpu->regs[30] = PB_BASE + 0x245cb8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1896));
L_245cc4:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245cd0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2459cc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2459cc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x245cf4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2459cc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 320));
    cpu->regs[30] = PB_BASE + 0x245d00ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
L_245d08:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
L_245d0c:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x245d18ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1920));
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 896));
    cpu->regs[30] = PB_BASE + 0x245d30ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x245d48ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1400));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245d60ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245d7c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246368;
L_245d7c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x245d8cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1280));
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 72));
    cpu->regs[30] = PB_BASE + 0x245da4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x16e000ULL;
    cpu->regs[3] = cpu->regs[3] + 3752ULL;
    cpu->regs[30] = PB_BASE + 0x245dc4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1840));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245ddcULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245df8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_245e6c;
L_245df8:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x245e08ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1920));
L_245e14:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245e20ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245e3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_245e78;
L_245e3c:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 24));
L_245e40:
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_245e84;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1864));
    goto L_245cc4;
L_245e64:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_245c80;
L_245e6c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x245e74ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245df8;
L_245e78:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x245e80ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245e3c;
L_245e84:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1864));
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 712));
    cpu->regs[30] = PB_BASE + 0x245e98ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x245eb0ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1816));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245ec8ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245ee4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246020;
L_245ee4:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0xa0000ULL;
    cpu->regs[3] = cpu->regs[3] + 964ULL;
    cpu->regs[30] = PB_BASE + 0x245efcULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1272));
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 984));
    cpu->regs[30] = PB_BASE + 0x245f14ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
L_245f1c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[24] = PB_BASE + 0x245000ULL;
    cpu->regs[3] = cpu->regs[24] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x245f34ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1248));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245f4cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245f68;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246174;
L_245f68:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0xa0000ULL;
    cpu->regs[3] = cpu->regs[3] + 1736ULL;
    cpu->regs[30] = PB_BASE + 0x245f80ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1472));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245f98ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245fb4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246278;
L_245fb4:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[3] = cpu->regs[24] + 2432ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x245fc8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1720));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x245fe0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_245ffc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2462a8;
L_245ffc:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 32));
    cpu->regs[3] = cpu->regs[24] + 2432ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246010ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1432));
    goto L_245cc4;
L_246020:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246028ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245ee4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 448));
    cpu->regs[30] = PB_BASE + 0x246034ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_246060;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_246060:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1648));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246070ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24608c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24629c;
L_24608c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x98000ULL;
    cpu->regs[3] = cpu->regs[3] + 3720ULL;
    cpu->regs[30] = PB_BASE + 0x2460a4ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1672));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2460bcULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2460d8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2462b4;
L_2460d8:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 24),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x2460e0ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1608));
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 456));
    cpu->regs[30] = PB_BASE + 0x2460f8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x98000ULL;
    cpu->regs[3] = cpu->regs[3] + 3720ULL;
    cpu->regs[30] = PB_BASE + 0x246118ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1672));
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 992));
    cpu->regs[30] = PB_BASE + 0x246130ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_245f1c;
    goto L_245ac8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 392));
    cpu->regs[30] = PB_BASE + 0x246144ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
L_24614c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x87000ULL;
    cpu->regs[3] = cpu->regs[3] + 484ULL;
    cpu->regs[30] = PB_BASE + 0x246164ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1672));
    goto L_245cc4;
L_246174:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24617cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245f68;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 64));
    cpu->regs[30] = PB_BASE + 0x246188ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2461a0ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1848));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2461b8ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2461d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246284;
L_2461d4:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2461e4ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1656));
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 96));
    cpu->regs[30] = PB_BASE + 0x2461fcULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
L_246204:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0xa0000ULL;
    cpu->regs[3] = cpu->regs[3] + 1392ULL;
    cpu->regs[30] = PB_BASE + 0x24621cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1504));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246234ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246250;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246290;
L_246250:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x245000ULL;
    cpu->regs[3] = cpu->regs[3] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x246268ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1248));
    goto L_245e14;
L_246278:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246280ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245fb4;
L_246284:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24628cULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2461d4;
L_246290:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246298ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246250;
L_24629c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2462a4ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24608c;
L_2462a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2462b0ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245ffc;
L_2462b4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2462bcULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2460d8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1008));
    cpu->regs[30] = PB_BASE + 0x2462c8ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2462e0ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1664));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2462f8ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246314;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2463c4;
L_246314:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x9f000ULL;
    cpu->regs[3] = cpu->regs[3] + 2908ULL;
    cpu->regs[30] = PB_BASE + 0x24632cULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1896));
L_246338:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246344ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246360;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2465fc;
L_246360:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    goto L_245d0c;
L_246368:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246370ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245d7c;
L_246374:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24637cULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245c28;
L_246380:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_245c60;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246394ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245c60;
L_246398:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_245b2c;
L_2463a0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_245b4c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2463b4ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245b4c;
L_2463b8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2463c0ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245b90;
L_2463c4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2463ccULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246314;
L_2463d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2463d8ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245bdc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 776));
    cpu->regs[30] = PB_BASE + 0x2463e4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_24614c;
    goto L_245ac8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 904));
    cpu->regs[30] = PB_BASE + 0x2463f8ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_245d08;
    goto L_245ac8;
L_246404:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_245ca0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246418ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245ca0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 88));
    cpu->regs[30] = PB_BASE + 0x246424ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_245b0c;
    goto L_245ac8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 256));
    cpu->regs[30] = PB_BASE + 0x246438ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x16e000ULL;
    cpu->regs[3] = cpu->regs[3] + 3752ULL;
    cpu->regs[30] = PB_BASE + 0x246458ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1840));
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 208));
    cpu->regs[30] = PB_BASE + 0x246470ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_24649c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_24649c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1664));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2464acULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2464c8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24660c;
L_2464c8:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[24] = PB_BASE + 0x16e000ULL;
    cpu->regs[3] = cpu->regs[24] + 3752ULL;
    cpu->regs[30] = PB_BASE + 0x2464e0ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1240));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2464f8ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246514;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246aa4;
L_246514:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x81000ULL;
    cpu->regs[3] = cpu->regs[3] + 2556ULL;
    cpu->regs[30] = PB_BASE + 0x24652cULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1544));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246544ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246560;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246ad4;
L_246560:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 32));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x245000ULL;
    cpu->regs[3] = cpu->regs[3] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x246578ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1248));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246590ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2465ac;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246af0;
L_2465ac:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 40));
    cpu->regs[3] = cpu->regs[24] + 3752ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2465c0ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1352));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2465d8ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2465f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246afc;
L_2465f4:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 48));
    goto L_245ca4;
L_2465fc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246604ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    goto L_245d0c;
L_24660c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246614ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2464c8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1088));
    cpu->regs[30] = PB_BASE + 0x246620ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_246204;
    goto L_245ac8;
L_24662c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_245a50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246640ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245a50;
L_246644:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_245a24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246658ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245a24;
L_24665c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2459f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246670ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2459f8;
L_246674:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x24668cULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_245aec;
L_246690:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    goto L_245a90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 192));
    cpu->regs[30] = PB_BASE + 0x2466a4ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_2459cc;
    goto L_245ac8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 232));
    cpu->regs[30] = PB_BASE + 0x2466b8ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_2459cc;
    goto L_245ac8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 352));
    cpu->regs[30] = PB_BASE + 0x2466ccULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
L_2466d4:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2466e4ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1832));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2466fcULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246718;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2468ec;
L_246718:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246728ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1512));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246740ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24675c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246ab0;
L_24675c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[24] = PB_BASE + 0x245000ULL;
    cpu->regs[3] = cpu->regs[24] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x246774ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1248));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24678cULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2467a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246abc;
L_2467a8:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 32));
    cpu->regs[3] = cpu->regs[24] + 2432ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2467bcULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1720));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2467d4ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2467f0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246ae0;
L_2467f0:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 40));
    goto L_245e40;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    cpu->regs[30] = PB_BASE + 0x246800ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246818ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1832));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246830ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24684c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246a3c;
L_24684c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24685cULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1168));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246874ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246890;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246a60;
L_246890:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2468a0ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1920));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2468b8ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2468d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246a78;
L_2468d4:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[22] + 32),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x2468dcULL; PB_CALL(133, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1784));
    goto L_245cc4;
L_2468ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2468f4ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246718;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1080));
    cpu->regs[30] = PB_BASE + 0x246900ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
L_246908:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246918ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1848));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x246930ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24694c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246a6c;
L_24694c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[24] = PB_BASE + 0x245000ULL;
    cpu->regs[3] = cpu->regs[24] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x246964ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1248));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24697cULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246998;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246a84;
L_246998:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[3] = cpu->regs[24] + 2432ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2469acULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1720));
    goto L_245cc4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 112));
    cpu->regs[30] = PB_BASE + 0x2469c4ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ac8;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2469dcULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_245ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1832));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2469f4ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_245ad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246a10;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246ac8;
L_246a10:
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246a1cULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x25c348ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1680));
    goto L_246338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 440));
    cpu->regs[30] = PB_BASE + 0x246a30ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_246908;
    goto L_245ac8;
L_246a3c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246a44ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24684c;
L_246a48:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_245a7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246a5cULL; PB_CALL(147, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_245a7c;
L_246a60:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246a68ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246890;
L_246a6c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246a74ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24694c;
L_246a78:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246a80ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2468d4;
L_246a84:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246a8cULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246998;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 80));
    cpu->regs[30] = PB_BASE + 0x246a98ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_2466d4;
    goto L_245ac8;
L_246aa4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246aacULL; PB_CALL(153, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246514;
L_246ab0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246ab8ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24675c;
L_246abc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246ac4ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2467a8;
L_246ac8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246ad0ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246a10;
L_246ad4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246adcULL; PB_CALL(157, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246560;
L_246ae0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246ae8ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 40));
    goto L_245e40;
L_246af0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246af8ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2465ac;
L_246afc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246b04ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 48));
    goto L_245ca4;
L_246b0c:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if ((cpu->regs[2])==0) goto L_246e18;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GT) goto L_246dfc;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1208));
    cpu->regs[30] = PB_BASE + 0x246b4cULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_246dc4;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 0));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[24] = PB_BASE + 0x246000ULL;
    cpu->regs[3] = cpu->regs[24] + 3620ULL;
    cpu->regs[30] = PB_BASE + 0x246b6cULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_246d94;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1752));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246b84ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_246d98;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246ba0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246d88;
L_246ba0:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[3] = cpu->regs[24] + 3620ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246bb4ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_246d94;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1192));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246bccULL; PB_CALL(165, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_246d98;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246be8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246dd8;
L_246be8:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246bf8ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x246e24ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_246d94;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1936));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246c10ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_246d98;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_246d70;
L_246c20:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 24));
    cpu->regs[3] = cpu->regs[24] + 3620ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246c34ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_246d94;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1592));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246c4cULL; PB_CALL(169, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_246d98;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246c68;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246dcc;
L_246c68:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 32));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[24] = PB_BASE + 0x16e000ULL;
    cpu->regs[3] = cpu->regs[24] + 3752ULL;
    cpu->regs[30] = PB_BASE + 0x246c80ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_246d94;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1560));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246c98ULL; PB_CALL(171, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_246d98;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246cb4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246de4;
L_246cb4:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 40));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246cc4ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0x246e24ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_246d94;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1568));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246cdcULL; PB_CALL(173, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_246d98;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_246d58;
L_246cec:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 48));
    cpu->regs[3] = cpu->regs[24] + 3752ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246d00ULL; PB_CALL(174, cpu, tlb, PB_BASE + 0x170270ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_246d94;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1360));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246d18ULL; PB_CALL(175, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_246d98;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_246d34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_246df0;
L_246d34:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_246d48:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_246d58:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246cec;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246d6cULL; PB_CALL(176, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246cec;
L_246d70:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246c20;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246d84ULL; PB_CALL(177, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246c20;
L_246d88:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246d90ULL; PB_CALL(178, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246ba0;
L_246d94:
    cpu->regs[19] = 0ULL;
L_246d98:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x246dacULL; PB_CALL(179, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246db4ULL; PB_CALL(180, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_246db8:
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_246d48;
L_246dc4:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_246db8;
L_246dcc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246dd4ULL; PB_CALL(181, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246c68;
L_246dd8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246de0ULL; PB_CALL(182, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246be8;
L_246de4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246decULL; PB_CALL(183, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246cb4;
L_246df0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x246df8ULL; PB_CALL(184, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246d34;
L_246dfc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x246e14ULL; PB_CALL(185, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_246db8;
L_246e18:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    goto L_246d48;
L_246e24:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if ((cpu->regs[2])==0) goto L_246ff8;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GT) goto L_2470ec;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1184));
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x246e64ULL; PB_CALL(186, cpu, tlb, PB_BASE + 0x115740ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2470bc;
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2470e4;
L_246e8c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1176));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246e9cULL; PB_CALL(187, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2470a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_2470cc;
L_246eac:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x246ebcULL; PB_CALL(188, cpu, tlb, PB_BASE + 0x16eea8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24709c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1168));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246ed4ULL; PB_CALL(189, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2470a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_247084;
L_246ee4:
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_24707c;
L_246f04:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1864));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246f14ULL; PB_CALL(190, cpu, tlb, PB_BASE + 0xe28a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2470a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_247064;
L_246f24:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[21] + 24),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x246f2cULL; PB_CALL(191, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24709c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1616));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246f44ULL; PB_CALL(192, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2470a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_247034;
L_246f50:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[21] + 28),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x246f58ULL; PB_CALL(193, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24709c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1304));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246f70ULL; PB_CALL(194, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2470a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_24704c;
L_246f7c:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[21] + 32),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x246f84ULL; PB_CALL(195, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24709c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1392));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246f9cULL; PB_CALL(196, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2470a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_24701c;
L_246fa8:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[21] + 36),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x246fb0ULL; PB_CALL(197, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24709c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 1384));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x246fc8ULL; PB_CALL(198, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2470a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_247004;
L_246fd4:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_246fe8:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_246ff8:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    goto L_246fe8;
L_247004:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246fd4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247018ULL; PB_CALL(199, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246fd4;
L_24701c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246fa8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247030ULL; PB_CALL(200, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246fa8;
L_247034:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246f50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247048ULL; PB_CALL(201, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246f50;
L_24704c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246f7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247060ULL; PB_CALL(202, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246f7c;
L_247064:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246f24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247078ULL; PB_CALL(203, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246f24;
L_24707c:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_246f04;
L_247084:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246ee4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247098ULL; PB_CALL(204, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246ee4;
L_24709c:
    cpu->regs[19] = 0ULL;
L_2470a0:
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x2470b4ULL; PB_CALL(205, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2470bcULL; PB_CALL(206, cpu, tlb, PB_BASE + 0xdce4cULL);
L_2470bc:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_246fe8;
L_2470cc:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_246eac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2470e0ULL; PB_CALL(207, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_246eac;
L_2470e4:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_246e8c;
L_2470ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x247104ULL; PB_CALL(208, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2470bc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3064));
    { PB_CALL(209, cpu, tlb, PB_BASE + 0x1a3d00ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_247130;
    cpu->regs[1] = 6ULL;
    { PB_CALL(210, cpu, tlb, PB_BASE + 0x221c28ULL); return; };
L_247130:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    /* nop */
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]);
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3];
    if ((cpu->regs[3])!=0) goto L_247234;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_2471f0;
    FLAG_CMP(cpu->regs[5], 0ULL);
    cpu->regs[21] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_24723c;
L_247190:
    PB_LDR(cpu->regs[20], (cpu->regs[5] + 0));
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_NE) goto L_24722c;
    cpu->regs[21] = 0ULL;
L_2471a0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2471a8ULL; PB_CALL(211, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_247278;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_247294;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80));
    SP = SP + 96ULL;
    goto L_2472b0;
L_2471f0:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 80ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x247220ULL; PB_CALL(212, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_247278;
    PB_LDR(cpu->regs[20], (cpu->regs[5] + 0));
L_24722c:
    PB_LDR(cpu->regs[21], (cpu->regs[5] + 8));
    goto L_2471a0;
L_247234:
    PB_LDR(cpu->regs[21], (cpu->regs[3] + 16));
    cpu->regs[21] = cpu->regs[2] + cpu->regs[21];
L_24723c:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[4] + 80ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x247270ULL; PB_CALL(213, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_247190;
L_247278:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_247298;
L_247294:
    cpu->regs[30] = PB_BASE + 0x247298ULL; PB_CALL(214, cpu, tlb, PB_BASE + 0x7c170ULL);
L_247298:
    PB_LDR(cpu->regs[21], (SP + 80));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_2472b0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 48));
    if ((cpu->regs[4])==0) goto L_24732c;
    cpu->regs[2] = cpu->regs[3];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x2472e0ULL; PB_CALL(215, cpu, tlb, PB_BASE + 0x2219f0ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_247328;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 64));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[0] << 3)));
    if ((cpu->regs[1])==0) goto L_247328;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x247300ULL; PB_CALL(216, cpu, tlb, PB_BASE + 0x247380ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_247374;
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(217, cpu, tlb, PB_BASE + 0x1a988cULL); return; };
L_247328:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_24732c:
    cpu->regs[30] = PB_BASE + 0x247330ULL; PB_CALL(218, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_24736c;
    if ((cpu->regs[22])==0) goto L_247358;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_247348;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_247348:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_247358:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x24736cULL; PB_CALL(219, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
L_24736c:
    cpu->regs[22] = 0ULL;
    goto L_247348;
L_247374:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[22] = 0ULL;
    goto L_247348;
L_247380:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 48));
    if ((cpu->regs[3])==0) goto L_2473e8;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x2473a8ULL; PB_CALL(220, cpu, tlb, PB_BASE + 0x2219f0ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_247404;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 64));
    cpu->regs[0] = cpu->regs[0] << 3;
    if ((cpu->regs[19])==0) goto L_2473f8;
L_2473b8:
    PB_STR((cpu->regs[1] + cpu->regs[0]), 0ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2473c8ULL; PB_CALL(221, cpu, tlb, PB_BASE + 0x247420ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_2473e0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_247414;
L_2473e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2473e8ULL; PB_CALL(222, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_2473e8:
    cpu->regs[0] = 0ULL;
L_2473ec:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2473f8:
    PB_LDR(cpu->regs[19], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[19])!=0) goto L_2473b8;
    goto L_2473e8;
L_247404:
    cpu->regs[30] = PB_BASE + 0x247408ULL; PB_CALL(223, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
    goto L_2473ec;
L_247414:
    cpu->regs[30] = PB_BASE + 0x247418ULL; PB_CALL(224, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2473e0;
    /* nop */
L_247420:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 48));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_247464;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    PB_STR((cpu->regs[0] + 48), cpu->regs[2]);
L_247434:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 56));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_247478;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    if ((cpu->regs[2])==0) goto L_247450;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 24));
    PB_STR((cpu->regs[2] + 24), cpu->regs[3]);
L_247450:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 88));
    PB_STR((cpu->regs[1] + 16), 0ULL); PB_STR((cpu->regs[1] + 16) + 8, 0ULL);
    cpu->regs[1] = cpu->regs[2] + 1ULL;
    PB_STR((cpu->regs[0] + 88), cpu->regs[1]);
    return;
L_247464:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    if ((cpu->regs[2])==0) goto L_247434;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    PB_STR((cpu->regs[2] + 16), cpu->regs[3]);
    goto L_247434;
L_247478:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    PB_STR((cpu->regs[0] + 56), cpu->regs[2]);
    goto L_247450;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_2474f8;
L_2474a8:
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 48));
L_2474ac:
    cpu->regs[1] = cpu->regs[20];
    if ((cpu->regs[19])==0) goto L_2474cc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_2474c4;
    cpu->regs[30] = PB_BASE + 0x2474c0ULL; PB_CALL(225, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_247504;
L_2474c4:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    goto L_2474ac;
L_2474cc:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2680));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 184));
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_2474f8:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x247500ULL; PB_CALL(226, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2474a8;
L_247504:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(227, cpu, tlb, PB_BASE + 0x247528ULL); return; };
}
