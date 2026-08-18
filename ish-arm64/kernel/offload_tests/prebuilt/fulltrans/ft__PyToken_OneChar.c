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

void ft__PyToken_OneChar(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 33ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(93ULL)));
    if (FLAG_HI) goto L_10a2e0;
    cpu->regs[1] = PB_BASE + 0x2b7000ULL;
    cpu->regs[1] = cpu->regs[1] + 1840ULL;
    cpu->regs[1] = cpu->regs[1] + 3216ULL;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[1] + ((uint64_t)(uint32_t)(cpu->regs[0]))),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    return;
L_10a2e0:
    cpu->regs[0] = 55ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_10a318;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x10a314ULL; PB_CALL(1, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10a324;
L_10a318:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])!=0) goto L_10a334;
    cpu->regs[0] = 0ULL;
L_10a324:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_10a334:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    SP = SP - 240ULL;
    cpu->regs[2] = 6000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 144), cpu->regs[29]); PB_STR((SP + 144) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 144ULL;
    PB_STR((SP + 160), cpu->regs[19]); PB_STR((SP + 160) + 8, cpu->regs[20]);
    PB_STR((SP + 176), cpu->regs[21]); PB_STR((SP + 176) + 8, cpu->regs[22]);
    PB_STR((SP + 208), cpu->regs[25]); PB_STR((SP + 208) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 144));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    PB_STR((SP + 136), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_10b22c;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_10b23c;
L_10a3a0:
    PB_LDRW(cpu->regs[19], (cpu->regs[25] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[25] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10add4;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 8));
    cpu->regs[20] = (((uint64_t)(((int64_t)(cpu->regs[19] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[20]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    if ((cpu->regs[0])==0) goto L_10a3e4;
L_10a3c0:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1158ULL)));
    if (FLAG_EQ) goto L_10a5c4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_10a3c0;
L_10a3d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_EQ) goto L_10b248;
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 96));
L_10a3e4:
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
L_10a3e8:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[20]));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[2], (cpu->regs[0] + 20) + 4);
    PB_STRW((SP + 44), cpu->regs[0]);
    PB_STRW((SP + 80), cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_10b23c;
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10b00c;
L_10a410:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 16));
    PB_STRW((SP + 4), cpu->regs[0]);
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x10a420ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10b278;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b01c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2272));
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 40), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = 6000ULL;
    PB_STR((SP + 32), cpu->regs[1]);
    PB_STR((SP + 192), cpu->regs[23]); PB_STR((SP + 192) + 8, cpu->regs[24]);
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 224), cpu->regs[27]); PB_STR((SP + 224) + 8, cpu->regs[28]);
L_10a458:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_10b200;
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10b214;
L_10a474:
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[0]);
    PB_LDRW(cpu->regs[22], (cpu->regs[25] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_10a814;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10a830;
    cpu->regs[0] = cpu->regs[22];
L_10a498:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[4] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_10a8ac;
L_10a4ac:
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 96));
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
L_10a4b4:
    PB_STRW((cpu->regs[25] + 16), cpu->regs[22]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10ace8;
L_10a4c0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_EQ) goto L_10a844;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10a860;
L_10a4dc:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_10a614;
L_10a4f0:
    PB_LDRW(cpu->regs[19], (SP + 40));
L_10a4f4:
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_10a4fc:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_10a500:
    PB_LDRW(cpu->regs[0], (SP + 4));
    PB_STRW((cpu->regs[25] + 16), cpu->regs[0]);
    PB_STRW((cpu->regs[25] + 144), cpu->regs[3]);
    if ((cpu->regs[24])==0) goto L_10adac;
    PB_LDRW(cpu->regs[20], (cpu->regs[25] + 96));
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_10adac;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 32));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x10a524ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10b094;
    FLAG_CMP(cpu->regs[24], 0ULL);
    if (FLAG_LE) goto L_10a558;
    cpu->regs[2] = 0ULL;
L_10a538:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    PB_LDR(cpu->regs[1], (cpu->regs[26] + cpu->regs[2]));
    PB_STR((cpu->regs[0] + cpu->regs[2]), cpu->regs[1]);
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    FLAG_CMP(cpu->regs[24], cpu->regs[20]);
    if (FLAG_GT) goto L_10a538;
L_10a558:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x10a560ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[20], (cpu->regs[25] + 144));
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    cpu->regs[2] = ((uint32_t)(cpu->regs[20] - 1ULL));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 16));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x10a578ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10b17c;
    PB_LDR(cpu->regs[6], (cpu->regs[25] + 32));
    cpu->regs[1] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[0] = cpu->regs[25];
    PB_LDRW(cpu->regs[2], (SP + 44));
    PB_LDRW(cpu->regs[3], (SP + 80));
    cpu->regs[30] = PB_BASE + 0x10a59cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1972d0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10b18c;
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
L_10a5ac:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = 1158ULL;
    cpu->regs[30] = PB_BASE + 0x10a5c0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1082e0ULL);
    goto L_10a5d0;
L_10a5c4:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 8));
    PB_STRW((cpu->regs[25] + 16), cpu->regs[1]);
L_10a5d0:
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
L_10a5d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[3]);
    PB_LDR(cpu->regs[2], (SP + 136));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_10ae88;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 160)); PB_LDR(cpu->regs[20], (SP + 160) + 8);
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[25], (SP + 208)); PB_LDR(cpu->regs[26], (SP + 208) + 8);
    SP = SP + 240ULL;
    return;
L_10a614:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[6] = ((uint32_t)(cpu->regs[22] + 1ULL));
    PB_STRW((cpu->regs[25] + 16), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x10a624ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1063e8ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10af48;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[30] = PB_BASE + 0x10a634ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1063e8ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10af28;
    PB_LDR(cpu->regs[2], (SP + 32));
    cpu->regs[3] = 0ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[28] = 0ULL;
    PB_LDRB(cpu->regs[5], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + (cpu->regs[0] << 2)));
    FLAG_CMP((cpu->regs[0]) & (3ULL), 0);
    if (FLAG_NE) goto L_10a7c0;
L_10a65c:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(39ULL)));
    cpu->regs[0] = 34ULL;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_10acf8;
    cpu->regs[27] = cpu->regs[1] + 1ULL;
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[27];
    PB_STRW((SP + 16), cpu->regs[3]);
    PB_STRW((SP + 24), cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x10a684ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[1] = 2147483647ULL;
    PB_LDRW(cpu->regs[3], (SP + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    PB_LDRW(cpu->regs[5], (SP + 24));
    PB_LDR(cpu->regs[1], (SP + 8));
    if (FLAG_HI) goto L_10af5c;
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[22] = cpu->regs[0] - 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_NE) goto L_10b1e8;
    FLAG_CMP(cpu->regs[22], 3ULL);
    if (FLAG_LS) goto L_10a6c0;
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_EQ) goto L_10a778;
L_10a6c0:
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_10adfc;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = 92ULL;
    cpu->regs[30] = PB_BASE + 0x10a6d0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7b3e0ULL);
    if ((((uint32_t)(cpu->regs[28])))!=0) goto L_10a874;
    if ((cpu->regs[0])!=0) goto L_10a75c;
