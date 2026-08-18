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

void ft__PyErr_NoMemory(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3000));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_22d800;
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22d7dcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x18ebe4ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22d7f0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x22d7f0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18d760ULL);
L_22d7f0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_22d800:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1960ULL;
    cpu->regs[1] = cpu->regs[1] + 2336ULL;
    cpu->regs[30] = PB_BASE + 0x22d818ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x91ebcULL);
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_22d868;
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 3ULL));
    cpu->regs[0] = 2ULL;
    cpu->regs[1] = cpu->regs[1] & 18446744073709551608ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - cpu->regs[2]));
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
L_22d85c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_22d868:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[0] = cpu->regs[1] * cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x22d87cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x12de88ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_22d85c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22d85c;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP = SP - 112ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_22daf4;
L_22d8e0:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[22], (cpu->regs[19] + 0) + 8);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x22d8f0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d53a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22daec;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[4] = 26712ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x22d910ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22dad8;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x22d924ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x14d444ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_22da84;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22d9cc;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 8));
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_NE) goto L_22da1c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_22d9ec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22d95cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x14d444ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_22da84;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22d9ec;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_22da64;
L_22d97c:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3184));
L_22d984:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22d98cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22d994ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdce4cULL);
L_22d994:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_22da14;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_22d9cc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_22db18;
L_22d9e0:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3664));
    goto L_22d984;
L_22d9ec:
    cpu->regs[3] = 33488ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[3];
    cpu->regs[1] = SP;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 0), cpu->regs[23]); PB_STR((SP + 0) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x22da0cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_22d984;
L_22da14:
    PB_STR((SP + 96), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x22da1cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_22da1c:
    cpu->regs[1] = 33488ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[1];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[1] = SP;
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 0), cpu->regs[23]); PB_STR((SP + 0) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x22da40ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[25] = SP;
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22da80;
    cpu->regs[30] = PB_BASE + 0x22da50ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1227a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22da8c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_22da6c;
    PB_LDR(cpu->regs[25], (SP + 96));
    goto L_22d984;
L_22da64:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_22d97c;
L_22da6c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22da80;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22db20;
L_22da80:
    PB_LDR(cpu->regs[25], (SP + 96));
L_22da84:
    cpu->regs[21] = 0ULL;
    goto L_22d984;
L_22da8c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22daa0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22dacc;
L_22daa0:
    cpu->regs[2] = 2ULL;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = 33488ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[0] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 0), cpu->regs[23]); PB_STR((SP + 0) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x22dac0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[25], (SP + 96));
    goto L_22d984;
L_22dacc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22dad4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22daa0;
L_22dad8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22daec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22db34;
L_22daec:
    cpu->regs[21] = 0ULL;
    goto L_22d994;
L_22daf4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2400ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x22db0cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22d8e0;
    cpu->regs[21] = 0ULL;
    goto L_22d994;
L_22db18:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_22d9e0;
L_22db20:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22db2cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 96));
    goto L_22d984;
L_22db34:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22db40ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22d994;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[6] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 2ULL));
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_22dcac;
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[7] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3288));
    cpu->regs[30] = PB_BASE + 0x22db74ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22dcb8;
L_22db78:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3288));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x22db88ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22dc8c;
L_22db8c:
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[20], (cpu->regs[7] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_22dc5c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_22dc5c;
    PB_LDR(cpu->regs[19], (cpu->regs[5] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_22dc5c;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_22dc5c;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_22dc54;
L_22dbd4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_22dc4c;
L_22dbe0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22dbf0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11ed08ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_22dc34;
L_22dbfc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_22dc18;
L_22dc04:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_22dc08:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_22dc18:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22dc04;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22dc2cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_22dc08;
L_22dc34:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22dbfc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22dc48ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22dbfc;
L_22dc4c:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_22dbe0;
L_22dc54:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_22dbd4;
L_22dc5c:
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(3ULL)));
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3184));
    cpu->regs[1] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[21] = (FLAG_EQ) ? cpu->regs[21] : cpu->regs[0];
    goto L_22dc08;
L_22dc8c:
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4056));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3632));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_22db8c;
L_22dcac:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2400));
    goto L_22dc08;
L_22dcb8:
    PB_LDR(cpu->regs[2], (cpu->regs[7] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3632));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 4056));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_22db78;
    goto L_22dcac;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[2];
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(40ULL)));
    if (FLAG_EQ) goto L_22dd40;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_EQ) goto L_22dd58;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 24));
L_22dd1c:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 176ULL;
    cpu->regs[30] = PB_BASE + 0x22dd30ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1815f0ULL);
L_22dd30:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_22dd40:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 3152ULL;
    cpu->regs[30] = PB_BASE + 0x22dd54ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1815f0ULL);
    goto L_22dd30;
L_22dd58:
    cpu->regs[4] = PB_BASE + 0x2a3000ULL;
    cpu->regs[4] = cpu->regs[4] + 2064ULL;
    goto L_22dd1c;
}
