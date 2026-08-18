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

void ft__PyDict_SizeOf(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_277dc4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[7], (cpu->regs[1] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 32) + 8);
    if ((cpu->regs[1])!=0) goto L_277e04;
L_277dd4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_277dfc;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x277decULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x18ff00ULL);
    cpu->regs[7] = cpu->regs[7] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[7];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_277dfc:
    cpu->regs[0] = cpu->regs[7];
    return;
L_277e04:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 16) + 8);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[7] = cpu->regs[7] + (cpu->regs[1] << 3);
    goto L_277dd4;
    /* nop */
    /* nop */
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x277e2cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x277dc4ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 8));
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2592));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    FLAG_CMP(cpu->regs[5], cpu->regs[6]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_277ec0;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x277e84ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_277ec0;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x277e94ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_277ec0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3096));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x277ea8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_277ec0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4024));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x277ebcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_277fa4;
L_277ec0:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x277ec8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x141d48ULL);
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_277f9c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x277ed8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x141d48ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_277f9c;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(3ULL)));
    if (FLAG_GT) goto L_277f68;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_277f3c;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_277fb8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x277f00ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x277fe0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GE) { FLAG_CMP(cpu->regs[20], 3ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_277fc4;
L_277f0c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_277f9c;
    if (FLAG_EQ) goto L_277f44;
L_277f18:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_277f20:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_277fb0;
L_277f2c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_277f3c:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_277f50;
    if (FLAG_EQ) goto L_277fcc;
L_277f44:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_277f20;
L_277f50:
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_GE) goto L_277f44;
L_277f58:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x277f64ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x277fe0ULL);
    goto L_277f0c;
L_277f68:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_277f90;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(5ULL)));
    if (FLAG_NE) goto L_277f44;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LT) goto L_277f44;
L_277f80:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x277f8cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x277fe0ULL);
    goto L_277f0c;
L_277f90:
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LE) goto L_277f44;
    goto L_277f80;
L_277f9c:
    cpu->regs[0] = 0ULL;
    goto L_277f2c;
L_277fa4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_277f2c;
L_277fb0:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_277f2c;
L_277fb8:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_277f44;
    goto L_277f18;
L_277fc4:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_277f18;
    goto L_277f44;
L_277fcc:
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_GT) goto L_277f44;
    goto L_277f58;
    /* nop */
    /* nop */
L_277fe0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x277ff8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_278080;
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[20] = 1ULL;
    goto L_278030;
L_278008:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278010ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11e710ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    if (((cpu->regs[2] >> 31) & 1)) goto L_278028;
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
    if ((cpu->regs[3])==0) goto L_278088;
L_278028:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_278050;
L_278030:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x278038ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    if ((cpu->regs[19])!=0) goto L_278008;
    cpu->regs[30] = PB_BASE + 0x278048ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[20] = ((uint32_t)((FLAG_EQ) ? cpu->regs[20] : (~0ULL)));
L_278050:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_27806c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_27806c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x27806cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_27806c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_278080:
    cpu->regs[20] = 4294967295ULL;
    goto L_27806c;
L_278088:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278090ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_278028;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x2780c4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_27812c;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = (FLAG_GT) ? cpu->regs[19] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_2780f0;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_2780f0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278100ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe28a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_278118;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_278134;
L_278118:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_27812c:
    cpu->regs[20] = 4294967295ULL;
    goto L_278118;
L_278134:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27813cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_278118;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[5];
    cpu->regs[20] = cpu->regs[6];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[3];
    cpu->regs[22] = cpu->regs[4];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[7];
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[1];
    cpu->regs[1] = 56ULL;
    cpu->regs[30] = PB_BASE + 0x278180ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_27819c;
    cpu->regs[1] = 4ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[24]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[25]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[23]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[21]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[22]);
    PB_STRW((cpu->regs[0] + 48), cpu->regs[19]); PB_STRW((cpu->regs[0] + 48) + 4, cpu->regs[20]);
L_27819c:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    /* nop */
    /* nop */
    /* nop */
    goto L_2781c4;
L_2781c4:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_278240;
L_2781ec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_278248;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 14ULL;
    cpu->regs[30] = PB_BASE + 0x278204ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_278228;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_278228;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 15ULL;
    cpu->regs[30] = PB_BASE + 0x278220ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_278228;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_278228:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_278230:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_278240:
    cpu->regs[30] = PB_BASE + 0x278244ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_2781ec;
