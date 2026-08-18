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

void ft_PyObject_IsSubclass(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x136280ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[2] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[4];
    goto L_1362a0;
    /* nop */
    /* nop */
    /* nop */
L_1362a0:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3216));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_136398;
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_EQ) goto L_136380;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_13651c;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_13651c;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 344));
    if ((cpu->regs[0])==0) goto L_136364;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[21] = 0ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_136384;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_136380;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_136384;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_136380;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_13635c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 40));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_136380;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_13635c;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[2] = 3ULL;
L_136344:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + (cpu->regs[2] << 3)));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[3]);
    if (FLAG_EQ) goto L_136380;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_136344;
L_13635c:
    cpu->regs[21] = 0ULL;
    goto L_136384;
L_136364:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 256));
    if ((cpu->regs[20])==0) goto L_1364ec;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_NE) goto L_136364;
    /* nop */
    /* nop */
    /* nop */
L_136380:
    cpu->regs[21] = 1ULL;
L_136384:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_136398:
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x495000ULL;
    cpu->regs[0] = cpu->regs[0] + 576ULL;
    cpu->regs[0] = cpu->regs[0] + 2536ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_1364e4;
L_1363b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_136418;
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 3176ULL;
    cpu->regs[30] = PB_BASE + 0x1363ccULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_136514;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[19] = cpu->regs[19] + 24ULL;
    cpu->regs[23] = 0ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[19] + -8));
L_1363e0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    FLAG_CMP(cpu->regs[23], cpu->regs[24]);
    if (FLAG_GE) goto L_1364b4;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + (cpu->regs[23] << 3)));
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1363fcULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1362a0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1363e0;
L_136404:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[22] + 36), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_136384;
L_136418:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 33488ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x136430ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xed124ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1364bc;
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 3176ULL;
    cpu->regs[30] = PB_BASE + 0x136448ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_136500;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x136458ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[22] + 36), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_136484;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_136484;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x136484ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_136484:
    if ((cpu->regs[19])==0) goto L_136514;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x136490ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_136384;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_136384;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1364b0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_136384;
L_1364b4:
    cpu->regs[21] = 0ULL;
    goto L_136404;
L_1364bc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 96));
    if ((cpu->regs[0])==0) goto L_1364cc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_136514;
L_1364cc:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x1c11e0ULL); return; };
L_1364e4:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    goto L_1363b0;
L_1364ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3488));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    cpu->regs[21] = (FLAG_EQ) ? 1 : 0;
    goto L_136384;
L_136500:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_136514;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_136534;
L_136514:
    cpu->regs[21] = 4294967295ULL;
    goto L_136384;
L_13651c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x7c5acULL); return; };
L_136534:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x136540ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_136384;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[2] >> 2) & 0x7ULL)));
    cpu->regs[3] = ((uint32_t)(((cpu->regs[2] >> 5) & 0x1ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_13656c;
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_136590;
    if (!((cpu->regs[2] >> 6) & 1)) goto L_136584;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 40));
    return;
L_13656c:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_13659c;
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_1365ac;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 2)));
L_136580:
    return;
L_136584:
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[1]));
L_13658c:
    return;
L_136590:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + cpu->regs[1]));
    goto L_13658c;
L_13659c:
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_1365c4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 1)));
L_1365a8:
    return;
L_1365ac:
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 2)));
    goto L_136580;
L_1365c4:
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 1)));
    goto L_1365a8;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_136678;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2744));
    cpu->regs[30] = PB_BASE + 0x136608ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_136688;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[1] + 16), 0ULL);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_136690;
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x136634ULL; PB_CALL(14, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + -8));
    PB_STRW((cpu->regs[19] + 0), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[0] = cpu->regs[1] - 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 208));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    PB_STR((cpu->regs[1] + 24), cpu->regs[19]);
    cpu->regs[2] = cpu->regs[2] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[1] + -16), cpu->regs[3]); PB_STR((cpu->regs[1] + -16) + 8, cpu->regs[2]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[0]);
L_136668:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_136678:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 3233ULL;
    cpu->regs[0] = cpu->regs[0] + 224ULL;
    cpu->regs[30] = PB_BASE + 0x136688ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_136688:
    cpu->regs[1] = 0ULL;
    goto L_136668;
