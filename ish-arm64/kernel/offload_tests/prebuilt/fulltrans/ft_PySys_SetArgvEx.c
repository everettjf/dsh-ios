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

void ft_PySys_SetArgvEx(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 128ULL;
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    PB_STR((SP + 112), cpu->regs[25]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb1430ULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    cpu->regs[4] = PB_BASE + 0x2b4000ULL;
    cpu->regs[4] = cpu->regs[4] + 480ULL;
    PB_STR((SP + 32), cpu->regs[4]);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[24], (cpu->regs[3] + cpu->regs[0]));
    if (FLAG_GT) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_b1458;
    cpu->regs[22] = SP + 32ULL;
    cpu->regs[20] = 1ULL;
    goto L_b145c;
L_b1458:
    cpu->regs[22] = cpu->regs[1];
L_b145c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1464ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1620;
    cpu->regs[21] = 0ULL;
L_b1470:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[21] << 3)));
    cpu->regs[25] = ((cpu->regs[21] & 0xffffffffULL) << 3);
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0xb1480ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1934e0ULL);
    if ((cpu->regs[0])!=0) goto L_b14a4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b1620;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b1620;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb14a0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b1620;
L_b14a4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    PB_STR((cpu->regs[1] + cpu->regs[25]), cpu->regs[0]);
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_GT) goto L_b1470;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 16));
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[0] + 3880ULL;
    cpu->regs[30] = PB_BASE + 0xb14c8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xde9e0ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xb14dcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d74b0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xb14ecULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[21])))==0) goto L_b1524;
    if (((cpu->regs[3] >> 31) & 1)) goto L_b150c;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_b150c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb150cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b150c:
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 1504ULL;
    cpu->regs[1] = cpu->regs[1] + 3272ULL;
    cpu->regs[30] = PB_BASE + 0xb1524ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x91ebcULL);
L_b1524:
    if (((cpu->regs[3] >> 31) & 1)) goto L_b153c;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_b153c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb153cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b153c:
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_b1638;
    cpu->regs[1] = SP;
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), 0ULL);
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0xb1554ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d90e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b1638;
    PB_LDR(cpu->regs[19], (SP + 0));
    if ((cpu->regs[19])!=0) goto L_b1578;
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 1504ULL;
    cpu->regs[1] = cpu->regs[1] + 3296ULL;
    cpu->regs[30] = PB_BASE + 0xb1578ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x91ebcULL);
L_b1578:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = 53360ULL;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xb1590ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b15b0;
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 1504ULL;
    cpu->regs[1] = cpu->regs[1] + 3328ULL;
    cpu->regs[30] = PB_BASE + 0xb15b0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x91ebcULL);
L_b15b0:
    PB_LDR(cpu->regs[20], (SP + 8));
    if ((cpu->regs[20])==0) goto L_b1600;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb15c8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1c65a8ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_b15e4;
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 1504ULL;
    cpu->regs[1] = cpu->regs[1] + 3352ULL;
    cpu->regs[30] = PB_BASE + 0xb15e4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x91ebcULL);
L_b15e4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b1600;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b1600;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1600ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b1600:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b1638;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b1638;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb161cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b1638;
L_b1620:
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 1504ULL;
    cpu->regs[1] = cpu->regs[1] + 3384ULL;
    cpu->regs[30] = PB_BASE + 0xb1638ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x91ebcULL);
L_b1638:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_b1658;
    cpu->regs[30] = PB_BASE + 0xb1658ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b1658:
    PB_LDR(cpu->regs[25], (SP + 112));
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
}
