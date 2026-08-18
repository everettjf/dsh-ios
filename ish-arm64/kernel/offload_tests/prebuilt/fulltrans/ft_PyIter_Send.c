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

void ft_PyIter_Send(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[5] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[7], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[7]);
    cpu->regs[7] = 0ULL;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 80));
    if ((cpu->regs[3])==0) goto L_a8e04;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    if ((cpu->regs[3])==0) goto L_a8e04;
    PB_LDR(cpu->regs[4], (SP + 24));
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[5]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[5] = 0ULL;
    if (FLAG_NE) goto L_a8e94;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_a8e04:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_NE) goto L_a8e38;
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 224));
    if ((cpu->regs[1])==0) goto L_a8e38;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2208));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a8e38;
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0xa8e34ULL; PB_CALL(1, cpu, tlb, cpu->regs[1]);
    goto L_a8e60;
L_a8e38:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 56176ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[1] = SP;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0xa8e60ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x147564ULL);
L_a8e60:
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a8e7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa8e70ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1fc170ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
    goto L_a8e80;
L_a8e7c:
    cpu->regs[0] = 1ULL;
L_a8e80:
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_a8e98;
L_a8e94:
    cpu->regs[30] = PB_BASE + 0xa8e98ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a8e98:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    if ((cpu->regs[0])==0) goto L_a8ed4;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a8ef4;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_a8ef4;
L_a8ed4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0xa8edcULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1c7228ULL);
    if ((cpu->regs[0])==0) goto L_a8ef4;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a8ef0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_a8ef0:
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
L_a8ef4:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    if ((cpu->regs[0])==0) goto L_a8f2c;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a8f5c;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_a8f5c;
L_a8f2c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])!=0) goto L_a8f40;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0xdb548ULL); return; };
L_a8f40:
    cpu->regs[30] = PB_BASE + 0xa8f44ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c7228ULL);
    if ((cpu->regs[0])==0) goto L_a8f58;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a8f58;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_a8f58:
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
L_a8f5c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_a8f94;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a8fc4;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_a8fc4;
L_a8f94:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_a8fbc;
    cpu->regs[30] = PB_BASE + 0xa8fa0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c7228ULL);
    if ((cpu->regs[0])==0) goto L_a8fb4;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a8fb4;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_a8fb4:
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    goto L_a8fc4;
L_a8fbc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a8fc4:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[1])!=0) goto L_a9034;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2856));
    cpu->regs[30] = PB_BASE + 0xa8ff0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a8ffc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0xa8ffcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x137ba0ULL);
L_a8ffc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0xa9004ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a9014;
L_a9008:
    cpu->regs[0] = 1ULL;
    PB_STRB((cpu->regs[20] + 65), cpu->regs[0]);
    goto L_a9028;
L_a9014:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3144));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9024ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a9008;
L_a9028:
    cpu->regs[19] = 0ULL;
    PB_STRB((cpu->regs[20] + 66), 0ULL);
    goto L_a9074;
L_a9034:
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3968));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_a9074;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0xa9054ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x252128ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a9028;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a9028;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa9070ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a9028;
L_a9074:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0xa90a0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x9a66cULL);
    if ((cpu->regs[0])==0) goto L_a90f8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0xa90b4ULL; PB_CALL(16, cpu, tlb, cpu->regs[1]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a90d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a90d4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa90d4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a90d4:
    if ((cpu->regs[20])!=0) goto L_a90fc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2856));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa90e8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a90f8;
    cpu->regs[30] = PB_BASE + 0xa90f0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[30] = PB_BASE + 0xa90f8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x252128ULL);
L_a90f8:
    cpu->regs[20] = 0ULL;
L_a90fc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3632));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a9144;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 4056));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_a9168;
L_a9144:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0xa914cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x22d664ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a91a4;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = (FLAG_GT) ? cpu->regs[19] : cpu->regs[0];
L_a9168:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a9178;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_a9178:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa9180ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x14e5a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_a91a8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a91a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa91a0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a91a8;
L_a91a4:
    cpu->regs[20] = 0ULL;
L_a91a8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_a91f8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa91f4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9218;
L_a91f8:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 20));
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_a9220;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9218ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_a9218:
    cpu->regs[20] = 4294967295ULL;
    goto L_a9284;
