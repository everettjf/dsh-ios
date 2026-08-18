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

void ft_PyImport_GetMagicNumber(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1de27cULL; PB_CALL(1, cpu, tlb, cpu->regs[1]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 1056ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 960));
    cpu->regs[30] = PB_BASE + 0x1de298ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11d200ULL);
    if ((cpu->regs[0])==0) goto L_1de304;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 1080ULL;
    cpu->regs[30] = PB_BASE + 0x1de2acULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1de2c4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1de2f8;
L_1de2c4:
    if ((cpu->regs[19])==0) goto L_1de304;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de2d0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x129680ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1de2e8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1de30c;
L_1de2e8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1de2f8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1de300ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1de2c4;
L_1de304:
    cpu->regs[20] = 18446744073709551615ULL;
    goto L_1de2e8;
L_1de30c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de314ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1de2e8;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_1de350;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1de34cULL; PB_CALL(7, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1de39c;
L_1de350:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])!=0) goto L_1de390;
L_1de358:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])==0) goto L_1de36c;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de368ULL; PB_CALL(8, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1de39c;
L_1de36c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])!=0) goto L_1de3ac;
L_1de374:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0x1de120ULL); return; };
L_1de390:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de398ULL; PB_CALL(10, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1de358;
L_1de39c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1de3ac:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de3b4ULL; PB_CALL(11, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1de374;
    goto L_1de39c;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1de3ecULL; PB_CALL(12, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 1056ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 960));
    cpu->regs[30] = PB_BASE + 0x1de408ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11d200ULL);
    if ((cpu->regs[0])==0) goto L_1de4c4;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1de418ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1de430;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_1de4e8;
L_1de430:
    if ((cpu->regs[20])==0) goto L_1de4c4;
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = cpu->regs[2] + 2912ULL;
    cpu->regs[1] = cpu->regs[1] + 1104ULL;
    cpu->regs[30] = PB_BASE + 0x1de450ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe6d90ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1de468;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1de4dc;
L_1de468:
    if ((cpu->regs[19])==0) goto L_1de4c4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1792ULL;
    cpu->regs[30] = PB_BASE + 0x1de480ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1de4ac;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1de498;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1de4cc;
L_1de498:
    cpu->regs[0] = 0ULL;
L_1de49c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1de4ac:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1de4c4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1de4c4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de4c4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1de4c4:
    cpu->regs[0] = 4294967295ULL;
    goto L_1de49c;
L_1de4cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de4d4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1de49c;
L_1de4dc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1de4e4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1de468;
L_1de4e8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de4f0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1de430;
    /* nop */
    /* nop */
    /* nop */
L_1de500:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1de524ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1de580;
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_HS) goto L_1de56c;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[19];
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LO) goto L_1de57c;
L_1de540:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de550ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[3] = cpu->regs[0];
    PB_STRB((cpu->regs[0] + cpu->regs[19]), 0ULL);
L_1de558:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1de56c:
    if (FLAG_LS) goto L_1de540;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[19];
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_HS) goto L_1de540;
L_1de57c:
    __builtin_trap();
L_1de580:
    cpu->regs[0] = 15ULL;
    PB_STRW((cpu->regs[21] + 64), cpu->regs[0]);
    goto L_1de558;
    SP = SP - 96ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[5];
    cpu->regs[23] = cpu->regs[6];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[3];
    cpu->regs[26] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1de5c8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x193da0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1de638;
    PB_STR((SP + 0), cpu->regs[19]);
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[6] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[7] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1de5f8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1de6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_1de608;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de608ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7b1c0ULL);
L_1de608:
    if ((cpu->regs[20])==0) goto L_1de62c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[5] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de628ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1e33e0ULL);
    cpu->regs[20] = cpu->regs[0];
L_1de62c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1de638ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1c12acULL);
L_1de638:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[4];
    if ((cpu->regs[3])==0) goto L_1de698;
    cpu->regs[5] = 1ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1de680ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1236a4ULL);
    if (!((cpu->regs[0] >> 63) & 1)) goto L_1de690;
L_1de684:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1de690:
    cpu->regs[0] = cpu->regs[0] + cpu->regs[19];
    goto L_1de684;
L_1de698:
    cpu->regs[0] = cpu->regs[4];
    goto L_1de684;
L_1de6a0:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[2];
    cpu->regs[25] = cpu->regs[4];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[0] + 352ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[21] = cpu->regs[5];
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 112ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[6];
    cpu->regs[23] = cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x1de6f8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1de7c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1de714ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1de808ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1de7b8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    if ((cpu->regs[0])==0) goto L_1de7d0;
    cpu->regs[21] = cpu->regs[21] | cpu->regs[25];
    if ((cpu->regs[21])!=0) goto L_1de7d0;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2952ULL;
    cpu->regs[30] = PB_BASE + 0x1de73cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe9950ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1de7d0;
