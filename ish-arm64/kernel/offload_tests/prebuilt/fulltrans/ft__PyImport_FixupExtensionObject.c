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

void ft__PyImport_FixupExtensionObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1f46d0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe97e4ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f4710;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f46e4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1909e8ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f4704;
L_1f46f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f4704:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f4710ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x144960ULL);
L_1f4710:
    cpu->regs[0] = 4294967295ULL;
    goto L_1f46f4;
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1f4860;
L_1f4748:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f4850;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_EQ) goto L_1f4818;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
L_1f4770:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f4778ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1f49c4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f47a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f4838;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 15ULL;
    cpu->regs[30] = PB_BASE + 0x1f4798ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1f47c8;
L_1f479c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_1f47a0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[4] = cpu->regs[20];
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1f47b4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1f47c8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f47d0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1f49c4ULL);
    cpu->regs[7] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f479c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1f47e4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f488c;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1f4808ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1a6780ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f4868;
    cpu->regs[20] = cpu->regs[0];
    goto L_1f47a0;
L_1f4818:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f4820ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f48a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1f4770;
L_1f4838:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1f47b4;
L_1f4850:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1f47b4;
L_1f4860:
    cpu->regs[30] = PB_BASE + 0x1f4864ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f4748;
L_1f4868:
    cpu->regs[30] = PB_BASE + 0x1f486cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1f47a0;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1f47b4;
L_1f488c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1f47b4;
L_1f48a0:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[4] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1f47b4;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1f48e8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x15bbccULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f49b0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 344));
    if ((cpu->regs[4])==0) goto L_1f495c;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 16));
    cpu->regs[6] = PB_BASE + 0x1f4000ULL;
    cpu->regs[5] = cpu->regs[4] + 24ULL;
    cpu->regs[6] = cpu->regs[6] + 1504ULL;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
L_1f4910:
    if (((cpu->regs[3] >> 63) & 1)) goto L_1f4984;
    PB_LDR(cpu->regs[4], (cpu->regs[5] + (cpu->regs[3] << 3)));
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 152));
    FLAG_CMP(cpu->regs[2], cpu->regs[6]);
    if (FLAG_EQ) goto L_1f4910;
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 152));
    FLAG_CMP(cpu->regs[2], cpu->regs[7]);
    if (FLAG_NE) goto L_1f4910;
L_1f4934:
    cpu->regs[3] = PB_BASE + 0x1f4000ULL;
    cpu->regs[3] = cpu->regs[3] + 1504ULL;
L_1f493c:
    if ((cpu->regs[4])==0) goto L_1f495c;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 152));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_1f495c;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_1f498c;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 256));
    goto L_1f493c;
L_1f495c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f4968ULL; PB_CALL(13, cpu, tlb, cpu->regs[19]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f49b0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1f4974:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f4984:
    cpu->regs[4] = cpu->regs[0];
    goto L_1f4934;
L_1f498c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[2] = PB_BASE + 0x294000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[2] + 2832ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x1f49b0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1f49b0:
    cpu->regs[0] = 0ULL;
    goto L_1f4974;
    /* nop */
    /* nop */
    { PB_CALL(15, cpu, tlb, PB_BASE + 0x1aaec0ULL); return; };
L_1f49c4:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1f4ab0;
L_1f49ec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f4aa0;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f4a00ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x116c80ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f4a2c;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1f4a10:
    cpu->regs[2] = 0ULL;
L_1f4a14:
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_1f4a18:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1f4a2c:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_1f4a58;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2320));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f4a58;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    goto L_1f4a14;
L_1f4a58:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[2] + 36),&_a,4); tlb_read(tlb,(cpu->regs[2] + 40),&_b,4); cpu->regs[3]=(uint64_t)(int64_t)_a; cpu->regs[4]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = PB_BASE + 0x294000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[6] = cpu->regs[6] + 2888ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 44),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1f4a80ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x1f4a84ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1f4a10;
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1f4a18;
L_1f4aa0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1f4a18;
L_1f4ab0:
    cpu->regs[30] = PB_BASE + 0x1f4ab4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f49ec;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1f4ba8;
