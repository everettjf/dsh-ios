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

void ft_PyDict_Items(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 96ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[20])==0) goto L_250214;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_250214;
    PB_STR((SP + 80), cpu->regs[23]);
L_250100:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
L_250104:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[23] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x250110ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_250240;
    cpu->regs[19] = 0ULL;
L_25011c:
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_LE) goto L_25013c;
    cpu->regs[30] = PB_BASE + 0x250128ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x187fc0ULL);
    if ((cpu->regs[0])==0) goto L_25022c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    PB_STR((cpu->regs[1] + (cpu->regs[19] << 3)), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_25011c;
L_25013c:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[23], cpu->regs[22]);
    if (FLAG_NE) goto L_2501f4;
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP;
    cpu->regs[11] = 0ULL;
    PB_STR((SP + 0), 0ULL);
L_25015c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x250168ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2501a4;
    PB_LDR(cpu->regs[5], (SP + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[21] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    PB_LDR(cpu->regs[6], (cpu->regs[4] + cpu->regs[11]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2501e4;
L_250184:
    PB_LDR(cpu->regs[4], (SP + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((cpu->regs[6] + 24), cpu->regs[5]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_2501dc;
L_250198:
    cpu->regs[11] = cpu->regs[11] + 8ULL;
    PB_STR((cpu->regs[6] + 32), cpu->regs[4]);
    goto L_25015c;
L_2501a4:
    PB_LDR(cpu->regs[23], (SP + 80));
L_2501a8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_2501ec;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_2501dc:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[0]);
    goto L_250198;
L_2501e4:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[0]);
    goto L_250184;
L_2501ec:
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x2501f4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2501f4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_250104;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_250104;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x250210ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_250100;
L_250214:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 3139ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x250228ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_2501a8;
L_25022c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_250240;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_25024c;
L_250240:
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[21] = 0ULL;
    goto L_2501a8;
L_25024c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x250254ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_250240;
    /* nop */
    /* nop */
    cpu->regs[1] = 2ULL;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0x221c28ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 29) & 1)) goto L_2502b8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 29) & 1)) goto L_2502b8;
    cpu->regs[30] = PB_BASE + 0x250294ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2502e0;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2502a4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x19eba8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2502c4;
L_2502a8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2502b8:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2400));
    goto L_2502a8;
L_2502c4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2502e0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2502e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2502e0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2502e0:
    cpu->regs[20] = 0ULL;
    goto L_2502a8;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 29568ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x250330ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_250358;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_250358:
    cpu->regs[30] = PB_BASE + 0x25035cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
L_250360:
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x2503a0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_250490;
    PB_LDR(cpu->regs[19], (SP + 16));
    if ((cpu->regs[19])==0) goto L_250498;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x2503c0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_25047c;
    PB_LDR(cpu->regs[20], (SP + 8));
    if ((cpu->regs[20])==0) goto L_250440;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x2503e0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_2503f8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2504a0;
L_2503f8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_25040c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_25045c;
L_25040c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_250478;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_250440:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_250454;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_250468;
L_250454:
    cpu->regs[21] = 1ULL;
    goto L_25040c;
L_25045c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x250464ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_25040c;
L_250468:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x250474ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_25040c;
L_250478:
    cpu->regs[30] = PB_BASE + 0x25047cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_25047c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_250490;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2504ac;
L_250490:
    cpu->regs[21] = 4294967295ULL;
    goto L_25040c;
L_250498:
    cpu->regs[21] = 0ULL;
    goto L_25040c;
L_2504a0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2504a8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2503f8;
L_2504ac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x2504b8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_25040c;
    /* nop */
    SP = SP - 128ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 56), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if ((cpu->regs[3])==0) goto L_25062c;
    PB_LDR(cpu->regs[21], (cpu->regs[3] + 16));
    cpu->regs[21] = cpu->regs[2] + cpu->regs[21];
    cpu->regs[20] = cpu->regs[21] - 1ULL;
L_250500:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[4] + 368ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 4ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x25052cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_25066c;
L_250534:
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 0));
    if ((cpu->regs[20])==0) goto L_2507bc;
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 8));
    if ((cpu->regs[22])==0) goto L_250698;
    cpu->regs[20] = cpu->regs[21] - 2ULL; FLAG_CMP(cpu->regs[20], 0);
    if (FLAG_EQ) goto L_25064c;
