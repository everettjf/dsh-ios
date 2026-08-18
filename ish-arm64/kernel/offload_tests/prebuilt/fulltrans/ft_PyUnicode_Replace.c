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

void ft_PyUnicode_Replace(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x7fa84ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7facc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x7fa94ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7facc;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[30] = PB_BASE + 0x7faa4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7facc;
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x140940ULL); return; };
L_7facc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 240ULL;
    cpu->regs[8] = 1ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 192), cpu->regs[29]); PB_STR((SP + 192) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 192ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[3] = PB_BASE + 0x521000ULL;
    cpu->regs[3] = cpu->regs[3] + 272ULL;
    PB_STR((SP + 208), cpu->regs[19]); PB_STR((SP + 208) + 8, cpu->regs[20]);
    cpu->regs[19] = SP + 24ULL;
    cpu->regs[3] = cpu->regs[3] + 1840ULL;
    PB_STR((SP + 224), cpu->regs[21]); PB_STR((SP + 224) + 8, cpu->regs[22]);
    cpu->regs[5] = cpu->regs[19];
    cpu->regs[7] = SP + 12ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 184), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[6] = SP + 16ULL;
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[4] = SP + 20ULL;
    cpu->regs[2] = cpu->regs[2] + 2416ULL;
    PB_STRW((SP + 12), 0ULL); PB_STRW((SP + 12) + 4, cpu->regs[8]);
    PB_STR((SP + 24), 0ULL);
    cpu->regs[30] = PB_BASE + 0x7fb48ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x13eb20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7fbd8;
    PB_LDRW(cpu->regs[0], (SP + 20));
    cpu->regs[30] = PB_BASE + 0x7fb54ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7fc8cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7fbd8;
    cpu->regs[30] = PB_BASE + 0x7fb5cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c8584ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7fbd8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7fb6cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c7a00ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7fbd8;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2648));
    if ((cpu->regs[0])!=0) goto L_7fbac;
    cpu->regs[1] = 192ULL;
    cpu->regs[0] = 65ULL;
    cpu->regs[30] = PB_BASE + 0x7fb94ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdbdc0ULL);
    PB_STR((cpu->regs[19] + 2648), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7fbac;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x7fba4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[30] = PB_BASE + 0x7fba8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_7fc58;
L_7fbac:
    PB_LDRW(cpu->regs[1], (SP + 20));
    cpu->regs[2] = 192ULL;
    cpu->regs[1] = (uint64_t)((int64_t)(int32_t)cpu->regs[1] * (int64_t)(int32_t)cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0] + cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + cpu->regs[1]));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_7fc24;
    cpu->regs[30] = PB_BASE + 0x7fbc8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1c8830ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7fbe0;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x7fbd8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
L_7fbd8:
    cpu->regs[0] = 0ULL;
    goto L_7fc58;
L_7fbe0:
    PB_LDRW(cpu->regs[1], (SP + 12));
    cpu->regs[22] = SP + 32ULL;
    PB_LDRW(cpu->regs[0], (SP + 20));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7fbf4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7fd18ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7fc14;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7fc08ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1b2720ULL);
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x7fc10ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_7fbd8;
L_7fc14:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    cpu->regs[2] = 152ULL;
    cpu->regs[30] = PB_BASE + 0x7fc24ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c090ULL);
L_7fc24:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_STR((cpu->regs[19] + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x7fc34ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[4] = 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    PB_LDRW(cpu->regs[2], (SP + 12)); PB_LDRW(cpu->regs[3], (SP + 12) + 4);
    PB_STRW((cpu->regs[19] + 0), cpu->regs[4]);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]); PB_STRW((cpu->regs[19] + 16) + 4, cpu->regs[3]);
    PB_STRW((cpu->regs[19] + 24), cpu->regs[2]);
    PB_STR((cpu->regs[19] + 184), cpu->regs[1]);
L_7fc58:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 184));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_7fc78;
    cpu->regs[30] = PB_BASE + 0x7fc78ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_7fc78:
    PB_LDR(cpu->regs[29], (SP + 192)); PB_LDR(cpu->regs[30], (SP + 192) + 8);
    PB_LDR(cpu->regs[19], (SP + 208)); PB_LDR(cpu->regs[20], (SP + 208) + 8);
    PB_LDR(cpu->regs[21], (SP + 224)); PB_LDR(cpu->regs[22], (SP + 224) + 8);
    SP = SP + 240ULL;
    return;
L_7fc8c:
    cpu->regs[1] = PB_BASE + 0x51e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3856ULL;
    cpu->regs[1] = cpu->regs[1] + 2568ULL;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = 176ULL;
    cpu->regs[29] = SP;
L_7fcac:
    cpu->regs[4] = (uint64_t)(uint32_t)cpu->regs[3] * (uint64_t)(uint32_t)cpu->regs[0];
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_7fcdc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7fcd8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_7fd0c;
L_7fcdc:
    FLAG_CMP(cpu->regs[3], 5ULL);
    if (FLAG_NE) goto L_7fcac;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[0] = 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(63ULL)));
    if (FLAG_LS) goto L_7fd10;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7fd0cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_7fd0c:
    cpu->regs[0] = 0ULL;
