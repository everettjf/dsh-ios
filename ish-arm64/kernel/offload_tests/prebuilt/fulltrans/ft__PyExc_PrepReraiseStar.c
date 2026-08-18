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

void ft__PyExc_PrepReraiseStar(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 112ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 16));
    PB_STR((SP + 96), cpu->regs[25]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    if ((cpu->regs[24])!=0) goto L_c5cc8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c5cbc;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_c5cbc:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    goto L_c5f44;
L_c5cc8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3792));
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xc5cdcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c5cfc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c5f44;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_c5f44;
L_c5cfc:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc5d04ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c5d14;
L_c5d0c:
    cpu->regs[19] = 0ULL;
    goto L_c5f44;
L_c5d14:
    cpu->regs[0] = 0ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc5d20ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c5d34;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    goto L_c5d68;
L_c5d34:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c5d0c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c5d0c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5d50ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c5d0c;
L_c5d54:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + (cpu->regs[23] << 3)));
    FLAG_CMP(cpu->regs[1], cpu->regs[25]);
    if (FLAG_NE) goto L_c5d74;
L_c5d64:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
L_c5d68:
    FLAG_CMP(cpu->regs[23], cpu->regs[24]);
    if (FLAG_LT) goto L_c5d54;
    goto L_c5dc8;
L_c5d74:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_c5db8;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 40));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_c5db8;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 56));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_c5db8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 48));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[21] : cpu->regs[20];
    goto L_c5dbc;
L_c5db8:
    cpu->regs[0] = cpu->regs[20];
L_c5dbc:
    cpu->regs[30] = PB_BASE + 0xc5dc0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe548cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c5d64;
    goto L_c5e9c;
L_c5dc8:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc5dd0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c5e9c;
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 16));
    cpu->regs[23] = 0ULL;
L_c5de0:
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_LE) goto L_c5e24;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[23] << 3)));
    cpu->regs[30] = PB_BASE + 0xc5df8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xc5b3cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c5e1c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c5e9c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c5e9c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5e18ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c5e9c;
L_c5e1c:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    goto L_c5de0;
L_c5e24:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 2ULL;
    cpu->regs[4] = SP + 8ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc5e3cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xb9b0cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_c5e5c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c5e5c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5e5cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c5e5c:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c5e9c;
    PB_LDR(cpu->regs[19], (SP + 8));
    if ((cpu->regs[19])!=0) goto L_c5e8c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c5e84;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_c5e84:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_c5e8c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if ((cpu->regs[0])==0) goto L_c5ea0;
    if (FLAG_GT) goto L_c5eb4;
L_c5e9c:
    cpu->regs[19] = 0ULL;
L_c5ea0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5ea8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc5eb0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_c5f44;
L_c5eb4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_c5ed8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5ed0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe548cULL);
    cpu->regs[22] = cpu->regs[0];
    goto L_c5edc;
L_c5ed8:
    cpu->regs[22] = 0ULL;
L_c5edc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c5ef8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c5ef8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5ef8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c5ef8:
    if (((cpu->regs[22] >> 31) & 1)) goto L_c5e9c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_LE) goto L_c5f20;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    cpu->regs[30] = PB_BASE + 0xc5f18ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xa6694ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_c5ea0;
L_c5f20:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc5f2cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1c4a00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c5ea0;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_c5ea0;
L_c5f44:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_c5f64;
    cpu->regs[30] = PB_BASE + 0xc5f64ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c5f64:
    PB_LDR(cpu->regs[25], (SP + 96));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
}
