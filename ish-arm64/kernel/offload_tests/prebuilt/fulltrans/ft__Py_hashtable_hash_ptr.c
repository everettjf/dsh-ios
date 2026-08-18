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

void ft__Py_hashtable_hash_ptr(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = ror64(cpu->regs[0], 4);
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = 2147483647ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_1c1b98;
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c1b7cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1445c4ULL);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x144720ULL); return; };
L_1c1b98:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 12));
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[2] + 8), cpu->regs[1]); PB_STRW((cpu->regs[2] + 8) + 4, cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    if ((cpu->regs[2])==0) goto L_1c1c60;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    if ((cpu->regs[3])!=0) goto L_1c1c88;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[4] = 16777216ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 40));
    cpu->regs[3] = 9223372036854775807ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2] - cpu->regs[5];
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    cpu->regs[20] = cpu->regs[0] + 1024ULL;
    cpu->regs[4] = (uint64_t)((int64_t)cpu->regs[0] >> 3);
    cpu->regs[2] = cpu->regs[3] - cpu->regs[0];
    cpu->regs[20] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[4];
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    cpu->regs[20] = (FLAG_GE) ? cpu->regs[20] : cpu->regs[1];
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_LT) goto L_1c1c7c;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19] + 16ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1c30ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x13e868ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1c68;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]);
    cpu->regs[2] = cpu->regs[1] + cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[20];
    PB_STR((cpu->regs[19] + 24), cpu->regs[2]); PB_STR((cpu->regs[19] + 24) + 8, cpu->regs[1]);
    PB_LDR(cpu->regs[21], (SP + 32));
L_1c1c54:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1c1c60:
    cpu->regs[0] = 0ULL;
    return;
L_1c1c68:
    PB_STR((cpu->regs[19] + 24), 0ULL); PB_STR((cpu->regs[19] + 24) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 40), 0ULL);
L_1c1c70:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    goto L_1c1c54;
L_1c1c7c:
    cpu->regs[0] = 3ULL;
    PB_STRW((cpu->regs[19] + 8), cpu->regs[0]);
    goto L_1c1c70;
L_1c1c88:
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1c1c90ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x87760ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 24) + 8);
    PB_LDR(cpu->regs[1], (SP + 56));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    cpu->regs[0] = (FLAG_GE) ? 1 : 0;
    goto L_1c1c54;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    if ((cpu->regs[0])==0) goto L_1c1cd8;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1c1cd4ULL; PB_CALL(5, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1cd8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_1c1cec;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1ce8ULL; PB_CALL(6, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1cec:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_1c1d00;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1cfcULL; PB_CALL(7, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1d00:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_1c1d14;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1d10ULL; PB_CALL(8, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1d14:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    if ((cpu->regs[0])==0) goto L_1c1d28;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1d24ULL; PB_CALL(9, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1d28:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    if ((cpu->regs[0])==0) goto L_1c1d3c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1d38ULL; PB_CALL(10, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1d3c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 56));
    if ((cpu->regs[0])==0) goto L_1c1d50;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1d4cULL; PB_CALL(11, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1d50:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 64));
    if ((cpu->regs[0])==0) goto L_1c1d64;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1d60ULL; PB_CALL(12, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1d64:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 72));
    if ((cpu->regs[0])==0) goto L_1c1d78;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1d74ULL; PB_CALL(13, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1d78:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 80));
    if ((cpu->regs[0])==0) goto L_1c1d8c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1d88ULL; PB_CALL(14, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1d8c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 88));
    if ((cpu->regs[0])==0) goto L_1c1da0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1d9cULL; PB_CALL(15, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1da0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    if ((cpu->regs[0])==0) goto L_1c1db4;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1db0ULL; PB_CALL(16, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1db4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 104));
    if ((cpu->regs[0])==0) goto L_1c1dc8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1dc4ULL; PB_CALL(17, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1dc8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 112));
    if ((cpu->regs[0])==0) goto L_1c1ddc;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c1dd8ULL; PB_CALL(18, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1dfc;
L_1c1ddc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 120));
    if ((cpu->regs[0])==0) goto L_1c1dfc;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1c1dfc:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1c1e1cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x141d48ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_1c1e28;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(20, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_1c1e28:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    /* nop */
    /* nop */
    { PB_CALL(21, cpu, tlb, PB_BASE + 0xdce4cULL); return; };
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_1c1ef8;
    if ((cpu->regs[2])!=0) goto L_1c1f1c;
L_1c1e70:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    if ((cpu->regs[1])==0) goto L_1c1f80;
    cpu->regs[20] = cpu->regs[1] - 1ULL;
L_1c1e7c:
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_HS) goto L_1c1fc4;
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 24));
    cpu->regs[24] = cpu->regs[20] << 3;
    cpu->regs[19] = cpu->regs[1] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    PB_LDR(cpu->regs[23], (cpu->regs[22] + cpu->regs[24]));
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[22] + (cpu->regs[20] << 3);
    if (FLAG_EQ) goto L_1c1ed8;
    cpu->regs[20] = cpu->regs[19] - cpu->regs[20];
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_GT) goto L_1c1f58;
L_1c1eac:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c1eb8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe5550ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c1fa0;
    PB_LDR(cpu->regs[25], (SP + 64));
L_1c1ec0:
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1c1ed8:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1c1ee8;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_1c1ee8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c1ef0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x129f00ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1c1ec0;
L_1c1ef8:
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3608ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c1f10ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c1f98;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_1c1e70;
L_1c1f1c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x1c1f24ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c1f70;
    cpu->regs[30] = PB_BASE + 0x1c1f30ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1c1fe4;
L_1c1f3c:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c1f70;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    if ((cpu->regs[1])==0) goto L_1c1f80;
    if (!((cpu->regs[20] >> 63) & 1)) goto L_1c1e7c;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[1];
    goto L_1c1e7c;
L_1c1f58:
    cpu->regs[1] = cpu->regs[24] + 8ULL;
    cpu->regs[2] = cpu->regs[20] << 3;
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1c1f6cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7b030ULL);
    goto L_1c1eac;
L_1c1f70:
    cpu->regs[30] = PB_BASE + 0x1c1f74ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1c1f98;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    if ((cpu->regs[1])!=0) goto L_1c1ffc;
L_1c1f80:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 48ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c1f98ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1c1f98:
    cpu->regs[23] = 0ULL;
    goto L_1c1ec0;
L_1c1fa0:
    cpu->regs[0] = cpu->regs[24] + 8ULL;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[20] << 3;
    cpu->regs[0] = cpu->regs[22] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1c1fb4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7b030ULL);
    PB_STR((cpu->regs[22] + cpu->regs[24]), cpu->regs[23]);
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[23] = 0ULL;
    goto L_1c1ec0;
L_1c1fc4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 72ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c1fe0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1c1ec0;
L_1c1fe4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c1f3c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c1ff8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c1f3c;
L_1c1ffc:
    cpu->regs[20] = 18446744073709551615ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[1];
    goto L_1c1e7c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1c2018ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    if ((cpu->regs[1])!=0) goto L_1c206c;
L_1c2024:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_1c203c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    if ((cpu->regs[1])!=0) goto L_1c2084;
L_1c2034:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1c203cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1c208cULL);
L_1c203c:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[30] = PB_BASE + 0x1c204cULL; PB_CALL(35, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c2060;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c2074;
L_1c2060:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1c206c:
    cpu->regs[30] = PB_BASE + 0x1c2070ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_1c2024;
L_1c2074:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_1c2084:
    cpu->regs[30] = PB_BASE + 0x1c2088ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x17faa0ULL);
    goto L_1c2034;
}
