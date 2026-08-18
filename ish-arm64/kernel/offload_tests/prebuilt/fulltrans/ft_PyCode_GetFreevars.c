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

void ft_PyCode_GetFreevars(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x9d2e8ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9d35cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdb480ULL);
    if ((cpu->regs[0])==0) goto L_9d3d8;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2520));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[20] + 24ULL;
    cpu->regs[24] = cpu->regs[0] + 24ULL;
    cpu->regs[21] = 0ULL;
    goto L_9d394;
L_9d37c:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9d38c;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_9d38c:
    PB_STR((cpu->regs[24] + (cpu->regs[21] << 3)), cpu->regs[0]);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
L_9d394:
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_GE) goto L_9d408;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[21] << 3)));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[23]);
    if (FLAG_EQ) goto L_9d37c;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_9d3e0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9d3d0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9d3f0;
L_9d3d8:
    cpu->regs[19] = 0ULL;
    goto L_9d408;
L_9d3e0:
    cpu->regs[30] = PB_BASE + 0x9d3e4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x25a260ULL);
    if ((cpu->regs[0])!=0) goto L_9d38c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9d3d8;
L_9d3f0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9d3d8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d404ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9d3d8;
L_9d408:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x9d444ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x121b20ULL);
    if ((cpu->regs[0])!=0) goto L_9d46c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_9d460;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[3]);
L_9d460:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
    goto L_9d470;
L_9d46c:
    cpu->regs[20] = cpu->regs[0];
L_9d470:
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x9d480ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe0f0cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_9d4a0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9d4a0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9d4a0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9d4a0:
    if ((cpu->regs[19])==0) goto L_9d4dc;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9d4b0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x279dccULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9d4c8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_9d4d0;
L_9d4c8:
    cpu->regs[19] = cpu->regs[20];
    goto L_9d4dc;
L_9d4d0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d4d8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9d4c8;
L_9d4dc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x9d504ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdb548ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8)); PB_LDR(cpu->regs[3], (cpu->regs[3] + 8) + 8);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x9d518ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe0f0cULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9d538;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9d538;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d538ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9d538:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_NE) goto L_9d618;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 88));
    if ((cpu->regs[0])==0) goto L_9d618;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 96));
    cpu->regs[1] = 3ULL;
    cpu->regs[0] = 5ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x9d588ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9d678;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9d5a8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_9d5a8:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9d5c0;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_9d5c0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 88));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[19] + 32), cpu->regs[2]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9d5d8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_9d5d8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 96));
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_9d628;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9d5fc;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_9d5fc:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 48), cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9d610;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_9d610:
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    goto L_9d628;
L_9d618:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9d628;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9d628:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[3], (cpu->regs[20] + 8) + 8);
    cpu->regs[2] = cpu->regs[19];
    if ((cpu->regs[3])==0) goto L_9d644;
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x9d63cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe0f0cULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_9d650;
L_9d644:
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x9d64cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[20] = cpu->regs[0];
L_9d650:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9d664;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_9d66c;
L_9d664:
    cpu->regs[19] = cpu->regs[20];
    goto L_9d678;
L_9d66c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d674ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9d664;
L_9d678:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_9d6d4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_9d6dc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 3264ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9d6ccULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
L_9d6d4:
    cpu->regs[19] = 0ULL;
    goto L_9d8d8;
L_9d6dc:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    if (((cpu->regs[2] >> 63) & 1)) goto L_9d8b4;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 40));
    cpu->regs[3] = 1ULL;
    PB_LDRB(cpu->regs[5], (cpu->regs[1] + 9));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[5] & 63);
    if ((cpu->regs[4])==0) goto L_9d718;
    cpu->regs[0] = cpu->regs[4] - cpu->regs[2];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + -3));
    cpu->regs[3] = cpu->regs[3] + (((cpu->regs[0]) & 0xffffffffULL) << 4);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    PB_LDR(cpu->regs[20], (cpu->regs[4] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 32));
    goto L_9d784;
L_9d718:
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + 10));
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_9d754;
    cpu->regs[3] = cpu->regs[3] + (cpu->regs[2] << 4);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