L_278248:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_278230;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_2782d4;
L_278288:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2782dc;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x2782a0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_2782c4;
L_2782a4:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_2782ac:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_2782b4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2782c4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2782ccULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1f4ac0ULL);
    if ((cpu->regs[0])!=0) goto L_2782ac;
    goto L_2782a4;
L_2782d4:
    cpu->regs[30] = PB_BASE + 0x2782d8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_278288;
L_2782dc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_2782b4;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_278540;
L_278318:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27850c;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_2784f0;
L_27833c:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x278348ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x27854cULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278488;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_2784b8;
L_278368:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27847c;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x27837cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278470;
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_27847c;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = 0ULL;
    cpu->regs[26] = 1ULL;
L_278398:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x2783a4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_278420;
L_2783a8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x2783b8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278518;
L_2783c0:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[24]));
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_GT) goto L_278450;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2783d4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x2783f0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x118accULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    if ((cpu->regs[0])==0) goto L_278490;
L_278408:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_278410:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_278420:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x27842cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x27854cULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278468;
    FLAG_CMP(cpu->regs[26], cpu->regs[25]);
    if (FLAG_EQ) goto L_27849c;
L_27843c:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[25] << 3)), cpu->regs[27]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_278398;
L_278450:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_2783c0;
L_278468:
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_2783a8;
L_278470:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x27847cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x22d780ULL);
L_27847c:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
L_278488:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_278490:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    goto L_278408;
L_27849c:
    cpu->regs[26] = cpu->regs[26] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[26] << 3;
    cpu->regs[30] = PB_BASE + 0x2784acULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_2784c4;
    cpu->regs[20] = cpu->regs[0];
    goto L_27843c;
L_2784b8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2784c0ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_278368;
L_2784c4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2784ccULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x2784d8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_278488;
L_2784f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2784f8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_27833c;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_278490;
L_27850c:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[0] = 0ULL;
    goto L_278410;
L_278518:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x278520ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x27852cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_278488;
L_278540:
    cpu->regs[30] = PB_BASE + 0x278544ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    goto L_278318;
L_27854c:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 144));
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_27888c;
L_278578:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2788b8;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    cpu->regs[1] = 6000ULL;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[21] = cpu->regs[22];
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_278898;
    cpu->regs[3] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
L_2785a8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[21];
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_2788d4;
    PB_STR((SP + 64), cpu->regs[25]);
L_2785c4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_27874c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[0] + 20) + 4);
L_2785dc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2785e4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1f4190ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278678;
    cpu->regs[1] = PB_BASE + 0x278000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 452ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x278600ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_278678;
L_278604:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_278608:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
L_278614:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x278628ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_2788fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278634ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1f2228ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2788fc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x278648ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1085d0ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_27890c;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_STR((cpu->regs[0] + 0), cpu->regs[20]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[21]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_27865c:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_278664:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_278678:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27876c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x27868cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1f43e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_278604;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27876c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2786a8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x10a34cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_278604;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27876c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 602ULL;
    cpu->regs[30] = PB_BASE + 0x2786c8ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_278848;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27876c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 601ULL;
    cpu->regs[30] = PB_BASE + 0x2786e4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_2787ec;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27876c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 603ULL;
    cpu->regs[30] = PB_BASE + 0x278700ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_278790;
L_278704:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_278708:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
L_278714:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[4]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27877c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278728ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1f4f24ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_278614;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
L_278744:
    cpu->regs[4] = 0ULL;
    goto L_27865c;
L_27874c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278754ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2787d0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[24], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[25], (cpu->regs[1] + 20) + 4);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2785dc;
L_27876c:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_278714;
L_27877c:
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    goto L_278744;
L_278790:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x27879cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_278878;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[25];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2787c0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x10c468ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_278604;
    cpu->regs[30] = PB_BASE + 0x2787ccULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_278704;
L_2787d0:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    goto L_278714;
L_2787ec:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x2787f8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_278878;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[25];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = 0ULL;
L_278818:
    cpu->regs[30] = PB_BASE + 0x27881cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x10c468ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])!=0) goto L_278608;
    cpu->regs[30] = PB_BASE + 0x278830ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_278708;
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[1];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    goto L_278714;
L_278848:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x278854ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_278878;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[25];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[1] = 0ULL;
    goto L_278818;
L_278878:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    goto L_278714;
L_27888c:
    cpu->regs[30] = PB_BASE + 0x278890ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    goto L_278578;