L_1de740:
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1de750;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[2]);
L_1de750:
    PB_STR((cpu->regs[19] + 2336), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1de760ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x195040ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (SP + 80));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1de778ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1950e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1de794;
    cpu->regs[30] = PB_BASE + 0x1de784ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x195310ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1de794ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x124000ULL);
L_1de794:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de79cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1a8480ULL);
L_1de79c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1de7b8:
    cpu->regs[30] = PB_BASE + 0x1de7bcULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1de7c8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1de7c8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xcaea4ULL);
L_1de7c8:
    cpu->regs[20] = 0ULL;
    goto L_1de79c;
L_1de7d0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 24), cpu->regs[0]);
    goto L_1de740;
    /* nop */
    cpu->regs[0] = PB_BASE + 0x491000ULL;
    cpu->regs[2] = cpu->regs[0] + 3904ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 4016));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1de800;
L_1de7f4:
    cpu->regs[0] = cpu->regs[0] + 3904ULL;
    cpu->regs[0] = cpu->regs[0] + 4016ULL;
    return;
L_1de800:
    PB_STRW((cpu->regs[2] + 4016), cpu->regs[1]);
    goto L_1de7f4;
L_1de808:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1de830ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1946e4ULL);
    if ((cpu->regs[0])==0) goto L_1de8a0;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 1024ULL;
    cpu->regs[30] = PB_BASE + 0x1de840ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdbd90ULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1de898;
    cpu->regs[1] = cpu->regs[0] + 1024ULL;
    PB_STR((cpu->regs[19] + 8), cpu->regs[0]); PB_STR((cpu->regs[19] + 8) + 8, cpu->regs[0]);
    PB_STR((cpu->regs[19] + 48), cpu->regs[1]);
    PB_STR((cpu->regs[19] + 72), cpu->regs[23]);
    PB_STR((cpu->regs[19] + 496), cpu->regs[21]); PB_STR((cpu->regs[19] + 496) + 8, cpu->regs[22]);
    if ((cpu->regs[20])!=0) goto L_1de878;
L_1de860:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1de878:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1de880ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1de890ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1de500ULL);
    PB_STR((cpu->regs[19] + 2752), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1de8a8;
L_1de898:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de8a0ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1a8480ULL);
L_1de8a0:
    cpu->regs[19] = 0ULL;
    goto L_1de860;
L_1de8a8:
    cpu->regs[0] = 2ULL;
    PB_STRW((cpu->regs[19] + 2744), cpu->regs[0]);
    goto L_1de860;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[0] = PB_BASE + 0x491000ULL;
    cpu->regs[2] = cpu->regs[0] + 3904ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 3296));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1de8e0;
L_1de8d4:
    cpu->regs[0] = cpu->regs[0] + 3904ULL;
    cpu->regs[0] = cpu->regs[0] + 3296ULL;
    return;
L_1de8e0:
    PB_STRW((cpu->regs[2] + 3296), cpu->regs[1]);
    goto L_1de8d4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    if ((cpu->regs[0])==0) goto L_1de904;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1de900;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1de900:
    return;
L_1de904:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    SP = SP - 144ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 16), cpu->regs[1]); PB_STR((SP + 16) + 8, cpu->regs[0]);
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1de940ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1dec0cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1deb90;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1de950ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1dec0cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1deb90;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    if (FLAG_EQ) goto L_1debcc;
L_1de974:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x495000ULL;
    cpu->regs[0] = cpu->regs[1] + 576ULL;
    cpu->regs[0] = cpu->regs[0] + 2536ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_1deb80;
    cpu->regs[22] = SP + 24ULL;
    cpu->regs[21] = 1ULL;
L_1de994:
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_1deb0c;
L_1de99c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[1] + 576ULL;
    cpu->regs[1] = cpu->regs[1] + 2536ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1debdc;
    cpu->regs[24] = SP + 16ULL;
    cpu->regs[23] = 1ULL;
L_1de9b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2968));
    cpu->regs[27] = 0ULL;
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[21] + cpu->regs[23];
    PB_STR((SP + 8), cpu->regs[0]);
    PB_STR((SP + 32), 0ULL);
L_1de9d8:
    cpu->regs[25] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[27]));
    FLAG_CMP(cpu->regs[23], cpu->regs[27]);
    if (FLAG_GT) goto L_1dea60;
    PB_LDR(cpu->regs[21], (SP + 32));
    if ((cpu->regs[21])==0) goto L_1deb54;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = SP + 32ULL;
    cpu->regs[30] = PB_BASE + 0x1de9f8ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xe2100ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    if ((cpu->regs[21])==0) goto L_1deb54;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1dea08ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1dec70ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1dea20;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1debb0;
