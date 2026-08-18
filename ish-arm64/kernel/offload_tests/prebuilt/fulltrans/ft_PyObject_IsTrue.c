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

void ft_PyObject_IsTrue(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3664));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_122858;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    cpu->regs[4] = 0ULL;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1227dc;
    cpu->regs[0] = cpu->regs[4];
    return;
L_1227dc:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 96));
    if ((cpu->regs[2])==0) goto L_1227f8;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 72));
    if ((cpu->regs[2])!=0) goto L_122834;
L_1227f8:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 112));
    if ((cpu->regs[0])==0) goto L_122864;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_122864;
    cpu->regs[0] = PB_BASE + 0x14b000ULL;
    cpu->regs[0] = cpu->regs[0] + 3808ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_122880;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
L_12281c:
    FLAG_CMP(cpu->regs[4], 0ULL);
    if (FLAG_LE) goto L_122828;
L_122824:
    cpu->regs[4] = 1ULL;
L_122828:
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_122834:
    cpu->regs[3] = PB_BASE + 0x126000ULL;
    cpu->regs[3] = cpu->regs[3] + 1312ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_122890;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    cpu->regs[4] = (FLAG_NE) ? 1 : 0;
    goto L_12281c;
L_122858:
    cpu->regs[4] = 1ULL;
    cpu->regs[0] = cpu->regs[4];
    return;
L_122864:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 104));
    if ((cpu->regs[0])==0) goto L_122824;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_122824;
    /* nop */
    /* nop */
    /* nop */
L_122880:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x122888ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    cpu->regs[4] = cpu->regs[0];
    goto L_12281c;
L_122890:
    cpu->regs[30] = PB_BASE + 0x122894ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    cpu->regs[4] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    goto L_12281c;
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1228ccULL; PB_CALL(3, cpu, tlb, cpu->regs[4]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[1] = 29280ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[1] = cpu->regs[24] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1228f8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe31ccULL);
    if ((cpu->regs[0])==0) goto L_122994;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    if (!((cpu->regs[2] >> 17) & 1)) goto L_1229a4;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_12291c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_12291c:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x122934ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x122b8cULL);
    cpu->regs[20] = cpu->regs[0];
L_122938:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12294c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1229d8;
L_12294c:
    if ((cpu->regs[20])==0) goto L_12299c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_1229e4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_122a28;
L_122968:
    cpu->regs[0] = 0ULL;
L_12296c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_122980:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12298cULL; PB_CALL(6, cpu, tlb, cpu->regs[3]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1229bc;
L_122994:
    cpu->regs[30] = PB_BASE + 0x122998ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_122a40;
L_12299c:
    cpu->regs[0] = 4294967295ULL;
    goto L_12296c;
L_1229a4:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 272));
    if ((cpu->regs[3])!=0) goto L_122980;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1229bc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1229bc:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1229d0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x12660cULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_122938;
L_1229d8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1229e0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12294c;
L_1229e4:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 2000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x122a04ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_12299c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_12299c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x122a20ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_12296c;
L_122a28:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_122968;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x122a3cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_122968;
L_122a40:
    cpu->regs[0] = 29280ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x122a4cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c598ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_12296c;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    cpu->regs[3] = ((uint32_t)(((cpu->regs[2] >> 2) & 0x7ULL)));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[2] >> 5) & 0x1ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_122a90;
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_122adc;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[1]));
L_122a8c:
    return;
L_122a90:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_122ab4;
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_122ae8;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 1)));
L_122ab0:
    return;
L_122ab4:
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_122ad0;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 2)));
L_122acc:
    return;
L_122ad0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 2)));
    goto L_122acc;
L_122adc:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[1]));
    goto L_122a8c;
L_122ae8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 1)));
    goto L_122ab0;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x122b1cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_122b48;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 168));
    if (!((cpu->regs[3] >> 17) & 1)) goto L_122b58;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_122b48;
L_122b44:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_122b48:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_122b58:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 272));
    PB_STRW((cpu->regs[20] + 0), 0ULL);
    if ((cpu->regs[3])!=0) goto L_122b74;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_122b44;
    goto L_122b48;
L_122b74:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
}
