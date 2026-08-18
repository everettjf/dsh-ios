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

void ft__PyConfig_AsDict(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1add74ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd94a0ULL);
    if ((cpu->regs[0])==0) goto L_1aeca8;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[0];
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[20],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1add88ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3592ULL;
    cpu->regs[30] = PB_BASE + 0x1adda4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aed58;
L_1addb0:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 4),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1addbcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3608ULL;
    cpu->regs[30] = PB_BASE + 0x1addd8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aef4c;
L_1adde4:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 8),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1addf0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3624ULL;
    cpu->regs[30] = PB_BASE + 0x1ade0cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aef34;
L_1ade18:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 12),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ade24ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3640ULL;
    cpu->regs[30] = PB_BASE + 0x1ade40ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aef1c;
L_1ade4c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 16),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ade58ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3656ULL;
    cpu->regs[30] = PB_BASE + 0x1ade74ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aef04;
L_1ade80:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 20),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ade8cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3680ULL;
    cpu->regs[30] = PB_BASE + 0x1adea8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aeeec;
L_1adeb4:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x1adec0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe1564ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3696ULL;
    cpu->regs[30] = PB_BASE + 0x1adedcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aeed4;
L_1adee8:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 32),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1adef4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2320ULL;
    cpu->regs[30] = PB_BASE + 0x1adf10ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aeebc;
L_1adf1c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 36),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1adf28ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3712ULL;
    cpu->regs[30] = PB_BASE + 0x1adf44ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aeea4;
L_1adf50:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 40),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1adf5cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3728ULL;
    cpu->regs[30] = PB_BASE + 0x1adf78ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aee8c;
L_1adf84:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 44),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1adf90ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3744ULL;
    cpu->regs[30] = PB_BASE + 0x1adfacULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aee74;
L_1adfb8:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 48),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1adfc4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3760ULL;
    cpu->regs[30] = PB_BASE + 0x1adfe0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aee5c;
L_1adfec:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 52),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1adff8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3784ULL;
    cpu->regs[30] = PB_BASE + 0x1ae014ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aee44;
L_1ae020:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 56),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae02cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3800ULL;
    cpu->regs[30] = PB_BASE + 0x1ae048ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aee2c;
L_1ae054:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 72),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae060ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3816ULL;
    cpu->regs[30] = PB_BASE + 0x1ae07cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aee14;
L_1ae088:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 80));
    if ((cpu->regs[0])==0) goto L_1aedf0;
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1ae09cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
L_1ae0a4:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2792ULL;
    cpu->regs[30] = PB_BASE + 0x1ae0b8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ae0d0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1aede4;
L_1ae0d0:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 88));
    if ((cpu->regs[0])==0) goto L_1af3ec;
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1ae0e4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
L_1ae0ec:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2816ULL;
    cpu->regs[30] = PB_BASE + 0x1ae100ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ae118;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1af3e0;
L_1ae118:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 96));
    if ((cpu->regs[0])!=0) goto L_1af410;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af3a4;
L_1ae138:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae140:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x1ae154ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af3c0;
L_1ae160:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 272));
    if ((cpu->regs[0])!=0) goto L_1af3ac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af3d8;
L_1ae180:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae188:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3848ULL;
    cpu->regs[30] = PB_BASE + 0x1ae19cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af38c;
L_1ae1a8:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 104),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae1b4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0x1ae1d0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af374;
L_1ae1dc:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    cpu->regs[0] = cpu->regs[20] + 128ULL;
    cpu->regs[30] = PB_BASE + 0x1ae1e8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1af424ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3880ULL;
    cpu->regs[30] = PB_BASE + 0x1ae204ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ae21c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1af368;
L_1ae21c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    cpu->regs[0] = cpu->regs[20] + 144ULL;
    cpu->regs[30] = PB_BASE + 0x1ae228ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1af424ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3888ULL;
    cpu->regs[30] = PB_BASE + 0x1ae244ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ae25c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1af35c;
L_1ae25c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    cpu->regs[0] = cpu->regs[20] + 160ULL;
    cpu->regs[30] = PB_BASE + 0x1ae268ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1af424ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3136ULL;
    cpu->regs[30] = PB_BASE + 0x1ae284ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ae29c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1af350;
L_1ae29c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 280));
    if ((cpu->regs[0])!=0) goto L_1af33c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af334;
L_1ae2bc:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae2c4:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3904ULL;
    cpu->regs[30] = PB_BASE + 0x1ae2d8ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af31c;
L_1ae2e4:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 288));
    if ((cpu->regs[0])!=0) goto L_1af308;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af300;
L_1ae304:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae30c:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3920ULL;
    cpu->regs[30] = PB_BASE + 0x1ae320ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af2e8;
