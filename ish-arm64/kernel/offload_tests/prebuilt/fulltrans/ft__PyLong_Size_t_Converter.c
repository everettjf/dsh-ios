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

void ft__PyLong_Size_t_Converter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_9f190;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_9f190;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9f18cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9f1a8;
L_9f190:
    cpu->regs[30] = PB_BASE + 0x9f194ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1b00c0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9f1b0;
    cpu->regs[30] = PB_BASE + 0x9f1a4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_9f1b0;
L_9f1a8:
    cpu->regs[0] = 0ULL;
    goto L_9f1b8;
L_9f1b0:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
L_9f1b8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_9f1c4:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x9f1d8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x2283d0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9f1ec;
    cpu->regs[30] = PB_BASE + 0x9f1e8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_9f1f8;
L_9f1ec:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
    goto L_9f1fc;
L_9f1f8:
    cpu->regs[0] = 0ULL;
L_9f1fc:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 64ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3080));
    if (FLAG_NE) goto L_9f254;
L_9f240:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x9f24cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x9f1c4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9f274;
    goto L_9f310;
L_9f254:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1680ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x9f26cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9f240;
    goto L_9f310;
L_9f274:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x9f280ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x9f1c4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9f310;
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[3], (SP + 8) + 8);
    cpu->regs[0] = 4294967295ULL;
    cpu->regs[1] = cpu->regs[3] | cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_9f2b4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 1688ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9f2b0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9f2e0;
L_9f2b4:
    cpu->regs[0] = cpu->regs[3] << 32;
    cpu->regs[1] = cpu->regs[2] << 12;
    cpu->regs[0] = cpu->regs[0] & 18446726481523507200ULL;
    cpu->regs[3] = ((cpu->regs[3] & 0xfffULL) << 8);
    cpu->regs[1] = cpu->regs[1] & 17592184995840ULL;
    cpu->regs[2] = cpu->regs[2] & 255ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9f2ec;
L_9f2e0:
    cpu->regs[30] = PB_BASE + 0x9f2e4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_9f310;
    cpu->regs[0] = 18446744073709551615ULL;
L_9f2ec:
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_9f324;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x1485e0ULL); return; };
L_9f310:
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9f328;
L_9f324:
    cpu->regs[30] = PB_BASE + 0x9f328ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9f328:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = SP;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9f368ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x9f1c4ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9f3a0;
    PB_LDR(cpu->regs[2], (SP + 0));
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_9f3b4;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[2] >> 12;
    SP = SP + 32ULL;
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] & ~0xffULL) | ((cpu->regs[2] >> 0) & 0xffULL))));
    { PB_CALL(14, cpu, tlb, PB_BASE + 0xe1564ULL); return; };
L_9f3a0:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9f3b8;
L_9f3b4:
    cpu->regs[30] = PB_BASE + 0x9f3b8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9f3b8:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    SP = SP + 32ULL;
    return;
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = SP;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9f3f4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x9f1c4ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9f430;
    PB_LDR(cpu->regs[2], (SP + 0));
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_9f444;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[2] >> 32;
    SP = SP + 32ULL;
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] & ~0xfffULL) | ((cpu->regs[2] >> 8) & 0xfffULL))));
    cpu->regs[0] = cpu->regs[0];
    { PB_CALL(17, cpu, tlb, PB_BASE + 0xe1564ULL); return; };
L_9f430:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9f448;
L_9f444:
    cpu->regs[30] = PB_BASE + 0x9f448ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9f448:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    SP = SP + 32ULL;
    return;
    cpu->regs[2] = cpu->regs[0];
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x9f470ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe548cULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 0));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
L_9f498:
    cpu->regs[1] = cpu->regs[19] + 16ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_EQ) goto L_9f4c8;
    FLAG_CMP(cpu->regs[1], cpu->regs[21]);
    if (FLAG_NE) goto L_9f4b4;
L_9f4ac:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 0));
    goto L_9f498;
L_9f4b4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9f4bcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe548cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9f4ac;
    cpu->regs[0] = 4294967295ULL;
    goto L_9f4cc;
L_9f4c8:
    cpu->regs[0] = 0ULL;
L_9f4cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = 4ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[22], (cpu->regs[3] + 16));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDRW(cpu->regs[23], (cpu->regs[3] + 32));
    cpu->regs[30] = PB_BASE + 0x9f508ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdb480ULL);
    if ((cpu->regs[0])==0) goto L_9f5b8;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x9f518ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7aeb0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9f560;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x9f52cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7aeb0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9f560;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9f544ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x9d8ecULL);
    if ((cpu->regs[0])==0) goto L_9f560;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
    PB_LDRH(cpu->regs[0], (cpu->regs[1] + 10));
    cpu->regs[30] = PB_BASE + 0x9f558ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe1564ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9f580;
L_9f560:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9f5b8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9f5b8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9f57cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9f5b8;
L_9f580:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    PB_STR((cpu->regs[19] + 48), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9f590ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe548cULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9f5b0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9f5b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9f5b0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9f5b0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[20] >> 31));
    goto L_9f5bc;
L_9f5b8:
    cpu->regs[0] = 1ULL;
L_9f5bc:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x9f5ecULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9f5fcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x108264ULL);
    if ((cpu->regs[0])==0) goto L_9f630;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[30] = PB_BASE + 0x9f610ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xf7220ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9f634;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9f630;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9f630;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9f630ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9f630:
    cpu->regs[19] = 0ULL;
L_9f634:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_EQ) goto L_9f6a0;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2392));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_EQ) goto L_9f6a0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 1744ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9f698ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 1ULL;
    goto L_9f6e8;
L_9f6a0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_EQ) goto L_9f6e0;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9f6b8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xf7220ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9f6c8;
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[20] + 0), 0ULL);
    goto L_9f6e8;
L_9f6c8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9f6d8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9f6d8:
    PB_STR((cpu->regs[20] + 0), cpu->regs[19]);
    goto L_9f6e4;
L_9f6e0:
    PB_STR((cpu->regs[20] + 0), 0ULL);
L_9f6e4:
    cpu->regs[0] = 0ULL;
L_9f6e8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 208));
    if ((cpu->regs[1])==0) goto L_9f760;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x9f714ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x88494ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9f720ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x8ef74ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x9f728ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    if ((cpu->regs[0])==0) goto L_9f768;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[2] = 0ULL;
L_9f734:
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_GE) goto L_9f768;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[4] + (cpu->regs[2] << 3)), cpu->regs[1]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    if (FLAG_EQ) goto L_9f758;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[3]);
L_9f758:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    goto L_9f734;
L_9f760:
    cpu->regs[0] = 0ULL;
    { PB_CALL(38, cpu, tlb, PB_BASE + 0xd8bc0ULL); return; };
L_9f768:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
