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

void ft__PyWeakref_ClearRef(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
    PB_STR((cpu->regs[0] + 24), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1ded3cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1a1f20ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[20]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1ded60ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18e42cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ded68ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])==0) goto L_1ded70;
    cpu->regs[30] = PB_BASE + 0x1ded70ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1c17e0ULL);
L_1ded70:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 888));
    if ((cpu->regs[0])!=0) goto L_1dedac;
L_1ded78:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 344));
    if ((cpu->regs[0])==0) goto L_1ded9c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 344), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ded9c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ded9c;
    cpu->regs[30] = PB_BASE + 0x1ded9cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ded9c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1dedac:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 888), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ded78;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ded78;
    cpu->regs[30] = PB_BASE + 0x1dedc8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ded78;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1dede0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[30] = PB_BASE + 0x1dede4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1dee90ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1dedecULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x13f6ecULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 256));
    cpu->regs[30] = PB_BASE + 0x1dedf4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 264));
    cpu->regs[30] = PB_BASE + 0x1dedfcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 336));
    cpu->regs[30] = PB_BASE + 0x1dee04ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 344));
    cpu->regs[30] = PB_BASE + 0x1dee0cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 352));
    cpu->regs[30] = PB_BASE + 0x1dee14ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1dee1cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1df1e0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 176));
    cpu->regs[30] = PB_BASE + 0x1dee24ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdfce0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 856));
    cpu->regs[30] = PB_BASE + 0x1dee2cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 872));
    cpu->regs[30] = PB_BASE + 0x1dee34ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 864));
    cpu->regs[30] = PB_BASE + 0x1dee3cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 880));
    if ((cpu->regs[1])==0) goto L_1dee64;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1dee58ULL; PB_CALL(20, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1dee64ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe9320ULL);
L_1dee64:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 888));
    cpu->regs[30] = PB_BASE + 0x1dee6cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 896));
    cpu->regs[30] = PB_BASE + 0x1dee74ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1dee90:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 336));
    if ((cpu->regs[4])==0) goto L_1deecc;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1deeacULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1deebcULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1deed0ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0x121f40ULL); return; };
L_1deecc:
    return;
L_1deed0:
    SP = SP - 160ULL;
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = 0ULL;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[1] + 24ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
L_1def14:
    FLAG_CMP(cpu->regs[22], cpu->regs[4]);
    if (FLAG_LT) goto L_1def54;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1defb8;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    SP = SP + 160ULL;
    return;
L_1def54:
    PB_LDR(cpu->regs[24], (cpu->regs[25] + (cpu->regs[22] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1defb0;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1def6cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe1a08ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1defb0;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1def7cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1564ULL);
    PB_STR((SP + 32), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1defd8;
L_1def88:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1def94ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x197f6cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1defd0;
L_1def98:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1defa0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1defa8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1df090ULL);
    if ((cpu->regs[0])==0) goto L_1defc0;
    PB_LDR(cpu->regs[4], (cpu->regs[21] + 16));
L_1defb0:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_1def14;
L_1defb8:
    PB_STR((SP + 144), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x1defc0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1defc0:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1defc8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1df1e0ULL);
    PB_LDR(cpu->regs[4], (cpu->regs[21] + 16));
    goto L_1defb0;
L_1defd0:
    cpu->regs[30] = PB_BASE + 0x1defd4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1def98;
L_1defd8:
    cpu->regs[30] = PB_BASE + 0x1defdcULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_STR((SP + 40), 0ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1defe8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe1a08ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1def98;
    PB_STR((SP + 144), cpu->regs[27]);
    cpu->regs[3] = SP + 48ULL;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2760));
    cpu->regs[2] = SP + 32ULL;
    cpu->regs[1] = SP + 40ULL;
L_1df008:
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 8), cpu->regs[1]); PB_STR((SP + 8) + 8, cpu->regs[2]);
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1df018ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xecfc8ULL);
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[1], (SP + 8)); PB_LDR(cpu->regs[2], (SP + 8) + 8);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1df060;
    PB_LDR(cpu->regs[0], (SP + 48));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[4], 0ULL);
    if (FLAG_GT) goto L_1df068;
    cpu->regs[0] = 0ULL;
L_1df03c:
    FLAG_CMP(cpu->regs[23], cpu->regs[0]);
    if (FLAG_NE) goto L_1df008;
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1df074;
    PB_LDR(cpu->regs[27], (SP + 144));
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1def88;
L_1df060:
    PB_LDR(cpu->regs[27], (SP + 144));
    goto L_1def98;
L_1df068:
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : 0ULL;
    goto L_1df03c;
L_1df074:
    PB_LDR(cpu->regs[27], (SP + 144));
    goto L_1def88;
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    { PB_CALL(38, cpu, tlb, PB_BASE + 0x7c060ULL); return; };
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 72));
    { PB_CALL(39, cpu, tlb, PB_BASE + 0x7bdc0ULL); return; };
}
