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

void ft_PyInterpreterState_Delete(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1f61ecULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 96));
    PB_STR((SP + 32), cpu->regs[21]);
    if ((cpu->regs[2])==0) goto L_1f6224;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[19]);
    if (FLAG_NE) goto L_1f6224;
    PB_STR((cpu->regs[1] + cpu->regs[0]), 0ULL);
    cpu->regs[0] = cpu->regs[19] + 368ULL;
    cpu->regs[1] = 0ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 24));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] & 4294967279ULL));
    PB_STRW((cpu->regs[2] + 24), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1f6224ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x14770cULL);
L_1f6224:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f622cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1f658cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 408));
    if ((cpu->regs[0])==0) goto L_1f623c;
    cpu->regs[30] = PB_BASE + 0x1f6238ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1c208cULL);
    PB_STR((cpu->regs[19] + 408), 0ULL);
L_1f623c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f6244ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x187b80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f6260;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f6250ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1f69e0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 392));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    PB_STR((cpu->regs[2] + 392), cpu->regs[1]);
L_1f6260:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1f626cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 40));
    cpu->regs[1] = cpu->regs[20] + 40ULL;
L_1f6274:
    if ((cpu->regs[2])==0) goto L_1f62e4;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_1f6348;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])!=0) goto L_1f6330;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_NE) goto L_1f62ac;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 40));
    PB_STR((cpu->regs[20] + 48), 0ULL);
    if ((cpu->regs[1])!=0) goto L_1f6318;
L_1f62ac:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[30] = PB_BASE + 0x1f62b4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x17faa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])!=0) goto L_1f6310;
L_1f62bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + (18ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 1936ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_1f62fc;
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f62e4:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1056ULL;
    cpu->regs[1] = cpu->regs[1] + 3320ULL;
    cpu->regs[30] = PB_BASE + 0x1f62fcULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x91ebcULL);
L_1f62fc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0xd7784ULL); return; };
L_1f6310:
    cpu->regs[30] = PB_BASE + 0x1f6314ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1c208cULL);
    goto L_1f62bc;
L_1f6318:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1056ULL;
    cpu->regs[1] = cpu->regs[1] + 3368ULL;
    cpu->regs[30] = PB_BASE + 0x1f6330ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x91ebcULL);
L_1f6330:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1056ULL;
    cpu->regs[1] = cpu->regs[1] + 3344ULL;
    cpu->regs[30] = PB_BASE + 0x1f6348ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x91ebcULL);
L_1f6348:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[0];
    goto L_1f6274;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1f63f8;
L_1f6388:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f6400;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 23ULL;
    cpu->regs[30] = PB_BASE + 0x1f63a0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1f63e0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1f63e0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1f63bcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1f63e0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1f63e0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x1f63d8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1f63e0;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1f63e0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1f63e8:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1f63f8:
    cpu->regs[30] = PB_BASE + 0x1f63fcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1f6388;
L_1f6400:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1f63e8;
    SP = SP - 64ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = SP + 4ULL;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = 29848ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1f6458ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x122b00ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1f6534;
    if ((cpu->regs[0])==0) goto L_1f64cc;
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f6480ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d3764ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f6498;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f6570;
L_1f6498:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f6530;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_1f64cc:
    cpu->regs[30] = PB_BASE + 0x1f64d0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = 28440ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f64e4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x122b00ULL);
    if ((cpu->regs[0])==0) goto L_1f6548;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f64fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f6584;
L_1f64fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f6530;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    { PB_CALL(22, cpu, tlb, PB_BASE + 0x1fa944ULL); return; };
L_1f6530:
    cpu->regs[30] = PB_BASE + 0x1f6534ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f6534:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f6548;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f657c;
L_1f6548:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 536ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f656cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1f6498;
L_1f6570:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f6578ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f6498;
L_1f657c:
    cpu->regs[30] = PB_BASE + 0x1f6580ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f6548;