L_10a6d8:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10a6f0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdea80ULL);
    cpu->regs[28] = cpu->regs[0];
L_10a6f4:
    if ((cpu->regs[28])==0) goto L_10af28;
L_10a6f8:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 32));
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x10a704ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xf7220ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10b1c0;
    PB_LDRB(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[1] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(117ULL)));
    if (FLAG_EQ) goto L_10af30;
L_10a718:
    PB_LDR(cpu->regs[6], (cpu->regs[25] + 32));
    cpu->regs[0] = cpu->regs[28];
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + 20)); PB_LDRW(cpu->regs[3], (cpu->regs[21] + 20) + 4);
    PB_LDRW(cpu->regs[4], (cpu->regs[21] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[21] + 28) + 4);
    cpu->regs[30] = PB_BASE + 0x10a72cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x10c468ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    if ((cpu->regs[0])==0) goto L_10af54;
L_10a738:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 2ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[3]);
    FLAG_CMP(cpu->regs[19], cpu->regs[24]);
    if (FLAG_EQ) goto L_10ad30;
L_10a748:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 16));
    PB_STR((cpu->regs[26] + (cpu->regs[24] << 3)), cpu->regs[21]);
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    PB_STRW((SP + 4), cpu->regs[0]);
    goto L_10a458;
L_10a75c:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10a770ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1a1860ULL);
    cpu->regs[28] = cpu->regs[0];
    goto L_10a6f4;
L_10a778:
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + 2));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_NE) goto L_10a6c0;
    cpu->regs[27] = cpu->regs[1] + 3ULL;
    cpu->regs[1] = cpu->regs[27] + cpu->regs[0];
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + -4));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_10a7a8;
    cpu->regs[22] = cpu->regs[0] - 5ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[27] + cpu->regs[22]));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10a6c0;
L_10a7a8:
    PB_LDRW(cpu->regs[19], (SP + 40));
    cpu->regs[0] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = 299ULL;
    cpu->regs[0] = cpu->regs[0] + 3168ULL;
    cpu->regs[30] = PB_BASE + 0x10a7bcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_10ad0c;
L_10a7c0:
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    cpu->regs[6] = 1ULL;
L_10a7c8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[5] - 66ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(51ULL)));
    if (FLAG_HI) goto L_10acf0;
    cpu->regs[0] = cpu->regs[6] << (cpu->regs[0] & 63);
    FLAG_CMP((cpu->regs[0]) & (281474976776192ULL), 0);
    if (FLAG_NE) goto L_10ae04;
    FLAG_CMP((cpu->regs[0]) & (2251799814209536ULL), 0);
    if (FLAG_NE) goto L_10aeec;
    FLAG_CMP((cpu->regs[0]) & (4294967297ULL), 0);
    if (FLAG_EQ) goto L_10acf8;
    PB_LDRB(cpu->regs[5], (cpu->regs[2] + 0));
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[28] = 1ULL;
L_10a7fc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[28] ^ 1ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[3] ^ 1ULL));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | cpu->regs[4]));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10a7c8;
    goto L_10a65c;
L_10a814:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10a81cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10b220;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[25] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_10a498;
L_10a830:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10a838ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10aec8;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 16));
    goto L_10a498;
L_10a844:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10a84cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10a4f0;
    PB_LDRW(cpu->regs[22], (cpu->regs[25] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[25] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_NE) goto L_10a4dc;
L_10a860:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10a868ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10aedc;
    PB_LDRW(cpu->regs[22], (cpu->regs[25] + 16));
    goto L_10a4dc;
L_10a874:
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[28] = (FLAG_EQ) ? 1 : 0;
L_10a87c:
    cpu->regs[1] = cpu->regs[27];
    goto L_10a88c;
L_10a884:
    if (((cpu->regs[0] >> 7) & 1)) goto L_10ae5c;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_10a88c:
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10a884;
    cpu->regs[1] = cpu->regs[22];
    if ((((uint32_t)(cpu->regs[28])))==0) goto L_10ad4c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10a8a4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[28] = cpu->regs[0];
    goto L_10a6f4;
L_10a8ac:
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[25] + 16), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10afc0;
L_10a8cc:
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10afb0;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 16));
    PB_STRW((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 8ULL;
    PB_STR((SP + 16), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x10a8e8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 16));
    if ((cpu->regs[0])==0) goto L_10b0f0;
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 96));
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10b104;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[27] = 0ULL;
    cpu->regs[25] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[23] = 1ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[26]);
    PB_LDRW(cpu->regs[26], (SP + 8));
    PB_STRW((SP + 48), cpu->regs[22]);
    PB_STR((SP + 56), cpu->regs[4]);
    goto L_10a934;
L_10a928:
    PB_LDRW(cpu->regs[26], (cpu->regs[21] + 16));
    PB_STR((cpu->regs[28] + (cpu->regs[27] << 3)), cpu->regs[22]);
    cpu->regs[27] = cpu->regs[27] + 1ULL;
L_10a934:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] + 1ULL));
    PB_STRW((cpu->regs[21] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10b110;
L_10a948:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10aa00;
    PB_LDRW(cpu->regs[19], (cpu->regs[21] + 16));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x10a95cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x19eda0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10a9cc;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 96));
    PB_STRW((cpu->regs[21] + 16), cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10ae30;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 62ULL;
    cpu->regs[30] = PB_BASE + 0x10a97cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10aa00;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x10a98cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1063e8ULL);
    if ((cpu->regs[0])==0) goto L_10afd4;
    cpu->regs[30] = PB_BASE + 0x10a994ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10afd4;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    cpu->regs[30] = PB_BASE + 0x10a9a8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xf7220ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10b11c;
    PB_LDR(cpu->regs[6], (cpu->regs[21] + 32));
    cpu->regs[0] = cpu->regs[22];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 20)); PB_LDRW(cpu->regs[3], (cpu->regs[19] + 20) + 4);
    cpu->regs[1] = 0ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[19] + 28) + 4);
    cpu->regs[30] = PB_BASE + 0x10a9c4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x10c468ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10afd4;
L_10a9cc:
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[21] + 144), cpu->regs[3]);
    FLAG_CMP(cpu->regs[23], cpu->regs[27]);
    if (FLAG_NE) goto L_10a928;
    cpu->regs[23] = cpu->regs[23] << 1;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[23] << 3;
    cpu->regs[30] = PB_BASE + 0x10a9f0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_10b0dc;
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + 144));
    cpu->regs[28] = cpu->regs[0];
    goto L_10a928;
L_10aa00:
    PB_STRW((SP + 8), cpu->regs[26]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[26], (SP + 16) + 8);
    cpu->regs[21] = cpu->regs[25];
    PB_LDR(cpu->regs[4], (SP + 56));
    cpu->regs[25] = cpu->regs[0];
    PB_LDRW(cpu->regs[22], (SP + 48));
