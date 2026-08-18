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

void ft__Py_GetLocaleEncodingObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x21721cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x180140ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21724c;
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x21722cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x21723cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd7784ULL);
L_21723c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_21724c:
    cpu->regs[30] = PB_BASE + 0x217250ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_21723c;
    /* nop */
    /* nop */
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_2173cc;
L_21728c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2173bc;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x2172a0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2173b0;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_21739c;
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = 1ULL;
L_2172c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2172c8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x2173e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_217324;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x2172e0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_217374;
L_2172e8:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[24], cpu->regs[23]);
    if (FLAG_GT) goto L_21733c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2172fcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_21730c:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_217324:
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_EQ) goto L_217354;
L_21732c:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[24] << 3)), cpu->regs[22]);
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_2172c0;
L_21733c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_2172e8;
L_217354:
    cpu->regs[25] = cpu->regs[25] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[25] << 3;
    cpu->regs[30] = PB_BASE + 0x217364ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_217374;
    cpu->regs[20] = cpu->regs[0];
    goto L_21732c;
L_217374:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x21737cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x217388ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_21730c;
L_21739c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_21730c;
L_2173b0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x2173bcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x22d780ULL);
L_2173bc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_21730c;
L_2173cc:
    cpu->regs[30] = PB_BASE + 0x2173d0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_21728c;
    /* nop */
    /* nop */
    /* nop */
L_2173e0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_2174f8;
L_217408:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_217514;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x217420ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1e1324ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21746c;
L_217428:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
L_21742c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_217500;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21743cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1e1324ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_2174cc;
L_217444:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_217448:
    cpu->regs[3] = 0ULL;
L_21744c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_217458:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_21746c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x217474ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1a5b60ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[22] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_21742c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x21748cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_217428;
L_217490:
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2174a4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1a5cccULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21744c;
    cpu->regs[30] = PB_BASE + 0x2174b0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_217448;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_217458;
L_2174cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2174d4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1a5b60ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[22] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_217444;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 11ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2174f0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_217490;
    goto L_217444;
L_2174f8:
    cpu->regs[30] = PB_BASE + 0x2174fcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_217408;
L_217500:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_217458;
L_217514:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_217458;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x21753cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[30] = PB_BASE + 0x217540ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x217580ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[30] = PB_BASE + 0x21754cULL; PB_CALL(25, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_217560;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_21756c;
L_217560:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_21756c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    /* nop */
L_217580:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((SP + 32), cpu->regs[21]);
    if ((cpu->regs[0])==0) goto L_2175a8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 32), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2175e4;
L_2175a8:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[19] = cpu->regs[19] + 48ULL;
    cpu->regs[20] = 0ULL;
L_2175b4:
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_LT) goto L_2175d0;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2175d0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])!=0) goto L_2175f8;
L_2175d8:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    goto L_2175b4;
L_2175e4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2175a8;
    cpu->regs[30] = PB_BASE + 0x2175f4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2175a8;
L_2175f8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_2175d8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2175d8;
    cpu->regs[30] = PB_BASE + 0x217614ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2175d8;
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_217684;
    cpu->regs[20] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[5];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[1] = 56ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x217658ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_2176a4;
    PB_STRW((cpu->regs[0] + 40), cpu->regs[22]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[23]);
    cpu->regs[1] = 2ULL;
    PB_STRW((cpu->regs[0] + 48), cpu->regs[20]); PB_STRW((cpu->regs[0] + 48) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_217678:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_217684:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[1] + 2304ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x21769cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_217678;
L_2176a4:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_217678;
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
    if (FLAG_EQ) goto L_2178a0;
L_2176dc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2178ec;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_2178d0;
L_217700:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x21770cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1f2228ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21784c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_2178f8;
L_21772c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2178c0;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[0] = 8ULL;
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x217744ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_217830;
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_2178ac;
    cpu->regs[25] = 0ULL;
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[27] = 1ULL;
L_217760:
    cpu->regs[1] = 12ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21776cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[1])!=0) goto L_2177f4;
L_217778:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[26]);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x217788ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_217874;
L_217790:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[24]));
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_GT) goto L_217818;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2177a4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x2177c0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x118accULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    if ((cpu->regs[0])==0) goto L_217854;
L_2177dc:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_2177e4:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_2177f4:
    cpu->regs[30] = PB_BASE + 0x2177f8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1f2228ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_217778;
    FLAG_CMP(cpu->regs[27], cpu->regs[25]);
    if (FLAG_EQ) goto L_217860;
