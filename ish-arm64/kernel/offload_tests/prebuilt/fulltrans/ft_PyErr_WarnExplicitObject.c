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

void ft_PyErr_WarnExplicitObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[4];
    cpu->regs[24] = cpu->regs[5];
    if ((cpu->regs[0])==0) goto L_1e1650;
L_1e15fc:
    cpu->regs[30] = PB_BASE + 0x1e1600ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1e17e0ULL);
    if ((cpu->regs[0])==0) goto L_1e1678;
    PB_STR((SP + 0), 0ULL);
    cpu->regs[6] = cpu->regs[24];
    cpu->regs[5] = cpu->regs[23];
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[7] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e1628ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1e19c0ULL);
    if ((cpu->regs[0])==0) goto L_1e1678;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1e1660;
L_1e1634:
    cpu->regs[0] = 0ULL;
L_1e1638:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_1e1650:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3744));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    goto L_1e15fc;
L_1e1660:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1e1634;
    cpu->regs[30] = PB_BASE + 0x1e1670ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1e1638;
L_1e1678:
    cpu->regs[0] = 4294967295ULL;
    goto L_1e1638;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e1794;
L_1e16ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e17d0;
    PB_LDRW(cpu->regs[24], (cpu->regs[22] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1e16c0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e17c4;
    PB_LDRW(cpu->regs[21], (cpu->regs[22] + 96));
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1e17d0;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = 1ULL;
    goto L_1e16f8;
L_1e16e4:
    FLAG_CMP(cpu->regs[25], cpu->regs[20]);
    if (FLAG_EQ) goto L_1e1774;
L_1e16ec:
    PB_LDRW(cpu->regs[24], (cpu->regs[22] + 16));
    PB_STR((cpu->regs[23] + (cpu->regs[20] << 3)), cpu->regs[19]);
    cpu->regs[20] = cpu->regs[20] + 1ULL;
L_1e16f8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e1700ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1e1240ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e16e4;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 32));
    PB_STRW((cpu->regs[22] + 16), cpu->regs[24]);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e1718ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e1738;
    goto L_1e179c;
L_1e1724:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[23] + cpu->regs[1]));
    PB_STR((cpu->regs[0] + cpu->regs[1]), cpu->regs[2]);
L_1e1738:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[20], cpu->regs[21]);
    if (FLAG_GT) goto L_1e1724;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e174cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e175c:
    PB_STRW((cpu->regs[22] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1e1774:
    cpu->regs[25] = cpu->regs[25] << 1;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[25] << 3;
    cpu->regs[30] = PB_BASE + 0x1e1784ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e179c;
    cpu->regs[23] = cpu->regs[0];
    goto L_1e16ec;
L_1e1794:
    cpu->regs[30] = PB_BASE + 0x1e1798ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e16ac;
L_1e179c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e17a4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[22] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e17b0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_1e175c;
L_1e17c4:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[22] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e17d0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1e17d0:
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 144));
    cpu->regs[24] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e175c;
L_1e17e0:
    cpu->regs[1] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1e17fcULL; PB_CALL(13, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_1e1814;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])==0) goto L_1e1814;
L_1e180c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1e1814:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1096ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e182cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1e180c;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e1998;
L_1e186c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e19ac;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1e1880ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e19a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e19ac;
    cpu->regs[24] = 1ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = 0ULL;
L_1e189c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e18a4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1e2540ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e18e4;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((cpu->regs[22])!=0) goto L_1e18fc;
L_1e18b4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e18bcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[23] = 0ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e18cc:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1e18e4:
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_EQ) goto L_1e1954;
L_1e18ec:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[22] << 3)), cpu->regs[21]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_1e189c;
L_1e18fc:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1e18b4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e1910ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e1974;
L_1e1918:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_GT) goto L_1e193c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e192cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e18cc;
L_1e193c:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_1e1918;
L_1e1954:
    cpu->regs[24] = cpu->regs[24] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24] << 3;
    cpu->regs[30] = PB_BASE + 0x1e1964ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e1974;
    cpu->regs[20] = cpu->regs[0];
    goto L_1e18ec;