L_10aa1c:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_10aa24:
    PB_STRW((cpu->regs[25] + 144), cpu->regs[0]);
L_10aa28:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 32));
    PB_STR((SP + 16), cpu->regs[4]);
    PB_LDRW(cpu->regs[0], (SP + 8));
    PB_STRW((cpu->regs[25] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x10aa40ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 16));
    if ((cpu->regs[0])!=0) goto L_10aa64;
    goto L_10b0e8;
L_10aa50:
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[28] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
L_10aa64:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[27], cpu->regs[21]);
    if (FLAG_GT) goto L_10aa50;
    cpu->regs[0] = cpu->regs[28];
    PB_STR((SP + 8), cpu->regs[3]); PB_STR((SP + 8) + 8, cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x10aa7cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 144));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 63ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x10aa94ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_STR((SP + 96), cpu->regs[0]);
    PB_LDR(cpu->regs[3], (SP + 8)); PB_LDR(cpu->regs[4], (SP + 8) + 8);
    if ((cpu->regs[0])==0) goto L_10a4ac;
    cpu->regs[7] = cpu->regs[3];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[2], cpu->regs[7]); cpu->regs[7] += 16;
    PB_STR((SP + 56), cpu->regs[2]);
L_10aab0:
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LE) goto L_10aaf4;
    PB_LDR(cpu->regs[0], (cpu->regs[7] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(19ULL)));
    if (FLAG_EQ) goto L_10aad0;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_10aab0;
L_10aad0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_10b174;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
L_10aae0:
    PB_LDR(cpu->regs[5], (SP + 56));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[0] = cpu->regs[5] + cpu->regs[0];
    PB_STR((SP + 56), cpu->regs[0]);
    goto L_10aab0;
L_10aaf4:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 8));
    PB_STR((SP + 8), cpu->regs[4]); PB_STR((SP + 8) + 8, cpu->regs[2]);
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x10ab04ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1063e8ULL);
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[4], (SP + 8)); PB_LDR(cpu->regs[2], (SP + 8) + 8);
    if ((cpu->regs[0])==0) goto L_10afa8;
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 3072ULL;
    PB_STR((SP + 16), cpu->regs[4]); PB_STR((SP + 16) + 8, cpu->regs[3]);
    PB_STR((SP + 48), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x10ab24ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7b450ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 32));
    PB_STR((SP + 8), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x10ab34ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[6] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 48));
    PB_LDR(cpu->regs[4], (SP + 16)); PB_LDR(cpu->regs[3], (SP + 16) + 8);
    if ((cpu->regs[0])==0) goto L_10afa8;
    cpu->regs[0] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[0] + 3160ULL;
    cpu->regs[28] = PB_BASE + 0x286000ULL;
    cpu->regs[23] = cpu->regs[6];
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[28] + 3152ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[3];
    PB_STR((SP + 88), cpu->regs[24]);
    cpu->regs[24] = cpu->regs[2];
    cpu->regs[21] = 0ULL;
    cpu->regs[28] = 0ULL;
    PB_STR((SP + 16), cpu->regs[1]);
    PB_STR((SP + 24), cpu->regs[0]);
    PB_STRW((SP + 84), cpu->regs[22]);
    PB_STR((SP + 104), cpu->regs[4]);
L_10ab8c:
    FLAG_CMP(cpu->regs[24], cpu->regs[21]);
    if (FLAG_LE) goto L_10ac80;
    cpu->regs[0] = cpu->regs[26] + 16ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[0] + (cpu->regs[21] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[27] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(19ULL)));
    if (FLAG_EQ) goto L_10ae94;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_10ac6c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    cpu->regs[30] = PB_BASE + 0x10abb8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10aef8;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x10abc8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10af7c;
    PB_LDR(cpu->regs[1], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10abd8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10af7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10abe4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[22] = cpu->regs[0];
L_10abe8:
    PB_LDR(cpu->regs[0], (SP + 8));
    if ((cpu->regs[0])!=0) goto L_10ac00;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 92ULL;
    cpu->regs[30] = PB_BASE + 0x10abfcULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7b3e0ULL);
    if ((cpu->regs[0])!=0) goto L_10ae14;
L_10ac00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10ac18ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdea80ULL);
    cpu->regs[19] = cpu->regs[0];
L_10ac1c:
    if ((cpu->regs[19])==0) goto L_10af0c;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 32));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10ac2cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xf7220ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10af84;
    PB_LDR(cpu->regs[6], (cpu->regs[25] + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 32)); PB_LDRW(cpu->regs[3], (cpu->regs[27] + 32) + 4);
    cpu->regs[1] = 0ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[27] + 40)); PB_LDRW(cpu->regs[5], (cpu->regs[27] + 40) + 4);
    cpu->regs[30] = PB_BASE + 0x10ac48ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x10c468ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10aef8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_10ac6c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_10ac78;
L_10ac6c:
    cpu->regs[0] = cpu->regs[28] + 2ULL;
    cpu->regs[28] = cpu->regs[28] + 1ULL;
    PB_STR((cpu->regs[23] + (cpu->regs[0] << 3)), cpu->regs[27]);
L_10ac78:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_10ab8c;
L_10ac80:
    PB_LDR(cpu->regs[0], (SP + 56)); PB_LDR(cpu->regs[19], (SP + 56) + 8);
    cpu->regs[6] = cpu->regs[23];
    PB_LDR(cpu->regs[26], (SP + 72));
    PB_LDR(cpu->regs[24], (SP + 88));
    PB_LDR(cpu->regs[4], (SP + 104));
    PB_LDRW(cpu->regs[22], (SP + 84));
    FLAG_CMP(cpu->regs[0], cpu->regs[28]);
    if (FLAG_NE) goto L_10b060;
L_10aca0:
    PB_LDR(cpu->regs[3], (SP + 96));
    cpu->regs[0] = cpu->regs[6];
    PB_LDR(cpu->regs[5], (cpu->regs[25] + 32));
    cpu->regs[3] = cpu->regs[3] + 28ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[4] + 20)); PB_LDRW(cpu->regs[2], (cpu->regs[4] + 20) + 4);
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 0)); PB_LDRW(cpu->regs[4], (cpu->regs[3] + 0) + 4);
    cpu->regs[30] = PB_BASE + 0x10acbcULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1a1320ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    if ((cpu->regs[0])!=0) goto L_10a738;