L_217808:
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[25] << 3)), cpu->regs[22]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_217760;
L_217818:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_217790;
L_217830:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x21783cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_21784c:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_217854:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    goto L_2177dc;
L_217860:
    cpu->regs[27] = cpu->regs[27] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[27] << 3;
    cpu->regs[30] = PB_BASE + 0x217870ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])!=0) goto L_217904;
L_217874:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x21787cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x217888ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_21784c;
L_2178a0:
    cpu->regs[30] = PB_BASE + 0x2178a4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    goto L_2176dc;
L_2178ac:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_21784c;
L_2178c0:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_21784c;
L_2178d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2178d8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_217700;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_217854;
L_2178ec:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[0] = 0ULL;
    goto L_2177e4;
L_2178f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x217900ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_21772c;
L_217904:
    cpu->regs[20] = cpu->regs[0];
    goto L_217808;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_217988;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[6];
    PB_LDR(cpu->regs[0], (SP + 80));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[4];
    cpu->regs[21] = cpu->regs[7];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[2];
    cpu->regs[23] = cpu->regs[5];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[1];
    cpu->regs[25] = cpu->regs[3];
    cpu->regs[1] = 56ULL;
    cpu->regs[30] = PB_BASE + 0x217954ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_2179a8;
    cpu->regs[1] = 5ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[26]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[24]); PB_STR((cpu->regs[0] + 24) + 8, cpu->regs[25]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[22]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[23]);
    PB_STRW((cpu->regs[0] + 48), cpu->regs[20]); PB_STRW((cpu->regs[0] + 48) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_217980:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_217988:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[1] + 2352ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2179a0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_217980;
L_2179a8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_217980;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_GT) goto L_217a40;
    if ((cpu->regs[0])==0) goto L_217a88;
    cpu->regs[0] = 0ULL;
    cpu->regs[19] = 0ULL;
L_2179ec:
    cpu->regs[0] = cpu->regs[0] + 33ULL;
    cpu->regs[30] = PB_BASE + 0x2179f4ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xd8e60ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_217ae0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2392));
    cpu->regs[30] = PB_BASE + 0x217a08ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xd93e0ULL);
    cpu->regs[0] = cpu->regs[20] + cpu->regs[19];
    cpu->regs[1] = 18446744073709551615ULL;
    PB_STR((cpu->regs[20] + 16), cpu->regs[19]); PB_STR((cpu->regs[20] + 16) + 8, cpu->regs[1]);
    cpu->regs[2] = cpu->regs[21] + 32ULL;
    cpu->regs[1] = cpu->regs[19];
    PB_STRB((cpu->regs[0] + 32), 0ULL);
    cpu->regs[0] = cpu->regs[20] + 32ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 16));
    cpu->regs[30] = PB_BASE + 0x217a2cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x16bdc8ULL);
L_217a2c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_217a40:
    cpu->regs[2] = 9223372036854775807ULL;
    cpu->regs[2] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[2] / (int64_t)cpu->regs[1]) : 0);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LT) goto L_217a68;
    cpu->regs[19] = cpu->regs[1] * cpu->regs[0];
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_217abc;
L_217a5c:
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(34ULL)));
    if (FLAG_LS) goto L_2179ec;
L_217a68:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2392ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x217a84ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_217a2c;
L_217a88:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2392));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_217ad4;
L_217a9c:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_217ab0;
    cpu->regs[20] = cpu->regs[21];
    goto L_217a2c;
L_217ab0:
    cpu->regs[20] = cpu->regs[21];
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_217a2c;
L_217abc:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2392));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_217a9c;
    goto L_217a5c;
L_217ad4:
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = 0ULL;
    goto L_2179ec;
L_217ae0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(51, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
    SP = SP - 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x217b20ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_217b58;
L_217b24:
    cpu->regs[0] = 0ULL;
L_217b28:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_217b50;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
L_217b50:
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x217b58ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x7c170ULL);
L_217b58:
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x217b60ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    if ((cpu->regs[0])==0) goto L_217b84;
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0x217b74ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x217b7cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x121fa0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_217b94;
L_217b84:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x217b8cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x121f40ULL);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_217b24;
L_217b94:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_217ba8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_217bb4;
L_217ba8:
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = 1ULL;
    goto L_217b28;
L_217bb4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x217bbcULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_217ba8;
}
