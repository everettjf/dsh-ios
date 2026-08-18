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

void ft_PyDict_Values(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[19])==0) goto L_a09c8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_a09f4;
L_a09c8:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 3129ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0xa09d8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[11] = 0ULL;
    goto L_a0a68;
L_a09e0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_EQ) goto L_a0a20;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_a0a0c;
L_a09f4:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa0a00ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[11] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a09e0;
    goto L_a0a68;
L_a0a0c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a09f4;
    cpu->regs[30] = PB_BASE + 0xa0a1cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a09f4;
L_a0a20:
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[12] = 0ULL;
    PB_STR((SP + 8), 0ULL);
L_a0a30:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa0a40ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a0a68;
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a0a58;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_a0a58:
    PB_LDR(cpu->regs[0], (cpu->regs[11] + 24));
    PB_STR((cpu->regs[0] + cpu->regs[12]), cpu->regs[2]);
    cpu->regs[12] = cpu->regs[12] + 8ULL;
    goto L_a0a30;
L_a0a68:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a0a88;
    cpu->regs[30] = PB_BASE + 0xa0a88ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a0a88:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[11];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 160ULL;
    cpu->regs[2] = cpu->tls_ptr;
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa0abcULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 72), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = 72ULL;
    cpu->regs[0] = SP;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[30] = PB_BASE + 0xa0af8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa0b00ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    if ((cpu->regs[0])==0) goto L_a0bb4;
    cpu->regs[26] = PB_BASE + 0x286000ULL;
    cpu->regs[25] = PB_BASE + 0x286000ULL;
    cpu->regs[24] = PB_BASE + 0x2a3000ULL;
    cpu->regs[23] = PB_BASE + 0x2a3000ULL;
    cpu->regs[20] = SP;
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[26] = cpu->regs[26] + 2296ULL;
    cpu->regs[25] = cpu->regs[25] + 2312ULL;
    cpu->regs[24] = cpu->regs[24] + 1776ULL;
    cpu->regs[23] = cpu->regs[23] + 1792ULL;
    cpu->regs[22] = 3ULL;
L_a0b30:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0)); PB_LDR(cpu->regs[4], (cpu->regs[20] + 0) + 8);
    cpu->regs[5] = cpu->regs[26];
    PB_LDR(cpu->regs[6], (cpu->regs[20] + 16));
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xa0b4cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a0bac;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa0b60ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a0b84;
    if (((cpu->regs[2] >> 31) & 1)) goto L_a0bac;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_a0bac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0b80ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a0bac;
L_a0b84:
    if (((cpu->regs[2] >> 31) & 1)) goto L_a0b9c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_a0b9c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa0b9cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a0b9c:
    cpu->regs[20] = cpu->regs[20] + 24ULL;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] - 1ULL)); FLAG_CMP(cpu->regs[22], 0);
    if (FLAG_NE) goto L_a0b30;
    goto L_a0bb8;
L_a0bac:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa0bb4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
L_a0bb4:
    cpu->regs[21] = 0ULL;
L_a0bb8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a0bd8;
    cpu->regs[30] = PB_BASE + 0xa0bd8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a0bd8:
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
}
