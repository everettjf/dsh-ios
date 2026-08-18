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

void ft_PyUnicode_Splitlines(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x21d820ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11ae28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_21da3c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 32));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_21da68;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[1] = ((uint32_t)(((cpu->regs[0] >> 5) & 0x1ULL)));
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    if (!((cpu->regs[0] >> 6) & 1)) goto L_21dca0;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_21ddc0;
    cpu->regs[20] = cpu->regs[23] + 40ULL;
L_21d850:
    PB_LDR(cpu->regs[27], (cpu->regs[23] + 16));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21d85cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21de28;
    cpu->regs[21] = PB_BASE + 0x2b8000ULL;
    cpu->regs[21] = cpu->regs[21] + 2096ULL;
    cpu->regs[21] = cpu->regs[21] + 1744ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = 0ULL;
L_21d878:
    FLAG_CMP(cpu->regs[27], cpu->regs[25]);
    if (FLAG_LE) goto L_21d9cc;
    cpu->regs[19] = cpu->regs[25];
L_21d884:
    cpu->regs[0] = cpu->regs[27] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] & 3ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21d928;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_21d8b8;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_NE) goto L_21da44;
L_21d8a0:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[20] + cpu->regs[19]),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + cpu->regs[19]));
    if (((cpu->regs[0] >> 31) & 1)) goto L_21dde0;
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + ((uint64_t)(uint32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_21d938;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_21d8b8:
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + cpu->regs[19]));
    if (((cpu->regs[2] >> 7) & 1)) goto L_21dde0;
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_21d938;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[19]);
    if (FLAG_NE) goto L_21d928;
L_21d8d4:
    cpu->regs[26] = cpu->regs[27];
    goto L_21d954;
L_21d8dc:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[0] = cpu->regs[19];
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + cpu->regs[19]));
    if (((cpu->regs[2] >> 7) & 1)) goto L_21dde0;
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_21d938;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + cpu->regs[19]));
    if (((cpu->regs[2] >> 7) & 1)) goto L_21dde0;
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_21d938;
    cpu->regs[19] = cpu->regs[0] + 2ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + cpu->regs[19]));
    if (((cpu->regs[2] >> 7) & 1)) goto L_21dde0;
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_21d938;
    cpu->regs[19] = cpu->regs[0] + 3ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[19]);
    if (FLAG_EQ) goto L_21d8d4;
L_21d928:
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + cpu->regs[19]));
    if (((cpu->regs[2] >> 7) & 1)) goto L_21dde0;
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_21d8dc;
L_21d938:
    FLAG_CMP(cpu->regs[27], cpu->regs[19]);
    if (FLAG_LE) goto L_21db8c;
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + cpu->regs[19]));
    cpu->regs[26] = cpu->regs[19] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_21d9ec;
L_21d950:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_21da08;
L_21d954:
    FLAG_CMP(cpu->regs[25], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[27], cpu->regs[26]); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_21d9a8;
L_21d960:
    cpu->regs[1] = cpu->regs[26] - cpu->regs[25];
    cpu->regs[0] = cpu->regs[20] + cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x21d96cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21da1c;
L_21d974:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21d980ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe548cULL);
    cpu->regs[25] = cpu->regs[26];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21de38;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21d878;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21d878;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21d9a4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21d878;
L_21d9a8:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_21deec;
L_21d9bc:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21d9c8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe548cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21da1c;
L_21d9cc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_21d9d8:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_21d9ec:
    FLAG_CMP(cpu->regs[27], cpu->regs[26]);
    if (FLAG_LE) goto L_21d950;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[19];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_21da60;
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_21d960;
L_21da08:
    cpu->regs[1] = cpu->regs[19] - cpu->regs[25];
    cpu->regs[0] = cpu->regs[20] + cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x21da14ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe9b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_21d974;
L_21da1c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_21da30;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_21def4;
L_21da30:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_21da3c:
    cpu->regs[22] = 0ULL;
    goto L_21d9d8;
