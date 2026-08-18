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

void ft_PyWeakref_GetObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_1a1e4c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3288));
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1a1e08ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a1e2c;
L_1a1e0c:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[0] = (FLAG_GT) ? cpu->regs[0] : cpu->regs[1];
L_1a1e24:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1a1e2c:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3632));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 4056));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1a1e0c;
L_1a1e4c:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = 911ULL;
    cpu->regs[0] = cpu->regs[0] + 1464ULL;
    cpu->regs[30] = PB_BASE + 0x1a1e5cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a1e24;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 32));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[1] >> 5) & 0x1ULL)));
    if (!((cpu->regs[1] >> 6) & 1)) goto L_1a1ea4;
    cpu->regs[3] = 127ULL;
    PB_STRW((cpu->regs[0] + 20), cpu->regs[3]);
    cpu->regs[3] = cpu->regs[2] + 40ULL;
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1a1ecc;
L_1a1e84:
    PB_STR((cpu->regs[0] + 8), cpu->regs[3]);
    PB_LDRB(cpu->regs[3], (cpu->regs[0] + 53));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_1a1edc;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 16));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
L_1a1e98:
    PB_STRW((cpu->regs[0] + 16), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[2]);
    return;
L_1a1ea4:
    cpu->regs[3] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1a1ed4;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(2ULL)));
    cpu->regs[5] = 1114111ULL;
    cpu->regs[3] = 65535ULL;
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[5];
L_1a1ec0:
    PB_STRW((cpu->regs[0] + 20), cpu->regs[3]);
    cpu->regs[3] = cpu->regs[2] + 56ULL;
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1a1e84;
L_1a1ecc:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 56));
    goto L_1a1e84;
L_1a1ed4:
    cpu->regs[3] = 255ULL;
    goto L_1a1ec0;
L_1a1edc:
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    goto L_1a1e98;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1a1efcULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[30] = PB_BASE + 0x1a1f00ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1a1f20ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
L_1a1f20:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[5], (cpu->regs[0] + 16) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_EQ) goto L_1a1f74;
    cpu->regs[30] = PB_BASE + 0x1a1f48ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18d520ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_NE) goto L_1a1f5c;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
L_1a1f5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_STR((cpu->regs[19] + 16), cpu->regs[4]);
    if ((cpu->regs[0])!=0) goto L_1a1fb4;
L_1a1f68:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    if ((cpu->regs[1])!=0) goto L_1a1fa8;
    PB_STR((cpu->regs[19] + 40), 0ULL); PB_STR((cpu->regs[19] + 40) + 8, 0ULL);
L_1a1f74:
    if ((cpu->regs[5])!=0) goto L_1a1f84;
L_1a1f78:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1a1f84:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a1fa0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[5] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1a1fa0;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1a1fa0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1a1fa0:
    PB_STR((cpu->regs[19] + 24), 0ULL);
    goto L_1a1f78;
L_1a1fa8:
    PB_STR((cpu->regs[1] + 40), cpu->regs[0]);
    PB_STR((cpu->regs[19] + 40), 0ULL); PB_STR((cpu->regs[19] + 40) + 8, 0ULL);
    goto L_1a1f74;
L_1a1fb4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    PB_STR((cpu->regs[0] + 48), cpu->regs[1]);
    goto L_1a1f68;
    SP = SP - 112ULL;
    cpu->regs[1] = 6000ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1a22e4;
L_1a1fec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a2334;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[24])));
    if (FLAG_EQ) goto L_1a2200;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 148));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1a224c;
L_1a201c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 654ULL;
    cpu->regs[30] = PB_BASE + 0x1a2028ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a2240;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a2034ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a2240;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1a2048ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x199ca0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[25] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1a22ec;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1a21d8;
L_1a206c:
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1a207cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a2168;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a2088ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1179e4ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1a216c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1a20a0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a2168;
    if ((cpu->regs[20])==0) goto L_1a2178;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
L_1a20ac:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1a22ec;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x1a20c8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a21a4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a20d4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x19e3e8ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a21a4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1a20e8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a218c;
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[3], (cpu->regs[0] + 28) + 4);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    if ((cpu->regs[20])==0) goto L_1a2160;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16)); PB_LDR(cpu->regs[20], (cpu->regs[20] + 16) + 8);
L_1a2100:
    cpu->regs[7] = cpu->regs[23];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    PB_STRW((SP + 0), cpu->regs[4]);
    PB_STRW((SP + 8), cpu->regs[3]);
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 16), cpu->regs[2]);
    cpu->regs[6] = cpu->regs[22];
    cpu->regs[5] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[8];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a212cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1a3240ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a2344;
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_1a213c:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_1a2148:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 112ULL;
    return;
L_1a2160:
    cpu->regs[1] = 0ULL;
    goto L_1a2100;
