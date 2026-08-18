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

void ft_PyType_Modified(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_18e42c:
    SP = SP - 96ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if (((cpu->regs[2] >> 19) & 1)) goto L_18e47c;
L_18e454:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_18e51c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 96ULL;
    return;
L_18e47c:
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x18e488ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe1a08ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_18e4b8;
L_18e490:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 408));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_18e52c;
L_18e498:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    PB_STRW((cpu->regs[19] + 384), 0ULL);
    cpu->regs[1] = cpu->regs[0] & 18446744073709027327ULL;
    PB_STR((cpu->regs[19] + 168), cpu->regs[1]);
    if (!((cpu->regs[0] >> 9) & 1)) goto L_18e590;
    PB_STR((cpu->regs[19] + 904), 0ULL);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    goto L_18e454;
L_18e4b8:
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = SP + 16ULL;
    cpu->regs[21] = SP + 8ULL;
    PB_STR((SP + 8), 0ULL);
L_18e4d4:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18e4e8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18e510;
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_18e4d4;
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_18e4d4;
    cpu->regs[30] = PB_BASE + 0x18e50cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18e42cULL);
    goto L_18e4d4;
L_18e510:
    PB_LDR(cpu->regs[23], (SP + 80));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_18e490;
L_18e51c:
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x18e52cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_18e52c:
    cpu->regs[2] = cpu->tls_ptr;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x18e544ULL; PB_CALL(5, cpu, tlb, cpu->regs[3]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[23] = 33402ULL;
L_18e55c:
    if (!((cpu->regs[20] >> 0) & 1)) goto L_18e598;
L_18e560:
    cpu->regs[0] = cpu->regs[23] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[0] << 3)));
    if ((cpu->regs[1])==0) goto L_18e578;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18e574ULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18e5a8;
L_18e578:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[20] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[20] >> 1)));
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_18e55c;
    PB_LDR(cpu->regs[23], (SP + 80));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_18e498;
L_18e590:
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    goto L_18e454;
L_18e598:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[20] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[20] >> 1)));
    if (!((cpu->regs[20] >> 0) & 1)) goto L_18e598;
    goto L_18e560;
L_18e5a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18e5b0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_18e578;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[2] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8080));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_18e5e4;
L_18e5d8:
    cpu->regs[1] = 24464ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    return;
L_18e5e4:
    PB_STRW((cpu->regs[2] + 8080), cpu->regs[1]);
    goto L_18e5d8;
    SP = SP - 80ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x18e634ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18e780ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 168));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 12) & 1)) goto L_18e740;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18e650ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18e7c4ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18e774;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 24),&_s,4); cpu->regs[4] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = PB_BASE + 0x51d000ULL;
    PB_LDR(cpu->regs[9], (cpu->regs[20] + 0)); PB_LDR(cpu->regs[7], (cpu->regs[20] + 0) + 8);
    cpu->regs[4] = cpu->regs[21] - cpu->regs[4];
    cpu->regs[4] = cpu->regs[4] + 3ULL;
    cpu->regs[0] = cpu->regs[0] + 3600ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2640));
    cpu->regs[22] = cpu->regs[22] | 16384ULL;
    cpu->regs[0] = cpu->regs[0] + 1720ULL;
    cpu->regs[4] = cpu->regs[4] << 3;
    cpu->regs[6] = PB_BASE + 0x149000ULL;
    cpu->regs[5] = PB_BASE + 0x27a000ULL;
    cpu->regs[6] = cpu->regs[6] + 1952ULL;
    cpu->regs[5] = cpu->regs[5] + 3360ULL;
    cpu->regs[1] = PB_BASE + 0x20b000ULL;
    cpu->regs[3] = PB_BASE + 0x258000ULL;
    cpu->regs[1] = cpu->regs[1] + 560ULL;
    cpu->regs[3] = cpu->regs[3] + 1184ULL;
    cpu->regs[8] = 8ULL;
    cpu->regs[10] = 4294967295ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[10]);
    PB_STR((cpu->regs[19] + 24), cpu->regs[9]); PB_STR((cpu->regs[19] + 24) + 8, cpu->regs[4]);
    PB_STR((cpu->regs[19] + 40), cpu->regs[8]); PB_STR((cpu->regs[19] + 40) + 8, cpu->regs[6]);
    PB_STR((cpu->regs[19] + 88), cpu->regs[5]);
    PB_STR((cpu->regs[19] + 168), cpu->regs[22]); PB_STR((cpu->regs[19] + 168) + 8, cpu->regs[7]);
    PB_STR((cpu->regs[19] + 184), cpu->regs[3]);
    PB_STR((cpu->regs[19] + 232), cpu->regs[0]); PB_STR((cpu->regs[19] + 232) + 8, cpu->regs[23]);
    PB_STR((cpu->regs[19] + 256), cpu->regs[2]);
    PB_STR((cpu->regs[19] + 312), cpu->regs[1]);
L_18e6d0:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18e6dcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x187e60ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18e74c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18e6e8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdb420ULL);
    PB_LDR(cpu->regs[3], (SP + 0));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18e6fcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18e8a0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_18e768;
L_18e70c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_18e748;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_18e740:
    cpu->regs[23] = 0ULL;
    goto L_18e6d0;
L_18e748:
    cpu->regs[30] = PB_BASE + 0x18e74cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_18e74c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] + 3456ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18e768ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11f220ULL);