L_278898:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2788a0ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2788c4;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_2785a8;
L_2788b8:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[4] = 0ULL;
    goto L_278664;
L_2788c4:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    goto L_278744;
L_2788d4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2788dcULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2788f0;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    PB_STR((SP + 64), cpu->regs[25]);
    goto L_2785c4;
L_2788f0:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 144));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    goto L_278714;
L_2788fc:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    goto L_278744;
L_27890c:
    cpu->regs[30] = PB_BASE + 0x278910ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    if ((cpu->regs[0])!=0) goto L_278924;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[4] = 0ULL;
    goto L_27865c;
L_278924:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_278664;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x278960ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    if ((cpu->regs[0])==0) goto L_27898c;
    cpu->regs[3] = cpu->regs[0] + 16ULL;
    cpu->regs[2] = 0ULL;
L_27896c:
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    if (FLAG_LE) goto L_27898c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[2] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_STR((cpu->regs[3] + (cpu->regs[2] << 3)), cpu->regs[1]);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    goto L_27896c;
L_27898c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_278a24;
L_2789c8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_278a84;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2789dcULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x116c80ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278a74;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_278a2c;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2320));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_278a2c;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
L_278a0c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_278a10:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_278a24:
    cpu->regs[30] = PB_BASE + 0x278a28ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_2789c8;
L_278a2c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[2] + 36),&_a,4); tlb_read(tlb,(cpu->regs[2] + 40),&_b,4); cpu->regs[3]=(uint64_t)(int64_t)_a; cpu->regs[4]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = PB_BASE + 0x2a0000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[6] = cpu->regs[6] + 1376ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 44),&_s,4); cpu->regs[5] = (uint64_t)(int64_t)_s; } while(0);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[2] + 32),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x278a54ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x278a58ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_278a7c;
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_278a10;
L_278a74:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_278a7c:
    cpu->regs[2] = 0ULL;
    goto L_278a0c;
L_278a84:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_278a10;
    /* nop */
    /* nop */
    /* nop */
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_278c8c;
L_278acc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_278c80;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_278c50;
L_278af0:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x278afcULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x278d00ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278bdc;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_278cd4;
L_278b1c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_278cc4;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = 8ULL;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x278b34ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278ce0;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_278c6c;
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[27] = 1ULL;
L_278b50:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x278b5cULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_278c0c;
L_278b60:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x278b70ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278c98;
L_278b78:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[24], cpu->regs[21]);
    if (FLAG_GT) goto L_278bf4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x278b8cULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x278ba8ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x118accULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    if ((cpu->regs[0])==0) goto L_278be8;
L_278bc4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_278bcc:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_278bdc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_278be0:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_278be8:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    goto L_278bc4;
L_278bf4:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_278b78;
L_278c0c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278c14ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x278d00ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278b60;
    FLAG_CMP(cpu->regs[27], cpu->regs[24]);
    if (FLAG_EQ) goto L_278c34;
L_278c24:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[24] << 3)), cpu->regs[26]);
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_278b50;
L_278c34:
    cpu->regs[27] = cpu->regs[27] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[27] << 3;
    cpu->regs[30] = PB_BASE + 0x278c44ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_278c98;
    cpu->regs[20] = cpu->regs[0];
    goto L_278c24;
L_278c50:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278c58ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_278af0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_278be8;
L_278c6c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_278be0;
L_278c80:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[0] = 0ULL;
    goto L_278bcc;
L_278c8c:
    cpu->regs[30] = PB_BASE + 0x278c90ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    goto L_278acc;
L_278c98:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x278ca0ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x278cacULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_278be0;
L_278cc4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_278be0;
L_278cd4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278cdcULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_278b1c;
L_278ce0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x278cecULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_278be0;
L_278d00:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_278dbc;
L_278d28:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_278dac;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x278d40ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278da0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x278d54ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_278da0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x278d60ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x1f2228ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278da0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x278d74ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x1085d0ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_278dc4;
    PB_STR((cpu->regs[0] + 0), cpu->regs[20]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[21]);
L_278d80:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_278d8c:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_278da0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
L_278da4:
    cpu->regs[3] = 0ULL;
    goto L_278d80;
L_278dac:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_278d8c;
L_278dbc:
    cpu->regs[30] = PB_BASE + 0x278dc0ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_278d28;
L_278dc4:
    cpu->regs[30] = PB_BASE + 0x278dc8ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_278da4;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_278d8c;
}
