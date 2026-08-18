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

void ft__PyObject_DebugMallocStats(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_8fc6c:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x187000ULL;
    cpu->regs[1] = cpu->regs[1] + 3912ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0xd8000ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    SP = SP - 976ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 184));
    PB_LDR(cpu->regs[5], (cpu->regs[2] + 0));
    PB_STR((SP + 968), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_NE) goto L_8fcd8;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 328));
    cpu->regs[0] = cpu->regs[0] + 3716ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_8fce4;
    goto L_900f8;
L_8fcd8:
    cpu->regs[0] = cpu->regs[0] + 3716ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_NE) goto L_900f8;
L_8fce4:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x8fcf8ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x8fd08ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x187b80ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_8fd10;
    PB_LDR(cpu->regs[20], (cpu->regs[3] + 48));
L_8fd10:
    cpu->regs[3] = 32ULL;
    cpu->regs[2] = 512ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[24] = SP + 200ULL;
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 4064ULL;
    cpu->regs[30] = PB_BASE + 0x8fd2cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[2] = 256ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[23] = SP + 456ULL;
    cpu->regs[30] = PB_BASE + 0x8fd40ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[25] = SP + 712ULL;
    cpu->regs[2] = 256ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x8fd54ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = 256ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x8fd64ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7aee0ULL);
    PB_LDRW(cpu->regs[11], (cpu->regs[20] + 4480));
    cpu->regs[3] = 0ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[10] = 48ULL;
    cpu->regs[9] = 16336ULL;
    PB_STR((SP + 0), 0ULL);
L_8fd80:
    FLAG_CMP(((uint32_t)(cpu->regs[11])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_LS) goto L_8fe24;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 4472));
    cpu->regs[0] = (uint64_t)(uint32_t)cpu->regs[3] * (uint64_t)(uint32_t)cpu->regs[10];
    cpu->regs[1] = cpu->regs[2] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_8fe1c;
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 16));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + cpu->regs[2]));
    FLAG_CMP((cpu->regs[0]) & (16383ULL), 0);
    if (FLAG_EQ) goto L_8fdc4;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[0] = cpu->regs[0] & 18446744073709535232ULL;
    cpu->regs[0] = cpu->regs[0] + (4ULL << 12);
    cpu->regs[2] = cpu->regs[2] + (4ULL << 12);
    PB_STR((SP + 0), cpu->regs[2]);
L_8fdc4:
    PB_LDR(cpu->regs[12], (cpu->regs[1] + 8));
L_8fdc8:
    FLAG_CMP(cpu->regs[12], cpu->regs[0]);
    if (FLAG_LS) goto L_8fe1c;
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_8fe14;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 36));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + 1ULL));
    cpu->regs[1] = ((cpu->regs[1] & 0xffffffffULL) << 3);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] << 4));
    PB_LDR(cpu->regs[5], (cpu->regs[23] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)((cpu->regs[2] ? cpu->regs[9] / cpu->regs[2] : 0)));
    PB_LDR(cpu->regs[13], (cpu->regs[24] + cpu->regs[1]));
    cpu->regs[5] = cpu->regs[5] + ((cpu->regs[6]) & 0xffffffffULL);
    PB_LDR(cpu->regs[4], (cpu->regs[25] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[6]));
    cpu->regs[2] = cpu->regs[2] + cpu->regs[13];
    PB_STR((cpu->regs[23] + cpu->regs[1]), cpu->regs[5]);
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    PB_STR((cpu->regs[24] + cpu->regs[1]), cpu->regs[2]);
    PB_STR((cpu->regs[25] + cpu->regs[1]), cpu->regs[4]);
L_8fe14:
    cpu->regs[0] = cpu->regs[0] + (4ULL << 12);
    goto L_8fdc8;
L_8fe1c:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_8fd80;
L_8fe24:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x8fe30ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7ba50ULL);
    cpu->regs[26] = 0ULL;
    cpu->regs[2] = 110ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x8fe4cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7b510ULL);
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 136ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[27] = 0ULL;
    cpu->regs[28] = 0ULL;
    PB_STR((SP + 8), 0ULL);