L_7fd10:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_7fd18:
    SP = SP - 208ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 160), cpu->regs[29]); PB_STR((SP + 160) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 160ULL;
    PB_STR((SP + 176), cpu->regs[19]); PB_STR((SP + 176) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 192), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x91000ULL;
    cpu->regs[1] = cpu->regs[1] + 920ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 152), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x7fd60ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7b610ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    cpu->regs[0] = 1073741824ULL;
    cpu->regs[3] = 268435456ULL;
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[0];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | 134217728ULL));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19];
    PB_STRW((SP + 136), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x7fd88ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c030ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 152));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_7fda8;
    cpu->regs[30] = PB_BASE + 0x7fda8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7c170ULL);
L_7fda8:
    PB_LDR(cpu->regs[21], (SP + 192));
    PB_LDR(cpu->regs[29], (SP + 160)); PB_LDR(cpu->regs[30], (SP + 160) + 8);
    PB_LDR(cpu->regs[19], (SP + 176)); PB_LDR(cpu->regs[20], (SP + 176) + 8);
    SP = SP + 208ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3488));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_7fe48;
    if ((cpu->regs[21])==0) goto L_7fe00;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7fdfcULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1227a0ULL);
    goto L_7fe04;
L_7fe00:
    cpu->regs[0] = 0ULL;
L_7fe04:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[20], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_7fe18;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7fe18ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1227a0ULL);
L_7fe18:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_7fe48;
    if (FLAG_GT) goto L_7fe2c;
L_7fe24:
    cpu->regs[19] = 0ULL;
    goto L_7ff60;
L_7fe2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2520ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x7fe44ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_7fe24;
L_7fe48:
    cpu->regs[1] = PB_BASE + 0x51d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3600ULL;
    cpu->regs[1] = cpu->regs[1] + 2440ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7fe5cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 304));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 32));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7fe74ULL; PB_CALL(29, cpu, tlb, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7fe24;
    if ((cpu->regs[21])==0) goto L_7fe90;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_7fe90;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_7fe90:
    PB_STR((cpu->regs[19] + 24), cpu->regs[21]);
    if ((cpu->regs[20])==0) goto L_7fea8;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_7fea8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_7fea8:
    PB_STR((cpu->regs[19] + 32), cpu->regs[20]);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 2568ULL;
    cpu->regs[30] = PB_BASE + 0x7febcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7fed0;
L_7fec4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_7ff48;
    goto L_7fe24;
L_7fed0:
    cpu->regs[30] = PB_BASE + 0x7fed4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_7fec4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7fee8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe1700ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7fec4;
    cpu->regs[0] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[0] + 272ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 1880ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7ff0cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xddd20ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_7ff2c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7ff2c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7ff2cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7ff2c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_7fec4;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7ff40ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x800bcULL);
    if ((cpu->regs[0])!=0) goto L_7ff60;
    goto L_7fec4;
L_7ff48:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7fe24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7ff5cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7fe24;
L_7ff60:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 64ULL;
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[2], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[5] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if (FLAG_LE) goto L_7ffb4;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_7ffec;
L_7ffb4:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[6] = 1ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 1912ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7ffe4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_80088;
L_7ffec:
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x80000ULL; PB_CALL(38, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[20], (cpu->regs[5] + 0));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] + 2584ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x8001cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x181ea8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_80050;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3640));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x80038ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x121d80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_80088;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x80044ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1d2f00ULL);
L_80044:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_8008c;
L_80050:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    cpu->regs[19] = cpu->regs[19] + (64ULL << 12);
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 5064));
    if ((cpu->regs[4])!=0) goto L_80078;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x80068ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((cpu->regs[19] + 5064), cpu->regs[0]);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_80088;
    cpu->regs[30] = PB_BASE + 0x80078ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcd00ULL);
L_80078:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x80084ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xe548cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_80044;
L_80088:
    cpu->regs[0] = 0ULL;
L_8008c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_800ac;
    cpu->regs[30] = PB_BASE + 0x800acULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x7c170ULL);
L_800ac:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_800bc:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x800dcULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x215100ULL);
    if ((cpu->regs[0])!=0) goto L_800fc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2608ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x800f8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_801b8;
L_800fc:
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x80104ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_801b8;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 304));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x8011cULL; PB_CALL(49, cpu, tlb, cpu->regs[2]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_801c8;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 56));
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x80130ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe1700ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_801cc;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 48));
    cpu->regs[30] = PB_BASE + 0x80148ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_801cc;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_80168;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_80168;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x80168ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_80168:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x80178ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_801c8;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_80198;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_80198;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x80198ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_80198:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_801e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_801e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x801b4ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_801e8;
L_801b8:
    cpu->regs[21] = 0ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_801cc;
L_801c8:
    cpu->regs[20] = 0ULL;
L_801cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x801d8ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x801e0ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x801e8ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x18d760ULL);
L_801e8:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP = SP - 64ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = PB_BASE + 0x51e000ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[2] = cpu->regs[2] + 3856ULL;
    cpu->regs[2] = cpu->regs[2] - 96ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[3] = 96ULL;
    cpu->regs[30] = PB_BASE + 0x8024cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x7f1e8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_802c0;
    cpu->regs[30] = PB_BASE + 0x80254ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[19], (SP + 4));
    PB_STRW((cpu->regs[20] + 0), 0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x80268ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x7b880ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_80294;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_8028c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x8028cULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_8028c:
    cpu->regs[30] = PB_BASE + 0x80290ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_802c0;
L_80294:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_802d4;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(64, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_802c0:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_802d8;
L_802d4:
    cpu->regs[30] = PB_BASE + 0x802d8ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x7c170ULL);
L_802d8:
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
}
