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

void ft__PyEval_SliceIndexNotNone(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22bad8ULL; PB_CALL(1, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[20], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])==0) goto L_22bb34;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    if ((cpu->regs[0])==0) goto L_22bb34;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22bafcULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_22bb1c;
L_22bb08:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
L_22bb10:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_22bb1c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 96));
    if ((cpu->regs[0])==0) goto L_22bb08;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_22bb08;
    cpu->regs[0] = 0ULL;
    goto L_22bb10;
L_22bb34:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = cpu->regs[2] + 1616ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x22bb50ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5980ULL);
    cpu->regs[0] = 0ULL;
    goto L_22bb10;
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    SP = SP - 528ULL;
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    PB_STR((SP + 520), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x22bb98ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_22bbcc;
L_22bb9c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 520));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_22bca8;
    SP = SP + 528ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_22bbcc:
    if ((cpu->regs[4])!=0) goto L_22bc5c;
    PB_STR((SP + 576), cpu->regs[23]);
    cpu->regs[19] = SP + 8ULL;
    if ((cpu->regs[3])==0) goto L_22bc80;
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = cpu->regs[2] + 1680ULL;
    cpu->regs[1] = 512ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22bbf0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22bbf8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[23] = cpu->regs[19] + cpu->regs[0];
L_22bbfc:
    cpu->regs[1] = cpu->regs[19] - cpu->regs[23];
    cpu->regs[1] = cpu->regs[1] + 512ULL;
    if ((cpu->regs[21])==0) goto L_22bc88;
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = cpu->regs[2] + 1696ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22bc1cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22bc28ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[23] = cpu->regs[23] + cpu->regs[0];
L_22bc2c:
    PB_LDRW(cpu->regs[3], (cpu->regs[22] + (cpu->regs[21] << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_22bcb0;
L_22bc38:
    cpu->regs[1] = cpu->regs[19] - cpu->regs[23];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[1] + 512ULL;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = cpu->regs[2] + 1728ULL;
    cpu->regs[30] = PB_BASE + 0x22bc54ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1815f0ULL);
    PB_LDR(cpu->regs[23], (SP + 576));
    cpu->regs[4] = cpu->regs[19];
L_22bc5c:
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(40ULL)));
    if (FLAG_EQ) goto L_22bcf4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[4];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22bc7cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_22bb9c;
L_22bc80:
    cpu->regs[23] = cpu->regs[19];
    goto L_22bbfc;
L_22bc88:
    cpu->regs[2] = PB_BASE + 0x2ab000ULL;
    cpu->regs[2] = cpu->regs[2] + 3120ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22bc98ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22bca0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[23] = cpu->regs[23] + cpu->regs[0];
    goto L_22bc38;
L_22bca8:
    PB_STR((SP + 576), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x22bcb0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_22bcb0:
    cpu->regs[0] = cpu->regs[23] - cpu->regs[19];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(219ULL)));
    if (FLAG_GT) goto L_22bc38;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = 512ULL;
    cpu->regs[2] = cpu->regs[2] + 1712ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22bcd8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22bce4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[23] = cpu->regs[23] + cpu->regs[0];
    FLAG_CMP(cpu->regs[21], 32ULL);
    if (FLAG_NE) goto L_22bc2c;
    goto L_22bc38;
L_22bcf4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = cpu->regs[4];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22bd08ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_22bb9c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = 0ULL;
L_22bd20:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LT) goto L_22bd50;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 12));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22bd44;
L_22bd34:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_22bd44:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x22bd4cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_22bd34;
L_22bd50:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[3] = (((uint64_t)(((int64_t)(cpu->regs[20] << 32)) >> 32) & 0xffffffffULL) << 4);
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 4);
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + cpu->regs[3]));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    cpu->regs[30] = PB_BASE + 0x22bd70ULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    goto L_22bd20;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    { PB_CALL(19, cpu, tlb, PB_BASE + 0xe5240ULL); return; };
    SP = SP - 128ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = SP + 16ULL;
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22bdccULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x129708ULL);
    PB_LDRW(cpu->regs[1], (SP + 16));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_22c574;
    cpu->regs[1] = 2147483648ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = 4294967295ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HI) goto L_22c574;
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_22c58c;
    cpu->regs[25] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22be08ULL; PB_CALL(21, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_22c5b4;
L_22be10:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_22c7b4;
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22504));
    if ((cpu->regs[0])==0) goto L_22c6f8;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[8] = 31888ULL;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x22be40ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_22c288;
L_22be48:
    PB_LDR(cpu->regs[19], (SP + 8));
    if ((cpu->regs[19])==0) goto L_22bfcc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[5] = 31888ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x22be60ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22c274;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22be78ULL; PB_CALL(24, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_22c5b4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_22c7b4;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 22504));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22bea4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22c6e4;
