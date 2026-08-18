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

void ft_PyType_GenericAlloc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xde83cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xde8a0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_de88c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (!((cpu->regs[0] >> 14) & 1)) goto L_de88c;
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xde860ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
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
L_de88c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
L_de8a0:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32)); PB_LDR(cpu->regs[19], (cpu->regs[0] + 32) + 8);
    FLAG_CMP((cpu->regs[3]) & (24ULL), 0);
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    cpu->regs[3] = ((cpu->regs[3] >> 14) & 0x1ULL);
    cpu->regs[1] = ((cpu->regs[1] & 0x1ULL) << 1);
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[3] << 1);
    cpu->regs[19] = cpu->regs[21] * cpu->regs[19] + cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 7ULL;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] & 18446744073709551608ULL;
    cpu->regs[1] = cpu->regs[19] + (cpu->regs[3] << 3); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_LT) goto L_de9b8;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2248));
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[3] << 3;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 176)); PB_LDR(cpu->regs[2], (cpu->regs[25] + 176) + 8);
    cpu->regs[30] = PB_BASE + 0xde908ULL; PB_CALL(3, cpu, tlb, cpu->regs[2]);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_de9b0;
    cpu->regs[23] = cpu->regs[0] + cpu->regs[24];
    if ((cpu->regs[24])==0) goto L_de988;
    PB_STR((cpu->regs[0] + 0), 0ULL); PB_STR((cpu->regs[0] + 0) + 8, 0ULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xde924ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd9340ULL);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xde934ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7aee0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    if ((cpu->regs[0])!=0) goto L_de99c;
L_de93c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    PB_STR((cpu->regs[23] + 8), cpu->regs[20]);
    if (((cpu->regs[0] >> 9) & 1)) goto L_de974;
L_de948:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 2708));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_de9c8;
L_de950:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[22] + cpu->regs[24]), cpu->regs[0]);
L_de958:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_de974:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_de948;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_de948;
L_de988:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xde994ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7aee0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    if ((cpu->regs[0])==0) goto L_de93c;
L_de99c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xde9a8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xd93e0ULL);
    PB_STR((cpu->regs[23] + 16), cpu->regs[21]);
    goto L_de958;
L_de9b0:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64));
L_de9b8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_de9c8:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xde9d0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x98264ULL);
    goto L_de950;
    /* nop */
    /* nop */
    /* nop */
}
