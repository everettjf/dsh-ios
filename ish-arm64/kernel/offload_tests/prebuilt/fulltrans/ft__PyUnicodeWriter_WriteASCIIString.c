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

void ft__PyUnicodeWriter_WriteASCIIString(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_120184;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[20] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_1201a0;
L_120114:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(126ULL)));
    if (FLAG_LS) goto L_1201d8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 24) + 8);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_LT) goto L_1201d8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_120248;
L_12013c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_HS) goto L_12022c;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[20];
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_LO) goto L_120240;
L_12015c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x120164ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
L_120168:
    cpu->regs[1] = cpu->regs[20] + cpu->regs[1];
L_12016c:
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
L_120174:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_120184:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x12018cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[1])!=0) goto L_120114;
    /* nop */
    /* nop */
L_1201a0:
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 52));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_120114;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1201b4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe9b80ULL);
    if ((cpu->regs[0])==0) goto L_120344;
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    PB_STRB((cpu->regs[19] + 53), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1201ccULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1a1e64ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[20] + cpu->regs[1];
    goto L_12016c;
L_1201d8:
    if ((cpu->regs[20])==0) goto L_120208;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x1201ecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11cba0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_120344;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_120244;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    goto L_12013c;
L_120208:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_120244;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_HI) goto L_12015c;
L_12022c:
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_HS) goto L_12015c;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_12015c;
L_120240:
    __builtin_trap();
L_120244:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
L_120248:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1202e0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[4] = cpu->regs[20] & 18446744073709551612ULL;
    cpu->regs[4] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[5] = cpu->regs[21] + cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[1] << 1);
    cpu->regs[3] = cpu->regs[0];
L_12026c:
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_LO) goto L_1202b4;
    cpu->regs[3] = cpu->regs[4] - cpu->regs[21];
    cpu->regs[2] = cpu->regs[21] - 3ULL;
    cpu->regs[3] = cpu->regs[3] + 3ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    cpu->regs[2] = cpu->regs[3] & 18446744073709551612ULL;
    cpu->regs[3] = cpu->regs[3] >> 2;
    cpu->regs[2] = (FLAG_HS) ? cpu->regs[2] : 0ULL;
    cpu->regs[2] = cpu->regs[2] + cpu->regs[21];
    cpu->regs[3] = cpu->regs[3] << 3;
    cpu->regs[3] = (FLAG_HS) ? cpu->regs[3] : 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
L_1202a0:
    FLAG_CMP(cpu->regs[2], cpu->regs[5]);
    if (FLAG_HS) goto L_120168;
    PB_LDRB(cpu->regs[3], cpu->regs[2]); cpu->regs[2] += 1;
    PB_STRH(cpu->regs[0], cpu->regs[3]); cpu->regs[0] += 2;
    goto L_1202a0;
L_1202b4:
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    PB_STRH((cpu->regs[3] + -8), cpu->regs[6]);
    cpu->regs[2] = cpu->regs[2] + 4ULL;
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + -3));
    PB_STRH((cpu->regs[3] + -6), cpu->regs[6]);
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + -2));
    PB_STRH((cpu->regs[3] + -4), cpu->regs[6]);
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + -1));
    PB_STRH((cpu->regs[3] + -2), cpu->regs[6]);
    goto L_12026c;
L_1202e0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[4] = cpu->regs[20] & 18446744073709551612ULL;
    cpu->regs[4] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[5] = cpu->regs[21] + cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[1] << 2);
    cpu->regs[3] = cpu->regs[0];
L_1202fc:
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_LO) goto L_12034c;
    cpu->regs[3] = cpu->regs[4] - cpu->regs[21];
    cpu->regs[2] = cpu->regs[21] - 3ULL;
    cpu->regs[3] = cpu->regs[3] + 3ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    cpu->regs[2] = cpu->regs[3] & 18446744073709551612ULL;
    cpu->regs[3] = cpu->regs[3] >> 2;
    cpu->regs[2] = (FLAG_HS) ? cpu->regs[2] : 0ULL;
    cpu->regs[2] = cpu->regs[2] + cpu->regs[21];
    cpu->regs[3] = cpu->regs[3] << 4;
    cpu->regs[3] = (FLAG_HS) ? cpu->regs[3] : 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
L_120330:
    FLAG_CMP(cpu->regs[2], cpu->regs[5]);
    if (FLAG_HS) goto L_120168;
    PB_LDRB(cpu->regs[3], cpu->regs[2]); cpu->regs[2] += 1;
    PB_STRW(cpu->regs[0], cpu->regs[3]); cpu->regs[0] += 4;
    goto L_120330;
L_120344:
    cpu->regs[0] = 4294967295ULL;
    goto L_120174;
