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

void ft_PyException_GetCause(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    if ((cpu->regs[0])==0) goto L_7d5e8;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_7d5e8;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_7d5e8:
    return;
    SP = SP - 176ULL;
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[28], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    PB_STR((SP + 40), 0ULL);
    if (((cpu->regs[0] >> 30) & 1)) goto L_7d6a8;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] << 1));
    cpu->regs[30] = PB_BASE + 0x7d64cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1e7d30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7d65c;
L_7d654:
    cpu->regs[0] = 4294967295ULL;
    goto L_7e748;
L_7d65c:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[0] + 40ULL;
    cpu->regs[30] = PB_BASE + 0x7d66cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7d654;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[28];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x7d684ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7d654;
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 104ULL;
    cpu->regs[30] = PB_BASE + 0x7d69cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
    goto L_7e748;
L_7d6a8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_7d6b8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_7d6b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3344));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7d6ccULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7b050ULL);
    PB_LDR(cpu->regs[5], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7d6d8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x121b20ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7d768;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_7d768;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3792));
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    PB_LDRW(cpu->regs[7], (cpu->regs[23] + 16));
    cpu->regs[0] = cpu->regs[0] + 4064ULL;
    cpu->regs[6] = PB_BASE + 0x299000ULL;
    cpu->regs[6] = cpu->regs[6] + 240ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(0ULL)));
    cpu->regs[6] = (FLAG_EQ) ? cpu->regs[6] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7d720ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7d73c;
    cpu->regs[4] = PB_BASE + 0x293000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(1ULL)));
    cpu->regs[4] = cpu->regs[4] + 4072ULL;
    if (FLAG_EQ) goto L_7d74c;
    cpu->regs[3] = cpu->regs[6];
    goto L_7d754;
L_7d73c:
    cpu->regs[4] = PB_BASE + 0x293000ULL;
    cpu->regs[3] = cpu->regs[6];
    cpu->regs[4] = cpu->regs[4] + 4088ULL;
    goto L_7d754;
L_7d74c:
    cpu->regs[3] = PB_BASE + 0x294000ULL;
    cpu->regs[3] = cpu->regs[3] + 32ULL;
L_7d754:
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] << 1));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7d764ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7e850ULL);
    cpu->regs[21] = cpu->regs[0];
L_7d768:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7d770ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdce4cULL);
    if (((cpu->regs[21] >> 31) & 1)) goto L_7d9dc;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[14] = 31128ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[2] = SP + 40ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[14];
    cpu->regs[24] = SP + 56ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7d79cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7d84c;
    cpu->regs[22] = SP + 64ULL;
    cpu->regs[20] = SP + 48ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7d7bcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1e6824ULL);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7d7ccULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x26c900ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 112ULL;
    cpu->regs[30] = PB_BASE + 0x7d7dcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[30] = PB_BASE + 0x7d7e8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x7d7f0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[30] = PB_BASE + 0x7d7f8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdce4cULL);
    if ((cpu->regs[22])==0) goto L_7d840;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7d804ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7d840;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7d81cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x190da0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7d84c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7d840;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7d840;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7d840ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7d840:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7d848ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_7d9dc;
