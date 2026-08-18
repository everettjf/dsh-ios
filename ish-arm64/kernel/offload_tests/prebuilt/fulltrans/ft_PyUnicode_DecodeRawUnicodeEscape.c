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

void ft_PyUnicode_DecodeRawUnicodeEscape(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x174de0ULL); return; };
    SP = SP - 80ULL;
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[3];
    if ((cpu->regs[3])!=0) goto L_22ca3c;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_LE) goto L_22caa0;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 3ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_22ca44;
L_22c9f4:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[5] + 0) + 8);
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_22ca30;
L_22ca00:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 16));
L_22ca04:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_LDR(cpu->regs[5], (SP + 40));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    cpu->regs[5] = cpu->regs[5] - cpu->regs[4]; FLAG_CMP(cpu->regs[5], 0);
    cpu->regs[4] = 0ULL;
    if (FLAG_NE) goto L_22ca9c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64));
    SP = SP + 80ULL;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x1f5d40ULL); return; };
L_22ca30:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    goto L_22ca04;
L_22ca3c:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    cpu->regs[19] = cpu->regs[2] + cpu->regs[19];
L_22ca44:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 2784ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22ca78ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_22c9f4;
L_22ca80:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_22cae0;
L_22ca9c:
    cpu->regs[30] = PB_BASE + 0x22caa0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_22caa0:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 2784ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22cad0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22ca80;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[5] + 0) + 8);
    goto L_22ca00;
L_22cae0:
    PB_LDR(cpu->regs[19], (SP + 64));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 32ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[4] = 29224ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[1] = SP;
    cpu->regs[2] = 1ULL;
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x22cb44ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_22cb6c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_22cb6c:
    cpu->regs[30] = PB_BASE + 0x22cb70ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
    SP = SP - 112ULL;
    cpu->regs[2] = cpu->tls_ptr;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22cbc0ULL; PB_CALL(8, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 96));
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_NE) goto L_22cc58;
L_22cbd0:
    if ((cpu->regs[0])==0) goto L_22ccfc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x22c000ULL;
    cpu->regs[0] = cpu->regs[0] + 2928ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_22ccfc;
L_22cbe8:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
L_22cbfc:
    cpu->regs[23] = 0ULL;
L_22cc00:
    cpu->regs[4] = 33440ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x22cc14ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_22ccb4;
L_22cc20:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_22ccf8;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_22cc58:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 96));
    if ((cpu->regs[2])==0) goto L_22cbd0;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    cpu->regs[2] = PB_BASE + 0x22c000ULL;
    cpu->regs[2] = cpu->regs[2] + 2928ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    cpu->regs[23] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[0])==0) goto L_22cccc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_22cccc;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_22cbe8;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x22cc94ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22cd08;
L_22cca0:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[23] = 1ULL;
    goto L_22cc00;
L_22ccb4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_22ccfc;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_22cd80;
L_22cccc:
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_22ccfc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 32728ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x22ccf0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[3] = cpu->regs[0];
    goto L_22cc20;
L_22ccf8:
    cpu->regs[30] = PB_BASE + 0x22ccfcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c170ULL);
L_22ccfc:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2400));
    goto L_22cc20;
L_22cd08:
    cpu->regs[6] = 32728ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[24] + cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x22cd1cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x250360ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_22cd94;
    if (FLAG_EQ) goto L_22cca0;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
    cpu->regs[5] = 32728ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[5];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x22cd4cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_22cc20;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    PB_LDR(cpu->regs[2], (SP + 8));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22cbfc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22cbfc;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x22cd78ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    goto L_22cbfc;
L_22cd80:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22cccc;
    cpu->regs[30] = PB_BASE + 0x22cd90ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22cccc;
