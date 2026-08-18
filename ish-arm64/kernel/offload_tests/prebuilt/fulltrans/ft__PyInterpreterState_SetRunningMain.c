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

void ft__PyInterpreterState_SetRunningMain(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = cpu->regs[0] + (88ULL << 12);
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 22800));
    if ((cpu->regs[0])!=0) goto L_1d9bd8;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1d9bb4ULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + cpu->regs[0]));
    if ((cpu->regs[2])==0) goto L_1d9c18;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1d9bf8;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[3] + 22800), cpu->regs[2]);
L_1d9bd0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1d9bd8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2296ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d9bf0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1d9bd0;
L_1d9bf8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2328ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d9c10ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1d9bd0;
L_1d9c18:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 832ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x1d9c30ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x91ebcULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3496));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1d9c4cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d9c94;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2600));
    cpu->regs[30] = PB_BASE + 0x1d9c5cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d9ca4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[5] + 16), 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d9c78;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1d9c78:
    PB_STR((cpu->regs[5] + 24), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1d9c84ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xd9444ULL);
L_1d9c84:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1d9c94:
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = 2478ULL;
    cpu->regs[0] = cpu->regs[0] + 2368ULL;
    cpu->regs[30] = PB_BASE + 0x1d9ca4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_1d9ca4:
    cpu->regs[5] = 0ULL;
    goto L_1d9c84;
    SP = SP - 80ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3272ULL;
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[0] + 2400ULL;
    cpu->regs[30] = PB_BASE + 0x1d9cf4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d9fe0;
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[0] + 2424ULL;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1d9d0cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1c7c60ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d9f98;
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2464ULL;
    cpu->regs[30] = PB_BASE + 0x1d9d20ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d9f58;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d9d30ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b8b0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d9d3cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d9f04;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3664));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 2ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1d9d68ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d9e60;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_STRW((cpu->regs[24] + 1536), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1d9d8cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c1e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d9e3c;
L_1d9d94:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9da8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1da004;
L_1d9da8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9dbc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1da010;
L_1d9dbc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9dd0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d9fd4;
L_1d9dd0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9dec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d9dec;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d9decULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d9dec:
    if ((cpu->regs[22])==0) goto L_1d9ed4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9e04;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d9ef8;
L_1d9e04:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
L_1d9e0c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d9ef0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_1d9e3c:
    cpu->regs[30] = PB_BASE + 0x1d9e40ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3440));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1d9d94;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[24] + 1536), cpu->regs[0]);
    goto L_1d9d94;
L_1d9e60:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = 57ULL;
    cpu->regs[0] = cpu->regs[0] + 2584ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1d9e80ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7b510ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9e9c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d9e9c;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1d9e9cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d9e9c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9eb8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d9eb8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d9eb8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d9eb8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9ed4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d9ed4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d9ed4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d9ed4:
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = SP + 4ULL;
    PB_STRW((SP + 4), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1d9ee4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x2023a4ULL);
    PB_LDRW(cpu->regs[0], (SP + 4));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1d9e0c;
L_1d9ef0:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1d9ef8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d9ef8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d9f00ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d9e04;
L_1d9f04:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = 41ULL;
    cpu->regs[0] = cpu->regs[0] + 2536ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1d9f24ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7b510ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9f38;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d9ff8;
L_1d9f38:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9ed4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d9ed4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d9f54ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d9ed4;
L_1d9f58:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = 43ULL;
    cpu->regs[0] = cpu->regs[0] + 2488ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1d9f78ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7b510ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d9ed4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d9ed4;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1d9f94ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d9ed4;
L_1d9f98:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[2] = 30ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[0] + 2432ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1d9fb8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7b510ULL);
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = SP + 4ULL;
    PB_STRW((SP + 4), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1d9fc8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x2023a4ULL);
    PB_LDRW(cpu->regs[0], (SP + 4));
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1d9e0c;
L_1d9fd4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d9fdcULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d9dd0;
L_1d9fe0:
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = SP + 4ULL;
    PB_STRW((SP + 4), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1d9ff0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x2023a4ULL);
    PB_LDRW(cpu->regs[0], (SP + 4));
    goto L_1d9e0c;
L_1d9ff8:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1da000ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d9f38;
L_1da004:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1da00cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d9da8;
L_1da010:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1da018ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d9dbc;
    /* nop */
    cpu->regs[0] = PB_BASE + 0x494000ULL;
    cpu->regs[2] = cpu->regs[0] + 320ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 3616));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1da040;
L_1da034:
    cpu->regs[0] = cpu->regs[0] + 320ULL;
    cpu->regs[0] = cpu->regs[0] + 3616ULL;
    return;