L_7d84c:
    cpu->regs[0] = 54008ULL;
    cpu->regs[2] = cpu->regs[24];
    PB_LDR(cpu->regs[27], (cpu->regs[23] + 0));
    cpu->regs[1] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7d864ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_7da04;
    PB_LDR(cpu->regs[0], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_7da0c;
L_7d878:
    cpu->regs[13] = 50816ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[13];
    cpu->regs[30] = PB_BASE + 0x7d888ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xed3ccULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_7db98;
    cpu->regs[12] = 44368ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[12];
    cpu->regs[30] = PB_BASE + 0x7d8a0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7db98;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_7da20;
L_7d8b8:
    cpu->regs[10] = 49376ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[10];
    cpu->regs[30] = PB_BASE + 0x7d8c8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7db9c;
    cpu->regs[30] = PB_BASE + 0x7d8d4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe5240ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_7da58;
L_7d8e0:
    PB_LDR(cpu->regs[0], (SP + 8));
    if (((cpu->regs[0] >> 63) & 1)) goto L_7da70;
L_7d8e8:
    cpu->regs[9] = 52224ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x7d8f8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7db9c;
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_7da90;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_7da7c;
L_7d910:
    cpu->regs[20] = 18446744073709551615ULL;
L_7d914:
    cpu->regs[8] = 42968ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x7d924ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7dac4;
    cpu->regs[30] = PB_BASE + 0x7d930ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_7d930:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_STR((SP + 16), cpu->regs[0]);
L_7d938:
    cpu->regs[7] = 43024ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x7d948ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7db20;
    cpu->regs[30] = PB_BASE + 0x7d954ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_7d954:
    cpu->regs[26] = 18446744073709551615ULL;
L_7d958:
    cpu->regs[6] = 59096ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x7d968ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7db9c;
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_7db78;
L_7d978:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7d994;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7d994;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7d994ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7d994:
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 152ULL;
    cpu->regs[30] = PB_BASE + 0x7d9a8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_7e4cc;
L_7d9b4:
    if ((cpu->regs[19])==0) goto L_7e6e4;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x7d9c4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7e788ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_7dbb4;
L_7d9c8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7d9d0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7d9d8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[19], (SP + 0));
L_7d9dc:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x7d9e4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7d654;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7d654;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7da00ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7d654;
L_7da04:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7dbdc;
    goto L_7dbac;
L_7da0c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7d878;
    cpu->regs[30] = PB_BASE + 0x7da1cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7d878;
L_7da20:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7da38;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7da38;
    cpu->regs[30] = PB_BASE + 0x7da38ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7da38:
    cpu->regs[1] = cpu->regs[21] + (4ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 7712));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_7da4c;
    PB_STRW((cpu->regs[1] + 7712), cpu->regs[0]);
L_7da4c:
    cpu->regs[11] = 24096ULL;
    cpu->regs[25] = cpu->regs[21] + cpu->regs[11];
    goto L_7d8b8;
L_7da58:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7d8e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7da6cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7d8e0;
L_7da70:
    cpu->regs[30] = PB_BASE + 0x7da74ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_7db9c;
    goto L_7d8e8;
L_7da7c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7d910;
    cpu->regs[30] = PB_BASE + 0x7da8cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7d910;
L_7da90:
    cpu->regs[30] = PB_BASE + 0x7da94ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7dab4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7dab4;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7dab4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7dab4:
    if (!((cpu->regs[20] >> 63) & 1)) goto L_7d914;
    cpu->regs[30] = PB_BASE + 0x7dabcULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_7db9c;
    goto L_7d914;
L_7dac4:
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_7dae8;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7d930;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7d930;
    cpu->regs[30] = PB_BASE + 0x7dae4ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7d930;
L_7dae8:
    cpu->regs[30] = PB_BASE + 0x7daecULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe5240ULL);
    PB_STR((SP + 16), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7db0c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7db0c;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7db0cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7db0c:
    PB_LDR(cpu->regs[0], (SP + 16));
    if (!((cpu->regs[0] >> 63) & 1)) goto L_7d938;
    cpu->regs[30] = PB_BASE + 0x7db18ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_7db9c;
    goto L_7d938;
L_7db20:
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_7db44;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7d954;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7d954;
    cpu->regs[30] = PB_BASE + 0x7db40ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7d954;
L_7db44:
    cpu->regs[30] = PB_BASE + 0x7db48ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7db68;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7db68;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7db68ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7db68:
    if (!((cpu->regs[26] >> 63) & 1)) goto L_7d958;
    cpu->regs[30] = PB_BASE + 0x7db70ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_7db9c;
    goto L_7d958;
L_7db78:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7db90;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7db90;
    cpu->regs[30] = PB_BASE + 0x7db90ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7db90:
    cpu->regs[24] = 0ULL;
    goto L_7d978;
L_7db98:
    cpu->regs[25] = 0ULL;
L_7db9c:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x7dba4ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7dbacULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdce4cULL);
L_7dbac:
    cpu->regs[30] = PB_BASE + 0x7dbb0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_7dbdc;
L_7dbb4:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7dbc4ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7d9c8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_7e4e4;
L_7dbd4:
    if ((cpu->regs[24])!=0) goto L_7e4fc;