L_1f4ae8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f4b98;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[1] = PB_BASE + 0x2b1000ULL;
    cpu->regs[1] = cpu->regs[1] + 3368ULL;
    cpu->regs[30] = PB_BASE + 0x1f4b08ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x196ae4ULL);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((cpu->regs[0])!=0) goto L_1f4b20;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f4b18ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f4b48;
L_1f4b20:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_1f4b24:
    cpu->regs[3] = 0ULL;
L_1f4b28:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1f4b34:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f4b48:
    cpu->regs[1] = PB_BASE + 0x1f6000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 864ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f4b5cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f4b20;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1f4b70ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x10d8f0ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f4b28;
    cpu->regs[30] = PB_BASE + 0x1f4b7cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1f4b24;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1f4b34;
L_1f4b98:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1f4b34;
L_1f4ba8:
    cpu->regs[30] = PB_BASE + 0x1f4bacULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f4ae8;
    cpu->regs[6] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 2ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_1f4c88;
    cpu->regs[5] = cpu->regs[1];
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[7] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2864));
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1f4bdcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f4bec;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1f4be8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f4bfc;
L_1f4bec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
L_1f4bf4:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1f4bfc:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[7] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f4c38;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(2ULL)));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_1f4c24:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1f4bf4;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1f4bf4;
L_1f4c38:
    PB_LDR(cpu->regs[1], (cpu->regs[7] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1f4c6c;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    goto L_1f4c24;
L_1f4c6c:
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    goto L_1f4c24;
L_1f4c88:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1f4dec;
L_1f4cc8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f4ddc;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_1f4d8c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20) + 4);
L_1f4cec:
    cpu->regs[1] = PB_BASE + 0x2b1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3368ULL;
    cpu->regs[30] = PB_BASE + 0x1f4cfcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x196ae4ULL);
    if ((cpu->regs[0])!=0) goto L_1f4d28;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1f4d04:
    cpu->regs[3] = 0ULL;
L_1f4d08:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1f4d14:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f4d28:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1f4d34ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f4d08;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 28));
    cpu->regs[1] = 56ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1f4d4cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1085d0ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f4d6c;
    cpu->regs[0] = 7ULL;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[3] + 8), 0ULL); PB_STR((cpu->regs[3] + 8) + 8, 0ULL);
    PB_STRW((cpu->regs[3] + 40), cpu->regs[21]); PB_STRW((cpu->regs[3] + 40) + 4, cpu->regs[22]);
    PB_STR((cpu->regs[3] + 48), cpu->regs[20]);
    goto L_1f4d08;
L_1f4d6c:
    cpu->regs[30] = PB_BASE + 0x1f4d70ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1f4d04;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1f4d14;
L_1f4d8c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f4d94ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f4dc0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1f4cec;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1f4d14;
L_1f4dc0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1f4d14;
L_1f4ddc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1f4d14;
L_1f4dec:
    cpu->regs[30] = PB_BASE + 0x1f4df0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f4cc8;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 22488));
    if ((cpu->regs[19])==0) goto L_1f4e54;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1f4e60;
L_1f4e2c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f4e34ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1c17e0ULL);
L_1f4e34:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f4e50;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1f4e50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f4e50ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1f4e50:
    PB_STR((cpu->regs[20] + 22488), 0ULL);
L_1f4e54:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1f4e60:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 1712));
    if (((cpu->regs[0] >> 5) & 1)) goto L_1f4e34;
    goto L_1f4e2c;
    SP = SP - 64ULL;
    cpu->regs[4] = 2ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[6] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[5] = SP + 8ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[0] + 16));
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 2760));
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[2] = PB_BASE + 0x28b000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = cpu->regs[2] + 584ULL;
    PB_STR((SP + 0), cpu->regs[8]);
    PB_STR((SP + 16), cpu->regs[7]);
    cpu->regs[30] = PB_BASE + 0x1f4ec8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x15594cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f4f1c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 45512ULL;
    cpu->regs[1] = SP;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[2] = 9223372036854775811ULL;
    cpu->regs[30] = PB_BASE + 0x1f4eecULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x147564ULL);
