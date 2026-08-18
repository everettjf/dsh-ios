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

void ft_PyNumber_Add(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x11a71cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2400));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_11a740;
L_11a730:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_11a740:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_11a78c;
L_11a748:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 104));
    if ((cpu->regs[1])==0) goto L_11a774;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    if ((cpu->regs[2])==0) goto L_11a774;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[16] = cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_11a774:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = cpu->regs[2] + 328ULL;
    cpu->regs[30] = PB_BASE + 0x11a784ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x230820ULL);
    cpu->regs[2] = 0ULL;
    goto L_11a730;
L_11a78c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11a748;
    cpu->regs[30] = PB_BASE + 0x11a79cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11a748;
L_11a7a0:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 96));
    if ((cpu->regs[4])==0) goto L_11a968;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[21], (cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    PB_STR((SP + 48), cpu->regs[23]);
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_NE) goto L_11a818;
L_11a7d8:
    if ((cpu->regs[21])==0) goto L_11a908;
L_11a7dc:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
L_11a7e4:
    cpu->regs[23] = 0ULL;
L_11a7e8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11a7f4ULL; PB_CALL(4, cpu, tlb, cpu->regs[21]);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_11a8b8;
L_11a800:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_11a808:
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_11a818:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 96));
    if ((cpu->regs[0])==0) goto L_11a7d8;
    PB_LDR(cpu->regs[23], (cpu->regs[0] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_EQ) goto L_11a7d8;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
    if ((cpu->regs[21])==0) goto L_11a8c0;
    if ((cpu->regs[23])==0) goto L_11a7dc;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 344));
    if ((cpu->regs[0])==0) goto L_11a91c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_11a8ac;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_11a92c;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_11a8ac;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_11a92c;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_11a8ac;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 40));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_11a92c;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[2] = 3ULL;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_11a8ac;
L_11a894:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + (cpu->regs[2] << 3)));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[4]);
    if (FLAG_EQ) goto L_11a92c;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_11a894;
L_11a8ac:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
    goto L_11a7e8;
L_11a8b8:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_11a9b0;
L_11a8c0:
    if ((cpu->regs[23])==0) goto L_11a908;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11a8d0ULL; PB_CALL(5, cpu, tlb, cpu->regs[23]);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_11a808;
L_11a8e4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_11a910;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_11a910;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    cpu->regs[30] = PB_BASE + 0x11a904ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11a910;
L_11a908:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_11a910:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2400));
    goto L_11a808;
L_11a91c:
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 256));
    if ((cpu->regs[5])==0) goto L_11a99c;
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_NE) goto L_11a91c;
L_11a92c:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11a940ULL; PB_CALL(7, cpu, tlb, cpu->regs[23]);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_11a800;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_11a7e4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11a7e4;
    cpu->regs[30] = PB_BASE + 0x11a964ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11a7e4;
L_11a968:
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_EQ) goto L_11a910;
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 96));
    if ((cpu->regs[3])==0) goto L_11a910;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    if ((cpu->regs[2])==0) goto L_11a910;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
    cpu->regs[30] = PB_BASE + 0x11a98cULL; PB_CALL(9, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_11a808;
    goto L_11a8e4;
L_11a99c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3488));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_11a8ac;
    goto L_11a92c;
L_11a9b0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11a8c0;
    cpu->regs[30] = PB_BASE + 0x11a9c0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11a8c0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
L_11a9d4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11a9dcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xf6800ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 48ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_11a9d4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_EQ) goto L_11a9fc;
L_11a9f0:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_11a9fc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11aa04ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xf6800ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 48ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_11a9d4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11aa1cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xf71a0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 3584ULL;
    cpu->regs[30] = PB_BASE + 0x11aa2cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x26aaacULL);
    cpu->regs[0] = 0ULL;
    goto L_11a9f0;
    /* nop */
    /* nop */
    /* nop */
}