L_7dbd8:
    PB_LDR(cpu->regs[19], (SP + 0));
L_7dbdc:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 16));
    PB_LDR(cpu->regs[22], (cpu->regs[23] + 0));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7dbecULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x7e788ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_7d9dc;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[5] = 30600ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x7dc00ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7dc14;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_7dc3c;
L_7dc14:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7dc1cULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[30] = PB_BASE + 0x7dc20ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[0] + 184ULL;
    cpu->regs[30] = PB_BASE + 0x7dc30ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7dcd0;
    goto L_7d9dc;
L_7dc3c:
    cpu->regs[4] = 38256ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x7dc48ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x12b670ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_7dcb4;
    cpu->regs[3] = 30384ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x7dc5cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x12b670ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_7dcb4;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7dc70ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[24] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_7dc90;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7dc90;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7dc90ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7dc90:
    FLAG_CMP(cpu->regs[24], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7d9dc;
    cpu->regs[0] = PB_BASE + 0x2b3000ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[0] + 1376ULL;
    cpu->regs[30] = PB_BASE + 0x7dca8ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7dcd0;
    goto L_7d9dc;
L_7dcb4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7dcd0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7dcd0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7dcd0ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7dcd0:
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x7dcd8ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x1e8fa0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7dcec;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_7dd24;
L_7dcec:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7dcf4ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[30] = PB_BASE + 0x7dcf8ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[0] + 400ULL;
    cpu->regs[30] = PB_BASE + 0x7dd08ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7d9dc;
L_7dd10:
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_NE) goto L_7dd5c;
    goto L_7dd8c;
L_7dd24:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7dd30ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7dd50;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7dd50;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7dd50ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7dd50:
    FLAG_CMP(cpu->regs[24], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7dd10;
    goto L_7d9dc;
L_7dd5c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7dd64ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x12cb88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7ddac;
    cpu->regs[30] = PB_BASE + 0x7dd70ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 200ULL;
    cpu->regs[30] = PB_BASE + 0x7dd80ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
L_7dd88:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_7d9dc;
L_7dd8c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[22], (cpu->regs[23] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_7de84;
    goto L_7de3c;
L_7ddac:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_7ddd4;
L_7ddb8:
    cpu->regs[0] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[0] + 1656ULL;
    cpu->regs[30] = PB_BASE + 0x7ddc8ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7de00;
    goto L_7dde0;
L_7ddd4:
    cpu->regs[30] = PB_BASE + 0x7ddd8ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x1e2680ULL);
    if ((cpu->regs[0])!=0) goto L_7ddb8;
    goto L_7de00;
L_7dde0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7d9dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7d9dc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7ddfcULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7d9dc;
L_7de00:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7de10ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_7de30;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7de30;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7de30ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7de30:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
    goto L_7dd88;
L_7de3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72)); PB_LDR(cpu->regs[20], (cpu->regs[19] + 72) + 8);
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_7e278;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_7e278;
    cpu->regs[30] = PB_BASE + 0x7de64ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x1db1b0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7e278;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7de74ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xac694ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_7e1e8;
    goto L_7e1fc;
L_7de84:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3520));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_7e14c;
    PB_LDR(cpu->regs[25], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[25])==0) goto L_7e278;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_7e278;
    if ((cpu->regs[0])==0) goto L_7e278;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2432));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_7e278;
L_7ded0:
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_7dee8;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_EQ) goto L_7ded0;
L_7dee8:
    PB_LDR(cpu->regs[26], (cpu->regs[2] + 24));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x7def4ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x1dc120ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x7defcULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x220a64ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7df1c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7df1c;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7df1cULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7df1c:
    if ((cpu->regs[20])==0) goto L_7e4bc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7df28ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x14d3acULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[24] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_7df48;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7df48;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7df48ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7df48:
    if ((cpu->regs[24])==0) goto L_7e4bc;
    cpu->regs[2] = 56128ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x7df5cULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x11e710ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_7e0f0;
    if (FLAG_EQ) goto L_7e030;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x7df70ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xc6b30ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7e0f0;
    cpu->regs[1] = 56128ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x7df84ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_7dfa8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7e0f0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7e0f0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7dfa4ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7e0f0;
