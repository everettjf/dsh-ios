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

void ft_PyOS_strtoul(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = cpu->regs[0];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11c230;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2272));
    PB_LDRW(cpu->regs[5], (cpu->regs[4] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 2)));
    if (((cpu->regs[5] >> 3) & 1)) goto L_11c144;
L_11be4c:
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_11c16c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_11beec;
L_11be58:
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_11bf54;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]))));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_11bee0;
    PB_LDRB(cpu->regs[5], (cpu->regs[3] + 1));
    cpu->regs[4] = 19ULL;
    cpu->regs[2] = 10ULL;
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]))));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_11bf4c;
L_11be90:
    PB_LDRB(cpu->regs[6], (cpu->regs[3] + 2));
    cpu->regs[0] = cpu->regs[5] + (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[0];
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 2ULL));
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[6]))));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_GE) goto L_11bed4;
L_11beac:
    cpu->regs[7] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
L_11beb0:
    cpu->regs[6] = cpu->regs[5];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_11c1c0;
    cpu->regs[3] += 1; PB_LDRB(cpu->regs[5], cpu->regs[3]);
    cpu->regs[0] = cpu->regs[7] * cpu->regs[0] + cpu->regs[6];
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - 1ULL));
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]))));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_LT) goto L_11beb0;
L_11bed4:
    if ((cpu->regs[1])==0) goto L_11c2b0;
L_11bed8:
    PB_STR((cpu->regs[1] + 0), cpu->regs[3]);
    return;
L_11bee0:
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[1])!=0) goto L_11bed8;
    return;
L_11beec:
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 1));
    cpu->regs[6] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] - 66ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(54ULL)));
    if (FLAG_HI) goto L_11bf40;
    cpu->regs[5] = 1ULL;
    cpu->regs[0] = cpu->regs[5] << (cpu->regs[0] & 63);
    FLAG_CMP((cpu->regs[0]) & (4294967297ULL), 0);
    if (FLAG_NE) goto L_11c054;
    FLAG_CMP((cpu->regs[0]) & (35184372097024ULL), 0);
    if (FLAG_NE) goto L_11c00c;
    FLAG_CMP((cpu->regs[0]) & (18014398513676288ULL), 0);
    if (FLAG_NE) goto L_11bfac;
L_11bf24:
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 2)));
    if (((cpu->regs[0] >> 3) & 1)) goto L_11c348;
L_11bf2c:
    if ((cpu->regs[1])==0) goto L_11bf34;
    PB_STR((cpu->regs[1] + 0), cpu->regs[6]);
L_11bf34:
    cpu->regs[0] = 0ULL;
    return;
L_11bf3c:
    cpu->regs[6] += 1; PB_LDRB(cpu->regs[2], cpu->regs[6]);
L_11bf40:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(48ULL)));
    if (FLAG_NE) goto L_11bf24;
    goto L_11bf3c;
L_11bf4c:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_11bed4;
L_11bf54:
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    cpu->regs[4] = 19ULL;
    cpu->regs[2] = 10ULL;
L_11bf64:
    cpu->regs[3] += 1; PB_LDRB(cpu->regs[0], cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_11bf64;
L_11bf70:
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + ((uint64_t)(uint32_t)(cpu->regs[0]))));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_GE) goto L_11bee0;
    cpu->regs[6] = cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_11c128;
    PB_LDRB(cpu->regs[5], (cpu->regs[3] + 1));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_GE) goto L_11bed4;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_11c0ac;
    cpu->regs[3] = cpu->regs[6];
    goto L_11be90;
L_11bfac:
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_HI) goto L_11bf2c;
    cpu->regs[4] = cpu->regs[3] + 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_11bffc;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 3));
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(15ULL)));
    if (FLAG_HI) goto L_11bff4;
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[2] = 16ULL;
    cpu->regs[4] = cpu->regs[2];
    goto L_11be90;
L_11bff4:
    cpu->regs[3] = cpu->regs[3] + 3ULL;
    goto L_11bed4;
L_11bffc:
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[2] = 16ULL;
    cpu->regs[4] = cpu->regs[2];
    goto L_11bf64;