L_1a2168:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
L_1a216c:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[26]);
    goto L_1a20ac;
L_1a2178:
    cpu->regs[30] = PB_BASE + 0x1a217cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1a21b8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[20] = 0ULL;
    goto L_1a20ac;
L_1a218c:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    goto L_1a2148;
L_1a21a4:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
L_1a21b0:
    cpu->regs[4] = 0ULL;
    goto L_1a213c;
L_1a21b8:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    goto L_1a21b0;
L_1a21d8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a21e0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a206c;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    goto L_1a21b0;
L_1a2200:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a2208ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a22f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 148));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1a2318;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a201c;
L_1a2228:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_1a2148;
L_1a2240:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    goto L_1a21b0;
L_1a224c:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_1a2250:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1a2378;
L_1a2264:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 654ULL;
    cpu->regs[30] = PB_BASE + 0x1a2274ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a23b4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a2280ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x10642cULL);
    if ((cpu->regs[0])==0) goto L_1a23b4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a228cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x199ca0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a2394;
L_1a2294:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1a2388;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 654ULL;
    cpu->regs[30] = PB_BASE + 0x1a22a8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a2400;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a22b8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x10642cULL);
    if ((cpu->regs[0])==0) goto L_1a2400;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a22c4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x199ca0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a23bc;
L_1a22cc:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_1a22d0:
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_1a22d4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[5]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a201c;
    goto L_1a2228;
L_1a22e4:
    cpu->regs[30] = PB_BASE + 0x1a22e8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1a1fec;
L_1a22ec:
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    goto L_1a21b0;
L_1a22f8:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_1a2148;
L_1a2318:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a2250;
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    cpu->regs[4] = 0ULL;
    goto L_1a2148;
L_1a2334:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_1a2148;
L_1a2344:
    cpu->regs[30] = PB_BASE + 0x1a2348ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    if ((cpu->regs[0])!=0) goto L_1a235c;
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    cpu->regs[4] = 0ULL;
    goto L_1a213c;
L_1a235c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    goto L_1a2148;
L_1a2378:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a2380ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a2264;
L_1a2388:
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 144));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - 1ULL));
    goto L_1a22d4;
L_1a2394:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a239cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xd0c54ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1a2294;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1a23b0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1a240c;
L_1a23b4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    goto L_1a2294;
L_1a23bc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a23c4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xd0c54ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1a22cc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x1a23d8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a2400;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1a23e8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a2400;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 5ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1a23fcULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a2448;
L_1a2400:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    goto L_1a22d0;
L_1a240c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = cpu->regs[3] + 2008ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1a242cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1a247c;
L_1a243c:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_1a213c;
L_1a2448:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2656));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 20));
    cpu->regs[3] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = cpu->regs[3] + 1488ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1a246cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_1a243c;
L_1a247c:
    cpu->regs[30] = PB_BASE + 0x1a2480ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1a2490;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_1a22d4;
L_1a2490:
    cpu->regs[0] = 1ULL;
    cpu->regs[1] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_1a22d4;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1a24c8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1a25d0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a257c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])!=0) goto L_1a25c4;
L_1a24d8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[24], (cpu->regs[1] + 944));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 1904));
    goto L_1a24f4;
L_1a24f0:
    cpu->regs[19] = cpu->regs[19] + 16ULL;
L_1a24f4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[20];
    if ((cpu->regs[1])==0) goto L_1a25b8;
    cpu->regs[30] = PB_BASE + 0x1a2504ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a24f0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_1a2594;
    cpu->regs[30] = PB_BASE + 0x1a2514ULL; PB_CALL(40, cpu, tlb, cpu->regs[0]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a257c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3928));
    cpu->regs[30] = PB_BASE + 0x1a2528ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a254c;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 1013ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(42, cpu, tlb, PB_BASE + 0x1a2a20ULL); return; };
L_1a254c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a2554ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x190cccULL);
    if ((cpu->regs[0])==0) goto L_1a257c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a2574ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1f46a4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[22] = (FLAG_EQ) ? 0ULL : cpu->regs[21];
L_1a257c:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a2594:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a259cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1a1d48ULL);
    if ((cpu->regs[0])==0) goto L_1a257c;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1a25b0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1a25b0:
    cpu->regs[22] = cpu->regs[0];
    goto L_1a257c;
L_1a25b8:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    goto L_1a257c;
L_1a25c4:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_1a257c;
    goto L_1a24d8;
L_1a25d0:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1a25f8ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1a2770ULL);
    if ((cpu->regs[0])!=0) goto L_1a2618;
L_1a25fc:
    cpu->regs[21] = 0ULL;
