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

void ft__Py_DumpASCII(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_90d30:
    SP = SP - 112ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_90f3c;
    PB_LDR(cpu->regs[24], (cpu->regs[1] + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 32));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 16));
    cpu->regs[24] = ((uint32_t)(((cpu->regs[24] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_90da8;
    if (!((cpu->regs[0] >> 6) & 1)) goto L_90d94;
    cpu->regs[19] = cpu->regs[1] + 40ULL;
    goto L_90db0;
L_90d94:
    cpu->regs[19] = cpu->regs[1] + 56ULL;
    FLAG_CMP(cpu->regs[21], 500ULL);
    if (FLAG_GT) goto L_90dd0;
    cpu->regs[22] = 0ULL;
    goto L_90dd8;
L_90da8:
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 56));
    if ((cpu->regs[19])==0) goto L_90f3c;
L_90db0:
    FLAG_CMP(cpu->regs[21], 500ULL);
    if (FLAG_GT) goto L_90dc0;
    cpu->regs[22] = 0ULL;
    goto L_90dc8;
L_90dc0:
    cpu->regs[22] = 1ULL;
    cpu->regs[21] = 500ULL;
L_90dc8:
    if (((cpu->regs[0] >> 6) & 1)) goto L_90df4;
    goto L_90dd8;
L_90dd0:
    cpu->regs[22] = 1ULL;
    cpu->regs[21] = 500ULL;
L_90dd8:
    cpu->regs[26] = PB_BASE + 0x2a1000ULL;
    cpu->regs[25] = PB_BASE + 0x2a1000ULL;
    cpu->regs[26] = cpu->regs[26] + 776ULL;
    cpu->regs[25] = cpu->regs[25] + 768ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[28] = 65535ULL;
    goto L_90e50;
L_90df4:
    cpu->regs[0] = 0ULL;
L_90df8:
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GE) goto L_90edc;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + cpu->regs[0]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 32ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(94ULL)));
    if (FLAG_HI) goto L_90dd8;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_90df8;
L_90e18:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x90e28ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1e78e4ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 32ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(94ULL)));
    if (FLAG_HI) goto L_90e5c;
    cpu->regs[1] = SP + 7ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    PB_STRB((SP + 7), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x90e4cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_90e4c:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
L_90e50:
    FLAG_CMP(cpu->regs[23], cpu->regs[21]);
    if (FLAG_LT) goto L_90e18;
    goto L_90eec;
L_90e5c:
    cpu->regs[27] = cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_90e90;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 760ULL;
    cpu->regs[30] = PB_BASE + 0x90e7cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x90e8cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x90c98ULL);
    goto L_90e4c;
L_90e90:
    cpu->regs[2] = 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[28])));
    if (FLAG_HI) goto L_90ebc;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x90ea8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x90eb8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x90c98ULL);
    goto L_90e4c;
L_90ebc:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x90ec8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x90ba8ULL);
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x90ed8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x90c98ULL);
    goto L_90e4c;
L_90edc:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x90eecULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_90eec:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_90f3c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_90f58;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[1] + 1656ULL;
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    cpu->regs[2] = 3ULL;
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
    SP = SP + 112ULL;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x90ba8ULL); return; };
L_90f3c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_90f5c;
L_90f58:
    cpu->regs[30] = PB_BASE + 0x90f5cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_90f5c:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_90fb0;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[2] = 32ULL;
    cpu->regs[1] = cpu->regs[1] + 784ULL;
    cpu->regs[30] = PB_BASE + 0x90fb0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_90fb0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x90fb8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x87950ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_90fd0;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 824ULL;
    cpu->regs[2] = 20ULL;
    goto L_9110c;
L_90fd0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    cpu->regs[24] = 101ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 0));
    if ((cpu->regs[20])==0) goto L_90ff4;
    cpu->regs[23] = PB_BASE + 0x2a1000ULL;
    cpu->regs[21] = PB_BASE + 0x293000ULL;
    cpu->regs[23] = cpu->regs[23] + 880ULL;
    cpu->regs[21] = cpu->regs[21] + 816ULL;
    goto L_910e0;
L_90ff4:
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 848ULL;
    cpu->regs[2] = 20ULL;
    goto L_9110c;
L_91008:
    PB_LDR(cpu->regs[25], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x9101cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x90ba8ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 112));
    if ((cpu->regs[0])==0) goto L_91124;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_91124;
    cpu->regs[22] = PB_BASE + 0x2a1000ULL;
    cpu->regs[22] = cpu->regs[22] + 888ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91048ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x90ba8ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 112));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91054ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x90d30ULL);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x91064ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x90ba8ULL);
L_91064:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9106cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x2273c0ULL);
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 896ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x91084ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x90ba8ULL);
    if (((cpu->regs[22] >> 31) & 1)) goto L_91138;
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x91094ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x90c10ULL);
L_91094:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[1] = cpu->regs[1] + 1952ULL;
    cpu->regs[30] = PB_BASE + 0x910a8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x90ba8ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 120));
    if ((cpu->regs[1])==0) goto L_9114c;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_9114c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x910c4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x90d30ULL);
L_910c4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x910d8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x90ba8ULL);
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    if ((cpu->regs[20])==0) goto L_91160;
L_910e0:
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + 70));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_910f4;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    if ((cpu->regs[20])==0) goto L_91160;
L_910f4:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] - 1ULL)); FLAG_CMP(cpu->regs[24], 0);
    if (FLAG_NE) goto L_91008;
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 872ULL;
    cpu->regs[2] = 6ULL;
L_9110c:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(24, cpu, tlb, PB_BASE + 0x90ba8ULL); return; };
L_91124:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x91134ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_91064;
L_91138:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x91148ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_91094;
L_9114c:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x9115cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x90ba8ULL);
    goto L_910c4;
L_91160:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
}
