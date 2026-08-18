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

void ft_PyType_GetModuleByDef(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 344));
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 16));
    FLAG_CMP(cpu->regs[4], 0ULL);
    if (FLAG_LE) goto L_14b964;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 24));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 168));
    if (!((cpu->regs[5] >> 9) & 1)) goto L_14b928;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 888));
    if ((cpu->regs[0])==0) goto L_14b928;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    if (FLAG_NE) goto L_14b928;
L_14b924:
    return;
L_14b928:
    FLAG_CMP(cpu->regs[4], 1ULL);
    if (FLAG_EQ) goto L_14b964;
    cpu->regs[3] = cpu->regs[3] + 24ULL;
    cpu->regs[5] = 1ULL;
L_14b938:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + (cpu->regs[5] << 3)));
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 168));
    if (!((cpu->regs[6] >> 9) & 1)) goto L_14b958;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 888));
    if ((cpu->regs[0])==0) goto L_14b958;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[6]);
    if (FLAG_EQ) goto L_14b924;
L_14b958:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[5]);
    if (FLAG_NE) goto L_14b938;
L_14b964:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3520ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0x14b988ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->tls_ptr;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x14b9c8ULL; PB_CALL(2, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[5], (cpu->regs[22] + cpu->regs[0]));
    cpu->regs[20] = cpu->regs[2] & 9223372036854775807ULL; FLAG_CMP(cpu->regs[20], 0);
    if (FLAG_EQ) goto L_14baf0;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_NE) goto L_14ba58;
L_14b9f0:
    PB_LDRW(cpu->regs[6], (cpu->regs[5] + 36));
    cpu->regs[3] = ((uint32_t)(cpu->regs[6] - 1ULL));
    PB_STRW((cpu->regs[5] + 36), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_14bb40;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 8));
    if ((cpu->regs[5])==0) goto L_14bad0;
L_14ba10:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[2] = cpu->regs[21] + 8ULL;
    cpu->regs[3] = cpu->regs[20] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x14ba20ULL; PB_CALL(3, cpu, tlb, cpu->regs[5]);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x14ba34ULL; PB_CALL(4, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + cpu->regs[0]));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[2] + 36), cpu->regs[0]);
L_14ba44:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_14ba58:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 344));
    if ((cpu->regs[2])==0) goto L_14bad8;
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[6], 0ULL);
    if (FLAG_LE) goto L_14bac8;
    PB_LDR(cpu->regs[7], (cpu->regs[2] + 24));
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_EQ) goto L_14b9f0;
    FLAG_CMP(cpu->regs[6], 1ULL);
    if (FLAG_EQ) goto L_14bac8;
    PB_LDR(cpu->regs[7], (cpu->regs[2] + 32));
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_EQ) goto L_14b9f0;
    FLAG_CMP(cpu->regs[6], 2ULL);
    if (FLAG_EQ) goto L_14bac8;
    PB_LDR(cpu->regs[7], (cpu->regs[2] + 40));
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_EQ) goto L_14b9f0;
    FLAG_CMP(cpu->regs[6], 3ULL);
    if (FLAG_EQ) goto L_14bac8;
    cpu->regs[2] = cpu->regs[2] + 24ULL;
    cpu->regs[7] = 3ULL;
L_14bab0:
    PB_LDR(cpu->regs[8], (cpu->regs[2] + (cpu->regs[7] << 3)));
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[8]);
    if (FLAG_EQ) goto L_14b9f0;
    FLAG_CMP(cpu->regs[6], cpu->regs[7]);
    if (FLAG_NE) goto L_14bab0;
L_14bac8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14bad0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1985a8ULL);
L_14bad0:
    cpu->regs[1] = 0ULL;
    goto L_14ba44;
L_14bad8:
    cpu->regs[2] = cpu->regs[1];
L_14badc:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 256));
    if ((cpu->regs[2])==0) goto L_14bb70;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_14b9f0;
    goto L_14badc;
L_14baf0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14baf8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x22b084ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14bad0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 3320ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x14bb1cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14bad0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14bad0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14bb38ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[1] = 0ULL;
    goto L_14ba44;
L_14bb40:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    PB_STR((SP + 56), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x14bb54ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x26c444ULL);
    PB_LDR(cpu->regs[4], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14bad0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    if ((cpu->regs[5])==0) goto L_14bad0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    goto L_14ba10;
L_14bb70:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3488));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_14b9f0;
    goto L_14bac8;
    SP = SP - 96ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 96));
    if ((cpu->regs[1])==0) goto L_14bc48;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 264));
    if ((cpu->regs[1])==0) goto L_14bc48;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3880));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x14bbd4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14be60;
    if (((cpu->regs[0] >> 63) & 1)) goto L_14be68;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_LE) goto L_14be7c;