L_11c00c:
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[4], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_11bf2c;
    cpu->regs[2] = cpu->regs[3] + 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_11c09c;
    PB_LDRB(cpu->regs[4], (cpu->regs[3] + 3));
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + cpu->regs[4]));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_11bff4;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[4] = 21ULL;
    cpu->regs[2] = 8ULL;
    goto L_11be90;
L_11c054:
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[4], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_11bf2c;
    cpu->regs[2] = cpu->regs[3] + 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_11c2cc;
    PB_LDRB(cpu->regs[4], (cpu->regs[3] + 3));
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + cpu->regs[4]));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_11bff4;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[4] = 64ULL;
    cpu->regs[2] = 2ULL;
    goto L_11be90;
L_11c09c:
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[4] = 21ULL;
    cpu->regs[2] = 8ULL;
    goto L_11bf64;
L_11c0ac:
    cpu->regs[4] = PB_BASE + 0x2b7000ULL;
    cpu->regs[4] = cpu->regs[4] + 1840ULL;
    cpu->regs[4] = cpu->regs[4] + 3568ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3)));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LS) goto L_11c108;
L_11c0c4:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[1])!=0) goto L_11c0d8;
    goto L_11c0ec;
L_11c0d4:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
L_11c0d8:
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 0));
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_LT) goto L_11c0d4;
    PB_STR((cpu->regs[1] + 0), cpu->regs[3]);
L_11c0ec:
    cpu->regs[30] = PB_BASE + 0x11c0f0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[2] = 34ULL;
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
    return;
L_11c108:
    PB_LDRB(cpu->regs[4], (cpu->regs[6] + 2));
    cpu->regs[0] = cpu->regs[5] + (uint64_t)(uint32_t)cpu->regs[0] * (uint64_t)(uint32_t)cpu->regs[2];
    cpu->regs[3] = cpu->regs[6] + 2ULL;
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + cpu->regs[4]));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_GE) goto L_11bed4;
    cpu->regs[4] = 4294967295ULL;
    goto L_11beac;
L_11c128:
    if (FLAG_NE) goto L_11c0c4;
    PB_LDRB(cpu->regs[4], (cpu->regs[3] + 1));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRB(cpu->regs[4], (cpu->regs[8] + cpu->regs[4]));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_LT) goto L_11c0c4;
    goto L_11bed4;
L_11c144:
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 1));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11c164;
L_11c150:
    cpu->regs[5] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDRW(cpu->regs[5], (cpu->regs[4] + (cpu->regs[5] << 2)));
    if (!((cpu->regs[5] >> 3) & 1)) goto L_11be4c;
    cpu->regs[3] += 1; PB_LDRB(cpu->regs[0], cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11c150;
L_11c164:
    cpu->regs[0] = 0ULL;
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_11be58;
L_11c16c:
    if (((cpu->regs[2] >> 31) & 1)) goto L_11c23c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(16ULL)));
    if (FLAG_EQ) goto L_11c20c;
    if (FLAG_GT) goto L_11c18c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_11c2dc;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(8ULL)));
    if (FLAG_EQ) goto L_11c280;
L_11c18c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] - 2ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(34ULL)));
    if (FLAG_HI) goto L_11c23c;
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[0] = cpu->regs[0] + 3408ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 2)));
L_11c1b0:
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_NE) goto L_11bf70;
    goto L_11bf64;
L_11c1c0:
    cpu->regs[4] = PB_BASE + 0x2b7000ULL;
    cpu->regs[4] = cpu->regs[4] + 1840ULL;
    cpu->regs[6] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[4] = cpu->regs[4] + 3568ULL;
    if (FLAG_NE) goto L_11c0c4;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + (cpu->regs[6] << 3)));
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_LO) goto L_11c0c4;
    cpu->regs[6] = cpu->regs[6] * cpu->regs[0];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[5] = cpu->regs[5] + cpu->regs[6]; FLAG_CMP(cpu->regs[5], 0);
    cpu->regs[0] = cpu->regs[5];
    if (FLAG_HS) goto L_11c0c4;
    cpu->regs[3] += 1; PB_LDRB(cpu->regs[5], cpu->regs[3]);
    PB_LDRB(cpu->regs[5], (cpu->regs[8] + cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_GE) goto L_11bed4;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    goto L_11c1c0;
L_11c20c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_EQ) goto L_11c248;
L_11c214:
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
L_11c21c:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[0] = cpu->regs[0] + 3408ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 2)));
    goto L_11c1b0;