L_1e1974:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e197cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e1988ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e18cc;
L_1e1998:
    cpu->regs[30] = PB_BASE + 0x1e199cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e186c;
L_1e19a0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e19acULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1e19ac:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[23] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e18cc;
    /* nop */
L_1e19c0:
    SP = SP - 384ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3080));
    PB_STR((SP + 288), cpu->regs[29]); PB_STR((SP + 288) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 288ULL;
    PB_STR((SP + 112), cpu->regs[0]);
    PB_STR((SP + 304), cpu->regs[19]); PB_STR((SP + 304) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[5];
    PB_STR((SP + 320), cpu->regs[21]); PB_STR((SP + 320) + 8, cpu->regs[22]);
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    PB_STR((SP + 336), cpu->regs[23]); PB_STR((SP + 336) + 8, cpu->regs[24]);
    PB_STR((SP + 352), cpu->regs[25]); PB_STR((SP + 352) + 8, cpu->regs[26]);
    PB_STR((SP + 368), cpu->regs[27]); PB_STR((SP + 368) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[8] + 0));
    PB_STR((SP + 280), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 104), cpu->regs[3]);
    PB_STR((SP + 128), cpu->regs[7]);
    PB_STRW((SP + 136), cpu->regs[4]);
    PB_LDR(cpu->regs[27], (SP + 384));
    FLAG_CMP(cpu->regs[5], cpu->regs[22]);
    if (FLAG_EQ) goto L_1e1dcc;
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[6];
    if ((cpu->regs[6])==0) goto L_1e1a44;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    FLAG_CMP((cpu->regs[0]) & (536870912ULL), 0);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[6], cpu->regs[22]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1e1f84;
