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

void ft_PyEval_AcquireLock(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x94ed8ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[0])!=0) goto L_94ef8;
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 1104ULL;
    cpu->regs[1] = cpu->regs[1] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x94ef8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x91ebcULL);
L_94ef8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xd8448ULL); return; };
    SP = SP - 48ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + 896ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    PB_STRW((SP + 4), 0ULL);
    cpu->regs[30] = PB_BASE + 0x94f3cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_94f80;
    PB_LDRW(cpu->regs[0], (SP + 4));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_94f68;
    cpu->regs[30] = PB_BASE + 0x94f4cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x94f54ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x87da4ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x94f5cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b6a0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x94f64ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    goto L_94f74;
L_94f68:
    cpu->regs[30] = PB_BASE + 0x94f6cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x87da4ULL);
    cpu->regs[0] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x94f74ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b6a0ULL);
L_94f74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_94f84;
L_94f80:
    cpu->regs[0] = 0ULL;
L_94f84:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_94fa4;
    cpu->regs[30] = PB_BASE + 0x94fa4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_94fa4:
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16));
    if (((cpu->regs[0] >> 31) & 1)) goto L_94fec;
    cpu->regs[30] = PB_BASE + 0x94fd0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x94fdcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7bdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x94fe8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_94ff8;
L_94fec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_95000;
L_94ff8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_95000:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x9501cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x95024ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7bc00ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9502cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 80ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[3] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 912ULL;
    cpu->regs[30] = PB_BASE + 0x95084ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_950d4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x95094ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x17f520ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_950dc;
    cpu->regs[30] = PB_BASE + 0x9509cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x950acULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x17f520ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x950b8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_950dc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 936ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x950d4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_950d4:
    cpu->regs[0] = 0ULL;
    goto L_950ec;
L_950dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]); PB_STR((cpu->regs[19] + 24) + 8, cpu->regs[2]);
L_950ec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9510c;
    cpu->regs[30] = PB_BASE + 0x9510cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9510c:
    PB_LDR(cpu->regs[21], (SP + 64));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
    if ((cpu->regs[1])==0) goto L_9517c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 32));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[30] = PB_BASE + 0x9514cULL; PB_CALL(25, cpu, tlb, cpu->regs[2]);
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2840));
    cpu->regs[30] = PB_BASE + 0x95158ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 2708));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9516c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9516cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x8f5ccULL);
L_9516c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2840));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(28, cpu, tlb, PB_BASE + 0x17faa0ULL); return; };
L_9517c:
    return;
L_95180:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = 1ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2840));
    cpu->regs[30] = PB_BASE + 0x951b4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 2708));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_951d0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x951c8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x8f630ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_951e8;
L_951d0:
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 65ULL;
    cpu->regs[1] = cpu->regs[1] + 960ULL;
    cpu->regs[30] = PB_BASE + 0x951e8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_951e8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2840));
    cpu->regs[30] = PB_BASE + 0x951f0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x17faa0ULL);
    if ((cpu->regs[20])==0) goto L_952a8;
    cpu->regs[25] = PB_BASE + 0x2a2000ULL;
    cpu->regs[24] = PB_BASE + 0x2a2000ULL;
    cpu->regs[23] = PB_BASE + 0x2a2000ULL;
    cpu->regs[26] = cpu->regs[25] + 1024ULL;
    cpu->regs[24] = cpu->regs[24] + 1088ULL;
    cpu->regs[23] = cpu->regs[23] + 1104ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 52ULL;
    cpu->regs[1] = cpu->regs[1] + 1032ULL;
    cpu->regs[30] = PB_BASE + 0x95224ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_95224:
    PB_LDRH(cpu->regs[3], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 8ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_LE) goto L_95288;
    cpu->regs[22] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x95244ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[22] = cpu->regs[20] + (uint64_t)((int64_t)(int32_t)cpu->regs[21] * (int64_t)(int32_t)cpu->regs[22]);
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 12));
    cpu->regs[30] = PB_BASE + 0x95258ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x90d30ULL);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = 8ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x95268ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x90ba8ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 20));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x95274ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x90c10ULL);
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x95284ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_95224;
L_95288:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[25] + 1024ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = 1ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(39, cpu, tlb, PB_BASE + 0x90ba8ULL); return; };
L_952a8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[1] = cpu->regs[1] + 1120ULL;
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 0));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x95300ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    if ((cpu->regs[20])!=0) goto L_95328;
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 10ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    { PB_CALL(41, cpu, tlb, PB_BASE + 0x7ba50ULL); return; };
L_95328:
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + -8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 1160ULL;
    cpu->regs[21] = cpu->regs[20] - 8ULL;
    cpu->regs[30] = PB_BASE + 0x95340ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    PB_LDRB(cpu->regs[23], (cpu->regs[20] + -16));
    cpu->regs[0] = cpu->regs[20] - 15ULL;