L_14bbf0:
    cpu->regs[3] = cpu->regs[19] + cpu->regs[3];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2248));
    PB_LDRB(cpu->regs[1], (cpu->regs[3] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 5ULL));
    cpu->regs[1] = ((cpu->regs[1] & 0x1ffULL) << 5);
    cpu->regs[1] = cpu->regs[1] + 3048ULL;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[4];
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_14becc;
L_14bc1c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_14be94;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_14bc48:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2224));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_14be9c;
    cpu->regs[20] = SP + 32ULL;
    PB_STR((SP + 80), cpu->regs[21]);
    cpu->regs[21] = SP + 24ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14bc74ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x146840ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14bec0;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[6], (SP + 16));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[7];
    cpu->regs[3] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x14bc98ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x146b24ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_14bcc8;
    PB_LDR(cpu->regs[20], (SP + 32));
    FLAG_CMP(cpu->regs[6], 1ULL);
    if ((cpu->regs[20])==0) goto L_14bce0;
    if (FLAG_NE) goto L_14bcfc;
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14bcc0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_LDR(cpu->regs[21], (SP + 80));
    goto L_14bc1c;
L_14bcc8:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    cpu->regs[30] = PB_BASE + 0x14bcd8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_LDR(cpu->regs[21], (SP + 80));
    goto L_14bc1c;
L_14bce0:
    if (FLAG_NE) goto L_14bcfc;
    FLAG_CMP(cpu->regs[0], cpu->regs[7]);
    if (FLAG_EQ) goto L_14be30;
L_14bcec:
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x14bcf4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_LDR(cpu->regs[21], (SP + 80));
    goto L_14bc1c;
L_14bcfc:
    cpu->regs[19] = cpu->regs[19] + 32ULL;
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14bd0cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe9c70ULL);
    if ((cpu->regs[0])==0) goto L_14bec0;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[20]));
    PB_STRB((cpu->regs[0] + 32), cpu->regs[2]);
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[3], (SP + 8) + 8);
    cpu->regs[20] = cpu->regs[20] + cpu->regs[3];
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[20]));
    cpu->regs[20] = cpu->regs[3] + cpu->regs[20];
    PB_STRB((cpu->regs[0] + 33), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[20]));
    cpu->regs[20] = cpu->regs[3] + cpu->regs[20];
    PB_STRB((cpu->regs[0] + 34), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[20]));
    cpu->regs[20] = cpu->regs[3] + cpu->regs[20];
    PB_STRB((cpu->regs[0] + 35), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], 4ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[20]));
    cpu->regs[20] = cpu->regs[3] + cpu->regs[20];
    PB_STRB((cpu->regs[0] + 36), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], 5ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[20]));
    cpu->regs[20] = cpu->regs[3] + cpu->regs[20];
    PB_STRB((cpu->regs[0] + 37), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], 6ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + cpu->regs[20]));
    cpu->regs[20] = cpu->regs[3] + cpu->regs[20];
    PB_STRB((cpu->regs[0] + 38), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], 7ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + cpu->regs[20]));
    cpu->regs[2] = cpu->regs[3] + cpu->regs[20];
    PB_STRB((cpu->regs[0] + 39), cpu->regs[4]);
    FLAG_CMP(cpu->regs[1], 8ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + cpu->regs[2]));
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    PB_STRB((cpu->regs[0] + 40), cpu->regs[4]);
    FLAG_CMP(cpu->regs[1], 9ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + cpu->regs[2]));
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    PB_STRB((cpu->regs[0] + 41), cpu->regs[4]);
    FLAG_CMP(cpu->regs[1], 10ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + cpu->regs[2]));
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    PB_STRB((cpu->regs[0] + 42), cpu->regs[4]);
    FLAG_CMP(cpu->regs[1], 11ULL);
    if (FLAG_EQ) goto L_14be28;
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + cpu->regs[2]));
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    PB_STRB((cpu->regs[0] + 43), cpu->regs[4]);
    FLAG_CMP(cpu->regs[1], 12ULL);
    if (FLAG_EQ) goto L_14be28;
    cpu->regs[5] = cpu->regs[0] + 32ULL;
    cpu->regs[3] = 12ULL;
L_14be0c:
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + cpu->regs[2]));
    PB_STRB((cpu->regs[5] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDR(cpu->regs[4], (SP + 16));
    cpu->regs[2] = cpu->regs[2] + cpu->regs[4];
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_NE) goto L_14be0c;
L_14be28:
    PB_LDR(cpu->regs[21], (SP + 80));
    goto L_14bc1c;
L_14be30:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2392));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_14bcec;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14be54;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_14be54:
    PB_LDR(cpu->regs[21], (SP + 80));
    cpu->regs[0] = cpu->regs[19];
    goto L_14bc1c;
L_14be60:
    cpu->regs[30] = PB_BASE + 0x14be64ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_14be8c;
L_14be68:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[3] = cpu->regs[3] + cpu->regs[0]; FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_LT) goto L_14be7c;
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_GT) goto L_14bbf0;
L_14be7c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 952ULL;
    cpu->regs[30] = PB_BASE + 0x14be8cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_14be8c:
    cpu->regs[0] = 0ULL;
    goto L_14bc1c;
L_14be94:
    PB_STR((SP + 80), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x14be9cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_14be9c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 40ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x14beb8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_14bc1c;
L_14bec0:
    PB_LDR(cpu->regs[21], (SP + 80));
    cpu->regs[0] = 0ULL;
    goto L_14bc1c;
L_14becc:
    PB_STRW((cpu->regs[4] + cpu->regs[1]), cpu->regs[2]);
    goto L_14bc1c;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    return;
}