L_1ae32c:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 304),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae338ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3928ULL;
    cpu->regs[30] = PB_BASE + 0x1ae354ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af2d0;
L_1ae360:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    cpu->regs[0] = cpu->regs[20] + 312ULL;
    cpu->regs[30] = PB_BASE + 0x1ae36cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1af424ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3952ULL;
    cpu->regs[30] = PB_BASE + 0x1ae388ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ae3a0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1af2c4;
L_1ae3a0:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 328));
    if ((cpu->regs[0])!=0) goto L_1af2b0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af2a8;
L_1ae3c0:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae3c8:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3976ULL;
    cpu->regs[30] = PB_BASE + 0x1ae3dcULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af290;
L_1ae3e8:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 336));
    if ((cpu->regs[0])!=0) goto L_1af27c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af260;
L_1ae408:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae410:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2712ULL;
    cpu->regs[30] = PB_BASE + 0x1ae424ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af248;
L_1ae430:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 344));
    if ((cpu->regs[0])!=0) goto L_1af268;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af240;
L_1ae450:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae458:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3992ULL;
    cpu->regs[30] = PB_BASE + 0x1ae46cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af228;
L_1ae478:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 352));
    if ((cpu->regs[0])!=0) goto L_1af214;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af20c;
L_1ae498:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae4a0:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3840ULL;
    cpu->regs[30] = PB_BASE + 0x1ae4b4ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af1f4;
L_1ae4c0:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 360));
    if ((cpu->regs[0])!=0) goto L_1af1ac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af1a4;
L_1ae4e0:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae4e8:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2656ULL;
    cpu->regs[30] = PB_BASE + 0x1ae4fcULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af18c;
L_1ae508:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 368));
    if ((cpu->regs[0])!=0) goto L_1af178;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af1d8;
L_1ae528:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae530:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2728ULL;
    cpu->regs[30] = PB_BASE + 0x1ae544ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af1c0;
L_1ae550:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 376));
    if ((cpu->regs[0])!=0) goto L_1af1e0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af170;
L_1ae570:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae578:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2672ULL;
    cpu->regs[30] = PB_BASE + 0x1ae58cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af158;
L_1ae598:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 296));
    if ((cpu->regs[0])!=0) goto L_1af144;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1af13c;
L_1ae5b8:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae5c0:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2696ULL;
    cpu->regs[30] = PB_BASE + 0x1ae5d4ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af124;
L_1ae5e0:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 176),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae5ecULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4008ULL;
    cpu->regs[30] = PB_BASE + 0x1ae608ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af10c;
L_1ae614:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 180),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae620ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4024ULL;
    cpu->regs[30] = PB_BASE + 0x1ae63cULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af0f4;
L_1ae648:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 184),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae654ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4040ULL;
    cpu->regs[30] = PB_BASE + 0x1ae670ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af0dc;
L_1ae67c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 188),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae688ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4064ULL;
    cpu->regs[30] = PB_BASE + 0x1ae6a4ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af0c4;
L_1ae6b0:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 192),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae6bcULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4072ULL;
    cpu->regs[30] = PB_BASE + 0x1ae6d8ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af0ac;
L_1ae6e4:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 196),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae6f0ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 4088ULL;
    cpu->regs[30] = PB_BASE + 0x1ae70cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af094;
L_1ae718:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 200),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae724ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x1ae740ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af07c;
L_1ae74c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 204),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae758ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x1ae774ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af064;
L_1ae780:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 208),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae78cULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 48ULL;
    cpu->regs[30] = PB_BASE + 0x1ae7a8ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af04c;
L_1ae7b4:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 212),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae7c0ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 56ULL;
    cpu->regs[30] = PB_BASE + 0x1ae7dcULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af034;
L_1ae7e8:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 216),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae7f4ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 64ULL;
    cpu->regs[30] = PB_BASE + 0x1ae810ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af01c;
L_1ae81c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 220),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae828ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 88ULL;
    cpu->regs[30] = PB_BASE + 0x1ae844ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1af004;
L_1ae850:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 224),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae85cULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 112ULL;
    cpu->regs[30] = PB_BASE + 0x1ae878ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aefec;
L_1ae884:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 232));
    if ((cpu->regs[0])==0) goto L_1aefc8;
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1ae898ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
L_1ae8a0:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 128ULL;
    cpu->regs[30] = PB_BASE + 0x1ae8b4ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ae8cc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1aefbc;
L_1ae8cc:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 240));
    if ((cpu->regs[0])==0) goto L_1aef98;
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1ae8e0ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
L_1ae8e8:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 144ULL;
    cpu->regs[30] = PB_BASE + 0x1ae8fcULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ae914;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1aef8c;