L_12034c:
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + 0));
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    PB_STRW((cpu->regs[3] + -16), cpu->regs[6]);
    cpu->regs[2] = cpu->regs[2] + 4ULL;
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + -3));
    PB_STRW((cpu->regs[3] + -12), cpu->regs[6]);
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + -2));
    PB_STRW((cpu->regs[3] + -8), cpu->regs[6]);
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + -1));
    PB_STRW((cpu->regs[3] + -4), cpu->regs[6]);
    goto L_1202fc;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[4];
    FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1204f8;
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_LE) goto L_120514;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1204c8;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_120504;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 1));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1204d0;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_120504;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 2));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1204d8;
    FLAG_CMP(cpu->regs[3], 3ULL);
    if (FLAG_EQ) goto L_120504;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 3));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1204e0;
    FLAG_CMP(cpu->regs[3], 4ULL);
    if (FLAG_EQ) goto L_120504;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 4));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1204c0;
    FLAG_CMP(cpu->regs[3], 5ULL);
    if (FLAG_EQ) goto L_120504;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 5));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1204e8;
    FLAG_CMP(cpu->regs[3], 6ULL);
    if (FLAG_EQ) goto L_120504;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 6));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1204f0;
    FLAG_CMP(cpu->regs[3], 7ULL);
    if (FLAG_EQ) goto L_120504;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 7));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12050c;
    cpu->regs[1] = 8ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_NE) goto L_120444;
    goto L_120504;
L_120438:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_EQ) goto L_120504;
L_120444:
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + cpu->regs[1]));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_120438;
L_12044c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = cpu->regs[3] + 128ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x120464ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdea80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_120520;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[3] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x120484ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x120528ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1204ac;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1204ac;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1204acULL; PB_CALL(8, cpu, tlb, cpu->regs[1]);
L_1204ac:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1204c0:
    cpu->regs[1] = 4ULL;
    goto L_12044c;
L_1204c8:
    cpu->regs[1] = 0ULL;
    goto L_12044c;
L_1204d0:
    cpu->regs[1] = 1ULL;
    goto L_12044c;
L_1204d8:
    cpu->regs[1] = 2ULL;
    goto L_12044c;
L_1204e0:
    cpu->regs[1] = 3ULL;
    goto L_12044c;
L_1204e8:
    cpu->regs[1] = 5ULL;
    goto L_12044c;
L_1204f0:
    cpu->regs[1] = 6ULL;
    goto L_12044c;
L_1204f8:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x120500ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[3] = cpu->regs[0];
L_120504:
    cpu->regs[1] = cpu->regs[3];
    goto L_12044c;
L_12050c:
    cpu->regs[1] = 7ULL;
    goto L_12044c;
L_120514:
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = cpu->regs[3];
    goto L_12044c;
L_120520:
    cpu->regs[20] = 4294967295ULL;
    goto L_1204ac;
L_120528:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[22]);
    if (FLAG_LT) { FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)1LL)); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12056c;
    FLAG_CMP(cpu->regs[2], cpu->regs[22]);
    if (FLAG_GT) goto L_120618;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x120700ULL); return; };
L_12056c:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
L_120570:
    FLAG_CMP(cpu->regs[22], cpu->regs[3]);
    cpu->regs[22] = (FLAG_LE) ? cpu->regs[22] : cpu->regs[3];
L_120578:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    cpu->regs[23] = (FLAG_GE) ? cpu->regs[22] : cpu->regs[19];
    cpu->regs[0] = 127ULL;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_1206c8;
L_12058c:
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + 20));
    cpu->regs[24] = cpu->regs[2];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LO) goto L_1206a0;
L_12059c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24)); PB_LDR(cpu->regs[1], (cpu->regs[21] + 24) + 8);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_GE) goto L_1205d0;
L_1205ac:
    if ((cpu->regs[23])==0) goto L_1206f0;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    PB_STRW((SP + 76), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1205c0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11cba0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1206e8;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    PB_LDRW(cpu->regs[4], (SP + 76));
L_1205d0:
    cpu->regs[19] = cpu->regs[19] - cpu->regs[22];
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_GT) goto L_120628;
L_1205e4:
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1205f4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11ae68ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[22];
    PB_STR((cpu->regs[21] + 32), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
L_120604:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_120618:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_120570;
    goto L_120578;
L_120628:
    if (!((cpu->regs[4] >> 0) & 1)) goto L_120674;
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x12063cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11ae68ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    PB_STR((cpu->regs[21] + 32), cpu->regs[1]);
    cpu->regs[3] = 32ULL;
    cpu->regs[30] = PB_BASE + 0x120658ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x259760ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1206e8;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[19];
    PB_STR((cpu->regs[21] + 32), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    goto L_120604;
L_120674:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[3] = 32ULL;
    cpu->regs[30] = PB_BASE + 0x120680ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x259760ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1206e8;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[19];
    PB_STR((cpu->regs[21] + 32), cpu->regs[1]);
    goto L_1205e4;
L_1206a0:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    PB_STRW((SP + 76), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1206b4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1dbe60ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[4], (SP + 76));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HS) goto L_12059c;
    goto L_1205ac;
L_1206c8:
    cpu->regs[0] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1206f8;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    cpu->regs[1] = 1114111ULL;
    cpu->regs[0] = 65535ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    goto L_12058c;
L_1206e8:
    cpu->regs[0] = 4294967295ULL;
    goto L_120604;
L_1206f0:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    goto L_1205d0;
L_1206f8:
    cpu->regs[0] = 255ULL;
    goto L_12058c;
}