L_250550:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_25073c;
    cpu->regs[30] = PB_BASE + 0x25055cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_250660;
    cpu->regs[30] = PB_BASE + 0x250568ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_250788;
L_250574:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_250660;
L_25057c:
    cpu->regs[20] = cpu->regs[20] - 1ULL; FLAG_CMP(cpu->regs[20], 0);
    if (FLAG_NE) goto L_250740;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[19] = 0ULL;
L_250590:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2728));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x2505a4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11e0a4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_250668;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_250734;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_EQ) goto L_2506c0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2505d0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x136260ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_2506e0;
    if ((cpu->regs[19])!=0) goto L_2506a4;
L_2505e0:
    cpu->regs[19] = 0ULL;
L_2505e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_25068c;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    SP = SP + 128ULL;
    { PB_CALL(27, cpu, tlb, PB_BASE + 0x226c60ULL); return; };
L_25062c:
    cpu->regs[20] = cpu->regs[2] - 1ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_250690;
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[21] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 4ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LE) goto L_250534;
    goto L_250500;
L_25064c:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[21] = 1ULL;
    cpu->regs[19] = 0ULL;
    goto L_250590;
L_250660:
    cpu->regs[30] = PB_BASE + 0x250664ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_2507b4;
L_250668:
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
L_25066c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_2507d4;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
L_25068c:
    cpu->regs[30] = PB_BASE + 0x250690ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7c170ULL);
L_250690:
    cpu->regs[21] = cpu->regs[2];
    goto L_250500;
L_250698:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    goto L_250550;
L_2506a4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_250708;
    FLAG_CMP(cpu->regs[21], 2ULL);
    cpu->regs[0] = 2ULL;
    cpu->regs[21] = (FLAG_GE) ? cpu->regs[21] : cpu->regs[0];
    goto L_2505e4;
L_2506c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3400));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0));
L_2506cc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2506d4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x136260ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_250728;
L_2506e0:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 144ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x250700ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    goto L_25066c;
L_250708:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2505e0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2505e0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x250724ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2505e0;
L_250728:
    if ((cpu->regs[22])==0) goto L_250668;
    if ((cpu->regs[19])==0) goto L_2505e0;
    goto L_2506a4;
L_250734:
    PB_LDR(cpu->regs[22], (cpu->regs[24] + 8));
    goto L_2506cc;
L_25073c:
    cpu->regs[21] = 1ULL;
L_250740:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 24));
    if ((cpu->regs[23])==0) goto L_2507a0;
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_2507ac;
L_250750:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_250590;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[2] = cpu->regs[2] + 3888ULL;
    cpu->regs[1] = cpu->regs[1] + 112ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 3152ULL;
    cpu->regs[30] = PB_BASE + 0x250780ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x23b310ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    goto L_25066c;
L_250788:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_250574;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x25079cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_250574;
L_2507a0:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    goto L_250750;
L_2507ac:
    cpu->regs[19] = 0ULL;
    goto L_250590;
L_2507b4:
    cpu->regs[21] = 18446744073709551615ULL;
    goto L_25057c;
L_2507bc:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    cpu->regs[21] = 1ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[22] = cpu->regs[23];
    goto L_250590;
L_2507d4:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_250818;
L_250804:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(35, cpu, tlb, PB_BASE + 0x11ed08ULL); return; };
L_250818:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2ad000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1656ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x250830ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250804;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[3] = 0ULL;
    { PB_CALL(37, cpu, tlb, PB_BASE + 0x21ce90ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_250878;
L_250864:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    cpu->regs[2] = 4ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(38, cpu, tlb, PB_BASE + 0x11ed08ULL); return; };
L_250878:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 192ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x250890ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250864;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[3] = 4ULL;
    { PB_CALL(40, cpu, tlb, PB_BASE + 0x21ce90ULL); return; };
    cpu->regs[3] = 1ULL;
    { PB_CALL(41, cpu, tlb, PB_BASE + 0x21ce90ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_2508ec;
L_2508d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    cpu->regs[2] = 5ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(42, cpu, tlb, PB_BASE + 0x11ed08ULL); return; };
L_2508ec:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x28c000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1104ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x250904ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2508d8;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    cpu->regs[3] = 5ULL;
    { PB_CALL(44, cpu, tlb, PB_BASE + 0x21ce90ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    if ((cpu->regs[2])==0) goto L_2509b4;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x250950ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1754c4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2509ac;
L_250958:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LT) goto L_250978;
L_250964:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_250978:
    cpu->regs[1] = cpu->regs[19] + 24ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[21] << 3)));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x25098cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1fb9c0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_250958;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2509ac;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2509ac;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2509acULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2509ac:
    cpu->regs[20] = 0ULL;
    goto L_250964;