L_1f4eec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1f4f18;
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1f4f18:
    cpu->regs[30] = PB_BASE + 0x1f4f1cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f4f1c:
    cpu->regs[0] = 0ULL;
    goto L_1f4eec;
L_1f4f24:
    SP = SP - 112ULL;
    cpu->regs[3] = 6000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_1f5110;
L_1f4f64:
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 1081ULL;
    PB_STR((SP + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1f4f78ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x196cacULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f4fc0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[20], (SP + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_1f4f88:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f50fc;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 112ULL;
    return;
L_1f4fc0:
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = 6000ULL;
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((SP + 96), cpu->regs[27]);
    cpu->regs[22] = cpu->regs[23];
L_1f4fdc:
    PB_LDR(cpu->regs[20], (SP + 0));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1081ULL;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f4ff4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f5118;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[24])));
    if (FLAG_EQ) goto L_1f5174;
L_1f5010:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f5150;
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1f5130;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[25])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
L_1f5030:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f5038ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1f5384ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f5074;
L_1f5040:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
L_1f5044:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1f5158;
L_1f5058:
    PB_LDR(cpu->regs[27], (SP + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_1f4f88;
L_1f5074:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 23ULL;
    cpu->regs[30] = PB_BASE + 0x1f5080ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1f5040;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f508cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f5040;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1f50a0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f5044;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 8));
    cpu->regs[3] = cpu->regs[26];
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[21];
    PB_LDRW(cpu->regs[5], (cpu->regs[2] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[2] + 28) + 4);
    cpu->regs[2] = 1ULL;
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1f50c8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x10dae0ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f5180;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_1f5158;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_LE) goto L_1f5058;
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 0), cpu->regs[2]);
    goto L_1f4fdc;
L_1f50fc:
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    PB_STR((SP + 96), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x1f5110ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f5110:
    cpu->regs[30] = PB_BASE + 0x1f5114ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f4f64;
L_1f5118:
    PB_LDR(cpu->regs[27], (SP + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_1f4f88;
L_1f5130:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f5138ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f5188;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[25])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1f5030;
L_1f5150:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_1f5158:
    PB_LDR(cpu->regs[27], (SP + 96));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_1f4f88;
L_1f5174:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f517cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f5010;
L_1f5180:
    cpu->regs[30] = PB_BASE + 0x1f5184ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1f5044;
L_1f5188:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1f5158;
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[5] = SP + 8ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[4] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1f51ecULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f5310;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 344));
    if ((cpu->regs[4])==0) goto L_1f5318;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 16));
    cpu->regs[1] = cpu->regs[3];
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_LT) goto L_1f5298;
    cpu->regs[0] = cpu->regs[4] + (cpu->regs[5] << 3);
    cpu->regs[2] = PB_BASE + 0x1f4000ULL;
    cpu->regs[8] = cpu->regs[2] + 1504ULL;
    cpu->regs[6] = cpu->regs[5];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[7], (cpu->regs[1] + 152));
    FLAG_CMP(cpu->regs[7], cpu->regs[8]);
    if (FLAG_EQ) goto L_1f5238;
    PB_LDR(cpu->regs[8], (cpu->regs[3] + 152));
    FLAG_CMP(cpu->regs[7], cpu->regs[8]);
    if (FLAG_EQ) goto L_1f5298;
L_1f5238:
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_EQ) goto L_1f5294;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = cpu->regs[2] + 1504ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[1] + 152));
    FLAG_CMP(cpu->regs[7], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f5260;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 152));
    FLAG_CMP(cpu->regs[7], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f5298;
L_1f5260:
    FLAG_CMP(cpu->regs[5], 2ULL);
    if (FLAG_EQ) goto L_1f5294;
    cpu->regs[2] = cpu->regs[2] + 1504ULL;
L_1f526c:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + (cpu->regs[6] << 3)));
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 152));
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    if (FLAG_EQ) goto L_1f5288;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 152));
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f5298;
L_1f5288:
    cpu->regs[6] = cpu->regs[6] - 1ULL;
    FLAG_CMP(cpu->regs[6], 2ULL);
    if (FLAG_NE) goto L_1f526c;
