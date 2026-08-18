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

void ft_PyList_AsTuple(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((cpu->regs[0])==0) goto L_dc758;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 25) & 1)) goto L_dc758;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 16) + 8);
    goto L_dc780;
L_dc758:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 2560ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[29] = SP;
    cpu->regs[0] = cpu->regs[0] + 224ULL;
    cpu->regs[30] = PB_BASE + 0xdc770ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
L_dc780:
    if ((cpu->regs[1])==0) goto L_dc87c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xdc7a0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdc8acULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_dc858;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_dc818;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_dc868;
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_dc818;
L_dc7cc:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_dc7e0;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_dc7e0:
    PB_STR((cpu->regs[2] + 32), cpu->regs[1]);
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_dc818;
    cpu->regs[4] = cpu->regs[2] + 24ULL;
    cpu->regs[1] = 2ULL;
L_dc7f4:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_dc808;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
L_dc808:
    PB_STR((cpu->regs[4] + (cpu->regs[1] << 3)), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_NE) goto L_dc7f4;
L_dc818:
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xdc82cULL; PB_CALL(3, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    cpu->regs[3] = cpu->regs[2] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[5];
    PB_STR((cpu->regs[5] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[2] + -16), cpu->regs[4]); PB_STR((cpu->regs[2] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[4] + 8), cpu->regs[3]);
L_dc858:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_dc868:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_dc7cc;
    goto L_dc818;
L_dc87c:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[2] + (16ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 10000));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_dc8a4;
L_dc894:
    cpu->regs[2] = cpu->regs[2] + (18ULL << 12);
    cpu->regs[2] = cpu->regs[2] + 1808ULL;
    cpu->regs[0] = cpu->regs[2];
    return;
L_dc8a4:
    PB_STRW((cpu->regs[1] + 10000), cpu->regs[0]);
    goto L_dc894;
L_dc8ac:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if (((cpu->regs[0] >> 63) & 1)) goto L_dc958;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xdc8d0ULL; PB_CALL(4, cpu, tlb, cpu->regs[3]);
    FLAG_CMP(cpu->regs[1], 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 20ULL); } else { FLAG_CMP(0, 1); }
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    if (FLAG_GT) goto L_dc944;
    cpu->regs[2] = cpu->regs[4] + (((cpu->regs[1]) & 0xffffffffULL) << 3);
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[2] + (64ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 7680));
    if ((cpu->regs[0])==0) goto L_dc934;
    cpu->regs[1] = cpu->regs[4] + (cpu->regs[3] << 2);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = cpu->regs[1] + (64ULL << 12);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 24));
    PB_STR((cpu->regs[2] + 7680), cpu->regs[4]);
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 2708));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 7844));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[1] + 7844), cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_dc970;
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
L_dc92c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_dc934:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    { PB_CALL(5, cpu, tlb, PB_BASE + 0xdc988ULL); return; };
L_dc944:
    cpu->regs[0] = 1152921504606846972ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_dc934;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_dc958:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 36ULL;
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[30] = PB_BASE + 0xdc968ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_dc92c;
L_dc970:
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xdc978ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_dc92c;
}