L_10acc8:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[30] = PB_BASE + 0x10acd0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_10b058;
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
L_10ace0:
    PB_STRW((cpu->regs[25] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_10a4c0;
L_10ace8:
    PB_LDRW(cpu->regs[19], (SP + 40));
    goto L_10a4fc;
L_10acf0:
    cpu->regs[1] = cpu->regs[2] - 1ULL;
    goto L_10a65c;
L_10acf8:
    cpu->regs[0] = PB_BASE + 0x286000ULL;
    PB_LDRW(cpu->regs[19], (SP + 40));
    cpu->regs[0] = cpu->regs[0] + 3168ULL;
    cpu->regs[1] = 271ULL;
    cpu->regs[30] = PB_BASE + 0x10ad0cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x9bb50ULL);
L_10ad0c:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10ad14ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x234f48ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
L_10ad18:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[30] = PB_BASE + 0x10ad20ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_10a4fc;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    goto L_10a4fc;
L_10ad30:
    cpu->regs[19] = cpu->regs[19] << 1;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[19] << 3;
    cpu->regs[30] = PB_BASE + 0x10ad40ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_10b090;
    cpu->regs[26] = cpu->regs[0];
    goto L_10a748;
L_10ad4c:
    cpu->regs[4] = SP + 128ULL;
    cpu->regs[3] = SP + 124ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10ad60ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1a42a0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_10af28;
    PB_LDR(cpu->regs[2], (SP + 128));
    if ((cpu->regs[2])==0) goto L_10a6f8;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10ad80ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x25d108ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_10a6f4;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    PB_LDRW(cpu->regs[19], (SP + 40));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10ad0c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_10ad0c;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x10ada8ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_10ad0c;
L_10adac:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x10adb4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_10adc4:
    cpu->regs[22] = 0ULL;
    PB_STRW((cpu->regs[25] + 16), cpu->regs[19]);
    PB_STRW((cpu->regs[25] + 144), cpu->regs[0]);
    goto L_10a5ac;
L_10add4:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10addcULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10b0bc;
    PB_LDRW(cpu->regs[19], (cpu->regs[25] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 8));
    cpu->regs[20] = (((uint64_t)(((int64_t)(cpu->regs[19] << 32)) >> 32) & 0xffffffffULL) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[20]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    if ((cpu->regs[0])!=0) goto L_10a3c0;
    goto L_10a3d4;
L_10adfc:
    if ((((uint32_t)(cpu->regs[28])))==0) goto L_10a6d8;
    goto L_10a87c;
L_10ae04:
    PB_LDRB(cpu->regs[5], (cpu->regs[2] + 0));
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[3] = 1ULL;
    goto L_10a7fc;
L_10ae14:
    PB_LDR(cpu->regs[3], (SP + 96));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10ae28ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1a1860ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_10ac1c;
L_10ae30:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[25];
    cpu->regs[25] = cpu->regs[0];
    PB_LDRW(cpu->regs[22], (SP + 48));
    PB_LDR(cpu->regs[4], (SP + 56));
    PB_STRW((SP + 8), cpu->regs[26]);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[26], (SP + 16) + 8);
    goto L_10aa28;
L_10ae5c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[0] = cpu->regs[25];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 20),&_a,4); tlb_read(tlb,(cpu->regs[21] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = PB_BASE + 0x286000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[6] = cpu->regs[6] + 3224ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[21] + 28),&_a,4); tlb_read(tlb,(cpu->regs[21] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    PB_LDRW(cpu->regs[19], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x10ae84ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x280d00ULL);
    goto L_10ad0c;
L_10ae88:
    PB_STR((SP + 192), cpu->regs[23]); PB_STR((SP + 192) + 8, cpu->regs[24]);
    PB_STR((SP + 224), cpu->regs[27]); PB_STR((SP + 224) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x10ae94ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x7c170ULL);
L_10ae94:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    if ((cpu->regs[0])==0) goto L_10b028;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_10b028;
    cpu->regs[1] = cpu->regs[23] + (cpu->regs[28] << 3);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[28] = cpu->regs[28] + 2ULL;
    PB_STR((cpu->regs[1] + 16), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_STR((cpu->regs[1] + 24), cpu->regs[0]);
    goto L_10ab8c;
L_10aec8:
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    goto L_10a4b4;
L_10aedc:
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[19], (SP + 40));
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    goto L_10a4f4;
L_10aeec:
    PB_LDRB(cpu->regs[5], (cpu->regs[2] + 0));
    cpu->regs[1] = cpu->regs[2];
    goto L_10a7fc;
L_10aef8:
    PB_LDR(cpu->regs[24], (SP + 88));
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    PB_LDRW(cpu->regs[22], (SP + 84));
    goto L_10acc8;
L_10af0c:
    PB_LDR(cpu->regs[24], (SP + 88));
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[22], (SP + 84));
    cpu->regs[30] = PB_BASE + 0x10af20ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x234f48ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    goto L_10acc8;
L_10af28:
    PB_LDRW(cpu->regs[19], (SP + 40));
    goto L_10ad0c;
L_10af30:
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 3272ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10af40ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x107580ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_10a718;
L_10af48:
    PB_LDRW(cpu->regs[19], (SP + 40));
L_10af4c:
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    goto L_10ad18;
L_10af54:
    PB_LDRW(cpu->regs[19], (SP + 40));
    goto L_10ad18;
L_10af5c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    PB_LDRW(cpu->regs[19], (SP + 40));
    cpu->regs[1] = cpu->regs[1] + 3192ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x10af78ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_10ad0c;
L_10af7c:
    cpu->regs[22] = 1ULL;
    goto L_10abe8;
L_10af84:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[23] = cpu->regs[19];
    PB_LDR(cpu->regs[24], (SP + 88));
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[22], (SP + 84));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10afa8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_10b164;
L_10afa8:
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    goto L_10acc8;
L_10afb0:
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[3]);
    goto L_10a4b4;
L_10afc0:
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x10afccULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDR(cpu->regs[4], (SP + 8));
    goto L_10a8cc;
L_10afd4:
    PB_STRW((SP + 8), cpu->regs[26]);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[26], (SP + 16) + 8);
    cpu->regs[21] = cpu->regs[25];
    PB_LDR(cpu->regs[4], (SP + 56));
    cpu->regs[25] = cpu->regs[0];
    PB_LDRW(cpu->regs[22], (SP + 48));
L_10aff0:
    cpu->regs[30] = PB_BASE + 0x10aff4ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_10aa1c;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[25] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_10aa24;
L_10b00c:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10b014ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10a410;
L_10b01c:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_10adc4;
L_10b028:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[27] + 32));
    cpu->regs[1] = cpu->regs[1] + 3080ULL;
    PB_LDR(cpu->regs[24], (SP + 88));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[22], (SP + 84));
    cpu->regs[30] = PB_BASE + 0x10b050ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    goto L_10acc8;
L_10b058:
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 96));
    goto L_10ace0;
L_10b060:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 32));
    cpu->regs[0] = cpu->regs[28];
    PB_STR((SP + 8), cpu->regs[4]); PB_STR((SP + 8) + 8, cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x10b070ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    PB_LDR(cpu->regs[4], (SP + 8)); PB_LDR(cpu->regs[6], (SP + 8) + 8);
    cpu->regs[1] = 1ULL;
    if ((cpu->regs[0])==0) goto L_10afa8;
L_10b07c:
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    FLAG_CMP(cpu->regs[28], cpu->regs[2]);
    if (FLAG_GT) goto L_10b0cc;
    cpu->regs[6] = cpu->regs[0];
    goto L_10aca0;
L_10b090:
    PB_LDRW(cpu->regs[19], (SP + 40));
L_10b094:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x10b09cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x10b0a8ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 144));
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    goto L_10adc4;
L_10b0bc:
    cpu->regs[0] = 1ULL;
    cpu->regs[22] = 0ULL;
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    goto L_10a5d0;
L_10b0cc:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[6] + (cpu->regs[1] << 3)));
    PB_STR((cpu->regs[0] + (cpu->regs[1] << 3)), cpu->regs[2]);
    goto L_10b07c;
