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

void ft_PyUnicode_AsCharmapString(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 28) & 1)) goto L_c2be0;
    if ((cpu->regs[1])==0) goto L_c2be0;
    cpu->regs[2] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x23f680ULL); return; };
L_c2be0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xc2becULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x22aba0ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_c2bf8:
    SP = SP - 240ULL;
    PB_STR((SP + 144), cpu->regs[29]); PB_STR((SP + 144) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 144ULL;
    PB_STR((SP + 176), cpu->regs[21]); PB_STR((SP + 176) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 160), cpu->regs[19]); PB_STR((SP + 160) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 192), cpu->regs[23]); PB_STR((SP + 192) + 8, cpu->regs[24]);
    PB_STR((SP + 208), cpu->regs[25]); PB_STR((SP + 208) + 8, cpu->regs[26]);
    PB_STR((SP + 224), cpu->regs[27]); PB_STR((SP + 224) + 8, cpu->regs[28]);
    PB_STR((SP + 88), cpu->regs[3]);
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    PB_STR((SP + 136), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 16), cpu->regs[1]);
    if ((cpu->regs[22])!=0) goto L_c2c68;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2528ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc2c60ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
L_c2c60:
    cpu->regs[0] = 0ULL;
    goto L_c3398;
L_c2c68:
    cpu->regs[19] = cpu->regs[3];
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 120), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xc2c78ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c2d7c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_c2c98;
    PB_LDR(cpu->regs[26], (cpu->regs[19] + 16));
    cpu->regs[19] = cpu->regs[19] + 24ULL;
    goto L_c2ca0;
L_c2c98:
    cpu->regs[19] = SP + 120ULL;
    cpu->regs[26] = 1ULL;
L_c2ca0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[5] = 34000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2968));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[5];
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2504));
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    PB_STR((SP + 8), cpu->regs[1]);
    PB_STR((SP + 24), cpu->regs[0]);
    goto L_c2ce0;
L_c2cd8:
    if (!((cpu->regs[1] >> 31) & 1)) goto L_c2dfc;
L_c2cdc:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
L_c2ce0:
    FLAG_CMP(cpu->regs[24], cpu->regs[26]);
    if (FLAG_GE) goto L_c2e58;
    PB_LDR(cpu->regs[25], (cpu->regs[19] + (cpu->regs[24] << 3)));
    PB_STR((SP + 120), cpu->regs[25]);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c2e44;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc2d08ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c2d84;
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + 48));
    if (!((cpu->regs[0] >> 0) & 1)) goto L_c2d84;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_c2d84;
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c2d3c;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
L_c2d3c:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_c2e18;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 16));
    if ((cpu->regs[0])!=0) goto L_c2dd0;
L_c2d50:
    cpu->regs[2] = 9223372036854775807ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xc2d64ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1ac20cULL);
    PB_LDR(cpu->regs[3], (SP + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c2cd8;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_c2de4;
L_c2d74:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c2e2c;
L_c2d7c:
    cpu->regs[19] = 0ULL;
    goto L_c2e80;
L_c2d84:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[2] = SP + 128ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc2d94ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_c2e14;
    PB_LDR(cpu->regs[3], (SP + 128));
    FLAG_CMP(cpu->regs[3], cpu->regs[23]);
    if (FLAG_NE) goto L_c2dc8;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c2e14;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c2e14;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xc2dc4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c2e14;
L_c2dc8:
    if ((cpu->regs[3])!=0) goto L_c2d3c;
    goto L_c2e14;
L_c2dd0:
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_NE) goto L_c2d50;
    goto L_c2e18;
L_c2de4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c2d74;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xc2df8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c2d74;
L_c2dfc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c2cdc;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xc2e10ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c2cdc;
L_c2e14:
    cpu->regs[3] = 0ULL;
L_c2e18:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xc2e20ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[30] = PB_BASE + 0xc2e24ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_c2e44;
    goto L_c2d74;
L_c2e2c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c2d7c;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xc2e40ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c2d7c;
L_c2e44:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xc2e50ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe548cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c2cdc;
    goto L_c2d74;
L_c2e58:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xc2e60ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_c2e80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c2e80;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xc2e80ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c2e80:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[27] = PB_BASE + 0x29f000ULL;
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 2760));
    cpu->regs[4] = 33864ULL;
    cpu->regs[27] = cpu->regs[27] + 3904ULL;
    cpu->regs[24] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[26] = 0ULL;
    PB_STR((SP + 88), cpu->regs[19]);
L_c2ea8:
    PB_LDR(cpu->regs[19], (SP + 88));
    FLAG_CMP(cpu->regs[26], cpu->regs[22]);
    if (FLAG_GE) goto L_c2f70;
    cpu->regs[0] = cpu->regs[21] + 24ULL;
    cpu->regs[2] = SP + 128ULL;
    cpu->regs[1] = cpu->regs[24];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[26] << 3)));
    cpu->regs[30] = PB_BASE + 0xc2ec8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c308c;
    PB_LDR(cpu->regs[25], (SP + 128));
    if ((cpu->regs[25])!=0) goto L_c2ee0;