L_2509b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    { PB_CALL(48, cpu, tlb, PB_BASE + 0x1f2d20ULL); return; };
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 28776ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x250a10ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_250a38;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_250a38:
    cpu->regs[30] = PB_BASE + 0x250a3cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_250a68;
L_250a58:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(51, cpu, tlb, PB_BASE + 0x14e480ULL); return; };
L_250a68:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 200ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x250a80ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250a58;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_250ac8;
L_250ab8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(53, cpu, tlb, PB_BASE + 0x149684ULL); return; };
L_250ac8:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 208ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x250ae0ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250ab8;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_250b28;
L_250b18:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(55, cpu, tlb, PB_BASE + 0x1fbdc8ULL); return; };
L_250b28:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 216ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x250b40ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250b18;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
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
    cpu->regs[30] = PB_BASE + 0x250bb0ULL; PB_CALL(57, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 96));
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_EQ) goto L_250c68;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 96));
    if ((cpu->regs[0])==0) goto L_250c68;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 112));
    cpu->regs[0] = PB_BASE + 0x250000ULL;
    cpu->regs[0] = cpu->regs[0] + 2912ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[2])==0) goto L_250ca4;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 112));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_250ca4;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_250ce4;
L_250bf4:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
L_250c08:
    cpu->regs[22] = 0ULL;
L_250c0c:
    cpu->regs[4] = 34256ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x250c20ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_250c8c;
L_250c2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_250c64;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_250c64:
    cpu->regs[30] = PB_BASE + 0x250c68ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x7c170ULL);
L_250c68:
    if ((cpu->regs[2])==0) goto L_250c80;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 112));
    cpu->regs[0] = PB_BASE + 0x250000ULL;
    cpu->regs[0] = cpu->regs[0] + 2912ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_250bf4;
L_250c80:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2400));
    goto L_250c2c;
L_250c8c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_250c80;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_250cd0;
L_250ca4:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_250c80;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 32840ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x250cc8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[3] = cpu->regs[0];
    goto L_250c2c;
L_250cd0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_250ca4;
    cpu->regs[30] = PB_BASE + 0x250ce0ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_250ca4;
L_250ce4:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x250cecULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250d0c;
L_250cf8:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[22] = 1ULL;
    goto L_250c0c;
L_250d0c:
    cpu->regs[6] = 32840ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[24] + cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x250d20ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x250360ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_250d84;
    if (FLAG_EQ) goto L_250cf8;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[5] = 32840ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[5];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x250d50ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_250c2c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[2], (SP + 8));
    if (((cpu->regs[0] >> 31) & 1)) goto L_250c08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_250c08;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x250d7cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    goto L_250c08;
L_250d84:
    cpu->regs[3] = 0ULL;
    goto L_250c2c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_250db4;
L_250da4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(66, cpu, tlb, PB_BASE + 0x1b06e0ULL); return; };
L_250db4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 224ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x250dccULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250da4;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 29960ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x250e28ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_250e50;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_250e50:
    cpu->regs[30] = PB_BASE + 0x250e54ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 4ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[1] = cpu->regs[21] + 3208ULL;
    cpu->regs[30] = PB_BASE + 0x250e8cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_250efc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 16) + 8);
    cpu->regs[30] = PB_BASE + 0x250e9cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x11a700ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_250efc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[21] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0x250eb0ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x1b06e0ULL);
    if ((cpu->regs[0])==0) goto L_250ee0;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_250f04;
L_250ecc:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_250ee0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_250efc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_250efc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x250efcULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_250efc:
    cpu->regs[21] = 0ULL;
    goto L_250ecc;
