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

void ft__PyUnicode_InternImmortal(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xdb75cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdb76cULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_db76c:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    if ((cpu->regs[1])==0) goto L_db97c;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[21] = ((uint32_t)(cpu->regs[2] & 255ULL));
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 168));
    FLAG_CMP((cpu->regs[4]) & (268435456ULL), 0);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_db7bc;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 32));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] & 3ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_db7d4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_db938;
L_db7bc:
    cpu->regs[22] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_db7c4:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_db7d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 32));
    if (((cpu->regs[0] >> 7) & 1)) goto L_db924;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_db984;
L_db7f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + (16ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 10104));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0xdb808ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])!=0) goto L_db8a4;
L_db80c:
    cpu->regs[0] = cpu->regs[20] + (88ULL << 12);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22488));
    cpu->regs[30] = PB_BASE + 0xdb820ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe09a4ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_db960;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_GE) { FLAG_CMP(cpu->regs[21], 0ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[20] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_db8f4;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_db958;
L_db848:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_db86c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_db86c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xdb86cULL; PB_CALL(4, cpu, tlb, cpu->regs[1]);
L_db86c:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_db8dc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 3ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_db8dc;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 32));
L_db884:
    cpu->regs[1] = 2ULL;
    cpu->regs[2] = 4294967295ULL;
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] & ~0x3ULL) | ((cpu->regs[1] >> 0) & 0x3ULL))));
    PB_STR((cpu->regs[22] + 0), cpu->regs[2]);
    PB_STRW((cpu->regs[22] + 32), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_db7c4;
L_db8a4:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 24));
    if ((cpu->regs[22])==0) goto L_db80c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_db8d0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_db8d0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xdb8d0ULL; PB_CALL(5, cpu, tlb, cpu->regs[1]);
L_db8d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_db96c;
L_db8dc:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_db8f4:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_db904;
    cpu->regs[0] = cpu->regs[0] - 2ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
L_db904:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 32));
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_db884;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] & ~0x3ULL) | ((cpu->regs[1] >> 0) & 0x3ULL))));
    PB_STRW((cpu->regs[22] + 32), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_db7c4;
L_db924:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x187988ULL); return; };
L_db938:
    if (!((cpu->regs[21] >> 0) & 1)) goto L_db7bc;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 2ULL;
    cpu->regs[2] = 4294967295ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] & ~0x3ULL) | ((cpu->regs[1] >> 0) & 0x3ULL))));
    PB_STRW((cpu->regs[19] + 32), cpu->regs[0]);
    goto L_db7bc;
L_db958:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_db848;
L_db960:
    cpu->regs[30] = PB_BASE + 0xdb964ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_db7bc;
L_db96c:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_db7c4;
L_db97c:
    cpu->regs[22] = 0ULL;
    goto L_db7c4;
L_db984:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 28ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_db7f0;
    if (((cpu->regs[2] >> 5) & 1)) goto L_db9e0;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 56));
    do { int8_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,1); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[1] >> 31) & 1)) goto L_dba0c;
L_db9a0:
    PB_LDRB(cpu->regs[22], (cpu->regs[0] + 0));
    cpu->regs[2] = 48ULL;
    cpu->regs[1] = 61184ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[22] = cpu->regs[1] + (uint64_t)(uint32_t)cpu->regs[22] * (uint64_t)(uint32_t)cpu->regs[2];
    cpu->regs[22] = cpu->regs[22] + cpu->regs[0];
    if (((cpu->regs[23] >> 31) & 1)) goto L_db8dc;
L_db9c0:
    cpu->regs[23] = cpu->regs[23] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[23]);
    if ((cpu->regs[23])!=0) goto L_db8dc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xdb9d4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_db7c4;
L_db9e0:
    if (((cpu->regs[2] >> 6) & 1)) goto L_db9f4;
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[1] + 56),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[0] >> 31) & 1)) goto L_dba04;
    cpu->regs[0] = cpu->regs[1] + 56ULL;
    goto L_db9a0;
