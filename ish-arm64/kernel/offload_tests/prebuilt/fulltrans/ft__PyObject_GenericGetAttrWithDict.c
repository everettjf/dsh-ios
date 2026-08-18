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

void ft__PyObject_GenericGetAttrWithDict(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_115b74;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[25] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 168));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL)); FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_NE) goto L_115a80;
L_115828:
    if (((cpu->regs[0] >> 1) & 1)) goto L_1159dc;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 264));
    if ((cpu->regs[0])==0) goto L_115a14;
L_115834:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x115840ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_115a40;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_115a2c;
    PB_LDR(cpu->regs[23], (cpu->regs[4] + 272));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[3]);
    if ((cpu->regs[23])==0) goto L_115a40;
L_115864:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 280));
    if ((cpu->regs[0])!=0) goto L_11599c;
L_11586c:
    if ((cpu->regs[25])!=0) goto L_115930;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 168));
    if (!((cpu->regs[0] >> 4) & 1)) goto L_11590c;
    PB_LDR(cpu->regs[25], (cpu->regs[24] + -24));
    if (!((cpu->regs[25] >> 0) & 1)) goto L_115aec;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_115b98;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 880));
    cpu->regs[30] = PB_BASE + 0x1158a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1192ccULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_115af4;
L_1158ac:
    if ((cpu->regs[23])==0) goto L_115aac;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 8));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1158c0ULL; PB_CALL(3, cpu, tlb, cpu->regs[23]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[21] = cpu->regs[0];
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[22], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_115be8;
L_1158d0:
    if ((cpu->regs[19])==0) goto L_1158e8;
L_1158d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1158e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_115b20;
L_1158e8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_115a88;
L_1158f0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_1158f4:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_11590c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 288));
    FLAG_CMP(cpu->regs[2], 0ULL);
    if ((cpu->regs[2])==0) goto L_1158ac;
    if (FLAG_LT) goto L_115b48;
    cpu->regs[2] = cpu->regs[24] + cpu->regs[2]; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1158ac;
L_115928:
    PB_LDR(cpu->regs[25], (cpu->regs[2] + 0));
    if ((cpu->regs[25])==0) goto L_1158ac;
L_115930:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_115940;
    PB_STRW((cpu->regs[25] + 0), cpu->regs[0]);
L_115940:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x11594cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_115a48;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_115968;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_115bd4;
L_115968:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x11597cULL; PB_CALL(5, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])==0) goto L_1158ac;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_1158ac;
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_115b2c;
L_115994:
    cpu->regs[21] = 0ULL;
    goto L_1158d0;
L_11599c:
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 8));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1159acULL; PB_CALL(6, cpu, tlb, cpu->regs[23]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[21] = cpu->regs[0];
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[22], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1158d4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1159ccULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1159d4;
    cpu->regs[30] = PB_BASE + 0x1159d4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_1159d4:
    cpu->regs[21] = 0ULL;
    goto L_1158d4;
L_1159dc:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1159f0ULL; PB_CALL(9, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 360));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    cpu->regs[3] = cpu->regs[3] + (cpu->regs[3] << 2);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[3] << 3);
    cpu->regs[3] = cpu->regs[3] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 13272));
    if ((cpu->regs[0])!=0) goto L_115834;
L_115a14:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x115a1cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_115834;
L_115a24:
    cpu->regs[21] = 0ULL;
    goto L_1158e8;
L_115a2c:
    PB_LDR(cpu->regs[23], (cpu->regs[4] + 272));
    if ((cpu->regs[23])!=0) goto L_115864;
    /* nop */
    /* nop */
    /* nop */
L_115a40:
    cpu->regs[23] = 0ULL;
    goto L_11586c;
L_115a48:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_115b14;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1158d0;
L_115a60:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1158d0;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x115a7cULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    goto L_1158d0;
L_115a80:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[4]);
    goto L_115828;
