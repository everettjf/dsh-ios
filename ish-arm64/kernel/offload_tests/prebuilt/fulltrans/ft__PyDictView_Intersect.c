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

void ft__PyDictView_Intersect(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3096));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0xc5900ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c5924;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4024));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc5914ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c5924;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[0];
L_c5924:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_c5934;
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    goto L_c5938;
L_c5934:
    cpu->regs[19] = 0ULL;
L_c5938:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3672));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_c598c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5954ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x141d48ULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_LT) goto L_c598c;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = 47480ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[4];
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x13bfa0ULL); return; };
L_c598c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3096));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc599cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c59b4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4024));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc59b0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c59dc;
L_c59b4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_c59c4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    goto L_c59c8;
L_c59c4:
    cpu->regs[0] = 0ULL;
L_c59c8:
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_GE) goto L_c59dc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[0];
L_c59dc:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc59e4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c5ac4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc59f4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c5aa8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3096));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[23] = PB_BASE + 0x277000ULL;
    cpu->regs[23] = cpu->regs[23] + 128ULL;
    cpu->regs[30] = PB_BASE + 0xc5a14ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe270cULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x24f000ULL;
    cpu->regs[0] = cpu->regs[0] + 3696ULL;
    cpu->regs[23] = (FLAG_NE) ? cpu->regs[23] : cpu->regs[0];
L_c5a24:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc5a2cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    if ((cpu->regs[20])==0) goto L_c5a84;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5a40ULL; PB_CALL(11, cpu, tlb, cpu->regs[23]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_c5acc;
    if (FLAG_NE) goto L_c5a5c;
L_c5a4c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_c5a70;
    goto L_c5a24;
L_c5a5c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5a68ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x12b468ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c5a4c;
    goto L_c5acc;
L_c5a70:
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c5a24;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5a80ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c5a24;
L_c5a84:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c5aa0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c5aa0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc5aa0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c5aa0:
    cpu->regs[30] = PB_BASE + 0xc5aa4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_c5b24;
L_c5aa8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c5ac4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c5ac4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5ac4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c5ac4:
    cpu->regs[19] = 0ULL;
    goto L_c5b24;
L_c5acc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c5ae8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c5ae8;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc5ae8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c5ae8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c5b04;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c5b04;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5b04ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c5b04:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c5ac4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c5ac4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc5b20ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c5ac4;
L_c5b24:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_c5b3c:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_c5b6c;
L_c5b64:
    cpu->regs[20] = 0ULL;
    goto L_c5c4c;
L_c5b6c:
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3792));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xc5b84ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c5bd0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5b90ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe1564ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c5ba0;
L_c5b98:
    cpu->regs[20] = 4294967295ULL;
    goto L_c5c4c;
L_c5ba0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc5bacULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x12b468ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c5c4c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c5c4c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc5bccULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c5c4c;
L_c5bd0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    cpu->regs[22] = PB_BASE + 0x2a6000ULL;
    cpu->regs[23] = cpu->tls_ptr;
    cpu->regs[22] = cpu->regs[22] + 3032ULL;
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
L_c5be8:
    FLAG_CMP(cpu->regs[20], cpu->regs[24]);
    if (FLAG_GE) goto L_c5b64;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 80));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xc5c04ULL; PB_CALL(24, cpu, tlb, cpu->regs[3]);
    cpu->regs[25] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[20] << 3);
    PB_LDR(cpu->regs[26], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0xc5c1cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xea32cULL);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[26];
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_c5b98;
    cpu->regs[30] = PB_BASE + 0xc5c30ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xc5b3cULL);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 36), cpu->regs[1]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c5be8;
    goto L_c5b98;
L_c5c4c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
}
