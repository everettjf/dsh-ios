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

void ft__PyCompile_CodeGen(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[23] = cpu->regs[4];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0xd1714ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1cef60ULL);
    if ((cpu->regs[0])==0) goto L_d1744;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd1724ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11e0a4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d1744;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 896ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd1740ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_d1750;
L_d1744:
    cpu->regs[30] = PB_BASE + 0xd1748ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x193da0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d1758;
L_d1750:
    cpu->regs[23] = 0ULL;
    goto L_d1a98;
L_d1758:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd1768ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x25d7f0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d1798;
    cpu->regs[30] = PB_BASE + 0xd1774ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x269328ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d1798;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xd1790ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1a88a8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d17a4;
L_d1798:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd17a0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c12acULL);
    goto L_d1750;
L_d17a4:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xd17acULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1af54cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_d17c0;
L_d17b4:
    cpu->regs[19] = 0ULL;
    cpu->regs[23] = 0ULL;
    goto L_d1a78;
L_d17c0:
    PB_LDR(cpu->regs[20], (cpu->regs[22] + 64));
    cpu->regs[30] = PB_BASE + 0xd17c8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d17b4;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 904));
    if ((cpu->regs[2])!=0) goto L_d17e8;
L_d17d8:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 912));
    cpu->regs[20] = cpu->regs[20] + 904ULL;
    if ((cpu->regs[2])!=0) goto L_d17fc;
    goto L_d1810;
L_d17e8:
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0xd17f4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_d17d8;
    goto L_d182c;
L_d17fc:
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 912ULL;
    cpu->regs[30] = PB_BASE + 0xd180cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_d182c;
L_d1810:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    if ((cpu->regs[2])==0) goto L_d1834;
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 928ULL;
    cpu->regs[30] = PB_BASE + 0xd1828ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_d1834;
L_d182c:
    cpu->regs[23] = 0ULL;
    goto L_d1a78;
L_d1834:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    if ((cpu->regs[2])==0) goto L_d1850;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2520ULL;
    cpu->regs[30] = PB_BASE + 0xd184cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_d182c;
L_d1850:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    if ((cpu->regs[2])==0) goto L_d186c;
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 936ULL;
    cpu->regs[30] = PB_BASE + 0xd1868ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_d182c;
L_d186c:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 40));
    if ((cpu->regs[2])==0) goto L_d1888;
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 952ULL;
    cpu->regs[30] = PB_BASE + 0xd1884ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_d182c;
L_d1888:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 48));
    if ((cpu->regs[2])==0) goto L_d18a4;
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 968ULL;
    cpu->regs[30] = PB_BASE + 0xd18a0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_d182c;
L_d18a4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 64));
    cpu->regs[30] = PB_BASE + 0xd18acULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d182c;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 984ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd18c8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xd18d4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdce4cULL);
    if (((cpu->regs[25] >> 31) & 1)) goto L_d182c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 72));
    cpu->regs[30] = PB_BASE + 0xd18e0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d182c;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd18fcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xd1908ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdce4cULL);
    if (((cpu->regs[25] >> 31) & 1)) goto L_d182c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 80));
    cpu->regs[30] = PB_BASE + 0xd1914ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d182c;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 1016ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd1930ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd193cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdce4cULL);
    if (((cpu->regs[24] >> 31) & 1)) goto L_d182c;
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[22];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(3ULL)));
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    cpu->regs[30] = PB_BASE + 0xd1954ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1b8308ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d182c;
    PB_LDR(cpu->regs[27], (cpu->regs[22] + 64));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xd1968ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d182c;
    cpu->regs[24] = PB_BASE + 0x2b8000ULL;
    cpu->regs[24] = cpu->regs[24] + 2096ULL;
    cpu->regs[26] = PB_BASE + 0x2a6000ULL;
    cpu->regs[24] = cpu->regs[24] - 144ULL;
    cpu->regs[26] = cpu->regs[26] + 3016ULL;
    cpu->regs[25] = 0ULL;
L_d1988:
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 36));
    cpu->regs[7] = cpu->regs[27] + 24ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_GE) goto L_d1a48;
    cpu->regs[1] = 36ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 24));
    cpu->regs[1] = (uint64_t)((int64_t)(int32_t)cpu->regs[25] * (int64_t)(int32_t)cpu->regs[1]);
    cpu->regs[0] = cpu->regs[2] + cpu->regs[1];
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + cpu->regs[1]));
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 8)); PB_LDRW(cpu->regs[4], (cpu->regs[0] + 8) + 4);
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 16)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(511ULL)));
    if (FLAG_HI) goto L_d19f0;
    cpu->regs[2] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[1] >> 5)));
    PB_LDRW(cpu->regs[2], (cpu->regs[24] + (cpu->regs[2] << 2)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> (cpu->regs[1] & 63)));
    if (((cpu->regs[2] >> 0) & 1)) goto L_d19e0;
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 4294967293ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(256ULL)));
    if (FLAG_EQ) goto L_d19e0;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(257ULL)));
    if (FLAG_NE) goto L_d19f0;