L_1ae914:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 384),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1ae920ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 160ULL;
    cpu->regs[30] = PB_BASE + 0x1ae93cULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aef74;
L_1ae948:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 392));
    if ((cpu->regs[0])!=0) goto L_1aecc4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1aef6c;
L_1ae968:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ae970:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x1ae984ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aec68;
L_1ae990:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 400));
    if ((cpu->regs[0])!=0) goto L_1aec80;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1aecd8;
L_1ae9b0:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
L_1ae9b8:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 2408ULL;
    cpu->regs[30] = PB_BASE + 0x1ae9ccULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aec38;
L_1ae9d8:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 408));
    if ((cpu->regs[0])!=0) goto L_1aecb0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1aef64;
L_1ae9f8:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
L_1aea00:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 184ULL;
    cpu->regs[30] = PB_BASE + 0x1aea14ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aec50;
L_1aea20:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 416),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1aea2cULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 200ULL;
    cpu->regs[30] = PB_BASE + 0x1aea48ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aece0;
L_1aea54:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 248));
    if ((cpu->regs[0])==0) goto L_1aed34;
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1aea68ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
L_1aea70:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 224ULL;
    cpu->regs[30] = PB_BASE + 0x1aea84ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1aea9c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1aed10;
L_1aea9c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 268),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1aeaa8ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 248ULL;
    cpu->regs[30] = PB_BASE + 0x1aeac4ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aed1c;
L_1aead0:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 420),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1aeadcULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 272ULL;
    cpu->regs[30] = PB_BASE + 0x1aeaf8ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aecf8;
L_1aeb04:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    cpu->regs[0] = cpu->regs[20] + 112ULL;
    cpu->regs[30] = PB_BASE + 0x1aeb10ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x1af424ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 288ULL;
    cpu->regs[30] = PB_BASE + 0x1aeb2cULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1aeb44;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1aedd8;
L_1aeb44:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 256),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1aeb50ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 304ULL;
    cpu->regs[30] = PB_BASE + 0x1aeb6cULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aedc0;
L_1aeb78:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 260),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1aeb84ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 328ULL;
    cpu->regs[30] = PB_BASE + 0x1aeba0ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aeda8;
L_1aebac:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 424),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1aebb8ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 344ULL;
    cpu->regs[30] = PB_BASE + 0x1aebd4ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aed90;
L_1aebe0:
    if (((cpu->regs[22] >> 31) & 1)) goto L_1aec90;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 264),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0x1aebecULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aec90;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 368ULL;
    cpu->regs[30] = PB_BASE + 0x1aec08ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1aec20;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1aed84;
L_1aec20:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1aec90;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1aec28:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1aec38:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae9d8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aec4cULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae9d8;
L_1aec50:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aea20;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aec64ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aea20;
L_1aec68:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae990;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1aec7cULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae990;
L_1aec80:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1aec88ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae9b8;
L_1aec90:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aeca4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1aed70;
L_1aeca4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1aeca8:
    cpu->regs[19] = 0ULL;
    goto L_1aec28;
L_1aecb0:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1aecb8ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1aea00;
    goto L_1aec90;
L_1aecc4:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1aecccULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae970;
    goto L_1aec90;
