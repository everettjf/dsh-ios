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

void ft_PyUnicode_Partition(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x1fca44ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fcc7c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x1fca54ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1fcc7c;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[28], (cpu->regs[19] + 16));
    cpu->regs[26] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    PB_LDR(cpu->regs[27], (cpu->regs[20] + 16));
    cpu->regs[23] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_GE) { FLAG_CMP(cpu->regs[27], cpu->regs[28]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_1fcd90;
    if (!((cpu->regs[1] >> 5) & 1)) goto L_1fcdd0;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[24] = cpu->regs[20] + 56ULL;
    cpu->regs[1] = cpu->regs[20] + 40ULL;
    cpu->regs[24] = (FLAG_EQ) ? cpu->regs[24] : cpu->regs[1];
L_1fcaa0:
    if (!((cpu->regs[0] >> 5) & 1)) goto L_1fcdd8;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[25] = cpu->regs[19] + 56ULL;
    cpu->regs[0] = cpu->regs[19] + 40ULL;
    cpu->regs[25] = (FLAG_EQ) ? cpu->regs[25] : cpu->regs[0];
L_1fcab4:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_NE) goto L_1fcc54;
L_1fcabc:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1fcbb8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_1fcd18;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_1fcd18;
    if ((cpu->regs[28])==0) goto L_1fcde0;
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1fcae0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fcc4c;
    cpu->regs[5] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1fcb04ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1236a4ULL);
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_1fcb70;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1fcb18ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe9b80ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[21] + 24), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1fce00;
L_1fcb28:
    cpu->regs[0] = cpu->regs[28] + cpu->regs[22];
    PB_STR((cpu->regs[21] + 32), cpu->regs[19]);
    cpu->regs[1] = cpu->regs[27] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1fcb3cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe9b80ULL);
    PB_STR((cpu->regs[21] + 40), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1fcb44ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1fcc38;
L_1fcb48:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[26])));
    if (FLAG_NE) goto L_1fcc84;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_1fcb5c:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1fcb70:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1fcb80;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_1fcb80:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8080));
    PB_STR((cpu->regs[21] + 24), cpu->regs[20]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_NE) goto L_1fce08;
    cpu->regs[1] = 24464ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    PB_STR((cpu->regs[21] + 32), cpu->regs[1]);
L_1fcba8:
    cpu->regs[2] = 24464ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    PB_STR((cpu->regs[21] + 40), cpu->regs[0]);
    goto L_1fcb48;
L_1fcbb8:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_1fcc9c;
    if ((cpu->regs[28])==0) goto L_1fcde0;
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1fcbccULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fcc4c;
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1fcbf0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x27b888ULL);
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_1fcb70;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1fcc04ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x212cecULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[21] + 24), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1fcc18;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_1fcc18:
    cpu->regs[0] = cpu->regs[28] + cpu->regs[22];
    PB_STR((cpu->regs[21] + 32), cpu->regs[19]);
    cpu->regs[1] = cpu->regs[27] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[0] << 2);
    cpu->regs[30] = PB_BASE + 0x1fcc2cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x212cecULL);
    PB_STR((cpu->regs[21] + 40), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1fcc34ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1fcb48;
L_1fcc38:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1fcc4c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1fce28;
L_1fcc4c:
    cpu->regs[21] = 0ULL;
    goto L_1fcb48;
L_1fcc54:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1fcc68ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x22e06cULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1fcabc;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_1fcc7c:
    cpu->regs[21] = 0ULL;
    goto L_1fcb5c;
L_1fcc84:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1fcc8cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1fcb5c;
L_1fcc9c:
    if ((cpu->regs[28])==0) goto L_1fcde0;
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1fcca8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fcc4c;
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1fccccULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x22e280ULL);
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_1fcb70;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1fcce0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x212fe0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[21] + 24), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1fccf4;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_1fccf4:
    cpu->regs[0] = cpu->regs[28] + cpu->regs[22];
    PB_STR((cpu->regs[21] + 32), cpu->regs[19]);
    cpu->regs[1] = cpu->regs[27] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[0] << 1);
    cpu->regs[30] = PB_BASE + 0x1fcd08ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x212fe0ULL);
    PB_STR((cpu->regs[21] + 40), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1fcd10ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1fcb48;
    goto L_1fcc38;
L_1fcd18:
    if ((cpu->regs[28])==0) goto L_1fcde0;
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1fcd24ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1fcc4c;
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1fcd48ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1236a4ULL);
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_1fcb70;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1fcd5cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xefdb0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[21] + 24), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1fcdc8;
L_1fcd6c:
    cpu->regs[0] = cpu->regs[28] + cpu->regs[22];
    PB_STR((cpu->regs[21] + 32), cpu->regs[19]);
    cpu->regs[1] = cpu->regs[27] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1fcd80ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xefdb0ULL);
    PB_STR((cpu->regs[21] + 40), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1fcd88ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1fcb48;
    goto L_1fcc38;
L_1fcd90:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[4] = 24464ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    cpu->regs[0] = 3ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[3] = cpu->regs[3] + cpu->regs[4];
    cpu->regs[2] = cpu->regs[3];
    { PB_CALL(25, cpu, tlb, PB_BASE + 0xe0f0cULL); return; };
L_1fcdc8:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
    goto L_1fcd6c;
L_1fcdd0:
    PB_LDR(cpu->regs[24], (cpu->regs[20] + 56));
    goto L_1fcaa0;
L_1fcdd8:
    PB_LDR(cpu->regs[25], (cpu->regs[19] + 56));
    goto L_1fcab4;
L_1fcde0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2736ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fcdfcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1fcb48;
L_1fce00:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
    goto L_1fcb28;
L_1fce08:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[3]);
    cpu->regs[3] = 24464ULL;
    cpu->regs[3] = cpu->regs[0] + cpu->regs[3];
    PB_STR((cpu->regs[21] + 32), cpu->regs[3]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 2ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1fcba8;
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_1fcba8;
L_1fce28:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1fce34ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1fcb48;
    /* nop */
    /* nop */
}