L_95348:
    PB_LDRB(cpu->regs[1], cpu->regs[0]); cpu->regs[0] += 1;
    cpu->regs[23] = cpu->regs[1] | (cpu->regs[23] << 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_95348;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 1176ULL;
    cpu->regs[30] = PB_BASE + 0x9536cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[3] = 7ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 1216ULL;
    cpu->regs[30] = PB_BASE + 0x95384ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[0] = cpu->regs[20] - 1ULL;
L_95388:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(253ULL)));
    if (FLAG_NE) goto L_9556c;
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_95388;
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1592ULL;
    cpu->regs[2] = 28ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x953b8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x7b510ULL);
L_953b8:
    cpu->regs[22] = cpu->regs[20] + cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 8ULL;
    cpu->regs[1] = cpu->regs[1] + 1448ULL;
    cpu->regs[30] = PB_BASE + 0x953d4ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[0] = 0ULL;
L_953d8:
    PB_LDRB(cpu->regs[1], (cpu->regs[22] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(253ULL)));
    if (FLAG_NE) goto L_954f4;
    FLAG_CMP(cpu->regs[0], 8ULL);
    if (FLAG_NE) goto L_953d8;
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1592ULL;
    cpu->regs[2] = 28ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x95408ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x7b510ULL);
L_95408:
    if ((cpu->regs[23])==0) goto L_954b8;
    cpu->regs[23] = PB_BASE + 0x2a2000ULL;
    cpu->regs[21] = cpu->regs[20];
    cpu->regs[23] = cpu->regs[23] + 1536ULL;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 14ULL;
    cpu->regs[0] = cpu->regs[0] + 1520ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x95430ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x7b510ULL);
L_95430:
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] - cpu->regs[20]));
    cpu->regs[1] = cpu->regs[23];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(8ULL)));
    cpu->regs[0] = cpu->regs[19];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], cpu->regs[22]); } else { FLAG_CMP(1, 0); }
    if (FLAG_HS) goto L_95454;
    PB_LDRB(cpu->regs[2], cpu->regs[21]); cpu->regs[21] += 1;
    cpu->regs[30] = PB_BASE + 0x95450ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    goto L_95430;
L_95454:
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_LO) goto L_9546c;
L_9545c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x95468ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x7ba50ULL);
    goto L_954b8;
L_9546c:
    cpu->regs[0] = cpu->regs[22] - cpu->regs[21];
    FLAG_CMP(cpu->regs[0], 8ULL);
    if (FLAG_LE) goto L_95494;
    cpu->regs[21] = cpu->regs[22] - 8ULL;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[0] = cpu->regs[0] + 1544ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x95494ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x7b510ULL);
L_95494:
    cpu->regs[23] = PB_BASE + 0x2a2000ULL;
    cpu->regs[23] = cpu->regs[23] + 1536ULL;
L_9549c:
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_HS) goto L_9545c;
    PB_LDRB(cpu->regs[2], cpu->regs[21]); cpu->regs[21] += 1;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x954b4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    goto L_9549c;
L_954b8:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x954c4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x7ba50ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x954ccULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x7b050ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x954d4ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x7bf20ULL);
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    goto L_95180;
L_954f4:
    cpu->regs[25] = PB_BASE + 0x2a2000ULL;
    cpu->regs[24] = PB_BASE + 0x2a2000ULL;
    cpu->regs[25] = cpu->regs[25] + 1488ULL;
    cpu->regs[24] = cpu->regs[24] + 1280ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 253ULL;
    cpu->regs[1] = cpu->regs[1] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0x9551cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x7b6e0ULL);
L_9551c:
    PB_LDRB(cpu->regs[26], (cpu->regs[22] + cpu->regs[21]));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x95534ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(253ULL)));
    if (FLAG_EQ) goto L_95550;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[2] = 9ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x95550ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x7b510ULL);
L_95550:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x95560ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x7ba50ULL);
    FLAG_CMP(cpu->regs[21], 8ULL);
    if (FLAG_NE) goto L_9551c;
    goto L_95408;
L_9556c:
    cpu->regs[24] = PB_BASE + 0x2a2000ULL;
    cpu->regs[22] = PB_BASE + 0x2a2000ULL;
    cpu->regs[26] = cpu->regs[20] - 7ULL;
    cpu->regs[24] = cpu->regs[24] + 1256ULL;
    cpu->regs[22] = cpu->regs[22] + 1280ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[27] = 7ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 253ULL;
    cpu->regs[1] = cpu->regs[1] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0x9559cULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x7b6e0ULL);
L_9559c:
    PB_LDRB(cpu->regs[25], (cpu->regs[26] + cpu->regs[21]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[27] - cpu->regs[21]));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x955b4ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(253ULL)));
    if (FLAG_EQ) goto L_955d0;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 9ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x955d0ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x7b510ULL);
L_955d0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x955e0ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x7ba50ULL);
    FLAG_CMP(cpu->regs[21], 7ULL);
    if (FLAG_NE) goto L_9559c;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 146ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 1296ULL;
    cpu->regs[30] = PB_BASE + 0x95600ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x7b510ULL);
    goto L_953b8;
}
