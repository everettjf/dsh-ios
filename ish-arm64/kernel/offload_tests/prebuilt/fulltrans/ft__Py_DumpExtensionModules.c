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

void ft__Py_DumpExtensionModules(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_9e4b8:
    SP = SP - 192ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    PB_STR((SP + 144), cpu->regs[23]); PB_STR((SP + 144) + 8, cpu->regs[24]);
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    PB_STR((SP + 176), cpu->regs[27]); PB_STR((SP + 176) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 88), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[1])==0) goto L_9e6d4;
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 944));
    if ((cpu->regs[22])==0) goto L_9e6d4;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_9e6d4;
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 352));
    cpu->regs[24] = SP + 40ULL;
    cpu->regs[25] = SP + 48ULL;
    cpu->regs[26] = SP + 56ULL;
    if ((cpu->regs[20])==0) goto L_9e57c;
    PB_STR((SP + 56), 0ULL);
L_9e520:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9e534ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e57c;
    PB_LDR(cpu->regs[0], (SP + 48));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_9e520;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = cpu->regs[1] + 3344ULL;
    cpu->regs[30] = PB_BASE + 0x9e554ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe9950ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9e520;
    PB_LDR(cpu->regs[20], (SP + 40));
    if ((cpu->regs[20])==0) goto L_9e57c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2592));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_9e580;
    cpu->regs[30] = PB_BASE + 0x9e578ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9e580;
L_9e57c:
    cpu->regs[20] = 0ULL;
L_9e580:
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 1480ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3536));
    cpu->regs[1] = cpu->regs[1] + 2888ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[23] = 1ULL;
    PB_STR((SP + 8), cpu->regs[0]); PB_STR((SP + 8) + 8, cpu->regs[1]);
    PB_STR((SP + 56), 0ULL);
L_9e5ac:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9e5c0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e688;
    PB_LDR(cpu->regs[0], (SP + 48));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_9e5ac;
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[5], (SP + 40));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x9e5e4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e5ac;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 24));
    if ((cpu->regs[0])==0) goto L_9e5ac;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 64));
    if ((cpu->regs[0])==0) goto L_9e5ac;
    if ((cpu->regs[20])==0) goto L_9e648;
    cpu->regs[28] = SP + 64ULL;
    cpu->regs[27] = SP + 72ULL;
    cpu->regs[0] = SP + 80ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    PB_STR((SP + 80), 0ULL);
L_9e610:
    PB_LDR(cpu->regs[1], (SP + 0));
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9e624ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c8b60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e648;
    PB_LDR(cpu->regs[1], (SP + 72));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_9e610;
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[30] = PB_BASE + 0x9e640ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c4a70ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9e610;
    goto L_9e5ac;
L_9e648:
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_9e660;
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 20ULL;
    cpu->regs[30] = PB_BASE + 0x9e65cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_9e670;
L_9e660:
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x9e670ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_9e670:
    PB_LDR(cpu->regs[1], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9e684ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x90d30ULL);
    goto L_9e5ac;
L_9e688:
    if ((cpu->regs[21])==0) goto L_9e6d4;
    cpu->regs[2] = 9ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 1504ULL;
    cpu->regs[30] = PB_BASE + 0x9e6a0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9e6acULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x90c10ULL);
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 192ULL;
    cpu->regs[30] = PB_BASE + 0x9e6c0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1024ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x9e6d4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_9e6d4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 88));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9e6f4;
    cpu->regs[30] = PB_BASE + 0x9e6f4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9e6f4:
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    PB_LDR(cpu->regs[23], (SP + 144)); PB_LDR(cpu->regs[24], (SP + 144) + 8);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    PB_LDR(cpu->regs[27], (SP + 176)); PB_LDR(cpu->regs[28], (SP + 176) + 8);
    SP = SP + 192ULL;
    return;
    SP = SP - 128ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_STR((SP + 112), cpu->regs[27]); PB_STR((SP + 112) + 8, cpu->regs[28]);
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 2536));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e8f0;
    cpu->regs[26] = PB_BASE + 0x51e000ULL;
    cpu->regs[0] = cpu->regs[26] + 3856ULL;
    cpu->regs[0] = cpu->regs[0] + 2568ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = 176ULL;
L_9e770:
    cpu->regs[24] = (uint64_t)(uint32_t)cpu->regs[19] * (uint64_t)(uint32_t)cpu->regs[1];
    PB_LDRW(cpu->regs[28], (cpu->regs[24] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_EQ) goto L_9e79c;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[19], 5ULL);
    if (FLAG_NE) goto L_9e770;
    cpu->regs[24] = 704ULL;
    cpu->regs[19] = 4ULL;
    cpu->regs[27] = 0ULL;
    goto L_9e7a0;
L_9e79c:
    cpu->regs[27] = 1ULL;
L_9e7a0:
    cpu->regs[30] = PB_BASE + 0x9e7a4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[26] + 3856ULL;
    cpu->regs[3] = 176ULL;
    cpu->regs[1] = cpu->regs[1] + 2568ULL;
    PB_LDRW(cpu->regs[20], (cpu->regs[23] + 2552));
    PB_LDRW(cpu->regs[25], (cpu->regs[22] + 0));
    cpu->regs[3] = cpu->regs[19] * cpu->regs[3] + cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 4));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e7e0;
    cpu->regs[24] = cpu->regs[24] + 16ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[24];
    cpu->regs[2] = 0ULL;
    PB_STRW((cpu->regs[3] + 4), 0ULL);
    cpu->regs[30] = PB_BASE + 0x9e7e0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c030ULL);
L_9e7e0:
    cpu->regs[24] = PB_BASE + 0x2a3000ULL;
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_9e838;
    cpu->regs[2] = 20ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[26] = cpu->regs[26] + 3856ULL;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 1168ULL;
    cpu->regs[30] = PB_BASE + 0x9e800ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[0] = 176ULL;
    cpu->regs[19] = cpu->regs[19] * cpu->regs[0] + cpu->regs[26];
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2576));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9e814ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9e824ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = cpu->regs[24] + 1520ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x9e834ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_9e894;
L_9e838:
    PB_STR((SP + 0), 0ULL); PB_STR((SP + 0) + 8, 0ULL);
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = 23ULL;
    cpu->regs[0] = SP;
    cpu->regs[2] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = cpu->regs[2] + 3056ULL;
    PB_STR((SP + 15), 0ULL);
    cpu->regs[30] = PB_BASE + 0x9e858ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 1528ULL;
    cpu->regs[2] = 43ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9e86cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x9e874ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[1] = SP;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9e884ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = cpu->regs[24] + 1520ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x9e894ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_9e894:
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 2556));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9e8a0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x91324ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 2560));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9e8acULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x9e4b8ULL);
    PB_STRW((cpu->regs[22] + 0), cpu->regs[25]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_9e90c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    SP = SP + 128ULL;
    { PB_CALL(29, cpu, tlb, PB_BASE + 0x7b6a0ULL); return; };
L_9e8f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9e910;
L_9e90c:
    cpu->regs[30] = PB_BASE + 0x9e910ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9e910:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
}