L_10b0dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[26], (SP + 16) + 8);
    cpu->regs[25] = cpu->regs[21];
    PB_LDRW(cpu->regs[22], (SP + 48));
L_10b0e8:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x10b0f0ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_10b0f0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x10b0fcULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 96));
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
L_10b104:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[25] + 144), cpu->regs[3]);
    goto L_10a4b4;
L_10b110:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x10b118ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_10a948;
L_10b11c:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[25];
    cpu->regs[25] = cpu->regs[0];
    PB_STRW((SP + 8), cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[4], (SP + 56));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[26], (SP + 16) + 8);
    PB_LDRW(cpu->regs[22], (SP + 48));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10aff0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_10aff0;
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 16), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x10b15cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[4], (SP + 16));
    goto L_10aff0;
L_10b164:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x10b16cULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    goto L_10acc8;
L_10b174:
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_10aae0;
L_10b17c:
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    cpu->regs[3] = ((uint32_t)(cpu->regs[20] - 2ULL));
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    goto L_10a5d8;
L_10b18c:
    cpu->regs[30] = PB_BASE + 0x10b190ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_10b1b0;
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    goto L_10a5d8;
L_10b1b0:
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[27], (SP + 224)); PB_LDR(cpu->regs[28], (SP + 224) + 8);
    goto L_10a5ac;
L_10b1c0:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    PB_LDRW(cpu->regs[19], (SP + 40));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10af4c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_10af4c;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x10b1e0ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    goto L_10ad18;
L_10b1e8:
    PB_LDRW(cpu->regs[19], (SP + 40));
    cpu->regs[0] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = 288ULL;
    cpu->regs[0] = cpu->regs[0] + 3168ULL;
    cpu->regs[30] = PB_BASE + 0x10b1fcULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_10ad0c;
L_10b200:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10b208ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + 96));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 144));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_10a474;
L_10b214:
    PB_LDRW(cpu->regs[19], (SP + 40));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10a500;
L_10b220:
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    goto L_10ace0;
L_10b22c:
    cpu->regs[30] = PB_BASE + 0x10b230ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 96));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_10a3a0;
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
L_10b23c:
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[22] = 0ULL;
    goto L_10a5d8;
L_10b248:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x10b250ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xf27b0ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[25] + 144));
    if (((cpu->regs[0] >> 31) & 1)) goto L_10b264;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 96));
    goto L_10a3e8;
L_10b264:
    cpu->regs[0] = 1ULL;
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    cpu->regs[22] = 0ULL;
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    goto L_10a5d8;
L_10b278:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[25] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x10b284ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_10adc4;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    cpu->regs[23] = cpu->regs[20] + 24ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10b30c;
L_10b2bc:
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_10b2f8;
L_10b2c4:
    PB_LDR(cpu->regs[20], (cpu->regs[23] + (cpu->regs[19] << 3)));
    if ((cpu->regs[20])==0) goto L_10b2bc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 14) & 1)) goto L_10b2bc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10b3e4;
L_10b2e0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10b2bc;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[20] + -8), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_GE) goto L_10b2c4;
L_10b2f8:
    cpu->regs[0] = 0ULL;
L_10b2fc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_10b30c:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
L_10b318:
    cpu->regs[23] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_LT) goto L_10b3dc;
    cpu->regs[24] = cpu->regs[20] + (cpu->regs[19] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[19] << 3;
    if ((cpu->regs[0])==0) goto L_10b414;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10b33cULL; PB_CALL(80, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b3c4;
    cpu->regs[23] = cpu->regs[19] - 2ULL;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_10b3d0;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    if ((cpu->regs[0])==0) goto L_10b414;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10b35cULL; PB_CALL(81, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b3c4;
    cpu->regs[23] = cpu->regs[19] - 3ULL;
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_10b3d0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[25]));
    if ((cpu->regs[0])==0) goto L_10b414;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10b37cULL; PB_CALL(82, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b3c4;
    cpu->regs[23] = cpu->regs[19] - 4ULL;
    FLAG_CMP(cpu->regs[19], 3ULL);
    if (FLAG_EQ) goto L_10b3d0;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + -8));
    if ((cpu->regs[0])==0) goto L_10b414;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10b39cULL; PB_CALL(83, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b3c4;
    cpu->regs[19] = cpu->regs[20] + 24ULL;
L_10b3a4:
    cpu->regs[23] = cpu->regs[23] - 1ULL;
    cpu->regs[1] = cpu->regs[22];
    FLAG_CMP(cpu->regs[23], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_10b3d0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + (cpu->regs[23] << 3)));
    if ((cpu->regs[0])==0) goto L_10b414;
    cpu->regs[30] = PB_BASE + 0x10b3c0ULL; PB_CALL(84, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10b3a4;
L_10b3c4:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_10b2fc;
L_10b3d0:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_10b2f8;
L_10b3dc:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_10b2f8;
L_10b3e4:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10b404;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b2e0;
    goto L_10b2bc;
L_10b404:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10b40cULL; PB_CALL(85, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b2e0;
    goto L_10b2bc;
L_10b414:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[19] = cpu->regs[23];
    goto L_10b318;
    SP = SP - 272ULL;
    PB_STR((SP + 208), cpu->regs[29]); PB_STR((SP + 208) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 208ULL;
    PB_STR((SP + 224), cpu->regs[19]); PB_STR((SP + 224) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 240), cpu->regs[21]); PB_STR((SP + 240) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 168));
    PB_STR((SP + 256), cpu->regs[23]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 200), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if (!((cpu->regs[1] >> 9) & 1)) goto L_10b760;
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 264));
    cpu->regs[20] = cpu->regs[2];
    if ((cpu->regs[22])==0) goto L_10b484;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_10b624;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10b518;
L_10b484:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 352));
    if ((cpu->regs[0])!=0) goto L_10b750;
L_10b48c:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 344));
    if ((cpu->regs[22])==0) goto L_10b708;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_10b5e8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10b534;
L_10b4b0:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 336));
    if ((cpu->regs[23])==0) goto L_10b4c4;
L_10b4b8:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10b560;
L_10b4c4:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 256));
    if ((cpu->regs[22])==0) goto L_10b4d8;
L_10b4cc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10b58c;
L_10b4d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 888));
    if ((cpu->regs[0])!=0) goto L_10b5ac;
L_10b4e0:
    cpu->regs[0] = 0ULL;