L_9d72c:
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 8));
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    if ((cpu->regs[20])!=0) goto L_9d74c;
    cpu->regs[1] = cpu->regs[1] - 16ULL;
    cpu->regs[2] = cpu->regs[3];
    FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9d72c;
    goto L_9d8b4;
L_9d74c:
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0));
    goto L_9d784;
L_9d754:
    cpu->regs[4] = 24ULL;
    cpu->regs[3] = cpu->regs[2] * cpu->regs[4] + cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
L_9d760:
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 16));
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    if ((cpu->regs[20])!=0) goto L_9d780;
    cpu->regs[1] = cpu->regs[1] - 24ULL;
    cpu->regs[2] = cpu->regs[3];
    FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9d760;
    goto L_9d8b4;
L_9d780:
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 8));
L_9d784:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    PB_STR((cpu->regs[19] + 32), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2200));
    PB_STR((cpu->regs[19] + 48), cpu->regs[1]);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_9d7c4;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9d7bc;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_9d7bc:
    cpu->regs[19] = cpu->regs[21];
    goto L_9d8d8;
L_9d7c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 4064));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_9d7e8;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9d8d4;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_9d8d4;
L_9d7e8:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_9d87c;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[22], (cpu->regs[19] + 24) + 8);
    if (FLAG_EQ) goto L_9d80c;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
L_9d80c:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 24), cpu->regs[21]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9d820;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_9d820:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[19] + 32), cpu->regs[20]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9d834;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_9d834:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9d84c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9d84c;
    cpu->regs[30] = PB_BASE + 0x9d84cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9d84c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9d868;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9d868;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9d868ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9d868:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -16));
    if ((cpu->regs[0])!=0) goto L_9d8d8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d878ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_9d8d8;
L_9d87c:
    cpu->regs[30] = PB_BASE + 0x9d880ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x187fc0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9d6d4;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9d898;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_9d898:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 24), cpu->regs[21]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9d8ac;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_9d8ac:
    PB_STR((cpu->regs[19] + 32), cpu->regs[20]);
    goto L_9d8d8;
L_9d8b4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_9d6d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9d6d4;
    cpu->regs[30] = PB_BASE + 0x9d8d0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9d6d4;
L_9d8d4:
    cpu->regs[19] = cpu->regs[20];
L_9d8d8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]);
    if ((cpu->regs[1])==0) goto L_9d924;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9d91cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xd88a4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9da18;
L_9d924:
    PB_LDRH(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9d930ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9d9b0;
    cpu->regs[24] = cpu->regs[0] + 16ULL;
    cpu->regs[25] = 12ULL;
    goto L_9d978;
L_9d944:
    cpu->regs[0] = cpu->regs[21] + cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 12));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9d95c;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_9d95c:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 20));
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    PB_STR((cpu->regs[20] + 24), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x9d96cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1564ULL);
    if ((cpu->regs[0])==0) goto L_9d9b8;
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    PB_STR((cpu->regs[24] + (cpu->regs[23] << 3)), cpu->regs[20]);
L_9d978:
    PB_LDRH(cpu->regs[0], (cpu->regs[21] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_LE) goto L_9d9d8;
    cpu->regs[30] = PB_BASE + 0x9d988ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x187fc0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = (uint64_t)((int64_t)(int32_t)cpu->regs[23] * (int64_t)(int32_t)cpu->regs[25]);
    if ((cpu->regs[0])!=0) goto L_9d944;
L_9d994:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9d9b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9d9b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d9b0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9d9b0:
    cpu->regs[19] = 0ULL;
    goto L_9da28;
L_9d9b8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9d994;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9d994;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9d9d4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9d994;
L_9d9d8:
    if ((cpu->regs[22])==0) goto L_9da28;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9d9ecULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xd8a64ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9da18;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9da10;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9da10;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9da10ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9da10:
    cpu->regs[30] = PB_BASE + 0x9da14ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_9d9b0;
L_9da18:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9da28;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9da28:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
}