L_1da040:
    PB_STRW((cpu->regs[2] + 3616), cpu->regs[1]);
    goto L_1da034;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1da058ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x1da064ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(38, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_1da0f8;
L_1da09c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_1da0a8;
    cpu->regs[30] = PB_BASE + 0x1da0a8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdfce0ULL);
L_1da0a8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0xdf000ULL;
    cpu->regs[0] = cpu->regs[0] + 3296ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1da0e4;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1da0e4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[16] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1da0f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2648ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1da110ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[30] = PB_BASE + 0x1da114ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xcd33cULL);
    goto L_1da09c;
    /* nop */
    /* nop */
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3096));
    { PB_CALL(42, cpu, tlb, PB_BASE + 0x1a3d00ULL); return; };
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1da140;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3552));
    { PB_CALL(43, cpu, tlb, PB_BASE + 0x11d9e0ULL); return; };
L_1da140:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2184));
    { PB_CALL(44, cpu, tlb, PB_BASE + 0x1a3d00ULL); return; };
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1da174;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3832));
    { PB_CALL(45, cpu, tlb, PB_BASE + 0x11d9e0ULL); return; };
L_1da174:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_1da1b8;
L_1da198:
    cpu->regs[2] = cpu->regs[2] & 9223372036854775807ULL;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_NE) goto L_1da1e4;
L_1da1a4:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_1da204;
L_1da1b8:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 3920ULL;
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1da1ccULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x81c64ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1da198;
L_1da1d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1da1e4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3920ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1da1fcULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1da1a4;
    goto L_1da1d4;
L_1da204:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 32120ULL;
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1da234ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xed124ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1da2ec;
    if ((cpu->regs[0])==0) goto L_1da284;
    cpu->regs[30] = PB_BASE + 0x1da250ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x179564ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1da270;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1da270;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1da270ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1da270:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1da284:
    cpu->regs[30] = PB_BASE + 0x1da288ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1da314;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1da294ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1da2f4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1da2a0ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1fd1e8ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1da314;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 304));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1da2bcULL; PB_CALL(54, cpu, tlb, cpu->regs[2]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1da314;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    PB_STR((cpu->regs[21] + 16), cpu->regs[19]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1da2e0;
    PB_STR((cpu->regs[21] + 24), cpu->regs[20]);
    goto L_1da270;
L_1da2e0:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[21] + 24), cpu->regs[20]);
    goto L_1da270;
L_1da2ec:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1da31c;
L_1da2f4:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 2704ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1da314ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1da314:
    cpu->regs[21] = 0ULL;
    goto L_1da270;
L_1da31c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1da2f4;
    cpu->regs[30] = PB_BASE + 0x1da32cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1da2f4;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2488));
    cpu->regs[30] = PB_BASE + 0x1da34cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1da37c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1da370;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_1da370:
    PB_STR((cpu->regs[19] + 24), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1da37cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xe1984ULL);
L_1da37c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1da39cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x1da3a8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(61, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[2] & 9223372036854775807ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_1da3f0;
L_1da3dc:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_1da420;
L_1da3f0:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 3912ULL;
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1da404ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x81c64ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1da3dc;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
L_1da420:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_NE) goto L_1da4a0;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1da448ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x14e5a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1da50c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 3208));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1da5f0;
L_1da464:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 3240));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1da5f8;
L_1da470:
    cpu->regs[22] = cpu->regs[1] + 3240ULL;
    cpu->regs[20] = cpu->regs[1] + 3208ULL;
L_1da478:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1da48cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x14e610ULL);
    if ((cpu->regs[0])==0) goto L_1da600;
L_1da490:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1da4a0:
    if (FLAG_LE) goto L_1da57c;
    cpu->regs[22] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_1da514;
L_1da4b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x1da4b8ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x14e5a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1da50c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x1da4c8ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x14e5a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1da5c0;
    if ((cpu->regs[22])!=0) goto L_1da524;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1da4dcULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1da478;
L_1da4e4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1da4f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1da5e4;
L_1da4f8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1da50c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1da64c;
L_1da50c:
    cpu->regs[0] = 0ULL;
    goto L_1da490;
L_1da514:
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_NE) goto L_1da580;
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 16));
    goto L_1da4b0;
L_1da524:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1da52cULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x14e5a0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1da4e4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_1da478;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2744ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1da55cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1da4e4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1da4e4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1da578ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1da4e4;
L_1da57c:
    if ((cpu->regs[2])==0) goto L_1da5a0;
L_1da580:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2824ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1da598ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_1da490;
L_1da5a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2776ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1da5b8ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1da490;
L_1da5c0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1da50c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1da50c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1da5dcULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1da490;
L_1da5e4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1da5ecULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1da4f8;
L_1da5f0:
    PB_STRW((cpu->regs[1] + 3208), cpu->regs[0]);
    goto L_1da464;