L_115a88:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1158f0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x115aa4ULL; PB_CALL(12, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_1158f4;
L_115aac:
    cpu->regs[21] = cpu->regs[19];
    if ((cpu->regs[19])!=0) goto L_1158e8;
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_115a24;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[3] = cpu->regs[20];
    PB_LDR(cpu->regs[2], (cpu->regs[26] + 24));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + 3960ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x115adcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x115ae8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1a6548ULL);
    goto L_1158e8;
L_115aec:
    if ((cpu->regs[25])!=0) goto L_115930;
    goto L_1158ac;
L_115af4:
    cpu->regs[0] = cpu->regs[25] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 1));
    if ((cpu->regs[21])==0) goto L_1158ac;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1158d0;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_1158d0;
L_115b14:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_115a60;
    goto L_1158d0;
L_115b20:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x115b28ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18fc24ULL);
    goto L_1158e8;
L_115b2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x115b3cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_115994;
    cpu->regs[30] = PB_BASE + 0x115b44ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1158ac;
L_115b48:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32)); PB_LDR(cpu->regs[4], (cpu->regs[0] + 32) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 16));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[0] = (FLAG_LT) ? ((uint64_t)(-(int64_t)cpu->regs[1])) : cpu->regs[1];
    cpu->regs[1] = cpu->regs[3] + 7ULL;
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] & 18446744073709551608ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[2] = cpu->regs[24] + cpu->regs[0]; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_115928;
    goto L_1158ac;
L_115b74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    cpu->regs[1] = cpu->regs[1] + 3808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x115b94ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1158f4;
L_115b98:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x115bacULL; PB_CALL(19, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[3], (cpu->regs[24] + 8));
    cpu->regs[2] = cpu->regs[25] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 880));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x115bc4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x2024a4ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_115994;
    PB_STR((cpu->regs[24] + -24), cpu->regs[0]);
    goto L_115930;
L_115bd4:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x115be4ULL; PB_CALL(21, cpu, tlb, cpu->regs[1]);
    goto L_115968;
L_115be8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x115bf8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_115994;
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x115c04ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1158d0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_115d14;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_115c4c;
L_115c30:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 40));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 24));
    if (((cpu->regs[0] >> 1) & 1)) goto L_115cdc;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(24, cpu, tlb, PB_BASE + 0x115d60ULL); return; };
L_115c4c:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 344));
    if ((cpu->regs[2])==0) goto L_115d2c;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_LE) goto L_115cbc;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_EQ) goto L_115c30;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_115cbc;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 32));
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_EQ) goto L_115c30;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_115cbc;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_EQ) goto L_115c30;
    FLAG_CMP(cpu->regs[3], 3ULL);
    if (FLAG_EQ) goto L_115cbc;
    cpu->regs[2] = cpu->regs[2] + 24ULL;
    cpu->regs[4] = 3ULL;
L_115ca4:
    PB_LDR(cpu->regs[5], (cpu->regs[2] + (cpu->regs[4] << 3)));
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_EQ) goto L_115c30;
    FLAG_CMP(cpu->regs[3], cpu->regs[4]);
    if (FLAG_NE) goto L_115ca4;
L_115cbc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x115cc4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1985a8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_115c30;
L_115ccc:
    cpu->regs[0] = 0ULL;
L_115cd0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_115cdc:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[0] + 328ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 320ULL;
    cpu->regs[30] = PB_BASE + 0x115cf8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_115ccc;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 40));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(27, cpu, tlb, PB_BASE + 0x115d60ULL); return; };
L_115d14:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_115d24;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_115d24:
    cpu->regs[0] = cpu->regs[20];
    goto L_115cd0;
L_115d2c:
    cpu->regs[2] = cpu->regs[1];
L_115d30:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 256));
    if ((cpu->regs[2])==0) goto L_115d44;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_115c30;
    goto L_115d30;
L_115d44:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3488));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_115c30;
    goto L_115cbc;
    /* nop */
    /* nop */
}
