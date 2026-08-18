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

void ft__PyObject_RealIsInstance(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x14b6c4ULL); return; };
    SP = SP - 80ULL;
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1f98dcULL; PB_CALL(2, cpu, tlb, cpu->regs[5]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[1] = 26600ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[23] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1f9918ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x122b00ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f9994;
    PB_LDRW(cpu->regs[0], (SP + 4));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f99c0;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f9940ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x122b8cULL);
    cpu->regs[20] = cpu->regs[0];
L_1f9944:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f9958;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f99ac;
L_1f9958:
    cpu->regs[19] = cpu->regs[20];
L_1f995c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f99bc;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_1f9994:
    cpu->regs[30] = PB_BASE + 0x1f9998ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1f995c;
    cpu->regs[0] = 26600ULL;
    cpu->regs[0] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1f99a8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c598ULL);
    goto L_1f995c;
L_1f99ac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f99b8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f995c;
L_1f99bc:
    cpu->regs[30] = PB_BASE + 0x1f99c0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f99c0:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f99d4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x12660cULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_1f9944;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_1f9a10;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1f9a0cULL; PB_CALL(10, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f9a44;
L_1f9a10:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])!=0) goto L_1f9a38;
L_1f9a18:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_1f9a44;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1f9a38:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f9a40ULL; PB_CALL(11, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f9a18;
L_1f9a44:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1f9a90;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1f9a8cULL; PB_CALL(12, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f9ab0;
L_1f9a90:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_1f9ab0;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1f9ab0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_1f9b18;
L_1f9ae8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_1f9b10;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
L_1f9afc:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_1f9b48;
L_1f9b10:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    goto L_1f9afc;
L_1f9b18:
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 440ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1f9b30ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f9ae8;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f9b48:
    SP = SP - 128ULL;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[4] = cpu->tls_ptr;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1f9b6cULL; PB_CALL(14, cpu, tlb, cpu->regs[3]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    PB_LDR(cpu->regs[4], (cpu->regs[4] + cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[20], (cpu->regs[4] + 16));
    cpu->regs[30] = PB_BASE + 0x1f9ba4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x179564ULL);
    if ((cpu->regs[0])==0) goto L_1f9d64;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2680));
    FLAG_CMP(cpu->regs[1], cpu->regs[24]);
    if (FLAG_NE) goto L_1f9bf0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])!=0) goto L_1f9bf0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1f9db8;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3672));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2592));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1f9cac;
L_1f9bf0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f9bf8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f9e98;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_1f9c40;
    goto L_1f9d84;
L_1f9c10:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f9c20ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f9c38;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f9ebc;
L_1f9c38:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f9e84;
L_1f9c40:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1f9c48ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1f9c10;
L_1f9c50:
    cpu->regs[30] = PB_BASE + 0x1f9c54ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if ((cpu->regs[0])!=0) goto L_1f9e88;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f9c74;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1f9c74;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1f9c74ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1f9c74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1f9e7c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_1f9cac:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[5] = 2ULL;
    cpu->regs[4] = 64ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[2] << 1);
    PB_STR((SP + 32), 0ULL);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[2] = (cpu->regs[5] ? (uint64_t)((int64_t)cpu->regs[2] / (int64_t)cpu->regs[5]) : 0);
    cpu->regs[2] = cpu->regs[2] | 8ULL;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    cpu->regs[2] = cpu->regs[2] | 7ULL;
    cpu->regs[2] = (((uint64_t)(cpu->regs[2])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[2])));
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - cpu->regs[2]));
    cpu->regs[30] = PB_BASE + 0x1f9cecULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe03e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f9e98;
    cpu->regs[24] = SP + 16ULL;
    cpu->regs[22] = SP + 24ULL;
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[25] = SP + 32ULL;
L_1f9d00:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f9d14ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1c8b60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f9d6c;
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1f9e74;
L_1f9d28:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[3], (SP + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1f9ec8;
L_1f9d38:
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f9d48ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdfd00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f9d00;
L_1f9d4c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f9d60;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f9ee8;
L_1f9d60:
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
L_1f9d64:
    cpu->regs[21] = 0ULL;
    goto L_1f9c74;
L_1f9d6c:
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    goto L_1f9c74;
L_1f9d74:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f9ed8;
    if (((cpu->regs[20] >> 31) & 1)) goto L_1f9e84;
L_1f9d84:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1f9d8cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f9c50;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f9da4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe97e4ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1f9d74;
    if (!((cpu->regs[20] >> 31) & 1)) goto L_1f9d84;
    goto L_1f9e84;
L_1f9db8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[5] = 2ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    cpu->regs[4] = 64ULL;
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[0] << 1);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + 10));
    PB_STR((SP + 24), 0ULL);
    cpu->regs[2] = (cpu->regs[5] ? (uint64_t)((int64_t)cpu->regs[2] / (int64_t)cpu->regs[5]) : 0);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(0ULL)));
    cpu->regs[3] = (FLAG_NE) ? 1 : 0;
    cpu->regs[2] = cpu->regs[2] | 8ULL;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    cpu->regs[2] = cpu->regs[2] | 7ULL;
    cpu->regs[2] = (((uint64_t)(cpu->regs[2])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[2])));
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - cpu->regs[2]));
    cpu->regs[30] = PB_BASE + 0x1f9e04ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe03e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f9e98;
    cpu->regs[24] = SP + 16ULL;
    cpu->regs[22] = SP + 24ULL;
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[26] = SP + 8ULL;
    cpu->regs[25] = SP + 32ULL;