L_a9220:
    if ((cpu->regs[0])!=0) goto L_a9240;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 3896ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa923cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9218;
L_a9240:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2976));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0xa9250ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x123dd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9264;
    cpu->regs[30] = PB_BASE + 0xa925cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a926c;
    goto L_a9218;
L_a9264:
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_a9280;
L_a926c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 3920ULL;
    cpu->regs[30] = PB_BASE + 0xa927cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9218;
L_a9280:
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
L_a9284:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 64ULL;
    cpu->regs[4] = 18446744073709551615ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    FLAG_CMP(cpu->regs[20], 1ULL);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 3080));
    if (FLAG_HI) goto L_a92f0;
L_a92e4:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_GT) goto L_a9310;
    goto L_a9320;
L_a92f0:
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 2888ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa9308ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a92e4;
    goto L_a9378;
L_a9310:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xa931cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x155680ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a9378;
L_a9320:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[20], (SP + 0));
    cpu->regs[30] = PB_BASE + 0xa932cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x230c8cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a9378;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 24) + 8);
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2];
    if (FLAG_GE) { FLAG_CMP(cpu->regs[20], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = cpu->regs[0] & ~(((uint64_t)((int64_t)cpu->regs[0] >> 63)));
    cpu->regs[20] = (FLAG_GT) ? cpu->regs[0] : cpu->regs[20];
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_a938c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    { PB_CALL(33, cpu, tlb, PB_BASE + 0x80e30ULL); return; };
L_a9378:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a9390;
L_a938c:
    cpu->regs[30] = PB_BASE + 0xa9390ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a9390:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_a93a8:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2584));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0xa93ccULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a93e8;
    cpu->regs[30] = PB_BASE + 0xa93dcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a93ec;
L_a93e0:
    cpu->regs[19] = 18446744073709551615ULL;
    goto L_a9410;
L_a93e8:
    if (!((cpu->regs[0] >> 63) & 1)) goto L_a9410;
L_a93ec:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 104));
    if ((cpu->regs[0])==0) goto L_a9410;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if ((cpu->regs[1])==0) goto L_a9410;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa9408ULL; PB_CALL(37, cpu, tlb, cpu->regs[1]);
    if (((cpu->regs[0] >> 63) & 1)) goto L_a93e0;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
L_a9410:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 1ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xa9448ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x15bbccULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a9454;
L_a944c:
    cpu->regs[0] = 0ULL;
    goto L_a949c;
L_a9454:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa9460ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xa93a8ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9474;
    cpu->regs[30] = PB_BASE + 0xa9470ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a944c;
L_a9474:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa9484ULL; PB_CALL(41, cpu, tlb, cpu->regs[21]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9494;
    cpu->regs[30] = PB_BASE + 0xa9490ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a944c;
L_a9494:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a949c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_NE) goto L_a9500;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xa94d4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xa93a8ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a94e8;
    cpu->regs[30] = PB_BASE + 0xa94e4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a950c;
L_a94e8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_a9500:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa950cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x15bbccULL);
L_a950c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[5] = SP + 8ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[4] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xa9568ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a9574;
L_a956c:
    cpu->regs[0] = 0ULL;
    goto L_a95bc;
L_a9574:
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa9580ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xa93a8ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9594;
    cpu->regs[30] = PB_BASE + 0xa9590ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a956c;
L_a9594:
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa95a4ULL; PB_CALL(49, cpu, tlb, cpu->regs[20]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a95b4;
    cpu->regs[30] = PB_BASE + 0xa95b0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a956c;
L_a95b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a95bc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_a95dc;
    cpu->regs[30] = PB_BASE + 0xa95dcULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a95dc:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[1])!=0) goto L_a9634;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 104));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9628;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 2912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9624ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a965c;
L_a9628:
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 104), cpu->regs[0]);
    goto L_a9668;
L_a9634:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xa9648ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9664;
    cpu->regs[30] = PB_BASE + 0xa9658ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a9664;
L_a965c:
    cpu->regs[0] = 4294967295ULL;
    goto L_a966c;
L_a9664:
    PB_STR((cpu->regs[19] + 104), cpu->regs[3]);
L_a9668:
    cpu->regs[0] = 0ULL;
L_a966c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