L_8fe64:
    PB_LDR(cpu->regs[4], (cpu->regs[25] + (cpu->regs[2] << 3)));
    cpu->regs[10] = cpu->regs[2] + 1ULL;
    if ((cpu->regs[4])==0) goto L_8fed8;
    PB_LDR(cpu->regs[5], (cpu->regs[23] + (cpu->regs[2] << 3)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_LDR(cpu->regs[6], (cpu->regs[24] + (cpu->regs[2] << 3)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] << 4));
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 16), cpu->regs[1]); PB_STR((SP + 16) + 8, cpu->regs[4]);
    PB_STR((SP + 32), cpu->regs[6]); PB_STR((SP + 32) + 8, cpu->regs[5]);
    PB_STRW((SP + 52), cpu->regs[3]);
    PB_STR((SP + 56), cpu->regs[10]);
    cpu->regs[30] = PB_BASE + 0x8fe98ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    PB_LDRW(cpu->regs[3], (SP + 52));
    cpu->regs[9] = 16336ULL;
    PB_LDR(cpu->regs[10], (SP + 56));
    cpu->regs[11] = 48ULL;
    PB_LDR(cpu->regs[4], (SP + 24)); PB_LDR(cpu->regs[6], (SP + 24) + 8);
    cpu->regs[0] = ((uint32_t)((cpu->regs[3] ? cpu->regs[9] / cpu->regs[3] : 0)));
    cpu->regs[2] = ((cpu->regs[10] & 0xffffffffULL) << 4);
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[5], (SP + 40));
    cpu->regs[0] = ((uint32_t)(cpu->regs[9] - cpu->regs[0] * cpu->regs[3]));
    cpu->regs[26] = cpu->regs[4] * cpu->regs[11] + cpu->regs[26];
    cpu->regs[27] = cpu->regs[6] * cpu->regs[2] + cpu->regs[27];
    cpu->regs[28] = cpu->regs[5] * cpu->regs[2] + cpu->regs[28];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4] + cpu->regs[1];
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_STR((SP + 8), cpu->regs[0]);
L_8fed8:
    cpu->regs[2] = cpu->regs[10];
    FLAG_CMP(cpu->regs[10], 32ULL);
    if (FLAG_NE) goto L_8fe64;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x8fef0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7ba50ULL);
    cpu->regs[24] = cpu->regs[20] + 3960ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 5032));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 168ULL;
    cpu->regs[24] = cpu->regs[24] + (64ULL << 12);
    cpu->regs[30] = PB_BASE + 0x8ff0cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x8645cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 5032));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 200ULL;
    cpu->regs[2] = cpu->regs[2] - cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x8ff24ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x8645cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 5040));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 224ULL;
    cpu->regs[20] = SP + 72ULL;
    cpu->regs[30] = PB_BASE + 0x8ff3cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 248ULL;
    cpu->regs[30] = PB_BASE + 0x8ff50ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[4] = 1048576ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 128ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[2] = cpu->regs[2] + 280ULL;
    cpu->regs[30] = PB_BASE + 0x8ff6cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[2] = cpu->regs[21] << 20;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x8ff7cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x8ff88ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7ba50ULL);
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 312ULL;
    cpu->regs[30] = PB_BASE + 0x8ff9cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 344ULL;
    cpu->regs[30] = PB_BASE + 0x8ffb4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[21] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[4] = 16384ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 128ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[2] = cpu->regs[2] + 376ULL;
    cpu->regs[30] = PB_BASE + 0x8ffd4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1815f0ULL);
    cpu->regs[2] = ((cpu->regs[22] & 0xffffffffULL) << 14);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x8ffe4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 408ULL;
    cpu->regs[30] = PB_BASE + 0x8fffcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x8645cULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 440ULL;
    cpu->regs[22] = PB_BASE + 0x2a1000ULL;
    cpu->regs[30] = PB_BASE + 0x90018ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[22] = cpu->regs[22] + 504ULL;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[21] = cpu->regs[0] + cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 472ULL;
    cpu->regs[30] = PB_BASE + 0x90034ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[2] = cpu->regs[0] + cpu->regs[20];
    cpu->regs[2] = cpu->regs[2] + cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x90048ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = 18ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[0] + 512ULL;
    cpu->regs[30] = PB_BASE + 0x90060ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x7b510ULL);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 1096),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 536ULL;
    cpu->regs[30] = PB_BASE + 0x90074ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x8645cULL);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 1100),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 560ULL;
    cpu->regs[30] = PB_BASE + 0x90088ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x90094ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7ba50ULL);
    cpu->regs[2] = 262144ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 584ULL;
    cpu->regs[30] = PB_BASE + 0x900a8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[21] = cpu->regs[0];
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 1096),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 616ULL;
    cpu->regs[2] = cpu->regs[2] << 18;
    cpu->regs[30] = PB_BASE + 0x900c4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x8645cULL);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[24] + 1100),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[21] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 648ULL;
    cpu->regs[2] = cpu->regs[2] << 17;
    cpu->regs[30] = PB_BASE + 0x900e0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x900f0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x8645cULL);
    cpu->regs[0] = 1ULL;
    goto L_900fc;
L_900f8:
    cpu->regs[0] = 0ULL;
L_900fc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 968));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9011c;
    cpu->regs[30] = PB_BASE + 0x9011cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9011c:
    SP = SP + 976ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
    if ((cpu->regs[1])==0) goto L_90214;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x90164ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 32)); PB_LDR(cpu->regs[23], (cpu->regs[20] + 32) + 8);
    cpu->regs[1] = cpu->regs[0] - 1ULL;
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[1] : 0ULL;
    PB_LDRB(cpu->regs[24], (cpu->regs[22] + cpu->regs[1]));
    cpu->regs[23] = cpu->regs[23] - cpu->regs[21];
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_90188;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_90188:
    cpu->regs[19] = cpu->regs[0] + cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x90198ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_901c0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    if ((cpu->regs[0])==0) goto L_901ac;
    cpu->regs[30] = PB_BASE + 0x901acULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_901ac:
    cpu->regs[1] = 15ULL;
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[20] + 32), 0ULL); PB_STR((cpu->regs[20] + 32) + 8, 0ULL);
    PB_STRW((cpu->regs[20] + 64), cpu->regs[1]);
    goto L_90200;
L_901c0:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x901ccULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7b130ULL);
    cpu->regs[1] = cpu->regs[20] + (4ULL << 12);
    PB_STRW((cpu->regs[1] + 892), 0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_901f4;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[19];
    cpu->regs[3] = 10ULL;
    cpu->regs[2] = 1ULL;
    PB_STRB((cpu->regs[0] + -1), cpu->regs[3]);
    PB_STRB((cpu->regs[21] + cpu->regs[19]), 0ULL);
    PB_STRW((cpu->regs[1] + 892), cpu->regs[2]);
L_901f4:
    cpu->regs[19] = cpu->regs[21] + cpu->regs[19];
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[20] + 32), cpu->regs[21]); PB_STR((cpu->regs[20] + 32) + 8, cpu->regs[19]);
L_90200:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_90214:
    cpu->regs[0] = 0ULL;
    return;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2192));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9023cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x8fc6cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9024c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x9024cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7ba50ULL);
L_9024c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x90254ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x8fc38ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