L_21da44:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[20] + cpu->regs[19]),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + cpu->regs[19]));
    if (((cpu->regs[0] >> 31) & 1)) goto L_21dde0;
    PB_LDRB(cpu->regs[2], (cpu->regs[21] + ((uint64_t)(uint32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_21d938;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_21d8a0;
L_21da60:
    cpu->regs[26] = cpu->regs[19] + 2ULL;
    goto L_21d950;
L_21da68:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_21dbd4;
    if (!((cpu->regs[0] >> 5) & 1)) goto L_21ddd8;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[25] = cpu->regs[23] + 56ULL;
    cpu->regs[0] = cpu->regs[23] + 40ULL;
    cpu->regs[25] = (FLAG_EQ) ? cpu->regs[25] : cpu->regs[0];
L_21da88:
    PB_LDR(cpu->regs[21], (cpu->regs[23] + 16));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21da94ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ddcc;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x2b8000ULL;
    cpu->regs[20] = cpu->regs[20] + 2096ULL;
    cpu->regs[20] = cpu->regs[20] + 1744ULL;
    cpu->regs[26] = 0ULL;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
L_21dab4:
    cpu->regs[28] = cpu->regs[26];
    FLAG_CMP(cpu->regs[21], cpu->regs[26]);
    if (FLAG_LE) goto L_21d9cc;
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    cpu->regs[19] = cpu->regs[26];
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 216));
    goto L_21dae4;
L_21dad0:
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21db04;
L_21dad8:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    if (FLAG_EQ) goto L_21db78;
L_21dae4:
    PB_LDRH(cpu->regs[2], (cpu->regs[25] + (cpu->regs[19] << 1)));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(127ULL)));
    if (FLAG_LS) goto L_21dad0;
    cpu->regs[0] = cpu->regs[27] >> (cpu->regs[2] & 63);
    if (!((cpu->regs[0] >> 0) & 1)) goto L_21dad8;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x21db00ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x24e3a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21dad8;
L_21db04:
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    if (FLAG_LE) goto L_21dbac;
    PB_LDRH(cpu->regs[0], (cpu->regs[25] + (cpu->regs[19] << 1)));
    cpu->regs[2] = cpu->regs[19] << 1;
    cpu->regs[1] = cpu->regs[19] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_21dbb4;
L_21db20:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_21db80;
L_21db24:
    FLAG_CMP(cpu->regs[26], 0ULL);
    cpu->regs[26] = cpu->regs[1];
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[21], cpu->regs[1]); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_21db94;
L_21db34:
    cpu->regs[1] = cpu->regs[1] - cpu->regs[28];
    cpu->regs[0] = cpu->regs[25] + (cpu->regs[28] << 1);
    cpu->regs[30] = PB_BASE + 0x21db40ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x212fe0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21da1c;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21db54ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21de38;
    if (((cpu->regs[1] >> 31) & 1)) goto L_21dab4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21dab4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21db74ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21dab4;
L_21db78:
    cpu->regs[1] = cpu->regs[21];
    goto L_21db24;
L_21db80:
    cpu->regs[26] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[19];
    goto L_21db34;
L_21db8c:
    cpu->regs[26] = cpu->regs[19];
    goto L_21d954;
L_21db94:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_21d9bc;
    goto L_21db34;
L_21dbac:
    cpu->regs[1] = cpu->regs[19];
    goto L_21db24;
L_21dbb4:
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_LE) goto L_21db20;
    cpu->regs[2] = cpu->regs[25] + cpu->regs[2];
    PB_LDRH(cpu->regs[0], (cpu->regs[2] + 2));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_21db20;
    cpu->regs[1] = cpu->regs[19] + 2ULL;
    goto L_21db20;
L_21dbd4:
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    if (((cpu->regs[0] >> 5) & 1)) goto L_21de14;
    PB_LDR(cpu->regs[20], (cpu->regs[23] + 56));
