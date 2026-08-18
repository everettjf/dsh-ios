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

void ft_PySequence_Fast(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    if ((cpu->regs[0])==0) goto L_136e78;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2640));
    cpu->regs[2] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3312));
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[3]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_136df8;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_136de8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_136de8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_136df8:
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x136e00ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_136e30;
    cpu->regs[30] = PB_BASE + 0x136e0cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x14d3acULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_136de8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_136de8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x136e2cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_136de8;
L_136e30:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2736));
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x136e4cULL; PB_CALL(4, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[19], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x136e5cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x121d80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_136e70;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x136e70ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d5980ULL);
L_136e70:
    cpu->regs[19] = 0ULL;
    goto L_136de8;
L_136e78:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x136e80ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x96bd4ULL);
    goto L_136de8;
    SP = SP - 96ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[4];
    cpu->regs[19] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[3];
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[2];
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 0));
    PB_STR((SP + 8), cpu->regs[7]);
    cpu->regs[7] = 0ULL;
    if ((cpu->regs[5])==0) goto L_136fa0;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 16));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_136fa0;
    cpu->regs[4] = SP;
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20] + 24ULL;
    PB_STR((SP + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x136ef4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x122d00ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_137060;
    PB_LDR(cpu->regs[26], (SP + 0));
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[5] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x136f1cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xf328cULL);
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x136f2cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1230ecULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_136f40;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_137044;
L_136f40:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_136f64;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_136f64;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x136f64ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
L_136f64:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_13705c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_136fa0:
    PB_STR((SP + 0), 0ULL);
    cpu->regs[3] = cpu->regs[20] + 24ULL;
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_LE) goto L_13700c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_136fc4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_136fc4:
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_13700c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_136fe0;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_136fe0:
    FLAG_CMP(cpu->regs[21], 2ULL);
    if (FLAG_EQ) goto L_13700c;
    cpu->regs[1] = 2ULL;
L_136fec:
    PB_LDR(cpu->regs[2], (cpu->regs[3] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_137000;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_137000:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_NE) goto L_136fec;
L_13700c:
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x137024ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xf328cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_13703c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_137044;
L_13703c:
    if ((cpu->regs[19])!=0) goto L_136f40;
    goto L_136f64;
L_137044:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x137054ULL; PB_CALL(13, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[19])!=0) goto L_136f40;
    goto L_136f64;
L_13705c:
    cpu->regs[30] = PB_BASE + 0x137060ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_137060:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_137084;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_137084;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x137084ULL; PB_CALL(15, cpu, tlb, cpu->regs[1]);
L_137084:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1370a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1370a8;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1370a8ULL; PB_CALL(16, cpu, tlb, cpu->regs[1]);
L_1370a8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1370cc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1370cc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1370ccULL; PB_CALL(17, cpu, tlb, cpu->regs[1]);
L_1370cc:
    cpu->regs[21] = 0ULL;
    goto L_136f64;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 76));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 9ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[30] = PB_BASE + 0x137104ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdc988ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_137184;
    PB_STR((cpu->regs[0] + 40), 0ULL); PB_STR((cpu->regs[0] + 40) + 8, 0ULL);
    cpu->regs[0] = 4ULL;
    PB_STRB((cpu->regs[2] + 67), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32)); PB_LDR(cpu->regs[4], (cpu->regs[19] + 32) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[2] + 16), 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1371dc;
L_13712c:
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_137194;
    cpu->regs[5] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x137150ULL; PB_CALL(19, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_STRW((cpu->regs[4] + 0), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[5] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[0] = cpu->regs[2] - 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_STR((cpu->regs[2] + 32), cpu->regs[4]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[2] + -16), cpu->regs[3]); PB_STR((cpu->regs[2] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[0]);
L_137184:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_137194:
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1371a8ULL; PB_CALL(20, cpu, tlb, cpu->regs[1]);
    PB_STR((cpu->regs[2] + 32), cpu->regs[4]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[1] & 3ULL;
    cpu->regs[3] = cpu->regs[2] - 16ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    cpu->regs[0] = cpu->regs[0] | cpu->regs[5];
    PB_STR((cpu->regs[5] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[2] + -16), cpu->regs[4]); PB_STR((cpu->regs[2] + -16) + 8, cpu->regs[0]);
    PB_STR((cpu->regs[4] + 8), cpu->regs[3]);
    goto L_137184;
L_1371dc:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_13712c;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[29] = SP;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 64),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[2] = cpu->regs[2] + 9ULL;
    cpu->regs[2] = cpu->regs[2] << 3;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LS) goto L_137228;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LO) goto L_137238;
L_137210:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x13721cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_STR((cpu->regs[0] + 8), 0ULL);
    return;
L_137228:
    cpu->regs[1] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[0], cpu->regs[3]); } else { FLAG_CMP(1, 0); }
    if (FLAG_HS) goto L_137210;
L_137238:
    __builtin_trap();
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x137250ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_13733c;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 224));
L_137268:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x137270ULL; PB_CALL(23, cpu, tlb, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1372c0;
    cpu->regs[30] = PB_BASE + 0x13727cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1372fc;
L_137288:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_137320;
    if (FLAG_EQ) goto L_137268;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1372a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_137314;
L_1372a8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_1372b8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1372c0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1372d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1372f0;
L_1372d4:
    cpu->regs[30] = PB_BASE + 0x1372d8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_137344;
L_1372dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_1372b8;
L_1372f0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1372f8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1372d4;
L_1372fc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_137288;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x137310ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_137288;
L_137314:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13731cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1372a8;
L_137320:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_137334;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_137360;
L_137334:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_13733c:
    cpu->regs[0] = 0ULL;
    goto L_1372b8;
L_137344:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x137354ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_137334;
    cpu->regs[30] = PB_BASE + 0x13735cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1372dc;
L_137360:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x137368ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1372b8;
    /* nop */
    /* nop */
}
