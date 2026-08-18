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

void ft_PyWrapper_New(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2672));
    cpu->regs[30] = PB_BASE + 0x1be384ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1be3bc;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1be39c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1be39c:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[5] + 16), cpu->regs[19]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1be3b0;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_1be3b0:
    PB_STR((cpu->regs[5] + 24), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1be3bcULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd9444ULL);
L_1be3bc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 16) + 8);
    cpu->regs[3] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 40));
    PB_LDRW(cpu->regs[6], (cpu->regs[2] + 40));
    PB_LDR(cpu->regs[7], (cpu->regs[2] + 24));
    if (((cpu->regs[6] >> 0) & 1)) goto L_1be3fc;
    cpu->regs[4] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_1be408;
L_1be3ec:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 48));
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[16] = cpu->regs[7];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1be3fc:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 48));
    cpu->regs[16] = cpu->regs[7];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1be408:
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 29) & 1)) goto L_1be41c;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    if ((cpu->regs[1])==0) goto L_1be3ec;
L_1be41c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 1808ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1be440ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1be460ULL; PB_CALL(4, cpu, tlb, cpu->regs[4]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = (FLAG_GE) ? cpu->regs[1] : 0ULL;
    return;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1be490ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x1be000ULL;
    cpu->regs[0] = cpu->regs[0] + 1152ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1be500;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1be4c0ULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[20], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1be4d0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcdb0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1be520;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1be4dcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x1be4e4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1be4ecULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    if ((cpu->regs[20])==0) goto L_1be520;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xdce80ULL); return; };
L_1be500:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1be508ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x1be510ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
L_1be520:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 20ULL));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LE) goto L_1be5d4;
L_1be564:
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] - cpu->regs[22]));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[22], (cpu->regs[20] + 0)); PB_LDRW(cpu->regs[20], (cpu->regs[20] + 0) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    cpu->regs[2] = 128ULL;
    cpu->regs[20] = ((uint32_t)((FLAG_LE) ? (cpu->regs[20] + 1) : cpu->regs[20]));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] - 2ULL));
    cpu->regs[20] = ((uint32_t)(cpu->regs[3] | (cpu->regs[20] << 1)));
    cpu->regs[30] = PB_BASE + 0x1be590ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1be6e4ULL);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1be5a0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1be6e4ULL);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1be5b0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1be6e4ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1be5c0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1be6e4ULL);
    cpu->regs[0] = 0ULL;
L_1be5c4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1be5d4:
    cpu->regs[1] = cpu->regs[1] << 1;
    cpu->regs[0] = cpu->regs[19] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x1be5e0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x13e868ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1be564;
    goto L_1be5c4;
    SP = SP - 48ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[2] = SP;
    cpu->regs[30] = PB_BASE + 0x1be624ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1be7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1be6c8;
    cpu->regs[30] = PB_BASE + 0x1be630ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xd7750ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    if ((cpu->regs[1])!=0) goto L_1be68c;
L_1be63c:
    PB_LDR(cpu->regs[1], (SP + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1be648ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1be970ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1be6d0;
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 24), cpu->regs[20]); PB_STR((cpu->regs[19] + 24) + 8, cpu->regs[0]);
L_1be658:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_1be660:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1be6ac;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_1be68c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_NE) goto L_1be63c;
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_1be6b0;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    goto L_1be658;
L_1be6ac:
    cpu->regs[30] = PB_BASE + 0x1be6b0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1be6b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1872ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1be6c8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1be6c8:
    cpu->regs[0] = 0ULL;
    goto L_1be660;
L_1be6d0:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_1be6c8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_1be660;
L_1be6e4:
    cpu->regs[3] = 16777215ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_GT) goto L_1be730;
    cpu->regs[3] = 262143ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_GT) goto L_1be754;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4095ULL)));
    if (FLAG_GT) goto L_1be77c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(63ULL)));
    if (FLAG_GT) goto L_1be7a4;
L_1be70c:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 63ULL));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 24));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] | cpu->regs[2]));
    cpu->regs[1] = cpu->regs[3] + 32ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + 1ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[3]);
    PB_STRB((cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[4]))), cpu->regs[2]);
    return;
