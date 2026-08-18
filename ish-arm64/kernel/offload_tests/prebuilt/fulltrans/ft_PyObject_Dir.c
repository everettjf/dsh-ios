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

void ft_PyObject_Dir(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    if ((cpu->regs[0])==0) goto L_1db25c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 27576ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1db1d4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xed124ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1db2fc;
    cpu->regs[30] = PB_BASE + 0x1db1e0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x179564ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1db208;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1db208;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1db208ULL; PB_CALL(3, cpu, tlb, cpu->regs[1]);
L_1db208:
    if ((cpu->regs[19])==0) goto L_1db2d4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1db214ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x14d3acULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1db23c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1db23c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1db23cULL; PB_CALL(5, cpu, tlb, cpu->regs[1]);
L_1db23c:
    if ((cpu->regs[20])==0) goto L_1db2d4;
L_1db240:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1db248ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x190310ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1db2dc;
L_1db24c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1db25c:
    cpu->regs[30] = PB_BASE + 0x1db260ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x21d144ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1db2d4;
    cpu->regs[30] = PB_BASE + 0x1db26cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d2d70ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1db284;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1db2e8;
L_1db284:
    if ((cpu->regs[20])==0) goto L_1db2d4;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 25) & 1)) goto L_1db240;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3152ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1db2b0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1db2d4;
L_1db2b8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1db2d4;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1db2d4ULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
L_1db2d4:
    cpu->regs[20] = 0ULL;
    goto L_1db24c;
L_1db2dc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1db2b8;
    goto L_1db2d4;
L_1db2e8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1db2f8ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    goto L_1db284;
L_1db2fc:
    cpu->regs[30] = PB_BASE + 0x1db300ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1db2d4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1db320ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1db24c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 27464ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[1] = cpu->regs[20] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1db344ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1db3ac;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 29) & 1)) goto L_1db394;
    cpu->regs[1] = 27576ULL;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1db364ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_1db3b4;
    cpu->regs[30] = PB_BASE + 0x1db36cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1db3ac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1db378ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1b01a4ULL);
    cpu->regs[20] = cpu->regs[0];
L_1db37c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1db384ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1db394:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 3248ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1db3acULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1db3ac:
    cpu->regs[20] = 0ULL;
    goto L_1db37c;
L_1db3b4:
    cpu->regs[30] = PB_BASE + 0x1db3b8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x179564ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_1db37c;
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_1db3f8;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[0] = 61184ULL;
    cpu->regs[2] = 48ULL;
    FLAG_CMP((cpu->regs[1]) & (128ULL), 0);
    cpu->regs[2] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[1] * (uint64_t)(uint32_t)cpu->regs[2];
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 924ULL));
    cpu->regs[1] = cpu->regs[2] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[0] << 6);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1db3f8:
    { PB_CALL(21, cpu, tlb, PB_BASE + 0x15190cULL); return; };
    /* nop */
    cpu->regs[0] = PB_BASE + 0x485000ULL;
    cpu->regs[2] = cpu->regs[0] + 832ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 960));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1db420;
L_1db414:
    cpu->regs[0] = cpu->regs[0] + 832ULL;
    cpu->regs[0] = cpu->regs[0] + 960ULL;
    return;
L_1db420:
    PB_STRW((cpu->regs[2] + 960), cpu->regs[1]);
    goto L_1db414;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1db434ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x144470ULL);
    if ((cpu->regs[0])==0) goto L_1db448;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1db448;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1db448:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    cpu->regs[0] = PB_BASE + 0x47d000ULL;
    cpu->regs[2] = cpu->regs[0] + 3136ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 3024));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1db470;
L_1db464:
    cpu->regs[0] = cpu->regs[0] + 3136ULL;
    cpu->regs[0] = cpu->regs[0] + 3024ULL;
    return;
L_1db470:
    PB_STRW((cpu->regs[2] + 3024), cpu->regs[1]);
    goto L_1db464;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1db4e0;
L_1db4a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1db4b0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1db4f0;
L_1db4bc:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1db4c8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe8180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1db4f0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_1db4d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1db4e0:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1db4bc;
    goto L_1db4a8;
L_1db4f0:
    cpu->regs[0] = 0ULL;
    goto L_1db4d4;
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 16) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = ror64(cpu->regs[1], 4);
    cpu->regs[0] = ror64(cpu->regs[2], 4);
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1db530;
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1db548;
L_1db520:
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[1];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1db540;
    return;
L_1db530:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1db550;
    cpu->regs[1] = 18446744073709551614ULL;
    goto L_1db520;
L_1db540:
    cpu->regs[0] = 18446744073709551614ULL;
    return;
L_1db548:
    cpu->regs[0] = 18446744073709551614ULL;
    goto L_1db520;
L_1db550:
    cpu->regs[0] = 0ULL;
    return;
    /* nop */
    /* nop */