L_c2ed8:
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    goto L_c2ea8;
L_c2ee0:
    FLAG_CMP(cpu->regs[25], cpu->regs[28]);
    if (FLAG_EQ) goto L_c2ed8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_c2f14;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 112ULL;
    cpu->regs[30] = PB_BASE + 0xc2f0cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe6d90ULL);
    cpu->regs[23] = cpu->regs[0];
    goto L_c2f2c;
L_c2f14:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc2f28ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe6d90ULL);
    cpu->regs[23] = cpu->regs[0];
L_c2f2c:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c2f48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c2f48;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc2f48ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c2f48:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((SP + 88), cpu->regs[23]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_c2f68;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c2f68;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc2f68ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c2f68:
    if ((cpu->regs[23])!=0) goto L_c2ed8;
    goto L_c2c60;
L_c2f70:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_c2f88;
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[26] = cpu->regs[19] + 24ULL;
    goto L_c2f90;
L_c2f88:
    cpu->regs[26] = SP + 88ULL;
    cpu->regs[23] = 1ULL;
L_c2f90:
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_EQ) goto L_c2ff4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c2fb4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c2fb4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc2fb4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c2fb4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[2] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 2512ULL;
    cpu->regs[2] = cpu->regs[2] + 2520ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[2] = (FLAG_GE) ? cpu->regs[2] : cpu->regs[1];
    cpu->regs[5] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 2560ULL;
    cpu->regs[30] = PB_BASE + 0xc2ff0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c2c60;
L_c2ff4:
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xc3004ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdb480ULL);
    PB_STR((SP + 104), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c30ac;
    goto L_c308c;
L_c3010:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    PB_LDR(cpu->regs[1], (SP + 104));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c3024;
    PB_STRW((cpu->regs[25] + 0), cpu->regs[0]);
L_c3024:
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[20] << 3);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_STR((cpu->regs[0] + 24), cpu->regs[25]);
L_c3030:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
L_c3034:
    PB_LDR(cpu->regs[0], (SP + 8));
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_GE) goto L_c3348;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[0] + (cpu->regs[24] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c3010;
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[0] = SP + 128ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc3070ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x112290ULL);
    cpu->regs[22] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_c30e0;
L_c307c:
    if (!((cpu->regs[22] >> 31) & 1)) goto L_c3110;
L_c3080:
    PB_LDR(cpu->regs[0], (SP + 104));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_c32e0;
L_c308c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c2c60;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c2c60;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc30a8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c2c60;
L_c30ac:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 33784ULL;
    cpu->regs[2] = 33936ULL;
    cpu->regs[3] = 31400ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[20] = 0ULL;
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[1]); PB_STR((SP + 48) + 8, cpu->regs[0]);
    goto L_c3034;
L_c30e0:
    PB_LDR(cpu->regs[27], (SP + 128));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0xc30ecULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_c307c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c307c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0xc310cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c307c;
L_c3110:
    PB_LDR(cpu->regs[1], (SP + 48));
    cpu->regs[2] = SP + 112ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc3120ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c3080;
    PB_LDR(cpu->regs[27], (SP + 112));
    if ((cpu->regs[27])==0) goto L_c3190;
    cpu->regs[1] = cpu->regs[21] + 24ULL;
    cpu->regs[0] = 0ULL;
L_c3138:
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_GE) goto L_c3154;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + (cpu->regs[0] << 3)));
    FLAG_CMP(cpu->regs[25], cpu->regs[2]);
    if (FLAG_EQ) goto L_c3158;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_c3138;
L_c3154:
    cpu->regs[0] = 18446744073709551615ULL;
L_c3158:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0xc3164ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c317c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_c3184;
L_c317c:
    cpu->regs[27] = cpu->regs[28];
    goto L_c32d8;
L_c3184:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0xc318cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c317c;
L_c3190:
    PB_LDR(cpu->regs[1], (SP + 56));
    cpu->regs[2] = SP + 120ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc31a0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c3080;
    PB_LDR(cpu->regs[27], (SP + 120));
    if ((cpu->regs[27])==0) goto L_c32bc;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_c32bc;
    PB_LDR(cpu->regs[28], (cpu->regs[27] + 16));
    if ((cpu->regs[28])==0) goto L_c32bc;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    PB_STR((SP + 32), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xc31d4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdb480ULL);
    PB_STR((SP + 128), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c31fc;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c3080;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c3080;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0xc31f8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c3080;
L_c31fc:
    cpu->regs[9] = cpu->regs[27] + 24ULL;
    cpu->regs[8] = cpu->regs[21] + 24ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[1] = 0ULL;
L_c320c:
    FLAG_CMP(cpu->regs[28], cpu->regs[6]);
    if (FLAG_LE) goto L_c3288;
    PB_LDR(cpu->regs[2], (cpu->regs[9] + (cpu->regs[6] << 3)));
    cpu->regs[0] = 0ULL;
L_c321c:
    PB_LDR(cpu->regs[3], (SP + 32));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LE) goto L_c3260;
    PB_LDR(cpu->regs[3], (cpu->regs[8] + (cpu->regs[0] << 3)));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_c323c;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_c321c;
