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

void ft_PyObject_Free(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
    SP = SP - 96ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[4];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[6], (cpu->regs[1] + 32));
    PB_STR((SP + 80), cpu->regs[25]);
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 0));
    PB_STR((SP + 8), cpu->regs[7]);
    cpu->regs[7] = 0ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[6] + 10));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_dfd64;
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_e0144;
L_dfd64:
    cpu->regs[3] = SP;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xdfd78ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdd360ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_EQ) goto L_e0154;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + -16));
    if ((cpu->regs[0])!=0) goto L_dfda4;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_dfe8c;
L_dfd98:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_dfeb0;
L_dfda4:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dfed4;
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_e0040;
    PB_LDRB(cpu->regs[25], (cpu->regs[20] + 24));
    if ((((uint32_t)(cpu->regs[25])))!=0) goto L_e01f4;
L_dfdc4:
    cpu->regs[2] = cpu->regs[24] + (64ULL << 12);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[23];
    PB_LDR(cpu->regs[24], (cpu->regs[2] + 8576));
    cpu->regs[24] = cpu->regs[24] + 256ULL;
    PB_STR((cpu->regs[2] + 8576), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 12), 0ULL);
L_dfde0:
    cpu->regs[30] = PB_BASE + 0xdfde4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe0260ULL);
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_dff54;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[0] = 1ULL;
    PB_STRB((cpu->regs[1] + 32), cpu->regs[3]);
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32));
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 10));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 9));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[2] & 63);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_dff80;
L_dfe18:
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[3] << 4);
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 40));
    cpu->regs[4] = cpu->regs[1] + cpu->regs[0];
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[21]);
    if ((cpu->regs[2])!=0) goto L_e0184;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[3] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[4] + 8), cpu->regs[22]);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STR((cpu->regs[20] + 16), cpu->regs[2]); PB_STR((cpu->regs[20] + 16) + 8, cpu->regs[24]);
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[0]);
L_dfe50:
    cpu->regs[0] = 0ULL;
L_dfe54:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_e01c8;
    PB_LDR(cpu->regs[25], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_dfe8c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_e0088;
L_dfe94:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2640));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_e00e8;
L_dfea4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xdfeacULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_dfda4;
L_dfeb0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_e00ac;
L_dfeb8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2640));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_dfea4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + -16));
    if ((cpu->regs[0])==0) goto L_dfda4;
    goto L_dfea4;
L_dfed4:
    PB_LDR(cpu->regs[25], (SP + 0));
    FLAG_CMP(cpu->regs[25], cpu->regs[22]);
    if (FLAG_EQ) goto L_dff28;
    PB_LDRB(cpu->regs[23], (cpu->regs[20] + 24));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_dffbc;
    cpu->regs[0] = cpu->regs[24] + (64ULL << 12);
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8576));
    cpu->regs[1] = cpu->regs[1] + 256ULL;
    PB_STR((cpu->regs[0] + 8576), cpu->regs[1]);
    if ((cpu->regs[3])!=0) goto L_e0000;
L_dff00:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    cpu->regs[3] = 1ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 10));
    PB_LDRB(cpu->regs[4], (cpu->regs[2] + 9));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[4] & 63);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e00d0;
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[19] << 4);
    cpu->regs[2] = cpu->regs[2] + cpu->regs[3];
    PB_STR((cpu->regs[2] + 40), cpu->regs[22]);
    PB_STR((cpu->regs[20] + 24), cpu->regs[1]);
L_dff28:
    if ((cpu->regs[25])==0) goto L_dff34;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_e0020;
L_dff34:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_dfe50;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_dfe50;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xdff50ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_dfe50;
L_dff54:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_e011c;
    cpu->regs[1] = cpu->regs[19] + (cpu->regs[0] << 1);
    cpu->regs[0] = 1ULL;
    PB_STRH((cpu->regs[1] + 32), cpu->regs[3]);
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 10));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 9));
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[2] & 63);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_dfe18;
    /* nop */
    /* nop */