L_21dbe0:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 16));
    cpu->regs[30] = PB_BASE + 0x21dbecULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21ddc8;
    cpu->regs[21] = PB_BASE + 0x2b8000ULL;
    cpu->regs[21] = cpu->regs[21] + 2096ULL;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2520));
    cpu->regs[21] = cpu->regs[21] + 1744ULL;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[28] = 0ULL;
L_21dc10:
    FLAG_CMP(cpu->regs[25], cpu->regs[28]);
    if (FLAG_LE) goto L_21d9cc;
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    cpu->regs[19] = cpu->regs[28];
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 216));
L_21dc24:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + (cpu->regs[19] << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_21de54;
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21de64;
L_21dc38:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[19]);
    if (FLAG_NE) goto L_21dc24;
L_21dc44:
    FLAG_CMP(cpu->regs[28], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[25], cpu->regs[19]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_21dc5c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_EQ) goto L_21d9bc;
L_21dc5c:
    cpu->regs[27] = cpu->regs[19];
L_21dc60:
    cpu->regs[1] = cpu->regs[19] - cpu->regs[28];
    cpu->regs[0] = cpu->regs[20] + (cpu->regs[28] << 2);
    cpu->regs[30] = PB_BASE + 0x21dc6cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x212cecULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21da1c;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21dc80ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21dec0;
    if (((cpu->regs[2] >> 31) & 1)) goto L_21dc98;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_21deb0;
L_21dc98:
    cpu->regs[28] = cpu->regs[27];
    goto L_21dc10;
L_21dca0:
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_21ddb8;
    cpu->regs[20] = cpu->regs[23] + 56ULL;
L_21dca8:
    PB_LDR(cpu->regs[28], (cpu->regs[23] + 16));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21dcb4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21de28;
    cpu->regs[21] = PB_BASE + 0x2b8000ULL;
    cpu->regs[21] = cpu->regs[21] + 2096ULL;
    cpu->regs[21] = cpu->regs[21] + 1744ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = 0ULL;
    cpu->regs[25] = PB_BASE + 0x450000ULL;
L_21dcd4:
    cpu->regs[27] = cpu->regs[26];
    FLAG_CMP(cpu->regs[28], cpu->regs[26]);
    if (FLAG_LE) goto L_21d9cc;
    cpu->regs[19] = cpu->regs[26];
    goto L_21dcfc;
L_21dce8:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21dd20;
L_21dcf0:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[28], cpu->regs[19]);
    if (FLAG_EQ) goto L_21dd44;
L_21dcfc:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[20] + cpu->regs[19]),&_s,1); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + cpu->regs[19]));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_21dce8;
    cpu->regs[1] = cpu->regs[25] + 8ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 208));
    cpu->regs[1] = cpu->regs[1] >> (cpu->regs[0] & 63);
    if (!((cpu->regs[1] >> 0) & 1)) goto L_21dcf0;
    cpu->regs[30] = PB_BASE + 0x21dd1cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x24e3a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21dcf0;
L_21dd20:
    cpu->regs[26] = cpu->regs[19];
    FLAG_CMP(cpu->regs[19], cpu->regs[28]);
    if (FLAG_GE) goto L_21dd54;
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + cpu->regs[19]));
    cpu->regs[26] = cpu->regs[19] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_21dd98;
L_21dd3c:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_21dd54;
    cpu->regs[19] = cpu->regs[26];
L_21dd44:
    FLAG_CMP(cpu->regs[27], 0ULL);
    cpu->regs[26] = cpu->regs[19];
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[28], cpu->regs[19]); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_21ded4;
L_21dd54:
    cpu->regs[1] = cpu->regs[19] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[20] + cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x21dd60ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xefdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21da1c;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x21dd74ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_21dec0;
    if (((cpu->regs[2] >> 31) & 1)) goto L_21dcd4;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_21dcd4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21dd94ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21dcd4;