L_1e1a44:
    if ((cpu->regs[19])==0) goto L_1e1e50;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1e1a58;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1e1a58:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1e1a68;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_1e1a68:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2728));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1e1a7cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11e0a4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e219c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1e202c;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1e1a98ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_STR((SP + 40), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1e2018;
L_1e1aa0:
    do { int32_t _s=0; tlb_read(tlb,(SP + 136),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    PB_STR((SP + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1e1aacULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e1f74;
    FLAG_CMP(cpu->regs[27], cpu->regs[22]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[27] = (FLAG_NE) ? cpu->regs[27] : 0ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1e1ad0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe0f0cULL);
    PB_STR((SP + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1e1e30;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[22]); } else { FLAG_CMP(0, 0); }
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    PB_STRW((SP + 140), cpu->regs[0]);
    if (FLAG_EQ) goto L_1e1b10;
    PB_LDR(cpu->regs[2], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e1b00ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x227684ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e1e30;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1e2058;
L_1e1b10:
    cpu->regs[0] = cpu->regs[23] + 3896ULL; FLAG_CMP(cpu->regs[0], 0);
    PB_STR((SP + 120), cpu->regs[0]);
    if (FLAG_EQ) goto L_1e1e30;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[7] = 44584ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    PB_STR((SP + 48), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x1e1b40ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1e2828ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2048;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 3896));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[23] + 3896), cpu->regs[2]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1e1b64;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1e1e0c;
L_1e1b64:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_1e1e18;
    PB_STR((SP + 24), 0ULL);
L_1e1b74:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    PB_LDR(cpu->regs[1], (SP + 24));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GE) goto L_1e2118;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[26], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_1e20f4;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 16));
    FLAG_CMP(cpu->regs[0], 5ULL);
    if (FLAG_NE) goto L_1e20f4;
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1e1bb8;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
L_1e1bb8:
    PB_LDR(cpu->regs[28], (cpu->regs[26] + 24)); PB_LDR(cpu->regs[0], (cpu->regs[26] + 24) + 8);
    PB_LDR(cpu->regs[6], (cpu->regs[26] + 56));
    PB_LDR(cpu->regs[5], (cpu->regs[26] + 40)); PB_LDR(cpu->regs[4], (cpu->regs[26] + 40) + 8);
    PB_STR((SP + 72), cpu->regs[6]);
    PB_LDR(cpu->regs[3], (cpu->regs[28] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1e20cc;
    cpu->regs[1] = 1ULL;
    PB_STRW((SP + 56), cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_1e1ee8;
L_1e1be4:
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 64), cpu->regs[0]);
    FLAG_CMP(cpu->regs[4], cpu->regs[22]);
    if (FLAG_NE) goto L_1e1f30;
L_1e1bf4:
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[24];
    PB_STR((SP + 80), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1e1c04ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x136260ULL);
    PB_LDR(cpu->regs[2], (SP + 80));
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e1f0c;
    PB_LDR(cpu->regs[0], (SP + 72));
    PB_STR((SP + 80), cpu->regs[2]);
    PB_STRW((SP + 88), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1e1c24ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 80));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_LDRW(cpu->regs[1], (SP + 88));
    if (FLAG_EQ) goto L_1e1fac;
L_1e1c38:
    PB_LDRW(cpu->regs[0], (SP + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    PB_LDRW(cpu->regs[0], (SP + 64));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1e1ec0;
    PB_LDR(cpu->regs[0], (SP + 96));
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[3]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1e1ec0;
L_1e1c60:
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + 3752ULL;
    cpu->regs[30] = PB_BASE + 0x1e1c70ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e1e3c;
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + 3288ULL;
    cpu->regs[30] = PB_BASE + 0x1e1c84ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e1d78;
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + 1944ULL;
    cpu->regs[30] = PB_BASE + 0x1e1c98ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e21b4;
L_1e1c9c:
    PB_LDR(cpu->regs[0], (SP + 112));
    FLAG_CMP(cpu->regs[27], 0ULL);
    cpu->regs[5] = 36048ULL;
    cpu->regs[2] = (FLAG_NE) ? 1 : 0;
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[1] = cpu->regs[0] + cpu->regs[5];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e1cc0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1e2828ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e23a8;
    cpu->regs[30] = PB_BASE + 0x1e1cccULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11d7acULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e1fd8;
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 25312ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e1ce8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1e2828ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e222c;
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_STR((SP + 0), 0ULL);
    PB_LDR(cpu->regs[3], (SP + 104));
    cpu->regs[7] = cpu->regs[27];
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2760));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x1e1d18ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1987c8ULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1e1d30;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1e2220;
L_1e1d30:
    if ((cpu->regs[23])==0) goto L_1e1ff0;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e1d40ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1e1d58;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1e200c;
L_1e1d58:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1e1d6c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1e2000;
L_1e1d6c:
    if ((cpu->regs[24])==0) goto L_1e1e34;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1e2390;
L_1e1d78:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1e1fa4;
L_1e1d84:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
L_1e1d8c:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1e1d94ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x1e1d9cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e1da4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1e1dacULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e1dc0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1e207c;
L_1e1dc0:
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e1dccULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdce4cULL);
L_1e1dcc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 280));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e1ee4;
    PB_LDR(cpu->regs[29], (SP + 288)); PB_LDR(cpu->regs[30], (SP + 288) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 304)); PB_LDR(cpu->regs[20], (SP + 304) + 8);
    PB_LDR(cpu->regs[21], (SP + 320)); PB_LDR(cpu->regs[22], (SP + 320) + 8);
    PB_LDR(cpu->regs[23], (SP + 336)); PB_LDR(cpu->regs[24], (SP + 336) + 8);
    PB_LDR(cpu->regs[25], (SP + 352)); PB_LDR(cpu->regs[26], (SP + 352) + 8);
    PB_LDR(cpu->regs[27], (SP + 368)); PB_LDR(cpu->regs[28], (SP + 368) + 8);
    SP = SP + 384ULL;
    return;
