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

void ft_PyErr_DisplayException(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_91ad0:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x7cdf4ULL); return; };
    SP = SP - 144ULL;
    cpu->regs[5] = PB_BASE + 0x5ad000ULL;
    cpu->regs[5] = cpu->regs[5] + 4048ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[4];
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    PB_LDRW(cpu->regs[27], (cpu->regs[5] + 272));
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 0));
    PB_STR((SP + 40), cpu->regs[7]);
    cpu->regs[7] = 0ULL;
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_91b3c;
L_91b28:
    FLAG_CMP(cpu->regs[26], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_91b34;
    cpu->regs[30] = PB_BASE + 0x91b34ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7ac30ULL);
L_91b34:
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x91b3cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7b690ULL);
L_91b3c:
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[2] = 1ULL;
    PB_STRW((cpu->regs[5] + 272), cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[25] = PB_BASE + 0x2a2000ULL;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_91be4;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[20] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] + 1168ULL;
    cpu->regs[2] = 20ULL;
    cpu->regs[30] = PB_BASE + 0x91b68ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x90ba8ULL);
    if ((cpu->regs[21])==0) goto L_91b9c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x91b74ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[30] = PB_BASE + 0x91b88ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1656ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x91b9cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_91b9c:
    if ((cpu->regs[20])==0) goto L_91bc0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x91ba8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[30] = PB_BASE + 0x91bbcULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_91bd4;
L_91bc0:
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1192ULL;
    cpu->regs[2] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x91bd4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_91bd4:
    cpu->regs[1] = cpu->regs[25] + 1024ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x91be4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_91be4:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 22ULL;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 1216ULL;
    cpu->regs[30] = PB_BASE + 0x91c00ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[0] = cpu->regs[23] + 24ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 0));
    if ((cpu->regs[20])==0) goto L_91c48;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 21ULL;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 1240ULL;
    cpu->regs[30] = PB_BASE + 0x91c20ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x91c30ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x90c98ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 192ULL;
    cpu->regs[30] = PB_BASE + 0x91c44ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_91cdc;
L_91c48:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 16));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_91c68;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[2] = 11ULL;
    cpu->regs[1] = cpu->regs[1] + 2488ULL;
    cpu->regs[30] = PB_BASE + 0x91c64ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_91cdc;
L_91c68:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 12));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_91c88;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[2] = 16ULL;
    cpu->regs[1] = cpu->regs[1] + 1264ULL;
    cpu->regs[30] = PB_BASE + 0x91c84ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_91cdc;
L_91c88:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 8));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_91ca8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[2] = 14ULL;
    cpu->regs[1] = cpu->regs[1] + 1288ULL;
    cpu->regs[30] = PB_BASE + 0x91ca4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_91cdc;
L_91ca8:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 4));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_91cc8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[2] = 15ULL;
    cpu->regs[1] = cpu->regs[1] + 1304ULL;
    cpu->regs[30] = PB_BASE + 0x91cc4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_91cdc;
L_91cc8:
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 504ULL;
    cpu->regs[2] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x91cdcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_91cdc:
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[25] + 1024ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91cecULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x91d00ULL; PB_CALL(22, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[21], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x91d08ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x90a78ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[21])==0) goto L_91d18;
    PB_LDR(cpu->regs[24], (cpu->regs[21] + 16));
    goto L_91d28;
L_91d18:
    if ((cpu->regs[0])==0) goto L_91d24;
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    goto L_91d28;
L_91d24:
    cpu->regs[24] = 0ULL;
L_91d28:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[21]); } else { FLAG_CMP(0, 1); }
    cpu->regs[28] = (FLAG_EQ) ? 1 : 0;
    if (FLAG_NE) goto L_91e4c;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 96));
    PB_STR((cpu->regs[20] + 96), 0ULL);
    if ((cpu->regs[21])==0) goto L_91e4c;
    cpu->regs[2] = 57792ULL;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[23] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x91d54ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_91d64;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x91d64ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1d2f00ULL);
L_91d64:
    PB_LDR(cpu->regs[22], (SP + 24));
    if ((cpu->regs[22])==0) goto L_91d7c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_NE) goto L_91da4;
L_91d7c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x91d84ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_91e4c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_91e4c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x91da0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_91e4c;
L_91da4:
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x91db0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x91ad0ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x91db8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x121b20ULL);
    if ((cpu->regs[0])==0) goto L_91dc8;
    PB_LDR(cpu->regs[1], (SP + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    cpu->regs[27] = (FLAG_NE) ? 1 : 0;
L_91dc8:
    cpu->regs[30] = PB_BASE + 0x91dccULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_91de8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_91de8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x91de8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_91de8:
    cpu->regs[0] = 44840ULL;
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 32), cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x91e04ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])!=0) goto L_91e14;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x91e10ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    goto L_91e2c;
L_91e14:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_91e2c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_91e2c;
    cpu->regs[30] = PB_BASE + 0x91e2cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_91e2c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_91e48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_91e48;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x91e48ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_91e48:
    if ((((uint32_t)(cpu->regs[27])))!=0) goto L_91e6c;
L_91e4c:
    cpu->regs[1] = cpu->regs[25] + 1024ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91e5cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91e6cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x91180ULL);
L_91e6c:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91e78ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x9e4b8ULL);
    cpu->regs[30] = PB_BASE + 0x91e7cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1ebda4ULL);
    if ((((uint32_t)(cpu->regs[28])))==0) goto L_91b28;
    cpu->regs[30] = PB_BASE + 0x91e84ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1e99c0ULL);
    goto L_91b28;
}