L_10b4e4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 200));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_10b6a8;
    PB_LDR(cpu->regs[23], (SP + 256));
    PB_LDR(cpu->regs[29], (SP + 208)); PB_LDR(cpu->regs[30], (SP + 208) + 8);
    PB_LDR(cpu->regs[19], (SP + 224)); PB_LDR(cpu->regs[20], (SP + 224) + 8);
    PB_LDR(cpu->regs[21], (SP + 240)); PB_LDR(cpu->regs[22], (SP + 240) + 8);
    SP = SP + 272ULL;
    return;
L_10b518:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10b68c;
L_10b520:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10b484;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[22] + -8), cpu->regs[0]);
    goto L_10b484;
L_10b534:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10b670;
L_10b53c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10b4b0;
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 336));
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[22] + -8), cpu->regs[0]);
    if ((cpu->regs[23])==0) goto L_10b4c4;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 14) & 1)) goto L_10b4c4;
L_10b560:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10b654;
L_10b568:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10b4c4;
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 256));
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[23] + -8), cpu->regs[0]);
    if ((cpu->regs[22])==0) goto L_10b4d8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 14) & 1)) goto L_10b4d8;
L_10b58c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10b638;
L_10b594:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + -8));
    if (!((cpu->regs[1] >> 1) & 1)) goto L_10b4d8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 888));
    cpu->regs[1] = cpu->regs[1] - 4ULL;
    PB_STR((cpu->regs[22] + -8), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_10b4e0;
L_10b5ac:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 200));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_10b6a8;
    PB_LDR(cpu->regs[29], (SP + 208)); PB_LDR(cpu->regs[30], (SP + 208) + 8);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 224)); PB_LDR(cpu->regs[20], (SP + 224) + 8);
    PB_LDR(cpu->regs[21], (SP + 240)); PB_LDR(cpu->regs[22], (SP + 240) + 8);
    PB_LDR(cpu->regs[23], (SP + 256));
    SP = SP + 272ULL;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_10b5e8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10b5f4ULL; PB_CALL(86, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b4e4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 336));
    if ((cpu->regs[0])==0) goto L_10b6ec;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10b608ULL; PB_CALL(87, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b4e4;
L_10b60c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 256));
    if ((cpu->regs[0])==0) goto L_10b4d8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10b61cULL; PB_CALL(88, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10b4d8;
    goto L_10b4e4;
L_10b624:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x10b630ULL; PB_CALL(89, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10b484;
    goto L_10b4e4;
L_10b638:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10b6dc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10b594;
    goto L_10b4d8;
L_10b654:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10b6cc;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10b568;
    goto L_10b4c4;
L_10b670:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10b6bc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10b53c;
    goto L_10b4b0;
L_10b68c:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10b6ac;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10b520;
    goto L_10b484;
L_10b6a8:
    cpu->regs[30] = PB_BASE + 0x10b6acULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x7c170ULL);
L_10b6ac:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10b6b4ULL; PB_CALL(91, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b520;
    goto L_10b484;
L_10b6bc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10b6c4ULL; PB_CALL(92, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b53c;
    goto L_10b4b0;
L_10b6cc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x10b6d4ULL; PB_CALL(93, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b568;
    goto L_10b4c4;
L_10b6dc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10b6e4ULL; PB_CALL(94, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b594;
    goto L_10b4d8;
L_10b6ec:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 256));
    if ((cpu->regs[22])==0) goto L_10b4d8;
L_10b6f4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10b700ULL; PB_CALL(95, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10b4d8;
    goto L_10b4e4;
L_10b708:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 336));
    if ((cpu->regs[23])==0) goto L_10b734;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_10b4b8;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10b72cULL; PB_CALL(96, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10b60c;
    goto L_10b4e4;
L_10b734:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 256));
    if ((cpu->regs[22])==0) goto L_10b4d8;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_10b4cc;
    goto L_10b6f4;
L_10b750:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10b758ULL; PB_CALL(97, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10b48c;
    goto L_10b4e4;
L_10b760:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[0] = SP;
    cpu->regs[2] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = 200ULL;
    cpu->regs[2] = cpu->regs[2] + 3280ULL;
    cpu->regs[30] = PB_BASE + 0x10b778ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x7ada0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(200ULL)));
    if (FLAG_LS) goto L_10b788;
    __builtin_trap();
L_10b788:
    cpu->regs[5] = PB_BASE + 0x2b7000ULL;
    cpu->regs[5] = cpu->regs[5] + 1840ULL;
    cpu->regs[3] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 3384ULL;
    cpu->regs[3] = cpu->regs[3] + 3336ULL;
    cpu->regs[4] = 5243ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x10b7b0ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x924f8ULL);
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_10b834;
L_10b7cc:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    if ((cpu->regs[19])==0) goto L_10b7f0;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_10b81c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10b800;
L_10b7f0:
    cpu->regs[0] = 0ULL;
L_10b7f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_10b800:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10b86c;
L_10b808:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10b7f0;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    goto L_10b7f0;
L_10b81c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_10b834:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 80));
    if ((cpu->regs[3])==0) goto L_10b7cc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_10b850;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_10b7cc;
L_10b850:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x10b860ULL; PB_CALL(100, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[2], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10b7cc;
    goto L_10b7f4;
L_10b86c:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10b88c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b808;
    goto L_10b7f0;
L_10b88c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10b894ULL; PB_CALL(101, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b808;
    goto L_10b7f0;
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = PB_BASE + 0x51d000ULL;
    cpu->regs[21] = cpu->regs[21] + 3600ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[23] = PB_BASE + 0x108000ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[21] + 1784ULL;
    cpu->regs[23] = cpu->regs[23] + 1664ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32)); PB_LDR(cpu->regs[5], (cpu->regs[0] + 32) + 8);
    cpu->regs[25] = cpu->regs[1];
L_10b8e0:
    cpu->regs[6] = cpu->regs[20] << 4;
    cpu->regs[4] = cpu->regs[5] + (cpu->regs[20] << 4);
    FLAG_CMP(cpu->regs[3], cpu->regs[20]);
    if (FLAG_LT) goto L_10b9c4;
L_10b8f0:
    PB_LDR(cpu->regs[19], (cpu->regs[5] + cpu->regs[6]));
    cpu->regs[2] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_10b9e0;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_LT) goto L_10b9c4;
    PB_LDR(cpu->regs[19], (cpu->regs[4] + 16));
    cpu->regs[2] = cpu->regs[20] + 2ULL;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_10b9e0;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_LT) goto L_10b9c4;
    PB_LDR(cpu->regs[19], (cpu->regs[4] + 32));
    cpu->regs[2] = cpu->regs[20] + 3ULL;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_10b9e0;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_LT) goto L_10b9c4;
    PB_LDR(cpu->regs[19], (cpu->regs[4] + 48));
    cpu->regs[20] = cpu->regs[20] + 4ULL;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_10b984;
L_10b958:
    FLAG_CMP(cpu->regs[3], cpu->regs[20]);
    if (FLAG_LT) goto L_10b9c4;
    cpu->regs[4] = cpu->regs[20] << 4;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[5] + cpu->regs[4]));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_10b958;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_LT) goto L_10b9c4;