L_1e1e0c:
    cpu->regs[30] = PB_BASE + 0x1e1e10ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1e1e10:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 3896));
    if ((cpu->regs[2])!=0) goto L_1e1b64;
L_1e1e18:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 1760ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e1e30ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1e1e30:
    cpu->regs[26] = 0ULL;
L_1e1e34:
    cpu->regs[20] = 0ULL;
    goto L_1e1d8c;
L_1e1e3c:
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e1e4cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    goto L_1e1d8c;
L_1e1e50:
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[30] = PB_BASE + 0x1e1e58ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1e2680ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_1e1f9c;
    if (FLAG_EQ) goto L_1e2060;
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 32));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_1e1f68;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[0] = cpu->regs[1] + 40ULL;
    cpu->regs[1] = cpu->regs[1] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
L_1e1e88:
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_LE) goto L_1e1ea8;
    cpu->regs[5] = cpu->regs[3] - 3ULL;
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1e1ea0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x12b440ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(46ULL)));
    if (FLAG_EQ) goto L_1e2088;
L_1e1ea8:
    PB_LDR(cpu->regs[0], (SP + 104));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1e1fc8;
    PB_LDR(cpu->regs[19], (SP + 104));
    goto L_1e1a58;
L_1e1ec0:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e1ed4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1e1f54;
L_1e1ed4:
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    goto L_1e1b74;
L_1e1ee4:
    cpu->regs[30] = PB_BASE + 0x1e1ee8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e1ee8:
    cpu->regs[1] = cpu->regs[21];
    PB_STR((SP + 64), cpu->regs[2]);
    PB_STR((SP + 80), cpu->regs[5]); PB_STR((SP + 80) + 8, cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1e1ef8ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1e3000ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_STRW((SP + 56), cpu->regs[0]);
    PB_LDR(cpu->regs[2], (SP + 64));
    PB_LDR(cpu->regs[5], (SP + 80)); PB_LDR(cpu->regs[4], (SP + 80) + 8);
    if (FLAG_NE) goto L_1e1be4;
L_1e1f0c:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e1e30;
L_1e1f14:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1e1e30;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e1f2cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e1e34;
L_1e1f30:
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[19];
    PB_STR((SP + 80), cpu->regs[2]); PB_STR((SP + 80) + 8, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x1e1f40ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1e3000ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_STRW((SP + 64), cpu->regs[0]);
    PB_LDR(cpu->regs[2], (SP + 80)); PB_LDR(cpu->regs[5], (SP + 80) + 8);
    if (FLAG_NE) goto L_1e1bf4;
    goto L_1e1f0c;
L_1e1f54:
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1e1f60ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 56));
    goto L_1e1ed4;
L_1e1f68:
    PB_LDR(cpu->regs[0], (SP + 104));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
    goto L_1e1e88;
L_1e1f74:
    cpu->regs[26] = 0ULL;
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 32), 0ULL);
    goto L_1e1d8c;
L_1e1f84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 1720ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e1f9cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1e1f9c:
    cpu->regs[19] = 0ULL;
    goto L_1e1dcc;
L_1e1fa4:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_1e1d84;
L_1e1fac:
    PB_STR((SP + 72), cpu->regs[2]);
    PB_STRW((SP + 80), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1e1fb8ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDRW(cpu->regs[1], (SP + 80));
    if ((cpu->regs[0])==0) goto L_1e1c38;
    goto L_1e1f0c;
L_1e1fc8:
    PB_LDR(cpu->regs[1], (SP + 104));
    PB_LDR(cpu->regs[19], (SP + 104));
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_1e1a58;
L_1e1fd8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2104ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e1ff0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1e1ff0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e1ffcULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_1e1d8c;
L_1e2000:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e2008ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e1d6c;
L_1e200c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e2014ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e1d58;
L_1e2018:
    cpu->regs[26] = 0ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 32), 0ULL);
    goto L_1e1d8c;