L_d19e0:
    PB_LDR(cpu->regs[2], (cpu->regs[7] + 16));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 4),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + (cpu->regs[0] << 2)));
    goto L_d19f4;
L_d19f0:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 4));
L_d19f4:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0xd19fcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d1a3c;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd1a10ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe548cULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_d1a30;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d1a30;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xd1a30ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d1a30:
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_d1a3c;
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] + 1ULL));
    goto L_d1988;
L_d1a3c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd1a44ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_d182c;
L_d1a48:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xd1a58ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe1204ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[23] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_d1a78;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d1a78;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd1a78ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d1a78:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd1a80ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xd1a88ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1bede0ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xd1a90ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1c1190ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd1a98ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1c12acULL);
L_d1a98:
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
    SP = SP - 144ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = PB_BASE + 0x2a8000ULL;
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = cpu->regs[21] + 1032ULL;
    cpu->regs[30] = PB_BASE + 0xd1b00ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d4b00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d1b30;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_d1b38;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0xd1b30ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x11f220ULL);
L_d1b30:
    cpu->regs[21] = 4294967295ULL;
    goto L_d1ecc;
L_d1b38:
    PB_LDR(cpu->regs[7], (cpu->regs[20] + 16));
    cpu->regs[6] = 0ULL;
    if ((cpu->regs[7])==0) goto L_d1b54;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3488));
    cpu->regs[9] = cpu->regs[20] + 24ULL;
    goto L_d1b90;
L_d1b54:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[1] + 1096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd1b70ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_d1b30;
L_d1b74:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0xd1b80ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d1be8;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 344));
    if ((cpu->regs[0])!=0) goto L_d1bd4;
L_d1b8c:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
L_d1b90:
    FLAG_CMP(cpu->regs[6], cpu->regs[7]);
    if (FLAG_GE) goto L_d1c04;
    PB_LDR(cpu->regs[5], (cpu->regs[9] + (cpu->regs[6] << 3)));
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1b74;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1152ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0xd1bc8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_d1b30;
L_d1bcc:
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 256));
    if ((cpu->regs[5])==0) goto L_d1be0;
L_d1bd4:
    FLAG_CMP(cpu->regs[19], cpu->regs[5]);
    if (FLAG_NE) goto L_d1bcc;
    goto L_d1be8;
L_d1be0:
    FLAG_CMP(cpu->regs[19], cpu->regs[8]);
    if (FLAG_NE) goto L_d1b8c;
L_d1be8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 1200ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd1c00ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_d1b30;
L_d1c04:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd1c0cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x18e280ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d1b30;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[21] + 1032ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 256));
    cpu->regs[30] = PB_BASE + 0xd1c24ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xa2b34ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d1b30;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 256));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 336));
    if (FLAG_EQ) goto L_d1c40;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_d1c40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_d1c50;
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
L_d1c50:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    PB_STR((cpu->regs[19] + 336), cpu->regs[20]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_d1c64;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_d1c64:
    PB_STR((cpu->regs[19] + 256), cpu->regs[23]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xd1c70ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d1e2c;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd1c84ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xb847cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_d1cac;
    PB_LDR(cpu->regs[7], (cpu->regs[21] + 16));
    cpu->regs[0] = SP + 32ULL;
    cpu->regs[25] = PB_BASE + 0x299000ULL;
    cpu->regs[28] = SP + 16ULL;
    cpu->regs[25] = cpu->regs[25] + 240ULL;
    cpu->regs[27] = SP + 24ULL;
    cpu->regs[26] = cpu->regs[7] - 1ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    goto L_d1dbc;
L_d1cac:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1cc8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d1cc8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd1cc8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d1cc8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 336));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_d1d40;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[25] = cpu->regs[20] + 24ULL;
    cpu->regs[30] = PB_BASE + 0xd1ce4ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1deed0ULL);
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 16));
    cpu->regs[21] = 0ULL;
    cpu->regs[20] = 0ULL;
L_d1cf0:
    FLAG_CMP(cpu->regs[23], cpu->regs[20]);
    if (FLAG_LE) goto L_d1d14;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + (cpu->regs[20] << 3)));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0xd1d08ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x18d3a0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[21] = ((uint32_t)((FLAG_GE) ? cpu->regs[21] : (~0ULL)));
    goto L_d1cf0;
