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

void ft__PyTime_FromMillisecondsObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = 16960ULL;
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x226240ULL); return; };
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2592));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_84bd8;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_84bdc;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_84bdc;
L_84bd8:
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x1f2d20ULL); return; };
L_84bdc:
    cpu->regs[0] = cpu->regs[1];
    return;
    SP = SP - 112ULL;
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[3], 0ULL); } else { FLAG_CMP(0, 1); }
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[3];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3080));
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 0));
    PB_STR((SP + 40), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = 18446744073709551615ULL;
    PB_STR((SP + 16), cpu->regs[5]);
    if (FLAG_LT) goto L_84c48;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LE) goto L_84c7c;
L_84c48:
    cpu->regs[1] = SP + 32ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[1] = PB_BASE + 0x496000ULL;
    cpu->regs[1] = cpu->regs[1] + 832ULL;
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[7] = 0ULL;
    cpu->regs[4] = cpu->regs[1] + 3488ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x84c78ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_84d38;
L_84c7c:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_GT) goto L_84cac;
L_84c84:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[22], (SP + 16));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_84cc0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x84ca8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_84d38;
L_84cac:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x84cb8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x155680ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_84c84;
    goto L_84d38;
L_84cc0:
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 20));
    if (((cpu->regs[0] >> 1) & 1)) goto L_84cec;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 888));
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = cpu->regs[2] + 720ULL;
    cpu->regs[1] = cpu->regs[1] + 728ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x84ce8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_84d38;
L_84cec:
    if (!((cpu->regs[22] >> 63) & 1)) goto L_84d20;
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_84df0;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 96));
    SP = SP + 112ULL;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x1ccda4ULL); return; };
L_84d20:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x84d2cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_84d40;
L_84d38:
    cpu->regs[0] = 0ULL;
    goto L_84ddc;
L_84d40:
    cpu->regs[1] = cpu->regs[0] + 32ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x84d50ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1ccfecULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_84d98;
    cpu->regs[30] = PB_BASE + 0x84d60ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_84d80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_84d80;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x84d80ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_84d80:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(11ULL)));
    if (FLAG_NE) goto L_84d38;
    cpu->regs[30] = PB_BASE + 0x84d8cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_84ddc;
L_84d98:
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_EQ) goto L_84dd8;
    cpu->regs[0] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0x84da8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x13e868ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_84dd8;
    PB_LDR(cpu->regs[0], (SP + 24));
    if ((cpu->regs[0])==0) goto L_84d38;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_84d38;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_84d38;
    cpu->regs[30] = PB_BASE + 0x84dd4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_84d38;
L_84dd8:
    PB_LDR(cpu->regs[0], (SP + 24));
L_84ddc:
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_84df4;
L_84df0:
    cpu->regs[30] = PB_BASE + 0x84df4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_84df4:
    PB_LDR(cpu->regs[23], (SP + 96));
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 80));
    if ((cpu->regs[0])!=0) goto L_84e40;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
L_84e40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    cpu->regs[30] = PB_BASE + 0x84e48ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x12cb88ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_84e5c;
L_84e50:
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_84f10;
L_84e5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[30] = PB_BASE + 0x84e64ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x12cb88ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_84e50;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80)); PB_LDR(cpu->regs[22], (cpu->regs[19] + 80) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GE) { FLAG_CMP(cpu->regs[1], cpu->regs[22]); } else { FLAG_CMP(0, 0); }
    if (FLAG_LE) goto L_84ef0;
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_GE) { FLAG_CMP(cpu->regs[1], cpu->regs[3]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_84ef0;
    cpu->regs[1] = cpu->regs[22] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_NE) goto L_84ef0;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x84ea4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x84f34ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_84ed0;
    cpu->regs[1] = 65535ULL;
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    cpu->regs[0] = cpu->regs[0] + 2592ULL;
    cpu->regs[3] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = cpu->regs[3] + 2656ULL;
    cpu->regs[0] = (FLAG_HI) ? cpu->regs[3] : cpu->regs[0];
    goto L_84ed8;
L_84ed0:
    cpu->regs[3] = PB_BASE + 0x2a0000ULL;
    cpu->regs[0] = cpu->regs[3] + 2528ULL;
L_84ed8:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x84ee8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_84f10;
L_84ef0:
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[0] = cpu->regs[0] + 2720ULL;
    cpu->regs[30] = PB_BASE + 0x84f0cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[19] = cpu->regs[0];
L_84f10:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x84f18ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x84f20ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
