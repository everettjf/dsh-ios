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

void ft_PyInit_errno(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[0] + 272ULL;
    cpu->regs[0] = cpu->regs[0] + 160ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x20339cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18fc40ULL);
    if ((cpu->regs[0])==0) goto L_204518;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x2033acULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20549c;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1408ULL;
    cpu->regs[30] = PB_BASE + 0x2033c8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_20547c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1424ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 19ULL;
    cpu->regs[30] = PB_BASE + 0x2033e4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2054f4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1432ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 50ULL;
    cpu->regs[30] = PB_BASE + 0x203404ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2054d4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1440ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 113ULL;
    cpu->regs[30] = PB_BASE + 0x203424ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204e9c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1456ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 42ULL;
    cpu->regs[30] = PB_BASE + 0x203444ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204e7c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1464ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 117ULL;
    cpu->regs[30] = PB_BASE + 0x203464ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2055f4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1472ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 45ULL;
    cpu->regs[30] = PB_BASE + 0x203484ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2055d4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1488ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 51ULL;
    cpu->regs[30] = PB_BASE + 0x2034a4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20519c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1496ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 61ULL;
    cpu->regs[30] = PB_BASE + 0x2034c4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20517c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1504ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 15ULL;
    cpu->regs[30] = PB_BASE + 0x2034e4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205594;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1512ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 38ULL;
    cpu->regs[30] = PB_BASE + 0x203504ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205574;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1520ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 32ULL;
    cpu->regs[30] = PB_BASE + 0x203524ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204b9c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1528ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x203544ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204b7c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1536ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 75ULL;
    cpu->regs[30] = PB_BASE + 0x203564ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2057f4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1552ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 68ULL;
    cpu->regs[30] = PB_BASE + 0x203584ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2057d4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1560ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x2035a4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20531c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1568ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 87ULL;
    cpu->regs[30] = PB_BASE + 0x2035c4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2052fc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1576ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 39ULL;
    cpu->regs[30] = PB_BASE + 0x2035e4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205734;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1592ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 105ULL;
    cpu->regs[30] = PB_BASE + 0x203604ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205714;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1600ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 71ULL;
    cpu->regs[30] = PB_BASE + 0x203624ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204d1c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1608ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 66ULL;
    cpu->regs[30] = PB_BASE + 0x203644ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204cfc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1616ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 119ULL;
    cpu->regs[30] = PB_BASE + 0x203664ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205794;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1624ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x203684ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205774;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1632ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 40ULL;
    cpu->regs[30] = PB_BASE + 0x2036a4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20501c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1640ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 18ULL;
    cpu->regs[30] = PB_BASE + 0x2036c4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204ffc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1648ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x2036e4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2056d4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1656ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x203704ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2056b4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1664ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 90ULL;
    cpu->regs[30] = PB_BASE + 0x203724ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204a1c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1680ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 97ULL;
    cpu->regs[30] = PB_BASE + 0x203744ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2049fc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1696ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 53ULL;
    cpu->regs[30] = PB_BASE + 0x203764ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205bf4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1704ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 112ULL;
    cpu->regs[30] = PB_BASE + 0x203784ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205bd4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1720ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 96ULL;
    cpu->regs[30] = PB_BASE + 0x2037a4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2053dc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1736ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 92ULL;
    cpu->regs[30] = PB_BASE + 0x2037c4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2053bc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1752ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x2037e4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205a74;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1760ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x203804ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205a54;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1776ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 77ULL;
    cpu->regs[30] = PB_BASE + 0x203824ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204ddc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1784ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 73ULL;
    cpu->regs[30] = PB_BASE + 0x203844ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204dbc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1792ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 106ULL;
    cpu->regs[30] = PB_BASE + 0x203864ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205b34;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1800ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 55ULL;
    cpu->regs[30] = PB_BASE + 0x203884ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205b14;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1808ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 108ULL;
    cpu->regs[30] = PB_BASE + 0x2038a4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2050dc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1824ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 44ULL;
    cpu->regs[30] = PB_BASE + 0x2038c4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2050bc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1832ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 80ULL;
    cpu->regs[30] = PB_BASE + 0x2038e4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2059b4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1840ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 64ULL;
    cpu->regs[30] = PB_BASE + 0x203904ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205994;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1848ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 52ULL;
    cpu->regs[30] = PB_BASE + 0x203924ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204adc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1856ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x203944ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204abc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1864ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 72ULL;
    cpu->regs[30] = PB_BASE + 0x203964ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205b94;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1880ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x203984ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205b74;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1888ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 49ULL;
    cpu->regs[30] = PB_BASE + 0x2039a4ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20525c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1896ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 91ULL;
    cpu->regs[30] = PB_BASE + 0x2039c4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20523c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1912ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 28ULL;
    cpu->regs[30] = PB_BASE + 0x2039e4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205a14;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1920ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x203a04ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2059f4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1928ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 114ULL;
    cpu->regs[30] = PB_BASE + 0x203a24ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204c5c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1944ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 100ULL;
    cpu->regs[30] = PB_BASE + 0x203a44ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204c3c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1960ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 118ULL;
    cpu->regs[30] = PB_BASE + 0x203a64ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205ad4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1968ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 13ULL;
    cpu->regs[30] = PB_BASE + 0x203a84ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205ab4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1976ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x203aa4ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204f5c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1984ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 84ULL;
    cpu->regs[30] = PB_BASE + 0x203ac4ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204f3c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1992ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 20ULL;
    cpu->regs[30] = PB_BASE + 0x203ae4ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205954;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 76ULL;
    cpu->regs[30] = PB_BASE + 0x203b04ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205934;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2016ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x203b24ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20495c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2024ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 33ULL;
    cpu->regs[30] = PB_BASE + 0x203b44ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20493c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2032ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 54ULL;
    cpu->regs[30] = PB_BASE + 0x203b64ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2063f4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2040ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 111ULL;
    cpu->regs[30] = PB_BASE + 0x203b84ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2063d4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2056ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 21ULL;
    cpu->regs[30] = PB_BASE + 0x203ba4ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20543c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2064ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 93ULL;
    cpu->regs[30] = PB_BASE + 0x203bc4ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20541c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2080ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 30ULL;
    cpu->regs[30] = PB_BASE + 0x203be4ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2060f4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2088ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 99ULL;
    cpu->regs[30] = PB_BASE + 0x203c04ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2060d4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2104ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 43ULL;
    cpu->regs[30] = PB_BASE + 0x203c24ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204e3c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2112ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 70ULL;
    cpu->regs[30] = PB_BASE + 0x203c44ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204e1c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2120ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 69ULL;
    cpu->regs[30] = PB_BASE + 0x203c64ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206274;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2128ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 121ULL;
    cpu->regs[30] = PB_BASE + 0x203c84ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206254;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2144ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 47ULL;
    cpu->regs[30] = PB_BASE + 0x203ca4ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20513c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2152ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 74ULL;
    cpu->regs[30] = PB_BASE + 0x203cc4ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20511c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2160ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 23ULL;
    cpu->regs[30] = PB_BASE + 0x203ce4ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205f74;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2168ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 82ULL;
    cpu->regs[30] = PB_BASE + 0x203d04ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205f54;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2176ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 29ULL;
    cpu->regs[30] = PB_BASE + 0x203d24ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204b3c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2184ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 67ULL;
    cpu->regs[30] = PB_BASE + 0x203d44ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204b1c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2192ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 102ULL;
    cpu->regs[30] = PB_BASE + 0x203d64ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206334;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2208ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 110ULL;
    cpu->regs[30] = PB_BASE + 0x203d84ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206314;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2224ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x203da4ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2052bc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2232ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x203dc4ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20529c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2240ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 122ULL;
    cpu->regs[30] = PB_BASE + 0x203de4ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206034;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2248ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 60ULL;
    cpu->regs[30] = PB_BASE + 0x203e04ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206014;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2256ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 57ULL;
    cpu->regs[30] = PB_BASE + 0x203e24ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204cbc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2264ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 56ULL;
    cpu->regs[30] = PB_BASE + 0x203e44ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204c9c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2272ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 79ULL;
    cpu->regs[30] = PB_BASE + 0x203e64ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2061b4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2280ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 14ULL;
    cpu->regs[30] = PB_BASE + 0x203e84ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206194;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2288ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 27ULL;
    cpu->regs[30] = PB_BASE + 0x203ea4ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204fbc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2296ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x203ec4ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204f9c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2304ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 107ULL;
    cpu->regs[30] = PB_BASE + 0x203ee4ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205eb4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2320ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 89ULL;
    cpu->regs[30] = PB_BASE + 0x203f04ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205e94;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2336ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 81ULL;
    cpu->regs[30] = PB_BASE + 0x203f24ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2049bc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2344ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 37ULL;
    cpu->regs[30] = PB_BASE + 0x203f44ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20499c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2352ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 120ULL;
    cpu->regs[30] = PB_BASE + 0x203f64ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206394;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2360ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 103ULL;
    cpu->regs[30] = PB_BASE + 0x203f84ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206374;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2376ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 101ULL;
    cpu->regs[30] = PB_BASE + 0x203fa4ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20537c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2392ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 116ULL;
    cpu->regs[30] = PB_BASE + 0x203fc4ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20535c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2400ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 63ULL;
    cpu->regs[30] = PB_BASE + 0x203fe4ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206094;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2408ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x204004ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206074;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2416ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 88ULL;
    cpu->regs[30] = PB_BASE + 0x204024ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204d7c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2432ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 86ULL;
    cpu->regs[30] = PB_BASE + 0x204044ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204d5c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2448ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 31ULL;
    cpu->regs[30] = PB_BASE + 0x204064ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206214;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2456ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 34ULL;
    cpu->regs[30] = PB_BASE + 0x204084ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2061f4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2464ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 83ULL;
    cpu->regs[30] = PB_BASE + 0x2040a4ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20507c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2480ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 46ULL;
    cpu->regs[30] = PB_BASE + 0x2040c4ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20505c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2488ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 104ULL;
    cpu->regs[30] = PB_BASE + 0x2040e4ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205f14;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2504ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 98ULL;
    cpu->regs[30] = PB_BASE + 0x204104ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205ef4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2520ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 95ULL;
    cpu->regs[30] = PB_BASE + 0x204124ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204a7c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2536ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 78ULL;
    cpu->regs[30] = PB_BASE + 0x204144ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204a5c;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2544ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x204164ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2062d4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2552ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 36ULL;
    cpu->regs[30] = PB_BASE + 0x204184ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2062b4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2568ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 25ULL;
    cpu->regs[30] = PB_BASE + 0x2041a4ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2051fc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2576ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 85ULL;
    cpu->regs[30] = PB_BASE + 0x2041c4ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2051dc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2592ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 94ULL;
    cpu->regs[30] = PB_BASE + 0x2041e4ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205fd4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2608ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 62ULL;
    cpu->regs[30] = PB_BASE + 0x204204ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205fb4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2616ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 59ULL;
    cpu->regs[30] = PB_BASE + 0x204224ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204bfc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 35ULL;
    cpu->regs[30] = PB_BASE + 0x204244ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204bdc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2640ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 109ULL;
    cpu->regs[30] = PB_BASE + 0x204264ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206154;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2656ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 24ULL;
    cpu->regs[30] = PB_BASE + 0x204284ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206134;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2664ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 26ULL;
    cpu->regs[30] = PB_BASE + 0x2042a4ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204efc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2672ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 115ULL;
    cpu->regs[30] = PB_BASE + 0x2042c4ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204edc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2688ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 6ULL;
    cpu->regs[30] = PB_BASE + 0x2042e4ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205e54;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2696ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 65ULL;
    cpu->regs[30] = PB_BASE + 0x204304ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_205e34;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2704ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 123ULL;
    cpu->regs[30] = PB_BASE + 0x204324ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2048fc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2720ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 124ULL;
    cpu->regs[30] = PB_BASE + 0x204344ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2048dc;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 125ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = PB_BASE + 0x296000ULL;
    cpu->regs[2] = cpu->regs[23] + 2736ULL;
    cpu->regs[30] = PB_BASE + 0x204368ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2047e8;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2752ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 126ULL;
    cpu->regs[30] = PB_BASE + 0x204388ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2047c4;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2760ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x2043a8ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2046fc;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2776ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 128ULL;
    cpu->regs[30] = PB_BASE + 0x2043c8ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2046d8;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2792ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 129ULL;
    cpu->regs[30] = PB_BASE + 0x2043e8ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204770;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = PB_BASE + 0x296000ULL;
    cpu->regs[22] = cpu->regs[22] + 2808ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 130ULL;
    cpu->regs[30] = PB_BASE + 0x204410ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204748;
    cpu->regs[21] = PB_BASE + 0x296000ULL;
    cpu->regs[21] = cpu->regs[21] + 2824ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 131ULL;
    cpu->regs[30] = PB_BASE + 0x204434ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204680;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2840ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 132ULL;
    cpu->regs[30] = PB_BASE + 0x204454ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204658;
    cpu->regs[2] = cpu->regs[23] + 2736ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 125ULL;
    cpu->regs[30] = PB_BASE + 0x204470ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204548;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2848ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 95ULL;
    cpu->regs[30] = PB_BASE + 0x204490ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_204520;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 130ULL;
    cpu->regs[30] = PB_BASE + 0x2044acULL; PB_CALL(139, cpu, tlb, PB_BASE + 0x206f28ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2045d0;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 131ULL;
    cpu->regs[30] = PB_BASE + 0x2044c8ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x206f28ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2044fc;
    if (((cpu->regs[1] >> 31) & 1)) goto L_2044e4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2054c8;
L_2044e4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_2044f4:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_2044fc:
    if (((cpu->regs[1] >> 31) & 1)) goto L_204628;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20463c;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_204518:
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204520:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204570;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204584;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204548:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2045a0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2045b4;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204570:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204584:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20458cULL; PB_CALL(141, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2045a0:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2045b4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2045bcULL; PB_CALL(142, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2045d0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2045f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20460c;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2045f8:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_20460c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204614ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204628:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_20463c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204644ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204658:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2046a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2046bc;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204680:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204834;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204848;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2046a8:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2046bc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2046c4ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2046d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204720;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204730;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2046fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20488c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20489c;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204720:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204730:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204738ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204748:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204794;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2047a8;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204770:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204864;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204874;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204794:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2047a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2047b0ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_2047c4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20480c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20481c;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2047e8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2048b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2048c4;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20480c:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20481c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204824ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204834:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204848:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204850ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_2044f4;
L_204864:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204874:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20487cULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20488c:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20489c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2048a4ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2048b4:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2048c4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2048ccULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2048dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20491c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204928;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2048fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206434;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206440;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20491c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204928:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204930ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20493c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20497c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204988;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20495c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205c34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205c40;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20497c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204988:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204990ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20499c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2049dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2049e8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2049bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206634;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206640;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2049dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2049e8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2049f0ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2049fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204a3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204a48;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204a1c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205834;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205840;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204a3c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204a48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204a50ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204a5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204a9c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204aa8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204a7c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206534;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206540;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204a9c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204aa8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204ab0ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204abc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204afc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204b08;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204adc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205d34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205d40;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204afc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204b08:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204b10ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204b1c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204b5c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204b68;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204b3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206734;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206740;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204b5c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204b68:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204b70ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204b7c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204bbc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204bc8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204b9c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205634;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205640;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204bbc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204bc8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204bd0ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204bdc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204c1c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204c28;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204bfc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2064b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2064c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204c1c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204c28:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204c30ULL; PB_CALL(161, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204c3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204c7c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204c88;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204c5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205cb4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205cc0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204c7c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204c88:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204c90ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204c9c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204cdc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204ce8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204cbc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2066b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2066c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204cdc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204ce8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204cf0ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204cfc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204d3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204d48;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204d1c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2058b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2058c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204d3c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204d48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204d50ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204d5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204d9c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204da8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204d7c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2065b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2065c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204d9c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204da8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204db0ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204dbc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204dfc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204e08;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204ddc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205db4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205dc0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204dfc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204e08:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204e10ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204e1c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204e5c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204e68;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204e3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2067b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2067c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204e5c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204e68:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204e70ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204e7c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204ebc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204ec8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204e9c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205534;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205540;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204ebc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204ec8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204ed0ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204edc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204f1c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204f28;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204efc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206474;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206480;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204f1c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204f28:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204f30ULL; PB_CALL(169, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204f3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204f7c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204f88;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204f5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205c74;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205c80;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204f7c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204f88:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204f90ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204f9c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_204fdc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_204fe8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204fbc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206674;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206680;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204fdc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_204fe8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x204ff0ULL; PB_CALL(171, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_204ffc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20503c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205048;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20501c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205874;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205880;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20503c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205048:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205050ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20505c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20509c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2050a8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20507c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206574;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206580;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20509c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2050a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2050b0ULL; PB_CALL(173, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2050bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2050fc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205108;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2050dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205d74;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205d80;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2050fc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205108:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205110ULL; PB_CALL(174, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20511c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20515c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205168;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20513c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206774;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206780;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20515c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205168:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205170ULL; PB_CALL(175, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20517c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2051bc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2051c8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20519c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205674;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205680;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2051bc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2051c8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2051d0ULL; PB_CALL(176, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2051dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20521c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205228;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2051fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2064f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206500;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20521c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205228:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205230ULL; PB_CALL(177, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20523c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20527c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205288;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20525c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205cf4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205d00;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20527c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205288:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205290ULL; PB_CALL(178, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20529c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2052dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2052e8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2052bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2066f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206700;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2052dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2052e8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2052f0ULL; PB_CALL(179, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2052fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20533c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205348;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20531c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2058f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205900;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20533c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205348:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205350ULL; PB_CALL(180, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20535c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20539c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2053a8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20537c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2065f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206600;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20539c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2053a8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2053b0ULL; PB_CALL(181, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2053bc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2053fc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205408;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2053dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205df4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205e00;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2053fc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205408:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205410ULL; PB_CALL(182, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20541c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20545c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205468;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20543c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2067f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206800;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20545c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205468:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205470ULL; PB_CALL(183, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_20547c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2054a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2054b4;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_20549c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2054a8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2054b4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2054bcULL; PB_CALL(184, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2054c8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2054d0ULL; PB_CALL(185, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2044e4;
L_2054d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205514;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205520;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2054f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205554;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205560;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205514:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205520:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205528ULL; PB_CALL(186, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205534:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205540:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205548ULL; PB_CALL(187, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205554:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205560:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205568ULL; PB_CALL(188, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205574:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2055b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2055c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205594:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205654;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205660;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2055b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2055c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2055c8ULL; PB_CALL(189, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2055d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205614;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205620;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2055f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205694;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2056a0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205614:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205620:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205628ULL; PB_CALL(190, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205634:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205640:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205648ULL; PB_CALL(191, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205654:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205660:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205668ULL; PB_CALL(192, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205674:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205680:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205688ULL; PB_CALL(193, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205694:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2056a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2056a8ULL; PB_CALL(194, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2056b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2056f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205700;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2056d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205854;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205860;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2056f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205700:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205708ULL; PB_CALL(195, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205714:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205754;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205760;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205734:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2058d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2058e0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205754:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205760:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205768ULL; PB_CALL(196, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205774:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2057b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2057c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205794:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205894;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2058a0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2057b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2057c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2057c8ULL; PB_CALL(197, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2057d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205814;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205820;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2057f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205914;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205920;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205814:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205820:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205828ULL; PB_CALL(198, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205834:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205840:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205848ULL; PB_CALL(199, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205854:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205860:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205868ULL; PB_CALL(200, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205874:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205880:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205888ULL; PB_CALL(201, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205894:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2058a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2058a8ULL; PB_CALL(202, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2058b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2058c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2058c8ULL; PB_CALL(203, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2058d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2058e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2058e8ULL; PB_CALL(204, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2058f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205900:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205908ULL; PB_CALL(205, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205914:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205920:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205928ULL; PB_CALL(206, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205934:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205974;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205980;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205954:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205c54;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205c60;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205974:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205980:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205988ULL; PB_CALL(207, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205994:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2059d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2059e0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2059b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205d54;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205d60;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2059d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2059e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2059e8ULL; PB_CALL(208, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2059f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205a34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205a40;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205a14:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205cd4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205ce0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205a34:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205a40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205a48ULL; PB_CALL(209, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205a54:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205a94;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205aa0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205a74:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205dd4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205de0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205a94:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205aa0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205aa8ULL; PB_CALL(210, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205ab4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205af4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205b00;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205ad4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205c94;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205ca0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205af4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205b00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205b08ULL; PB_CALL(211, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205b14:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205b54;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205b60;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205b34:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205d94;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205da0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205b54:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205b60:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205b68ULL; PB_CALL(212, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205b74:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205bb4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205bc0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205b94:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205d14;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205d20;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205bb4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205bc0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205bc8ULL; PB_CALL(213, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205bd4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205c14;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205c20;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205bf4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205e14;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205e20;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205c14:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205c20:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205c28ULL; PB_CALL(214, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205c34:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205c40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205c48ULL; PB_CALL(215, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205c54:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205c60:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205c68ULL; PB_CALL(216, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205c74:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205c80:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205c88ULL; PB_CALL(217, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205c94:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205ca0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205ca8ULL; PB_CALL(218, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205cb4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205cc0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205cc8ULL; PB_CALL(219, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205cd4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205ce0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205ce8ULL; PB_CALL(220, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205cf4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205d00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205d08ULL; PB_CALL(221, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205d14:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205d20:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205d28ULL; PB_CALL(222, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205d34:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205d40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205d48ULL; PB_CALL(223, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205d54:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205d60:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205d68ULL; PB_CALL(224, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205d74:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205d80:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205d88ULL; PB_CALL(225, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205d94:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205da0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205da8ULL; PB_CALL(226, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205db4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205dc0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205dc8ULL; PB_CALL(227, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205dd4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205de0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205de8ULL; PB_CALL(228, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205df4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205e00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205e08ULL; PB_CALL(229, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205e14:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205e20:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205e28ULL; PB_CALL(230, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205e34:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205e74;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205e80;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205e54:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206454;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206460;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205e74:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205e80:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205e88ULL; PB_CALL(231, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205e94:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205ed4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205ee0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205eb4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206654;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206660;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205ed4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205ee0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205ee8ULL; PB_CALL(232, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205ef4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205f34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205f40;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205f14:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206554;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206560;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205f34:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205f40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205f48ULL; PB_CALL(233, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205f54:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205f94;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_205fa0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205f74:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206754;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206760;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205f94:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205fa0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x205fa8ULL; PB_CALL(234, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_205fb4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_205ff4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206000;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205fd4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2064d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2064e0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_205ff4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206000:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206008ULL; PB_CALL(235, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206014:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206054;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206060;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206034:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2066d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2066e0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206054:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206060:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206068ULL; PB_CALL(236, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206074:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2060b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2060c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206094:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2065d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2065e0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2060b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2060c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2060c8ULL; PB_CALL(237, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2060d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206114;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206120;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2060f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2067d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2067e0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206114:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206120:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206128ULL; PB_CALL(238, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206134:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206174;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206180;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206154:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206494;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2064a0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206174:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206180:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206188ULL; PB_CALL(239, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206194:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2061d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2061e0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2061b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206694;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2066a0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2061d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2061e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2061e8ULL; PB_CALL(240, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2061f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206234;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206240;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206214:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206594;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2065a0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206234:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206240:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206248ULL; PB_CALL(241, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206254:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206294;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2062a0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206274:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206794;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2067a0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206294:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2062a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2062a8ULL; PB_CALL(242, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2062b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2062f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206300;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2062d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206514;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206520;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2062f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206300:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206308ULL; PB_CALL(243, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206314:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206354;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206360;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206334:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206714;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206720;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206354:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206360:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206368ULL; PB_CALL(244, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206374:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2063b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2063c0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206394:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206614;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206620;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2063b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2063c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2063c8ULL; PB_CALL(245, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2063d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206414;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206420;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2063f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206814;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206820;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206414:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206420:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206428ULL; PB_CALL(246, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206434:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206440:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206448ULL; PB_CALL(247, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206454:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206460:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206468ULL; PB_CALL(248, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206474:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206480:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206488ULL; PB_CALL(249, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206494:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2064a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2064a8ULL; PB_CALL(250, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2064b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2064c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2064c8ULL; PB_CALL(251, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2064d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2064e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2064e8ULL; PB_CALL(252, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2064f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206500:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206508ULL; PB_CALL(253, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206514:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206520:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206528ULL; PB_CALL(254, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206534:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206540:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206548ULL; PB_CALL(255, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206554:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206560:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206568ULL; PB_CALL(256, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206574:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206580:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206588ULL; PB_CALL(257, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206594:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2065a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2065a8ULL; PB_CALL(258, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2065b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2065c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2065c8ULL; PB_CALL(259, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2065d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2065e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2065e8ULL; PB_CALL(260, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2065f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206600:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206608ULL; PB_CALL(261, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206614:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206620:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206628ULL; PB_CALL(262, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206634:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206640:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206648ULL; PB_CALL(263, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206654:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206660:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206668ULL; PB_CALL(264, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206674:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206680:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206688ULL; PB_CALL(265, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206694:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2066a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2066a8ULL; PB_CALL(266, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2066b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2066c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2066c8ULL; PB_CALL(267, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2066d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2066e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2066e8ULL; PB_CALL(268, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2066f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206700:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206708ULL; PB_CALL(269, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206714:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206720:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206728ULL; PB_CALL(270, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206734:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206740:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206748ULL; PB_CALL(271, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206754:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206760:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206768ULL; PB_CALL(272, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206774:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206780:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206788ULL; PB_CALL(273, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206794:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2067a0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2067a8ULL; PB_CALL(274, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2067b4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2067c0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2067c8ULL; PB_CALL(275, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2067d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_2067e0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2067e8ULL; PB_CALL(276, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_2067f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206800:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206808ULL; PB_CALL(277, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
L_206814:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_2044f4;
L_206820:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206828ULL; PB_CALL(278, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_2044f4;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 176ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = SP + 24ULL;
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 72), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 64), 0ULL);
    cpu->regs[30] = PB_BASE + 0x20687cULL; PB_CALL(279, cpu, tlb, PB_BASE + 0x1968a0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(66ULL)));
    if (FLAG_EQ) goto L_206c20;
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[28], (cpu->regs[19] + 24));
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_206b70;
    PB_LDR(cpu->regs[0], (SP + 48));
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    if ((cpu->regs[0])==0) goto L_206bac;
    PB_LDR(cpu->regs[1], (SP + 56));
    if ((cpu->regs[1])==0) goto L_206bac;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x2068b0ULL; PB_CALL(280, cpu, tlb, PB_BASE + 0xe1ec0ULL);
    cpu->regs[25] = cpu->regs[0];
L_2068b4:
    if ((cpu->regs[25])==0) goto L_206eec;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(62ULL)));
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], 3ULL); } else { FLAG_CMP(0, 0); }
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[26] = (FLAG_EQ) ? 1 : 0;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_206b64;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(6ULL)));
    if (FLAG_EQ) goto L_206c0c;
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_206c00;
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[23] = 0ULL;
L_2068e4:
    cpu->regs[0] = cpu->regs[3] + (4ULL << 12);
    PB_LDR(cpu->regs[22], (cpu->regs[3] + 2768));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 884));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_206b38;
L_2068fc:
    PB_LDR(cpu->regs[21], (cpu->regs[3] + 16));
    cpu->regs[21] = cpu->regs[21] - cpu->regs[22];
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_LE) goto L_20691c;
    cpu->regs[0] = cpu->regs[3] + (4ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 892));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_20691c;
    cpu->regs[21] = cpu->regs[21] - 1ULL;
L_20691c:
    PB_LDR(cpu->regs[27], (cpu->regs[19] + 32)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 32) + 8);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[3] + 512),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_206a6c;
L_20692c:
    if ((cpu->regs[27])==0) goto L_206ed4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 512));
    cpu->regs[24] = cpu->regs[21];
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_206bf8;
L_206940:
    PB_LDR(cpu->regs[1], (SP + 48));
    cpu->regs[24] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[24]));
    cpu->regs[21] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    PB_STR((cpu->regs[19] + 40), cpu->regs[24]); PB_STR((cpu->regs[19] + 40) + 8, cpu->regs[21]);
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[22]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LO) goto L_206ba0;
    cpu->regs[22] = cpu->regs[1] - cpu->regs[22];
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_206aac;
    PB_LDR(cpu->regs[26], (cpu->regs[19] + 56));
    cpu->regs[26] = cpu->regs[22] - cpu->regs[26];
L_20696c:
    PB_LDR(cpu->regs[1], (SP + 56));
    if ((cpu->regs[1])==0) goto L_206b98;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2768));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_206b98;
    cpu->regs[2] = cpu->regs[1] - cpu->regs[0];
    FLAG_CMP(cpu->regs[24], cpu->regs[21]);
    if (FLAG_NE) goto L_206ea4;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x206998ULL; PB_CALL(281, cpu, tlb, PB_BASE + 0x208bd0ULL);
    cpu->regs[6] = cpu->regs[26] + cpu->regs[0];
    PB_LDR(cpu->regs[3], (SP + 48)); PB_LDR(cpu->regs[1], (SP + 48) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 56));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    PB_STR((cpu->regs[19] + 56), cpu->regs[1]);
L_2069b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 884));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_2069f0;
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_206b50;
L_2069c8:
    cpu->regs[2] = ((uint32_t)(cpu->regs[20] - 7ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(47ULL)));
    if (FLAG_LS) goto L_206a64;
    cpu->regs[2] = ((uint32_t)(cpu->regs[20] - 56ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_206ecc;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_206ad0;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(65ULL)));
    if (FLAG_EQ) goto L_206bc0;
L_2069f0:
    cpu->regs[5] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[26];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[7] = cpu->regs[27];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[0] + 2960ULL;
    cpu->regs[30] = PB_BASE + 0x206a14ULL; PB_CALL(282, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
L_206a20:
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[30] = PB_BASE + 0x206a28ULL; PB_CALL(283, cpu, tlb, PB_BASE + 0x18d760ULL);
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_206a9c;
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
L_206a30:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_206d58;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 176ULL;
    return;
L_206a64:
    cpu->regs[20] = 55ULL;
    goto L_2069f0;
L_206a6c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x206a74ULL; PB_CALL(284, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = PB_BASE + 0x286000ULL;
    cpu->regs[28] = 1ULL;
    cpu->regs[2] = cpu->regs[2] + 128ULL;
    cpu->regs[30] = PB_BASE + 0x206a8cULL; PB_CALL(285, cpu, tlb, PB_BASE + 0x108264ULL);
    cpu->regs[27] = cpu->regs[0];
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    PB_STR((cpu->regs[19] + 56), 0ULL);
    goto L_20692c;
L_206a9c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 24), cpu->regs[0]);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    goto L_206a30;
L_206aac:
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x206abcULL; PB_CALL(286, cpu, tlb, PB_BASE + 0x208bd0ULL);
    cpu->regs[1] = cpu->regs[22] - cpu->regs[0];
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[19] + 56), cpu->regs[1]);
    goto L_20696c;
L_206ad0:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_206e60;
L_206ad8:
    cpu->regs[1] = cpu->regs[0] + (4ULL << 12);
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 892));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_2069f0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_STR((SP + 8), cpu->regs[6]);
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_206e48;
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x206b08ULL; PB_CALL(287, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[25] = cpu->regs[0];
    PB_LDR(cpu->regs[6], (SP + 8));
L_206b10:
    if ((cpu->regs[25])!=0) goto L_2069f0;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206b28;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206f10;
L_206b28:
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    goto L_206d18;
L_206b38:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[28] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    cpu->regs[30] = PB_BASE + 0x206b48ULL; PB_CALL(288, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[27] = cpu->regs[0];
    goto L_20692c;
L_206b50:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[21] = cpu->regs[24];
    cpu->regs[26] = 0ULL;
    goto L_2069c8;
L_206b64:
    cpu->regs[1] = 1ULL;
    cpu->regs[23] = cpu->regs[1];
    goto L_2068e4;
L_206b70:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 2944ULL;
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x206b8cULL; PB_CALL(289, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 24), cpu->regs[0]);
    goto L_206a20;
L_206b98:
    cpu->regs[6] = 18446744073709551615ULL;
    goto L_2069b4;
L_206ba0:
    cpu->regs[22] = 18446744073709551615ULL;
    cpu->regs[26] = cpu->regs[22];
    goto L_20696c;
L_206bac:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    cpu->regs[30] = PB_BASE + 0x206bb8ULL; PB_CALL(290, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[25] = cpu->regs[0];
    goto L_2068b4;
L_206bc0:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 892));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2069f0;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206bdc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206e84;
L_206bdc:
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    PB_STR((SP + 8), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x206becULL; PB_CALL(291, cpu, tlb, PB_BASE + 0xdea4cULL);
    PB_LDR(cpu->regs[6], (SP + 8));
    cpu->regs[25] = cpu->regs[0];
    goto L_206b10;
L_206bf8:
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 516));
    goto L_206940;
L_206c00:
    PB_LDR(cpu->regs[22], (cpu->regs[3] + 2776));
    cpu->regs[23] = 0ULL;
    goto L_2068fc;
L_206c0c:
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(11ULL)));
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[23] = cpu->regs[1];
    goto L_2068e4;
L_206c20:
    cpu->regs[30] = PB_BASE + 0x206c24ULL; PB_CALL(292, cpu, tlb, PB_BASE + 0xe1f30ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_206d18;
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(18ULL)));
    if (FLAG_NE) goto L_206d28;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2696));
    cpu->regs[21] = PB_BASE + 0x285000ULL;
    cpu->regs[21] = cpu->regs[21] + 2560ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 0));
L_206c54:
    cpu->regs[2] = PB_BASE + 0x286000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[2] + 128ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x206c70ULL; PB_CALL(293, cpu, tlb, PB_BASE + 0x108264ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_206e98;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x206c88ULL; PB_CALL(294, cpu, tlb, PB_BASE + 0x1e61ecULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_206e98;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 2336));
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2760));
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 512));
    cpu->regs[0] = cpu->regs[0] + 2928ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x206cb8ULL; PB_CALL(295, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_206e98;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x206cc8ULL; PB_CALL(296, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_206e40;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x206ce0ULL; PB_CALL(297, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_206cf4;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206cf4ULL; PB_CALL(298, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
L_206cf4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x206cfcULL; PB_CALL(299, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x206d04ULL; PB_CALL(300, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x206d0cULL; PB_CALL(301, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206d14ULL; PB_CALL(302, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
L_206d18:
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[30] = PB_BASE + 0x206d24ULL; PB_CALL(303, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_206a30;
L_206d28:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    PB_LDR(cpu->regs[24], (cpu->regs[1] + 0));
    if (FLAG_LE) goto L_206d68;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(21ULL)));
    if (FLAG_NE) goto L_206da4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2656));
    cpu->regs[21] = PB_BASE + 0x285000ULL;
    cpu->regs[21] = cpu->regs[21] + 2728ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 0));
    goto L_206c54;
L_206d58:
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x206d68ULL; PB_CALL(304, cpu, tlb, PB_BASE + 0x7c170ULL);
L_206d68:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(11ULL)));
    if (FLAG_NE) goto L_206dc0;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 2888ULL;
    cpu->regs[30] = PB_BASE + 0x206d80ULL; PB_CALL(305, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2336));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[3];
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 512));
    cpu->regs[2] = cpu->regs[2] & ~(((uint64_t)((int64_t)cpu->regs[2] >> 63)));
    cpu->regs[30] = PB_BASE + 0x206d9cULL; PB_CALL(306, cpu, tlb, PB_BASE + 0x85020ULL);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    goto L_206d18;
L_206da4:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(25ULL)));
    if (FLAG_EQ) goto L_206e10;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_206df8;
L_206db4:
    cpu->regs[21] = PB_BASE + 0x296000ULL;
    cpu->regs[21] = cpu->regs[21] + 2856ULL;
    goto L_206c54;
L_206dc0:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_LE) goto L_206db4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_EQ) goto L_206e34;
    if (FLAG_GT) goto L_206db4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(12ULL)));
    if (FLAG_EQ) goto L_206e1c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(13ULL)));
    cpu->regs[21] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = PB_BASE + 0x285000ULL;
    cpu->regs[21] = cpu->regs[21] + 2856ULL;
    cpu->regs[0] = cpu->regs[0] + 2544ULL;
    cpu->regs[21] = (FLAG_NE) ? cpu->regs[21] : cpu->regs[0];
    goto L_206c54;
L_206df8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2656));
    cpu->regs[21] = PB_BASE + 0x285000ULL;
    cpu->regs[21] = cpu->regs[21] + 2616ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 0));
    goto L_206c54;
L_206e10:
    cpu->regs[21] = PB_BASE + 0x285000ULL;
    cpu->regs[21] = cpu->regs[21] + 2648ULL;
    goto L_206c54;
L_206e1c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3440));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x206e2cULL; PB_CALL(307, cpu, tlb, PB_BASE + 0x137ba0ULL);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    goto L_206d18;
L_206e34:
    cpu->regs[30] = PB_BASE + 0x206e38ULL; PB_CALL(308, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    goto L_206d18;
L_206e40:
    cpu->regs[19] = 0ULL;
    goto L_206cf4;
L_206e48:
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[0] + 2952ULL;
    cpu->regs[30] = PB_BASE + 0x206e54ULL; PB_CALL(309, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[25] = cpu->regs[0];
    PB_LDR(cpu->regs[6], (SP + 8));
    goto L_206b10;
L_206e60:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_206ad8;
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 8), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x206e78ULL; PB_CALL(310, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[6], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_206ad8;
L_206e84:
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 8), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x206e90ULL; PB_CALL(311, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[6], (SP + 8));
    goto L_206bdc;
L_206e98:
    cpu->regs[19] = 0ULL;
    cpu->regs[22] = 0ULL;
    goto L_206cf4;
L_206ea4:
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x206eb0ULL; PB_CALL(312, cpu, tlb, PB_BASE + 0x1e6224ULL);
    cpu->regs[6] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 56));
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    PB_STR((cpu->regs[19] + 56), cpu->regs[1]);
    goto L_2069b4;
L_206ecc:
    cpu->regs[20] = 1ULL;
    goto L_2069f0;
L_206ed4:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206ee8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_206ef8;
L_206ee8:
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
L_206eec:
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    goto L_206a20;
L_206ef8:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x206f04ULL; PB_CALL(313, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    goto L_206a20;
L_206f10:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x206f18ULL; PB_CALL(314, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    goto L_206d18;
L_206f28:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x206f4cULL; PB_CALL(315, cpu, tlb, PB_BASE + 0xdea4cULL);
    if ((cpu->regs[0])==0) goto L_206fd8;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[30] = PB_BASE + 0x206f5cULL; PB_CALL(316, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_206fbc;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206f74ULL; PB_CALL(317, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_207004;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x206f88ULL; PB_CALL(318, cpu, tlb, PB_BASE + 0xddf30ULL);
    cpu->regs[21] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
L_206f8c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_206fa0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_206ff8;
L_206fa0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_206fe0;
L_206fa8:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_206fbc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_206fd8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_206fd8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x206fd8ULL; PB_CALL(319, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_206fd8:
    cpu->regs[21] = 4294967295ULL;
    goto L_206fa8;
L_206fe0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_206fa8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x206ff4ULL; PB_CALL(320, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_206fa8;
L_206ff8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x207000ULL; PB_CALL(321, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_206fa0;
L_207004:
    cpu->regs[21] = 4294967295ULL;
    goto L_206f8c;
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_20702c;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 255ULL));
    cpu->regs[0] = cpu->regs[6] + cpu->regs[3];
    { PB_CALL(322, cpu, tlb, PB_BASE + 0x7aee0ULL); return; };
L_20702c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_207054;
    cpu->regs[3] = cpu->regs[6] + (cpu->regs[3] << 1);
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 65535ULL));
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[4] << 1);
L_207040:
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_HS) goto L_207050;
    PB_STRH(cpu->regs[3], cpu->regs[5]); cpu->regs[3] += 2;
    goto L_207040;
L_207050:
    return;
L_207054:
    cpu->regs[3] = cpu->regs[6] + (cpu->regs[3] << 2);
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[4] << 2);
L_20705c:
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_LS) goto L_207050;
    PB_STRW(cpu->regs[3], cpu->regs[1]); cpu->regs[3] += 4;
    goto L_20705c;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 28) & 1)) goto L_2070c0;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_GT) goto L_207088;
    { PB_CALL(323, cpu, tlb, PB_BASE + 0x12cb88ULL); return; };
L_207088:
    cpu->regs[2] = cpu->regs[0];
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2070b4ULL; PB_CALL(324, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_2070c0:
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(325, cpu, tlb, PB_BASE + 0x7f10cULL); return; };
    SP = SP - 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[3] = 32064ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x207108ULL; PB_CALL(326, cpu, tlb, PB_BASE + 0x122b00ULL);
    if ((cpu->regs[0])==0) goto L_207168;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x207120ULL; PB_CALL(327, cpu, tlb, PB_BASE + 0x1d3764ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_207138;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2071ac;
L_207138:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_2071b8;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_207168:
    cpu->regs[30] = PB_BASE + 0x20716cULL; PB_CALL(328, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_2071b8;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 456ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    SP = SP + 48ULL;
    { PB_CALL(329, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_2071ac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2071b4ULL; PB_CALL(330, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_207138;
L_2071b8:
    cpu->regs[30] = PB_BASE + 0x2071bcULL; PB_CALL(331, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    SP = SP - 32ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[4] = 33392ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[1] = SP;
    cpu->regs[2] = 1ULL;
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x207204ULL; PB_CALL(332, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_20722c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_20722c:
    cpu->regs[30] = PB_BASE + 0x207230ULL; PB_CALL(333, cpu, tlb, PB_BASE + 0x7c170ULL);
    SP = SP - 64ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[2] = cpu->regs[2] + 3072ULL;
    cpu->regs[30] = PB_BASE + 0x207268ULL; PB_CALL(334, cpu, tlb, PB_BASE + 0x1d4b00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2072fc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_20733c;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x207288ULL; PB_CALL(335, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2072f8;
    cpu->regs[30] = PB_BASE + 0x207294ULL; PB_CALL(336, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_207318;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[20] + 24), cpu->regs[21]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 856));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_2072b8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_2072b8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 856), cpu->regs[19]);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_207304;
L_2072c4:
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = 0ULL;
L_2072cc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_207364;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_2072f8:
    PB_LDR(cpu->regs[21], (SP + 48));
L_2072fc:
    cpu->regs[0] = 4294967295ULL;
    goto L_2072cc;
L_207304:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2072c4;
    cpu->regs[30] = PB_BASE + 0x207314ULL; PB_CALL(337, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2072c4;
L_207318:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1952ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x207330ULL; PB_CALL(338, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    goto L_2072cc;
L_20733c:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2736));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 3088ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x20735cULL; PB_CALL(339, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_2072cc;
L_207364:
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x20736cULL; PB_CALL(340, cpu, tlb, PB_BASE + 0x7c170ULL);
}
