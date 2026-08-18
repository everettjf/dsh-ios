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

void ft_PyTuple_Pack(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 144ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]);
    PB_STR((SP + 88), cpu->regs[1]); PB_STR((SP + 88) + 8, cpu->regs[2]);
    PB_STR((SP + 104), cpu->regs[3]); PB_STR((SP + 104) + 8, cpu->regs[4]);
    PB_STR((SP + 120), cpu->regs[5]); PB_STR((SP + 120) + 8, cpu->regs[6]);
    PB_STR((SP + 136), cpu->regs[7]);
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[0])==0) goto L_e11dc;
    cpu->regs[2] = SP + 80ULL;
    cpu->regs[3] = SP + 144ULL;
    cpu->regs[1] = 4294967240ULL;
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 8), cpu->regs[3]); PB_STR((SP + 8) + 8, cpu->regs[3]);
    PB_STR((SP + 24), cpu->regs[2]);
    PB_STRW((SP + 32), cpu->regs[1]); PB_STRW((SP + 32) + 4, 0ULL);
    cpu->regs[30] = PB_BASE + 0xe0f64ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdc8acULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e1088;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_e1048;
    PB_LDRW(cpu->regs[3], (SP + 32));
    PB_LDR(cpu->regs[0], (SP + 8));
    if (((cpu->regs[3] >> 31) & 1)) goto L_e10b8;
L_e0f80:
    cpu->regs[2] = cpu->regs[0] + 15ULL;
    cpu->regs[2] = cpu->regs[2] & 18446744073709551608ULL;
    PB_STR((SP + 8), cpu->regs[2]);
L_e0f8c:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e0fa0;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_e0fa0:
    PB_STR((cpu->regs[1] + 24), cpu->regs[2]);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_e1048;
    cpu->regs[4] = cpu->regs[1] + 24ULL;
    if (((cpu->regs[3] >> 31) & 1)) goto L_e10d4;
    cpu->regs[0] = 1ULL;
L_e0fb8:
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[5] = cpu->regs[0] << 3;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    PB_LDRW(cpu->regs[3], (cpu->regs[6] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_e0fd4;
    PB_STRW((cpu->regs[6] + 0), cpu->regs[3]);
L_e0fd4:
    cpu->regs[3] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[4] + cpu->regs[5]), cpu->regs[6]);
    FLAG_CMP(cpu->regs[19], cpu->regs[3]);
    if (FLAG_LE) goto L_e1048;
    cpu->regs[2] = cpu->regs[2] + 15ULL;
    cpu->regs[5] = cpu->regs[5] + 8ULL;
    cpu->regs[2] = cpu->regs[2] & 18446744073709551608ULL;
    cpu->regs[3] = cpu->regs[2] + 8ULL;
    PB_STR((SP + 8), cpu->regs[3]);
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[6] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_e100c;
    PB_STRW((cpu->regs[6] + 0), cpu->regs[2]);
L_e100c:
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    PB_STR((cpu->regs[4] + cpu->regs[5]), cpu->regs[6]);
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_LE) goto L_e1048;
L_e101c:
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[2] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_e1038;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
L_e1038:
    PB_STR((cpu->regs[4] + (cpu->regs[0] << 3)), cpu->regs[5]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_e101c;
L_e1048:
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe105cULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + -8));
    cpu->regs[3] = cpu->regs[1] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    cpu->regs[2] = cpu->regs[2] | cpu->regs[5];
    PB_STR((cpu->regs[5] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[1] + -16), cpu->regs[4]); PB_STR((cpu->regs[1] + -16) + 8, cpu->regs[2]);
    PB_STR((cpu->regs[4] + 8), cpu->regs[3]);
L_e1088:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_e11d8;
    PB_LDR(cpu->regs[19], (SP + 64));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    SP = SP + 144ULL;
    return;
