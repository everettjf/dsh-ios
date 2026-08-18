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

void ft__Py_dup(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1e46d4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 1030ULL;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e46e8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7bb50ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e46f4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if (((cpu->regs[19] >> 31) & 1)) goto L_1e4708;
L_1e46f8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e4708:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    cpu->regs[19] = 4294967295ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e471cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_1e46f8;
    SP = SP - 96ULL;
    cpu->regs[3] = 6000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_1e48c8;
L_1e4760:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e48d0;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e4778ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x10642cULL);
    if ((cpu->regs[0])!=0) goto L_1e47e4;
L_1e477c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e48b4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1e4794ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e4804;
L_1e479c:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_1e47a4:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e47b0:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1e4898;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 96ULL;
    return;
L_1e47e4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1e47f0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e477c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
    goto L_1e47a4;
L_1e4804:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = SP + 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x1e4818ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1e34c0ULL);
    PB_LDR(cpu->regs[24], (SP + 16));
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 48));
L_1e4820:
    PB_LDR(cpu->regs[22], (cpu->regs[23] + 0));
    if ((cpu->regs[22])==0) goto L_1e4890;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e4830ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_1e4840;
L_1e4838:
    cpu->regs[23] = cpu->regs[23] + 8ULL;
    goto L_1e4820;
L_1e4840:
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1e4850ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b080ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e4838;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x1e485cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1063e8ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e48a4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e486cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x107580ULL);
    if ((cpu->regs[0])==0) goto L_1e48a4;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[1] = 1ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 20)); PB_LDRW(cpu->regs[3], (cpu->regs[20] + 20) + 4);
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[20] + 28) + 4);
    cpu->regs[30] = PB_BASE + 0x1e4884ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x19702cULL);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    if ((cpu->regs[0])!=0) goto L_1e47a4;
    goto L_1e479c;
L_1e4890:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_1e479c;
L_1e4898:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1e48a4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e48a4:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_1e479c;
L_1e48b4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e47b0;
L_1e48c8:
    cpu->regs[30] = PB_BASE + 0x1e48ccULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e4760;
L_1e48d0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e47b0;
    SP = SP - 112ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    if ((cpu->regs[2])!=0) goto L_1e4a0c;
    cpu->regs[0] = cpu->regs[3] - 2ULL;
    cpu->regs[23] = cpu->regs[3];
    FLAG_CMP(cpu->regs[0], 1ULL);
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    if (FLAG_HI) goto L_1e4a18;
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e4a18;
L_1e4934:
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[22] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x1e493cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e4a4c;
    FLAG_CMP(cpu->regs[23], 2ULL);
    if (FLAG_NE) goto L_1e49f0;
L_1e494c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = cpu->regs[1] + (12ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 9048));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1e49e8;
L_1e4964:
    cpu->regs[0] = 58200ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
L_1e496c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1e4978ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1e498c;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
L_1e498c:
    PB_STR((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1e4994ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 32));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 4294967264ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] | (cpu->regs[1] << 1)));
    PB_STRB((cpu->regs[19] + 32), cpu->regs[1]);
L_1e49b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1e49e4;
    PB_LDR(cpu->regs[23], (SP + 96));
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_1e49e4:
    cpu->regs[30] = PB_BASE + 0x1e49e8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e49e8:
    PB_STRW((cpu->regs[2] + 9048), cpu->regs[0]);
    goto L_1e4964;
L_1e49f0:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    if ((cpu->regs[1])==0) goto L_1e494c;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1e496c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_1e496c;
L_1e4a0c:
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 16));
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    cpu->regs[23] = cpu->regs[3] + cpu->regs[23];
L_1e4a18:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[4] = cpu->regs[4] + 2592ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e4a44ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e4934;
L_1e4a4c:
    cpu->regs[0] = 4294967295ULL;
    goto L_1e49b0;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e4b60;
L_1e4a8c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e4b4c;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    cpu->regs[21] = cpu->regs[20];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1e4c84;
L_1e4ab8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x1e4ac4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e4c60;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e4c9c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1e4ae0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e4c60;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e4c9c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 25ULL;
    cpu->regs[30] = PB_BASE + 0x1e4afcULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1e4c60;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
L_1e4b10:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e4c50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4b20ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1e4f20ULL);
    if ((cpu->regs[0])!=0) goto L_1e4be0;
L_1e4b24:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e4c50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4b38ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1e4f20ULL);
    if ((cpu->regs[0])!=0) goto L_1e4b6c;
L_1e4b3c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1e4b44:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e4b4c:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e4b60:
    cpu->regs[30] = PB_BASE + 0x1e4b64ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    goto L_1e4a8c;
L_1e4b6c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4b74ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11976cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e4b3c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e4b88ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e4b3c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4b98ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])==0) goto L_1e4b3c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x293000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 28),&_a,4); tlb_read(tlb,(cpu->regs[22] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 2736ULL;
L_1e4bb0:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 32),&_a,4); tlb_read(tlb,(cpu->regs[21] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
L_1e4bbc:
    cpu->regs[30] = PB_BASE + 0x1e4bc0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0x1e4bc4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1e4b44;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e4b4c;
L_1e4be0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4be8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x11976cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e4b24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e4bfcULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e4b24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4c08ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x19e7e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e4b24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4c18ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])==0) goto L_1e4b24;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1e4c30ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x85f70ULL);
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[6] = PB_BASE + 0x293000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 32),&_a,4); tlb_read(tlb,(cpu->regs[21] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[1] = cpu->regs[20];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[4] + 40),&_a,4); tlb_read(tlb,(cpu->regs[4] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[6] = cpu->regs[6] + 2736ULL;
    goto L_1e4bbc;
L_1e4c50:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_1e4b4c;
L_1e4c60:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1e4c74ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x118420ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e4cac;
L_1e4c7c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    goto L_1e4b10;
L_1e4c84:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4c8cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e4c9c;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    goto L_1e4ab8;
L_1e4c9c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_1e4b10;
L_1e4cac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e4cb4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])==0) goto L_1e4c7c;
    cpu->regs[6] = PB_BASE + 0x293000ULL;
    cpu->regs[6] = cpu->regs[6] + 2680ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 40),&_a,4); tlb_read(tlb,(cpu->regs[21] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    goto L_1e4bb0;
}