L_1f5294:
    cpu->regs[1] = cpu->regs[3];
L_1f5298:
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 152));
    FLAG_CMP(cpu->regs[19], cpu->regs[4]);
    if (FLAG_EQ) goto L_1f5318;
    cpu->regs[2] = PB_BASE + 0x1f4000ULL;
    cpu->regs[2] = cpu->regs[2] + 1504ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_NE) goto L_1f52ec;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 256));
    if ((cpu->regs[0])==0) goto L_1f5318;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 152));
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_EQ) goto L_1f5318;
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_NE) goto L_1f52ec;
L_1f52d0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 256));
    if ((cpu->regs[0])==0) goto L_1f5318;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 152));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_1f5318;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_1f52d0;
L_1f52ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = PB_BASE + 0x294000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] + 2960ULL;
    cpu->regs[1] = cpu->regs[1] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x1f5310ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1f5310:
    cpu->regs[0] = 0ULL;
    goto L_1f5344;
L_1f5318:
    cpu->regs[3] = PB_BASE + 0xe2000ULL;
    cpu->regs[3] = cpu->regs[3] + 2764ULL;
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    cpu->regs[0] = cpu->regs[20];
    FLAG_CMP(cpu->regs[19], cpu->regs[3]);
    if (FLAG_NE) goto L_1f5370;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f5338ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe2ae0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f5310;
L_1f533c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1f5344:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1f5380;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_1f5370:
    cpu->regs[30] = PB_BASE + 0x1f5374ULL; PB_CALL(54, cpu, tlb, cpu->regs[19]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1f533c;
    cpu->regs[0] = 0ULL;
    goto L_1f5344;
L_1f5380:
    cpu->regs[30] = PB_BASE + 0x1f5384ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f5384:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1f53f8;
L_1f53ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f5400;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f53c0ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x1f4f24ULL);
    if ((cpu->regs[0])!=0) goto L_1f53e0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1f53e0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f53d8ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x10642cULL);
    if ((cpu->regs[0])!=0) goto L_1f53e0;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1f53e0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1f53e8:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1f53f8:
    cpu->regs[30] = PB_BASE + 0x1f53fcULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f53ac;
L_1f5400:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1f53e8;
L_1f5410:
    SP = SP - 112ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f544cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1f5560ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f5550;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f5458ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xe1a08ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f5494;
L_1f5460:
    cpu->regs[0] = 0ULL;
L_1f5464:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1f5544;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 112ULL;
    return;
L_1f5494:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[22] = SP + 8ULL;
    cpu->regs[23] = SP + 16ULL;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2760));
    PB_STR((SP + 8), 0ULL);
    PB_STR((SP + 96), cpu->regs[25]);
L_1f54b0:
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f54c4ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f5538;
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1f54b0;
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_EQ) goto L_1f54b0;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1f54ecULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])==0) goto L_1f5510;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 29) & 1)) goto L_1f5510;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f5504ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdd250ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f5528;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f54b0;
L_1f5510:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f5520ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1f5410ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1f54b0;
L_1f5528:
    PB_LDR(cpu->regs[25], (SP + 96));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_1f5464;
L_1f5538:
    PB_LDR(cpu->regs[25], (SP + 96));
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_1f5460;
L_1f5544:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_STR((SP + 96), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x1f5550ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f5550:
    cpu->regs[0] = 4294967295ULL;
    goto L_1f5464;
    /* nop */
    /* nop */
L_1f5560:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
L_1f5574:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[20];
    if ((cpu->regs[1])!=0) goto L_1f5590;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1f5590:
    cpu->regs[19] = cpu->regs[19] + 8ULL;
    cpu->regs[30] = PB_BASE + 0x1f5598ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xecac4ULL);
    goto L_1f5574;
    /* nop */
    SP = SP - 144ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 72), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 16));
    if ((cpu->regs[2])!=0) goto L_1f5828;
    FLAG_CMP(cpu->regs[20], 3ULL);
    if (FLAG_HI) goto L_1f5a1c;
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[22] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_1f5834;
L_1f55f0:
    if ((cpu->regs[19])==0) goto L_1f57f0;
    PB_STR((SP + 128), cpu->regs[23]);
