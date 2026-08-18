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

void ft__PyWideStringList_AsList(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1af440ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    if ((cpu->regs[0])==0) goto L_1af49c;
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[19] = 0ULL;
L_1af44c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[19] << 3;
    cpu->regs[1] = 18446744073709551615ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_LE) goto L_1af4a0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + cpu->regs[21]));
    cpu->regs[30] = PB_BASE + 0x1af470ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1934e0ULL);
    if ((cpu->regs[0])==0) goto L_1af480;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    PB_STR((cpu->regs[1] + cpu->regs[21]), cpu->regs[0]);
    goto L_1af44c;
L_1af480:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1af49c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1af49c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af49cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1af49c:
    cpu->regs[22] = 0ULL;
L_1af4a0:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2712));
    cpu->regs[30] = PB_BASE + 0x1af4dcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1af508;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1af4f4;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1af4f4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[5] + 16), cpu->regs[19]); PB_STR((cpu->regs[5] + 16) + 8, cpu->regs[1]);
    cpu->regs[0] = cpu->regs[5];
    PB_STR((cpu->regs[5] + 32), 0ULL); PB_STR((cpu->regs[5] + 32) + 8, cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1af508ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xd9444ULL);
L_1af508:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1af530ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1af53cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = 1ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = 23984ULL;
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1af580ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1af6a4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1af5e4;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_1af5b4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1af5a0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x132ce0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1af5dc;
L_1af5a4:
    cpu->regs[0] = 0ULL;
L_1af5a8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1af5b4:
    if (FLAG_HI) goto L_1af650;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1af5ec;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 4294967297ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1af5d4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1b096cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1af5a4;
L_1af5dc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1af5e4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1bede0ULL);
L_1af5e4:
    cpu->regs[0] = 4294967295ULL;
    goto L_1af5a8;
L_1af5ec:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1af650;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x1af5fcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1b0ba0ULL);
    if (((cpu->regs[0] >> 0) & 1)) goto L_1af678;
L_1af600:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 8));
    PB_STRW((cpu->regs[20] + 48), cpu->regs[0]);
    if ((cpu->regs[21])==0) goto L_1af648;
    cpu->regs[19] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1af61c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[3] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    cpu->regs[0] = cpu->regs[20];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LE) goto L_1af648;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1af63cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x12fe88ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1af670;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    goto L_1af61c;
L_1af648:
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_1af5a4;
L_1af650:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1af668ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1af5a8;
L_1af670:
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_1af5dc;
L_1af678:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 64));
    cpu->regs[3] = 4294967297ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 85ULL;
    cpu->regs[30] = PB_BASE + 0x1af694ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1af600;
    cpu->regs[0] = 4294967295ULL;
    goto L_1af5a8;
L_1af6a4:
    SP = SP - 96ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[1] = 1000ULL;
    cpu->regs[23] = cpu->regs[2];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[24] = cpu->regs[4];
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1af6f4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x12c1a0ULL);
    if ((cpu->regs[0])==0) goto L_1afb14;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[0] + 1024ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[22];
    PB_STRW((cpu->regs[19] + 8), cpu->regs[23]);
    PB_STR((cpu->regs[2] + -56), 0ULL); PB_STR((cpu->regs[2] + -56) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 984), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1af718ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1afb84ULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1afb20;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1afa98;
L_1af72c:
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 40));
    PB_STR((cpu->regs[19] + 904), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1af738ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1afaf4;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1af748ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1b0088ULL);
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[21] = 0ULL;
L_1af750:
    FLAG_CMP(cpu->regs[25], cpu->regs[21]);
    if (FLAG_LE) goto L_1af790;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af760ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1afae0;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 24));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[21] << 3)));
    cpu->regs[30] = PB_BASE + 0x1af77cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1afad0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1afa20;
L_1af788:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_1af750;
L_1af790:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 2048ULL;
    cpu->regs[1] = 5ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_STR((cpu->regs[19] + 936), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x1af7acULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x12c6a0ULL);
    PB_STR((cpu->regs[19] + 944), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1afb20;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 80));
    if (((cpu->regs[2] >> 3) & 1)) goto L_1afa5c;
L_1af7c0:
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 80));
    if (((cpu->regs[0] >> 4) & 1)) goto L_1afb30;