L_7dfa8:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[2] = SP + 64ULL;
    cpu->regs[30] = PB_BASE + 0x7dfb4ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x112290ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7dfd4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7dfd4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7dfd4ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7dfd4:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e0f0;
    PB_LDR(cpu->regs[0], (SP + 64));
    if ((cpu->regs[0])==0) goto L_7e030;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7dffc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7dffc;
    cpu->regs[30] = PB_BASE + 0x7dffcULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7dffc:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7e018;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7e018;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7e018ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e018:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x7e028ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_7e110;
L_7e030:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7e03cULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xac694ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7e05c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7e05c;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7e05cULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e05c:
    if ((cpu->regs[20])!=0) goto L_7e114;
    cpu->regs[30] = PB_BASE + 0x7e064ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_7e4bc;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x7e074ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x14d3acULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7e4bc;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7e084ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xac694ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_7e0a4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7e0a4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e0a4ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e0a4:
    if ((cpu->regs[20])!=0) goto L_7e114;
    cpu->regs[30] = PB_BASE + 0x7e0acULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_7e4bc;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[30] = PB_BASE + 0x7e0bcULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x14d3acULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7e4bc;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7e0ccULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xac694ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_7e110;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7e110;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e0ecULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7e110;
L_7e0f0:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7e4bc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7e4bc;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7e10cULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7e4bc;
L_7e110:
    if ((cpu->regs[20])==0) goto L_7e4bc;
L_7e114:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[24] = PB_BASE + 0x3d9000ULL;
    cpu->regs[30] = PB_BASE + 0x7e120ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[24] = cpu->regs[24] + 3440ULL;
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[21] = 0ULL;
L_7e12c:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + (cpu->regs[21] << 3)));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x7e138ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7e708;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[21], 301ULL);
    if (FLAG_NE) goto L_7e12c;
    goto L_7e6ec;
L_7e14c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2840));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_7e278;
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    FLAG_CMP(cpu->regs[24], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_7e278;
    FLAG_CMP(cpu->regs[24], cpu->regs[25]);
    if (FLAG_EQ) goto L_7e278;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_7e278;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_7e278;
    cpu->regs[30] = PB_BASE + 0x7e1a0ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x1d5800ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7e278;
    cpu->regs[30] = PB_BASE + 0x7e1acULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x1db1b0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_7e1cc;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_7e1cc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7e1ccULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e1cc:
    if ((cpu->regs[21])==0) goto L_7e278;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e1dcULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xac694ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7e1fc;
L_7e1e8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7e1fc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e1fcULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e1fc:
    if ((cpu->regs[20])==0) goto L_7e278;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 232ULL;
    cpu->regs[30] = PB_BASE + 0x7e210ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_7e230;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7e230;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7e230ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e230:
    if ((cpu->regs[21])==0) goto L_7e278;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7e244ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7e258;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e254ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_7d9dc;
L_7e258:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7e284;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7e284;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e274ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7e284;
L_7e278:
    cpu->regs[30] = PB_BASE + 0x7e27cULL; PB_CALL(124, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_7e284;
L_7e280:
    cpu->regs[30] = PB_BASE + 0x7e284ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_7e284:
    cpu->regs[24] = PB_BASE + 0x2a2000ULL;
    cpu->regs[26] = cpu->regs[24] + 1024ULL;
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x7e298ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x1e3340ULL);
    PB_LDR(cpu->regs[21], (SP + 40));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7d9dc;
    if ((cpu->regs[21])!=0) goto L_7e2bc;
L_7e2a8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e2b0ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_7e4a0;
    goto L_7e4b4;
L_7e2bc:
    PB_LDR(cpu->regs[20], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e2c8ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7e2dc;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    FLAG_CMP((cpu->regs[0]) & (402653184ULL), 0);
    if (FLAG_EQ) goto L_7e358;
L_7e2dc:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7e2e8ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x7e788ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e2f0ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x14d650ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7e314;
    cpu->regs[30] = PB_BASE + 0x7e2fcULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 352ULL;
    cpu->regs[30] = PB_BASE + 0x7e30cULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x1e3340ULL);
    cpu->regs[22] = cpu->regs[0];
    goto L_7e340;
L_7e314:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7e320ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7e340;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7e340;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x7e340ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e340:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[24] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x7e34cULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7e494;
    goto L_7d9dc;
L_7e358:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e360ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x1fd1e8ULL);
    cpu->regs[24] = PB_BASE + 0x294000ULL;
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[22] = 0ULL;
    cpu->regs[0] = cpu->regs[24] + 384ULL;
    PB_STR((SP + 8), cpu->regs[0]);
