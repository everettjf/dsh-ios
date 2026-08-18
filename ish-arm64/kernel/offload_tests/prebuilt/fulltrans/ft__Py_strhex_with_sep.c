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

void ft__Py_strhex_with_sep(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x22f26cULL); return; };
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x233080ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x16a2f0ULL);
    fr[31] = -1.0;
    FCMP(fr[0], fr[31]);
    if (FLAG_EQ) goto L_233118;
L_23308c:
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 4));
    cpu->regs[5] = 6ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[3] = 0ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[4] = ((cpu->regs[4] >> 3) & 0x1ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[1] = (FLAG_GE) ? cpu->regs[1] : cpu->regs[5];
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] << 2));
    cpu->regs[30] = PB_BASE + 0x2330b4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x225020ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_233110;
    cpu->regs[30] = PB_BASE + 0x2330c0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[20])!=0) goto L_2330f0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2330d0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe9b80ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
L_2330d4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2330dcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 0ULL;
L_2330e0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2330f0:
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x233100ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_2330d4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x233110ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_233110:
    cpu->regs[0] = 4294967295ULL;
    goto L_2330e0;
L_233118:
    cpu->regs[30] = PB_BASE + 0x23311cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_23308c;
    cpu->regs[0] = 4294967295ULL;
    goto L_2330e0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_HI) goto L_2331d0;
L_233150:
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_23317c;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = 0ULL;
L_233164:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_233200;
L_23317c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3360));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 3104ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x233198ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2331ec;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[19], 3ULL);
    if (FLAG_EQ) goto L_2331bc;
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_NE) goto L_2331c4;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 8));
    cpu->regs[4] = 0ULL;
    goto L_233164;
L_2331bc:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[4], (cpu->regs[20] + 8) + 8);
    goto L_233164;
L_2331c4:
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = 0ULL;
    goto L_233164;
L_2331d0:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3096ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2331e8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_233150;
L_2331ec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_233200:
    SP = SP - 112ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 8), cpu->regs[4]); PB_STR((SP + 8) + 8, cpu->regs[3]);
    PB_STR((SP + 24), cpu->regs[2]);
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x23323cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1b8040ULL);
    if ((cpu->regs[0])!=0) goto L_233364;
L_233240:
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_EQ) goto L_2334b0;
    if ((cpu->regs[1])!=0) goto L_2334d8;
L_233258:
    cpu->regs[1] = 0ULL;
L_23325c:
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_233270;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_233270:
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])!=0) goto L_233348;
L_233278:
    if ((cpu->regs[1])!=0) goto L_23349c;
L_23327c:
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (((cpu->regs[1] >> 31) & 1)) goto L_23332c;
L_233288:
    if (!((cpu->regs[1] >> 30) & 1)) goto L_2334b8;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[4]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_233440;
    PB_STR((SP + 16), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x2332a0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_2332b8;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_2332b8:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_STR((SP + 24), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[1])!=0) goto L_2332d0;
    cpu->regs[30] = PB_BASE + 0x2332ccULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x121b20ULL);
    PB_STR((SP + 8), cpu->regs[0]);
L_2332d0:
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x2332dcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1e68c0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2332f4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1b8380ULL);
    cpu->regs[21] = cpu->regs[0];
L_2332f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_23335c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_23332c:
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 168));
    if (!((cpu->regs[5] >> 30) & 1)) goto L_233288;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0x233344ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x26c900ULL);
    goto L_2332d0;
L_233348:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_233278;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
    goto L_233278;
L_23335c:
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x233364ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_233364:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3144));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[22] = cpu->regs[20] + 72ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x233380ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x121d90ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & cpu->regs[21]));
    if (((cpu->regs[0] >> 0) & 1)) goto L_23357c;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2816));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3840));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_23350c;
    cpu->regs[2] = cpu->tls_ptr;
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x2333c0ULL; PB_CALL(20, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[4], (SP + 8)); PB_LDR(cpu->regs[3], (SP + 8) + 8);
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[24], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[5], (cpu->regs[24] + 56));
    PB_LDR(cpu->regs[23], (cpu->regs[5] + 0));
    PB_STR((cpu->regs[22] + 8), cpu->regs[23]);
    PB_STR((cpu->regs[5] + 0), cpu->regs[22]);
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[20] + 67),&_s,1); cpu->regs[21] = (uint64_t)(int64_t)_s; } while(0);
    PB_STRB((cpu->regs[20] + 67), 0ULL);
    cpu->regs[30] = PB_BASE + 0x2333f0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x233200ULL);
    PB_STRB((cpu->regs[20] + 67), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 56));
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]);
    PB_STR((cpu->regs[22] + 8), 0ULL);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
L_233408:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_23341c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_233490;
L_23341c:
    if ((cpu->regs[21])!=0) goto L_2332f8;
L_233420:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x233438ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1b8380ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_2332f8;
L_233440:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 3256ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x233458ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_233458:
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_23347c;
L_233464:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x23346cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x233474ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18d760ULL);
L_233474:
    cpu->regs[21] = 0ULL;
    goto L_2332f8;
L_23347c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_233464;
    cpu->regs[30] = PB_BASE + 0x23348cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_233464;
L_233490:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x233498ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_23341c;
L_23349c:
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_23327c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
    goto L_23327c;
L_2334b0:
    PB_STR((SP + 8), 0ULL);
    goto L_233258;
L_2334b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2334d4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_233458;
L_2334d8:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2432));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_23325c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3200ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x233508ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2332f8;
L_23350c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 59200ULL;
    cpu->regs[2] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x233528ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2335b4;
    PB_LDR(cpu->regs[22], (SP + 32));
    if ((cpu->regs[22])==0) goto L_2335d8;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[20] + 67),&_s,1); cpu->regs[21] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[22];
    PB_STRB((cpu->regs[20] + 67), 0ULL);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[3], (SP + 8)); PB_LDR(cpu->regs[2], (SP + 8) + 8);
    cpu->regs[30] = PB_BASE + 0x233554ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1987c8ULL);
    PB_STRB((cpu->regs[20] + 67), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_233408;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_233408;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x233578ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_233408;
L_23357c:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[20] + 67),&_s,1); cpu->regs[21] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[19];
    PB_STRB((cpu->regs[20] + 67), 0ULL);
    cpu->regs[30] = PB_BASE + 0x23358cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x27ff40ULL);
    PB_STRB((cpu->regs[20] + 67), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2335a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2335f8;
L_2335a8:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_233240;
    goto L_233420;
L_2335b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_233474;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_233474;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2335d4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2332f8;
L_2335d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_233240;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_233240;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2335f4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_233240;
L_2335f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x233600ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2335a8;
}
