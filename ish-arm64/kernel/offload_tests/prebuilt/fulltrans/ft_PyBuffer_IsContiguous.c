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

void ft_PyBuffer_IsContiguous(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 64));
    if ((cpu->regs[3])!=0) goto L_14ce40;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 255ULL));
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(67ULL)));
    if (FLAG_NE) goto L_14ce34;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_14cdec;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 56));
    if ((cpu->regs[0])!=0) goto L_14cdf4;
L_14cdec:
    cpu->regs[0] = 1ULL;
    return;
L_14cdf4:
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 36));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 24));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[3] = (((uint64_t)(((int64_t)(cpu->regs[1] << 32)) >> 32) & 0xffffffffULL) << 3);
L_14ce04:
    if (((cpu->regs[1] >> 31) & 1)) goto L_14cdec;
    PB_LDR(cpu->regs[5], (cpu->regs[2] + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[5], (cpu->regs[5] + cpu->regs[3]));
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_LE) goto L_14ce28;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + cpu->regs[3]));
    FLAG_CMP(cpu->regs[6], cpu->regs[4]);
    if (FLAG_NE) goto L_14ce40;
L_14ce28:
    cpu->regs[4] = cpu->regs[4] * cpu->regs[5];
    cpu->regs[3] = cpu->regs[3] - 8ULL;
    goto L_14ce04;
L_14ce34:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(70ULL)));
    if (FLAG_NE) goto L_14ce48;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x22fcc8ULL); return; };
L_14ce40:
    cpu->regs[0] = 0ULL;
    return;
L_14ce48:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(65ULL)));
    if (FLAG_NE) goto L_14ce40;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_14cdec;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 56));
    cpu->regs[0] = 1ULL;
    if ((cpu->regs[4])!=0) goto L_14ce68;
    return;
L_14ce68:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 36));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[1] = (((uint64_t)(((int64_t)(cpu->regs[0] << 32)) >> 32) & 0xffffffffULL) << 3);
L_14ce78:
    if (((cpu->regs[0] >> 31) & 1)) goto L_14cdec;
    PB_LDR(cpu->regs[5], (cpu->regs[2] + 48));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[5], (cpu->regs[5] + cpu->regs[1]));
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_LE) goto L_14ce9c;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + cpu->regs[1]));
    FLAG_CMP(cpu->regs[6], cpu->regs[3]);
    if (FLAG_NE) goto L_14cea8;
L_14ce9c:
    cpu->regs[3] = cpu->regs[3] * cpu->regs[5];
    cpu->regs[1] = cpu->regs[1] - 8ULL;
    goto L_14ce78;
L_14cea8:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x14ceb8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x22fcc8ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_14cf18;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_14cef8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_14d004;
L_14ceec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    return;
L_14cef8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_14d008;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    return;
L_14cf18:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_14cfb0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 200));
    if ((cpu->regs[3])==0) goto L_14cfb0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 2ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x14cf40ULL; PB_CALL(3, cpu, tlb, cpu->regs[3]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14cfec;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_14cf9c;
    cpu->regs[30] = PB_BASE + 0x14cf5cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_14d010;
L_14cf68:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_14cfec;
    if (FLAG_EQ) goto L_14cfcc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_14cff4;
L_14cf88:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_14cf90:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_14cf9c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_14cfb0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14ceec;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_14ceec;
L_14cfcc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_14cffc;
L_14cfe0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_14cf90;
L_14cfec:
    cpu->regs[0] = 0ULL;
    goto L_14cf90;
L_14cff4:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_14cf88;
L_14cffc:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_14cfe0;
L_14d004:
    cpu->regs[0] = cpu->regs[1];
L_14d008:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
    return;
L_14d010:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_14cf68;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14d024ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_14cf68;
}
