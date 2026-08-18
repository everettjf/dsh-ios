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

void ft__PyObject_LookupAttr(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 168));
    if (!((cpu->regs[2] >> 28) & 1)) goto L_112464;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 144));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 4048));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_112348;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1122e8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1157e0ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_112320;
L_1122f0:
    cpu->regs[0] = 1ULL;
L_1122f4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_11245c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_112320:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x112334ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_1123d4;
L_112340:
    cpu->regs[0] = 0ULL;
    goto L_1122f4;
L_112348:
    cpu->regs[3] = PB_BASE + 0x124000ULL;
    cpu->regs[3] = cpu->regs[3] + 288ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_EQ) goto L_112398;
    cpu->regs[3] = PB_BASE + 0x11d000ULL;
    cpu->regs[3] = cpu->regs[3] + 744ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_112430;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x112380ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1157e0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1123e4;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_1122f4;
L_112398:
    cpu->regs[2] = SP + 4ULL;
    PB_STRW((SP + 4), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1123a4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x112810ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    PB_LDRW(cpu->regs[1], (SP + 4));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_112340;
    if ((cpu->regs[0])!=0) goto L_1122f0;
L_1123b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1123c4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_112484;
    cpu->regs[30] = PB_BASE + 0x1123ccULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = 0ULL;
    goto L_1122f4;
L_1123d4:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
    goto L_1122f4;
L_1123e4:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1123f4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11d330ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_112428;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x112410ULL; PB_CALL(8, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_112448;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    goto L_1122f4;
L_112428:
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_1122f0;
L_112430:
    if ((cpu->regs[2])==0) goto L_11248c;
L_112434:
    cpu->regs[30] = PB_BASE + 0x112438ULL; PB_CALL(9, cpu, tlb, cpu->regs[2]);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_112428;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_1123b4;
L_112448:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
    goto L_1122f4;
L_11245c:
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x112464ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c170ULL);
L_112464:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 24));
    cpu->regs[1] = cpu->regs[1] + 3808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x112480ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_STR((cpu->regs[21] + 0), 0ULL);
L_112484:
    cpu->regs[0] = 4294967295ULL;
    goto L_1122f4;
L_11248c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 64));
    if ((cpu->regs[0])==0) goto L_1124b0;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x11249cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1124c0;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 64));
    cpu->regs[0] = cpu->regs[19];
    goto L_112434;
L_1124b0:
    PB_STR((cpu->regs[21] + 0), 0ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_1122f4;
L_1124c0:
    PB_STR((cpu->regs[21] + 0), 0ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_1122f4;
L_1124d0:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_112808;
L_1124fc:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_11274c;
L_112508:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 40));
    if ((cpu->regs[20])==0) goto L_11252c;
L_112518:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1127ULL)));
    if (FLAG_EQ) goto L_112610;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[20])!=0) goto L_112518;
L_11252c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1127ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[22] = cpu->regs[21];
    cpu->regs[23] = 6000ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x112554ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1125fc;
L_11255c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_EQ) goto L_1127fc;
L_112570:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_112794;
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_11263c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[1] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[1] + 20) + 4);
    cpu->regs[30] = PB_BASE + 0x112598ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1124d0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_11266c;
L_1125a0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_112794;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1125b4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x112ac0ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_112728;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_112734;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GE) goto L_1126f8;
L_1125d8:
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1127ULL;
    cpu->regs[30] = PB_BASE + 0x1125f4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1080e0ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11255c;
L_1125fc:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_112624;
L_112610:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[1]);
L_112624:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_11263c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112644ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1127e8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[24])) << 3)));
    PB_LDRW(cpu->regs[26], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[27], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_112794;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112664ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1124d0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1125a0;
L_11266c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_112760;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(32ULL)));
    if (FLAG_NE) goto L_1125a0;
L_11268c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11269cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x112ac0ULL);
    cpu->regs[8] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1125a0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1126b0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1127d0;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[26];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x1126d4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1a5f40ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1127b8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_112734;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_GT) goto L_1125d8;
L_1126f8:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_112728:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1126f8;
L_112734:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_112624;
L_11274c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112754ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1127a0;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_112508;
L_112760:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112768ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_112788;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(32ULL)));
    if (FLAG_NE) goto L_1125a0;
    goto L_11268c;
L_112788:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
L_112794:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112734;
L_1127a0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112624;
L_1127b8:
    cpu->regs[30] = PB_BASE + 0x1127bcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1127dc;
L_1127c0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1126f8;
    goto L_112734;
L_1127d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1127c0;
L_1127dc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_112734;
L_1127e8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_112734;
L_1127fc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112804ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_112570;
L_112808:
    cpu->regs[30] = PB_BASE + 0x11280cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1124fc;
L_112810:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_112a60;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 168));
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    if (((cpu->regs[0] >> 1) & 1)) goto L_112958;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 264));
    if ((cpu->regs[0])==0) goto L_112990;
L_112850:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11285cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1129d4;
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL)); FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_EQ) goto L_1128c8;
    PB_LDR(cpu->regs[22], (cpu->regs[5] + 272));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[4]);
    if ((cpu->regs[22])==0) goto L_1128d0;
L_112880:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 280));
    if ((cpu->regs[0])==0) goto L_1129a8;
L_112888:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x112898ULL; PB_CALL(28, cpu, tlb, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1128b0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_112a84;
L_1128b0:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1128c8:
    PB_LDR(cpu->regs[22], (cpu->regs[5] + 272));
    if ((cpu->regs[22])!=0) goto L_112880;
L_1128d0:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1128dcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11293c;
L_1128e4:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_112a18;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 272));
    PB_STRW((cpu->regs[19] + 0), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 0));
    if (((cpu->regs[3] >> 31) & 1)) goto L_112910;
L_112904:
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[3]);
    if ((cpu->regs[3])==0) goto L_1129c0;
L_112910:
    if ((cpu->regs[21])==0) goto L_1128b0;
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x112924ULL; PB_CALL(30, cpu, tlb, cpu->regs[21]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_11293c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_112a90;
L_11293c:
    cpu->regs[19] = cpu->regs[20];
L_112940:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_112958:
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x11296cULL; PB_CALL(31, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[4], (cpu->regs[23] + 360));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[4] = cpu->regs[4] + (cpu->regs[4] << 2);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[4] << 3);
    cpu->regs[4] = cpu->regs[4] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 13272));
    if ((cpu->regs[0])!=0) goto L_112850;
L_112990:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x112998ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_112850;
    cpu->regs[19] = 0ULL;
    goto L_1128b0;
L_1129a8:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1129b4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1128e4;
    goto L_112888;
L_1129c0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1129d0ULL; PB_CALL(34, cpu, tlb, cpu->regs[1]);
    goto L_112910;
L_1129d4:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1129e0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_112a04;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_112a2c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 272));
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_112910;
L_112a04:
    if ((cpu->regs[22])==0) goto L_112a38;
    cpu->regs[0] = 1ULL;
    cpu->regs[19] = 0ULL;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_1128b0;
L_112a18:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 272));
    if (((cpu->regs[3] >> 31) & 1)) goto L_112910;
    goto L_112904;
L_112a2c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 272));
    goto L_112910;
L_112a38:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[3] = cpu->regs[24];
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 24));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + 224ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x112a5cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1128b0;
L_112a60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 24));
    cpu->regs[1] = cpu->regs[1] + 3808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x112a80ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1128b0;
L_112a84:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x112a8cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1128b0;
L_112a90:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x112a9cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_112940;
}