L_dff80:
    cpu->regs[1] = cpu->regs[3] + (cpu->regs[3] << 1);
    cpu->regs[6] = cpu->regs[19] + 32ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 3);
    cpu->regs[5] = cpu->regs[6] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[3] + 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 16));
    PB_STR((cpu->regs[5] + 8), cpu->regs[21]);
    PB_STR((cpu->regs[6] + cpu->regs[1]), cpu->regs[23]);
    cpu->regs[3] = cpu->regs[4] + 1ULL;
    PB_STR((cpu->regs[5] + 16), cpu->regs[22]);
    cpu->regs[1] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 16), cpu->regs[3]); PB_STR((cpu->regs[20] + 16) + 8, cpu->regs[24]);
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[0]);
    goto L_dfe50;
L_dffbc:
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 1ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xdffd4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x9b684ULL);
    cpu->regs[0] = cpu->regs[24] + (64ULL << 12);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 40));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8576));
    cpu->regs[4] = cpu->regs[4] + 256ULL;
    PB_STR((cpu->regs[0] + 8576), cpu->regs[4]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    if ((cpu->regs[3])==0) goto L_dff00;
    /* nop */
    /* nop */
    /* nop */
L_e0000:
    PB_STR((cpu->regs[3] + (cpu->regs[19] << 3)), cpu->regs[22]);
    if ((cpu->regs[25])==0) goto L_e00f4;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    PB_STR((cpu->regs[20] + 24), cpu->regs[1]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_dff34;
    /* nop */
    /* nop */
    /* nop */
L_e0020:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_dff34;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe003cULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    goto L_dff34;
L_e0040:
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 16));
    cpu->regs[2] = 64ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[3] = 1ULL;
    cpu->regs[4] = cpu->regs[4] + (cpu->regs[4] << 1);
    cpu->regs[4] = cpu->regs[4] | 8ULL;
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[4] = cpu->regs[4] | 7ULL;
    cpu->regs[4] = (((uint64_t)(cpu->regs[4])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[4])));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[4]));
    cpu->regs[30] = PB_BASE + 0xe0070ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe03e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e0154;
    PB_LDRB(cpu->regs[25], (cpu->regs[20] + 24));
    if ((((uint32_t)(cpu->regs[25])))!=0) goto L_e01f4;
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32));
    goto L_dfdc4;
L_e0088:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_e01d8;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
L_e00a0:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_dfd98;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    goto L_dfe94;
L_e00ac:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_e01cc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
L_e00c4:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_dfda4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    goto L_dfeb8;
L_e00d0:
    cpu->regs[0] = cpu->regs[19] + (cpu->regs[19] << 1);
    cpu->regs[0] = cpu->regs[2] + (cpu->regs[0] << 3);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    PB_STR((cpu->regs[0] + 48), cpu->regs[22]);
    PB_STR((cpu->regs[20] + 24), cpu->regs[1]);
    goto L_dff28;
L_e00e8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + -16));
    if ((cpu->regs[0])==0) goto L_dfd98;
    goto L_dfea4;
L_e00f4:
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + -2));
    cpu->regs[2] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    cpu->regs[2] = cpu->regs[3] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    PB_STRB((cpu->regs[2] + -2), cpu->regs[19]);
    PB_STRB((cpu->regs[3] + -2), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[20] + 16), cpu->regs[0]); PB_STR((cpu->regs[20] + 16) + 8, cpu->regs[1]);
    goto L_dff34;
L_e011c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_e01e4;
    cpu->regs[0] = cpu->regs[19] + (cpu->regs[0] << 2);
    PB_STRW((cpu->regs[0] + 32), cpu->regs[3]);
L_e012c:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 10));
    cpu->regs[0] = 1ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 9));
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[2] & 63);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_dfe18;
    goto L_dff80;
L_e0144:
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xe014cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18ce80ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dfd64;
L_e0154:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e0168;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e0238;
L_e0168:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e017c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e0244;
L_e017c:
    cpu->regs[0] = 4294967295ULL;
    goto L_dfe54;