L_250f04:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_250ecc;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x250f18ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_250ecc;
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[9] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[9], (cpu->regs[9] + 2592));
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 8));
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3672));
    FLAG_CMP(cpu->regs[7], cpu->regs[9]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[7], cpu->regs[8]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_250fa8;
L_250f50:
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 8));
    FLAG_CMP(cpu->regs[7], cpu->regs[9]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[7], cpu->regs[8]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_250f70;
L_250f60:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[5];
    goto L_250fcc;
L_250f70:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    cpu->regs[0] = cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x250f80ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250f60;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2592));
    cpu->regs[0] = cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x250f94ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250f60;
L_250f98:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_250fa8:
    cpu->regs[1] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x250fb4ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_250f50;
    cpu->regs[0] = cpu->regs[7];
    cpu->regs[1] = cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x250fc4ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_250f98;
    goto L_250f50;
L_250fcc:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x250fe4ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x1f2d20ULL);
    if ((cpu->regs[0])==0) goto L_25102c;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x250ff4ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x251048ULL);
    if ((cpu->regs[0])==0) goto L_251010;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_251034;
L_251000:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_251010:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_25102c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_25102c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x25102cULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_25102c:
    cpu->regs[19] = 0ULL;
    goto L_251000;
L_251034:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_251000;
    cpu->regs[30] = PB_BASE + 0x251044ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_251000;
L_251048:
    SP = SP - 128ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_EQ) goto L_251324;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2680));
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_EQ) goto L_2511f0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2592));
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], cpu->regs[6]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_2511a4;
L_2510b4:
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_2510c8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_2510c8:
    cpu->regs[23] = SP + 32ULL;
    cpu->regs[22] = SP + 16ULL;
L_2510d0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32)); PB_LDR(cpu->regs[1], (cpu->regs[20] + 32) + 8);
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2510e0ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x197144ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_251154;
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[24], (cpu->regs[0] + 0) + 8);
    PB_STR((SP + 8), cpu->regs[24]);
    PB_STR((SP + 24), cpu->regs[19]);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_251104;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[3]);
L_251104:
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x251114ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x1ac52cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2512e0;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_251134;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x251130ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xe8180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2512e0;
L_251134:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_2510d0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_2510d0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x251150ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2510d0;
L_251154:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_251168;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2511dc;
L_251168:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
L_251170:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_251178:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2512d0;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 128ULL;
    return;
L_2511a4:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x2511acULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2510b4;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x2511bcULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2510b4;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2511ccULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x1f2d20ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_25130c;
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    goto L_2510c8;
L_2511dc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2511e4ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    goto L_251170;
L_2511f0:
    cpu->regs[22] = SP + 16ULL;
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[23] = SP + 32ULL;
    cpu->regs[24] = SP + 24ULL;
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[25] = SP + 8ULL;
    goto L_251220;
L_25120c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_251220;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2512c4;
L_251220:
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x251238ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2512ac;
    PB_LDR(cpu->regs[19], (SP + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_251250;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_251250:
    PB_LDR(cpu->regs[26], (SP + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x251264ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x1ac52cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_251284;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_25120c;
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x251280ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xe8180ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_25120c;
L_251284:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_251298;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_251318;
L_251298:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    goto L_251178;
L_2512ac:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_251178;
L_2512c4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2512ccULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_251220;
L_2512d0:
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x2512e0ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2512e0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2512f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_25132c;
L_2512f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_251308;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_251338;
L_251308:
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
L_25130c:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    goto L_251178;
L_251318:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x251320ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_251298;
L_251324:
    cpu->regs[30] = PB_BASE + 0x251328ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x14d4e0ULL);
    goto L_251170;
L_25132c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x251334ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2512f4;
L_251338:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x251340ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    goto L_25130c;
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 29792ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x251390ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2513b8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_2513b8:
    cpu->regs[30] = PB_BASE + 0x2513bcULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    SP = SP - 48ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = 28832ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x251408ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_251430;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_251430:
    cpu->regs[30] = PB_BASE + 0x251434ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if ((cpu->regs[2])!=0) goto L_251568;
L_251470:
    PB_STR((SP + 48), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_GT) goto L_251544;
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 232ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[4] = SP;
    cpu->regs[30] = PB_BASE + 0x25149cULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_25155c;
L_2514a0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 888));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2514b0ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_25155c;
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_25153c;
L_2514c8:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[3] = 18446744073709551615ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    PB_STR((cpu->regs[19] + 16), cpu->regs[21]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[0]);
    PB_STR((cpu->regs[19] + 32), cpu->regs[3]);
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_2514f4;
    cpu->regs[30] = PB_BASE + 0x2514ecULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xe5240ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_251554;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
L_2514f4:
    cpu->regs[0] = PB_BASE + 0x251000ULL;
    cpu->regs[0] = cpu->regs[0] + 1412ULL;
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x251508ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xe1984ULL);
    PB_LDR(cpu->regs[21], (SP + 48));