L_1a2600:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1a2618:
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1a2624ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[30] = PB_BASE + 0x1a2628ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1f2ea0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1a25fc;
    PB_LDR(cpu->regs[21], (cpu->regs[23] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_STR((SP + 64), cpu->regs[25]);
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 944));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1a26a0;
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 32));
    if ((cpu->regs[24])==0) goto L_1a2714;
L_1a2650:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1a265cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1955c0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a270c;
    cpu->regs[30] = PB_BASE + 0x1a2668ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x18fc40ULL);
    if ((cpu->regs[0])==0) goto L_1a26f8;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1a2674ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1904c0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a26f8;
L_1a2678:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a2688ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x190d00ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a26ec;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 1488));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a26d0;
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2600;
L_1a26a0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_1a270c;
    cpu->regs[30] = PB_BASE + 0x1a26acULL; PB_CALL(53, cpu, tlb, cpu->regs[0]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a270c;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1a26c4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xe97e4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1a2678;
    goto L_1a26f8;
L_1a26d0:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[0] = cpu->regs[0] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0x1a26e4ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xabed8ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2600;
L_1a26ec:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1a26f8ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x144960ULL);
L_1a26f8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a270c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1a2740;
L_1a270c:
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a25fc;
L_1a2714:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_NE) goto L_1a270c;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3624ULL;
    cpu->regs[30] = PB_BASE + 0x1a272cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xe9950ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a2750;
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 1728));
    if ((cpu->regs[24])!=0) goto L_1a2650;
L_1a2738:
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a25fc;
L_1a2740:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a2748ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a25fc;
L_1a2750:
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 136ULL;
    cpu->regs[30] = PB_BASE + 0x1a2760ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xe9950ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a270c;
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 1736));
    if ((cpu->regs[24])!=0) goto L_1a2650;
    goto L_1a2738;
L_1a2770:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1920));
    cpu->regs[30] = PB_BASE + 0x1a279cULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1928));
    if ((cpu->regs[0])==0) goto L_1a27fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a27b0ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x190e28ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a27fc;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1928));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x1a27c8ULL; PB_CALL(62, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a27f4;
L_1a27d0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1920));
    cpu->regs[30] = PB_BASE + 0x1a27d8ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x17faa0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a27e0ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xd7784ULL);
L_1a27e0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1a27f4:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
    goto L_1a27d0;
L_1a27fc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1920));
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1a2808ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x17faa0ULL);
    goto L_1a27e0;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a282c;
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
L_1a282c:
    cpu->regs[0] = 1ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a2838ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xe9ee0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_GT) goto L_1a2968;
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a284c;
    PB_STR((cpu->regs[19] + 0), 0ULL);
L_1a284c:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 184));
    if ((cpu->regs[20])!=0) goto L_1a2910;
L_1a2854:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x1a285cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1a2864ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[30] = PB_BASE + 0x1a286cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    cpu->regs[30] = PB_BASE + 0x1a2874ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    cpu->regs[30] = PB_BASE + 0x1a287cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    cpu->regs[30] = PB_BASE + 0x1a2884ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 128));
    cpu->regs[30] = PB_BASE + 0x1a288cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 136));
    cpu->regs[30] = PB_BASE + 0x1a2894ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[30] = PB_BASE + 0x1a289cULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    if ((cpu->regs[0])!=0) goto L_1a28c4;
L_1a28a4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 144));
    if ((cpu->regs[0])!=0) goto L_1a2904;
L_1a28ac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if ((cpu->regs[0])!=0) goto L_1a28fc;
L_1a28b4:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(76, cpu, tlb, PB_BASE + 0xdfce0ULL); return; };
L_1a28c4:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a28ccULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1a28d8ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x1a28e4ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x1a28f0ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    cpu->regs[30] = PB_BASE + 0x1a28f8ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_1a28a4;
L_1a28fc:
    cpu->regs[30] = PB_BASE + 0x1a2900ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x1a29b0ULL);
    goto L_1a28b4;
L_1a2904:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a290cULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_1a28ac;
L_1a2910:
    cpu->regs[1] = cpu->tls_ptr;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1a2928ULL; PB_CALL(84, cpu, tlb, cpu->regs[2]);
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 16));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[20];
    cpu->regs[22] = cpu->regs[22] + 1832ULL;
    PB_LDR(cpu->regs[0], cpu->regs[23]); cpu->regs[23] += 8;
L_1a2944:
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_LE) goto L_1a2980;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[21] << 3)));
    if ((cpu->regs[1])==0) goto L_1a2960;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + (cpu->regs[21] << 3)));
    cpu->regs[30] = PB_BASE + 0x1a295cULL; PB_CALL(85, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
L_1a2960:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_1a2944;
L_1a2968:
    cpu->regs[1] = cpu->regs[0] - 1ULL;
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a2974;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
L_1a2974:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a2980:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a2988ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1a2854;
    /* nop */
    /* nop */
    /* nop */
}
