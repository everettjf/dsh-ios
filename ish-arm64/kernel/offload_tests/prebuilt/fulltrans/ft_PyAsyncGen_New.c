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

void ft_PyAsyncGen_New(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2800));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[29] = SP;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x9bfccULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x9be60ULL);
    if ((cpu->regs[0])==0) goto L_9bfdc;
    PB_STR((cpu->regs[0] + 56), 0ULL);
    PB_STRH((cpu->regs[0] + 64), 0ULL);
    PB_STRB((cpu->regs[0] + 66), 0ULL);
L_9bfdc:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x9bff8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x279ea0ULL);
    if ((cpu->regs[0])!=0) goto L_9c018;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 1480ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9c014ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9c09c;
L_9c018:
    cpu->regs[19] = cpu->regs[0];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 45));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c030;
L_9c024:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_9c0a0;
L_9c030:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9c040;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_9c040:
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x9c054ULL; PB_CALL(4, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 24));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 72));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 88));
    cpu->regs[30] = PB_BASE + 0x9c074ULL; PB_CALL(5, cpu, tlb, cpu->regs[4]);
    PB_STRW((cpu->regs[19] + 40), 0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_9c098;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9c098;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9c098ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9c098:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_9c024;
L_9c09c:
    cpu->regs[0] = 0ULL;
L_9c0a0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_9c0ac:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x9c0d4ULL; PB_CALL(7, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[20], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 64));
    if ((cpu->regs[0])!=0) goto L_9c0ec;
L_9c0e0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_9c168;
L_9c0ec:
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x9c0f4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x279ea0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9c118;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 904ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9c114ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9c164;
L_9c118:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_9c128;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
L_9c128:
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 64));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 80));
    cpu->regs[3] = cpu->regs[21];
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 24));
    cpu->regs[30] = PB_BASE + 0x9c140ULL; PB_CALL(10, cpu, tlb, cpu->regs[4]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9c160;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9c160;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9c160ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9c160:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_9c0e0;
L_9c164:
    cpu->regs[0] = 0ULL;
L_9c168:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2864));
    PB_LDR(cpu->regs[5], (cpu->regs[6] + 16));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x9c1a0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c244;
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3592));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_9c220;
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 24));
    cpu->regs[0] = PB_BASE + 0x451000ULL;
    cpu->regs[0] = cpu->regs[0] + 576ULL;
    cpu->regs[0] = cpu->regs[0] + 848ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_9c258;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 272));
    cpu->regs[30] = PB_BASE + 0x9c1e0ULL; PB_CALL(13, cpu, tlb, cpu->regs[3]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9c1f0;
L_9c1e8:
    cpu->regs[19] = 0ULL;
    goto L_9c260;
L_9c1f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9c1fcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x9c0acULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9c260;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9c260;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9c21cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9c260;
L_9c220:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3984));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_9c258;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 16));
    if ((cpu->regs[5])==0) goto L_9c1e8;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x9c240ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9c258;
L_9c244:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[5];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    goto L_9c0ac;
L_9c258:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_9c260:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    goto L_9c0ac;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    goto L_9c0ac;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    goto L_9c0ac;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_9c2a4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4064));
    { PB_CALL(17, cpu, tlb, PB_BASE + 0x11d9e0ULL); return; };
L_9c2a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_9c2c4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2912));
    { PB_CALL(18, cpu, tlb, PB_BASE + 0x11d9e0ULL); return; };
L_9c2c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_9c2e4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2200));
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x11d9e0ULL); return; };
L_9c2e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2200));
    { PB_CALL(20, cpu, tlb, PB_BASE + 0x11d9e0ULL); return; };
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 2ULL;
    { PB_CALL(21, cpu, tlb, PB_BASE + 0xe1204ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])!=0) goto L_9c338;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9c334ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x137ba0ULL);
    goto L_9c348;
L_9c338:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 16) + 8);
    cpu->regs[30] = PB_BASE + 0x9c340ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d8300ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9c350;
L_9c348:
    cpu->regs[19] = 0ULL;
    goto L_9c378;
L_9c350:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[1] = 1ULL;
    PB_STRB((cpu->regs[19] + 48), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_9c378;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9c378;
    cpu->regs[30] = PB_BASE + 0x9c378ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9c378:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    if ((cpu->regs[2])==0) goto L_9c394;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0x1d8300ULL); return; };
L_9c394:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 952ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9c3b4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    { PB_CALL(27, cpu, tlb, PB_BASE + 0xe13e0ULL); return; };
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 8), 0ULL); PB_STR((SP + 8) + 8, 0ULL);
    if ((cpu->regs[2])!=0) goto L_9c42c;
L_9c404:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3216));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x9c424ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c448;
    goto L_9c440;
L_9c42c:
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + 3960ULL;
    cpu->regs[30] = PB_BASE + 0x9c43cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c404;
L_9c440:
    cpu->regs[0] = 4294967295ULL;
    goto L_9c45c;
L_9c448:
    PB_LDR(cpu->regs[2], (SP + 8)); PB_LDR(cpu->regs[1], (SP + 8) + 8);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9c454ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x192aa8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
L_9c45c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9c47c;
    cpu->regs[30] = PB_BASE + 0x9c47cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9c47c:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    if ((cpu->regs[2])!=0) goto L_9c4c8;
L_9c4ac:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9c4bcULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x137bd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
    goto L_9c4e0;
L_9c4c8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x9c4d8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c4ac;
    cpu->regs[0] = 4294967295ULL;
L_9c4e0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2264));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_9c534;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 296));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_9c534;
L_9c524:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_9c54c;
    goto L_9c564;
L_9c534:
    if ((cpu->regs[1])==0) goto L_9c524;
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 1016ULL;
    cpu->regs[30] = PB_BASE + 0x9c544ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c524;
    goto L_9c5a0;
L_9c54c:
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 1016ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x9c560ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9c5a0;
L_9c564:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x9c570ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x11d7acULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c590;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[1] = cpu->regs[1] + 3784ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9c58cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9c5a0;
L_9c590:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(38, cpu, tlb, PB_BASE + 0x99f54ULL); return; };
L_9c5a0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 0), 0ULL);
    if ((cpu->regs[2])!=0) goto L_9c604;
L_9c5e4:
    cpu->regs[1] = cpu->regs[20] + 1032ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = SP;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9c5fcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c61c;
    goto L_9c614;
L_9c604:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[20] + 1032ULL;
    cpu->regs[30] = PB_BASE + 0x9c610ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c5e4;
L_9c614:
    cpu->regs[0] = 0ULL;
    goto L_9c624;
L_9c61c:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x9c624ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x118390ULL);
L_9c624:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9c644;
    cpu->regs[30] = PB_BASE + 0x9c644ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9c644:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 48ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[20] = PB_BASE + 0x282000ULL;
    if ((cpu->regs[2])!=0) goto L_9c6b0;
L_9c690:
    cpu->regs[1] = cpu->regs[20] + 3784ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = SP;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9c6a8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c6c8;
    goto L_9c6c0;
L_9c6b0:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[20] + 3784ULL;
    cpu->regs[30] = PB_BASE + 0x9c6bcULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9c690;
L_9c6c0:
    cpu->regs[0] = 0ULL;
    goto L_9c6f0;
L_9c6c8:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x9c6d0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_9c6c0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_9c6f0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9c710;
    cpu->regs[30] = PB_BASE + 0x9c710ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9c710:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
}
