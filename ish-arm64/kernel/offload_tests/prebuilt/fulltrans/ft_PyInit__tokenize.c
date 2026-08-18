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

void ft_PyInit__tokenize(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x520000ULL;
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[0] = cpu->regs[0] + 3592ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1f90a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    if ((cpu->regs[0])==0) goto L_1f90e8;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x520000ULL;
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3696ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f90c4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f90e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f90d8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1ab080ULL);
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
L_1f90dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1f90e8:
    cpu->regs[0] = 4294967295ULL;
    goto L_1f90dc;
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 28216ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1f9140ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe31ccULL);
    if ((cpu->regs[0])==0) goto L_1f91b0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[21], 0ULL);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[21] = (FLAG_NE) ? cpu->regs[21] : cpu->regs[1];
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[20] = (FLAG_NE) ? cpu->regs[20] : cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[19]); PB_STR((SP + 0) + 8, cpu->regs[21]);
    PB_STR((SP + 16), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1f9174ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11028cULL);
    cpu->regs[19] = cpu->regs[0];
L_1f9178:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f91ac;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_1f91ac:
    cpu->regs[30] = PB_BASE + 0x1f91b0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f91b0:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 272));
    cpu->regs[0] = PB_BASE + 0x1f9000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f91d8;
L_1f91c4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1f9178;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1f9178;
L_1f91d8:
    PB_STR((cpu->regs[22] + 272), 0ULL);
    goto L_1f91c4;
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
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1f922cULL; PB_CALL(8, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 96));
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_EQ) goto L_1f92c4;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 96));
    if ((cpu->regs[0])==0) goto L_1f92c4;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 104));
    cpu->regs[0] = PB_BASE + 0x1f9000ULL;
    cpu->regs[0] = cpu->regs[0] + 480ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[2])==0) goto L_1f9268;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 104));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f92e8;
L_1f9268:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_1f92dc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 31776ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1f928cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
L_1f9290:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1f933c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_1f92c4:
    if ((cpu->regs[2])==0) goto L_1f92dc;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 104));
    cpu->regs[0] = PB_BASE + 0x1f9000ULL;
    cpu->regs[0] = cpu->regs[0] + 480ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f9334;
L_1f92dc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    goto L_1f9290;
L_1f92e8:
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_1f9364;
L_1f92f4:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
L_1f9308:
    cpu->regs[22] = 0ULL;
L_1f930c:
    cpu->regs[4] = 25920ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1f9320ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_1f9344;
L_1f932c:
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    goto L_1f9290;
L_1f9334:
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    goto L_1f92f4;
L_1f933c:
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1f9344ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f9344:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_1f938c;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1f9394;
L_1f935c:
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    goto L_1f9268;
L_1f9364:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1f936cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f93ac;
L_1f9378:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[22] = 1ULL;
    goto L_1f930c;
L_1f938c:
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    goto L_1f92dc;
L_1f9394:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1f935c;
    cpu->regs[30] = PB_BASE + 0x1f93a4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    goto L_1f9268;
L_1f93ac:
    cpu->regs[6] = 31776ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[24] + cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x1f93c0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x250360ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1f9424;
    if (FLAG_EQ) goto L_1f9378;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[5] = 31776ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[5];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1f93f0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_1f932c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[2], (SP + 8));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f9308;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1f9308;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1f941cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    goto L_1f9308;
L_1f9424:
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    cpu->regs[1] = 0ULL;
    goto L_1f9290;
    SP = SP - 64ULL;
    cpu->regs[3] = 27248ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f9464ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1f9480ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x122b00ULL);
    if ((cpu->regs[0])==0) goto L_1f94b8;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f9498ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d3764ULL);
    if ((cpu->regs[0])==0) goto L_1f9510;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1f94fc;
L_1f94a4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f94b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f94f0;
L_1f94b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f94ec;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(20, cpu, tlb, PB_BASE + 0x121f40ULL); return; };
L_1f94ec:
    cpu->regs[30] = PB_BASE + 0x1f94f0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f94f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f94f8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f94b8;
L_1f94fc:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1f94a4;
    cpu->regs[30] = PB_BASE + 0x1f950cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f94a4;