L_1f55f8:
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 0));
    if ((cpu->regs[23])==0) goto L_1f56dc;
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_NE) goto L_1f56dc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 26544ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1f5620ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xed124ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f56a4;
    cpu->regs[30] = PB_BASE + 0x1f562cULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x179564ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f564c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1f564c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f564cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1f564c:
    if ((cpu->regs[19])==0) goto L_1f5894;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 27) & 1)) goto L_1f59b4;
    PB_LDR(cpu->regs[23], (SP + 128));
L_1f5660:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2392));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_1f578c;
L_1f5670:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f5820;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_1f56a4:
    cpu->regs[30] = PB_BASE + 0x1f56a8ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1f5894;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_1f59f8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_1f574c;
L_1f56c0:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1f56c8ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x2078e0ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_1f5660;
L_1f56d4:
    cpu->regs[19] = 0ULL;
    goto L_1f5670;
L_1f56dc:
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 8));
    if ((cpu->regs[20])==0) goto L_1f58a0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1f5964;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[30] = PB_BASE + 0x1f56fcULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f5894;
    cpu->regs[30] = PB_BASE + 0x1f5708ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1f5940;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_1f58a0;
    if ((cpu->regs[23])==0) goto L_1f5928;
    cpu->regs[2] = 0ULL;
L_1f5724:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1f5990;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f573cULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x146d68ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 128));
    if ((cpu->regs[19])!=0) goto L_1f5660;
    goto L_1f56d4;
L_1f574c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    if ((cpu->regs[0])==0) goto L_1f56c0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2584));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1f5768ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x123dd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f5878;
    if (((cpu->regs[0] >> 63) & 1)) goto L_1f5a60;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1f577cULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xe9da0ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_1f5660;
    goto L_1f56d4;
L_1f578c:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 304));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f57a0ULL; PB_CALL(77, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f57d4;
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[2] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_1f5808;
    cpu->regs[3] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LO) goto L_1f5818;
L_1f57c8:
    cpu->regs[30] = PB_BASE + 0x1f57ccULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[20] + 24), cpu->regs[0]);
L_1f57d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f57e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f5918;
L_1f57e8:
    cpu->regs[19] = cpu->regs[20];
    goto L_1f5670;
L_1f57f0:
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f57fcULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_1f5660;
    goto L_1f56d4;
L_1f5808:
    if (FLAG_LS) goto L_1f57c8;
    cpu->regs[3] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_HS) goto L_1f57c8;
L_1f5818:
    PB_STR((SP + 128), cpu->regs[23]);
    __builtin_trap();
L_1f5820:
    PB_STR((SP + 128), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x1f5828ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f5828:
    PB_LDR(cpu->regs[19], (cpu->regs[2] + 16));
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    cpu->regs[19] = cpu->regs[20] + cpu->regs[19];
L_1f5834:
    cpu->regs[1] = SP + 48ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[4] + 3024ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f5868ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f55f0;
    cpu->regs[19] = 0ULL;
    goto L_1f5670;
L_1f5878:
    cpu->regs[30] = PB_BASE + 0x1f587cULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1f5a60;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f5890ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f5ad8;
L_1f5894:
    PB_LDR(cpu->regs[23], (SP + 128));
    cpu->regs[19] = 0ULL;
    goto L_1f5670;
L_1f58a0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1f5aac;
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[30] = PB_BASE + 0x1f58b8ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f5894;
    cpu->regs[30] = PB_BASE + 0x1f58c4ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[2], (SP + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1f5940;
    if ((cpu->regs[23])==0) goto L_1f5a84;
    if ((cpu->regs[20])!=0) goto L_1f5724;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 2160ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 168));
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] + 2120ULL;
    FLAG_CMP((cpu->regs[3]) & (268435456ULL), 0);
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[1];
L_1f5908:
    cpu->regs[30] = PB_BASE + 0x1f590cULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 128));
    goto L_1f5670;
