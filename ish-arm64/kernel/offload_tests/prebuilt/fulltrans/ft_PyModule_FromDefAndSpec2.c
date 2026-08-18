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

void ft_PyModule_FromDefAndSpec2(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1a2a44ULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[2];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[24], (cpu->regs[3] + 16));
    cpu->regs[30] = PB_BASE + 0x1a2a60ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x18f580ULL);
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1a2a70ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11d200ULL);
    if ((cpu->regs[0])==0) goto L_1a2bf8;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1a2a80ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a2bd4;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1a2a90ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18f600ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a2bd4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 56));
    if (((cpu->regs[1] >> 63) & 1)) goto L_1a2d50;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 72));
    cpu->regs[23] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = 0ULL;
L_1a2ab4:
    if ((cpu->regs[2])==0) goto L_1a2ae8;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 0));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_1a2ae8;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_1a2b74;
    if (FLAG_GT) goto L_1a2cfc;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1a2cec;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1a2cfc;
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] + 16ULL;
    goto L_1a2ab4;
L_1a2ae8:
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a2ba8;
    if ((cpu->regs[4])==0) goto L_1a2bb0;
    FLAG_CMP(cpu->regs[4], 2ULL);
    if (FLAG_NE) goto L_1a2ba8;
L_1a2af8:
    if ((cpu->regs[25])!=0) goto L_1a2c84;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a2b04ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18f6c0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a2bd0;
L_1a2b0c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3536));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a2b1cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a2c08;
    PB_STR((cpu->regs[20] + 24), cpu->regs[19]); PB_STR((cpu->regs[20] + 24) + 8, 0ULL);
L_1a2b24:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 64));
    if ((cpu->regs[2])==0) goto L_1a2b3c;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a2b38ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18f9d0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a2c00;
L_1a2b3c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    if ((cpu->regs[1])==0) goto L_1a2b50;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a2b4cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18fba0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a2c00;
L_1a2b50:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1a2b88;
L_1a2b58:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64));
L_1a2b60:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1a2b74:
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1a2cc4;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] + 16ULL;
    goto L_1a2ab4;
L_1a2b88:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1a2b58;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a2b9cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1a2b60;
L_1a2ba8:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 392));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a2af8;
L_1a2bb0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_EQ) goto L_1a2af8;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1a2bccULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1f2ea0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1a2af8;
L_1a2bd0:
    PB_LDR(cpu->regs[25], (SP + 64));
L_1a2bd4:
    cpu->regs[20] = 0ULL;
L_1a2bd8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1a2bec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1a2c78;
L_1a2bec:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a2bf4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1a2bf8:
    cpu->regs[20] = 0ULL;
    goto L_1a2b60;
L_1a2c00:
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2bd8;
L_1a2c08:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_1a2c54;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])!=0) goto L_1a2c54;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])!=0) goto L_1a2c54;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])!=0) goto L_1a2c54;
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_1a2b24;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 1992ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a2c4cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2bd8;
L_1a2c54:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 1928ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a2c70ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2bd8;
L_1a2c78:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a2c80ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1a2bec;
L_1a2c84:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a2c90ULL; PB_CALL(16, cpu, tlb, cpu->regs[25]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1a2c98ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[20])==0) goto L_1a2d24;
    if ((cpu->regs[0])==0) goto L_1a2b0c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = cpu->regs[1] + 1872ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a2cbcULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xa6154ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2bd8;
L_1a2cc4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1704ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a2ce4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2bd8;
L_1a2cec:
    if ((cpu->regs[25])!=0) goto L_1a2d74;
    PB_LDR(cpu->regs[25], (cpu->regs[2] + 8));
    cpu->regs[2] = cpu->regs[2] + 16ULL;
    goto L_1a2ab4;
L_1a2cfc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1768ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a2d1cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2bd8;
L_1a2d24:
    if ((cpu->regs[0])!=0) goto L_1a2bd0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a2d48ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2bd8;
L_1a2d50:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1592ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a2d70ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1a2bd8;
L_1a2d74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1664ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a2d94ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_1a2bd8;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1a2db4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1a2dd8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1a2dd8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1a2dd8;
    cpu->regs[30] = PB_BASE + 0x1a2dd8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1a2dd8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3536));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1a2e1cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a2e50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a2e28ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x190cccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a2e50;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a2e38ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    if ((cpu->regs[0])!=0) goto L_1a2e50;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(29, cpu, tlb, PB_BASE + 0x1a2e60ULL); return; };
L_1a2e50:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