L_136690:
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1366a4ULL; PB_CALL(16, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + -8));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[2] & 3ULL;
    cpu->regs[3] = cpu->regs[1] - 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 208));
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 8));
    PB_STR((cpu->regs[1] + 24), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[5];
    PB_STR((cpu->regs[5] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[1] + -16), cpu->regs[4]); PB_STR((cpu->regs[1] + -16) + 8, cpu->regs[0]);
    PB_STR((cpu->regs[4] + 8), cpu->regs[3]);
    goto L_136668;
    /* nop */
    /* nop */
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_13673c;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_GE) goto L_136724;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[2] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[2] << 3)));
    PB_STR((cpu->regs[1] + 16), cpu->regs[3]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_136720;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
L_136720:
    return;
L_136724:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[1] + 24), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_13673c;
    cpu->regs[1] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_136744;
L_13673c:
    cpu->regs[0] = 0ULL;
    return;
L_136744:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x136750ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + -16)); PB_LDR(cpu->regs[2], (cpu->regs[0] + -16) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    PB_STR((cpu->regs[3] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_1367a8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1367b8;
L_1367a8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(18, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
L_1367b8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1367a8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1367d0ULL; PB_CALL(19, cpu, tlb, cpu->regs[1]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(20, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_1368ac;
    cpu->regs[25] = 26565ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = 51847ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = 60239ULL;
    cpu->regs[25] = (cpu->regs[25] & ~(0xffffULL << 16)) | ((0x1656ULL & 0xffff) << 16);
    cpu->regs[23] = (cpu->regs[23] & ~(0xffffULL << 16)) | ((0x27d4ULL & 0xffff) << 16);
    cpu->regs[22] = (cpu->regs[22] & ~(0xffffULL << 16)) | ((0x85ebULL & 0xffff) << 16);
    cpu->regs[25] = (cpu->regs[25] & ~(0xffffULL << 32)) | ((0xeb2fULL & 0xffff) << 32);
    cpu->regs[23] = (cpu->regs[23] & ~(0xffffULL << 32)) | ((0xae3dULL & 0xffff) << 32);
    cpu->regs[22] = (cpu->regs[22] & ~(0xffffULL << 32)) | ((0x79b1ULL & 0xffff) << 32);
    cpu->regs[21] = cpu->regs[0] + 24ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[25] = (cpu->regs[25] & ~(0xffffULL << 48)) | ((0x27d4ULL & 0xffff) << 48);
    cpu->regs[23] = (cpu->regs[23] & ~(0xffffULL << 48)) | ((0xc2b2ULL & 0xffff) << 48);
    cpu->regs[22] = (cpu->regs[22] & ~(0xffffULL << 48)) | ((0x9e37ULL & 0xffff) << 48);
L_13683c:
    PB_LDR(cpu->regs[24], (cpu->regs[21] + (cpu->regs[19] << 3)));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[26], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 120));
    if ((cpu->regs[1])==0) goto L_1368c0;
L_136850:
    cpu->regs[30] = PB_BASE + 0x136854ULL; PB_CALL(21, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1368d4;
    cpu->regs[0] = cpu->regs[0] * cpu->regs[23] + cpu->regs[25];
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[0] = ror64(cpu->regs[0], 33);
    cpu->regs[25] = cpu->regs[0] * cpu->regs[22];
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_NE) goto L_13683c;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_13687c:
    cpu->regs[0] = 46262ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x1663ULL & 0xffff) << 16);
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 32)) | ((0xeb2fULL & 0xffff) << 32);
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x27d4ULL & 0xffff) << 48);
    cpu->regs[0] = cpu->regs[20] ^ cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[25];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1368e4;
L_13689c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1368ac:
    cpu->regs[25] = 26565ULL;
    cpu->regs[25] = (cpu->regs[25] & ~(0xffffULL << 16)) | ((0x1656ULL & 0xffff) << 16);
    cpu->regs[25] = (cpu->regs[25] & ~(0xffffULL << 32)) | ((0xeb2fULL & 0xffff) << 32);
    cpu->regs[25] = (cpu->regs[25] & ~(0xffffULL << 48)) | ((0x27d4ULL & 0xffff) << 48);
    goto L_13687c;
L_1368c0:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1368c8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])==0) goto L_1368f0;
L_1368cc:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1368d4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x23d444ULL);
L_1368d4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_13689c;
L_1368e4:
    cpu->regs[0] = 19412ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x5c2aULL & 0xffff) << 16);
    goto L_13689c;
L_1368f0:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1368f8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1368d4;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 120));
    if ((cpu->regs[1])==0) goto L_1368cc;
    cpu->regs[0] = cpu->regs[24];
    goto L_136850;
    cpu->regs[0] = 25632ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0xfca8ULL & 0xffff) << 16);
    return;
    /* nop */
}
