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

void ft__PyCodecInfo_GetIncrementalDecoder(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = cpu->regs[2] + 1008ULL;
    goto L_1d6f2c;
L_1d6f2c:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1d6f44ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d6f7c;
    if ((cpu->regs[20])==0) goto L_1d6f8c;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    cpu->regs[30] = PB_BASE + 0x1d6f60ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe6d90ULL);
    cpu->regs[20] = cpu->regs[0];
L_1d6f64:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d6f78;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d6f98;
L_1d6f78:
    cpu->regs[19] = cpu->regs[20];
L_1d6f7c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1d6f8c:
    cpu->regs[30] = PB_BASE + 0x1d6f90ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x179564ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_1d6f64;
L_1d6f98:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d6fa4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d6f7c;
    SP = SP - 96ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[1] = SP;
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 32));
    PB_STR((SP + 80), cpu->regs[25]);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[3] = 60928ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[24] + cpu->regs[3];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d700cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x147564ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d7120;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1d701cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[25] = SP;
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1d7108;
L_1d702c:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d7120;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1d7078;
L_1d703c:
    cpu->regs[0] = 0ULL;
L_1d7040:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d7104;
    PB_LDR(cpu->regs[25], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_1d7078:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    if ((cpu->regs[0])!=0) goto L_1d7128;
L_1d7080:
    PB_STR((cpu->regs[20] + 104), 0ULL);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d7090ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d79e8ULL);
    PB_STR((cpu->regs[20] + 48), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d7120;
    cpu->regs[0] = 51144ULL;
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d70acULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d7120;
    PB_LDR(cpu->regs[21], (SP + 0));
    if ((cpu->regs[21])==0) goto L_1d70f8;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1d70f8;
    cpu->regs[19] = PB_BASE + 0x3db000ULL;
    cpu->regs[19] = cpu->regs[19] + 2816ULL;
    cpu->regs[19] = cpu->regs[19] + 192ULL;
L_1d70d4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((cpu->regs[1])==0) goto L_1d70f8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d70e4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d70f0;
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    goto L_1d70d4;
L_1d70f0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_STR((cpu->regs[20] + 104), cpu->regs[0]);
L_1d70f8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d7100ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1d703c;
L_1d7104:
    cpu->regs[30] = PB_BASE + 0x1d7108ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d7108:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d702c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d711cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d702c;
L_1d7120:
    cpu->regs[0] = 4294967295ULL;
    goto L_1d7040;
L_1d7128:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 48), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d7080;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d7080;
    cpu->regs[30] = PB_BASE + 0x1d7144ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d7080;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    return;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 32ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1d71e0;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = 56016ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x1d71b4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x147564ULL);
L_1d71b4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d71dc;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_1d71dc:
    cpu->regs[30] = PB_BASE + 0x1d71e0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d71e0:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 28));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1d7208;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x1d7200ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d71b4;
L_1d7208:
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0x1d7214ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d71b4;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 16));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d729c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = ((uint64_t)(((int64_t)(cpu->regs[1] << (62-36)) ) >> 62));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1d726c;
L_1d7244:
    cpu->regs[1] = ((uint64_t)(((int64_t)(cpu->regs[1] << (62-36)) ) >> 62));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_1d7264:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1d726c:
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d727cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1cc284ULL);
    if ((cpu->regs[0])==0) goto L_1d7290;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1d72bc;
L_1d7288:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    goto L_1d7244;
L_1d7290:
    cpu->regs[30] = PB_BASE + 0x1d7294ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    goto L_1d7244;
L_1d729c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d72b4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d7264;
L_1d72bc:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1d7288;
    cpu->regs[30] = PB_BASE + 0x1d72ccULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    goto L_1d7244;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 80ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 93));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1d7318;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])!=0) goto L_1d7348;
L_1d7318:
    cpu->regs[0] = 0ULL;
L_1d731c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d7418;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_1d7348:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[0] = 1ULL;
    cpu->regs[1] = 58944ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    PB_STRB((cpu->regs[19] + 112), cpu->regs[0]);
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x1d737cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d7420;
    cpu->regs[1] = cpu->regs[22] + 3208ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1d7390ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1d7400;
L_1d739c:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1d7420;
    if (FLAG_EQ) goto L_1d73b0;
L_1d73a8:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_1d7318;
L_1d73b0:
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 48));
    cpu->regs[4] = cpu->regs[22] + 3208ULL;
    PB_STRB((cpu->regs[19] + 112), 0ULL);
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = 56752ULL;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[22] + cpu->regs[0];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 8), cpu->regs[5]); PB_STR((SP + 8) + 8, cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1d73dcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1d7420;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1d73a8;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1d73a8;
    cpu->regs[30] = PB_BASE + 0x1d73f8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_1d7318;
L_1d7400:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d739c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d7414ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d739c;
L_1d7418:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1d7420ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d7420:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_1d731c;
}