L_1f6584:
    cpu->regs[30] = PB_BASE + 0x1f6588ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f64fc;
L_1f658c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = 55584ULL;
    cpu->regs[22] = cpu->tls_ptr;
    cpu->regs[21] = (cpu->regs[21] & ~(0xffffULL << 16)) | ((0x5ULL & 0xffff) << 16);
L_1f65ac:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 72));
    if ((cpu->regs[19])!=0) goto L_1f65c4;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f65c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1f65d4ULL; PB_CALL(28, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f6604;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f65e8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1f66c0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[21];
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f65ac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f6600ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xd7784ULL);
    goto L_1f65ac;
L_1f6604:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1088ULL;
    cpu->regs[1] = cpu->regs[1] + 3440ULL;
    cpu->regs[30] = PB_BASE + 0x1f6620ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x92290ULL);
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f6688;
    cpu->regs[20] = cpu->regs[4];
    cpu->regs[0] = cpu->regs[6];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[1] = 80ULL;
    cpu->regs[30] = PB_BASE + 0x1f665cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1f66a8;
    cpu->regs[1] = 16ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[19]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[24]);
    PB_STRW((cpu->regs[0] + 64), cpu->regs[22]); PB_STRW((cpu->regs[0] + 64) + 4, cpu->regs[23]);
    PB_STRW((cpu->regs[0] + 72), cpu->regs[20]); PB_STRW((cpu->regs[0] + 72) + 4, cpu->regs[21]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1f667c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1f6688:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 3472ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f66a0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1f667c;
L_1f66a8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1f667c;
    /* nop */
    /* nop */
    /* nop */
L_1f66c0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    if ((cpu->regs[20])==0) goto L_1f6784;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 96));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[30] = PB_BASE + 0x1f66ecULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    if ((cpu->regs[0])!=0) goto L_1f677c;
    PB_STR((cpu->regs[20] + 72), cpu->regs[1]);
L_1f66f8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    if ((cpu->regs[1])==0) goto L_1f6704;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
L_1f6704:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[30] = PB_BASE + 0x1f670cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x17faa0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    if (!((cpu->regs[0] >> 3) & 1)) goto L_1f6738;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    cpu->regs[0] = cpu->regs[0] + 1544ULL;
    cpu->regs[30] = PB_BASE + 0x1f6728ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x182ae0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f679c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967287ULL));
    PB_STRW((cpu->regs[19] + 24), cpu->regs[0]);
L_1f6738:
    if (!((cpu->regs[0] >> 1) & 1)) goto L_1f6744;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 4ULL));
    PB_STRW((cpu->regs[19] + 24), cpu->regs[0]);
L_1f6744:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 232));
    PB_STR((cpu->regs[19] + 232), 0ULL);
L_1f674c:
    if ((cpu->regs[0])!=0) goto L_1f676c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 128ULL));
    PB_STRW((cpu->regs[19] + 24), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f676c:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x1f6774ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1f6820ULL);
    cpu->regs[0] = cpu->regs[20];
    goto L_1f674c;
L_1f677c:
    PB_STR((cpu->regs[0] + 8), cpu->regs[1]);
    goto L_1f66f8;
L_1f6784:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1104ULL;
    cpu->regs[1] = cpu->regs[1] + 3320ULL;
    cpu->regs[30] = PB_BASE + 0x1f679cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x91ebcULL);
L_1f679c:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1128ULL;
    cpu->regs[1] = cpu->regs[1] + 3512ULL;
    cpu->regs[30] = PB_BASE + 0x1f67b4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x91ebcULL);
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[2] = cpu->regs[0];
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1f67d8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1c11e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f6804;
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
L_1f67fc:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1f6804:
    cpu->regs[30] = PB_BASE + 0x1f6808ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_1f67fc;
    /* nop */
L_1f6820:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 360));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 376));
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    { PB_CALL(42, cpu, tlb, PB_BASE + 0x7b300ULL); return; };
}