L_e0184:
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + -2));
    cpu->regs[1] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    cpu->regs[1] = cpu->regs[2] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_STRB((cpu->regs[1] + -2), cpu->regs[3]);
    PB_STRB((cpu->regs[2] + -2), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32)); PB_LDR(cpu->regs[2], (cpu->regs[20] + 32) + 8);
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_STR((cpu->regs[2] + (cpu->regs[3] << 3)), cpu->regs[22]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[4] + 1ULL;
    PB_STR((cpu->regs[20] + 16), cpu->regs[3]); PB_STR((cpu->regs[20] + 16) + 8, cpu->regs[24]);
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[2]);
    goto L_dfe50;
L_e01c8:
    cpu->regs[30] = PB_BASE + 0xe01ccULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e01cc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe01d4ULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    goto L_e00c4;
L_e01d8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe01e0ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    goto L_e00a0;
L_e01e4:
    cpu->regs[0] = cpu->regs[19] + (cpu->regs[0] << 3);
    PB_STR((cpu->regs[0] + 32), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    goto L_e012c;
L_e01f4:
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xe020cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x9b684ULL);
    cpu->regs[2] = cpu->regs[24] + (64ULL << 12);
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[25]));
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32));
    cpu->regs[1] = cpu->regs[23];
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8576));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[4] + 256ULL;
    PB_STR((cpu->regs[2] + 8576), cpu->regs[4]);
    cpu->regs[24] = cpu->regs[3] | cpu->regs[4];
    PB_STRW((cpu->regs[19] + 12), 0ULL);
    goto L_dfde0;
L_e0238:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe0240ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e0168;
L_e0244:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe024cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_dfe54;
    /* nop */
    /* nop */
    /* nop */
L_e0260:
    PB_LDRB(cpu->regs[5], (cpu->regs[0] + 8));
    cpu->regs[3] = 1ULL;
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[5] & 63);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    cpu->regs[0] = cpu->regs[3] & cpu->regs[1];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_e0338;
    cpu->regs[2] = cpu->regs[4] + cpu->regs[0];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,1); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[2] >> 31) & 1)) goto L_e0290;
L_e028c:
    return;
L_e0290:
    cpu->regs[1] = cpu->regs[1] >> 5;
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[0] << 2);
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] & cpu->regs[3];
    cpu->regs[2] = cpu->regs[4] + cpu->regs[0];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,1); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[2] >> 31) & 1)) goto L_e028c;
L_e02b0:
    cpu->regs[2] = cpu->regs[1] >> 5;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[0] << 2);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[1] & cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_e0318;
    cpu->regs[1] = cpu->regs[4] + cpu->regs[0];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[1] + 32),&_s,1); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[1] >> 31) & 1)) goto L_e028c;
L_e02d8:
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[0] << 2);
    cpu->regs[2] = cpu->regs[2] >> 5;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[1] & cpu->regs[3];
    cpu->regs[1] = cpu->regs[4] + cpu->regs[0];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[1] + 32),&_s,1); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_e02d8;
    return;
L_e02fc:
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[1] + 32),&_s,2); cpu->regs[6] = (uint64_t)(int64_t)_s; } while(0);
L_e0300:
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[0] << 2);
    cpu->regs[2] = cpu->regs[2] >> 5;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    if (((cpu->regs[6] >> 63) & 1)) goto L_e028c;
    cpu->regs[0] = cpu->regs[1] & cpu->regs[3];
L_e0318:
    cpu->regs[1] = cpu->regs[4] + (cpu->regs[0] << 1);
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(15ULL)));
    if (FLAG_LE) goto L_e02fc;
    cpu->regs[1] = cpu->regs[4] + (cpu->regs[0] << 2);
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_e03c0;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[1] + 32),&_s,4); cpu->regs[6] = (uint64_t)(int64_t)_s; } while(0);
    goto L_e0300;