L_21dd98:
    FLAG_CMP(cpu->regs[28], cpu->regs[26]);
    if (FLAG_LE) goto L_21dd3c;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[19];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_21dd3c;
    cpu->regs[26] = cpu->regs[19] + 2ULL;
    goto L_21dd3c;
L_21ddb8:
    PB_LDR(cpu->regs[20], (cpu->regs[23] + 56));
    goto L_21dca8;
L_21ddc0:
    PB_LDR(cpu->regs[20], (cpu->regs[23] + 56));
    goto L_21d850;
L_21ddc8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_21ddcc:
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_21d9d8;
L_21ddd8:
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 56));
    goto L_21da88;
L_21dde0:
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 216));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[2] & 63);
    if (((cpu->regs[0] >> 0) & 1)) goto L_21de04;
L_21ddf0:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[27], cpu->regs[19]);
    if (FLAG_NE) goto L_21d884;
    cpu->regs[26] = cpu->regs[27];
    goto L_21d954;
L_21de04:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x21de0cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x24e3a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21ddf0;
    goto L_21d938;
L_21de14:
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[20] = cpu->regs[23] + 56ULL;
    cpu->regs[0] = cpu->regs[23] + 40ULL;
    cpu->regs[20] = (FLAG_EQ) ? cpu->regs[20] : cpu->regs[0];
    goto L_21dbe0;
L_21de28:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_21d9d8;
L_21de38:
    if (((cpu->regs[1] >> 31) & 1)) goto L_21da1c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_21da1c;
L_21de48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21de50ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21da1c;
L_21de54:
    cpu->regs[1] = cpu->regs[27] >> (cpu->regs[0] & 63);
    if (!((cpu->regs[1] >> 0) & 1)) goto L_21dc38;
    cpu->regs[30] = PB_BASE + 0x21de60ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x24e3a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21dc38;
L_21de64:
    FLAG_CMP(cpu->regs[25], cpu->regs[19]);
    if (FLAG_LE) goto L_21dc5c;
    cpu->regs[0] = cpu->regs[19] << 2;
    cpu->regs[27] = cpu->regs[19] + 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_21de8c;
L_21de80:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_21dc60;
L_21de84:
    cpu->regs[19] = cpu->regs[27];
    goto L_21dc44;
L_21de8c:
    FLAG_CMP(cpu->regs[25], cpu->regs[27]);
    if (FLAG_LE) goto L_21de80;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_21de80;
    cpu->regs[27] = cpu->regs[19] + 2ULL;
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_21dc60;
    goto L_21de84;
L_21deb0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[28] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x21debcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21dc10;
L_21dec0:
    if (((cpu->regs[2] >> 31) & 1)) goto L_21da1c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_21da1c;
    goto L_21de48;
L_21ded4:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_21dd54;
    goto L_21d9bc;
L_21deec:
    cpu->regs[19] = cpu->regs[26];
    goto L_21da08;
L_21def4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21df00ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_21d9d8;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 208));
    if ((cpu->regs[0])==0) goto L_21df4c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    PB_STR((cpu->regs[19] + 208), cpu->regs[1]);
L_21df30:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 200));
    if ((cpu->regs[1])!=0) goto L_21df5c;
L_21df38:
    PB_STR((cpu->regs[0] + 32), 0ULL); PB_STR((cpu->regs[0] + 32) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[19] + 200), cpu->regs[0]);
L_21df40:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_21df4c:
    cpu->regs[0] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x21df54ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xd8e60ULL);
    if ((cpu->regs[0])!=0) goto L_21df30;
    goto L_21df40;
L_21df5c:
    PB_STR((cpu->regs[1] + 32), cpu->regs[0]);
    goto L_21df38;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    if ((cpu->regs[0])==0) goto L_21e044;
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 24));
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x21df88ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11d7acULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21e0c8;
    cpu->regs[1] = cpu->tls_ptr;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x21dfacULL; PB_CALL(28, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    cpu->regs[19] = cpu->regs[19] + 3928ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 24) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GE) goto L_21e09c;