L_25150c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_25154c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_25153c:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_2514c8;
L_251544:
    PB_STR((SP + 0), cpu->regs[19]);
    goto L_2514a0;
L_25154c:
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x251554ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x7c170ULL);
L_251554:
    cpu->regs[30] = PB_BASE + 0x251558ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_2514f4;
L_25155c:
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[19] = 0ULL;
    goto L_25150c;
L_251568:
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + 232ULL;
    cpu->regs[30] = PB_BASE + 0x251578ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_251470;
    cpu->regs[19] = 0ULL;
    goto L_25150c;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_2515bc;
L_25159c:
    cpu->regs[2] = cpu->regs[2] & 9223372036854775807ULL;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_NE) goto L_2515e8;
L_2515a8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_251608;
L_2515bc:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[0] = cpu->regs[0] + 232ULL;
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x2515d0ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x81c64ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_25159c;
L_2515d8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2515e8:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 232ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x251600ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2515d8;
    goto L_2515a8;
L_251608:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[23], 1ULL);
    if (FLAG_NE) goto L_25168c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    if (((cpu->regs[0] >> 63) & 1)) goto L_2516d0;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2640));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_2516d0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_2516d0;
    cpu->regs[0] = cpu->regs[19] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_251684;
L_25166c:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_251684:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_25166c;
L_25168c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x251698ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[0] + 24ULL;
    if ((cpu->regs[0])==0) goto L_251708;
L_2516a4:
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_GE) goto L_25166c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[22] << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[30] = PB_BASE + 0x2516c0ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    if ((cpu->regs[0])==0) goto L_2516ec;
    PB_STR((cpu->regs[24] + (cpu->regs[22] << 3)), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_2516a4;
L_2516d0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(115, cpu, tlb, PB_BASE + 0xe3ac0ULL); return; };
L_2516ec:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_251708;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_251708;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x251708ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_251708:
    cpu->regs[21] = 0ULL;
    goto L_25166c;
    { PB_CALL(117, cpu, tlb, PB_BASE + 0x208d40ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    { PB_CALL(118, cpu, tlb, PB_BASE + 0x208f60ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x251750ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 136));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_251788;
L_251760:
    if ((cpu->regs[21])!=0) goto L_25179c;
L_251764:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_2517c4;
L_251770:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 24) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(120, cpu, tlb, PB_BASE + 0x222760ULL); return; };
L_251788:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_251760;
    goto L_251764;
L_25179c:
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 248ULL;
    cpu->regs[30] = PB_BASE + 0x2517acULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_251764;
L_2517b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2517c4:
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 248ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x2517d8ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2517b0;
    goto L_251770;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x251800ULL; PB_CALL(123, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_251858;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2640));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_251860;
L_25181c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x25182cULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x7c1e0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_251844;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_251890;
L_251844:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_251854:
    PB_LDR(cpu->regs[21], (SP + 32));
L_251858:
    cpu->regs[20] = 0ULL;
    goto L_251844;
L_251860:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x251868ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_251880;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_25189c;
L_251880:
    if ((cpu->regs[21])==0) goto L_251854;
    cpu->regs[19] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_25181c;
L_251890:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x251898ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_251844;
L_25189c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2518a4ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_251880;
    { PB_CALL(128, cpu, tlb, PB_BASE + 0x222924ULL); return; };
    cpu->regs[7] = PB_BASE + 0x2b7000ULL;
    cpu->regs[4] = cpu->regs[7] + 1840ULL;
    cpu->regs[0] = cpu->regs[0] + 192ULL;
    cpu->regs[4] = cpu->regs[4] + 2064ULL;
    cpu->regs[6] = 0ULL;
