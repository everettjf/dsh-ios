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

void ft__Py_HashBytes(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_d7fd4;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = PB_BASE + 0x51d000ULL;
    cpu->regs[4] = PB_BASE + 0xd8000ULL;
    cpu->regs[29] = SP;
    cpu->regs[4] = cpu->regs[4] + 0ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 4088));
    FLAG_CMP(cpu->regs[5], cpu->regs[4]);
    if (FLAG_NE) goto L_d7fdc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3160));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0xd7fc4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd8020ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d7fe8;
L_d7fcc:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_d7fd4:
    cpu->regs[0] = cpu->regs[1];
    return;
L_d7fdc:
    cpu->regs[30] = PB_BASE + 0xd7fe0ULL; PB_CALL(2, cpu, tlb, cpu->regs[5]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_d7fcc;
L_d7fe8:
    cpu->regs[3] = 18446744073709551614ULL;
    cpu->regs[0] = cpu->regs[3];
    goto L_d7fcc;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3160));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[4] + 0) + 8);
    goto L_d8020;
    /* nop */
    /* nop */
L_d8020:
    SP = SP - 48ULL;
    cpu->regs[8] = cpu->regs[3];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[5] = 25973ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[5] = (cpu->regs[5] & ~(0xffffULL << 16)) | ((0x7073ULL & 0xffff) << 16);
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[5] = (cpu->regs[5] & ~(0xffffULL << 32)) | ((0x6d65ULL & 0xffff) << 32);
    cpu->regs[3] = 29281ULL;
    cpu->regs[5] = (cpu->regs[5] & ~(0xffffULL << 48)) | ((0x736fULL & 0xffff) << 48);
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 16)) | ((0x6e65ULL & 0xffff) << 16);
    cpu->regs[5] = cpu->regs[0] ^ cpu->regs[5];
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 32)) | ((0x6765ULL & 0xffff) << 32);
    cpu->regs[6] = 25971ULL;
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 48)) | ((0x6c79ULL & 0xffff) << 48);
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[3];
    cpu->regs[3] = 28525ULL;
    cpu->regs[6] = (cpu->regs[6] & ~(0xffffULL << 16)) | ((0x7974ULL & 0xffff) << 16);
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 16)) | ((0x6e64ULL & 0xffff) << 16);
    cpu->regs[6] = (cpu->regs[6] & ~(0xffffULL << 32)) | ((0x6462ULL & 0xffff) << 32);
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 32)) | ((0x7261ULL & 0xffff) << 32);
    cpu->regs[6] = (cpu->regs[6] & ~(0xffffULL << 48)) | ((0x7465ULL & 0xffff) << 48);
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 48)) | ((0x646fULL & 0xffff) << 48);
    cpu->regs[4] = cpu->regs[8] << 56;
    cpu->regs[3] = cpu->regs[1] ^ cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[6];
    FLAG_CMP(cpu->regs[8], 7ULL);
    if (FLAG_GT) goto L_d8204;
L_d80a0:
    PB_STR((SP + 8), 0ULL);
    FLAG_CMP(cpu->regs[8], 5ULL);
    if (FLAG_EQ) goto L_d8344;
    if (FLAG_LE) goto L_d81c8;
    FLAG_CMP(cpu->regs[8], 6ULL);
    if (FLAG_NE) goto L_d8338;
L_d80b8:
    PB_LDRH(cpu->regs[6], (cpu->regs[2] + 4));
    PB_STRH((SP + 12), cpu->regs[6]);
