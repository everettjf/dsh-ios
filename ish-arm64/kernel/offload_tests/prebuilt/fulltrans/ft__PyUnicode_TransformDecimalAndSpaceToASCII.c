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

void ft__PyUnicode_TransformDecimalAndSpaceToASCII(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1648f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_1647ec;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1647d8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1647d8:
    cpu->regs[20] = cpu->regs[19];
L_1647dc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1647ec:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[1] = 127ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x164800ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1648ec;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((SP + 64), cpu->regs[25]);
    if (!((cpu->regs[0] >> 5) & 1)) goto L_1648e4;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[22] = cpu->regs[20] + 56ULL;
    cpu->regs[0] = cpu->regs[20] + 40ULL;
    cpu->regs[22] = (FLAG_EQ) ? cpu->regs[22] : cpu->regs[0];
L_164828:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[24] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_1648dc;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[19] + 40ULL;
    cpu->regs[19] = cpu->regs[19] + 56ULL;
    cpu->regs[19] = (FLAG_EQ) ? cpu->regs[19] : cpu->regs[0];
L_164844:
    cpu->regs[25] = 0ULL;
L_164848:
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_GE) goto L_1648c4;
    cpu->regs[30] = PB_BASE + 0x164860ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(126ULL)));
    if (FLAG_LS) goto L_16488c;
    cpu->regs[30] = PB_BASE + 0x164870ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1fca00ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1648d4;
    cpu->regs[30] = PB_BASE + 0x164880ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x14d140ULL);
    cpu->regs[21] = ((uint32_t)(cpu->regs[0] + 48ULL));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_16489c;
L_16488c:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] & 255ULL));
L_164890:
    PB_STRB((cpu->regs[22] + cpu->regs[25]), cpu->regs[21]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_164848;
L_16489c:
    cpu->regs[0] = cpu->regs[22] + cpu->regs[25];
    cpu->regs[1] = 63ULL;
    PB_STRB((cpu->regs[22] + cpu->regs[25]), cpu->regs[1]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    PB_STRB((cpu->regs[0] + 1), 0ULL);
    PB_STR((cpu->regs[20] + 16), cpu->regs[25]);
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1647dc;
L_1648c4:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1647dc;
L_1648d4:
    cpu->regs[21] = 32ULL;
    goto L_164890;
L_1648dc:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 56));
    goto L_164844;
L_1648e4:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 56));
    goto L_164828;
L_1648ec:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[20] = 0ULL;
    goto L_1647dc;
L_1648f8:
    cpu->regs[0] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = 9046ULL;
    cpu->regs[0] = cpu->regs[0] + 144ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x16490cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_1647dc;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[21], (cpu->regs[24] + 16));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_164af0;
    if ((cpu->regs[19])==0) goto L_164b44;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 24));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_LE) goto L_164984;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x16495cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdc780ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_164ae8;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    if (((cpu->regs[2] >> 31) & 1)) goto L_16497c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_164ba4;
L_16497c:
    cpu->regs[19] = cpu->regs[22];
    goto L_16498c;
L_164984:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -16));
    if ((cpu->regs[0])==0) goto L_164b98;
L_16498c:
    cpu->regs[2] = cpu->regs[21] - 1ULL; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_LT) goto L_164ae8;
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[1] = cpu->regs[24] + (cpu->regs[21] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[2]));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    cpu->regs[1] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[23] + cpu->regs[2]), cpu->regs[1]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_EQ) goto L_164a08;
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_164a80;
L_1649cc:
    cpu->regs[2] = cpu->regs[19] + cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 24));
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_164aa0;
L_1649e0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1649f0;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1649f0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_164a08:
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 24));
    PB_STR((cpu->regs[23] + cpu->regs[2]), 0ULL);
    cpu->regs[2] = cpu->regs[19] + (cpu->regs[21] << 3);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_164b18;
L_164a20:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    PB_STR((cpu->regs[2] + 16), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_164af8;
L_164a30:
    cpu->regs[2] = cpu->regs[21] - 2ULL;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_164ae8;
L_164a3c:
    cpu->regs[24] = cpu->regs[24] + 24ULL;
L_164a40:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + (cpu->regs[2] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[24] + (cpu->regs[2] << 3)));
    cpu->regs[3] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[23] + (cpu->regs[2] << 3)), cpu->regs[3]);
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[4]);
    if (FLAG_EQ) goto L_164ab4;
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[0] << 3);
    cpu->regs[2] = cpu->regs[2] << 3;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1649cc;
    /* nop */
    /* nop */
    /* nop */
L_164a80:
    cpu->regs[2] = cpu->regs[19] + cpu->regs[2];
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 24));
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1649e0;
    /* nop */
    /* nop */
L_164aa0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1649e0;
    cpu->regs[30] = PB_BASE + 0x164ab0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1649e0;
L_164ab4:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_STR((cpu->regs[23] + (cpu->regs[2] << 3)), 0ULL);
    cpu->regs[3] = cpu->regs[19] + 24ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_164b3c;
L_164acc:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + (cpu->regs[2] << 3)));
    PB_STR((cpu->regs[3] + (cpu->regs[2] << 3)), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_164b20;
L_164adc:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_164a40;
L_164ae8:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[20] + 40), cpu->regs[0]);
L_164af0:
    cpu->regs[19] = 0ULL;
    goto L_1649f0;
L_164af8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_164a30;
    cpu->regs[30] = PB_BASE + 0x164b08ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[2] = cpu->regs[21] - 2ULL;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_NE) goto L_164a3c;
    goto L_164ae8;
L_164b18:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_164a20;
L_164b20:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_164adc;
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x164b34ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    goto L_164adc;
L_164b3c:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_164acc;
L_164b44:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x164b4cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_164ae8;
    cpu->regs[24] = cpu->regs[24] + 24ULL;
    cpu->regs[3] = cpu->regs[19] + 24ULL;
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[20] + 32), cpu->regs[19]);
L_164b64:
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GE) goto L_1649e0;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    if ((cpu->regs[2])==0) goto L_164ae8;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_164b8c;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_164b8c:
    PB_STR((cpu->regs[3] + (cpu->regs[0] << 3)), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_164b64;
L_164b98:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x164ba0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_16498c;
L_164ba4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x164bb0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16498c;
    /* nop */
    /* nop */
    /* nop */
}
