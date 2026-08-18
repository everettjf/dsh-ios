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

void ft_PyObject_GenericSetDict(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x81d20ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x26beccULL);
    if ((cpu->regs[0])!=0) goto L_81d5c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 4) & 1)) goto L_81d40;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + -24));
    if (!((cpu->regs[0] >> 0) & 1)) goto L_81d40;
    cpu->regs[30] = PB_BASE + 0x81d3cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_81d78;
L_81d40:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 3024ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x81d58ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_81d78;
L_81d5c:
    if ((cpu->regs[19])!=0) goto L_81d80;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 1752ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x81d78ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_81d78:
    cpu->regs[0] = 4294967295ULL;
    goto L_81dd0;
L_81d80:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_81db0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1776ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x81dacULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_81d78;
L_81db0:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_81dc4;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[2]);
L_81dc4:
    PB_STR((cpu->regs[1] + 0), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x81dccULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18fb80ULL);
    cpu->regs[0] = 0ULL;
L_81dd0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    if ((cpu->regs[0])==0) goto L_81e10;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_81e10;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_81e10;
    cpu->regs[30] = PB_BASE + 0x81e10ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_81e10:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2680));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 192));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 2160ULL;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0x26cac0ULL); return; };
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 2176ULL;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0x26cac0ULL); return; };
    cpu->regs[1] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x81e64ULL; PB_CALL(10, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[2] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[2] + 2208ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    cpu->regs[3] = cpu->regs[3] + 112ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[3] + 40));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 64));
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 88));
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[1])==0) goto L_81ea8;
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_81ec8;
L_81ea8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 2936ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x81ec0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_81ee8;
L_81ec8:
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 24));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_81edc;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[3]);
L_81edc:
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x81ee4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
L_81ee8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[1])==0) goto L_81f0c;
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_81f2c;
L_81f0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 2976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x81f24ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_81f4c;
L_81f2c:
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 32));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_81f40;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[3]);
L_81f40:
    PB_STR((cpu->regs[2] + 32), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x81f48ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
L_81f4c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x81f68ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x81f78ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x81f88ULL);
    PB_STRW((cpu->regs[19] + 0), cpu->regs[20]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_81f88:
    SP = SP - 64ULL;
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] + 29ULL;
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[1] = cpu->regs[19] + (cpu->regs[1] << 4);
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19] + 1512ULL;
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 48));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x81fe8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x8206cULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 1504));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_82038;
    cpu->regs[1] = SP + 7ULL;
    cpu->regs[2] = 1ULL;
    PB_STRB((SP + 7), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x82004ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x90ba8ULL);
    if (!((cpu->regs[0] >> 63) & 1)) goto L_82038;
    cpu->regs[30] = PB_BASE + 0x8200cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[19], (cpu->regs[19] + 1508));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_82020;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(11ULL)));
    if (FLAG_EQ) goto L_82038;
L_82020:
    cpu->regs[1] = PB_BASE + 0xac000ULL;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 3148ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x82038ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x95b5cULL);
L_82038:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_82058;
    cpu->regs[30] = PB_BASE + 0x82058ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_82058:
    PB_LDR(cpu->regs[21], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
}