L_e10b8:
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] + 8ULL));
    PB_STRW((SP + 32), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_e0f80;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    goto L_e0f8c;
L_e10d4:
    PB_LDRW(cpu->regs[3], (SP + 32));
    PB_LDR(cpu->regs[0], (SP + 8));
    if (((cpu->regs[3] >> 31) & 1)) goto L_e11a0;
L_e10e0:
    cpu->regs[2] = cpu->regs[0] + 15ULL;
    cpu->regs[2] = cpu->regs[2] & 18446744073709551608ULL;
    PB_STR((SP + 8), cpu->regs[2]);
L_e10ec:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e1100;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_e1100:
    PB_STR((cpu->regs[1] + 32), cpu->regs[2]);
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_e1048;
    if (((cpu->regs[3] >> 31) & 1)) goto L_e1118;
    cpu->regs[0] = 2ULL;
    goto L_e0fb8;
L_e1118:
    PB_LDRW(cpu->regs[3], (SP + 32));
    cpu->regs[8] = 0ULL;
    PB_LDR(cpu->regs[6], (SP + 8));
    cpu->regs[9] = 0ULL;
    cpu->regs[0] = 2ULL;
    if (((cpu->regs[3] >> 31) & 1)) goto L_e1140;
L_e1130:
    cpu->regs[2] = cpu->regs[6] + 15ULL;
    cpu->regs[7] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] & 18446744073709551608ULL;
    goto L_e1158;
L_e1140:
    cpu->regs[7] = ((uint32_t)(cpu->regs[3] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_e11bc;
    cpu->regs[2] = cpu->regs[6] + 15ULL;
    cpu->regs[8] = 1ULL;
    cpu->regs[2] = cpu->regs[2] & 18446744073709551608ULL;
L_e1158:
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[6] = cpu->regs[2];
    cpu->regs[9] = 1ULL;
L_e1164:
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_e1178;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
L_e1178:
    PB_STR((cpu->regs[4] + (cpu->regs[0] << 3)), cpu->regs[5]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_e1048;
    if (((cpu->regs[3] >> 31) & 1)) goto L_e11cc;
    if ((((uint32_t)(cpu->regs[8])))==0) goto L_e1194;
    PB_STRW((SP + 32), cpu->regs[7]);
L_e1194:
    if ((((uint32_t)(cpu->regs[9])))==0) goto L_e0fb8;
    PB_STR((SP + 8), cpu->regs[6]);
    goto L_e0fb8;
L_e11a0:
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] + 8ULL));
    PB_STRW((SP + 32), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_e10e0;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    goto L_e10ec;
L_e11bc:
    PB_LDR(cpu->regs[5], (SP + 16));
    cpu->regs[8] = 1ULL;
    cpu->regs[5] = cpu->regs[5] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    goto L_e1164;
L_e11cc:
    cpu->regs[3] = cpu->regs[7];
    if (!((cpu->regs[3] >> 31) & 1)) goto L_e1130;
    goto L_e1140;
L_e11d8:
    cpu->regs[30] = PB_BASE + 0xe11dcULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e11dc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = cpu->regs[1] + (16ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 10000));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e11f8;
    PB_STRW((cpu->regs[2] + 10000), cpu->regs[0]);
L_e11f8:
    cpu->regs[1] = cpu->regs[1] + (18ULL << 12);
    cpu->regs[1] = cpu->regs[1] + 1808ULL;
    goto L_e1088;
    SP = SP - 112ULL;
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[5] = SP + 96ULL;
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 96), cpu->regs[1]); PB_STR((SP + 96) + 8, cpu->regs[2]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe122cULL; PB_CALL(4, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[3];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + cpu->regs[0]));
    PB_STR((SP + 80), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[3] = SP + 112ULL;
    cpu->regs[2] = 4294967280ULL;
    cpu->regs[1] = cpu->regs[1] + (64ULL << 12);
    PB_STR((SP + 40), cpu->regs[5]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 7696));
    PB_STR((SP + 24), cpu->regs[3]); PB_STR((SP + 24) + 8, cpu->regs[3]);
    PB_STRW((SP + 48), cpu->regs[2]); PB_STRW((SP + 48) + 4, 0ULL);
    if ((cpu->regs[0])==0) goto L_e13a0;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 7852));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 2708));
    PB_STR((cpu->regs[1] + 7696), cpu->regs[5]);
    PB_STRW((cpu->regs[1] + 7852), cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_e13c0;
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
L_e12a0:
    PB_LDRW(cpu->regs[3], (SP + 48));
    PB_LDR(cpu->regs[1], (SP + 24));
    if (((cpu->regs[3] >> 31) & 1)) goto L_e1338;
L_e12ac:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[1] = cpu->regs[1] + 15ULL;
    cpu->regs[2] = cpu->regs[1] & 18446744073709551608ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[3] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_e12c8;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[1]);