L_c323c:
    cpu->regs[3] = cpu->regs[21] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[26] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 216));
    if ((cpu->regs[0])==0) goto L_c3260;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_c336c;
L_c3260:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[3], (SP + 128));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c3274;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_c3274:
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[1] << 3);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[0] + 24), cpu->regs[2]);
L_c3280:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    goto L_c320c;
L_c3288:
    PB_LDR(cpu->regs[28], (SP + 128));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xc3298ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[28] + 0));
    cpu->regs[25] = cpu->regs[0];
    if (((cpu->regs[2] >> 31) & 1)) goto L_c32cc;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c32cc;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xc32b8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c32cc;
L_c32bc:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c32cc;
    PB_STRW((cpu->regs[25] + 0), cpu->regs[0]);
L_c32cc:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[27] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xc32d8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x18d760ULL);
L_c32d8:
    if ((cpu->regs[27])!=0) goto L_c32f4;
    goto L_c3080;
L_c32e0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c308c;
    cpu->regs[30] = PB_BASE + 0xc32f0ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c308c;
L_c32f4:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_c3334;
    PB_LDR(cpu->regs[3], (cpu->regs[27] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[27] + 24ULL;
    cpu->regs[0] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0xc330cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x9e360ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c332c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c332c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0xc332cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c332c:
    if (!((cpu->regs[20] >> 63) & 1)) goto L_c3030;
    goto L_c308c;
L_c3334:
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[20] << 3);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_STR((cpu->regs[0] + 24), cpu->regs[27]);
    goto L_c3030;
L_c3348:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c3364;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c3364;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc3364ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c3364:
    PB_LDR(cpu->regs[0], (SP + 104));
    goto L_c3398;
L_c336c:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 16));
    cpu->regs[2] = cpu->regs[2] + 24ULL;
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_STR((SP + 64), cpu->regs[6]); PB_STR((SP + 64) + 8, cpu->regs[9]);
    PB_STR((SP + 80), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0xc3384ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x9e360ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[8], (SP + 80));
    PB_LDR(cpu->regs[6], (SP + 64)); PB_LDR(cpu->regs[9], (SP + 64) + 8);
    if (!((cpu->regs[0] >> 63) & 1)) goto L_c3280;
    goto L_c3080;
L_c3398:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 136));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_c33b8;
    cpu->regs[30] = PB_BASE + 0xc33b8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c33b8:
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    PB_LDR(cpu->regs[19], (SP + 160)); PB_LDR(cpu->regs[20], (SP + 160) + 8);
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[25], (SP + 208)); PB_LDR(cpu->regs[26], (SP + 208) + 8);
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    SP = SP + 240ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    PB_STR((SP + 32), cpu->regs[21]);
    if ((cpu->regs[2])!=0) goto L_c340c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0xc3400ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x207c00ULL);
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c3454;
L_c340c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc341cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xc2bf8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c3454;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0xc3430ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1d8300ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if ((cpu->regs[0])!=0) goto L_c345c;
    if (((cpu->regs[2] >> 31) & 1)) goto L_c3454;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c3454;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc3454ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c3454:
    cpu->regs[21] = 0ULL;
    goto L_c347c;
L_c345c:
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 48));
    PB_STRB((cpu->regs[21] + 48), cpu->regs[0]);
    if (((cpu->regs[2] >> 31) & 1)) goto L_c347c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c347c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc347cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c347c:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    if ((cpu->regs[2])!=0) goto L_c34d0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0xc34bcULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x207c00ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c34d0;
L_c34c8:
    cpu->regs[19] = 0ULL;
    goto L_c357c;
L_c34d0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc34e0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xc2bf8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c34c8;
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    if ((cpu->regs[23])!=0) goto L_c34fc;
    cpu->regs[30] = PB_BASE + 0xc34f4ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1dec70ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_c3560;
L_c34fc:
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c3510;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_c3510:
    cpu->regs[24] = cpu->regs[20] + 24ULL;
    cpu->regs[22] = 1ULL;
L_c3518:
    cpu->regs[0] = cpu->regs[21];
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_GE) goto L_c355c;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + (cpu->regs[22] << 3)));
    cpu->regs[30] = PB_BASE + 0xc352cULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x14e480ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_c354c;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c354c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc354cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c354c:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    cpu->regs[21] = cpu->regs[19];
    if ((cpu->regs[19])!=0) goto L_c3518;
    goto L_c3560;
L_c355c:
    cpu->regs[19] = cpu->regs[21];
L_c3560:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c357c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c357c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc357cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c357c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
}
