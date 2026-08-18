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

void ft__PyUnicode_EncodeUTF7(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_STR((SP + 64), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[2];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[21] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_178024;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[20] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    cpu->regs[20] = (FLAG_EQ) ? cpu->regs[20] : cpu->regs[1];
L_177c54:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    if ((cpu->regs[22])==0) goto L_177fe8;
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_GT) goto L_177fc0;
    cpu->regs[1] = cpu->regs[22] << 3;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x177c74ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_17802c;
    cpu->regs[1] = cpu->regs[0] + 32ULL;
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_177fe0;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    cpu->regs[7] = PB_BASE + 0x2b8000ULL;
    cpu->regs[7] = cpu->regs[7] + 2096ULL;
    cpu->regs[9] = PB_BASE + 0x29a000ULL;
    cpu->regs[7] = cpu->regs[7] + 2032ULL;
    cpu->regs[10] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[9] = cpu->regs[9] + 3344ULL;
    cpu->regs[8] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[11] = 43ULL;
L_177cbc:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_177f60;
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + cpu->regs[6]));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_177d54;
L_177ccc:
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(126ULL)));
    if (FLAG_LS) goto L_177e14;
L_177cd8:
    cpu->regs[3] = cpu->regs[0];
L_177cdc:
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 16ULL));
    cpu->regs[8] = cpu->regs[3] | (cpu->regs[8] << 16);
L_177ce4:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(5ULL)));
    if (FLAG_LS) goto L_177eb4;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 6ULL));
    cpu->regs[0] = cpu->regs[8] >> (cpu->regs[4] & 63);
    cpu->regs[0] = cpu->regs[0] & 63ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[9] + cpu->regs[0]));
    PB_STRB(cpu->regs[2], cpu->regs[0]); cpu->regs[2] += 1;
    goto L_177ce4;
L_177d04:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_177ec8;
    PB_LDRH(cpu->regs[0], (cpu->regs[20] + (cpu->regs[6] << 1)));
L_177d10:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(43ULL)));
    if (FLAG_EQ) goto L_177fb0;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_177f90;
L_177d24:
    PB_LDRB(cpu->regs[3], (cpu->regs[7] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_177d38;
L_177d2c:
    FLAG_CMP(((uint32_t)(cpu->regs[10])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_177f50;
L_177d38:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    PB_STRB(cpu->regs[2], cpu->regs[0]); cpu->regs[2] += 1;
    FLAG_CMP(cpu->regs[22], cpu->regs[6]);
    if (FLAG_EQ) goto L_177d80;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_177d04;
L_177d50:
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + cpu->regs[6]));
L_177d54:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(43ULL)));
    if (FLAG_EQ) goto L_177fb0;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_177ebc;
    PB_LDRB(cpu->regs[3], (cpu->regs[7] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_177d2c;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    PB_STRB(cpu->regs[2], cpu->regs[0]); cpu->regs[2] += 1;
    FLAG_CMP(cpu->regs[22], cpu->regs[6]);
    if (FLAG_NE) goto L_177d50;
L_177d80:
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_177db4;
    cpu->regs[3] = 0ULL;
L_177d88:
    cpu->regs[0] = 6ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - cpu->regs[4]));
    cpu->regs[4] = PB_BASE + 0x29a000ULL;
    cpu->regs[4] = cpu->regs[4] + 3344ULL;
    cpu->regs[0] = cpu->regs[8] << (cpu->regs[0] & 63);
    cpu->regs[0] = cpu->regs[0] & 63ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    PB_STRB(cpu->regs[2], cpu->regs[0]); cpu->regs[2] += 1;
L_177da8:
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_177db4;
    cpu->regs[0] = 45ULL;
    PB_STRB(cpu->regs[2], cpu->regs[0]); cpu->regs[2] += 1;
L_177db4:
    cpu->regs[1] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x177dc0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x13e868ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_17802c;
    PB_LDR(cpu->regs[0], (SP + 0));
L_177dcc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_177fdc;
    PB_LDR(cpu->regs[23], (SP + 64));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_177e00:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + (cpu->regs[6] << 2)));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_177ecc;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_177ee8;
