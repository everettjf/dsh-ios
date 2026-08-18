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

void ft_PyErr_Restore(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1e68e0ULL; PB_CALL(1, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[5] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[5];
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x121b40ULL); return; };
    /* nop */
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[5] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[4]));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1e6924;
    cpu->regs[2] = cpu->regs[2] - cpu->regs[0];
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x7bdd0ULL); return; };
L_1e6920:
    cpu->regs[0] = cpu->regs[0] + cpu->regs[5];
L_1e6924:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1e6940;
L_1e692c:
    PB_LDRH(cpu->regs[3], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_HS) goto L_1e6954;
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    goto L_1e692c;
L_1e6940:
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_HS) goto L_1e6954;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[5];
    goto L_1e6940;
L_1e6954:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_NE) goto L_1e6960;
    return;
L_1e6960:
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_1e6920;
    cpu->regs[0] = 0ULL;
    return;
    SP = SP - 96ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    PB_STR((SP + 80), cpu->regs[21]);
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1e6b4c;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20));
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1e6ac4;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e69b8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1e6ba0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e6adc;
    cpu->regs[30] = PB_BASE + 0x1e69c4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1e6b80;
L_1e69d0:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1e6adc;
    if (FLAG_NE) goto L_1e6ab4;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e6a70;
L_1e69ec:
    cpu->regs[4] = 44840ULL;
    cpu->regs[21] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20] + cpu->regs[4];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 8), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1e6a0cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1e6ae4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1e6b6c;
L_1e6a18:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 39328ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1e6a38ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[19] = cpu->regs[0];
L_1e6a3c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e6ac0;
    PB_LDR(cpu->regs[21], (SP + 80));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_1e6a70:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[5] = 34928ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[5];
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 16), cpu->regs[4]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1e6a94ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1e6b44;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1e69ec;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1e69ec;
    cpu->regs[30] = PB_BASE + 0x1e6ab0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e69ec;
L_1e6ab4:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    goto L_1e6a3c;
L_1e6ac0:
    cpu->regs[30] = PB_BASE + 0x1e6ac4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e6ac4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e6adcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1e6adc:
    cpu->regs[19] = 0ULL;
    goto L_1e6a3c;
L_1e6ae4:
    cpu->regs[30] = PB_BASE + 0x1e6ae8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[2] = 39328ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20] + cpu->regs[2];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1e6b0cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[21])==0) goto L_1e6a3c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e6b1cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
    if ((cpu->regs[19])==0) goto L_1e6adc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e6adc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1e6adc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e6b40ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e6a3c;
L_1e6b44:
    cpu->regs[30] = PB_BASE + 0x1e6b48ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1e69ec;
L_1e6b4c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e6b68ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1e6a3c;
L_1e6b6c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e6a18;
    cpu->regs[30] = PB_BASE + 0x1e6b7cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e6a18;
L_1e6b80:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e69d0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e6b94ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e69d0;
    /* nop */
    /* nop */
L_1e6ba0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1e6bfc;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1e6bd8;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[2] = 39376ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    { PB_CALL(20, cpu, tlb, PB_BASE + 0xed3ccULL); return; };
L_1e6bd8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e6bf0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1e6bf0:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1e6bfc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e6c14ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1e6bf0;
    /* nop */
    /* nop */
}