L_21dfc4:
    cpu->regs[0] = 24ULL;
    cpu->regs[30] = PB_BASE + 0x21dfccULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21e0b4;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x21dfe4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x13e388ULL);
    PB_STR((cpu->regs[20] + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_21e084;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21dffc;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_21dffc:
    PB_STR((cpu->regs[20] + 0), cpu->regs[21]);
    if ((cpu->regs[23])!=0) goto L_21e070;
L_21e004:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[20] + 16), cpu->regs[23]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 24), cpu->regs[3]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    PB_STR((cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)), cpu->regs[20]);
    if (FLAG_EQ) goto L_21e064;
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_21e034:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_21e044:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 760ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x21e060ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_21e034;
L_21e064:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_21e034;
L_21e070:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_21e004;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_21e004;
L_21e084:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x21e090ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_21e034;
L_21e09c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 16ULL));
    PB_STRW((cpu->regs[19] + 28), cpu->regs[1]);
    cpu->regs[1] = (((uint64_t)(((int64_t)(cpu->regs[1] << 32)) >> 32) & 0xffffffffULL) << 3);
    cpu->regs[30] = PB_BASE + 0x21e0b0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])!=0) goto L_21e0e8;
L_21e0b4:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(34, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_21e0c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 336ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x21e0e4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_21e034;
L_21e0e8:
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
    goto L_21dfc4;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x21e0fcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7ae40ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    { PB_CALL(37, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_21e120;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[1] - cpu->regs[0];
    { PB_CALL(38, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_21e120:
    cpu->regs[0] = 0ULL;
    { PB_CALL(39, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
    SP = SP - 128ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[5];
    cpu->regs[19] = cpu->regs[6];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[22] = cpu->regs[7];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[3];
    PB_STR((SP + 112), cpu->regs[27]); PB_STR((SP + 112) + 8, cpu->regs[28]);
    cpu->regs[28] = cpu->regs[1];
    cpu->regs[27] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[9], (cpu->regs[8] + 0));
    PB_STR((SP + 24), cpu->regs[9]);
    cpu->regs[9] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    PB_LDR(cpu->regs[24], (SP + 144));
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[25], (SP + 128) + 8);
    if ((cpu->regs[1])!=0) goto L_21e198;
    cpu->regs[30] = PB_BASE + 0x21e190ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1d3208ULL);
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_21e2fc;
L_21e198:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[22] + 0));
    if ((cpu->regs[0])!=0) goto L_21e2c8;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[5] = cpu->regs[26];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x21e1c0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x21e488ULL);
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
L_21e1c4:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if ((cpu->regs[1])==0) goto L_21e2fc;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[30] = PB_BASE + 0x21e1d4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_21e2fc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_21e420;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[3] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[1] + 808ULL;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x21e1fcULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21e300;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[30] = PB_BASE + 0x21e208ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x247b50ULL);
    if ((cpu->regs[0])==0) goto L_21e300;
    PB_LDR(cpu->regs[26], (cpu->regs[0] + 16));
    cpu->regs[3] = cpu->regs[0] + 32ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[20] + 0));
    cpu->regs[4] = cpu->regs[3] + cpu->regs[26];
    PB_LDR(cpu->regs[5], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[23] = cpu->regs[23] - cpu->regs[5];
    PB_LDR(cpu->regs[27], (cpu->regs[22] + 0));
    PB_STR((cpu->regs[21] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[20] + 0), cpu->regs[4]);
    cpu->regs[28] = cpu->regs[23] - cpu->regs[27];
    if (((cpu->regs[2] >> 31) & 1)) goto L_21e248;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_21e418;
L_21e248:
    PB_LDR(cpu->regs[2], (SP + 8));
    if (((cpu->regs[2] >> 63) & 1)) goto L_21e40c;
L_21e250:
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_GE) { FLAG_CMP(cpu->regs[26], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_21e43c;
    PB_LDR(cpu->regs[3], (SP + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[20] = cpu->regs[1] + cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[20];
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_GT) goto L_21e348;
    FLAG_CMP(cpu->regs[28], cpu->regs[0]);
    if (FLAG_LT) goto L_21e3ec;
L_21e284:
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x21e290ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x120700ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_21e300;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[25] + 0), cpu->regs[20]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_21e2c0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_21e2c0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21e2c0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_21e2c0:
    cpu->regs[0] = 0ULL;
    goto L_21e30c;
L_21e2c8:
    PB_STR((cpu->regs[0] + 88), cpu->regs[3]); PB_STR((cpu->regs[0] + 88) + 8, cpu->regs[4]);
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[0] + 104ULL;
    cpu->regs[30] = PB_BASE + 0x21e2d8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x247bb0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_21e1c4;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if ((cpu->regs[0])==0) goto L_21e2fc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[23] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_21e2fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_21e480;
L_21e2fc:
    cpu->regs[19] = 0ULL;
L_21e300:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x21e308ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 4294967295ULL;
L_21e30c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_21e3c8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_21e348:
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 40));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    PB_STR((cpu->regs[24] + 40), cpu->regs[1]);
    cpu->regs[2] = cpu->regs[1];
    FLAG_CMP(cpu->regs[28], cpu->regs[0]);
    if (FLAG_LT) goto L_21e3f0;