L_11c230:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_11c2b4;
    if (FLAG_GE) goto L_11c358;
L_11c23c:
    if ((cpu->regs[1])==0) goto L_11bf34;
    PB_STR((cpu->regs[1] + 0), cpu->regs[3]);
    goto L_11bf34;
L_11c248:
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 1));
    cpu->regs[4] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967263ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(88ULL)));
    if (FLAG_NE) goto L_11c2a0;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_HI) goto L_11c314;
L_11c278:
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    goto L_11c21c;
L_11c280:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_NE) goto L_11c214;
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 1));
    cpu->regs[4] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967263ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(79ULL)));
    if (FLAG_EQ) goto L_11c320;
L_11c2a0:
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    cpu->regs[3] = cpu->regs[4];
    goto L_11c21c;
L_11c2b0:
    return;
L_11c2b4:
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    cpu->regs[0] = 0ULL;
    cpu->regs[4] = 19ULL;
    cpu->regs[2] = 10ULL;
    goto L_11bf70;
L_11c2cc:
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[4] = 64ULL;
    cpu->regs[2] = 2ULL;
    goto L_11bf64;
L_11c2dc:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(48ULL)));
    if (FLAG_NE) goto L_11c214;
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 1));
    cpu->regs[4] = cpu->regs[3] + 1ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967263ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(66ULL)));
    if (FLAG_NE) goto L_11c340;
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_11c278;
L_11c314:
    if ((cpu->regs[1])==0) goto L_11bf34;
    PB_STR((cpu->regs[1] + 0), cpu->regs[4]);
    goto L_11bf34;
L_11c320:
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3352));
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 2));
    PB_LDRB(cpu->regs[0], (cpu->regs[8] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(7ULL)));
    if (FLAG_HI) goto L_11c314;
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    goto L_11c21c;
L_11c340:
    cpu->regs[3] = cpu->regs[4];
    goto L_11c21c;
L_11c348:
    cpu->regs[6] += 1; PB_LDRB(cpu->regs[0], cpu->regs[6]);
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + (cpu->regs[0] << 2)));
    if (!((cpu->regs[0] >> 3) & 1)) goto L_11bf2c;
    goto L_11c348;
L_11c358:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(16ULL)));
    if (FLAG_EQ) goto L_11c214;
    if (FLAG_GT) goto L_11c18c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_11c214;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(8ULL)));
    if (FLAG_NE) goto L_11c18c;
    goto L_11c214;
    /* nop */
    /* nop */
    SP = SP - 80ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 944));
    PB_STR((SP + 64), cpu->regs[21]);
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if ((cpu->regs[19])==0) goto L_11c500;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_11c490;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_STRW((cpu->regs[19] + 0), cpu->regs[2]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2680));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_11c4a4;
L_11c3dc:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_11c4e8;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_11c470;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11c470;
L_11c404:
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11c410ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdd360ULL);
    PB_LDR(cpu->regs[20], (SP + 16));
    if ((cpu->regs[20])==0) goto L_11c4d4;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_11c4d8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_11c43c;
L_11c430:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_11c520;
L_11c43c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_11c4e4;
    PB_LDR(cpu->regs[21], (SP + 64));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_11c470:
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x11c47cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_11c4d4;
    PB_LDR(cpu->regs[1], (SP + 8));
    goto L_11c404;
L_11c490:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2680));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_11c3dc;
L_11c4a4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11c4acULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_11c4d8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3544));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x11c4c8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x121d80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_11c4d4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11c4d4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d2f00ULL);
L_11c4d4:
    cpu->regs[20] = 0ULL;
L_11c4d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_11c430;
    goto L_11c43c;
L_11c4e4:
    cpu->regs[30] = PB_BASE + 0x11c4e8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_11c4e8:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 1760ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x11c4fcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x9bb50ULL);
    goto L_11c4d8;
L_11c500:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3296));
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + 1000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x11c51cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_11c43c;
L_11c520:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11c528ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11c43c;
}
