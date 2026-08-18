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

void ft__PyOS_URandom(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = cpu->regs[3];
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x1816ecULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x51d000ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[0] + 3600ULL;
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0] + 2440ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x83f88ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 32));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x83f9cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x84060ULL);
    if ((cpu->regs[0])!=0) goto L_83fa8;
L_83fa0:
    cpu->regs[19] = 0ULL;
    goto L_8404c;
L_83fa8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 27464ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x83fc8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_83fe4;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_8404c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_8404c;
L_83fe4:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_83fa0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_8402c;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x84008ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])==0) goto L_84024;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_8401c;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_8401c:
    cpu->regs[19] = cpu->regs[0];
    goto L_8404c;
L_84024:
    cpu->regs[30] = PB_BASE + 0x84028ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_83fa0;
L_8402c:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x1157e0ULL); return; };
L_8404c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_84060:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x8407cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x215100ULL);
    if ((cpu->regs[0])!=0) goto L_8409c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2608ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x84098ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_840b4;
L_8409c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x840a8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_8410c;
    cpu->regs[30] = PB_BASE + 0x840b0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_840bc;
L_840b4:
    cpu->regs[20] = 0ULL;
    goto L_84110;
L_840bc:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x840c8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x800bcULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_840b4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3488));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 296));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_84110;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 24) + 8);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x840f8ULL; PB_CALL(13, cpu, tlb, cpu->regs[3]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_84110;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x84108ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x197f6cULL);
    goto L_840b4;
L_8410c:
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
L_84110:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2680));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 88));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x84148ULL; PB_CALL(15, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_841c4;
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    if ((cpu->regs[0])!=0) goto L_8416c;
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 2064ULL;
    cpu->regs[30] = PB_BASE + 0x84164ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_841a4;
L_8416c:
    cpu->regs[30] = PB_BASE + 0x84170ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x213250ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_84190;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_841a8;
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1656ULL;
    cpu->regs[30] = PB_BASE + 0x84188ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_8419c;
L_84190:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    cpu->regs[30] = PB_BASE + 0x84198ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x14d650ULL);
    cpu->regs[20] = cpu->regs[0];
L_8419c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    cpu->regs[30] = PB_BASE + 0x841a4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x2153e0ULL);
L_841a4:
    if ((cpu->regs[20])!=0) goto L_841cc;
L_841a8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_841c4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_841c4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x841c4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_841c4:
    cpu->regs[21] = 0ULL;
    goto L_84228;
L_841cc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[30] = PB_BASE + 0x841d4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[0] = cpu->regs[0] + 1944ULL;
    cpu->regs[30] = PB_BASE + 0x841ecULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_8420c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_8420c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x8420cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_8420c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_84228;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_84228;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x84228ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_84228:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 64));
    if (((cpu->regs[0] >> 63) & 1)) goto L_84248;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_84248:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    SP = SP - 32ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[0] = 40944ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x8429cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_842bc;
    cpu->regs[30] = PB_BASE + 0x842bcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7c170ULL);
L_842bc:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[1])!=0) goto L_842f0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 2048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x842ecULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_84338;
L_842f0:
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_8436c;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2432));
    FLAG_CMP(cpu->regs[3], cpu->regs[4]);
    if (FLAG_EQ) goto L_84344;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 24));
    cpu->regs[1] = cpu->regs[1] + 2080ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x84338ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x11f220ULL);
L_84338:
    cpu->regs[0] = 4294967295ULL;
    goto L_84394;
L_84340:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
L_84344:
    if ((cpu->regs[0])==0) goto L_84370;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_84340;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 2120ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x84368ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_84338;
L_8436c:
    cpu->regs[1] = 0ULL;
L_84370:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    if ((cpu->regs[1])==0) goto L_84388;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_84388;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[3]);
L_84388:
    PB_STR((cpu->regs[2] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x84390ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
L_84394:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 32ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[4] = 29512ULL;
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
    cpu->regs[30] = PB_BASE + 0x843e0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_84400;
    cpu->regs[30] = PB_BASE + 0x84400ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7c170ULL);
L_84400:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 40));
    if ((cpu->regs[1])==0) goto L_84448;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 64));
    if (((cpu->regs[0] >> 63) & 1)) goto L_84448;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_GE) goto L_84448;
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_84450;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_84450;
L_84448:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_84450:
    return;
    SP = SP - 64ULL;
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[2], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    cpu->regs[5] = cpu->regs[1];
    if (FLAG_LE) goto L_84498;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_844d8;
L_84498:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[6] = 1ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 2048ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x844c8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_844d8;
L_844d0:
    cpu->regs[20] = 0ULL;
    goto L_84524;
L_844d8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[19], (cpu->regs[5] + 0));
    cpu->regs[30] = PB_BASE + 0x844e4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x15e540ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 40));
    cpu->regs[30] = PB_BASE + 0x844f4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x20cf68ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_844d0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x84504ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x20d548ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_84524;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_84524;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x84524ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_84524:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_84544;
    cpu->regs[30] = PB_BASE + 0x84544ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7c170ULL);
L_84544:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    { PB_CALL(41, cpu, tlb, PB_BASE + 0x11ed08ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    if ((cpu->regs[21])==0) goto L_84590;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_8460c;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_8460c;
L_84590:
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    cpu->regs[30] = PB_BASE + 0x8459cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_8460c;
    cpu->regs[23] = cpu->regs[20] + 80ULL;
    cpu->regs[24] = cpu->regs[0] + 24ULL;
    cpu->regs[22] = 0ULL;
L_845b0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 72));
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_GE) goto L_845f4;
    PB_LDR(cpu->regs[0], cpu->regs[23]); PB_LDR(cpu->regs[1], cpu->regs[23] + 8); cpu->regs[23] += 16;
    cpu->regs[30] = PB_BASE + 0x845c4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x25c624ULL);
    if ((cpu->regs[0])!=0) goto L_845e8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_8460c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_8460c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x845e4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_8460c;
L_845e8:
    PB_STR((cpu->regs[24] + (cpu->regs[22] << 3)), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_845b0;
L_845f4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_84604;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_84604:
    cpu->regs[21] = cpu->regs[19];
    PB_STR((cpu->regs[20] + 32), cpu->regs[19]);
L_8460c:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x84640ULL; PB_CALL(45, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[1] = cpu->regs[0] + 104ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    if ((cpu->regs[1])==0) goto L_84678;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 2240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x84674ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_8471c;
L_84678:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 1712));
    if (((cpu->regs[0] >> 15) & 1)) goto L_8469c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 2280ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x84698ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_8471c;
L_8469c:
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 2328ULL;
    cpu->regs[30] = PB_BASE + 0x846acULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_8471c;
    cpu->regs[30] = PB_BASE + 0x846b8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x84730ULL);
    cpu->regs[30] = PB_BASE + 0x846bcULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x7afd0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x846c4ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 0));
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_846d8;
    cpu->regs[30] = PB_BASE + 0x846d4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xd69f8ULL);
    goto L_84708;
L_846d8:
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[0] = cpu->regs[0] + 2336ULL;
    cpu->regs[30] = PB_BASE + 0x846e4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x8484cULL);
    cpu->regs[30] = PB_BASE + 0x846e8ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x84b3cULL);
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_84708;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x84704ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_8471c;
L_84708:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(56, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_8471c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