L_1dea20:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
L_1dea30:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1deb9c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 144ULL;
    return;
L_1dea60:
    PB_LDR(cpu->regs[28], (cpu->regs[24] + (cpu->regs[25] << 3)));
    cpu->regs[26] = 0ULL;
L_1dea68:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    FLAG_CMP(cpu->regs[21], cpu->regs[26]);
    if (FLAG_LE) goto L_1dea98;
    PB_LDR(cpu->regs[1], (SP + 0));
    PB_LDR(cpu->regs[5], (cpu->regs[22] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1dea84ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1deb24;
L_1dea88:
    FLAG_CMP(cpu->regs[28], cpu->regs[5]);
    if (FLAG_EQ) goto L_1deae8;
L_1dea90:
    cpu->regs[26] = ((uint32_t)(cpu->regs[26] + 1ULL));
    goto L_1dea68;
L_1dea98:
    PB_LDR(cpu->regs[0], (SP + 32));
    if ((cpu->regs[0])!=0) goto L_1dead0;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1deaacULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdb480ULL);
    PB_STR((SP + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1deb54;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[0] + 24ULL;
L_1deabc:
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_GT) goto L_1deaf0;
    cpu->regs[1] = cpu->regs[21] - cpu->regs[19]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[1] = (FLAG_GE) ? cpu->regs[1] : 0ULL;
    cpu->regs[19] = cpu->regs[1] + cpu->regs[19];
L_1dead0:
    PB_LDRW(cpu->regs[1], (cpu->regs[28] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1debec;
L_1deadc:
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[19] << 3);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_STR((cpu->regs[1] + 24), cpu->regs[28]);
L_1deae8:
    cpu->regs[27] = ((uint32_t)(cpu->regs[27] + 1ULL));
    goto L_1de9d8;
L_1deaf0:
    PB_LDR(cpu->regs[4], (cpu->regs[22] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_1deb1c;
L_1deb00:
    PB_STR((cpu->regs[5] + (cpu->regs[1] << 3)), cpu->regs[4]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_1deabc;
L_1deb0c:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3808));
    PB_STR((SP + 16), cpu->regs[19]);
    goto L_1de99c;
L_1deb1c:
    PB_STRW((cpu->regs[4] + 0), cpu->regs[2]);
    goto L_1deb00;
L_1deb24:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1deb2cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1dea88;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1deb40ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1dea90;
    if (FLAG_GE) goto L_1deae8;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x1deb54ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x18d760ULL);
L_1deb54:
    cpu->regs[30] = PB_BASE + 0x1deb58ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1debf4;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1dea20;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_1dea30;
L_1deb80:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[22] = cpu->regs[0] + 24ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    goto L_1de994;
L_1deb90:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2400));
    goto L_1dea30;
L_1deb9c:
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1debb0ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1debb0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1debb8ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_1dea30;
L_1debcc:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3808));
    PB_STR((SP + 24), cpu->regs[20]);
    goto L_1de974;
L_1debdc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[24] = cpu->regs[0] + 24ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    goto L_1de9b8;
L_1debec:
    PB_STRW((cpu->regs[28] + 0), cpu->regs[1]);
    goto L_1deadc;
L_1debf4:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    goto L_1dea30;
L_1dec0c:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_1dec28;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 168));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1dec30;
L_1dec28:
    cpu->regs[0] = 1ULL;
    return;
L_1dec30:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2968));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1dec44ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xe270cULL);
    cpu->regs[1] = PB_BASE + 0x495000ULL;
    cpu->regs[1] = cpu->regs[1] + 576ULL;
    cpu->regs[2] = cpu->regs[1] + 2536ULL;
    cpu->regs[1] = cpu->regs[1] + 3856ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] & 1ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | cpu->regs[2]));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1dec70:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x495000ULL;
    cpu->regs[1] = cpu->regs[1] + 576ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] + 2536ULL;
    cpu->regs[30] = PB_BASE + 0x1dec90ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1decb8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[5] + 24), 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1decac;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1decac:
    PB_STR((cpu->regs[5] + 16), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1decb8ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xd9444ULL);
L_1decb8:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1decc8:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1decd8ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1dece4ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x1dececULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    goto L_1decc8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3552));
    { PB_CALL(62, cpu, tlb, PB_BASE + 0x11d9e0ULL); return; };
    /* nop */
    /* nop */
}