L_e0338:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_e0374;
    cpu->regs[2] = cpu->regs[4] + (cpu->regs[0] << 1);
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,2); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[2] >> 31) & 1)) goto L_e028c;
    cpu->regs[1] = cpu->regs[1] >> 5;
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[0] << 2);
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] & cpu->regs[3]));
    cpu->regs[0] = cpu->regs[0] & cpu->regs[3];
    cpu->regs[2] = cpu->regs[4] + (cpu->regs[2] << 1);
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,2); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[2] >> 63) & 1)) goto L_e02b0;
L_e0370:
    return;
L_e0374:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_e03b4;
    cpu->regs[2] = cpu->regs[4] + (cpu->regs[0] << 2);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
L_e0384:
    if (((cpu->regs[2] >> 63) & 1)) goto L_e028c;
    cpu->regs[1] = cpu->regs[1] >> 5;
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[0] << 2);
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] & cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_e03cc;
    cpu->regs[2] = cpu->regs[4] + (cpu->regs[0] << 2);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[2] >> 63) & 1)) goto L_e0370;
    goto L_e02b0;
L_e03b4:
    cpu->regs[2] = cpu->regs[4] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 32));
    goto L_e0384;
L_e03c0:
    cpu->regs[1] = cpu->regs[4] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[6], (cpu->regs[1] + 32));
    goto L_e0300;
L_e03cc:
    cpu->regs[2] = cpu->regs[4] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 32));
    if (((cpu->regs[2] >> 63) & 1)) goto L_e0370;
    goto L_e02b0;
    /* nop */
L_e03e0:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    cpu->regs[29] = SP;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(63ULL)));
    if (FLAG_HI) goto L_e07f4;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32)); PB_LDR(cpu->regs[24], (cpu->regs[20] + 32) + 8);
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 10));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    cpu->regs[2] = (FLAG_NE) ? 1 : 0;
    cpu->regs[23] = ((uint32_t)(cpu->regs[2] & cpu->regs[3]));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xe0428ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xde420ULL);
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e07dc;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 9));
    cpu->regs[2] = 1ULL;
    PB_LDRB(cpu->regs[4], (cpu->regs[0] + 9));
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    cpu->regs[3] = cpu->regs[2] << (cpu->regs[1] & 63);
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[4] & 63);
    if ((cpu->regs[24])!=0) goto L_e06b8;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 10));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_e0554;
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_e0660;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 24));
    cpu->regs[3] = cpu->regs[0] + 32ULL;
    cpu->regs[3] = cpu->regs[3] + cpu->regs[2];
    FLAG_CMP(cpu->regs[4], cpu->regs[22]);
    if (FLAG_NE) goto L_e05d4;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 10));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_e05d4;
    cpu->regs[2] = cpu->regs[22] << 4;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LS) goto L_e05b0;
    cpu->regs[0] = cpu->regs[3] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_e05c0;
L_e0498:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xe04a0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[3] = cpu->regs[0];
L_e04a4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe04b4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe0800ULL);
L_e04b4:
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    cpu->regs[0] = cpu->regs[0] + 216ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_e064c;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_e0528;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 10));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e0528;
    cpu->regs[21] = cpu->regs[21] + (66ULL << 12);
    cpu->regs[21] = cpu->regs[21] + 384ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 1300));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(79ULL)));
    if (FLAG_GT) goto L_e0528;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[2] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[21] + 1300), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    PB_STR((cpu->regs[2] + 656), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[22];
    PB_STR((cpu->regs[1] + 16), cpu->regs[0]); PB_STR((cpu->regs[1] + 16) + 8, cpu->regs[22]);
L_e0510:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_e0520:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_e0528:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    cpu->regs[30] = PB_BASE + 0xe0540ULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[22];
    PB_STR((cpu->regs[1] + 16), cpu->regs[0]); PB_STR((cpu->regs[1] + 16) + 8, cpu->regs[22]);
    goto L_e0510;
L_e0554:
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[4] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    FLAG_CMP(cpu->regs[5], cpu->regs[22]);
    if (FLAG_NE) goto L_e0724;
    cpu->regs[2] = 24ULL;
    cpu->regs[2] = cpu->regs[22] * cpu->regs[2];
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_LO) goto L_e05c4;
    if (FLAG_LS) goto L_e0590;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_LO) goto L_e05c0;