L_2518c0:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_251910;
    PB_LDRB(cpu->regs[5], (cpu->regs[0] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[0] + 1));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | cpu->regs[6]));
    PB_LDRB(cpu->regs[5], (cpu->regs[4] + cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(135ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[3], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_2518ec;
    cpu->regs[0] = 1ULL;
    return;
L_2518ec:
    cpu->regs[8] = cpu->regs[7] + 1840ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] << 8));
    cpu->regs[8] = cpu->regs[8] + 2320ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(144ULL)));
    cpu->regs[6] = (FLAG_EQ) ? cpu->regs[3] : 0ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[8] + ((uint64_t)(uint32_t)(cpu->regs[5]))));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[3] << 1);
    goto L_2518c0;
L_251910:
    cpu->regs[0] = 0ULL;
    return;
    /* nop */
    /* nop */
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3736));
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[2];
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x251948ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_251b58;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_251b58;
    cpu->regs[0] = ((uint32_t)(cpu->regs[24] - 2ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_251b58;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2680));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 200));
    cpu->regs[30] = PB_BASE + 0x251980ULL; PB_CALL(130, cpu, tlb, cpu->regs[4]);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_251b3c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3736));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x251998ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0xe270cULL);
    PB_STRW((SP + 108), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_251ab0;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_251b04;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_EQ) goto L_251ab0;
L_2519b8:
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_251b64;
L_2519cc:
    PB_LDR(cpu->regs[20], (cpu->regs[23] + 48));
    PB_LDR(cpu->regs[19], (cpu->regs[25] + 48));
    PB_LDR(cpu->regs[26], (cpu->regs[23] + 88));
    PB_LDR(cpu->regs[27], (cpu->regs[25] + 88));
L_2519dc:
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[0] = cpu->regs[19] | cpu->regs[20];
    if ((cpu->regs[0])==0) goto L_251a74;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_251a70;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_251adc;
L_251a10:
    PB_LDR(cpu->regs[28], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[28] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_251afc;
L_251a20:
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x251a30ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_251ac4;
L_251a3c:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_251ae4;
L_251a44:
    if (((cpu->regs[21] >> 31) & 1)) goto L_251b7c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 88));
    FLAG_CMP(cpu->regs[26], cpu->regs[0]);
    if (FLAG_NE) goto L_251b18;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 88));
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_NE) goto L_251b18;
    if ((((uint32_t)(cpu->regs[21])))==0) goto L_251a70;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 16));
    goto L_2519dc;
L_251a70:
    PB_STRW((SP + 108), 0ULL);
L_251a74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3184));
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    PB_LDRW(cpu->regs[2], (SP + 108));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    cpu->regs[5] = (FLAG_NE) ? cpu->regs[5] : cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_251b44;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_251ab0:
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_251ac4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_251a3c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x251ad8ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_251a3c;
L_251adc:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[2]);
    goto L_251a10;
L_251ae4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_251a44;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x251af8ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_251a44;
L_251afc:
    PB_STRW((cpu->regs[28] + 0), cpu->regs[2]);
    goto L_251a20;
L_251b04:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_EQ) goto L_251ab0;
    goto L_2519b8;
L_251b18:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 1448ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x251b30ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_251b3c:
    cpu->regs[5] = 0ULL;
    goto L_251ab0;
L_251b44:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_251ab0;
L_251b58:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2400));
    goto L_251ab0;
L_251b64:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[5] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2519cc;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x251b78ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2519cc;
L_251b7c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_251ab0;
    SP = SP - 112ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[5], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_251cac;
    cpu->regs[0] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_251cac;
L_251bd4:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x251be0ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_251d40;
    cpu->regs[30] = PB_BASE + 0x251becULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_251d5c;
L_251bf8:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_251d40;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x251c08ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_251d1c;
    PB_STR((SP + 96), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    if (((cpu->regs[19] >> 63) & 1)) goto L_251d00;
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_HI) goto L_251cf4;
    cpu->regs[0] = cpu->regs[19] << 3;
    cpu->regs[30] = PB_BASE + 0x251c30ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[1] = 0ULL;
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_251cf4;
L_251c3c:
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_EQ) goto L_251c50;
    PB_STR((cpu->regs[20] + (cpu->regs[1] << 3)), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_251c3c;
L_251c50:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 304));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x251c60ULL; PB_CALL(141, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_251d30;
    PB_STR((cpu->regs[0] + 16), cpu->regs[21]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[20]);
    FLAG_CMP(cpu->regs[23], cpu->regs[19]);
    cpu->regs[1] = (FLAG_LT) ? 1 : 0;
    PB_STR((cpu->regs[0] + 32), 0ULL); PB_STR((cpu->regs[0] + 32) + 8, cpu->regs[19]);
    PB_LDR(cpu->regs[23], (SP + 96));
    PB_STRW((cpu->regs[0] + 48), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
L_251c80:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_251ce8;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_251cac:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[6] = 2ULL;
    cpu->regs[4] = cpu->regs[4] + 440ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x251cdcULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_251bd4;
    cpu->regs[0] = 0ULL;
    goto L_251c80;
L_251ce8:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x251cf4ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x7c170ULL);
L_251cf4:
    cpu->regs[30] = PB_BASE + 0x251cf8ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[23], (SP + 96));
    goto L_251d1c;