L_1da5f8:
    PB_STRW((cpu->regs[1] + 3240), cpu->regs[0]);
    goto L_1da470;
L_1da600:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1da614;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1da65c;
L_1da614:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1da628;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1da668;
L_1da628:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1da50c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1da50c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1da644ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1da490;
L_1da64c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1da654ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1da490;
L_1da65c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1da664ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1da614;
L_1da668:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1da670ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1da628;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 96ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = SP + 20ULL;
    cpu->regs[1] = cpu->regs[19];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 80), cpu->regs[23]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1da6c0ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 20));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1da8cc;
L_1da6cc:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1da884;
L_1da6d4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1da6e0ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 20));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1da8b0;
L_1da6ec:
    FLAG_CMP(cpu->regs[23], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1da810;
L_1da6f4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1da700ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 20));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1da894;
L_1da70c:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1da7c4;
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GT) { FLAG_CMP(cpu->regs[20], cpu->regs[23]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GE) goto L_1da7cc;
    cpu->regs[19] = cpu->regs[23] - cpu->regs[20];
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[19] = (cpu->regs[22] ? cpu->regs[19] / cpu->regs[22] : 0);
    cpu->regs[19] = cpu->regs[19] + 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_1da81c;
    if (FLAG_EQ) goto L_1da808;
    cpu->regs[0] = 9223372036854775808ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[22];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_LT) goto L_1da81c;
L_1da748:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3528));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    if (((cpu->regs[1] >> 63) & 1)) goto L_1da8f0;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 176)); PB_LDR(cpu->regs[2], (cpu->regs[23] + 176) + 8);
    cpu->regs[30] = PB_BASE + 0x1da768ULL; PB_CALL(82, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1da8f0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 168));
    PB_STR((cpu->regs[0] + 8), cpu->regs[21]);
    if (((cpu->regs[1] >> 9) & 1)) goto L_1da870;
L_1da778:
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 2708));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1da914;
L_1da780:
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[22]);
    PB_STR((cpu->regs[0] + 32), cpu->regs[19]);
L_1da790:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1da890;
    PB_LDR(cpu->regs[23], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_1da7c4:
    cpu->regs[30] = PB_BASE + 0x1da7c8ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1da818;
L_1da7cc:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LT) { FLAG_CMP(cpu->regs[20], cpu->regs[23]); } else { FLAG_CMP(0, 0); }
    if (FLAG_LE) goto L_1da808;
    cpu->regs[19] = cpu->regs[20] - 1ULL;
    cpu->regs[0] = (uint64_t)(-(int64_t)cpu->regs[22]);
    cpu->regs[19] = cpu->regs[19] - cpu->regs[23];
    cpu->regs[19] = (cpu->regs[0] ? cpu->regs[19] / cpu->regs[0] : 0);
    cpu->regs[19] = cpu->regs[19] + 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_1da81c;
    if (FLAG_EQ) goto L_1da808;
    cpu->regs[0] = 9223372036854775807ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[22];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_LE) goto L_1da748;
    goto L_1da81c;
L_1da808:
    cpu->regs[19] = 0ULL;
    goto L_1da748;
L_1da810:
    cpu->regs[30] = PB_BASE + 0x1da814ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1da6f4;
L_1da818:
    cpu->regs[30] = PB_BASE + 0x1da81cULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_1da81c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2904));
    cpu->regs[30] = PB_BASE + 0x1da828ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xe3a2cULL);
    if ((cpu->regs[0])==0) goto L_1da904;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1da8e8;
L_1da83c:
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 32));
    PB_LDRW(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((cpu->regs[0] + 16), cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1da90c;
L_1da850:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 40));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[0] + 24), cpu->regs[3]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1da868;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_1da868:
    PB_STR((cpu->regs[0] + 32), cpu->regs[2]);
    goto L_1da790;
L_1da870:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1da778;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
    goto L_1da778;
L_1da884:
    cpu->regs[30] = PB_BASE + 0x1da888ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1da6d4;
    goto L_1da818;
L_1da890:
    cpu->regs[30] = PB_BASE + 0x1da894ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1da894:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1da8acULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1da70c;
L_1da8b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1da8c8ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1da6ec;
L_1da8cc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 2856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1da8e4ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1da6cc;
L_1da8e8:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    goto L_1da83c;
L_1da8f0:
    cpu->regs[30] = PB_BASE + 0x1da8f4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x22d780ULL);
    if ((cpu->regs[0])==0) goto L_1da904;
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[22]);
    PB_STR((cpu->regs[0] + 32), cpu->regs[19]);
    goto L_1da790;