L_e0590:
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0xe0598ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[4] = cpu->regs[0];
L_e059c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe05acULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe1b64ULL);
    goto L_e04b4;
L_e05b0:
    if (FLAG_HS) goto L_e0498;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_HS) goto L_e0498;
L_e05c0:
    __builtin_trap();
L_e05c4:
    cpu->regs[0] = cpu->regs[4] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_e0590;
    __builtin_trap();
L_e05d4:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_e04a4;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[6] = cpu->regs[3] + (cpu->regs[22] << 4);
L_e05e4:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    if ((cpu->regs[2])==0) goto L_e0600;
    PB_LDR(cpu->regs[4], cpu->regs[1]); PB_LDR(cpu->regs[5], cpu->regs[1] + 8); cpu->regs[1] += 16;
    PB_STR(cpu->regs[0], cpu->regs[4]); PB_STR(cpu->regs[0] + 8, cpu->regs[5]); cpu->regs[0] += 16;
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_NE) goto L_e05e4;
    goto L_e04a4;
L_e0600:
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    if ((cpu->regs[2])==0) goto L_e0600;
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 0)); PB_LDR(cpu->regs[9], (cpu->regs[1] + 0) + 8);
    PB_STR(cpu->regs[0], cpu->regs[8]); PB_STR(cpu->regs[0] + 8, cpu->regs[9]); cpu->regs[0] += 16;
    cpu->regs[1] = cpu->regs[4] + 32ULL;
    FLAG_CMP(cpu->regs[6], cpu->regs[0]);
    if (FLAG_NE) goto L_e05e4;
    goto L_e04a4;
L_e0628:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe0630ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe0800ULL);
L_e0630:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe063cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe9320ULL);
    PB_STR((cpu->regs[20] + 40), 0ULL);
    PB_LDRB(cpu->regs[0], (cpu->regs[24] + -1));
    cpu->regs[0] = cpu->regs[24] - cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xe064cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_e064c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[22];
    PB_STR((cpu->regs[1] + 16), cpu->regs[0]); PB_STR((cpu->regs[1] + 16) + 8, cpu->regs[22]);
    goto L_e0510;
L_e0660:
    cpu->regs[4] = cpu->regs[0] + 32ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + cpu->regs[2];
    cpu->regs[2] = cpu->regs[4];
L_e0670:
    FLAG_CMP(cpu->regs[3], cpu->regs[22]);
    if (FLAG_GE) goto L_e06a8;
L_e0678:
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 8));
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    if ((cpu->regs[5])==0) goto L_e0678;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 0));
    PB_STR((cpu->regs[2] + 8), cpu->regs[6]);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[2] = cpu->regs[2] + 24ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 24));
    PB_STR((cpu->regs[2] + -24), cpu->regs[6]);
    PB_STR((cpu->regs[2] + -8), cpu->regs[5]);
    goto L_e0670;
L_e06a8:
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe06b4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1b64ULL);
    goto L_e04b4;
L_e06b8:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 10));
    cpu->regs[4] = cpu->regs[19] + 32ULL;
    cpu->regs[3] = cpu->regs[4] + cpu->regs[3];
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_e0760;
    cpu->regs[1] = cpu->regs[0] + 32ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[8] = 18446744073709551613ULL;
    cpu->regs[2] = cpu->regs[1];
L_e06dc:
    FLAG_CMP(cpu->regs[4], cpu->regs[22]);
    if (FLAG_GE) goto L_e0628;
    PB_LDR(cpu->regs[7], (cpu->regs[20] + 40));
    cpu->regs[6] = cpu->regs[8] - cpu->regs[4];
    PB_LDRB(cpu->regs[5], (cpu->regs[7] + cpu->regs[6]));
    PB_LDRB(cpu->regs[6], (cpu->regs[7] + cpu->regs[6]));
    cpu->regs[5] = cpu->regs[5] << 4;
    PB_LDR(cpu->regs[7], (cpu->regs[3] + cpu->regs[5]));
    PB_LDRW(cpu->regs[5], (cpu->regs[7] + 0));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] + 1ULL)); FLAG_CMP(cpu->regs[5], 0);
    if (FLAG_NE) goto L_e0784;
