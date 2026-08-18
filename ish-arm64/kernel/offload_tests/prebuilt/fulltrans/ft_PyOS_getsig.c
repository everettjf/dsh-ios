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

void ft_PyOS_getsig(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 176ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = SP;
    PB_STR((SP + 160), cpu->regs[29]); PB_STR((SP + 160) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 160ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 152), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d3df4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7c030ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d3e28;
    PB_LDR(cpu->regs[0], (SP + 0));
L_1d3e00:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 152));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d3e30;
    PB_LDR(cpu->regs[29], (SP + 160)); PB_LDR(cpu->regs[30], (SP + 160) + 8);
    SP = SP + 176ULL;
    return;
L_1d3e28:
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_1d3e00;
L_1d3e30:
    cpu->regs[30] = PB_BASE + 0x1d3e34ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 176ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((SP + 32), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 72), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d3e74ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1b2528ULL);
    if ((cpu->regs[0])==0) goto L_1d4270;
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    cpu->regs[7] = 27464ULL;
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[24] + cpu->regs[7];
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1d3ea0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d43fc;
    cpu->regs[30] = PB_BASE + 0x1d3eacULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d4560ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d43fc;
    cpu->regs[22] = PB_BASE + 0x291000ULL;
    cpu->regs[22] = cpu->regs[22] + 3776ULL;
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[27] = 0ULL;
L_1d3ec4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_GE) goto L_1d3f44;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[27] << 3)));
    cpu->regs[30] = PB_BASE + 0x1d3ee0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x136da0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d41c4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 8) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    cpu->regs[0] = cpu->regs[0] & 33554432ULL;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_1d4308;
    if ((cpu->regs[0])!=0) goto L_1d43e4;
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 24)); PB_LDR(cpu->regs[0], (cpu->regs[21] + 24) + 8);
L_1d3f04:
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_1d4290;
L_1d3f10:
    cpu->regs[30] = PB_BASE + 0x1d3f14ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d47c8ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1d419c;
    if (FLAG_NE) goto L_1d418c;
L_1d3f20:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d4278;
L_1d3f28:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d3f3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d4380;
L_1d3f3c:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    goto L_1d3ec4;
L_1d3f44:
    cpu->regs[6] = 26264ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x1d3f54ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d41c4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[25] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_1d439c;
    cpu->regs[0] = SP + 56ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[21] + 24ULL;
    cpu->regs[5] = 25592ULL;
    PB_STR((SP + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[24] + cpu->regs[5];
    PB_STR((SP + 24), cpu->regs[0]);
L_1d3f88:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_GE) goto L_1d4088;
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[0], (SP + 8) + 8);
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[25] << 3)));
    cpu->regs[30] = PB_BASE + 0x1d3fa4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d42c4;
    PB_LDR(cpu->regs[27], (SP + 56));
    if ((cpu->regs[27])==0) goto L_1d4080;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1d3fbcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe7e88ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d42ac;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d3fd8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d43d8;
L_1d3fd8:
    cpu->regs[0] = SP + 64ULL;
    PB_STR((SP + 0), cpu->regs[0]);
L_1d3fe0:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d3fe8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d405c;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4000ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d41e4;
    PB_LDR(cpu->regs[28], (SP + 64));
    if ((cpu->regs[28])==0) goto L_1d403c;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1d4018ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d47c8ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[28] + 0));
    cpu->regs[4] = cpu->regs[0];
    if (((cpu->regs[2] >> 31) & 1)) goto L_1d4030;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_1d43c4;
L_1d4030:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1d41e4;
    if (FLAG_NE) goto L_1d41d4;
L_1d403c:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d3fe0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d3fe0;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1d4058ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d3fe0;
L_1d405c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d4078;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d4078;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d4078ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d4078:
    cpu->regs[30] = PB_BASE + 0x1d407cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1d42c4;
L_1d4080:
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_1d3f88;
L_1d4088:
    cpu->regs[4] = 25592ULL;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d409cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe28a0ULL);
    cpu->regs[22] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
