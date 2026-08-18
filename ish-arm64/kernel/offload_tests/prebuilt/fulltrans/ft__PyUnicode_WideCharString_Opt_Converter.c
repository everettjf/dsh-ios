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

void ft__PyUnicode_WideCharString_Opt_Converter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    if ((cpu->regs[0])!=0) goto L_9cb20;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x9cb18ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((cpu->regs[19] + 0), 0ULL);
    goto L_9cb34;
L_9cb20:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_9cb3c;
    PB_STR((cpu->regs[19] + 0), 0ULL);
L_9cb34:
    cpu->regs[0] = 1ULL;
    goto L_9cb84;
L_9cb3c:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_9cb64;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9cb50ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] << 17));
    goto L_9cb84;
L_9cb64:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9cb80ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
L_9cb84:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + 3600ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP;
    cpu->regs[30] = PB_BASE + 0x9cbc8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9cbd4;
L_9cbcc:
    cpu->regs[19] = 0ULL;
    goto L_9cc14;
L_9cbd4:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9cbe0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    if ((cpu->regs[0])==0) goto L_9cbcc;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(47ULL)));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x9cc04ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9cc14;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9cc14:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9cc34;
    cpu->regs[30] = PB_BASE + 0x9cc34ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9cc34:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32));
    SP = SP + 48ULL;
    return;
    SP = SP - 192ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_STR((SP + 160), cpu->regs[29]); PB_STR((SP + 160) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 160ULL;
    cpu->regs[1] = cpu->regs[1] + 3600ULL;
    PB_STR((SP + 176), cpu->regs[19]); PB_STR((SP + 176) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 152), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x9cc80ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9cc8c;
L_9cc84:
    cpu->regs[19] = 0ULL;
    goto L_9ccfc;
L_9cc8c:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x9cc98ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9cc84;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0x9cca8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1b5420ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9ccdc;
    PB_LDRW(cpu->regs[1], (SP + 40));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] & 61440ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32768ULL)));
    if (FLAG_NE) goto L_9ccdc;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3664));
    cpu->regs[2] = 73ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(cpu->regs[2]))), 0);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[0];
    goto L_9cce4;
L_9ccdc:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3184));
L_9cce4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9ccecULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9ccfc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9ccfc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 152));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9cd1c;
    cpu->regs[30] = PB_BASE + 0x9cd1cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9cd1c:
    PB_LDR(cpu->regs[29], (SP + 160)); PB_LDR(cpu->regs[30], (SP + 160) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 176)); PB_LDR(cpu->regs[20], (SP + 176) + 8);
    SP = SP + 192ULL;
    return;
    SP = SP - 176ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_STR((SP + 144), cpu->regs[29]); PB_STR((SP + 144) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 144ULL;
    cpu->regs[1] = cpu->regs[1] + 3600ULL;
    PB_STR((SP + 160), cpu->regs[19]); PB_STR((SP + 160) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 136), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP;
    cpu->regs[30] = PB_BASE + 0x9cd68ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9cd74;
L_9cd6c:
    cpu->regs[19] = 0ULL;
    goto L_9cdd8;
L_9cd74:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9cd80ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9cd6c;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x9cd90ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1b5420ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9cdb8;
    PB_LDRW(cpu->regs[1], (SP + 24));
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3664));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 61440ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16384ULL)));
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[0];
    goto L_9cdc0;
L_9cdb8:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3184));
L_9cdc0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9cdc8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9cdd8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9cdd8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 136));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9cdf8;
    cpu->regs[30] = PB_BASE + 0x9cdf8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9cdf8:
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 160)); PB_LDR(cpu->regs[20], (SP + 160) + 8);
    SP = SP + 176ULL;
    return;
    SP = SP - 96ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    cpu->regs[1] = cpu->regs[1] + 1200ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 32ULL;
    cpu->regs[3] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0x9ce4cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9ce58;
