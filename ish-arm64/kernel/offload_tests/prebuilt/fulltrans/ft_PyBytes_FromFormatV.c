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

void ft_PyBytes_FromFormatV(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = 1ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    SP = SP - 592ULL;
    cpu->regs[21] = SP + 32ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 584), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDRW(cpu->regs[26], (cpu->regs[1] + 24));
    cpu->regs[25] = cpu->regs[0];
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 0)); PB_LDR(cpu->regs[23], (cpu->regs[1] + 0) + 8);
    PB_STR((SP + 32), 0ULL); PB_STR((SP + 32) + 8, 0ULL);
    PB_STR((cpu->regs[21] + 16), 0ULL); PB_STR((cpu->regs[21] + 16) + 8, 0ULL);
    cpu->regs[30] = PB_BASE + 0x240010ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[3] = 512ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = SP + 68ULL;
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 40), cpu->regs[3]);
    PB_STRW((SP + 64), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x24002cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11db70ULL);
    if ((cpu->regs[0])==0) goto L_2401fc;
    PB_STR((SP + 672), cpu->regs[27]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2272));
    PB_STRW((SP + 60), cpu->regs[19]);
L_240044:
    PB_LDRB(cpu->regs[2], (cpu->regs[25] + 0));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_240120;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(37ULL)));
    if (FLAG_EQ) goto L_240074;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[19] = cpu->regs[25];
    PB_STRB(cpu->regs[1], cpu->regs[2]); cpu->regs[1] += 1;
    cpu->regs[20] = cpu->regs[1];
L_240068:
    cpu->regs[25] = cpu->regs[19] + 1ULL;
    cpu->regs[26] = cpu->regs[24];
    goto L_240044;
L_240074:
    cpu->regs[19] = cpu->regs[25] + 1ULL;
L_240078:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[27] + (cpu->regs[1] << 2)));
    if (((cpu->regs[1] >> 2) & 1)) goto L_240714;
    cpu->regs[1] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(46ULL)));
    if (FLAG_EQ) goto L_24071c;
L_240094:
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(37ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_2400c4;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + (cpu->regs[0] << 2)));
    FLAG_CMP((cpu->regs[0]) & (3ULL), 0);
    if (FLAG_EQ) goto L_240770;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(108ULL)));
    if (FLAG_EQ) goto L_2402c0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(122ULL)));
    if (FLAG_EQ) goto L_24024c;
L_2400c4:
    PB_LDR(cpu->regs[3], (SP + 48));
    cpu->regs[0] = cpu->regs[19] - cpu->regs[25];
    cpu->regs[3] = cpu->regs[3] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[3] - 1ULL;
    PB_STR((SP + 48), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(100ULL)));
    if (FLAG_EQ) goto L_24037c;
    if (FLAG_LS) goto L_240168;
    cpu->regs[0] = 0ULL;
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(115ULL)));
    if (FLAG_EQ) goto L_2401ac;
L_2400f4:
    if (FLAG_LS) goto L_240334;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(117ULL)));
    if (FLAG_NE) goto L_240204;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2406b0;
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_2405c8;
    if (((cpu->regs[26] >> 31) & 1)) goto L_240548;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_240560;
L_240120:
    cpu->regs[1] = cpu->regs[20];
L_240124:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24012cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11dec4ULL);
    PB_LDR(cpu->regs[27], (SP + 672));
L_240130:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 584));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2405b0;
    SP = SP + 592ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_240168:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(37ULL)));
    if (FLAG_EQ) goto L_2403bc;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(99ULL)));
    if (FLAG_NE) goto L_240748;
    if (((cpu->regs[26] >> 31) & 1)) goto L_2403d4;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[0] & 18446744073709551608ULL;
L_240188:
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_240754;
    cpu->regs[1] = cpu->regs[20];
    PB_STR((SP + 48), cpu->regs[3]);
    cpu->regs[22] = cpu->regs[0];
    PB_STRB(cpu->regs[1], cpu->regs[2]); cpu->regs[1] += 1;
    cpu->regs[20] = cpu->regs[1];
    goto L_240068;
L_2401ac:
    if (((cpu->regs[26] >> 31) & 1)) goto L_240418;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_2401c0:
    PB_LDR(cpu->regs[25], (cpu->regs[26] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_GT) goto L_240694;
L_2401cc:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x2401d4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[3] = cpu->regs[0];
L_2401d8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2401e8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x240780ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_240068;
L_2401f0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2401f8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1fa1e0ULL);
    PB_LDR(cpu->regs[27], (SP + 672));
L_2401fc:
    cpu->regs[0] = 0ULL;
    goto L_240130;
L_240204:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(120ULL)));
    if (FLAG_NE) goto L_24063c;
    if (((cpu->regs[26] >> 31) & 1)) goto L_240664;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_240220:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 952ULL;
    cpu->regs[30] = PB_BASE + 0x24023cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_LS) goto L_2401cc;
L_240248:
    __builtin_trap();
L_24024c:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 1));
    cpu->regs[2] = 117ULL;
    PB_LDR(cpu->regs[0], (SP + 48));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(100ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_24062c;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[3] = cpu->regs[19] - cpu->regs[25];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3];
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((SP + 48), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(100ULL)));
    if (FLAG_NE) goto L_240470;
    if (((cpu->regs[26] >> 31) & 1)) goto L_240454;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_240294:
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 2864ULL;
    cpu->regs[30] = PB_BASE + 0x2402b0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_LS) goto L_2401cc;
    __builtin_trap();