L_177e14:
    cpu->regs[5] = PB_BASE + 0x2b8000ULL;
    cpu->regs[5] = cpu->regs[5] + 2096ULL;
    cpu->regs[5] = cpu->regs[5] + 2032ULL;
    cpu->regs[3] = cpu->regs[0];
    PB_LDRB(cpu->regs[5], (cpu->regs[5] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    if ((((uint32_t)(cpu->regs[5])))!=0) goto L_177f74;
L_177e2c:
    cpu->regs[5] = cpu->regs[2] + 1ULL;
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_177e60;
    cpu->regs[3] = 6ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - cpu->regs[4]));
    cpu->regs[4] = PB_BASE + 0x29a000ULL;
    cpu->regs[4] = cpu->regs[4] + 3344ULL;
    cpu->regs[3] = cpu->regs[8] << (cpu->regs[3] & 63);
    cpu->regs[3] = cpu->regs[3] & 63ULL;
    cpu->regs[8] = 0ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[4] + cpu->regs[3]));
    PB_STRB((cpu->regs[2] + 0), cpu->regs[3]);
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[5] = cpu->regs[5] + 1ULL;
L_177e60:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(57ULL)));
    if (FLAG_HI) goto L_177f2c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(42ULL)));
    if (FLAG_LS) goto L_177e90;
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] - 43ULL));
    cpu->regs[3] = 32757ULL;
    cpu->regs[3] = cpu->regs[3] >> (cpu->regs[4] & 63);
    if (!((cpu->regs[3] >> 0) & 1)) goto L_177e90;
L_177e80:
    cpu->regs[3] = 45ULL;
    PB_STRB((cpu->regs[2] + 0), cpu->regs[3]);
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[5] = cpu->regs[5] + 1ULL;
L_177e90:
    PB_STRB((cpu->regs[2] + 0), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
L_177ea0:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[6]);
    if (FLAG_NE) goto L_177cbc;
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_177d88;
    goto L_177da8;
L_177eb4:
    cpu->regs[3] = 1ULL;
    goto L_177ea0;
L_177ebc:
    cpu->regs[3] = cpu->regs[0];
    PB_STRB(cpu->regs[2], cpu->regs[11]); cpu->regs[2] += 1;
    goto L_177cdc;
L_177ec8:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + (cpu->regs[6] << 2)));
L_177ecc:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(43ULL)));
    if (FLAG_EQ) goto L_177fb0;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(126ULL)));
    if (FLAG_LS) goto L_177d24;
L_177ee0:
    cpu->regs[3] = 43ULL;
    PB_STRB(cpu->regs[2], cpu->regs[3]); cpu->regs[2] += 1;
L_177ee8:
    cpu->regs[3] = 65535ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_LS) goto L_177cd8;
    cpu->regs[3] = 55232ULL;
    cpu->regs[5] = PB_BASE + 0x29a000ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + (cpu->regs[0] >> 10)));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 16ULL));
    cpu->regs[5] = cpu->regs[5] + 3344ULL;
    cpu->regs[8] = cpu->regs[3] | (cpu->regs[8] << 16);
L_177f0c:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(5ULL)));
    if (FLAG_LS) goto L_177fa0;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 6ULL));
    cpu->regs[3] = cpu->regs[8] >> (cpu->regs[4] & 63);
    cpu->regs[3] = cpu->regs[3] & 63ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[5] + cpu->regs[3]));
    PB_STRB(cpu->regs[2], cpu->regs[3]); cpu->regs[2] += 1;
    goto L_177f0c;
L_177f2c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(90ULL)));
    if (FLAG_HI) goto L_177f40;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(64ULL)));
    if (FLAG_HI) goto L_177e80;
    goto L_177e90;
L_177f40:
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 97ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(25ULL)));
    if (FLAG_LS) goto L_177e80;
    goto L_177e90;
L_177f50:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[3], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_177d38;
    goto L_177ee0;
L_177f60:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_177e00;
    PB_LDRH(cpu->regs[0], (cpu->regs[20] + (cpu->regs[6] << 1)));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_177ccc;
    goto L_177d10;
L_177f74:
    FLAG_CMP(((uint32_t)(cpu->regs[10])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_177e2c;
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_177cdc;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_177cdc;
    goto L_177e2c;
L_177f90:
    cpu->regs[5] = 43ULL;
    cpu->regs[3] = cpu->regs[0];
    PB_STRB(cpu->regs[2], cpu->regs[5]); cpu->regs[2] += 1;
    goto L_177cdc;
L_177fa0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 1023ULL));
    cpu->regs[3] = 56320ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + cpu->regs[3]));
    goto L_177cdc;
L_177fb0:
    cpu->regs[0] = 11563ULL;
    cpu->regs[3] = 0ULL;
    PB_STRH(cpu->regs[2], cpu->regs[0]); cpu->regs[2] += 2;
    goto L_177ea0;
L_177fc0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_178034;
L_177fdc:
    cpu->regs[30] = PB_BASE + 0x177fe0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_177fe0:
    cpu->regs[2] = cpu->regs[1];
    goto L_177db4;
L_177fe8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_177fdc;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64));
    SP = SP + 80ULL;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0xe9c70ULL); return; };
L_178024:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 56));
    goto L_177c54;
L_17802c:
    cpu->regs[0] = 0ULL;
    goto L_177dcc;
L_178034:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64));
    SP = SP + 80ULL;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
}
