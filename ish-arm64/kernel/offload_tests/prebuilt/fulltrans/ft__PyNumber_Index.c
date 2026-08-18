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

void ft__PyNumber_Index(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    if ((cpu->regs[0])==0) goto L_123fc0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 168));
    if (!((cpu->regs[3] >> 24) & 1)) goto L_123f24;
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_123f10;
L_123f00:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_123f10:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_123f24:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 96));
    if ((cpu->regs[1])==0) goto L_123f34;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 264));
    if ((cpu->regs[1])!=0) goto L_123f58;
L_123f34:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x123f50ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11f220ULL);
L_123f50:
    cpu->regs[19] = 0ULL;
    goto L_123f00;
L_123f58:
    cpu->regs[30] = PB_BASE + 0x123f5cULL; PB_CALL(2, cpu, tlb, cpu->regs[1]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_123f50;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_123f00;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    if (((cpu->regs[1] >> 24) & 1)) goto L_123fcc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x123f9cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_123f50;
L_123fa4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_123f50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x123fbcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_123f00;
L_123fc0:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x123fc8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x96bd4ULL);
    goto L_123f00;
L_123fcc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3360));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[1] = 1ULL;
    cpu->regs[2] = PB_BASE + 0x289000ULL;
    cpu->regs[2] = cpu->regs[2] + 2960ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x123fecULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x24d184ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_123f00;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_123fa4;
    cpu->regs[19] = 0ULL;
    goto L_123f00;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 80));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x12401cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_124064;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[19] = 0ULL;
    /* nop */
    /* nop */
    /* nop */
L_124040:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 136));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[19] << 3)));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 168));
    cpu->regs[30] = PB_BASE + 0x124058ULL; PB_CALL(8, cpu, tlb, cpu->regs[2]);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_GT) goto L_124040;
L_124064:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[21] = cpu->regs[20] + 112ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x124074ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_124074:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 16));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[2], cpu->regs[19]);
    if (FLAG_HI) goto L_1240a0;
    cpu->regs[30] = PB_BASE + 0x12408cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xdc0e4ULL); return; };
L_1240a0:
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 4);
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[30] = PB_BASE + 0x1240b0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_124074;
    /* nop */
    /* nop */
    /* nop */
    if (((cpu->regs[1] >> 63) & 1)) goto L_1240f0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_GE) goto L_1240f0;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1240ec;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
L_1240ec:
    return;
L_1240f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3816ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x124110ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    cpu->regs[2] = 0ULL;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x112810ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1241ec;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3984));
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x12415cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1241dc;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[2] + 32), 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_124204;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[2] + 16), cpu->regs[20]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_124214;
L_124188:
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x12419cULL; PB_CALL(16, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_STRW((cpu->regs[19] + 0), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[0] = PB_BASE + 0x13c000ULL;
    cpu->regs[0] = cpu->regs[0] + 264ULL;
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    PB_STR((cpu->regs[2] + 24), cpu->regs[19]);
    PB_STR((cpu->regs[2] + 40), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[2] - 16ULL;
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[2] + -16), cpu->regs[3]); PB_STR((cpu->regs[2] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[0]);
L_1241dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1241ec:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1241fc;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_1241fc:
    cpu->regs[2] = cpu->regs[20];
    goto L_1241dc;
L_124204:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[2] + 16), cpu->regs[20]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_NE) goto L_124188;
L_124214:
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x124228ULL; PB_CALL(17, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    cpu->regs[3] = PB_BASE + 0x13c000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[3] + 264ULL;
    PB_STR((cpu->regs[2] + 40), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[2] + 24), cpu->regs[19]);
    cpu->regs[3] = cpu->regs[2] - 16ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    cpu->regs[0] = cpu->regs[0] | cpu->regs[5];
    PB_STR((cpu->regs[5] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[2] + -16), cpu->regs[4]); PB_STR((cpu->regs[2] + -16) + 8, cpu->regs[0]);
    PB_STR((cpu->regs[4] + 8), cpu->regs[3]);
    goto L_1241dc;
}