L_1f9e1c:
    cpu->regs[4] = cpu->regs[26];
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f9e34ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f9d6c;
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1f9e4c;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_1f9e4c:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[3], (SP + 8));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1f9ed0;
L_1f9e5c:
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f9e6cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdfd00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f9e1c;
    goto L_1f9d4c;
L_1f9e74:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_1f9d28;
L_1f9e7c:
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1f9e84ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f9e84:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
L_1f9e88:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f9e98;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f9ef8;
L_1f9e98:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f9d64;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1f9d64;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f9eb8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f9c74;
L_1f9ebc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f9ec4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f9c38;
L_1f9ec8:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_1f9d38;
L_1f9ed0:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_1f9e5c;
L_1f9ed8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f9ee0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if (!((cpu->regs[20] >> 31) & 1)) goto L_1f9d84;
    goto L_1f9e84;
L_1f9ee8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f9ef0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    goto L_1f9d64;
L_1f9ef8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1f9f00ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f9e98;
L_1f9f04:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 72)); PB_LDRW(cpu->regs[1], (cpu->regs[0] + 72) + 4);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 72), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GT) goto L_1fa1b8;
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_1f9fec;
    if (FLAG_LS) goto L_1f9f90;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(7ULL)));
    if (FLAG_EQ) goto L_1f9fc0;
    if (FLAG_HI) goto L_1fa0d0;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_1fa07c;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[21])==0) goto L_1fa040;
    cpu->regs[22] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1f9f64:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[3] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LE) goto L_1fa040;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1f9f84ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fa1a8;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    goto L_1f9f64;
L_1f9f90:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1f9fa8;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x1f9fa0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1283a0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fa1a0;
L_1f9fa8:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[0] = 1ULL;
L_1f9fb0:
    PB_STRW((cpu->regs[19] + 72), cpu->regs[2]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f9fc0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    if ((cpu->regs[1])!=0) goto L_1fa194;
L_1f9fc8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    if ((cpu->regs[1])==0) goto L_1f9fe4;
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 40) + 4);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + 48)); PB_LDRW(cpu->regs[6], (cpu->regs[20] + 48) + 4);
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1f9fe4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1ab0e0ULL);
L_1f9fe4:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    goto L_1f9fa8;
L_1f9fec:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[21])==0) goto L_1fa038;
    cpu->regs[20] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1fa000:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[3] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_GE) goto L_1fa034;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1fa020ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1f9f04ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fa1a8;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_1fa000;
L_1fa02c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    if ((cpu->regs[1])!=0) goto L_1fa138;
L_1fa034:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
L_1fa038:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1f9fa8;
L_1fa040:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_1fa02c;
    cpu->regs[22] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1fa050:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[3] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LE) goto L_1fa02c;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1fa070ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1f9f04ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fa1a8;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    goto L_1fa050;
L_1fa07c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(5ULL)));
    if (FLAG_NE) goto L_1fa118;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x1fa08cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fa19c;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    if ((cpu->regs[22])==0) goto L_1fa158;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = 0ULL;
L_1fa0a4:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[3] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LE) goto L_1fa158;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1fa0c4ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1f9f04ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fa1a8;
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_1fa0a4;
L_1fa0d0:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(8ULL)));
    if (FLAG_NE) goto L_1f9fa8;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    if ((cpu->regs[21])==0) goto L_1fa038;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = 0ULL;
L_1fa0ec:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[3] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LE) goto L_1fa034;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1fa10cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1f9f04ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fa1a8;
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    goto L_1fa0ec;
L_1fa118:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    if ((cpu->regs[1])==0) goto L_1f9fa8;
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 40) + 4);
    cpu->regs[2] = 2ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + 48)); PB_LDRW(cpu->regs[6], (cpu->regs[20] + 48) + 4);
    cpu->regs[30] = PB_BASE + 0x1fa130ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1ab0e0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    goto L_1f9fa8;
L_1fa138:
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 40)); PB_LDRW(cpu->regs[4], (cpu->regs[20] + 40) + 4);
    cpu->regs[2] = 2ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[20] + 48)); PB_LDRW(cpu->regs[6], (cpu->regs[20] + 48) + 4);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1fa14cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1ab0e0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1f9fa8;
L_1fa158:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 32));
    if ((cpu->regs[20])==0) goto L_1fa034;
    cpu->regs[21] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1fa168:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[3] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LE) goto L_1fa034;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1fa188ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1f9f04ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1fa1a8;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_1fa168;
L_1fa194:
    cpu->regs[30] = PB_BASE + 0x1fa198ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1f9f04ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f9fc8;
L_1fa19c:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
L_1fa1a0:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_1f9fb0;
L_1fa1a8:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_1f9fb0;
L_1fa1b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3496ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1fa1d0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_1f9fb0;
}