L_1e202c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e2034ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x12cb88ULL);
    if ((cpu->regs[0])==0) goto L_1e219c;
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 8));
    PB_STR((SP + 40), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    goto L_1e1aa0;
L_1e2048:
    cpu->regs[30] = PB_BASE + 0x1e204cULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e1e10;
    cpu->regs[26] = 0ULL;
    goto L_1e1e34;
L_1e2058:
    cpu->regs[26] = 0ULL;
    goto L_1e1d78;
L_1e2060:
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = cpu->regs[0] + 400ULL;
    cpu->regs[30] = PB_BASE + 0x1e206cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_1e1a58;
L_1e2074:
    cpu->regs[19] = 0ULL;
    goto L_1e1dcc;
L_1e207c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2084ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e1dc0;
L_1e2088:
    cpu->regs[2] = cpu->regs[3] - 2ULL;
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1e2094ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x12b440ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(112ULL)));
    if (FLAG_NE) goto L_1e1ea8;
    cpu->regs[2] = cpu->regs[3] - 1ULL;
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1e20a8ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x12b440ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(121ULL)));
    if (FLAG_NE) goto L_1e1ea8;
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e20c0ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x134b80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_1e1a58;
    goto L_1e2074;
L_1e20cc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    cpu->regs[1] = cpu->regs[1] + 1848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e20e8ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1e1f14;
    goto L_1e1e30;
L_1e20f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    PB_LDR(cpu->regs[2], (SP + 24));
    cpu->regs[1] = cpu->regs[1] + 1800ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e2114ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1e1e34;
L_1e2118:
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[6] = 41488ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[6];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e2130ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x1e2828ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e216c;
    cpu->regs[30] = PB_BASE + 0x1e213cULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1e1e30;
    PB_LDR(cpu->regs[0], (SP + 120));
    PB_LDR(cpu->regs[28], (cpu->regs[0] + 16));
    if ((cpu->regs[28])==0) goto L_1e1e30;
L_1e214c:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1e2164;
L_1e2158:
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2760));
    goto L_1e1c60;
L_1e2164:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_1e2158;
L_1e216c:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1e24fc;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 3912));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[23] + 3912), cpu->regs[28]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1e214c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e214c;
    cpu->regs[30] = PB_BASE + 0x1e2198ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e214c;
L_1e219c:
    cpu->regs[26] = 0ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 32), 0ULL); PB_STR((SP + 32) + 8, cpu->regs[21]);
    cpu->regs[21] = 0ULL;
    goto L_1e1d8c;
L_1e21b4:
    PB_LDRW(cpu->regs[0], (SP + 140));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e22a4;
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + 1952ULL;
    cpu->regs[30] = PB_BASE + 0x1e21ccULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2250;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + 2936ULL;
    cpu->regs[30] = PB_BASE + 0x1e21e0ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e1c9c;
L_1e21e4:
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x1e21f4ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e1c9c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2016ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e221cULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1e1d8c;
L_1e2220:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1e2228ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e1d30;
L_1e222c:
    cpu->regs[30] = PB_BASE + 0x1e2230ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1e1ff0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e224cULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1e1ff0;
L_1e2250:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[22]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1e22e8;
L_1e225c:
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1e226cULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[28] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e2284ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x227684ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1e2290ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xdce4cULL);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1e1d78;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_1e1c9c;
    cpu->regs[20] = 0ULL;
    goto L_1e1d8c;
L_1e22a4:
    PB_LDR(cpu->regs[1], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3664));
    cpu->regs[30] = PB_BASE + 0x1e22b8ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e1e34;
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + 1952ULL;
    cpu->regs[30] = PB_BASE + 0x1e22ccULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e225c;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[1] + 2936ULL;
    cpu->regs[30] = PB_BASE + 0x1e22e0ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e21e4;
    goto L_1e225c;
L_1e22e8:
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[4] = 52440ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e2300ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x1e2828ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2338;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_1e2350;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 3904));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[23] + 3904), cpu->regs[20]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1e225c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e225c;
    cpu->regs[30] = PB_BASE + 0x1e2334ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e225c;