L_db9f4:
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[1] + 40),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    if (((cpu->regs[0] >> 31) & 1)) goto L_dba28;
    cpu->regs[0] = cpu->regs[1] + 40ULL;
    goto L_db9a0;
L_dba04:
    if (((cpu->regs[2] >> 6) & 1)) goto L_dba28;
    cpu->regs[0] = cpu->regs[1] + 56ULL;
L_dba0c:
    PB_LDRB(cpu->regs[22], (cpu->regs[0] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[22] = cpu->regs[22] + 924ULL;
    cpu->regs[22] = cpu->regs[0] + (cpu->regs[22] << 6);
    if (!((cpu->regs[23] >> 31) & 1)) goto L_db9c0;
    goto L_db8dc;
L_dba28:
    cpu->regs[0] = cpu->regs[19] + 40ULL;
    goto L_dba0c;
L_dba30:
    SP = SP - 112ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (cpu->regs[24] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_dbc3c;
    cpu->regs[1] = cpu->tls_ptr;
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xdba88ULL; PB_CALL(9, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    cpu->regs[24] = cpu->regs[24] + 24ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2520));
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2640));
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2592));
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2272));
    /* nop */
    /* nop */
L_dbac0:
    PB_LDR(cpu->regs[20], (cpu->regs[24] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_NE) goto L_dbc74;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_dbc28;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_dbd4c;
    cpu->regs[0] = cpu->regs[20] + 40ULL;
    cpu->regs[2] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_dbc10;
L_dbaf0:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_dbc28;
    cpu->regs[1] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_dbc10;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_dbc28;
    cpu->regs[1] = cpu->regs[0] + 2ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_dbc10;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 2));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_dbc28;
    cpu->regs[1] = cpu->regs[0] + 3ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_dbc10;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 3));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_dbc28;
    cpu->regs[1] = cpu->regs[0] + 4ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_dbc10;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_dbc28;
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_dbc10;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 5));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_dbc28;
    cpu->regs[1] = cpu->regs[0] + 6ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_dbc10;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 6));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_dbc28;
    cpu->regs[0] = cpu->regs[0] + 7ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_dbc10;
L_dbbec:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_dbc28;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_dbbec;
L_dbc10:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xdbc20ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdb76cULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_dbcf4;
L_dbc28:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dbac0;
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
L_dbc3c:
    cpu->regs[0] = 0ULL;
L_dbc40:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_dbd08;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 112ULL;
    return;
L_dbc74:
    FLAG_CMP(cpu->regs[0], cpu->regs[26]);
    if (FLAG_EQ) goto L_dbcd0;
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_NE) goto L_dbc28;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xdbc8cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_dbce4;
    cpu->regs[1] = SP + 4ULL;
    PB_STRW((SP + 4), 0ULL);
    cpu->regs[30] = PB_BASE + 0xdbca0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdba30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_dbd60;
    PB_LDRW(cpu->regs[0], (SP + 4));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_dbd14;
L_dbcb0:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_dbc28;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_dbc28;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xdbcccULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_dbc28;
L_dbcd0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xdbcdcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdba30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_dbc28;
L_dbce4:
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
    goto L_dbc40;
L_dbcf4:
    PB_STR((cpu->regs[24] + (cpu->regs[19] << 3)), cpu->regs[0]);
    if ((cpu->regs[22])==0) goto L_dbc28;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_dbc28;
L_dbd08:
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0xdbd14ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_dbd14:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xdbd1cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1b2528ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_dbd60;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[24] + (cpu->regs[19] << 3)), cpu->regs[1]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_dbd3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_dbd80;
L_dbd3c:
    if ((cpu->regs[22])==0) goto L_dbcb0;
L_dbd40:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_dbcb0;
L_dbd4c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    cpu->regs[2] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_dbaf0;
    goto L_dbc10;
L_dbd60:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_dbce4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_dbce4;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xdbd7cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_dbce4;
L_dbd80:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xdbd88ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if ((cpu->regs[22])==0) goto L_dbcb0;
    goto L_dbd40;
}
