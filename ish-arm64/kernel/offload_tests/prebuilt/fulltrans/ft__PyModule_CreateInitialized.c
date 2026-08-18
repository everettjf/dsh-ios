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

void ft__PyModule_CreateInitialized(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x18f448ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL);
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 40));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18f458ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18f600ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18f528;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])!=0) goto L_18f50c;
    cpu->regs[20] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x18f478ULL; PB_CALL(3, cpu, tlb, cpu->regs[1]);
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    if ((cpu->regs[22])!=0) goto L_18f4e0;
L_18f484:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18f48cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18f660ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f528;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_18f554;
L_18f4a0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 64));
    if ((cpu->regs[1])==0) goto L_18f4b4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f4b0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18f8a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f530;
L_18f4b4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    if ((cpu->regs[1])==0) goto L_18f4c8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f4c4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18fba0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f530;
L_18f4c8:
    PB_STR((cpu->regs[20] + 24), cpu->regs[19]);
L_18f4cc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_18f4e0:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 46ULL;
    cpu->regs[30] = PB_BASE + 0x18f4ecULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b140ULL);
    if ((cpu->regs[0])==0) goto L_18f484;
    cpu->regs[1] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18f4fcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f484;
    cpu->regs[21] = cpu->regs[22];
    PB_STR((cpu->regs[20] + 8), 0ULL);
    goto L_18f484;
L_18f50c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 3544ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18f528ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
L_18f528:
    cpu->regs[20] = 0ULL;
    goto L_18f4cc;
L_18f530:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18f528;
L_18f538:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18f528;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18f550ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18f4cc;
L_18f554:
    cpu->regs[30] = PB_BASE + 0x18f558ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdbd90ULL);
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18f570;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 56));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18f56cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7aee0ULL);
    goto L_18f4a0;
L_18f570:
    cpu->regs[30] = PB_BASE + 0x18f574ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f538;
    goto L_18f528;
}