L_22bea4:
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_EQ) goto L_22bfb0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22bec0ULL; PB_CALL(25, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[20], (cpu->regs[25] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 11) & 1)) goto L_22c194;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 56));
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[2];
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LO) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    if (FLAG_HI) goto L_22c6f0;
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_HS) goto L_22bef8;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LO) goto L_22c6f0;
L_22bef8:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + cpu->regs[2]));
    if ((cpu->regs[4])==0) goto L_22c194;
    cpu->regs[0] = PB_BASE + 0x11d000ULL;
    cpu->regs[0] = cpu->regs[0] + 1996ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_NE) goto L_22c544;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 48));
    if (!((cpu->regs[0] >> 0) & 1)) goto L_22c770;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22bf38ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22bf4cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe8888ULL);
    cpu->regs[20] = cpu->regs[0];
L_22bf50:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22bf74;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22bf74;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x22bf74ULL; PB_CALL(28, cpu, tlb, cpu->regs[1]);
L_22bf74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_22c39c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_22bfb0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22bfcc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22bfcc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22bfccULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_22bfcc:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_22c1b4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 312));
    if ((cpu->regs[1])==0) goto L_22c3dc;
    cpu->regs[4] = 28552ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x22bff0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xed124ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_22c400;
    cpu->regs[30] = PB_BASE + 0x22bffcULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_22c288;
    cpu->regs[3] = 28496ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x22c014ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xed124ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_22c224;
    cpu->regs[30] = PB_BASE + 0x22c020ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_22c288;
L_22c028:
    cpu->regs[30] = PB_BASE + 0x22c02cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x23a904ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22c854;
L_22c034:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22c03cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[2] = 30960ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x22c04cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[25] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22c064;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22c848;
L_22c064:
    if ((cpu->regs[25])==0) goto L_22c838;
    if ((cpu->regs[19])!=0) goto L_22c290;
    cpu->regs[20] = 0ULL;
L_22c070:
    cpu->regs[0] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x22c078ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22c818;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_22c094;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_22c094:
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[23] + 24), cpu->regs[1]);
L_22c09c:
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_GT) goto L_22c1f4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22c0acULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdce4cULL);
    if ((cpu->regs[19])!=0) goto L_22c21c;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = 570425344ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    FLAG_CMP((cpu->regs[1]) & (cpu->regs[0]), 0);
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
L_22c0c4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x22c0ccULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x23a1c8ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22c3a4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    PB_STR((SP + 112), cpu->regs[27]);
    if (((cpu->regs[1] >> 25) & 1)) goto L_22c2b0;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    cpu->regs[1] = cpu->regs[1] & 536870912ULL;
    cpu->regs[27] = cpu->regs[19];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_22c608;
    if ((cpu->regs[1])!=0) goto L_22c2ec;
L_22c104:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[5] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x22c120ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe0f0cULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22c138;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22c82c;
L_22c138:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22c14c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22c7d0;
L_22c14c:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22c160;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22c7e4;
L_22c160:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_22c298;
L_22c168:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_22c178;
L_22c170:
    PB_LDR(cpu->regs[27], (SP + 112));
    goto L_22bf74;
L_22c178:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22c170;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22c18cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 112));
    goto L_22bf74;
L_22c194:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c1acULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xea120ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_22bf50;
L_22c1b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_22c39c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 128ULL;
    { PB_CALL(43, cpu, tlb, PB_BASE + 0x23eec8ULL); return; };
L_22c1f4:
    cpu->regs[1] = cpu->regs[19] + 24ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_22c210;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_22c210:
    cpu->regs[1] = cpu->regs[23] + 24ULL;
    PB_STR((cpu->regs[1] + (cpu->regs[0] << 3)), cpu->regs[2]);
    goto L_22c09c;
L_22c21c:
    cpu->regs[1] = 0ULL;
    goto L_22c0c4;
L_22c224:
    cpu->regs[30] = PB_BASE + 0x22c228ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x22c880ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22c248;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22c248;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22c248ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_22c248:
    if ((cpu->regs[19])==0) goto L_22c288;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 26) & 1)) goto L_22c028;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 2064ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x22c274ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x11f220ULL);
L_22c274:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c288;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22c7a4;
L_22c288:
    cpu->regs[20] = 0ULL;
    goto L_22bf74;
L_22c290:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    goto L_22c070;
L_22c298:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22c168;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x22c2acULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c168;
L_22c2b0:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x22c2b8ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22c354;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
L_22c2c4:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_22c2ec;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_22c7dc;
L_22c2e0:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    goto L_22c104;
L_22c2ec:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 47904ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 16), cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x22c308ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22c338;
    cpu->regs[30] = PB_BASE + 0x22c314ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c334;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22c334;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22c334ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_22c334:
    if ((cpu->regs[19])!=0) goto L_22c104;
L_22c338:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c354;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22c354;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x22c354ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_22c354:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c368;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22c7f0;
L_22c368:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c37c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22c7fc;
L_22c37c:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c390;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22c808;
L_22c390:
    PB_LDR(cpu->regs[27], (SP + 112));
L_22c394:
    cpu->regs[20] = 0ULL;
    goto L_22bf74;
L_22c39c:
    PB_STR((SP + 112), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x22c3a4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x7c170ULL);