L_1e2338:
    cpu->regs[30] = PB_BASE + 0x1e233cULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1e1e34;
    PB_LDR(cpu->regs[0], (SP + 120));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    if ((cpu->regs[20])!=0) goto L_1e225c;
    goto L_1e1e34;
L_1e2350:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1960ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e236cULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e1e34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1e1e34;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e238cULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e1d8c;
L_1e2390:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1e1d78;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1e23a4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e1d78;
L_1e23a8:
    cpu->regs[30] = PB_BASE + 0x1e23acULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e1e34;
    PB_LDRW(cpu->regs[3], (SP + 136));
    cpu->regs[27] = SP + 152ULL;
    cpu->regs[1] = 128ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = cpu->regs[2] + 2072ULL;
    PB_STR((SP + 144), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1e23d4ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[3] = 30760ULL;
    PB_LDR(cpu->regs[24], (SP + 48));
    cpu->regs[1] = cpu->regs[24] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1e23e8ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e24bc;
    cpu->regs[2] = 57792ULL;
    cpu->regs[1] = SP + 144ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1e2400ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1e24d4;
    PB_LDR(cpu->regs[0], (SP + 104));
    cpu->regs[2] = 1ULL;
    PB_LDR(cpu->regs[1], (SP + 144));
    cpu->regs[30] = PB_BASE + 0x1e2418ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    PB_LDR(cpu->regs[1], (SP + 144));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e24f4;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1e2428ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x1e3340ULL);
    PB_LDR(cpu->regs[1], (SP + 144));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e24f4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1e243cULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    PB_LDR(cpu->regs[1], (SP + 144));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e24f4;
    cpu->regs[0] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[0] + 1656ULL;
    cpu->regs[30] = PB_BASE + 0x1e2450ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x1e3340ULL);
    PB_LDR(cpu->regs[1], (SP + 144));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e24f4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1e2464ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    PB_LDR(cpu->regs[1], (SP + 144));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e24f4;
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x1e2478ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x1e3340ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e24f4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e2498;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1e2498;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e2498ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1e2498:
    PB_LDR(cpu->regs[1], (SP + 128));
    PB_LDR(cpu->regs[0], (SP + 144));
    if ((cpu->regs[1])!=0) goto L_1e24bc;
    PB_LDR(cpu->regs[1], (SP + 104));
    cpu->regs[5] = 0ULL;
    PB_LDRW(cpu->regs[2], (SP + 136));
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1e24bcULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x7c620ULL);
L_1e24bc:
    PB_LDR(cpu->regs[0], (SP + 144));
    cpu->regs[30] = PB_BASE + 0x1e24c4ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1e24ccULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[30] = PB_BASE + 0x1e24d0ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1e1d78;
L_1e24d4:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2192));
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = 16ULL;
    cpu->regs[0] = cpu->regs[0] + 2080ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1e24f4ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x7b510ULL);
L_1e24f4:
    cpu->regs[23] = cpu->regs[20];
    goto L_1e24bc;
L_1e24fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1888ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e2518ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e1e30;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1e1e30;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e2538ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e1e34;
    /* nop */
L_1e2540:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e2660;
L_1e2568:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2650;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1e2580ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x1e1324ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e262c;
L_1e2588:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e2668;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e259cULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x1e1324ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e25cc;
L_1e25a4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_1e25a8:
    cpu->regs[3] = 0ULL;
L_1e25ac:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e25b8:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e25cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e25d4ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x1a5b60ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e25a4;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 11ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1e25ecULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e25a4;
L_1e25f0:
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2604ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x1a5cccULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1e25ac;
    cpu->regs[30] = PB_BASE + 0x1e2610ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1e25a8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e25b8;
L_1e262c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e2634ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x1a5b60ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e2588;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1e2648ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1e2588;
    goto L_1e25f0;
L_1e2650:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e25b8;
L_1e2660:
    cpu->regs[30] = PB_BASE + 0x1e2664ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e2568;
L_1e2668:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e25b8;
    /* nop */
}