L_9ce50:
    cpu->regs[19] = 0ULL;
    goto L_9cf00;
L_9ce58:
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x9ce64ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9ce50;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x9ce78ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9cef8;
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[0], (SP + 8) + 8);
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_9cea8;
L_9ce8c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9cec0;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_9cec0;
L_9cea8:
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20] + (cpu->regs[0] << 2);
    cpu->regs[30] = PB_BASE + 0x9ceb8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7b720ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9ce8c;
    goto L_9cecc;
L_9cec0:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3184));
    goto L_9ceec;
L_9cecc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9cee4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_9cee4:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3664));
L_9ceec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9cef8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_9cef8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9cf00ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_9cf00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9cf20;
    cpu->regs[30] = PB_BASE + 0x9cf20ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9cf20:
    PB_LDR(cpu->regs[21], (SP + 80));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_9cf88;
L_9cf54:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_9cfa8;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 1208ULL;
    cpu->regs[30] = PB_BASE + 0x9cf84ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_9cfd8;
L_9cf88:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1208ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x9cfa0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9cf54;
    goto L_9cfd8;
L_9cfa8:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_9cfe0;
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2872ULL;
    cpu->regs[0] = cpu->regs[0] + 1208ULL;
    cpu->regs[30] = PB_BASE + 0x9cfd8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x23b310ULL);
L_9cfd8:
    cpu->regs[20] = 0ULL;
    goto L_9d038;
L_9cfe0:
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9cfe8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9cfd8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9cffcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9d020;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9d010ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7afe0ULL);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x9d018ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_9d024;
L_9d020:
    cpu->regs[20] = 0ULL;
L_9d024:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9d02cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    if ((cpu->regs[19])==0) goto L_9d038;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d038ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_9d038:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[4];
    FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9d084;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x9d07cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7b8b0ULL);
    cpu->regs[1] = cpu->regs[0];
    goto L_9d0a0;
L_9d084:
    cpu->regs[1] = 0ULL;
L_9d088:
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_GE) goto L_9d0a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + (cpu->regs[1] << 2)));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9d0a0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_9d088;
L_9d0a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d0a8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9d0ec;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[3] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x9d0c8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x120528ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_9d0f0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9d0f0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d0e8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9d0f0;
L_9d0ec:
    cpu->regs[20] = 4294967295ULL;
L_9d0f0:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    if ((cpu->regs[2])!=0) goto L_9d12c;
L_9d11c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_9d144;
    goto L_9d15c;
L_9d12c:
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + 712ULL;
    cpu->regs[30] = PB_BASE + 0x9d13cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9d11c;
    goto L_9d170;
L_9d144:
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 712ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x9d158ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9d170;
L_9d15c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(40, cpu, tlb, PB_BASE + 0x275fc0ULL); return; };
L_9d170:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[4];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = ((uint32_t)(cpu->regs[2] & 255ULL));
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x9d1b8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[27] = cpu->regs[0] + 24ULL;
    cpu->regs[28] = 0ULL;
L_9d1c4:
    FLAG_CMP(cpu->regs[28], cpu->regs[22]);
    if (FLAG_GE) goto L_9d224;
    cpu->regs[30] = PB_BASE + 0x9d1d0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9d1e4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe41e0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x9d1f0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x121f40ULL);
    if ((cpu->regs[19])==0) goto L_9d21c;
    if ((cpu->regs[21])==0) goto L_9d200;
    PB_STR((cpu->regs[27] + (cpu->regs[28] << 3)), cpu->regs[19]);
    goto L_9d21c;
L_9d200:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_9d21c;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9d21c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d21cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9d21c:
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    goto L_9d1c4;
L_9d224:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9d22cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[25])));
    if (FLAG_EQ) goto L_9d26c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[1] + 184ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    { PB_CALL(47, cpu, tlb, PB_BASE + 0x1d5940ULL); return; };
L_9d26c:
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_9d278;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
L_9d278:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
}