L_2402c0:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 1));
    cpu->regs[2] = 117ULL;
    PB_LDR(cpu->regs[0], (SP + 48));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(100ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_24062c;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[3] = cpu->regs[19] - cpu->regs[25];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3];
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((SP + 48), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(100ULL)));
    if (FLAG_NE) goto L_240408;
    if (((cpu->regs[26] >> 31) & 1)) goto L_2403ec;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_240308:
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 920ULL;
    cpu->regs[30] = PB_BASE + 0x240324ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_LS) goto L_2401cc;
    __builtin_trap();
L_240334:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(105ULL)));
    if (FLAG_NE) goto L_240434;
    if (((cpu->regs[26] >> 31) & 1)) goto L_24058c;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_240350:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 2232ULL;
    cpu->regs[30] = PB_BASE + 0x24036cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_LS) goto L_2401cc;
    __builtin_trap();
L_24037c:
    if (((cpu->regs[26] >> 31) & 1)) goto L_240480;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_240390:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 3056ULL;
    cpu->regs[30] = PB_BASE + 0x2403acULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_LS) goto L_2401cc;
    __builtin_trap();
L_2403bc:
    cpu->regs[1] = cpu->regs[20];
    PB_STR((SP + 48), cpu->regs[3]);
    cpu->regs[24] = cpu->regs[26];
    PB_STRB(cpu->regs[1], cpu->regs[2]); cpu->regs[1] += 1;
    cpu->regs[20] = cpu->regs[1];
    goto L_240068;
L_2403d4:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_240534;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[0] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_240188;
L_2403ec:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_240540;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_240308;
L_240408:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(115ULL)));
    cpu->regs[0] = 1ULL;
    cpu->regs[3] = 0ULL;
    goto L_2400f4;
L_240418:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_24052c;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_2401c0;
L_240434:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(112ULL)));
    if (FLAG_NE) goto L_24063c;
    if (((cpu->regs[26] >> 31) & 1)) goto L_2404ac;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_2404c4;
L_240454:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_2404a4;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_240294;
L_240470:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(115ULL)));
    cpu->regs[0] = 0ULL;
    cpu->regs[3] = 1ULL;
    goto L_2400f4;
L_240480:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_24049c;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_240390;
L_24049c:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_240390;
L_2404a4:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_240294;
L_2404ac:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_2405a8;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_2404c4:
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 200ULL;
    cpu->regs[30] = PB_BASE + 0x2404e0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_HI) goto L_240248;
    PB_LDRB(cpu->regs[0], (SP + 9));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(88ULL)));
    if (FLAG_EQ) goto L_240688;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(120ULL)));
    if (FLAG_EQ) goto L_2401cc;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x240508ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[2] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[2], 19ULL);
    if (FLAG_HI) goto L_240248;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = SP + 10ULL;
    cpu->regs[30] = PB_BASE + 0x240520ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7b030ULL);
    cpu->regs[0] = 30768ULL;
    PB_STRH((SP + 8), cpu->regs[0]);
    goto L_2401cc;
L_24052c:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_2401c0;
L_240534:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_240188;
L_240540:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_240308;
L_240548:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_2405b8;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_240560:
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 936ULL;
    cpu->regs[30] = PB_BASE + 0x24057cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_LS) goto L_2401cc;
    __builtin_trap();
L_24058c:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_2405c0;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_240350;
L_2405a8:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_2404c4;
L_2405b0:
    PB_STR((SP + 672), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x2405b8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2405b8:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_240560;
L_2405c0:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_240350;
L_2405c8:
    if (((cpu->regs[26] >> 31) & 1)) goto L_240608;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_2405dc:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 944ULL;
    cpu->regs[30] = PB_BASE + 0x2405f8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_LS) goto L_2401cc;
    __builtin_trap();
L_240608:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_240624;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_2405dc;
L_240624:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_2405dc;
L_24062c:
    cpu->regs[19] = cpu->regs[19] - cpu->regs[25];
    cpu->regs[0] = cpu->regs[0] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((SP + 48), cpu->regs[0]);
L_24063c:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x240644ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x240658ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x240780ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_240124;
    goto L_2401f0;
L_240664:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_240680;
    cpu->regs[0] = cpu->regs[22] + 11ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_240220;
L_240680:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_240220;
L_240688:
    cpu->regs[0] = 120ULL;
    PB_STRB((SP + 9), cpu->regs[0]);
    goto L_2401cc;
L_240694:
    cpu->regs[3] = 0ULL;
L_240698:
    PB_LDRB(cpu->regs[0], (cpu->regs[25] + cpu->regs[3]));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2401d8;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_NE) goto L_240698;
    goto L_2401d8;
L_2406b0:
    if (((cpu->regs[26] >> 31) & 1)) goto L_2406f0;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[24] = cpu->regs[26];
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
L_2406c4:
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = 21ULL;
    cpu->regs[2] = cpu->regs[2] + 928ULL;
    cpu->regs[30] = PB_BASE + 0x2406e0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_LS) goto L_2401cc;
    __builtin_trap();
L_2406f0:
    cpu->regs[24] = ((uint32_t)(cpu->regs[26] + 8ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_24070c;
    cpu->regs[0] = cpu->regs[22] + 15ULL;
    cpu->regs[26] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[0] & 18446744073709551608ULL;
    goto L_2406c4;
L_24070c:
    cpu->regs[26] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    goto L_2406c4;
L_240714:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_240078;
L_24071c:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[3] = 10ULL;
L_240724:
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + (cpu->regs[2] << 2)));
    if (!((cpu->regs[2] >> 2) & 1)) goto L_240094;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 48ULL));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] * cpu->regs[3] + cpu->regs[0];
    goto L_240724;
L_240748:
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_24063c;
    PB_STR((SP + 48), cpu->regs[3]);
    goto L_24063c;
L_240754:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x24076cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_2401f0;
L_240770:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_240094;
    /* nop */
    /* nop */
}