L_7e374:
    FLAG_CMP(cpu->regs[25], cpu->regs[22]);
    if (FLAG_LE) goto L_7e2a8;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7e388ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x14d028ULL);
    cpu->regs[28] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x7e390ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x12cb88ULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7e3b0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7e3b0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x7e3b0ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e3b0:
    if ((cpu->regs[27])!=0) goto L_7e3d0;
    cpu->regs[30] = PB_BASE + 0x7e3b8ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7e3c4ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7e468;
    goto L_7e484;
L_7e3d0:
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x7e3dcULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x21d800ULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7e3fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7e3fc;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x7e3fcULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e3fc:
    if ((cpu->regs[28])==0) goto L_7e484;
    PB_LDR(cpu->regs[27], (cpu->regs[28] + 16));
    cpu->regs[24] = 0ULL;
L_7e408:
    FLAG_CMP(cpu->regs[27], cpu->regs[24]);
    if (FLAG_LE) goto L_7e44c;
    PB_LDR(cpu->regs[2], (cpu->regs[28] + 24));
    cpu->regs[1] = cpu->regs[20];
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + (cpu->regs[24] << 3)));
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x7e428ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x7e788ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_7e488;
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7e43cULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e488;
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_7e408;
L_7e44c:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7e468;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7e468;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x7e468ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e468:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x7e474ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e484;
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_7e374;
L_7e484:
    cpu->regs[28] = 0ULL;
L_7e488:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x7e490ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_7d9dc;
L_7e494:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7e2a8;
    goto L_7d9dc;
L_7e4a0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7e4b4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7e4b4ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7e4b4:
    cpu->regs[0] = 0ULL;
    goto L_7e748;
L_7e4bc:
    cpu->regs[30] = PB_BASE + 0x7e4c0ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7e114;
    goto L_7e280;
L_7e4cc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7d9b4;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7e4e0ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7d9b4;
L_7e4e4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7dbd4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7e4f8ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7dbd4;
L_7e4fc:
    cpu->regs[1] = SP + 64ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7e508ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[2], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_GE) goto L_7e520;
    if ((cpu->regs[0])==0) goto L_7e538;
    PB_LDR(cpu->regs[26], (SP + 64));
    goto L_7e524;
L_7e520:
    if ((cpu->regs[0])==0) goto L_7e53c;
L_7e524:
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[26], cpu->regs[0]);
    cpu->regs[26] = (FLAG_LE) ? cpu->regs[26] : cpu->regs[0];
    goto L_7e53c;
L_7e538:
    cpu->regs[26] = 18446744073709551615ULL;
L_7e53c:
    cpu->regs[0] = cpu->regs[20] & ~(((uint64_t)((int64_t)cpu->regs[20] >> 63)));
    cpu->regs[19] = cpu->regs[26] - cpu->regs[20];
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[19] = (FLAG_LT) ? cpu->regs[19] : (0ULL + 1);
    cpu->regs[30] = PB_BASE + 0x7e554ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7e6e4;
    cpu->regs[1] = 4608ULL;
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 32)) | ((0x1ULL & 0xffff) << 32);
L_7e568:
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32ULL)));
    if (FLAG_HI) goto L_7e588;
    cpu->regs[0] = cpu->regs[1] >> (cpu->regs[0] & 63);
    if (!((cpu->regs[0] >> 0) & 1)) goto L_7e588;
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    goto L_7e568;
L_7e588:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7e590ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7e5ac;
    cpu->regs[0] = cpu->regs[25] + cpu->regs[0];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + -1));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_7e5ac;
    cpu->regs[26] = cpu->regs[26] - 1ULL;