L_1db560:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[6] = cpu->regs[0];
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 2592));
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[7], (cpu->regs[1] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    FLAG_CMP(cpu->regs[7], cpu->regs[8]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[7], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1db690;
L_1db590:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_1db61c;
    if (FLAG_LE) goto L_1db600;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_1db64c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_1db65c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_1db6bc;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1db5c8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1db560ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1db6e0;
    cpu->regs[30] = PB_BASE + 0x1db5d4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1db6c8;
L_1db5e0:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1db6e0;
    if (FLAG_EQ) goto L_1db680;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_1db5f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_1db5f8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1db600:
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_1db66c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1db6bc;
L_1db60c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[6];
    goto L_1db6ec;
L_1db61c:
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1db5f0;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 48));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1db60c;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)1LL)); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1db60c;
    goto L_1db5f0;
L_1db64c:
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GE) goto L_1db5f0;
L_1db65c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[6];
    { PB_CALL(27, cpu, tlb, PB_BASE + 0x2093d0ULL); return; };
L_1db66c:
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1db5f0;
    goto L_1db60c;
L_1db680:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_1db5f8;
L_1db690:
    cpu->regs[0] = cpu->regs[7];
    PB_STRW((SP + 44), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1db69cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    PB_LDRW(cpu->regs[2], (SP + 44));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1db590;
    cpu->regs[1] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[7];
    PB_STRW((SP + 44), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1db6b4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    PB_LDRW(cpu->regs[2], (SP + 44));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1db590;
L_1db6bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_1db5f8;
L_1db6c8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1db5e0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1db6dcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1db5e0;
L_1db6e0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    goto L_1db5f8;
L_1db6ec:
    SP = SP - 96ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2592));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    PB_STR((SP + 8), 0ULL);
    FLAG_CMP(cpu->regs[5], cpu->regs[6]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1db814;
L_1db740:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LT) goto L_1db7b4;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[24] = SP + 16ULL;
    cpu->regs[23] = SP + 8ULL;
L_1db75c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 32) + 8);
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1db76cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x197144ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1db7c0;
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1db788;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_1db788:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1db798ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1ac748ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1db7fc;
L_1db7a4:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1db86c;
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_1db75c;
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_1db7b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_1db7cc;
L_1db7c0:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_1db7c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_1db7cc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1db878;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_1db7fc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1db7a4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1db810ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1db7a4;
L_1db814:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1db81cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1db740;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1db82cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1db740;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1db83cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1f2620ULL);
    if ((cpu->regs[0])==0) goto L_1db870;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 24));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1db860;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1db860;
    cpu->regs[30] = PB_BASE + 0x1db860ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1db860:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_NE) goto L_1db7b4;
    goto L_1db7c4;
L_1db86c:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_1db870:
    cpu->regs[0] = 0ULL;
    goto L_1db7cc;
L_1db878:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1db880ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7c170ULL);
    cpu->regs[2] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1db89cULL; PB_CALL(39, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[1] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 1360));
    { PB_CALL(40, cpu, tlb, PB_BASE + 0x1934e0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[2] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1db8dcULL; PB_CALL(41, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[1] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 1368));
    { PB_CALL(42, cpu, tlb, PB_BASE + 0x1934e0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2] - cpu->regs[1];
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_1dba6c;
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1db92cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1519a0ULL);
    if ((cpu->regs[0])==0) goto L_1dba48;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + (cpu->regs[19] << 3)));
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[19] << 3);
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1db950;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_1db950:
    PB_STR((cpu->regs[5] + 0), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_1dba44;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1db970;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_1db970:
    PB_STR((cpu->regs[5] + 8), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_1dba44;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1db990;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_1db990:
    PB_STR((cpu->regs[5] + 16), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], 3ULL);
    if (FLAG_EQ) goto L_1dba44;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1db9b0;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_1db9b0:
    PB_STR((cpu->regs[5] + 24), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], 4ULL);
    if (FLAG_EQ) goto L_1dba44;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 32));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1db9d0;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_1db9d0:
    PB_STR((cpu->regs[5] + 32), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], 5ULL);
    if (FLAG_EQ) goto L_1dba44;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 40));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1db9f0;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_1db9f0:
    PB_STR((cpu->regs[5] + 40), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], 6ULL);
    if (FLAG_EQ) goto L_1dba44;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 48));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1dba10;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
L_1dba10:
    PB_STR((cpu->regs[5] + 48), cpu->regs[3]);
    FLAG_CMP(cpu->regs[20], 7ULL);
    if (FLAG_EQ) goto L_1dba44;
    cpu->regs[2] = 7ULL;
L_1dba20:
    PB_LDR(cpu->regs[4], (cpu->regs[1] + (cpu->regs[2] << 3)));
    PB_LDRW(cpu->regs[3], (cpu->regs[4] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_1dba58;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[5] + (cpu->regs[2] << 3)), cpu->regs[4]);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_NE) goto L_1dba20;
L_1dba44:
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]);
L_1dba48:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1dba58:
    PB_STR((cpu->regs[5] + (cpu->regs[2] << 3)), cpu->regs[4]);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    if (FLAG_NE) goto L_1dba20;
    goto L_1dba44;
L_1dba6c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(44, cpu, tlb, PB_BASE + 0xd8bc0ULL); return; };
    /* nop */
}