L_d80c0:
    cpu->regs[6] = SP + 8ULL;
    cpu->regs[7] = SP + 12ULL;
    FLAG_CMP(cpu->regs[6], cpu->regs[2]);
    if (FLAG_LO) { FLAG_CMP(cpu->regs[7], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_HI) goto L_d839c;
    FLAG_CMP(cpu->regs[2], cpu->regs[6]);
    if (FLAG_HS) goto L_d80e8;
    cpu->regs[7] = cpu->regs[2] + 4ULL;
    FLAG_CMP(cpu->regs[6], cpu->regs[7]);
    if (FLAG_LO) goto L_d839c;
L_d80e8:
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 0));
    PB_STRW((SP + 8), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[4] = cpu->regs[4] | cpu->regs[2];
L_d80f8:
    cpu->regs[2] = cpu->regs[1] ^ cpu->regs[4];
    cpu->regs[5] = cpu->regs[5] + cpu->regs[3];
    cpu->regs[3] = cpu->regs[5] ^ ror64(cpu->regs[3], 51);
    cpu->regs[0] = cpu->regs[2] + cpu->regs[0];
    cpu->regs[2] = cpu->regs[0] ^ ror64(cpu->regs[2], 48);
    cpu->regs[5] = ror64(cpu->regs[5], 32);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    cpu->regs[5] = cpu->regs[2] + cpu->regs[5];
    cpu->regs[3] = cpu->regs[0] ^ ror64(cpu->regs[3], 47);
    cpu->regs[4] = cpu->regs[5] ^ cpu->regs[4];
    cpu->regs[4] = cpu->regs[3] + cpu->regs[4];
    cpu->regs[1] = ror64(cpu->regs[0], 32);
    cpu->regs[2] = cpu->regs[5] ^ ror64(cpu->regs[2], 43);
    cpu->regs[1] = cpu->regs[1] ^ 255ULL;
    cpu->regs[0] = cpu->regs[4] ^ ror64(cpu->regs[3], 51);
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[2] = cpu->regs[1] ^ ror64(cpu->regs[2], 48);
    cpu->regs[3] = ror64(cpu->regs[4], 32);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[3] = cpu->regs[2] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[1] ^ ror64(cpu->regs[0], 47);
    cpu->regs[2] = cpu->regs[3] ^ ror64(cpu->regs[2], 43);
    cpu->regs[3] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[1] = ror64(cpu->regs[1], 32);
    cpu->regs[0] = cpu->regs[3] ^ ror64(cpu->regs[0], 51);
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[2] = cpu->regs[1] ^ ror64(cpu->regs[2], 48);
    cpu->regs[3] = ror64(cpu->regs[3], 32);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[3] = cpu->regs[2] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[1] ^ ror64(cpu->regs[0], 47);
    cpu->regs[2] = cpu->regs[3] ^ ror64(cpu->regs[2], 43);
    cpu->regs[3] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[1] = ror64(cpu->regs[1], 32);
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[3] ^ ror64(cpu->regs[0], 51);
    cpu->regs[3] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[2] = cpu->regs[1] ^ ror64(cpu->regs[2], 48);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[4] = ror64(cpu->regs[3], 32);
    cpu->regs[0] = cpu->regs[3] ^ ror64(cpu->regs[0], 47);
    cpu->regs[2] = cpu->regs[4] ^ ror64(cpu->regs[2], 43);
    cpu->regs[0] = cpu->regs[2] ^ cpu->regs[0];
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_d8350;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_d81c8:
    FLAG_CMP(cpu->regs[8], 3ULL);
    if (FLAG_EQ) goto L_d832c;
    FLAG_CMP(cpu->regs[8], 4ULL);
    if (FLAG_EQ) goto L_d80c0;
    FLAG_CMP(cpu->regs[8], 1ULL);
    if (FLAG_EQ) goto L_d81f0;
    FLAG_CMP(cpu->regs[8], 2ULL);
    if (FLAG_NE) goto L_d80f8;
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + 1));
    PB_STRB((SP + 9), cpu->regs[6]);
L_d81f0:
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + 0));
    PB_STRB((SP + 8), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[4] = cpu->regs[4] | cpu->regs[2];
    goto L_d80f8;
L_d8204:
    cpu->regs[7] = SP + 16ULL;
    cpu->regs[10] = SP + 24ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[2]);
    if (FLAG_LO) { FLAG_CMP(cpu->regs[10], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_HI) goto L_d839c;
    cpu->regs[6] = cpu->regs[2] + 8ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[7]);
    if (FLAG_HS) goto L_d8274;
    FLAG_CMP(cpu->regs[6], cpu->regs[7]);
    if (FLAG_HI) goto L_d839c;
    PB_LDR(cpu->regs[9], (cpu->regs[2] + 0));
    cpu->regs[5] = cpu->regs[5] + cpu->regs[3];
    cpu->regs[3] = cpu->regs[5] ^ ror64(cpu->regs[3], 51);
    cpu->regs[8] = cpu->regs[8] - 8ULL;
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[9];
    cpu->regs[5] = ror64(cpu->regs[5], 32);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[0] ^ ror64(cpu->regs[1], 48);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[5] = cpu->regs[5] + cpu->regs[1];
    cpu->regs[3] = cpu->regs[2] ^ ror64(cpu->regs[3], 47);
    cpu->regs[1] = cpu->regs[5] ^ ror64(cpu->regs[1], 43);
    cpu->regs[0] = ror64(cpu->regs[2], 32);
    cpu->regs[5] = cpu->regs[5] ^ cpu->regs[9];
    FLAG_CMP(cpu->regs[8], 7ULL);
    if (FLAG_HI) goto L_d82c0;