L_e12c8:
    PB_STR((cpu->regs[0] + 24), cpu->regs[3]);
L_e12cc:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_e137c;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -8));
    PB_STR((cpu->regs[0] + 32), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0] - 16ULL;
L_e12f4:
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[0] + -16), cpu->regs[3]); PB_STR((cpu->regs[0] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
L_e130c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_e13bc;
    PB_LDR(cpu->regs[19], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    SP = SP + 112ULL;
    return;
L_e1338:
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_e12ac;
    PB_LDR(cpu->regs[7], (SP + 32));
    PB_LDR(cpu->regs[5], (cpu->regs[7] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]))));
    PB_LDRW(cpu->regs[6], (cpu->regs[5] + 0));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] + 1ULL)); FLAG_CMP(cpu->regs[6], 0);
    if (FLAG_EQ) goto L_e1390;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[6]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[5]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_e1374;
L_e1364:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 16ULL));
    cpu->regs[2] = cpu->regs[7] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_e12cc;
L_e1374:
    cpu->regs[2] = cpu->regs[1];
    goto L_e12cc;
L_e137c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_STR((cpu->regs[0] + 32), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0] - 16ULL;
    goto L_e12f4;
L_e1390:
    PB_STR((cpu->regs[0] + 24), cpu->regs[5]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_e1364;
    cpu->regs[2] = cpu->regs[1];
    goto L_e12cc;
L_e13a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xe13b0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdc988ULL);
    if ((cpu->regs[0])==0) goto L_e130c;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 0));
    goto L_e12a0;
L_e13bc:
    cpu->regs[30] = PB_BASE + 0xe13c0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e13c0:
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xe13c8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_e12a0;
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[6] = SP + 96ULL;
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    cpu->regs[5] = 4294967288ULL;
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe1414ULL; PB_CALL(8, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 80), cpu->regs[19]);
    PB_LDR(cpu->regs[4], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[19] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[2] = cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 112ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 16));
    PB_STR((SP + 40), cpu->regs[6]);
    cpu->regs[1] = cpu->regs[1] + (64ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 7688));
    PB_STR((SP + 24), cpu->regs[2]); PB_STR((SP + 24) + 8, cpu->regs[2]);
    PB_STRW((SP + 48), cpu->regs[5]); PB_STRW((SP + 48) + 4, 0ULL);
    if ((cpu->regs[0])==0) goto L_e1524;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 7848));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 2708));
    PB_STR((cpu->regs[1] + 7688), cpu->regs[5]);
    PB_STRW((cpu->regs[1] + 7848), cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_e1544;
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
L_e1480:
    PB_LDRW(cpu->regs[1], (SP + 48));
    PB_LDR(cpu->regs[2], (SP + 24));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e14f8;
L_e148c:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_e1510;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -8));
    PB_STR((cpu->regs[0] + 24), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0] - 16ULL;
L_e14b4:
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[0] + -16), cpu->regs[3]); PB_STR((cpu->regs[0] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
L_e14cc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_e1540;
    PB_LDR(cpu->regs[19], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    SP = SP + 112ULL;
    return;
L_e14f8:
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_e148c;
    PB_LDR(cpu->regs[2], (SP + 32));
    cpu->regs[2] = cpu->regs[2] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    goto L_e148c;
L_e1510:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_STR((cpu->regs[0] + 24), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0] - 16ULL;
    goto L_e14b4;
L_e1524:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xe1534ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdc988ULL);
    if ((cpu->regs[0])==0) goto L_e14cc;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 0));
    goto L_e1480;
L_e1540:
    cpu->regs[30] = PB_BASE + 0xe1544ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e1544:
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xe154cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_e1480;
}
