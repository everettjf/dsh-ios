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

void ft_PyNumber_Rshift(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 96ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16a728ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2400));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_16a744;
L_16a738:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_16a744:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 96ULL;
    cpu->regs[3] = cpu->regs[3] + 3936ULL;
    cpu->regs[30] = PB_BASE + 0x16a75cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1b02c0ULL);
    cpu->regs[0] = 0ULL;
    goto L_16a738;
    SP = SP - 64ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_16a90c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_16a90c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_16a8ec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_16a82c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16a7d0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[2] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_16a864;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_16a8e8;
    cpu->regs[1] = 9838263505978427528ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 0)) | ((0x8889ULL & 0xffff) << 0);
    cpu->regs[1] = (uint64_t)(((__int128)(int64_t)cpu->regs[2] * (__int128)(int64_t)cpu->regs[1]) >> 64);
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 4);
    cpu->regs[1] = cpu->regs[1] - ((uint64_t)((int64_t)cpu->regs[2] >> 63));
    cpu->regs[3] = cpu->regs[1] << 4;
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - (cpu->regs[3] << 1)));
L_16a81c:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    goto L_16a920;
L_16a82c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 3208ULL;
L_16a838:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_16a8e8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_16a864:
    cpu->regs[30] = PB_BASE + 0x16a868ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = SP + 20ULL;
    cpu->regs[1] = 30ULL;
    cpu->regs[30] = PB_BASE + 0x16a878ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x151260ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_16a904;
    cpu->regs[30] = PB_BASE + 0x16a884ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_16a8ac;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_16a8ac;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x16a8a8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
L_16a8ac:
    cpu->regs[0] = 2305843009213693950ULL;
    PB_LDRW(cpu->regs[2], (SP + 20));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_16a8c8;
    cpu->regs[30] = PB_BASE + 0x16a8c0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 2305843009213693951ULL;
L_16a8c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[4], (SP + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    if (FLAG_EQ) goto L_16a81c;
L_16a8e8:
    cpu->regs[30] = PB_BASE + 0x16a8ecULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c170ULL);
L_16a8ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 1048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x16a904ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_16a904:
    cpu->regs[0] = 0ULL;
    goto L_16a838;
L_16a90c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_16a838;
    /* nop */
    /* nop */
L_16a920:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    cpu->regs[20] = cpu->regs[3] & 3ULL;
    FLAG_CMP(cpu->regs[3], 15ULL);
    if (FLAG_HI) goto L_16a9a8;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[3];
    if ((cpu->regs[1])!=0) goto L_16ac6c;
    cpu->regs[0] = (uint64_t)((int64_t)cpu->regs[0] >> (cpu->regs[2] & 63));
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_HI) goto L_16a988;
L_16a964:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 5ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_16a97c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_16a988:
    cpu->regs[1] = 1073741823ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = 2147483646ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HI) goto L_16ac4c;
L_16a99c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xe3e84ULL); return; };
L_16a9a8:
    FLAG_CMP(cpu->regs[20], 2ULL);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[3] >> 3;
    cpu->regs[3] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[3], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_16ac80;
L_16a9c4:
    cpu->regs[22] = cpu->regs[21] - cpu->regs[1];
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_16aca8;
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 48), cpu->regs[1]);
    PB_STRW((SP + 60), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x16a9e0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_16aca0;
    PB_LDR(cpu->regs[1], (SP + 48));
    cpu->regs[7] = 30ULL;
    PB_LDRW(cpu->regs[2], (SP + 60));
    cpu->regs[3] = cpu->regs[19] + (cpu->regs[1] << 2);
    cpu->regs[7] = ((uint32_t)(cpu->regs[7] - cpu->regs[2]));
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 24));
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_16ac18;
L_16aa04:
    cpu->regs[4] = cpu->regs[1] + 1ULL;
    cpu->regs[2] = cpu->regs[3] >> (cpu->regs[2] & 63);
    FLAG_CMP(cpu->regs[4], cpu->regs[21]);
    if (FLAG_GE) goto L_16abfc;
    cpu->regs[3] = cpu->regs[21] - 1ULL;
    cpu->regs[19] = cpu->regs[19] + (cpu->regs[1] << 2);
    cpu->regs[1] = cpu->regs[3] - cpu->regs[1];
    cpu->regs[19] = cpu->regs[19] + 28ULL;
    cpu->regs[3] = cpu->regs[1] & 7ULL; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[6] = cpu->regs[0] + 24ULL;
    cpu->regs[4] = 0ULL;
    if (FLAG_EQ) goto L_16ab30;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_16ab0c;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_EQ) goto L_16aaf0;
    FLAG_CMP(cpu->regs[3], 3ULL);
    if (FLAG_EQ) goto L_16aad4;
    FLAG_CMP(cpu->regs[3], 4ULL);
    if (FLAG_EQ) goto L_16aab8;
    FLAG_CMP(cpu->regs[3], 5ULL);
    if (FLAG_EQ) goto L_16aa9c;
    FLAG_CMP(cpu->regs[3], 6ULL);
    if (FLAG_EQ) goto L_16aa80;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[4] = 1ULL;
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + 0), cpu->regs[3]);
    cpu->regs[2] = cpu->regs[2] >> 30;