L_1da904:
    cpu->regs[0] = 0ULL;
    goto L_1da790;
L_1da90c:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[1]);
    goto L_1da850;
L_1da914:
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1da91cULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    goto L_1da780;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1da9b4;
L_1da93c:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1da97c;
L_1da948:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1da9d0;
L_1da954:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1da998;
L_1da960:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1da97c:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1da948;
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1da990ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    goto L_1da948;
L_1da998:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1da960;
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1da9acULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    goto L_1da960;
L_1da9b4:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1da93c;
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1da9c8ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    goto L_1da93c;
L_1da9d0:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1da954;
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1da9e4ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    goto L_1da954;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_1daa4c;
L_1daa04:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1daa18ULL; PB_CALL(98, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x1daa24ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x1362a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1daa68;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1daa40;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_1daa34:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1daa40:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_1daa34;
L_1daa4c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2912ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1daa64ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1daa04;
L_1daa68:
    cpu->regs[0] = 0ULL;
    goto L_1daa34;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_1dab10;
L_1daa90:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x1daa98ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1dab00;
    cpu->regs[30] = PB_BASE + 0x1daaa4ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1daae0;
L_1daab0:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1dab00;
L_1daab8:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1daac4ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x1c65e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dab2c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1daad0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1daae0:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1daab0;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1daaf8ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_1daab0;
L_1dab00:
    cpu->regs[30] = PB_BASE + 0x1dab04ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1dab2c;
    cpu->regs[1] = 18446744073709551615ULL;
    goto L_1daab8;
L_1dab10:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2936ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1dab28ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1daa90;
L_1dab2c:
    cpu->regs[0] = 0ULL;
    goto L_1daad0;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[1] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1dab5cULL; PB_CALL(107, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1dab8c;
    cpu->regs[1] = cpu->regs[0] + 3896ULL; FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1daba4;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STR((cpu->regs[1] + 24), cpu->regs[2]);
L_1dab84:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1dab8c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1daba4ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1daba4:
    cpu->regs[0] = 0ULL;
    goto L_1dab84;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1dabc4ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x1dabccULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1dabd4ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(112, cpu, tlb, PB_BASE + 0xdfce0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1dabf4ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x1dac00ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1dac08ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    goto L_1dac28;
L_1dac28:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1dac38ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x1d47c8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1dac64;
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
L_1dac5c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1dac64:
    cpu->regs[0] = 0ULL;
    goto L_1dac5c;
    SP = SP - 48ULL;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if (!((cpu->regs[2] >> 9) & 1)) goto L_1dad84;
    if (((cpu->regs[2] >> 1) & 1)) goto L_1dad30;
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 264));
L_1daca4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_1dae0c;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 30608));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1dad68;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 30624));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1dad68;
L_1dacd8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = SP;
    cpu->regs[1] = 30600ULL;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1dacecULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])==0) goto L_1dae1c;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1dad04;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1dad04:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1dae00;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_1dad30:
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1dad44ULL; PB_CALL(118, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 360));
    cpu->regs[3] = 40ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] * cpu->regs[3] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + (88ULL << 12);
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 13272));
    goto L_1daca4;
L_1dad68:
    cpu->regs[2] = 30600ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1dad74ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1dacd8;
    goto L_1dae1c;
L_1dad84:
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 24));
    cpu->regs[1] = 46ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1dad94ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x7b140ULL);
    if ((cpu->regs[0])==0) goto L_1dadd8;
    cpu->regs[1] = cpu->regs[0] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1dada4ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xe1ec0ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1dad04;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1dadc0ULL; PB_CALL(122, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1dadd0ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xdc100ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    goto L_1dad04;
L_1dadd8:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[1] = cpu->regs[19] + (8ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 5488));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1dae04;
L_1dadf0:
    cpu->regs[0] = 38256ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[0];
    PB_STR((SP + 0), cpu->regs[0]);
    goto L_1dad04;
L_1dae00:
    cpu->regs[30] = PB_BASE + 0x1dae04ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1dae04:
    PB_STRW((cpu->regs[1] + 5488), cpu->regs[0]);
    goto L_1dadf0;
L_1dae0c:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1dae1cULL; PB_CALL(125, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_1dae1c:
    cpu->regs[30] = PB_BASE + 0x1dae20ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1dae2c;
    cpu->regs[0] = 0ULL;
    goto L_1dad04;
L_1dae2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1dae44ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_1dad04;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_1dae7c;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1dae78ULL; PB_CALL(128, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dae9c;
L_1dae7c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_1dae9c;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1dae9c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    if (!((cpu->regs[2] >> 9) & 1)) goto L_1daed0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 872));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1daec8;
    return;
L_1daec8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
L_1daed0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1daedcULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x1ab164ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(130, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
}