L_22c3a4:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c3b8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22c63c;
L_22c3b8:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c288;
L_22c3c0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22c288;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c3d8ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22bf74;
L_22c3dc:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 1736ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c3fcULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_22bf74;
L_22c400:
    cpu->regs[30] = PB_BASE + 0x22c404ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x22c880ULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22c424;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22c424;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22c424ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_22c424:
    if ((cpu->regs[23])==0) goto L_22c288;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_22c610;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 16));
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_22c648;
    PB_LDR(cpu->regs[19], (cpu->regs[23] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_22c454;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_22c454:
    PB_LDR(cpu->regs[20], (cpu->regs[23] + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_22c468;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_22c468:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c484;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22c484;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22c484ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_22c484:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_22c6a4;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_22c67c;
    cpu->regs[30] = PB_BASE + 0x22c4a0ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x23a904ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22c854;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    if ((cpu->regs[1])==0) goto L_22c6cc;
    cpu->regs[1] = 31016ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x22c4bcULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[25] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22c4d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22c670;
L_22c4d4:
    if ((cpu->regs[25])==0) goto L_22c5d0;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x22c4ecULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xe0f0cULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22c504;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22c6d8;
L_22c504:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c518;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22c764;
L_22c518:
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[23])!=0) goto L_22c0c4;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c288;
L_22c528:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22c288;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c540ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22bf74;
L_22c544:
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c558ULL; PB_CALL(63, cpu, tlb, cpu->regs[4]);
    cpu->regs[2] = cpu->regs[0];
L_22c55c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c56cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xe8888ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_22bf50;
L_22c574:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 336ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22c58cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_22c58c:
    cpu->regs[30] = PB_BASE + 0x22c590ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_22c288;
    cpu->regs[25] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22c5a8ULL; PB_CALL(67, cpu, tlb, cpu->regs[1]);
    cpu->regs[23] = 4294967295ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + cpu->regs[0]));
    if ((cpu->regs[0])!=0) goto L_22be10;
L_22c5b4:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 3176ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    PB_STR((SP + 112), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x22c5d0ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x91ebcULL);
L_22c5d0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c5e4;
L_22c5d8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22c86c;
L_22c5e4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22c288;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22c288;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c604ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22bf74;
L_22c608:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[2]);
    goto L_22c2c4;
L_22c610:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1768ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22c62cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_22c3c0;
    cpu->regs[20] = 0ULL;
    goto L_22bf74;
L_22c63c:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x22c644ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c3b8;
L_22c648:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 1824ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22c660ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_22c3c0;
    cpu->regs[20] = 0ULL;
    goto L_22bf74;
L_22c670:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x22c678ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c4d4;
L_22c67c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22c698ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_22c5d8;
    goto L_22c5e4;
L_22c6a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1888ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22c6c0ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_22c5d8;
    goto L_22c5e4;
L_22c6cc:
    cpu->regs[23] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[26];
    goto L_22c034;
L_22c6d8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22c6e0ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c504;
L_22c6e4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22c6ecULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22bea4;
L_22c6f0:
    PB_STR((SP + 112), cpu->regs[27]);
    __builtin_trap();
L_22c6f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3488));
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[30] = PB_BASE + 0x22c70cULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x22c714ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] + (88ULL << 12);
    cpu->regs[6] = 31888ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[6];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22c72cULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xe27c8ULL);
    PB_STR((cpu->regs[19] + 22504), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x22c734ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22504));
    if ((cpu->regs[0])==0) goto L_22c794;
L_22c740:
    cpu->regs[7] = 31888ULL;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[7];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x22c754ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_22be48;
    cpu->regs[20] = 0ULL;
    goto L_22bf74;
L_22c764:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22c76cULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c518;
L_22c770:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c78cULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[2] = cpu->regs[0];
    goto L_22c55c;
L_22c794:
    cpu->regs[30] = PB_BASE + 0x22c798ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_22c740;
    cpu->regs[20] = 0ULL;
    goto L_22bf74;
L_22c7a4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c7b0ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22bf74;
L_22c7b4:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 3176ULL;
    cpu->regs[1] = cpu->regs[1] + 3448ULL;
    PB_STR((SP + 112), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x22c7d0ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x91ebcULL);
L_22c7d0:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22c7d8ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c14c;
L_22c7dc:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_22c2e0;
L_22c7e4:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x22c7ecULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c160;
L_22c7f0:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x22c7f8ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c368;
L_22c7fc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22c804ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c37c;
L_22c808:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x22c810ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 112));
    goto L_22c394;
L_22c818:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22c820ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_22c528;
    goto L_22c288;
L_22c82c:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x22c834ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c138;
L_22c838:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c844ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_22bf74;
L_22c848:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22c850ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c064;
L_22c854:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22c85cULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22c868ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_22bf74;
L_22c86c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22c874ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22c5e4;
    /* nop */
    /* nop */
L_22c880:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22c8a0ULL; PB_CALL(100, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    { PB_CALL(101, cpu, tlb, PB_BASE + 0x1bd3e0ULL); return; };
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_22c8e8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3536));
    cpu->regs[30] = PB_BASE + 0x22c8e4ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22c8fc;
L_22c8e8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    { PB_CALL(103, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
L_22c8fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 45784ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x22c910ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x225b60ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 16) + 8);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[4] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[4] + 2120ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    { PB_CALL(105, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
}