L_1af7c8:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 944));
    cpu->regs[2] = 64ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    cpu->regs[1] = 4ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    cpu->regs[30] = PB_BASE + 0x1af7e0ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x12c6a0ULL);
    PB_STR((cpu->regs[19] + 952), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1afb20;
    cpu->regs[30] = PB_BASE + 0x1af7ecULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[19] + 960), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1afb20;
    PB_STR((cpu->regs[19] + 56), 0ULL);
    PB_STRW((cpu->regs[19] + 992), cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1af800ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[19] + 920), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1afb20;
    cpu->regs[30] = PB_BASE + 0x1af80cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[19] + 928), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1afb20;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 64));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if ((cpu->regs[0])==0) goto L_1af878;
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 472ULL;
    cpu->regs[30] = PB_BASE + 0x1af830ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1b52c0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1afb54;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 72));
    cpu->regs[30] = PB_BASE + 0x1af844ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe548cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1afb54;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1af85c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1afb08;
L_1af85c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 64));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1af874;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1afac8;
L_1af874:
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
L_1af878:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 52));
    PB_STR((cpu->regs[20] + 64), cpu->regs[19]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 52), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_1af980;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 72));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[22], 1ULL);
    if (FLAG_LE) goto L_1af9e0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[23] = PB_BASE + 0x28b000ULL;
    cpu->regs[23] = cpu->regs[23] + 472ULL;
    cpu->regs[25] = cpu->regs[22] << 3;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[22] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + -8));
    cpu->regs[30] = PB_BASE + 0x1af8c0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1b6a4cULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(6ULL)));
    if (FLAG_EQ) goto L_1afaa0;
L_1af8d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_HI) goto L_1af918;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 904));
    cpu->regs[30] = PB_BASE + 0x1af8ecULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x129360ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1afa18;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x1af904ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1b14c0ULL);
    cpu->regs[23] = ((uint32_t)(((cpu->regs[0] >> 12) & 0xfULL)));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1afa7c;
L_1af910:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_1af9e0;
L_1af918:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 912));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 2ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_LS) goto L_1af9f8;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1afa54;
L_1af940:
    cpu->regs[0] = 63392ULL;
    cpu->regs[1] = cpu->regs[22] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af950ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x11aa40ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_STR((SP + 0), cpu->regs[0]);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1afa3c;
L_1af95c:
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])==0) goto L_1afa18;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 904));
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x1af970ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1b6b84ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])==0) goto L_1afa18;
L_1af978:
    cpu->regs[3] = cpu->regs[24];
    PB_STR((cpu->regs[19] + 912), cpu->regs[0]);
L_1af980:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 64));
    cpu->regs[3] = cpu->regs[3];
    cpu->regs[3] = cpu->regs[3] | (cpu->regs[24] << 32);
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 151ULL;
    cpu->regs[30] = PB_BASE + 0x1af9a0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
L_1af9a8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1afa94;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_1af9e0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 904));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1af978;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1af978;
L_1af9f8:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 24408ULL;
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1afa10ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x11aa40ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1af940;
L_1afa18:
    cpu->regs[0] = 4294967295ULL;
    goto L_1af9a8;
L_1afa20:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1af788;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1afa38ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1af750;
L_1afa3c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1af95c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1afa50ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1af95c;
L_1afa54:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_1af940;
L_1afa5c:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[3] = 26712ULL;
    cpu->regs[1] = cpu->regs[22] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1afa70ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x135248ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_1afb20;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    goto L_1af7c0;
L_1afa7c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1af910;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1afa90ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1af910;
L_1afa94:
    cpu->regs[30] = PB_BASE + 0x1afa98ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1afa98:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
    goto L_1af72c;
L_1afaa0:
    FLAG_CMP(cpu->regs[22], 2ULL);
    if (FLAG_EQ) goto L_1af9e0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 72));
    cpu->regs[1] = cpu->regs[23];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[25];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + -16));
    cpu->regs[30] = PB_BASE + 0x1afac0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1b6a4cULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_1af8d0;
L_1afac8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1af874;
L_1afad0:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1afae0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1afb78;
L_1afae0:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1afaf4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1afb6c;
L_1afaf4:
    PB_STR((cpu->regs[19] + 936), 0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1afb00ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1bf100ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1af9a8;
L_1afb08:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1afb10ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1af85c;
L_1afb14:
    cpu->regs[30] = PB_BASE + 0x1afb18ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1af9a8;
L_1afb20:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1afb28ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1bf100ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1af9a8;
L_1afb30:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 944));
    cpu->regs[2] = 26888ULL;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[1] = cpu->regs[22] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1afb48ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x135248ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_1afb20;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    goto L_1af7c8;
L_1afb54:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1afb5cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1afb64ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1bf100ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1af9a8;
L_1afb6c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1afb74ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1afaf4;
L_1afb78:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1afb80ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1afae0;
}