L_22cd94:
    cpu->regs[3] = 0ULL;
    goto L_22cc20;
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[2] = cpu->tls_ptr;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22cdf0ULL; PB_CALL(17, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 96));
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_NE) goto L_22ce88;
L_22ce00:
    if ((cpu->regs[0])==0) goto L_22cf28;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[0] = PB_BASE + 0x22c000ULL;
    cpu->regs[0] = cpu->regs[0] + 3488ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_22cf28;
L_22ce18:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
L_22ce2c:
    cpu->regs[22] = 0ULL;
L_22ce30:
    cpu->regs[4] = 25656ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x22ce44ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_22cee4;
L_22ce50:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_22cf34;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_22ce88:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 96));
    if ((cpu->regs[2])==0) goto L_22ce00;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    cpu->regs[2] = PB_BASE + 0x22c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3488ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[0])==0) goto L_22cefc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_22cefc;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_22ce18;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x22cec4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22cf4c;
L_22ced0:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[22] = 1ULL;
    goto L_22ce30;
L_22cee4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_22cf28;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_22cf38;
L_22cefc:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_22cf28;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 31720ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x22cf20ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    goto L_22ce50;
L_22cf28:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    goto L_22ce50;
L_22cf34:
    cpu->regs[30] = PB_BASE + 0x22cf38ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c170ULL);
L_22cf38:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22cefc;
    cpu->regs[30] = PB_BASE + 0x22cf48ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22cefc;
L_22cf4c:
    cpu->regs[6] = 31720ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[24] + cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x22cf60ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x250360ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_22cfc4;
    if (FLAG_EQ) goto L_22ced0;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[5] = 31720ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[5];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x22cf90ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_22ce50;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[2], (SP + 8));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22ce2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22ce2c;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22cfbcULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    goto L_22ce2c;
L_22cfc4:
    cpu->regs[1] = 0ULL;
    goto L_22ce50;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    if ((cpu->regs[2])==0) goto L_22cfe8;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 2176ULL;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
L_22cfe8:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 2184ULL;
    { PB_CALL(27, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x22d018ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_22d060;
L_22d024:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    if ((cpu->regs[0])==0) goto L_22d04c;
    cpu->regs[30] = PB_BASE + 0x22d030ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1fd1e8ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_22d068;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_LT) goto L_22d070;
    cpu->regs[1] = cpu->regs[0] - 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[19];
L_22d048:
    PB_STR((cpu->regs[20] + 16), cpu->regs[1]);
L_22d04c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_22d054:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_22d060:
    cpu->regs[30] = PB_BASE + 0x22d064ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_22d024;
L_22d068:
    cpu->regs[0] = 0ULL;
    goto L_22d054;
L_22d070:
    cpu->regs[1] = 18446744073709551615ULL;
    goto L_22d048;
    /* nop */
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[5] = cpu->tls_ptr;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[6] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22d0b0ULL; PB_CALL(31, cpu, tlb, cpu->regs[2]);
    cpu->regs[3] = PB_BASE + 0x521000ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[3] = cpu->regs[3] + 272ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[5] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 2864ULL;
    cpu->regs[2] = cpu->regs[2] + 2192ULL;
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[5] = SP + 8ULL;
    cpu->regs[4] = SP + 16ULL;
    PB_STR((SP + 8), 0ULL);
    cpu->regs[30] = PB_BASE + 0x22d0ecULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x13eb20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22d184;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x22d0f8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x22d18cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_22d134;
L_22d100:
    cpu->regs[30] = PB_BASE + 0x22d104ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7aeb0ULL);
L_22d104:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_22d130;
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_22d130:
    cpu->regs[30] = PB_BASE + 0x22d134ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x7c170ULL);
L_22d134:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 96));
    if ((cpu->regs[1])==0) goto L_22d100;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])==0) goto L_22d100;
    PB_LDR(cpu->regs[0], (SP + 8));
    if ((cpu->regs[0])==0) goto L_22d184;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x22d160ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x121d80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22d184;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22d16cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_22d104;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_22d104;
L_22d184:
    cpu->regs[0] = 0ULL;
    goto L_22d104;
}