L_e0708:
    cpu->regs[5] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[6]));
    PB_STR((cpu->regs[2] + 0), cpu->regs[7]);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[2] = cpu->regs[2] + 16ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[24] + (cpu->regs[5] << 3)));
    PB_STR((cpu->regs[2] + -8), cpu->regs[5]);
    goto L_e06dc;
L_e0724:
    cpu->regs[3] = 0ULL;
    cpu->regs[5] = 24ULL;
L_e072c:
    FLAG_CMP(cpu->regs[3], cpu->regs[22]);
    if (FLAG_GE) goto L_e059c;
L_e0734:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] + 24ULL;
    if ((cpu->regs[0])==0) goto L_e0734;
    cpu->regs[0] = cpu->regs[3] * cpu->regs[5] + cpu->regs[4];
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0)); PB_LDR(cpu->regs[7], (cpu->regs[2] + 0) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 16));
    PB_STR((cpu->regs[0] + 0), cpu->regs[6]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[7]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[2]);
    goto L_e072c;
L_e0760:
    cpu->regs[1] = cpu->regs[0] + 32ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[2] = cpu->regs[1];
L_e0770:
    FLAG_CMP(cpu->regs[4], cpu->regs[22]);
    if (FLAG_LT) goto L_e078c;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe0780ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe1b64ULL);
    goto L_e0630;
L_e0784:
    PB_STRW((cpu->regs[7] + 0), cpu->regs[5]);
    goto L_e0708;
L_e078c:
    PB_LDR(cpu->regs[7], (cpu->regs[20] + 40));
    cpu->regs[5] = 18446744073709551613ULL;
    cpu->regs[5] = cpu->regs[5] - cpu->regs[4];
    PB_LDRB(cpu->regs[6], (cpu->regs[7] + cpu->regs[5]));
    PB_LDRB(cpu->regs[7], (cpu->regs[7] + cpu->regs[5]));
    cpu->regs[5] = cpu->regs[6] << 4;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + cpu->regs[5]));
    PB_LDRW(cpu->regs[6], (cpu->regs[5] + 0));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] + 1ULL)); FLAG_CMP(cpu->regs[6], 0);
    if (FLAG_EQ) goto L_e07b8;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[6]);
L_e07b8:
    cpu->regs[6] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[7]));
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[5] + 24));
    PB_STR((cpu->regs[2] + 8), cpu->regs[5]);
    cpu->regs[2] = cpu->regs[2] + 24ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[24] + (cpu->regs[6] << 3)));
    PB_STR((cpu->regs[2] + -24), cpu->regs[7]);
    PB_STR((cpu->regs[2] + -8), cpu->regs[5]);
    goto L_e0770;
L_e07dc:
    PB_STR((cpu->regs[20] + 32), cpu->regs[19]);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_e0520;
L_e07f4:
    cpu->regs[30] = PB_BASE + 0xe07f8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_e0520;
L_e0800:
    PB_LDRB(cpu->regs[6], (cpu->regs[0] + 8));
    cpu->regs[8] = 1ULL;
    cpu->regs[8] = cpu->regs[8] << (cpu->regs[6] & 63);
    cpu->regs[8] = cpu->regs[8] - 1ULL;
    if ((cpu->regs[2])==0) goto L_e089c;
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = cpu->regs[3] << 4;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + cpu->regs[4]));
    PB_LDR(cpu->regs[7], (cpu->regs[4] + 24));
    cpu->regs[4] = cpu->regs[8] & cpu->regs[7];
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_e086c;
L_e0830:
    cpu->regs[5] = cpu->regs[0] + cpu->regs[4];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[5] + 32),&_s,1); cpu->regs[9] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[9], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_e08b0;
L_e0840:
    PB_STRB((cpu->regs[5] + 32), cpu->regs[3]);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_e089c;