L_18e768:
    if ((cpu->regs[23])==0) goto L_18e774;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x18e774ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_18e774:
    cpu->regs[0] = 4294967295ULL;
    goto L_18e70c;
    /* nop */
L_18e780:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 3496ULL;
    PB_STR((cpu->regs[1] + 0), 0ULL);
    goto L_18e7a4;
L_18e798:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_EQ) goto L_18e7b4;
L_18e7a4:
    cpu->regs[2] = cpu->regs[0] << 4;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + cpu->regs[2]));
    if ((cpu->regs[2])!=0) goto L_18e798;
    return;
L_18e7b4:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    goto L_18e7a4;
L_18e7c4:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[1] - cpu->regs[2];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = 3689348814741910323ULL;
    cpu->regs[0] = cpu->regs[2] + 1ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 48)) | ((0x333ULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HI) goto L_18e888;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = 40ULL;
    cpu->regs[0] = cpu->regs[0] * cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18e800ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdbd90ULL);
    if ((cpu->regs[0])==0) goto L_18e884;
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3496ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[10] = 6ULL;
    cpu->regs[9] = 1ULL;
    goto L_18e854;
L_18e820:
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[8], (cpu->regs[5] + cpu->regs[8]));
    cpu->regs[5] = cpu->regs[5] + (cpu->regs[3] << 4);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[8], cpu->regs[1]);
    if (FLAG_EQ) goto L_18e854;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 8));
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    PB_STR((cpu->regs[0] + cpu->regs[6]), cpu->regs[8]);
    PB_STRW((cpu->regs[4] + 8), cpu->regs[10]);
    PB_STR((cpu->regs[4] + 16), cpu->regs[2]);
    PB_STRW((cpu->regs[4] + 24), cpu->regs[9]);
    PB_STR((cpu->regs[4] + 32), cpu->regs[5]);
L_18e854:
    cpu->regs[6] = cpu->regs[7] * cpu->regs[21];
    cpu->regs[2] = cpu->regs[3] << 3;
    cpu->regs[8] = cpu->regs[3] << 4;
    cpu->regs[2] = cpu->regs[2] + 24ULL;
    cpu->regs[4] = cpu->regs[0] + cpu->regs[6];
    FLAG_CMP(cpu->regs[3], cpu->regs[19]);
    if (FLAG_LT) goto L_18e820;
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STR((cpu->regs[0] + cpu->regs[6]), 0ULL);
L_18e878:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_18e884:
    PB_LDR(cpu->regs[21], (SP + 32));
L_18e888:
    cpu->regs[30] = PB_BASE + 0x18e88cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = 0ULL;
    goto L_18e878;
    /* nop */
    /* nop */
    /* nop */
L_18e8a0:
    SP = SP - 80ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 24),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18e8e4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    if ((cpu->regs[0])==0) goto L_18ea6c;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[23] = PB_BASE + 0x2b7000ULL;
    cpu->regs[1] = cpu->regs[23] + 1840ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3008ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x18e904ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ead0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_18eaa0;
L_18e910:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18e918ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18ea6c;
    cpu->regs[1] = cpu->regs[23] + 1840ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3032ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x18e934ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ead0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_18eab8;
L_18e940:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18e948ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18ea6c;
    cpu->regs[1] = cpu->regs[23] + 1840ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 3056ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x18e964ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ead0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_18ea88;
L_18e970:
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 24),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x18e978ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdb480ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18ea6c;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 24),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[21] = PB_BASE + 0x283000ULL;
    cpu->regs[21] = cpu->regs[21] + 3496ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 0ULL;
L_18e994:
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_LE) goto L_18e9d4;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 16));
    cpu->regs[0] = cpu->regs[19] << 4;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_EQ) goto L_18e9cc;
    cpu->regs[30] = PB_BASE + 0x18e9b4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdea4cULL);
    PB_LDR(cpu->regs[2], (SP + 0));
    if ((cpu->regs[0])==0) goto L_18ea50;
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[20] << 3);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 24),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_STR((cpu->regs[2] + 24), cpu->regs[0]);
L_18e9cc:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_18e994;
L_18e9d4:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x18e9e0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe2100ULL);
    PB_LDR(cpu->regs[2], (SP + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_18ea50;
    cpu->regs[1] = cpu->regs[23] + 1840ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 3080ULL;
    cpu->regs[30] = PB_BASE + 0x18e9fcULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[2], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ea50;
    if (((cpu->regs[1] >> 31) & 1)) goto L_18ea18;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_18ea74;
L_18ea18:
    cpu->regs[0] = 0ULL;
L_18ea1c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_18ea84;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_18ea50:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ea6c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18ea6c;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x18ea6cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_18ea6c:
    cpu->regs[0] = 4294967295ULL;
    goto L_18ea1c;
L_18ea74:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x18ea7cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_18ea1c;
L_18ea84:
    cpu->regs[30] = PB_BASE + 0x18ea88ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c170ULL);
L_18ea88:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_18e970;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18ea9cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18e970;
L_18eaa0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_18e910;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18eab4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18e910;
L_18eab8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_18e940;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18eaccULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18e940;
L_18ead0:
    if (((cpu->regs[1] >> 31) & 1)) goto L_18ea6c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_18ea6c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18eae8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_18ea1c;
}