L_1f5918:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f5924ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f5670;
L_1f5928:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2080ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_1f5908;
L_1f5940:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f595cULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    goto L_1f5670;
L_1f5964:
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1896ULL;
    cpu->regs[0] = PB_BASE + 0x286000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 208ULL;
    cpu->regs[30] = PB_BASE + 0x1f5988ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    goto L_1f5670;
L_1f5990:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2080ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f59acULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    goto L_1f5670;
L_1f59b4:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 3240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1f59d0ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f5894;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1f5894;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f59f0ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    goto L_1f5670;
L_1f59f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f5a14ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    goto L_1f5670;
L_1f5a1c:
    cpu->regs[0] = SP + 48ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    cpu->regs[4] = cpu->regs[4] + 3024ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f5a4cULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f56d4;
    cpu->regs[19] = cpu->regs[20];
    PB_STR((SP + 128), cpu->regs[23]);
    goto L_1f55f8;
L_1f5a60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2200ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f5a7cULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    goto L_1f5670;
L_1f5a84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = cpu->regs[2] + 2080ULL;
    cpu->regs[1] = cpu->regs[1] + 2120ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    goto L_1f5908;
L_1f5aac:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    cpu->regs[0] = PB_BASE + 0x286000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 208ULL;
    cpu->regs[30] = PB_BASE + 0x1f5ad0ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[23], (SP + 128));
    goto L_1f5670;
L_1f5ad8:
    cpu->regs[30] = PB_BASE + 0x1f5adcULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1f56c0;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1f5d34;
L_1f5b0c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f5cfc;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1f5cdc;
L_1f5b30:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1f5b3cULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x1f1de0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f5cc4;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1f5d28;
L_1f5b5c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f5d18;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = 8ULL;
    PB_STR((SP + 80), cpu->regs[27]);
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1f5b78ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f5ca4;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_1f5cb0;
    cpu->regs[21] = 0ULL;
    cpu->regs[26] = 1ULL;
L_1f5b90:
    cpu->regs[1] = 12ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f5b9cULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[1])!=0) goto L_1f5c44;
L_1f5ba8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[27]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f5bb8ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f5c9c;
L_1f5bc0:
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    FLAG_CMP(cpu->regs[21], cpu->regs[20]);
    if (FLAG_GT) goto L_1f5c68;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1f5bd4ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1f5bf0ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x118accULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1f5d08;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1f5c10ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f5cd0;
L_1f5c28:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_1f5c30:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1f5c44:
    cpu->regs[30] = PB_BASE + 0x1f5c48ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x1f1de0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f5ba8;
    FLAG_CMP(cpu->regs[26], cpu->regs[21]);
    if (FLAG_EQ) goto L_1f5c80;
L_1f5c58:
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[22] + (cpu->regs[21] << 3)), cpu->regs[23]);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_1f5b90;
L_1f5c68:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + cpu->regs[2]));
    PB_STR((cpu->regs[0] + cpu->regs[2]), cpu->regs[1]);
    goto L_1f5bc0;
L_1f5c80:
    cpu->regs[26] = cpu->regs[26] << 1;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[26] << 3;
    cpu->regs[30] = PB_BASE + 0x1f5c90ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_1f5c9c;
    cpu->regs[22] = cpu->regs[0];
    goto L_1f5c58;
L_1f5c9c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1f5ca4ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_1f5ca4:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1f5cb0ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1f5cb0:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1f5cc4:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1f5cd0:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    goto L_1f5c28;
L_1f5cdc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f5ce4ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f5b30;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_1f5cd0;
L_1f5cfc:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[20] = 0ULL;
    goto L_1f5c30;
L_1f5d08:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1f5cd0;
L_1f5d18:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_1f5cc4;
L_1f5d28:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f5d30ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f5b5c;
L_1f5d34:
    cpu->regs[30] = PB_BASE + 0x1f5d38ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    goto L_1f5b0c;
}
