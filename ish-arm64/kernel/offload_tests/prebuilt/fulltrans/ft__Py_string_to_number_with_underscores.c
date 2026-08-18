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

void ft__Py_string_to_number_with_underscores(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 95ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[24] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1fe844ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7b3e0ULL);
    if ((cpu->regs[0])!=0) goto L_1fe86c;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[16] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1fe86c:
    cpu->regs[0] = cpu->regs[20] + 1ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x1fe878ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fe964;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[4] = 0ULL;
L_1fe88c:
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[1];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fe930;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_EQ) goto L_1fe918;
    PB_STRB(cpu->regs[3], cpu->regs[0]); cpu->regs[3] += 1;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(95ULL)));
    if (FLAG_EQ) goto L_1fe8c0;
L_1fe8ac:
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 0));
L_1fe8b0:
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[4] = cpu->regs[0];
    goto L_1fe88c;
L_1fe8c0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 48ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_1fe8ac;
L_1fe8d0:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1fe8d8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 3248ULL;
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fe8fcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1fe8fc:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1fe918:
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 48ULL));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(9ULL)));
    if (FLAG_LS) goto L_1fe8b0;
    goto L_1fe8d0;
L_1fe930:
    cpu->regs[19] = cpu->regs[19] + cpu->regs[20];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(95ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_1fe8d0;
    cpu->regs[2] = cpu->regs[24];
    PB_STRB((cpu->regs[1] + 0), 0ULL);
    cpu->regs[1] = cpu->regs[1] - cpu->regs[25];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1fe954ULL; PB_CALL(5, cpu, tlb, cpu->regs[21]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1fe960ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_1fe8fc;
L_1fe964:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
    /* nop */
    SP = SP - 160ULL;
    cpu->regs[5] = cpu->tls_ptr;
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 56), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1fe9d0ULL; PB_CALL(8, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[21], (cpu->regs[5] + cpu->regs[0]));
    if ((cpu->regs[1])==0) goto L_1fea18;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1febac;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 160ULL;
    goto L_1feda0;
L_1fea18:
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[2] & 9223372036854775807ULL;
    cpu->regs[23] = cpu->regs[24];
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    if ((cpu->regs[4])!=0) goto L_1feba0;
L_1fea2c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[26] = cpu->regs[0] + 24ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 16));
    if ((cpu->regs[23])==0) goto L_1feb54;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LT) { FLAG_CMP(cpu->regs[25], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_1feaac;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[24] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[23], (cpu->regs[20] + -8));
    cpu->regs[2] += -8; PB_STR(cpu->regs[2], cpu->regs[0]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1fea68ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe742cULL);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((cpu->regs[20] + -8), cpu->regs[23]);
L_1fea70:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1febbc;
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 160ULL;
    return;
L_1feaac:
    cpu->regs[0] = cpu->regs[23] + cpu->regs[25];
    cpu->regs[22] = SP + 16ULL;
    FLAG_CMP(cpu->regs[0], 5ULL);
    if (FLAG_GT) goto L_1febf0;
L_1feabc:
    PB_STR((SP + 144), cpu->regs[27]);
    cpu->regs[2] = cpu->regs[25] << 3;
    FLAG_CMP(cpu->regs[22], cpu->regs[26]);
    if (FLAG_LO) goto L_1febe0;
    if (FLAG_LS) goto L_1feadc;
    cpu->regs[0] = cpu->regs[26] + cpu->regs[2];
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_LO) goto L_1febdc;
L_1feadc:
    cpu->regs[27] = cpu->regs[22] + cpu->regs[2];
L_1feae0:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1feaf0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[4], (SP + 8));
    cpu->regs[2] = cpu->regs[23] << 3;
    FLAG_CMP(cpu->regs[27], cpu->regs[20]);
    if (FLAG_LO) goto L_1febd0;
    if (FLAG_LS) goto L_1feb10;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[2];
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_LO) goto L_1febdc;
L_1feb10:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[27];
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1feb20ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[4], (SP + 8));
    cpu->regs[3] = cpu->regs[24] + cpu->regs[25];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1feb38ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe742cULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = SP + 16ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_NE) goto L_1febc4;
L_1feb48:
    PB_LDR(cpu->regs[27], (SP + 144));
    cpu->regs[22] = cpu->regs[19];
    goto L_1fea70;
L_1feb54:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1febbc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[3] = cpu->regs[25];
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    cpu->regs[2] = cpu->regs[26];
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    SP = SP + 160ULL;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0xe742cULL); return; };
L_1feba0:
    PB_LDR(cpu->regs[23], (cpu->regs[4] + 16));
    cpu->regs[23] = cpu->regs[24] + cpu->regs[23];
    goto L_1fea2c;
L_1febac:
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x1febbcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1febbc:
    PB_STR((SP + 144), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x1febc4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1febc4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1febccULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_1feb48;
L_1febd0:
    cpu->regs[0] = cpu->regs[27] + cpu->regs[2];
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HS) goto L_1feb10;
L_1febdc:
    __builtin_trap();
L_1febe0:
    cpu->regs[27] = cpu->regs[22] + cpu->regs[2];
    FLAG_CMP(cpu->regs[26], cpu->regs[27]);
    if (FLAG_HS) goto L_1feae0;
    __builtin_trap();
L_1febf0:
    cpu->regs[0] = cpu->regs[0] << 3;
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1febfcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 8));
    if ((cpu->regs[0])!=0) goto L_1feabc;
    cpu->regs[30] = PB_BASE + 0x1fec0cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_1fea70;
    SP = SP - 48ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2272));
L_1fec44:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_1fece0;
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + (cpu->regs[2] << 2)));
    if (((cpu->regs[2] >> 3) & 1)) goto L_1fed08;
L_1fec58:
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_1fec7c;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2272));
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + (cpu->regs[2] << 2)));
    if (((cpu->regs[2] >> 3) & 1)) goto L_1fec58;
L_1fec7c:
    cpu->regs[1] = SP;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fec88ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1fedc0ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_NE) goto L_1fece4;
    fr[31] = -1.0;
    FCMP(fr[0], fr[31]);
    if (FLAG_EQ) goto L_1fecd0;
L_1feca0:
    cpu->regs[30] = PB_BASE + 0x1feca4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe538cULL);
L_1feca4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1fed10;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_1fecd0:
    cpu->regs[30] = PB_BASE + 0x1fecd4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1feca0;
    cpu->regs[0] = 0ULL;
    goto L_1feca4;
L_1fece0:
    if (FLAG_NE) goto L_1fec58;
L_1fece4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3288ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fed00ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_1feca4;
L_1fed08:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_1fec44;
L_1fed10:
    cpu->regs[30] = PB_BASE + 0x1fed14ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x1fed38ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1fed40ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[30] = PB_BASE + 0x1fed48ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x1fed50ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1fed58ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fed64ULL; PB_CALL(29, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fed78;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fed84;
L_1fed78:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1fed84:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    /* nop */
    /* nop */
    /* nop */
L_1feda0:
    PB_STR((cpu->regs[1] + 56), 0ULL);
    cpu->regs[3] = cpu->regs[3] & 9223372036854775807ULL;
    { PB_CALL(31, cpu, tlb, PB_BASE + 0xea120ULL); return; };
    cpu->regs[2] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = cpu->regs[2] + 3288ULL;
    { PB_CALL(32, cpu, tlb, PB_BASE + 0x1ff168ULL); return; };
    /* nop */
    /* nop */
}