L_d826c:
    cpu->regs[2] = cpu->regs[6];
    goto L_d80a0;
L_d8274:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[5] = cpu->regs[5] + cpu->regs[3];
    cpu->regs[3] = cpu->regs[5] ^ ror64(cpu->regs[3], 51);
    cpu->regs[8] = cpu->regs[8] - 8ULL;
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[2];
    cpu->regs[5] = ror64(cpu->regs[5], 32);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[0] ^ ror64(cpu->regs[1], 48);
    cpu->regs[0] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[5] = cpu->regs[5] + cpu->regs[1];
    cpu->regs[3] = cpu->regs[0] ^ ror64(cpu->regs[3], 47);
    cpu->regs[1] = cpu->regs[5] ^ ror64(cpu->regs[1], 43);
    cpu->regs[0] = ror64(cpu->regs[0], 32);
    cpu->regs[5] = cpu->regs[5] ^ cpu->regs[2];
    FLAG_CMP(cpu->regs[8], 7ULL);
    if (FLAG_LS) goto L_d826c;
    /* nop */
    /* nop */
    /* nop */
L_d82c0:
    FLAG_CMP(cpu->regs[7], cpu->regs[6]);
    if (FLAG_LO) { FLAG_CMP(cpu->regs[10], cpu->regs[6]); } else { FLAG_CMP(0, 1); }
    if (FLAG_HI) goto L_d839c;
    cpu->regs[6] = cpu->regs[6] + 8ULL;
    cpu->regs[2] = cpu->regs[6] - 8ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[2]);
    if (FLAG_LS) goto L_d8354;
    FLAG_CMP(cpu->regs[6], cpu->regs[7]);
    if (FLAG_HI) goto L_d839c;
    PB_LDR(cpu->regs[9], (cpu->regs[6] + -8));
    cpu->regs[5] = cpu->regs[5] + cpu->regs[3];
    cpu->regs[3] = cpu->regs[5] ^ ror64(cpu->regs[3], 51);
    cpu->regs[8] = cpu->regs[8] - 8ULL;
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[9];
    cpu->regs[5] = ror64(cpu->regs[5], 32);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[0] ^ ror64(cpu->regs[1], 48);
    cpu->regs[2] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[5] = cpu->regs[5] + cpu->regs[1];
    cpu->regs[3] = cpu->regs[2] ^ ror64(cpu->regs[3], 47);
    cpu->regs[1] = cpu->regs[5] ^ ror64(cpu->regs[1], 43);
    cpu->regs[0] = ror64(cpu->regs[2], 32);
    cpu->regs[5] = cpu->regs[5] ^ cpu->regs[9];
    FLAG_CMP(cpu->regs[8], 7ULL);
    if (FLAG_HI) goto L_d82c0;
    cpu->regs[2] = cpu->regs[6];
    goto L_d80a0;
L_d832c:
    PB_LDRH(cpu->regs[6], (cpu->regs[2] + 1));
    PB_STRH((SP + 9), cpu->regs[6]);
    goto L_d81f0;
L_d8338:
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + 6));
    PB_STRB((SP + 14), cpu->regs[6]);
    goto L_d80b8;
L_d8344:
    PB_LDRB(cpu->regs[6], (cpu->regs[2] + 4));
    PB_STRB((SP + 12), cpu->regs[6]);
    goto L_d80c0;
L_d8350:
    cpu->regs[30] = PB_BASE + 0xd8354ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_d8354:
    PB_LDR(cpu->regs[2], (cpu->regs[6] + -8));
    cpu->regs[5] = cpu->regs[5] + cpu->regs[3];
    cpu->regs[3] = cpu->regs[5] ^ ror64(cpu->regs[3], 51);
    cpu->regs[8] = cpu->regs[8] - 8ULL;
    cpu->regs[1] = cpu->regs[2] ^ cpu->regs[1];
    cpu->regs[5] = ror64(cpu->regs[5], 32);
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[0] ^ ror64(cpu->regs[1], 48);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    cpu->regs[5] = cpu->regs[1] + cpu->regs[5];
    cpu->regs[3] = cpu->regs[0] ^ ror64(cpu->regs[3], 47);
    cpu->regs[1] = cpu->regs[5] ^ ror64(cpu->regs[1], 43);
    cpu->regs[0] = ror64(cpu->regs[0], 32);
    cpu->regs[5] = cpu->regs[5] ^ cpu->regs[2];
    FLAG_CMP(cpu->regs[8], 7ULL);
    if (FLAG_HI) goto L_d82c0;
    cpu->regs[2] = cpu->regs[6];
    goto L_d80a0;
L_d839c:
    __builtin_trap();
}
