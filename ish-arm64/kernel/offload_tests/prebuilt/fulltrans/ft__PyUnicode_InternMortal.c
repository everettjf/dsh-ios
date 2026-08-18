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

void ft__PyUnicode_InternMortal(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xdc11cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdb76cULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    if ((cpu->regs[1])==0) goto L_dc23c;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xdc14cULL; PB_CALL(2, cpu, tlb, cpu->regs[3]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_dc2dc;
L_dc16c:
    cpu->regs[2] = cpu->regs[1] >> 49;
    cpu->regs[0] = cpu->regs[19] + 3960ULL;
    cpu->regs[5] = cpu->regs[1] & 18446744073709535232ULL;
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[2] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 1096));
    if ((cpu->regs[2])==0) goto L_dc210;
    cpu->regs[3] = ((cpu->regs[1] >> 34) & 0x7fffULL);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[3])) << 3)));
    if ((cpu->regs[3])==0) goto L_dc210;
    cpu->regs[2] = ((cpu->regs[1] >> 20) & 0x3fffULL);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1048575ULL));
    cpu->regs[6] = cpu->regs[3] + (cpu->regs[2] << 3);
    cpu->regs[2] = cpu->regs[2] << 3;
    PB_LDRW(cpu->regs[6], (cpu->regs[6] + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_GT) goto L_dc1bc;
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[4]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_dc210;
L_dc1bc:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 8));
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[5] + 8), cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[5] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[5] + 0), cpu->regs[1]);
    if ((cpu->regs[2])==0) goto L_dc1e8;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_dc240;
L_dc1dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_dc1e8:
    PB_LDRW(cpu->regs[1], (cpu->regs[5] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] << 1));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    PB_STR((cpu->regs[5] + 16), cpu->regs[0]); PB_STR((cpu->regs[5] + 16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[5]);
    PB_STR((cpu->regs[1] + 16), cpu->regs[5]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_dc210:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 128));
    cpu->regs[0] = PB_BASE + 0xd7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1984ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_dc3c4;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xdc22cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7bcf0ULL);
L_dc22c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 5048));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 5048), cpu->regs[0]);
    goto L_dc1dc;
L_dc23c:
    return;
L_dc240:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[1] = 48ULL;
    PB_LDRW(cpu->regs[21], (cpu->regs[5] + 32));
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 4472));
    PB_LDR(cpu->regs[4], (cpu->regs[5] + 16)); PB_LDR(cpu->regs[3], (cpu->regs[5] + 16) + 8);
    cpu->regs[21] = (uint64_t)(uint32_t)cpu->regs[21] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[2] = cpu->regs[22] + cpu->regs[21];
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 16));
    PB_LDR(cpu->regs[7], (cpu->regs[2] + 24));
    PB_STR((cpu->regs[4] + 24), cpu->regs[3]);
    cpu->regs[6] = cpu->regs[19] + (((cpu->regs[1]) & 0xffffffffULL) << 3);
    PB_STR((cpu->regs[3] + 16), cpu->regs[4]);
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 4504));
    PB_STR((cpu->regs[5] + 16), cpu->regs[7]);
    PB_STR((cpu->regs[2] + 24), cpu->regs[5]);
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_dc290;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 40));
    if ((cpu->regs[4])!=0) goto L_dc2cc;
L_dc28c:
    PB_STR((cpu->regs[6] + 4504), cpu->regs[4]);
L_dc290:
    PB_LDRW(cpu->regs[4], (cpu->regs[2] + 20));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 16), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_EQ) goto L_dc368;
L_dc2a4:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_dc340;
    cpu->regs[1] = cpu->regs[19] + (((cpu->regs[1]) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 4504));
    if ((cpu->regs[0])!=0) goto L_dc2bc;
    PB_STR((cpu->regs[1] + 4504), cpu->regs[2]);
L_dc2bc:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_dc308;
L_dc2c4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_dc1dc;
L_dc2cc:
    PB_LDRW(cpu->regs[5], (cpu->regs[4] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[5])));
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[4] : 0ULL;
    goto L_dc28c;
L_dc2dc:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 1712));
    if (!((cpu->regs[2] >> 5) & 1)) goto L_dc300;
    cpu->regs[2] = cpu->regs[20] + 24ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[2] = cpu->regs[20] + (18ULL << 12);
    cpu->regs[2] = cpu->regs[2] + 1936ULL;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_dc16c;
L_dc300:
    cpu->regs[19] = cpu->regs[0];
    goto L_dc16c;
L_dc308:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 32)); PB_LDR(cpu->regs[1], (cpu->regs[2] + 32) + 8);
    if ((cpu->regs[1])==0) goto L_dc338;
    PB_STR((cpu->regs[1] + 32), cpu->regs[0]);
L_dc314:
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 32));
    PB_STR((cpu->regs[4] + 40), cpu->regs[1]);
    PB_STR((cpu->regs[2] + 32), cpu->regs[0]); PB_STR((cpu->regs[2] + 32) + 8, cpu->regs[3]);
    if ((cpu->regs[0])==0) goto L_dc32c;
    PB_STR((cpu->regs[0] + 40), cpu->regs[2]);
L_dc32c:
    PB_STR((cpu->regs[3] + 32), cpu->regs[2]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_dc1dc;
L_dc338:
    PB_STR((cpu->regs[19] + 4496), cpu->regs[0]);
    goto L_dc314;
L_dc340:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 4496));
    PB_STR((cpu->regs[2] + 32), cpu->regs[0]); PB_STR((cpu->regs[2] + 32) + 8, 0ULL);
    if ((cpu->regs[0])==0) goto L_dc350;
    PB_STR((cpu->regs[0] + 40), cpu->regs[2]);
L_dc350:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 4512));
    PB_STR((cpu->regs[19] + 4496), cpu->regs[2]);
    if ((cpu->regs[0])!=0) goto L_dc2c4;
    PB_STR((cpu->regs[19] + 4512), cpu->regs[2]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_dc1dc;
L_dc368:
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 32));
    if ((cpu->regs[4])==0) goto L_dc2a4;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 40));
    if ((cpu->regs[3])==0) goto L_dc3d0;
    PB_STR((cpu->regs[3] + 32), cpu->regs[4]);
L_dc37c:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + cpu->regs[21]));
    PB_STR((cpu->regs[4] + 40), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 4488));
    PB_STR((cpu->regs[2] + 32), cpu->regs[3]);
    PB_STR((cpu->regs[19] + 4488), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xdc398ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x187c20ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + cpu->regs[21]));
    cpu->regs[2] = 1048576ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 360));
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 376));
    cpu->regs[30] = PB_BASE + 0xdc3acULL; PB_CALL(5, cpu, tlb, cpu->regs[3]);
    PB_STR((cpu->regs[22] + cpu->regs[21]), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 5024));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 5024), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_dc1dc;
L_dc3c4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 96));
    cpu->regs[30] = PB_BASE + 0xdc3ccULL; PB_CALL(6, cpu, tlb, cpu->regs[2]);
    goto L_dc22c;
L_dc3d0:
    PB_STR((cpu->regs[19] + 4496), cpu->regs[4]);
    goto L_dc37c;
    /* nop */
    /* nop */
}