L_1f9510:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f9518ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1f94a4;
    /* nop */
    SP = SP - 96ULL;
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 16));
    if ((cpu->regs[2])!=0) goto L_1f9764;
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_HI) goto L_1f97f0;
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    cpu->regs[21] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_1f9770;
L_1f9570:
    if ((cpu->regs[21])==0) goto L_1f96cc;
L_1f9574:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 0));
    if ((cpu->regs[20])==0) goto L_1f97b8;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_1f96c0;
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 8));
L_1f9588:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f9590ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1cb0b0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f9708;
L_1f9594:
    if ((cpu->regs[19])==0) goto L_1f96c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f95a0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1cb0b0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f9708;
    if ((cpu->regs[20])==0) goto L_1f9728;
L_1f95a8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_1f9758;
    if ((cpu->regs[19])==0) goto L_1f95c4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_1f97b0;
L_1f95c4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f95ccULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f9670;
L_1f95d8:
    cpu->regs[1] = 1ULL;
L_1f95dc:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1f95ec;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_1f95ec:
    if ((cpu->regs[19])==0) goto L_1f96f8;
L_1f95f0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1f9668;
L_1f95fc:
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1f9618;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f9608ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x129680ULL);
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_1f9694;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f9684;
L_1f9618:
    cpu->regs[21] = 9223372036854775807ULL;
L_1f961c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 304));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f962cULL; PB_CALL(29, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1f97c4;
    PB_STR((cpu->regs[0] + 16), cpu->regs[21]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[20]);
    PB_STR((cpu->regs[0] + 32), cpu->regs[19]);
L_1f9638:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1f97c0;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_1f9668:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1f95fc;
L_1f9670:
    cpu->regs[30] = PB_BASE + 0x1f9674ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1f95d8;
    cpu->regs[30] = PB_BASE + 0x1f967cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[1] = 0ULL;
    goto L_1f95dc;
L_1f9684:
    cpu->regs[30] = PB_BASE + 0x1f9688ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1f9618;
    cpu->regs[30] = PB_BASE + 0x1f9690ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1f9618;
L_1f9694:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1f96a4;
L_1f969c:
    cpu->regs[20] = 0ULL;
    goto L_1f961c;
L_1f96a4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1f969c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f96bcULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f961c;
L_1f96c0:
    cpu->regs[19] = 0ULL;
    goto L_1f9588;
L_1f96c8:
    if ((cpu->regs[20])!=0) goto L_1f95a8;
L_1f96cc:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 3208));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1f96e4;
    PB_STRW((cpu->regs[19] + 3208), cpu->regs[0]);
L_1f96e4:
    cpu->regs[20] = cpu->regs[19] + 3208ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 3240ULL;
    cpu->regs[1] = 1ULL;
    goto L_1f95f0;
L_1f96f8:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[19] = cpu->regs[19] + 3240ULL;
    goto L_1f95f0;
L_1f9708:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 416ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f9720ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1f9720:
    cpu->regs[0] = 0ULL;
    goto L_1f9638;
L_1f9728:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    cpu->regs[20] = cpu->regs[20] + 3208ULL;
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] >> 24) & 0x1ULL)));
L_1f9740:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1f95f0;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_1f95f0;
L_1f9758:
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = 0ULL;
    goto L_1f95dc;
L_1f9764:
    PB_LDR(cpu->regs[21], (cpu->regs[2] + 16));
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    cpu->regs[21] = cpu->regs[19] + cpu->regs[21];
L_1f9770:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[4] + 3728ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f97a4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_1f9570;
    cpu->regs[0] = 0ULL;
    goto L_1f9638;
L_1f97b0:
    cpu->regs[1] = 0ULL;
    goto L_1f9740;
L_1f97b8:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 8));
    goto L_1f9594;
L_1f97c0:
    cpu->regs[30] = PB_BASE + 0x1f97c4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f97c4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f97ccULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f9720;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1f9720;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f97e8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1f9638;
L_1f97f0:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    cpu->regs[4] = cpu->regs[4] + 3728ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f9820ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_1f9720;
    cpu->regs[21] = cpu->regs[19];
    goto L_1f9574;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 320));
    return;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[2] = cpu->regs[0];
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1f9858ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x14b6c4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f9884;
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
L_1f987c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1f9884:
    cpu->regs[30] = PB_BASE + 0x1f9888ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_1f987c;
    /* nop */
}