L_1d40a4:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d40b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d42fc;
L_1d40b8:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1d40c0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d40c8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d40d0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdce4cULL);
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_1d4264;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d40e8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d4a24ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d4264;
    cpu->regs[3] = 34304ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4104ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe28a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d42d0;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d411c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d4374;
L_1d411c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d414c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4130ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[1] = 25488ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d4140ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_1d4218;
    cpu->regs[30] = PB_BASE + 0x1d4148ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1d4264;
L_1d414c:
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1d4160:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d4298;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    SP = SP + 176ULL;
    return;
L_1d418c:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1d4198ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d3f20;
L_1d419c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d41b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d4390;
L_1d41b0:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d41c4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d43b8;
L_1d41c4:
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    cpu->regs[21] = 0ULL;
    cpu->regs[22] = 4294967295ULL;
    goto L_1d40a4;
L_1d41d4:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1d41e0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x12b468ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d403c;
L_1d41e4:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d41f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d43f0;
L_1d41f8:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d42c4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d42c4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d4214ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d42c4;
L_1d4218:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_1d4250;
    cpu->regs[30] = PB_BASE + 0x1d4230ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x129680ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d4340;
    cpu->regs[0] = cpu->regs[0] & 96ULL;
    FLAG_CMP(cpu->regs[0], 96ULL);
    if (FLAG_EQ) goto L_1d4348;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 168));
    cpu->regs[0] = cpu->regs[1] | cpu->regs[0];
    PB_STR((cpu->regs[20] + 168), cpu->regs[0]);
L_1d4250:
    cpu->regs[0] = 25488ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d4260ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x197f6cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d414c;
L_1d4264:
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
L_1d4270:
    cpu->regs[0] = 0ULL;
    goto L_1d4160;
L_1d4278:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d3f28;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1d428cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d3f28;
L_1d4290:
    PB_STRW((cpu->regs[25] + 0), cpu->regs[2]);
    goto L_1d3f10;
L_1d4298:
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1d42acULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d42ac:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d42c4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d42c4;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1d42c4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d42c4:
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    cpu->regs[22] = 4294967295ULL;
    goto L_1d40a4;
L_1d42d0:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d4264;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d4264;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d42e8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    goto L_1d4160;
L_1d42fc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1d4304ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d40b8;
L_1d4308:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x291000ULL;
    cpu->regs[1] = cpu->regs[1] + 3808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d4320ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d41c4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d41c4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d433cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d41c4;
L_1d4340:
    cpu->regs[30] = PB_BASE + 0x1d4344ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1d4264;
L_1d4348:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x291000ULL;
    cpu->regs[1] = cpu->regs[1] + 3880ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d4360ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    goto L_1d4160;
L_1d4374:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d437cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d411c;
L_1d4380:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1d438cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d3ec4;
L_1d4390:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d4398ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d41b0;
L_1d439c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x291000ULL;
    cpu->regs[1] = cpu->regs[1] + 3856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d43b4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1d42c4;
L_1d43b8:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1d43c0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d41c4;
L_1d43c4:
    cpu->regs[0] = cpu->regs[28];
    PB_STRW((SP + 44), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1d43d0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[4], (SP + 44));
    goto L_1d4030;
L_1d43d8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1d43e0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d3fd8;
L_1d43e4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 0) + 8);
    goto L_1d3f04;
L_1d43f0:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1d43f8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d41f8;
L_1d43fc:
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[22] = 4294967295ULL;
    goto L_1d40a4;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1d4418ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])==0) goto L_1d4424;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(49, cpu, tlb, PB_BASE + 0x1d4468ULL); return; };
L_1d4424:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[0] = PB_BASE + 0x471000ULL;
    cpu->regs[2] = cpu->regs[0] + 64ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 2624));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1d4460;
L_1d4454:
    cpu->regs[0] = cpu->regs[0] + 64ULL;
    cpu->regs[0] = cpu->regs[0] + 2624ULL;
    return;
L_1d4460:
    PB_STRW((cpu->regs[2] + 2624), cpu->regs[1]);
    goto L_1d4454;
}
