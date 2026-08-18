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

void ft_PyOS_Readline(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 3256));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x9191cULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[26], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[4], (cpu->regs[23] + 0));
    FLAG_CMP(cpu->regs[4], cpu->regs[26]);
    if (FLAG_NE) goto L_9194c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 1144ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x91948ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_919a4;
L_9194c:
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 3480));
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if ((cpu->regs[0])!=0) goto L_91970;
    cpu->regs[0] = PB_BASE + 0x91000ULL;
    cpu->regs[0] = cpu->regs[0] + 1752ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
L_91970:
    cpu->regs[20] = PB_BASE + 0x5ad000ULL;
    cpu->regs[24] = cpu->regs[20] + 4048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 264));
    if ((cpu->regs[0])!=0) goto L_919ac;
    cpu->regs[30] = PB_BASE + 0x91984ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x17aba0ULL);
    PB_STR((cpu->regs[24] + 264), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_919ac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3000));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1504ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x919a4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_919a4:
    cpu->regs[20] = 0ULL;
    goto L_91ab4;
L_919ac:
    cpu->regs[30] = PB_BASE + 0x919b0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[20] + 4048ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 264));
    cpu->regs[30] = PB_BASE + 0x919c4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_STR((cpu->regs[23] + 0), cpu->regs[26]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x919d0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7bf20ULL);
    cpu->regs[30] = PB_BASE + 0x919d4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7bdb0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_919f0;
L_919d8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x919e8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x916d8ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_91a30;
L_919f0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x919f8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7bf20ULL);
    cpu->regs[30] = PB_BASE + 0x919fcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7bdb0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_919d8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_919d8;
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x91a2cULL; PB_CALL(12, cpu, tlb, cpu->regs[3]);
    cpu->regs[19] = cpu->regs[0];
L_91a30:
    cpu->regs[20] = cpu->regs[20] + 4048ULL;
    PB_STR((cpu->regs[23] + 0), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 264));
    cpu->regs[30] = PB_BASE + 0x91a40ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x17faa0ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x91a48ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if ((cpu->regs[19])==0) goto L_919a4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91a54ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[21] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x91a60ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_91aa8;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_LS) goto L_91a80;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[21];
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_HS) goto L_91a94;
    goto L_91a90;
L_91a80:
    if (FLAG_HS) goto L_91a94;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[21];
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HS) goto L_91a94;
L_91a90:
    __builtin_trap();
L_91a94:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x91aa4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c090ULL);
    goto L_91aac;
L_91aa8:
    cpu->regs[30] = PB_BASE + 0x91aacULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x22d780ULL);
L_91aac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91ab4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xd7784ULL);
L_91ab4:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
}