L_1aecd8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae9b0;
L_1aece0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aea54;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aecf4ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aea54;
L_1aecf8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aeb04;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aed0cULL; PB_CALL(120, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aeb04;
L_1aed10:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aed18ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aea9c;
L_1aed1c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aead0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aed30ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aead0;
L_1aed34:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1aed4c;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1aed4c:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    goto L_1aea70;
L_1aed58:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1addb0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aed6cULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1addb0;
L_1aed70:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aed7cULL; PB_CALL(124, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1aec28;
L_1aed84:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1aed8cULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aec20;
L_1aed90:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aebe0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aeda4ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aebe0;
L_1aeda8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aebac;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aedbcULL; PB_CALL(127, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aebac;
L_1aedc0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aeb78;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aedd4ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aeb78;
L_1aedd8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aede0ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aeb44;
L_1aede4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aedecULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae0d0;
L_1aedf0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1aee08;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1aee08:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    goto L_1ae0a4;
L_1aee14:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae088;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aee28ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae088;
L_1aee2c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae054;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aee40ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae054;
L_1aee44:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae020;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aee58ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae020;
L_1aee5c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1adfec;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aee70ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1adfec;
L_1aee74:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1adfb8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aee88ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1adfb8;
L_1aee8c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1adf84;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aeea0ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1adf84;
L_1aeea4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1adf50;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aeeb8ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1adf50;
L_1aeebc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1adf1c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aeed0ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1adf1c;
L_1aeed4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1adee8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aeee8ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1adee8;
L_1aeeec:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1adeb4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aef00ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1adeb4;
L_1aef04:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ade80;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aef18ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ade80;
L_1aef1c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ade4c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aef30ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ade4c;
L_1aef34:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ade18;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aef48ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ade18;
L_1aef4c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1adde4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aef60ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1adde4;
L_1aef64:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae9f8;
L_1aef6c:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae968;
L_1aef74:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae948;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aef88ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae948;
L_1aef8c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aef94ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae914;
L_1aef98:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1aefb0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1aefb0:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    goto L_1ae8e8;
L_1aefbc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aefc4ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae8cc;
L_1aefc8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1aefe0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1aefe0:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    goto L_1ae8a0;
L_1aefec:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae884;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af000ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae884;
L_1af004:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae850;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af018ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae850;
L_1af01c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae81c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af030ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae81c;
L_1af034:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae7e8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af048ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae7e8;
L_1af04c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae7b4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af060ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae7b4;
L_1af064:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae780;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af078ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae780;
L_1af07c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae74c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af090ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae74c;
L_1af094:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae718;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af0a8ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae718;
L_1af0ac:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae6e4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af0c0ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae6e4;
L_1af0c4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae6b0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af0d8ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae6b0;
L_1af0dc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae67c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af0f0ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae67c;
L_1af0f4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae648;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af108ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae648;
L_1af10c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae614;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af120ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae614;
L_1af124:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae5e0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af138ULL; PB_CALL(161, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae5e0;
L_1af13c:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae5b8;
L_1af144:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af14cULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae5c0;
    goto L_1aec90;
L_1af158:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae598;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af16cULL; PB_CALL(163, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae598;
L_1af170:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae570;
L_1af178:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af180ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae530;
    goto L_1aec90;
L_1af18c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae508;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af1a0ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae508;
L_1af1a4:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae4e0;
L_1af1ac:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af1b4ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae4e8;
    goto L_1aec90;
L_1af1c0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae550;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af1d4ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae550;
L_1af1d8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae528;
L_1af1e0:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af1e8ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae578;
    goto L_1aec90;
L_1af1f4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae4c0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af208ULL; PB_CALL(169, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae4c0;
L_1af20c:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae498;
L_1af214:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af21cULL; PB_CALL(170, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae4a0;
    goto L_1aec90;
L_1af228:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae478;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af23cULL; PB_CALL(171, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae478;
L_1af240:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae450;
L_1af248:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae430;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af25cULL; PB_CALL(172, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae430;
L_1af260:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae408;
L_1af268:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af270ULL; PB_CALL(173, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae458;
    goto L_1aec90;
L_1af27c:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af284ULL; PB_CALL(174, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae410;
    goto L_1aec90;
L_1af290:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae3e8;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af2a4ULL; PB_CALL(175, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae3e8;
L_1af2a8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae3c0;
L_1af2b0:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af2b8ULL; PB_CALL(176, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae3c8;
    goto L_1aec90;
L_1af2c4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af2ccULL; PB_CALL(177, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae3a0;
L_1af2d0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae360;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af2e4ULL; PB_CALL(178, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae360;
L_1af2e8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae32c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af2fcULL; PB_CALL(179, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae32c;
L_1af300:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae304;
L_1af308:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af310ULL; PB_CALL(180, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae30c;
    goto L_1aec90;
L_1af31c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae2e4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af330ULL; PB_CALL(181, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae2e4;
L_1af334:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae2bc;
L_1af33c:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af344ULL; PB_CALL(182, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae2c4;
    goto L_1aec90;
L_1af350:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af358ULL; PB_CALL(183, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae29c;
L_1af35c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af364ULL; PB_CALL(184, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae25c;
L_1af368:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af370ULL; PB_CALL(185, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae21c;
L_1af374:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae1dc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af388ULL; PB_CALL(186, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae1dc;
L_1af38c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae1a8;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af3a0ULL; PB_CALL(187, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae1a8;
L_1af3a4:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae138;
L_1af3ac:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af3b4ULL; PB_CALL(188, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae188;
    goto L_1aec90;
L_1af3c0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ae160;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1af3d4ULL; PB_CALL(189, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae160;
L_1af3d8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_1ae180;
L_1af3e0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1af3e8ULL; PB_CALL(190, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ae118;
L_1af3ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1af404;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1af404:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    goto L_1ae0ec;
L_1af410:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1af418ULL; PB_CALL(191, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ae140;
    goto L_1aec90;
}