L_1be730:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | ((uint64_t)((int64_t)cpu->regs[1] >> 24))));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 24));
    cpu->regs[5] = ((uint32_t)(cpu->regs[2] | 64ULL));
    cpu->regs[3] = cpu->regs[3] + 32ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[6] = ((uint32_t)(cpu->regs[4] + 1ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[6]);
    PB_STRB((cpu->regs[3] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[4]))), cpu->regs[5]);
L_1be754:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[3] = ((cpu->regs[1] >> 18) & 0x3fULL);
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | cpu->regs[2]));
    cpu->regs[4] = cpu->regs[4] + 32ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | 64ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[5] + 1ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_STRB((cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]))), cpu->regs[3]);
L_1be77c:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[3] = ((cpu->regs[1] >> 12) & 0x3fULL);
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | cpu->regs[2]));
    cpu->regs[4] = cpu->regs[4] + 32ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | 64ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[5] + 1ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_STRB((cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]))), cpu->regs[3]);
L_1be7a4:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[3] = ((cpu->regs[1] >> 6) & 0x3fULL);
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | cpu->regs[2]));
    cpu->regs[4] = cpu->regs[4] + 32ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | 64ULL));
    cpu->regs[6] = ((uint32_t)(cpu->regs[5] + 1ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[6]);
    cpu->regs[2] = 0ULL;
    PB_STRB((cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]))), cpu->regs[3]);
    goto L_1be70c;
L_1be7d0:
    SP = SP - 80ULL;
    cpu->regs[4] = PB_BASE + 0x450000ULL;
    cpu->regs[4] = cpu->regs[4] + 8ULL;
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[4] = cpu->regs[4] + 264ULL;
    cpu->regs[5] = 18446744073709499904ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    cpu->regs[5] = (cpu->regs[5] & ~(0xffffULL << 16)) | ((0xc465ULL & 0xffff) << 16);
    PB_LDR(cpu->regs[8], (cpu->regs[4] + 0)); PB_LDR(cpu->regs[9], (cpu->regs[4] + 0) + 8);
    PB_STR((SP + 64), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[7] = 1ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[5]);
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 16));
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[4] = SP + 4ULL;
    cpu->regs[2] = cpu->regs[2] + 1904ULL;
    cpu->regs[5] = SP + 8ULL;
    PB_STRW((SP + 4), cpu->regs[7]);
    PB_STR((SP + 8), 0ULL);
    PB_STR((SP + 16), cpu->regs[8]); PB_STR((SP + 16) + 8, cpu->regs[9]);
    PB_STR((cpu->regs[3] + 16), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x1be844ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x13eb20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1be8e0;
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[1])!=0) goto L_1be900;
L_1be850:
    PB_LDRW(cpu->regs[1], (SP + 4));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1be8e8;
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = 18446744073709499904ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xc465ULL & 0xffff) << 16);
    if (FLAG_LT) { FLAG_CMP(cpu->regs[0], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1be91c;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1be8a8;
L_1be878:
    cpu->regs[0] = 0ULL;
L_1be87c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1be918;
    PB_LDR(cpu->regs[19], (SP + 64));
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_1be8a8:
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1be8b0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1bea60ULL);
    cpu->regs[1] = 21495ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xa5e3ULL & 0xffff) << 16);
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 32)) | ((0xc49bULL & 0xffff) << 32);
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 48)) | ((0x20ULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_1be878;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 2000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1be8e0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1be8e0:
    cpu->regs[0] = 4294967295ULL;
    goto L_1be87c;
L_1be8e8:
    cpu->regs[1] = 18446744073709499904ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xc465ULL & 0xffff) << 16);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1be93c;
    PB_STR((cpu->regs[19] + 0), 0ULL);
    goto L_1be878;
L_1be900:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1be90cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x226230ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1be850;
    cpu->regs[0] = 4294967295ULL;
    goto L_1be87c;
L_1be918:
    cpu->regs[30] = PB_BASE + 0x1be91cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1be91c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1968ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1be934ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1be87c;
L_1be93c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1be954ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1be87c;
    /* nop */
}