L_d1d14:
    cpu->regs[20] = PB_BASE + 0x512000ULL;
    cpu->regs[20] = cpu->regs[20] + 2704ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd1d24ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x18e42cULL);
L_d1d24:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if ((cpu->regs[0])==0) goto L_d1d44;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 48));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = cpu->regs[20] + 56ULL;
    cpu->regs[30] = PB_BASE + 0xd1d3cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1d1c4cULL);
    goto L_d1d24;
L_d1d40:
    cpu->regs[21] = 0ULL;
L_d1d44:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1d60;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d1d60;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xd1d60ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d1d60:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1ecc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d1ecc;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xd1d7cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d1ecc;
L_d1d80:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_STR((SP + 16), 0ULL);
    PB_LDR(cpu->regs[4], (SP + 8));
    cpu->regs[1] = cpu->regs[25];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[26] << 3)));
    cpu->regs[3] = 3ULL;
    cpu->regs[6] = cpu->regs[28];
    cpu->regs[5] = cpu->regs[27];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xd1da8ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x116904ULL);
    PB_LDR(cpu->regs[0], (SP + 24)); PB_LDR(cpu->regs[3], (SP + 24) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 344));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_d1dc4;
L_d1db8:
    cpu->regs[26] = cpu->regs[26] - 1ULL;
L_d1dbc:
    if (!((cpu->regs[26] >> 63) & 1)) goto L_d1d80;
    goto L_d1e10;
L_d1dc4:
    PB_LDR(cpu->regs[1], (SP + 16));
    if ((cpu->regs[1])==0) goto L_d1ddc;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_d1ddc;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
L_d1ddc:
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 168));
    if (!((cpu->regs[2] >> 1) & 1)) goto L_d1df0;
    if ((cpu->regs[1])==0) goto L_d1df0;
    cpu->regs[2] = 4294967295ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
L_d1df0:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[3] + 344), cpu->regs[1]);
    if (((cpu->regs[2] >> 31) & 1)) goto L_d1db8;
    cpu->regs[1] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d1db8;
    cpu->regs[30] = PB_BASE + 0xd1e0cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d1db8;
L_d1e10:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1e2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d1e2c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd1e2cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d1e2c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 336));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_d1e90;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_d1e4c;
    if ((cpu->regs[22])==0) goto L_d1e4c;
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
L_d1e4c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 256), cpu->regs[24]);
    PB_STR((cpu->regs[19] + 336), cpu->regs[22]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1e70;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d1e70;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd1e70ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d1e70:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1b30;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d1b30;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xd1e8cULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d1b30;
L_d1e90:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1eac;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d1eac;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xd1eacULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d1eac:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1b30;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d1b30;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xd1ec8ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d1b30;
L_d1ecc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_d1eec;
    cpu->regs[30] = PB_BASE + 0xd1eecULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x7c170ULL);
L_d1eec:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    SP = SP + 144ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if ((cpu->regs[1])!=0) goto L_d1f40;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 1248ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd1f3cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_d206c;
L_d1f40:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d1f74;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1288ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd1f70ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_d206c;
L_d1f74:
    cpu->regs[22] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[22] + 264ULL;
    cpu->regs[1] = cpu->regs[1] + 88ULL;
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 96ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd1f98ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d206c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3536));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 8));
    cpu->regs[30] = PB_BASE + 0xd1fb4ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d1fc4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd1fc0ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d1ff0;
L_d1fc4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (((cpu->regs[0] >> 8) & 1)) goto L_d1fd4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    if (!((cpu->regs[0] >> 8) & 1)) goto L_d1ff0;
L_d1fd4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 1344ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd1fecULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_d206c;
L_d1ff0:
    cpu->regs[2] = cpu->regs[22] + 264ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd2000ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xa2b34ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d206c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd200cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x26beccULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 168));
    if (!((cpu->regs[1] >> 4) & 1)) goto L_d2024;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + -24));
    if (!((cpu->regs[0] >> 0) & 1)) goto L_d2024;
    cpu->regs[30] = PB_BASE + 0xd2020ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_d206c;
L_d2024:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (!((cpu->regs[0] >> 9) & 1)) goto L_d203c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_d203c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_d203c:
    PB_STR((cpu->regs[21] + 8), cpu->regs[19]);
    if (((cpu->regs[1] >> 9) & 1)) goto L_d204c;
L_d2044:
    cpu->regs[0] = 0ULL;
    goto L_d2070;
L_d204c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d2044;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d2044;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd2068ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d2044;
L_d206c:
    cpu->regs[0] = 4294967295ULL;
L_d2070:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