L_e0850:
    PB_LDRB(cpu->regs[6], (cpu->regs[0] + 8));
L_e0854:
    cpu->regs[4] = cpu->regs[3] << 4;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + cpu->regs[4]));
    PB_LDR(cpu->regs[7], (cpu->regs[4] + 24));
    cpu->regs[4] = cpu->regs[8] & cpu->regs[7];
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(7ULL)));
    if (FLAG_LE) goto L_e0830;
L_e086c:
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_e0958;
    cpu->regs[9] = cpu->regs[0] + (cpu->regs[4] << 1);
    cpu->regs[5] = cpu->regs[4] << 1;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[9] + 32),&_s,2); cpu->regs[9] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[9], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_e08b0;
L_e0888:
    cpu->regs[5] = cpu->regs[0] + cpu->regs[5];
    PB_STRH((cpu->regs[5] + 32), cpu->regs[3]);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_e0850;
L_e089c:
    return;
L_e08a0:
    cpu->regs[5] = cpu->regs[0] + (cpu->regs[4] << 3);
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 32));
    FLAG_CMP(cpu->regs[5], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e0924;
L_e08b0:
    cpu->regs[5] = cpu->regs[4] << 2;
L_e08b4:
    cpu->regs[7] = cpu->regs[7] >> 5;
    cpu->regs[5] = cpu->regs[5] + cpu->regs[4];
    cpu->regs[4] = cpu->regs[7] + 1ULL;
    cpu->regs[4] = cpu->regs[4] + cpu->regs[5];
    cpu->regs[4] = cpu->regs[8] & cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_e090c;
L_e08d0:
    cpu->regs[5] = cpu->regs[0] + cpu->regs[4];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[5] + 32),&_s,1); cpu->regs[6] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[6], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e0840;
    cpu->regs[4] = cpu->regs[4] + (cpu->regs[4] << 2);
    cpu->regs[7] = cpu->regs[7] >> 5;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[4] = cpu->regs[4] + cpu->regs[7];
    cpu->regs[4] = cpu->regs[8] & cpu->regs[4];
    goto L_e08d0;
L_e08f8:
    cpu->regs[4] = cpu->regs[4] + (cpu->regs[4] << 2);
    cpu->regs[7] = cpu->regs[7] >> 5;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[4] = cpu->regs[4] + cpu->regs[7];
    cpu->regs[4] = cpu->regs[8] & cpu->regs[4];
L_e090c:
    cpu->regs[5] = cpu->regs[0] + (cpu->regs[4] << 1);
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_e0978;
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[5] + 32),&_s,2); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
L_e091c:
    FLAG_CMP(cpu->regs[5], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_e08f8;
L_e0924:
    cpu->regs[5] = cpu->regs[4] << 1;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(15ULL)));
    if (FLAG_LE) goto L_e0888;
    cpu->regs[5] = cpu->regs[4] << 2;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_e0998;
L_e093c:
    cpu->regs[5] = cpu->regs[0] + cpu->regs[5];
    PB_STRW((cpu->regs[5] + 32), cpu->regs[3]);
L_e0944:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_e089c;
    PB_LDRB(cpu->regs[6], (cpu->regs[0] + 8));
    goto L_e0854;
L_e0958:
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_e08a0;
    cpu->regs[9] = cpu->regs[0] + (cpu->regs[4] << 2);
    cpu->regs[5] = cpu->regs[4] << 2;
    PB_LDRW(cpu->regs[9], (cpu->regs[9] + 32));
    FLAG_CMP(cpu->regs[9], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e093c;
    goto L_e08b4;
L_e0978:
    cpu->regs[5] = cpu->regs[0] + (cpu->regs[4] << 2);
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_e098c;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[5] + 32),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    goto L_e091c;
L_e098c:
    cpu->regs[5] = cpu->regs[0] + (cpu->regs[4] << 3);
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 32));
    goto L_e091c;
L_e0998:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[4] << 3);
    PB_STR((cpu->regs[4] + 32), cpu->regs[3]);
    goto L_e0944;
}
