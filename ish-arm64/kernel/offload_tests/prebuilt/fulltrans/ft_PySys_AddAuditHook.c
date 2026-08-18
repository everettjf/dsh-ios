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

void ft_PySys_AddAuditHook(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 16));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e0b4;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x9e06cULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[21], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[21])==0) goto L_9e0b8;
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 2584ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9e088ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x181ea8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9e0b8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3296));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x9e0a4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x121d80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e144;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9e0b0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    goto L_9e0f4;
L_9e0b4:
    cpu->regs[21] = 0ULL;
L_9e0b8:
    cpu->regs[0] = 24ULL;
    cpu->regs[30] = PB_BASE + 0x9e0c0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xd7700ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9e0d8;
    if ((cpu->regs[21])==0) goto L_9e144;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9e0d4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x22d7a8ULL);
    goto L_9e144;
L_9e0d8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2992));
    PB_STR((cpu->regs[19] + 0), 0ULL); PB_STR((cpu->regs[19] + 0) + 8, cpu->regs[23]);
    PB_STR((cpu->regs[19] + 16), cpu->regs[22]);
    if ((cpu->regs[0])!=0) goto L_9e110;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 3000));
    if ((cpu->regs[0])!=0) goto L_9e0fc;
    PB_STR((cpu->regs[20] + 3000), cpu->regs[19]);
L_9e0f4:
    cpu->regs[0] = 0ULL;
    goto L_9e148;
L_9e0fc:
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])!=0) goto L_9e0fc;
    PB_STR((cpu->regs[1] + 0), cpu->regs[19]);
    goto L_9e0f4;
L_9e110:
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x9e118ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 3000));
    if ((cpu->regs[0])!=0) goto L_9e128;
    PB_STR((cpu->regs[20] + 3000), cpu->regs[19]);
    goto L_9e138;
L_9e128:
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])!=0) goto L_9e128;
    PB_STR((cpu->regs[1] + 0), cpu->regs[19]);
L_9e138:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2992));
    cpu->regs[30] = PB_BASE + 0x9e140ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x17faa0ULL);
    goto L_9e0f4;
L_9e144:
    cpu->regs[0] = 4294967295ULL;
L_9e148:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x9e174ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e1bc;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = (FLAG_GT) ? cpu->regs[19] : cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9e198ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x152da0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9e1c4;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 1392ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9e1bcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11f220ULL);
L_9e1bc:
    cpu->regs[20] = 0ULL;
    goto L_9e1fc;
L_9e1c4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9e1d4;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_9e1d4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9e1dcULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe8060ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_9e1fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9e1fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9e1fcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9e1fc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 224));
L_9e224:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9e22cULL; PB_CALL(14, cpu, tlb, cpu->regs[20]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9e250;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[2] = cpu->regs[3] - 1ULL;
    if (((cpu->regs[3] >> 31) & 1)) goto L_9e224;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_9e224;
    cpu->regs[30] = PB_BASE + 0x9e24cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9e224;
L_9e250:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x27c4ecULL); return; };
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2840));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x9e27cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9e288;
L_9e280:
    cpu->regs[19] = 4294967295ULL;
    goto L_9e2a4;
L_9e288:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3000));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9e298ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x121d30ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9e280;
    cpu->regs[30] = PB_BASE + 0x9e2a4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_9e2a4:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x9e2e4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x2804c4ULL);
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x9e2fcULL; PB_CALL(21, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(22, cpu, tlb, PB_BASE + 0x81764ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 80));
    cpu->regs[30] = PB_BASE + 0x9e32cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x10e664ULL);
    FLAG_CMP(cpu->regs[0], 2ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    cpu->regs[3] = (FLAG_LT) ? cpu->regs[3] : cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 1448ULL;
    { PB_CALL(24, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[22] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x9e394ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe2100ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9e3d8;
    cpu->regs[3] = 0ULL;
L_9e39c:
    FLAG_CMP(cpu->regs[3], cpu->regs[19]);
    if (FLAG_GE) goto L_9e3d0;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[3] << 3)));
    cpu->regs[4] = cpu->regs[20] + cpu->regs[3];
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[4] = cpu->regs[2] + (cpu->regs[4] << 3);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9e3c8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_9e3c8:
    PB_STR((cpu->regs[4] + 24), cpu->regs[1]);
    goto L_9e39c;
L_9e3d0:
    cpu->regs[0] = cpu->regs[19] + cpu->regs[20];
    goto L_9e3dc;
L_9e3d8:
    cpu->regs[0] = 18446744073709551615ULL;
L_9e3dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_9e414;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x9e40cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x207c00ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_9e424;
L_9e414:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9e424;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_9e424:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x9e440ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1d53a0ULL);
    if ((cpu->regs[0])==0) goto L_9e478;
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_9e480;
    cpu->regs[30] = PB_BASE + 0x9e454ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d5760ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9e480;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9e478;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9e478;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9e478ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9e478:
    cpu->regs[0] = 0ULL;
    goto L_9e4ac;
L_9e480:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9e494;
L_9e488:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_9e4ac;
L_9e494:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9e488;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9e4a8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9e488;
L_9e4ac:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
