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

void ft__PyList_Extend(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    goto L_136924;
L_136924:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3312));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    cpu->regs[0] = cpu->regs[20];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[19]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_136b18;
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 3336ULL;
    cpu->regs[30] = PB_BASE + 0x136970ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x136da0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_136c48;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    if ((cpu->regs[20])==0) goto L_136cb4;
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 16) + 8);
    if ((cpu->regs[0])!=0) goto L_136c80;
    cpu->regs[22] = cpu->regs[20] + 1ULL;
    cpu->regs[0] = 1152921504606846975ULL;
    cpu->regs[22] = cpu->regs[22] & 18446744073709551614ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_HI) goto L_136d50;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = cpu->regs[22] << 3;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[0] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x1369b4ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_136d50;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[0]);
    PB_STR((cpu->regs[19] + 32), cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 25) & 1)) goto L_136ca4;
L_1369cc:
    cpu->regs[3] = cpu->regs[21] + 24ULL;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_136ae0;
L_1369d8:
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    cpu->regs[1] = cpu->regs[23] << 3;
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[23] << 3);
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_136c18;
L_1369f0:
    PB_STR((cpu->regs[0] + cpu->regs[1]), cpu->regs[5]);
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_136ae0;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 8));
    cpu->regs[6] = cpu->regs[1] + 8ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_136c58;
L_136a10:
    PB_STR((cpu->regs[0] + cpu->regs[6]), cpu->regs[5]);
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_136ae0;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 16));
    cpu->regs[6] = cpu->regs[1] + 16ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_136c60;
L_136a30:
    PB_STR((cpu->regs[0] + cpu->regs[6]), cpu->regs[5]);
    FLAG_CMP(cpu->regs[20], 3ULL);
    if (FLAG_EQ) goto L_136ae0;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 24));
    cpu->regs[6] = cpu->regs[1] + 24ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_136c50;
L_136a50:
    PB_STR((cpu->regs[0] + cpu->regs[6]), cpu->regs[5]);
    FLAG_CMP(cpu->regs[20], 4ULL);
    if (FLAG_EQ) goto L_136ae0;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 32));
    cpu->regs[6] = cpu->regs[1] + 32ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_136c68;
L_136a70:
    PB_STR((cpu->regs[0] + cpu->regs[6]), cpu->regs[5]);
    FLAG_CMP(cpu->regs[20], 5ULL);
    if (FLAG_EQ) goto L_136ae0;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 40));
    cpu->regs[6] = cpu->regs[1] + 40ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_136c70;
L_136a90:
    PB_STR((cpu->regs[0] + cpu->regs[6]), cpu->regs[5]);
    FLAG_CMP(cpu->regs[20], 6ULL);
    if (FLAG_EQ) goto L_136ae0;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 48));
    cpu->regs[1] = cpu->regs[1] + 48ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_136c78;
L_136ab0:
    PB_STR((cpu->regs[0] + cpu->regs[1]), cpu->regs[5]);
    FLAG_CMP(cpu->regs[20], 7ULL);
    if (FLAG_EQ) goto L_136ae0;
    cpu->regs[1] = 7ULL;
L_136ac0:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_136b10;
L_136ad0:
    PB_STR((cpu->regs[4] + (cpu->regs[1] << 3)), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_NE) goto L_136ac0;
L_136ae0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_136af4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_136d40;
L_136af4:
    PB_LDR(cpu->regs[23], (SP + 48));
L_136af8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_136b00:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_136b10:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
    goto L_136ad0;
L_136b18:
    cpu->regs[30] = PB_BASE + 0x136b1cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_136c48;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 8ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 224));
    cpu->regs[30] = PB_BASE + 0x136b3cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x141b04ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_136c30;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[1] = 9223372036854775807ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_LT) goto L_136bb4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])!=0) goto L_136d10;
    if ((cpu->regs[0])==0) goto L_136bb4;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[1] = 1152921504606846975ULL;
    cpu->regs[20] = cpu->regs[0] & 18446744073709551614ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_HI) goto L_136d6c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = cpu->regs[20] << 3;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 136)); PB_LDR(cpu->regs[2], (cpu->regs[0] + 136) + 8);
    cpu->regs[30] = PB_BASE + 0x136b88ULL; PB_CALL(5, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_136d6c;
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]); PB_STR((cpu->regs[19] + 24) + 8, cpu->regs[20]);
    goto L_136bb4;
L_136b94:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_LE) goto L_136cd0;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[2] + (cpu->regs[21] << 3)), cpu->regs[0]);
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
L_136bb4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x136bbcULL; PB_CALL(6, cpu, tlb, cpu->regs[23]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_136b94;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x136bd8ULL; PB_CALL(7, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])!=0) goto L_136cec;
L_136be4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_136c20;
L_136bf4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_136af4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_136af4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x136c10ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_136af8;
L_136c18:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_1369f0;
L_136c20:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x136c28ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe5550ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_136bf4;
L_136c30:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_136c44;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_136d2c;
L_136c44:
    PB_LDR(cpu->regs[23], (SP + 48));
L_136c48:
    cpu->regs[0] = 0ULL;
    goto L_136b00;
L_136c50:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_136a50;
L_136c58:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_136a10;
L_136c60:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_136a30;
L_136c68:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_136a70;
L_136c70:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_136a90;
L_136c78:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_136ab0;
L_136c80:
    cpu->regs[1] = cpu->regs[23] + cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x136c8cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe5550ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_136d74;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 25) & 1)) goto L_1369cc;
L_136ca4:
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 24));
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_GT) goto L_1369d8;
    goto L_136ae0;
L_136cb4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_136af8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_136af8;
    cpu->regs[30] = PB_BASE + 0x136cccULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_136af8;
L_136cd0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x136cd8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe5550ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_136d60;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[0] + (cpu->regs[21] << 3)), cpu->regs[20]);
    goto L_136bb4;
L_136cec:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_136be4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x136d04ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_136c30;
    cpu->regs[30] = PB_BASE + 0x136d0cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_136be4;
L_136d10:
    cpu->regs[1] = cpu->regs[0] + cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x136d1cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe5550ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_136c30;
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_136bb4;
L_136d2c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x136d34ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 0ULL;
    goto L_136b00;
L_136d40:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x136d48ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_136af8;
L_136d50:
    cpu->regs[30] = PB_BASE + 0x136d54ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 0ULL;
    goto L_136b00;
L_136d60:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x136d68ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c408ULL);
    goto L_136c30;
L_136d6c:
    cpu->regs[30] = PB_BASE + 0x136d70ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_136c30;
L_136d74:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_136c44;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_136c44;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x136d90ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 0ULL;
    goto L_136b00;
    /* nop */
}