L_10b984:
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_NE) goto L_10b9ec;
L_10b98c:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 168));
    if (!((cpu->regs[4] >> 14) & 1)) goto L_10b8e0;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 328));
    if ((cpu->regs[2])!=0) goto L_10ba04;
L_10b9a0:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    if (!((cpu->regs[2] >> 1) & 1)) goto L_10b9b0;
    cpu->regs[2] = cpu->regs[2] - 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[2]);
L_10b9b0:
    PB_LDR(cpu->regs[3], (cpu->regs[24] + 32));
L_10b9b4:
    cpu->regs[6] = cpu->regs[20] << 4;
    cpu->regs[4] = cpu->regs[5] + (cpu->regs[20] << 4);
    FLAG_CMP(cpu->regs[3], cpu->regs[20]);
    if (FLAG_GE) goto L_10b8f0;
L_10b9c4:
    cpu->regs[0] = 0ULL;
L_10b9c8:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_10b9e0:
    cpu->regs[20] = cpu->regs[2];
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_EQ) goto L_10b98c;
L_10b9ec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x10b9f8ULL; PB_CALL(102, cpu, tlb, cpu->regs[25]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b9c8;
    PB_LDR(cpu->regs[3], (cpu->regs[24] + 32)); PB_LDR(cpu->regs[5], (cpu->regs[24] + 32) + 8);
    goto L_10b8e0;
L_10ba04:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_10ba28;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b9a0;
L_10ba20:
    PB_LDR(cpu->regs[3], (cpu->regs[24] + 32));
    goto L_10b9b4;
L_10ba28:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10ba30ULL; PB_CALL(103, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[5], (cpu->regs[24] + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10b9a0;
    goto L_10ba20;
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 48));
    if ((cpu->regs[23])==0) goto L_10bfec;
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bc90;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10bb9c;
L_10ba84:
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 16));
    if ((cpu->regs[24])==0) goto L_10ba98;
L_10ba8c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10bbc8;
L_10ba98:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 24));
    if ((cpu->regs[23])==0) goto L_10bbe8;
L_10baa0:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10be08;
L_10baac:
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 104));
    if ((cpu->regs[24])==0) goto L_10be28;
L_10bab4:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10bda4;
L_10bac0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])!=0) goto L_10bdc4;
L_10bac8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    if ((cpu->regs[0])!=0) goto L_10bc14;
L_10bad0:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 80));
    if ((cpu->regs[23])==0) goto L_10bddc;
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_NE) goto L_10bc40;
L_10bae8:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10bd1c;
L_10baf4:
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 32));
    if ((cpu->regs[24])==0) goto L_10bd3c;
L_10bafc:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10bd80;
L_10bb08:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])!=0) goto L_10bd60;
L_10bb10:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    if ((cpu->regs[0])!=0) goto L_10bf08;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    if ((cpu->regs[0])!=0) goto L_10bc7c;
L_10bb28:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    if ((cpu->regs[0])!=0) goto L_10bf50;
L_10bb30:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 40));
    if ((cpu->regs[19])==0) goto L_10bb54;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_NE) goto L_10bcfc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_10bb6c;
L_10bb54:
    cpu->regs[0] = 0ULL;
L_10bb58:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_10bb6c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10be60;
L_10bb74:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10bb54;
    cpu->regs[1] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[1]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_10bb9c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10be7c;
L_10bba4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10ba84;
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[23] + -8), cpu->regs[0]);
    if ((cpu->regs[24])==0) goto L_10ba98;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 14) & 1)) goto L_10ba98;
L_10bbc8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10be44;
L_10bbd0:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10ba98;
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[24] + -8), cpu->regs[0]);
    if ((cpu->regs[23])!=0) goto L_10baa0;
L_10bbe8:
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 104));
    if ((cpu->regs[24])==0) goto L_10be28;
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_EQ) goto L_10bab4;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bc0cULL; PB_CALL(104, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10bcdc;
    goto L_10bb58;
L_10bc14:
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_EQ) goto L_10bdd0;
L_10bc24:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bc2cULL; PB_CALL(105, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 80));
    if ((cpu->regs[23])==0) goto L_10bddc;
    /* nop */
    /* nop */
L_10bc40:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bc4cULL; PB_CALL(106, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_10bd3c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bc60ULL; PB_CALL(107, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
L_10bc64:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])!=0) goto L_10bf38;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])!=0) goto L_10bf08;
L_10bc74:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])==0) goto L_10bb28;
L_10bc7c:
    cpu->regs[21] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_NE) goto L_10bf28;
    cpu->regs[30] = PB_BASE + 0x10bc8cULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x108700ULL);
    goto L_10bb28;
L_10bc90:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x10bc9cULL; PB_CALL(109, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_10bfd0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bcb0ULL; PB_CALL(110, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
L_10bcb4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_10bbe8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bcc4ULL; PB_CALL(111, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
L_10bcc8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])==0) goto L_10be28;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bcd8ULL; PB_CALL(112, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
L_10bcdc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_10bac8;
L_10bce4:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bcecULL; PB_CALL(113, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    if ((cpu->regs[0])==0) goto L_10bad0;
    goto L_10bc24;
L_10bcfc:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[16] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_10bd1c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10beb4;
L_10bd24:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10baf4;
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[23] + -8), cpu->regs[0]);
    if ((cpu->regs[24])!=0) goto L_10bafc;
L_10bd3c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])==0) goto L_10bb10;
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_NE) goto L_10bf38;
    /* nop */
    /* nop */
    /* nop */
L_10bd60:
    cpu->regs[30] = PB_BASE + 0x10bd64ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x108700ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_10bc74;
L_10bd6c:
    cpu->regs[30] = PB_BASE + 0x10bd70ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x108700ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])==0) goto L_10bb28;
    cpu->regs[30] = PB_BASE + 0x10bd7cULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x108700ULL);
    goto L_10bb28;
L_10bd80:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10be98;
L_10bd88:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + -8));
    if (!((cpu->regs[1] >> 1) & 1)) goto L_10bb08;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    cpu->regs[1] = cpu->regs[1] - 4ULL;
    PB_STR((cpu->regs[24] + -8), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_10bb10;
    goto L_10bd60;
L_10bda4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10beec;
L_10bdac:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + -8));
    if (!((cpu->regs[1] >> 1) & 1)) goto L_10bac0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[1] = cpu->regs[1] - 4ULL;
    PB_STR((cpu->regs[24] + -8), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_10bac8;
L_10bdc4:
    cpu->regs[30] = PB_BASE + 0x10bdc8ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x108700ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    if ((cpu->regs[0])==0) goto L_10bad0;
L_10bdd0:
    cpu->regs[30] = PB_BASE + 0x10bdd4ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x108700ULL);
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 80));
    if ((cpu->regs[23])!=0) goto L_10bae8;
L_10bddc:
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 32));
    if ((cpu->regs[24])==0) goto L_10bd3c;
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_EQ) goto L_10bafc;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10be00ULL; PB_CALL(119, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10bc64;
    goto L_10bb58;
L_10be08:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_10bed0;
L_10be10:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_10baac;
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 104));
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[23] + -8), cpu->regs[0]);
    if ((cpu->regs[24])!=0) goto L_10bab4;