L_21e364:
    cpu->regs[0] = 1ULL;
    PB_STRB((cpu->regs[24] + 52), cpu->regs[0]);
    cpu->regs[2] = 127ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 32));
    cpu->regs[5] = ((uint32_t)(((cpu->regs[4] >> 6) & 0x1ULL)));
    if (!((cpu->regs[4] >> 6) & 1)) goto L_21e3cc;
L_21e37c:
    PB_LDRW(cpu->regs[3], (cpu->regs[24] + 20));
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 32));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_LO) goto L_21e3a0;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 24));
    cpu->regs[3] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] - cpu->regs[0];
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_LE) goto L_21e284;
L_21e3a0:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_21e284;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[2] = 127ULL;
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_21e458;
L_21e3b4:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x21e3bcULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x11cba0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_21e284;
    goto L_21e300;
L_21e3c8:
    cpu->regs[30] = PB_BASE + 0x21e3ccULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x7c170ULL);
L_21e3cc:
    cpu->regs[0] = ((uint32_t)(((cpu->regs[4] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_21e404;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    cpu->regs[2] = 65535ULL;
    cpu->regs[0] = 1114111ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[0];
    goto L_21e37c;
L_21e3ec:
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 40));
L_21e3f0:
    cpu->regs[27] = cpu->regs[27] + cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[23];
    cpu->regs[1] = cpu->regs[27] + cpu->regs[0];
    PB_STR((cpu->regs[24] + 40), cpu->regs[1]);
    goto L_21e364;
L_21e404:
    cpu->regs[2] = 255ULL;
    goto L_21e37c;
L_21e40c:
    cpu->regs[2] = cpu->regs[2] + cpu->regs[26];
    PB_STR((SP + 8), cpu->regs[2]);
    goto L_21e250;
L_21e418:
    cpu->regs[30] = PB_BASE + 0x21e41cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21e248;
L_21e420:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 811ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x21e438ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_21e300;
L_21e43c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 3560ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x21e454ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_21e300;
L_21e458:
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_21e478;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(2ULL)));
    cpu->regs[2] = 65535ULL;
    cpu->regs[0] = 1114111ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[0];
    goto L_21e3b4;
L_21e478:
    cpu->regs[2] = 255ULL;
    goto L_21e3b4;
L_21e480:
    cpu->regs[30] = PB_BASE + 0x21e484ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_21e1c4;
}