L_7e5ac:
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    cpu->regs[20] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[26];
L_7e5b4:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x7e5c0ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0x7b3e0ULL);
    if ((cpu->regs[0])==0) goto L_7e5e4;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[25];
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_GE) goto L_7e5e4;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[25] = cpu->regs[25] + cpu->regs[0];
    cpu->regs[26] = cpu->regs[26] - cpu->regs[0];
    cpu->regs[20] = cpu->regs[20] - ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    goto L_7e5b4;
L_7e5e4:
    cpu->regs[22] = PB_BASE + 0x2a9000ULL;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[22] + 2072ULL;
    cpu->regs[30] = PB_BASE + 0x7e5f4ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e6e4;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7e608ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e6e4;
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + cpu->regs[26]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_7e624;
L_7e61c:
    if (!((cpu->regs[20] >> 63) & 1)) goto L_7e640;
    goto L_7e6c4;
L_7e624:
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[0] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x7e634ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7e61c;
    goto L_7e6e4;
L_7e640:
    cpu->regs[0] = cpu->regs[22] + 2072ULL;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x7e64cULL; PB_CALL(160, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e6e4;
    cpu->regs[22] = PB_BASE + 0x299000ULL;
    cpu->regs[22] = cpu->regs[22] + 1688ULL;
L_7e65c:
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e680;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7e674ULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7e65c;
    goto L_7e6e4;
L_7e680:
    cpu->regs[20] = PB_BASE + 0x294000ULL;
    cpu->regs[20] = cpu->regs[20] + 176ULL;
    cpu->regs[22] = 0ULL;
L_7e68c:
    cpu->regs[1] = cpu->regs[27];
    FLAG_CMP(cpu->regs[19], cpu->regs[22]);
    if (FLAG_EQ) goto L_7e6b0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7e6a0ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e6e4;
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_7e68c;
L_7e6b0:
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x7e6bcULL; PB_CALL(163, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7e6e4;
L_7e6c4:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7dbd8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7dbd8;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x7e6e0ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7dbd8;
L_7e6e4:
    cpu->regs[19] = 0ULL;
    goto L_7d9c8;
L_7e6ec:
    if ((cpu->regs[20])==0) goto L_7e278;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 232ULL;
    cpu->regs[30] = PB_BASE + 0x7e700ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_7e720;
L_7e708:
    if ((cpu->regs[20])!=0) goto L_7e72c;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 264ULL;
    cpu->regs[30] = PB_BASE + 0x7e71cULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[21] = cpu->regs[0];
L_7e720:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7e728ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_7e230;
L_7e72c:
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 296ULL;
    cpu->regs[30] = PB_BASE + 0x7e740ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_7e720;
L_7e748:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_7e768;
    cpu->regs[30] = PB_BASE + 0x7e768ULL; PB_CALL(169, cpu, tlb, PB_BASE + 0x7c170ULL);
L_7e768:
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    SP = SP + 176ULL;
    return;
L_7e788:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[3] = PB_BASE + 0x293000ULL;
    cpu->regs[4] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 4064ULL;
    cpu->regs[4] = cpu->regs[4] + 240ULL;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] << 1));
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[4] : cpu->regs[3];
    { PB_CALL(170, cpu, tlb, PB_BASE + 0x1e7c40ULL); return; };
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x7e7ccULL; PB_CALL(171, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 8));
    cpu->regs[1] = PB_BASE + 0x5ac000ULL;
    cpu->regs[1] = cpu->regs[1] + 3792ULL;
    cpu->regs[1] = cpu->regs[1] + 1288ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_EQ) goto L_7e804;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[2] = PB_BASE + 0x295000ULL;
    cpu->regs[2] = cpu->regs[2] + 952ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x7e800ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_7e81c;
L_7e804:
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 24)); PB_LDR(cpu->regs[2], (cpu->regs[5] + 24) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 40)); PB_LDR(cpu->regs[4], (cpu->regs[5] + 40) + 8);
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 56));
    cpu->regs[30] = PB_BASE + 0x7e814ULL; PB_CALL(173, cpu, tlb, PB_BASE + 0x1fb420ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7e824;
L_7e81c:
    cpu->regs[0] = 0ULL;
    goto L_7e82c;
L_7e824:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_7e82c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