L_251d00:
    PB_LDR(cpu->regs[23], (SP + 96));
L_251d04:
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = cpu->regs[1] + 2912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x251d1cULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_251d1c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x251d24ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x18d760ULL);
L_251d24:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    cpu->regs[0] = 0ULL;
    goto L_251c80;
L_251d30:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x251d38ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 96));
    goto L_251d1c;
L_251d40:
    cpu->regs[30] = PB_BASE + 0x251d44ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_251d24;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x251d50ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_251d04;
    goto L_251d1c;
L_251d5c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_251bf8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x251d70ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_251bf8;
    /* nop */
    /* nop */
    /* nop */
    goto L_251d84;
L_251d84:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x251d9cULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x251da4ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x251dacULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_251db8;
    cpu->regs[30] = PB_BASE + 0x251db8ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_251db8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x251dc4ULL; PB_CALL(155, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_251dd8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_251de4;
L_251dd8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_251de4:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(156, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(157, cpu, tlb, PB_BASE + 0x243760ULL); return; };
    SP = SP - 32ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[4] = 31512ULL;
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
    cpu->regs[30] = PB_BASE + 0x251e4cULL; PB_CALL(158, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_251e74;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_251e74:
    cpu->regs[30] = PB_BASE + 0x251e78ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    SP = SP - 32ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[4] = 30864ULL;
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
    cpu->regs[30] = PB_BASE + 0x251ec4ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_251eec;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_251eec:
    cpu->regs[30] = PB_BASE + 0x251ef0ULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x7c170ULL);
    cpu->regs[2] = 0ULL;
    { PB_CALL(162, cpu, tlb, PB_BASE + 0x11ebb0ULL); return; };
    /* nop */
    /* nop */
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])!=0) goto L_251f30;
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[1] = cpu->regs[1] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x251f24ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_251f24:
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_251f30:
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[1] = cpu->regs[1] + 280ULL;
    cpu->regs[30] = PB_BASE + 0x251f3cULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_251f24;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[0] = cpu->regs[1] + 304ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[3] + 8) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    { PB_CALL(165, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x251f78ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[3], (cpu->regs[19] + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 312ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(167, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    { PB_CALL(168, cpu, tlb, PB_BASE + 0x1b8380ULL); return; };
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_251fc8;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_251fc4;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_251fc4:
    return;
L_251fc8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2816));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_NE) goto L_252024;
L_252004:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_252014;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_252014:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_252024:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3840));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_EQ) goto L_252080;
L_252038:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 80));
    if ((cpu->regs[1])==0) goto L_252094;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    if ((cpu->regs[1])==0) goto L_252094;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x252050ULL; PB_CALL(169, cpu, tlb, cpu->regs[1]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2520b0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_EQ) goto L_2520c8;
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_EQ) goto L_2520bc;
L_25206c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x252074ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0x152da0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_252100;
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_252014;
L_252080:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 48));
    if (!((cpu->regs[1] >> 8) & 1)) goto L_252038;
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_252004;
L_252094:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 424ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x2520b0ULL; PB_CALL(171, cpu, tlb, PB_BASE + 0x11f220ULL);
L_2520b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[19] = 0ULL;
    goto L_252014;
L_2520bc:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 48));
    if (!((cpu->regs[0] >> 8) & 1)) goto L_25206c;
L_2520c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[1] = cpu->regs[1] + 328ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2520e0ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2520b0;
L_2520e8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2520b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2520fcULL; PB_CALL(173, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2520b0;
L_252100:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 368ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x25211cULL; PB_CALL(174, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_2520e8;
    goto L_2520b0;
}