L_10be28:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_10bac8;
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_NE) goto L_10bce4;
    goto L_10bdc4;
L_10be44:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bf60;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10bbd0;
    goto L_10ba98;
L_10be60:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bfa0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10bb74;
    goto L_10bb54;
L_10be7c:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bf90;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10bba4;
    goto L_10ba84;
L_10be98:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bf80;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10bd88;
    goto L_10bb08;
L_10beb4:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bf70;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10bd24;
    goto L_10baf4;
L_10bed0:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bfc0;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10be10;
    goto L_10baac;
L_10beec:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bfb0;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10bdac;
    goto L_10bac0;
L_10bf08:
    cpu->regs[21] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_EQ) goto L_10bd6c;
L_10bf14:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bf1cULL; PB_CALL(120, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])==0) goto L_10bb28;
L_10bf28:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bf30ULL; PB_CALL(121, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10bb28;
    goto L_10bb58;
L_10bf38:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bf40ULL; PB_CALL(122, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb58;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_10bc74;
    goto L_10bf14;
L_10bf50:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bf58ULL; PB_CALL(123, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10bb30;
    goto L_10bb58;
L_10bf60:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x10bf68ULL; PB_CALL(124, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bbd0;
    goto L_10ba98;
L_10bf70:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x10bf78ULL; PB_CALL(125, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bd24;
    goto L_10baf4;
L_10bf80:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x10bf88ULL; PB_CALL(126, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bd88;
    goto L_10bb08;
L_10bf90:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x10bf98ULL; PB_CALL(127, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bba4;
    goto L_10ba84;
L_10bfa0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10bfa8ULL; PB_CALL(128, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bb74;
    goto L_10bb54;
L_10bfb0:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x10bfb8ULL; PB_CALL(129, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10bdac;
    goto L_10bac0;
L_10bfc0:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x10bfc8ULL; PB_CALL(130, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10be10;
    goto L_10baac;
L_10bfd0:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 24));
    if ((cpu->regs[23])==0) goto L_10bbe8;
L_10bfd8:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x10bfe4ULL; PB_CALL(131, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10bcc8;
    goto L_10bb58;
L_10bfec:
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    if ((cpu->regs[24])==0) goto L_10c018;
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_10ba8c;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x10c010ULL; PB_CALL(132, cpu, tlb, cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_10bcb4;
    goto L_10bb58;
L_10c018:
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 24));
    if ((cpu->regs[23])==0) goto L_10bbe8;
    cpu->regs[21] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[21] + 1664ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_10bfd8;
    goto L_10baa0;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_EQ) goto L_10c0f8;
    cpu->regs[20] = PB_BASE + 0x10c000ULL;
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1] | 1ULL;
    cpu->regs[20] = cpu->regs[20] + 288ULL;
    goto L_10c0ac;
L_10c07c:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 184));
    cpu->regs[30] = PB_BASE + 0x10c088ULL; PB_CALL(133, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 0) + 8);
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[23];
    cpu->regs[0] = cpu->regs[0] & 18446744073709551613ULL;
    PB_STR((cpu->regs[19] + 8), cpu->regs[0]);
    FLAG_CMP(cpu->regs[24], cpu->regs[1]);
    if (FLAG_EQ) goto L_10c0f8;
L_10c0a4:
    cpu->regs[23] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[1];
L_10c0ac:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19] + 16ULL;
    FLAG_CMP(0ULL, cpu->regs[3]);
    if (FLAG_NE) goto L_10c07c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = cpu->regs[19] | 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[0] & 18446744073709551612ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[2]);
    cpu->regs[3] = cpu->regs[3] | cpu->regs[0];
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[19] + 0), cpu->regs[22]); PB_STR((cpu->regs[19] + 0) + 8, cpu->regs[3]);
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    PB_STR((cpu->regs[21] + 8), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[23];
    FLAG_CMP(cpu->regs[24], cpu->regs[1]);
    if (FLAG_NE) goto L_10c0a4;
L_10c0f8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[24] + 8), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[0] & 18446744073709551614ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    /* nop */
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 168));
    if (((cpu->regs[3] >> 14) & 1)) goto L_10c134;
    cpu->regs[0] = 0ULL;
    return;
L_10c134:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 328));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[2])!=0) goto L_10c18c;
L_10c14c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    if (((cpu->regs[0] >> 1) & 1)) goto L_10c164;
L_10c154:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_10c164:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -16));
    if (((cpu->regs[2] >> 0) & 1)) goto L_10c1a8;
    FLAG_CMP(0ULL, cpu->regs[0]);
    if (FLAG_NE) goto L_10c154;
    cpu->regs[0] = cpu->regs[0] | 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_10c18c:
    cpu->regs[3] = PB_BASE + 0xe2000ULL;
    cpu->regs[3] = cpu->regs[3] + 1792ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_10c1fc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 9) & 1)) goto L_10c14c;
    goto L_10c154;
L_10c1a8:
    cpu->regs[5] = cpu->regs[2] & 18446744073709551614ULL;
    cpu->regs[0] = cpu->regs[0] & 18446744073709551612ULL;
    cpu->regs[4] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 8));
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[3] & 3ULL;
    cpu->regs[0] = cpu->regs[2] | cpu->regs[0];
    PB_STR((cpu->regs[5] + 8), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_STR((cpu->regs[2] + 0), cpu->regs[4]);
    PB_STR((cpu->regs[19] + -16), cpu->regs[1]);
    PB_STR((cpu->regs[1] + 8), cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    goto L_10c154;
L_10c1fc:
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x10c204ULL; PB_CALL(134, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[1], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_10c14c;
    goto L_10c154;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_10c39c;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10c2bc;
L_10c244:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10c2f0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(7ULL)));
    if (FLAG_EQ) goto L_10c2d4;
L_10c264:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10c3b0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10c31c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_10c2d4;
L_10c28c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_10c3a8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_10c348;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(23ULL)));
    if (FLAG_EQ) goto L_10c2d4;
L_10c2b4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_10c2bc:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_10c2c0:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
L_10c2c8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_10c2d4:
    cpu->regs[2] = cpu->regs[20];
L_10c2d8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    goto L_10c2c8;
L_10c2f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10c2f8ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10c370;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(7ULL)));
    if (FLAG_EQ) goto L_10c2d8;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_10c264;
L_10c31c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10c324ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10c380;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_10c2d8;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    goto L_10c28c;
L_10c348:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x10c350ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_10c390;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(23ULL)));
    if (FLAG_NE) goto L_10c2b4;
    goto L_10c2d8;
L_10c370:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_10c264;
L_10c380:
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[0];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_10c28c;
L_10c390:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_10c2b4;
L_10c39c:
    cpu->regs[30] = PB_BASE + 0x10c3a0ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_10c244;
L_10c3a8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    goto L_10c2bc;
L_10c3b0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_10c2c0;
    /* nop */
}