L_16aa80:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[2] = cpu->regs[2] >> 30;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
L_16aa9c:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[2] = cpu->regs[2] >> 30;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
L_16aab8:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[2] = cpu->regs[2] >> 30;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
L_16aad4:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[2] = cpu->regs[2] >> 30;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
L_16aaf0:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[2] = cpu->regs[2] >> 30;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
L_16ab0c:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[2] = cpu->regs[2] >> 30;
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_EQ) goto L_16abfc;
L_16ab30:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[5] = cpu->regs[4] + 1ULL;
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[4] + 2ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[5] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] >> 30);
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[5] << 2)), cpu->regs[3]);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] >> 30);
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[5] + 2ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] >> 30);
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[5] + 3ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] >> 30);
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[5] + 4ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] >> 30);
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[5] + 5ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] >> 30);
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[5] + 6ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 2)));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[7] & 63);
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] >> 30);
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[6] + (cpu->regs[4] << 2)), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[5] + 7ULL;
    cpu->regs[2] = cpu->regs[2] >> 30;
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_NE) goto L_16ab30;
L_16abfc:
    cpu->regs[22] = cpu->regs[0] + (cpu->regs[22] << 2);
    PB_STRW((cpu->regs[22] + 20), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x16ac08ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x145d20ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x145da0ULL); return; };
L_16ac18:
    cpu->regs[4] = cpu->regs[22] << 3;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = cpu->regs[4] | 2ULL;
    cpu->regs[6] = 0ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[4]);
L_16ac2c:
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    if (FLAG_GT) goto L_16ac58;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(0ULL)));
    cpu->regs[4] = 1073741823ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] >> (cpu->regs[7] & 63)));
    cpu->regs[4] = ((uint32_t)((FLAG_NE) ? (cpu->regs[4] + 1) : cpu->regs[4]));
    cpu->regs[3] = cpu->regs[3] + ((cpu->regs[4]) & 0xffffffffULL);
    goto L_16aa04;
L_16ac4c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0x169eacULL); return; };
L_16ac58:
    cpu->regs[4] = cpu->regs[19] + 24ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + (cpu->regs[5] << 2)));
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] | cpu->regs[4]));
    goto L_16ac2c;
L_16ac6c:
    cpu->regs[0] = (uint64_t)((int64_t)cpu->regs[0] >> 30);
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_LS) goto L_16a964;
    goto L_16a99c;
L_16ac80:
    if ((cpu->regs[1])!=0) goto L_16ac94;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x16de80ULL); return; };
L_16ac94:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[2] = 30ULL;
    goto L_16a9c4;
L_16aca0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_16a97c;
L_16aca8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = ((uint64_t)(((int64_t)(cpu->regs[3] << (63-0)) ) >> 63));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(17, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 16));
    if ((cpu->regs[2])!=0) goto L_16ad90;
L_16ace0:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_16ad4c;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[19] + 24), cpu->regs[20]);
    if ((cpu->regs[0])==0) goto L_16ad10;
L_16acfc:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_16ad10;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_16ad58;
L_16ad10:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])!=0) goto L_16ad70;
L_16ad18:
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_GT) goto L_16ad60;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
L_16ad28:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_16ad68;
L_16ad34:
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[19] + 72), cpu->regs[1]);
L_16ad3c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_16ad4c:
    PB_STR((cpu->regs[19] + 24), cpu->regs[20]);
    if ((cpu->regs[0])!=0) goto L_16acfc;
    goto L_16ad10;
L_16ad58:
    cpu->regs[30] = PB_BASE + 0x16ad5cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16ad10;
L_16ad60:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    goto L_16ad28;
L_16ad68:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_16ad34;
L_16ad70:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_16ad18;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_16ad18;
    cpu->regs[30] = PB_BASE + 0x16ad8cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16ad18;
L_16ad90:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x16ada0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16ace0;
    cpu->regs[0] = 4294967295ULL;
    goto L_16ad3c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + -16));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[2])==0) goto L_16ae24;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + -8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[3] = cpu->regs[3] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    PB_STR((cpu->regs[2] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_16ae00;
L_16adf4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_16ae30;
L_16ae00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16ae08ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe2500ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_16ae24:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    if ((cpu->regs[0])!=0) goto L_16adf4;
    goto L_16ae00;
L_16ae30:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_16ae00;
    cpu->regs[30] = PB_BASE + 0x16ae40ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16ae00;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    if ((cpu->regs[0])==0) goto L_16ae68;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_16ae80;
L_16ae68:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16ae70ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe2500ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_16ae80:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_16ae68;
    cpu->regs[30] = PB_BASE + 0x16ae90ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16ae68;
    /* nop */
    /* nop */
    /* nop */
}
