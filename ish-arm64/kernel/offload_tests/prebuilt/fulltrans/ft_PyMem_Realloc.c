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

void ft_PyMem_Realloc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[0];
    if (((cpu->regs[1] >> 63) & 1)) goto L_e56c8;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[5] = PB_BASE + 0xe5000ULL;
    cpu->regs[5] = cpu->regs[5] + 1744ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[3] + 160));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 136));
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_NE) goto L_e56bc;
    if ((cpu->regs[4])==0) goto L_e56b8;
    cpu->regs[1] = cpu->regs[4];
    goto L_e56e0;
L_e56b8:
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xd8e84ULL); return; };
L_e56bc:
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[16] = cpu->regs[6];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_e56c8:
    cpu->regs[0] = 0ULL;
    return;
    if ((cpu->regs[1])==0) goto L_e56d8;
    goto L_e56e0;
L_e56d8:
    cpu->regs[1] = cpu->regs[2];
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xd8e84ULL); return; };
L_e56e0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe5710ULL; PB_CALL(3, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2248));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 48));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_e587c;
L_e572c:
    cpu->regs[0] = cpu->regs[19] >> 49;
    cpu->regs[6] = cpu->regs[19] & 18446744073709535232ULL;
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 5056));
    if ((cpu->regs[0])==0) goto L_e5848;
    cpu->regs[2] = ((cpu->regs[19] >> 34) & 0x7fffULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3)));
    if ((cpu->regs[0])==0) goto L_e5848;
    cpu->regs[3] = ((cpu->regs[19] >> 20) & 0x3fffULL);
    cpu->regs[2] = ((uint32_t)(cpu->regs[19] & 1048575ULL));
    cpu->regs[5] = cpu->regs[0] + (cpu->regs[3] << 3);
    cpu->regs[3] = cpu->regs[3] << 3;
    PB_LDRW(cpu->regs[5], (cpu->regs[5] + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_GT) goto L_e5778;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_e5848;
L_e5778:
    PB_LDRW(cpu->regs[20], (cpu->regs[6] + 36));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] << 4));
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_HI) goto L_e57a0;
    cpu->regs[0] = ((cpu->regs[20] & 0xffffffffULL) << 1);
    cpu->regs[20] = cpu->regs[0] + ((cpu->regs[20]) & 0xffffffffULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_LO) goto L_e5830;
    cpu->regs[20] = cpu->regs[1];
L_e57a0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe57a8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd8e84ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e58c4;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_LS) goto L_e57f0;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[20];
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_LO) goto L_e58cc;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe57d0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe57dcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdc12cULL);
L_e57dc:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_e57f0:
    if (FLAG_HS) goto L_e5800;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[20];
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_LO) goto L_e58cc;
L_e5800:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe5810ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe581cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdc12cULL);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_e5830:
    cpu->regs[22] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_e5848:
    if (((cpu->regs[1] >> 63) & 1)) goto L_e58c4;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 120));
    cpu->regs[0] = PB_BASE + 0xd7000ULL;
    cpu->regs[0] = cpu->regs[0] + 2064ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_e58a4;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    FLAG_CMP(cpu->regs[1], 0ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[1] : (0ULL + 1);
    { PB_CALL(9, cpu, tlb, PB_BASE + 0x7ac40ULL); return; };
L_e587c:
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 1712));
    if (!((cpu->regs[2] >> 5) & 1)) goto L_e572c;
    cpu->regs[2] = cpu->regs[4] + 24ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[2] = cpu->regs[4] + (18ULL << 12);
    cpu->regs[2] = cpu->regs[2] + 1936ULL;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[0];
    goto L_e572c;
L_e58a4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 96));
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_e58c4:
    cpu->regs[22] = 0ULL;
    goto L_e57dc;
L_e58cc:
    __builtin_trap();
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[13] = 4288ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    SP = SP - cpu->regs[13];
    PB_STR((SP + 1024), 0ULL);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 4280), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STRW((SP + 52), cpu->regs[2]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[27], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 16) + 8);
    PB_STR((SP + 40), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STR((SP + 80), cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 16), 0ULL); PB_STR((cpu->regs[19] + 16) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    if (FLAG_NE) goto L_e61b4;
L_e593c:
    FLAG_CMP(cpu->regs[27], 1ULL);
    if (FLAG_LE) goto L_e63e8;
    PB_LDR(cpu->regs[28], (SP + 40));
    cpu->regs[21] = 0ULL;
    PB_STR((SP + 32), 0ULL);
    PB_STR((SP + 4336), cpu->regs[23]);
    PB_STR((SP + 4344), cpu->regs[24]);
    PB_STR((SP + 4352), cpu->regs[25]);
    PB_STR((SP + 4360), cpu->regs[26]);
L_e5960:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[10] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[10], (cpu->regs[10] + 2640));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[10]);
    if (FLAG_EQ) goto L_e6834;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2280));
    cpu->regs[2] = cpu->regs[1];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[6] = (FLAG_EQ) ? 1 : 0;
L_e598c:
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 2520));
    cpu->regs[9] = cpu->regs[3];
    goto L_e59d0;
L_e59a4:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 16));
    FLAG_CMP(cpu->regs[1], 15ULL);
    if (FLAG_HI) goto L_e6b6c;
    FLAG_CMP(cpu->regs[2], cpu->regs[8]);
    if (FLAG_EQ) goto L_e59ec;
    cpu->regs[3] = 1ULL;
L_e59bc:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_GE) goto L_e5a0c;
L_e59c8:
    PB_LDR(cpu->regs[1], (cpu->regs[28] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
L_e59d0:
    PB_LDR(cpu->regs[4], (cpu->regs[28] + (cpu->regs[0] << 3)));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_e6a94;
    FLAG_CMP((((uint32_t)(cpu->regs[3]))) & (((uint32_t)(cpu->regs[6]))), 0);
    if (FLAG_NE) goto L_e59a4;
    FLAG_CMP(cpu->regs[2], cpu->regs[8]);
    if (FLAG_NE) goto L_e59bc;
L_e59ec:
    if ((((uint32_t)(cpu->regs[9])))==0) goto L_e59bc;
    PB_LDRW(cpu->regs[1], (cpu->regs[4] + 32));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 28ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    cpu->regs[9] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_LT) goto L_e59c8;
L_e5a0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(cpu->regs[9]))), 0);
    if (FLAG_NE) goto L_e6118;
L_e5a28:
    FLAG_CMP((((uint32_t)(cpu->regs[3]))) & (((uint32_t)(cpu->regs[6]))), 0);
    if (FLAG_EQ) goto L_e67dc;
    cpu->regs[20] = PB_BASE + 0x15d000ULL;
    cpu->regs[20] = cpu->regs[20] + 1924ULL;
    PB_STR((SP + 4256), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_e6814;
L_e5a40:
    PB_LDR(cpu->regs[0], (SP + 32));
    if ((cpu->regs[0])!=0) goto L_e6420;
    cpu->regs[0] = 256ULL;
    PB_STR((SP + 136), 0ULL); PB_STR((SP + 136) + 8, cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (SP + 52));
    cpu->regs[1] = SP + 2208ULL;
    PB_STRW((SP + 152), 0ULL);
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = 7ULL;
    PB_STR((SP + 72), cpu->regs[2]);
    PB_STR((SP + 104), cpu->regs[1]); PB_STR((SP + 104) + 8, cpu->regs[27]);
    PB_STR((SP + 120), cpu->regs[28]); PB_STR((SP + 120) + 8, cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_e6bb4;
    FLAG_CMP(cpu->regs[27], 63ULL);
    if (FLAG_GT) goto L_e678c;
    PB_STR((SP + 32), 0ULL);
    PB_STR((SP + 88), cpu->regs[27]);
L_e5a84:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = PB_BASE + 0x15d000ULL;
    cpu->regs[0] = cpu->regs[0] + 1924ULL;
    PB_STR((SP + 24), cpu->regs[27]);
    PB_STR((SP + 64), cpu->regs[0]);
L_e5a98:
    cpu->regs[0] = cpu->regs[1] << 3;
    cpu->regs[25] = cpu->regs[28] + (cpu->regs[1] << 3);
    FLAG_CMP(cpu->regs[0], 8ULL);
    if (FLAG_EQ) goto L_e6bec;
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[20] = PB_BASE + 0x15d000ULL;
    PB_LDR(cpu->regs[3], (SP + 4256));
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 0)); PB_LDR(cpu->regs[6], (cpu->regs[28] + 0) + 8);
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_e5df0;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[6] + 16));
    cpu->regs[4] = cpu->regs[4] & 3ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[8], (cpu->regs[6] + 24));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[2] = cpu->regs[3] - cpu->regs[2];
    cpu->regs[3] = cpu->regs[3] - cpu->regs[4];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[8];
    cpu->regs[3] = cpu->regs[3] * cpu->regs[0];
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_LT) goto L_e5e10;
    cpu->regs[0] = cpu->regs[28] + 16ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_HI) goto L_e5ee4;
L_e5b00:
    cpu->regs[4] = 2ULL;
L_e5b04:
    PB_LDR(cpu->regs[0], (SP + 88));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LE) goto L_e6418;
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[25] = cpu->regs[28] + (((cpu->regs[4]) & 0xffffffffULL) << 3);
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[28] + (cpu->regs[0] << 3);
    PB_STR((SP + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_LS) goto L_e5d00;
L_e5b34:
    cpu->regs[0] = cpu->regs[20] + 1924ULL;
    cpu->regs[26] = 1ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = SP + 104ULL;
    PB_STR((SP + 16), cpu->regs[0]);
L_e5b48:
    PB_LDR(cpu->regs[20], (cpu->regs[25] + 0));
    cpu->regs[22] = cpu->regs[25];
    cpu->regs[23] = cpu->regs[28];
L_e5b54:
    cpu->regs[0] = cpu->regs[22] - cpu->regs[23];
    PB_LDR(cpu->regs[11], (SP + 4256));
    cpu->regs[0] = (uint64_t)((int64_t)cpu->regs[0] >> 4);
    cpu->regs[24] = cpu->regs[23] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[23] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[0], (SP + 8));
    FLAG_CMP(cpu->regs[11], cpu->regs[0]);
    if (FLAG_NE) goto L_e60d4;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_LDRW(cpu->regs[11], (cpu->regs[20] + 24));
    cpu->regs[0] = cpu->regs[26] - cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[2] = cpu->regs[26] - cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[1];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[11];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_GE) goto L_e6c1c;
    FLAG_CMP(cpu->regs[23], cpu->regs[24]);
    if (FLAG_HS) goto L_e5cc0;
    cpu->regs[22] = cpu->regs[24];
L_e5bb0:
    cpu->regs[1] = cpu->regs[22] - cpu->regs[23];
    PB_LDRW(cpu->regs[11], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 4);
    cpu->regs[2] = cpu->regs[23] + (cpu->regs[1] << 3);
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_LDR(cpu->regs[10], (cpu->regs[23] + (cpu->regs[1] << 3)));
    cpu->regs[0] = cpu->regs[26] - cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[10] + 16));
    cpu->regs[0] = cpu->regs[0] * cpu->regs[11];
    PB_LDRW(cpu->regs[10], (cpu->regs[10] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[26] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] * cpu->regs[10];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_e5bf8;
    cpu->regs[23] = cpu->regs[2] + 8ULL;
    cpu->regs[2] = cpu->regs[22];
L_e5bf8:
    FLAG_CMP(cpu->regs[23], cpu->regs[2]);
    if (FLAG_HS) goto L_e5cc0;
    cpu->regs[1] = cpu->regs[2] - cpu->regs[23];
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 4);
    cpu->regs[9] = cpu->regs[23] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[10], (cpu->regs[23] + (cpu->regs[1] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[10] + 16));
    PB_LDRW(cpu->regs[10], (cpu->regs[10] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[26] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] * cpu->regs[10];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_e5c34;
    cpu->regs[23] = cpu->regs[9] + 8ULL;
    cpu->regs[9] = cpu->regs[2];
L_e5c34:
    FLAG_CMP(cpu->regs[23], cpu->regs[9]);
    if (FLAG_HS) goto L_e5cc0;
    cpu->regs[1] = cpu->regs[9] - cpu->regs[23];
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 4);
    cpu->regs[2] = cpu->regs[23] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[10], (cpu->regs[23] + (cpu->regs[1] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[10] + 16));
    PB_LDRW(cpu->regs[10], (cpu->regs[10] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[26] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] * cpu->regs[10];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_e5c70;
    cpu->regs[23] = cpu->regs[2] + 8ULL;
    cpu->regs[2] = cpu->regs[9];
L_e5c70:
    FLAG_CMP(cpu->regs[23], cpu->regs[2]);
    if (FLAG_HS) goto L_e5cc0;
    cpu->regs[11] = 1ULL;
L_e5c7c:
    cpu->regs[1] = cpu->regs[2] - cpu->regs[23];
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 4);
    cpu->regs[10] = cpu->regs[23] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[9], (cpu->regs[23] + (cpu->regs[1] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 16));
    PB_LDRW(cpu->regs[9], (cpu->regs[9] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[11] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] * cpu->regs[9];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_e6bac;
    cpu->regs[23] = cpu->regs[10] + 8ULL;
L_e5cac:
    FLAG_CMP(cpu->regs[23], cpu->regs[2]);
    if (FLAG_LO) goto L_e5c7c;
    /* nop */
    /* nop */
    /* nop */
L_e5cc0:
    FLAG_CMP(cpu->regs[23], cpu->regs[25]);
    if (FLAG_HS) goto L_e5ce8;
    cpu->regs[0] = cpu->regs[25] - 1ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[23];
    cpu->regs[0] = cpu->regs[0] >> 3;
    cpu->regs[1] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[25] - (cpu->regs[0] << 3);
    cpu->regs[2] = cpu->regs[1] << 3;
    cpu->regs[1] = cpu->regs[25] - (cpu->regs[1] << 3);
    cpu->regs[30] = PB_BASE + 0xe5ce8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b030ULL);
L_e5ce8:
    PB_STR((cpu->regs[23] + 0), cpu->regs[20]);
    if ((cpu->regs[21])!=0) goto L_e62e4;
L_e5cf0:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[25] = cpu->regs[25] + 8ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_LO) goto L_e5b48;
L_e5d00:
    PB_LDRW(cpu->regs[0], (SP + 152));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_e6620;
    PB_LDR(cpu->regs[2], (SP + 56));
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 152), cpu->regs[0]);
    PB_STR((SP + 160), cpu->regs[28]); PB_STR((SP + 160) + 8, cpu->regs[21]);
    cpu->regs[1] = cpu->regs[2] << 3;
    PB_STR((SP + 176), cpu->regs[2]);
    cpu->regs[28] = cpu->regs[28] + (cpu->regs[2] << 3);
    if ((cpu->regs[21])!=0) goto L_e6724;
L_e5d28:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2]; FLAG_CMP(cpu->regs[1], 0);
    PB_STR((SP + 24), cpu->regs[1]);
    if (FLAG_NE) goto L_e5a98;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_GT) goto L_e6794;
L_e5d40:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
L_e5d48:
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[25], (SP + 4352));
    PB_LDR(cpu->regs[26], (SP + 4360));
    if ((cpu->regs[0])!=0) goto L_e64e4;
L_e5d58:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_e6784;
    PB_LDRW(cpu->regs[0], (SP + 52));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[27], 1ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_GT) goto L_e6ab4;
L_e5d74:
    PB_LDR(cpu->regs[23], (SP + 4336));
    PB_LDR(cpu->regs[24], (SP + 4344));
L_e5d7c:
    PB_LDR(cpu->regs[1], (SP + 72));
    PB_LDR(cpu->regs[0], (SP + 128));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_e6aa4;
L_e5d8c:
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[20], (cpu->regs[19] + 16) + 8);
    PB_STR((cpu->regs[19] + 16), cpu->regs[27]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 80));
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    if ((cpu->regs[20])!=0) goto L_e6c84;
L_e5da4:
    if ((cpu->regs[21])==0) goto L_e5db4;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_e6cbc;
L_e5db4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 4280));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_e6af4;
    cpu->regs[13] = 4288ULL;
    SP = SP + cpu->regs[13];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_e5df0:
    cpu->regs[24] = SP + 104ULL;
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe5e00ULL; PB_CALL(11, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_e67d4;
    if (FLAG_EQ) goto L_e5ff8;
L_e5e10:
    cpu->regs[23] = cpu->regs[28] + 16ULL;
    cpu->regs[0] = PB_BASE + 0x15d000ULL;
    cpu->regs[24] = 2ULL;
    cpu->regs[26] = cpu->regs[0] + 1924ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_LS) goto L_e5e6c;
L_e5e28:
    PB_LDR(cpu->regs[4], (SP + 4256));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + -8)); PB_LDR(cpu->regs[0], (cpu->regs[23] + -8) + 8);
    FLAG_CMP(cpu->regs[4], cpu->regs[26]);
    if (FLAG_NE) goto L_e60a4;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[3] - cpu->regs[2];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 24));
    cpu->regs[4] = cpu->regs[4] & 3ULL;
    cpu->regs[4] = cpu->regs[3] - cpu->regs[4];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[6];
    cpu->regs[0] = cpu->regs[4] * cpu->regs[0];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LT) goto L_e6328;
L_e5e6c:
    cpu->regs[4] = cpu->regs[24];
L_e5e70:
    cpu->regs[1] = cpu->regs[4] << 3;
    cpu->regs[1] = cpu->regs[1] - 8ULL;
    cpu->regs[0] = cpu->regs[28] + cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[28]);
    if (FLAG_LS) goto L_e5ebc;
    PB_LDR(cpu->regs[2], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] - 8ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[28] + 0));
    PB_STR((cpu->regs[28] + 0), cpu->regs[2]);
    cpu->regs[2] = cpu->regs[28] + 8ULL;
    PB_STR((cpu->regs[28] + cpu->regs[1]), cpu->regs[3]);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_HS) goto L_e5ebc;
L_e5ea4:
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR(cpu->regs[2], cpu->regs[6]); cpu->regs[2] += 8;
    PB_STR(cpu->regs[0], cpu->regs[3]); cpu->regs[0] += -8;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LO) goto L_e5ea4;
L_e5ebc:
    if ((cpu->regs[21])==0) goto L_e5b04;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[21];
L_e5ec8:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_e5b04;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR(cpu->regs[0], cpu->regs[3]); cpu->regs[0] += 8;
    PB_STR(cpu->regs[1], cpu->regs[2]); cpu->regs[1] += -8;
    goto L_e5ec8;
L_e5ee4:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 16));
    cpu->regs[1] = cpu->regs[6];
L_e5eec:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[3] - cpu->regs[2];
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[4] = cpu->regs[4] & 3ULL;
    cpu->regs[0] = cpu->regs[3] - cpu->regs[4];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[6];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[1];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LT) goto L_e5b00;
    cpu->regs[6] = cpu->regs[28] + 24ULL;
    cpu->regs[23] = 3ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[6]);
    if (FLAG_LS) goto L_e603c;
L_e5f30:
    PB_LDR(cpu->regs[9], (cpu->regs[6] + -8)); PB_LDR(cpu->regs[8], (cpu->regs[6] + -8) + 8);
    cpu->regs[2] = 1ULL;
    cpu->regs[4] = cpu->regs[23];
    PB_LDR(cpu->regs[0], (cpu->regs[8] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[9] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_LDRW(cpu->regs[8], (cpu->regs[8] + 24));
    cpu->regs[0] = cpu->regs[2] - cpu->regs[0];
    PB_LDRW(cpu->regs[9], (cpu->regs[9] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[8];
    cpu->regs[1] = cpu->regs[1] * cpu->regs[9];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LT) goto L_e5b04;
    cpu->regs[1] = cpu->regs[6] + 8ULL;
    cpu->regs[4] = cpu->regs[23] + cpu->regs[2];
    FLAG_CMP(cpu->regs[25], cpu->regs[1]);
    if (FLAG_LS) goto L_e5b04;
    PB_LDR(cpu->regs[8], (cpu->regs[6] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 16));
    PB_LDRW(cpu->regs[9], (cpu->regs[8] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] * cpu->regs[9];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_e5b04;
    cpu->regs[6] = cpu->regs[6] + 16ULL;
    cpu->regs[23] = cpu->regs[23] + 2ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[6]);
    if (FLAG_LS) goto L_e61ac;
L_e5fac:
    PB_LDR(cpu->regs[4], (cpu->regs[6] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[8] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_LDRW(cpu->regs[9], (cpu->regs[4] + 24));
    cpu->regs[0] = cpu->regs[2] - cpu->regs[0];
    PB_LDRW(cpu->regs[8], (cpu->regs[8] + 24));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[1] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[8];
    cpu->regs[1] = cpu->regs[1] * cpu->regs[9];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LT) goto L_e61ac;
    cpu->regs[6] = cpu->regs[6] + 8ULL;
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[6]);
    if (FLAG_LS) goto L_e61ac;
    cpu->regs[8] = cpu->regs[4];
    goto L_e5fac;
L_e5ff8:
    cpu->regs[0] = cpu->regs[28] + 16ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_LS) goto L_e5b00;
    PB_LDR(cpu->regs[2], (SP + 64));
    PB_LDR(cpu->regs[3], (SP + 4256));
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 8)); PB_LDR(cpu->regs[0], (cpu->regs[28] + 8) + 8);
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_e5eec;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe6020ULL; PB_CALL(12, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_e67d4;
    if (FLAG_NE) goto L_e5b00;
    cpu->regs[0] = cpu->regs[28] + 24ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_HI) goto L_e6044;
L_e603c:
    cpu->regs[4] = 3ULL;
    goto L_e5b04;
L_e6044:
    PB_LDR(cpu->regs[2], (SP + 64));
    PB_LDR(cpu->regs[3], (SP + 4256));
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[28] + 16) + 8);
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_e6128;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDRW(cpu->regs[6], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[3] - cpu->regs[2];
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[4] = cpu->regs[4] & 3ULL;
    cpu->regs[0] = cpu->regs[3] - cpu->regs[4];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[6];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[1];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LT) goto L_e603c;
    cpu->regs[6] = cpu->regs[28] + 32ULL;
    cpu->regs[23] = 4ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[6]);
    if (FLAG_HI) goto L_e5f30;
L_e609c:
    cpu->regs[4] = 4ULL;
    goto L_e5b04;
L_e60a4:
    cpu->regs[2] = SP + 104ULL;
    cpu->regs[30] = PB_BASE + 0xe60acULL; PB_CALL(13, cpu, tlb, cpu->regs[4]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_e67d4;
    if (FLAG_EQ) goto L_e5e6c;
    cpu->regs[23] = cpu->regs[23] + 8ULL;
    cpu->regs[4] = cpu->regs[24] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_LS) goto L_e5e70;
    cpu->regs[24] = cpu->regs[4];
    goto L_e5e28;
L_e60d4:
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe60e0ULL; PB_CALL(14, cpu, tlb, cpu->regs[11]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_e67d4;
    if (FLAG_EQ) goto L_e6100;
    FLAG_CMP(cpu->regs[23], cpu->regs[24]);
    if (FLAG_HS) goto L_e5cc0;
    cpu->regs[22] = cpu->regs[24];
    goto L_e5b54;
L_e6100:
    cpu->regs[23] = cpu->regs[24] + 8ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_LS) goto L_e5cc0;
    cpu->regs[24] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[24];
    goto L_e5b54;
L_e6118:
    cpu->regs[0] = PB_BASE + 0xe6000ULL;
    cpu->regs[0] = cpu->regs[0] + 3328ULL;
    PB_STR((SP + 4256), cpu->regs[0]);
    goto L_e5a40;
L_e6128:
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe6130ULL; PB_CALL(15, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_e67d4;
    if (FLAG_NE) goto L_e603c;
    cpu->regs[6] = cpu->regs[28] + 32ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[6]);
    if (FLAG_LS) goto L_e609c;
    cpu->regs[0] = PB_BASE + 0x15d000ULL;
    cpu->regs[22] = cpu->regs[0] + 1924ULL;
    cpu->regs[23] = 4ULL;
L_e6158:
    PB_LDR(cpu->regs[4], (SP + 4256));
    PB_LDR(cpu->regs[1], (cpu->regs[6] + -8)); PB_LDR(cpu->regs[0], (cpu->regs[6] + -8) + 8);
    FLAG_CMP(cpu->regs[4], cpu->regs[22]);
    if (FLAG_NE) goto L_e63b0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[4] = 1ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 16));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDRW(cpu->regs[9], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[4] - cpu->regs[2];
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[8] = cpu->regs[8] & 3ULL;
    cpu->regs[0] = cpu->regs[4] - cpu->regs[8];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[9];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[1];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LT) goto L_e61ac;
    cpu->regs[6] = cpu->regs[6] + 8ULL;
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[6]);
    if (FLAG_HI) goto L_e5f30;
L_e61ac:
    cpu->regs[4] = cpu->regs[23];
    goto L_e5b04;
L_e61b4:
    if ((cpu->regs[20])==0) goto L_e593c;
    PB_STR((SP + 4336), cpu->regs[23]);
    PB_STR((SP + 4344), cpu->regs[24]);
    FLAG_CMP(cpu->regs[27], 127ULL);
    if (FLAG_GT) goto L_e6b74;
    PB_STR((SP + 4360), cpu->regs[26]);
    cpu->regs[26] = cpu->regs[27] + 264ULL;
    cpu->regs[24] = SP + 104ULL;
    PB_STR((SP + 4352), cpu->regs[25]);
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[26] << 3);
    PB_STR((SP + 32), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 4352));
    PB_LDR(cpu->regs[26], (SP + 4360));
    FLAG_CMP(cpu->regs[27], 0ULL);
    if (FLAG_LE) goto L_e64a4;
L_e61f0:
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe6200ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_LDR(cpu->regs[1], (SP + 32));
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e6c6c;
    FLAG_CMP(cpu->regs[27], 1ULL);
    if (FLAG_EQ) goto L_e64a0;
    PB_LDR(cpu->regs[21], (SP + 40));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[30] = PB_BASE + 0xe6224ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_LDR(cpu->regs[22], (SP + 32));
    PB_STR((cpu->regs[22] + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e6c38;
    FLAG_CMP(cpu->regs[27], 2ULL);
    if (FLAG_EQ) goto L_e62d4;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe6244ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_STR((cpu->regs[22] + 16), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e6ce0;
    FLAG_CMP(cpu->regs[27], 3ULL);
    if (FLAG_EQ) goto L_e62d4;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe6260ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_STR((cpu->regs[22] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e6cd8;
    FLAG_CMP(cpu->regs[27], 4ULL);
    if (FLAG_EQ) goto L_e62d4;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe627cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_STR((cpu->regs[22] + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e6ca0;
    FLAG_CMP(cpu->regs[27], 5ULL);
    if (FLAG_EQ) goto L_e62d4;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 40));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe6298ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_STR((cpu->regs[22] + 40), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e6c98;
    FLAG_CMP(cpu->regs[27], 6ULL);
    if (FLAG_EQ) goto L_e62d4;
    cpu->regs[21] = 6ULL;
L_e62ac:
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + (cpu->regs[21] << 3)));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe62bcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_LDR(cpu->regs[1], (SP + 32));
    PB_STR((cpu->regs[1] + (cpu->regs[21] << 3)), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e6c3c;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[27]);
    if (FLAG_NE) goto L_e62ac;
L_e62d4:
    PB_LDR(cpu->regs[28], (SP + 32)); PB_LDR(cpu->regs[21], (SP + 32) + 8);
    PB_STR((SP + 4352), cpu->regs[25]);
    PB_STR((SP + 4360), cpu->regs[26]);
    goto L_e5960;
L_e62e4:
    cpu->regs[0] = cpu->regs[21] - cpu->regs[28];
    cpu->regs[23] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[25] + cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[25] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[1], cpu->regs[23]);
    if (FLAG_LS) goto L_e6320;
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    cpu->regs[6] = 18446744073709551608ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[23];
    cpu->regs[0] = cpu->regs[0] >> 3;
    cpu->regs[2] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[0] * cpu->regs[6] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] - (cpu->regs[2] << 3);
    cpu->regs[2] = cpu->regs[2] << 3;
    cpu->regs[30] = PB_BASE + 0xe6320ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7b030ULL);
L_e6320:
    PB_STR((cpu->regs[23] + 0), cpu->regs[20]);
    goto L_e5cf0;
L_e6328:
    cpu->regs[0] = cpu->regs[23] + 8ULL;
    cpu->regs[4] = cpu->regs[24] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_LS) goto L_e5e70;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    PB_LDRW(cpu->regs[6], (cpu->regs[1] + 24));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    cpu->regs[0] = cpu->regs[3] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[6];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_GE) goto L_e5e70;
    cpu->regs[23] = cpu->regs[23] + 16ULL;
    cpu->regs[4] = cpu->regs[24] + 2ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_LS) goto L_e5e70;
L_e6368:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    PB_LDRW(cpu->regs[8], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    cpu->regs[0] = cpu->regs[3] - cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    cpu->regs[0] = cpu->regs[0] * cpu->regs[8];
    PB_LDRW(cpu->regs[6], (cpu->regs[1] + 24));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[2] = cpu->regs[3] - cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[6];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_GE) goto L_e5e70;
    cpu->regs[23] = cpu->regs[23] + 8ULL;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_HI) goto L_e6368;
    goto L_e5e70;
L_e63b0:
    cpu->regs[2] = cpu->regs[24];
    PB_STR((SP + 0), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0xe63bcULL; PB_CALL(24, cpu, tlb, cpu->regs[4]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_e67d4;
    PB_LDR(cpu->regs[6], (SP + 0));
    if (FLAG_NE) goto L_e61ac;
    cpu->regs[6] = cpu->regs[6] + 8ULL;
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[6]);
    if (FLAG_HI) goto L_e6158;
    cpu->regs[4] = cpu->regs[23];
    goto L_e5b04;
L_e63e8:
    cpu->regs[1] = 7ULL;
    PB_STR((SP + 104), cpu->regs[1]); PB_STR((SP + 104) + 8, cpu->regs[27]);
    cpu->regs[2] = SP + 2208ULL;
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[0] = 256ULL;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    PB_STR((SP + 72), cpu->regs[2]);
    PB_STR((SP + 120), cpu->regs[1]); PB_STR((SP + 120) + 8, cpu->regs[2]);
    PB_STR((SP + 136), 0ULL); PB_STR((SP + 136) + 8, cpu->regs[0]);
    PB_STRW((SP + 152), 0ULL);
    goto L_e5d7c;
L_e6418:
    PB_STR((SP + 56), cpu->regs[4]);
    goto L_e5d00;
L_e6420:
    cpu->regs[1] = cpu->regs[27] + 1ULL;
    cpu->regs[0] = 2ULL;
    cpu->regs[0] = (cpu->regs[0] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[0]) : 0);
    PB_STR((SP + 144), cpu->regs[0]);
    FLAG_CMP(cpu->regs[1], 257ULL);
    if (FLAG_GT) goto L_e6b08;
    cpu->regs[1] = 4288ULL;
    cpu->regs[1] = SP + cpu->regs[1];
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[0] << 3);
    cpu->regs[2] = SP + 2208ULL;
    cpu->regs[0] = cpu->regs[0] - 2080ULL;
    PB_STR((SP + 136), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (SP + 52));
    cpu->regs[1] = 7ULL;
    PB_STR((SP + 72), cpu->regs[2]);
    PB_STR((SP + 104), cpu->regs[1]); PB_STR((SP + 104) + 8, cpu->regs[27]);
    PB_STR((SP + 120), cpu->regs[28]); PB_STR((SP + 120) + 8, cpu->regs[2]);
    PB_STRW((SP + 152), 0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_e6b38;
L_e646c:
    PB_STR((SP + 88), cpu->regs[27]);
    FLAG_CMP(cpu->regs[27], 63ULL);
    if (FLAG_LE) goto L_e5a84;
L_e6478:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = 0ULL;
L_e6480:
    cpu->regs[1] = cpu->regs[0] & 1ULL;
    cpu->regs[0] = (uint64_t)((int64_t)cpu->regs[0] >> 1);
    cpu->regs[2] = cpu->regs[2] | cpu->regs[1];
    FLAG_CMP(cpu->regs[0], 63ULL);
    if (FLAG_GT) goto L_e6480;
    cpu->regs[0] = cpu->regs[2] + cpu->regs[0];
    PB_STR((SP + 88), cpu->regs[0]);
    goto L_e5a84;
L_e64a0:
    cpu->regs[24] = SP + 104ULL;
L_e64a4:
    cpu->regs[0] = cpu->regs[27] + 1ULL;
    cpu->regs[1] = 2ULL;
    cpu->regs[3] = SP + 2208ULL;
    cpu->regs[2] = 7ULL;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2760));
    PB_STR((SP + 72), cpu->regs[3]);
    cpu->regs[0] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[1]) : 0);
    PB_STR((SP + 104), cpu->regs[2]); PB_STR((SP + 104) + 8, cpu->regs[27]);
    PB_LDR(cpu->regs[1], (SP + 32));
    PB_STR((SP + 120), cpu->regs[1]); PB_STR((SP + 120) + 8, cpu->regs[3]);
    cpu->regs[1] = cpu->regs[0] + 263ULL;
    PB_STR((SP + 144), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[24] + (cpu->regs[1] << 3);
    PB_STR((SP + 136), cpu->regs[0]);
    PB_STRW((SP + 152), 0ULL);
L_e64e4:
    FLAG_CMP(cpu->regs[27], 0ULL);
    if (FLAG_LE) goto L_e6730;
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e650c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e650c;
    cpu->regs[30] = PB_BASE + 0xe650cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e650c:
    FLAG_CMP(cpu->regs[27], 1ULL);
    if (FLAG_EQ) goto L_e6778;
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e6534;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e6534;
    cpu->regs[30] = PB_BASE + 0xe6534ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e6534:
    FLAG_CMP(cpu->regs[27], 2ULL);
    if (FLAG_EQ) goto L_e5d58;
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e655c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e655c;
    cpu->regs[30] = PB_BASE + 0xe655cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e655c:
    FLAG_CMP(cpu->regs[27], 3ULL);
    if (FLAG_EQ) goto L_e5d58;
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e6584;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e6584;
    cpu->regs[30] = PB_BASE + 0xe6584ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e6584:
    FLAG_CMP(cpu->regs[27], 4ULL);
    if (FLAG_EQ) goto L_e5d58;
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e65ac;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e65ac;
    cpu->regs[30] = PB_BASE + 0xe65acULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e65ac:
    FLAG_CMP(cpu->regs[27], 5ULL);
    if (FLAG_EQ) goto L_e5d58;
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e65d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e65d4;
    cpu->regs[30] = PB_BASE + 0xe65d4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e65d4:
    FLAG_CMP(cpu->regs[27], 6ULL);
    if (FLAG_EQ) goto L_e5d58;
    cpu->regs[20] = 6ULL;
L_e65e0:
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[20] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e6600;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e6600;
    cpu->regs[30] = PB_BASE + 0xe6600ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e6600:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[27]);
    if (FLAG_NE) goto L_e65e0;
    FLAG_CMP(cpu->regs[27], 127ULL);
    if (FLAG_LE) goto L_e5d58;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0xe661cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_e5d58;
L_e6620:
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[24] = SP + 104ULL;
    cpu->regs[2] = cpu->regs[24] + 56ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = (((uint64_t)(((int64_t)(cpu->regs[1] << 32)) >> 32) & 0xffffffffULL) << 5);
    PB_LDR(cpu->regs[3], (SP + 120));
    cpu->regs[4] = cpu->regs[2] + cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + cpu->regs[1]));
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 16));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[3];
    PB_LDR(cpu->regs[4], (SP + 56));
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 3);
    PB_LDR(cpu->regs[3], (SP + 112));
    cpu->regs[1] = cpu->regs[2] + (cpu->regs[1] << 1);
    cpu->regs[2] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[2] = cpu->regs[2] + cpu->regs[4];
    goto L_e6674;
L_e6664:
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_LE) goto L_e668c;
L_e666c:
    cpu->regs[1] = cpu->regs[1] << 1;
    cpu->regs[2] = cpu->regs[2] << 1;
L_e6674:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_GT) goto L_e6664;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] - cpu->regs[3];
    goto L_e666c;
L_e668c:
    cpu->regs[25] = SP + 160ULL;
L_e6690:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_e66c8;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 2ULL));
    cpu->regs[2] = ((cpu->regs[1] & 0xffffffffULL) << 5);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[2] = cpu->regs[25] + cpu->regs[2];
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_LE) goto L_e66c8;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe66bcULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x12d1e0ULL);
    if ((cpu->regs[0])!=0) goto L_e67d4;
    PB_LDRW(cpu->regs[0], (SP + 152));
    goto L_e6690;
L_e66c8:
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[1] = 56ULL;
    cpu->regs[2] = 32ULL;
    cpu->regs[4] = (((uint64_t)(((int64_t)(cpu->regs[0] << 32)) >> 32) & 0xffffffffULL) << 5);
    cpu->regs[3] = (((uint64_t)(((int64_t)(cpu->regs[3] << 32)) >> 32) & 0xffffffffULL) << 5);
    cpu->regs[2] = cpu->regs[1] + (uint64_t)((int64_t)(int32_t)cpu->regs[0] * (int64_t)(int32_t)cpu->regs[2]);
    cpu->regs[3] = cpu->regs[25] + cpu->regs[3];
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    cpu->regs[1] = cpu->regs[1] + 2ULL;
    cpu->regs[2] = cpu->regs[24] + cpu->regs[2];
    PB_STRW((cpu->regs[3] + 24), cpu->regs[20]);
    cpu->regs[3] = SP + 112ULL;
    cpu->regs[1] = cpu->regs[1] << 5;
    PB_STR((cpu->regs[25] + cpu->regs[4]), cpu->regs[28]);
    PB_LDR(cpu->regs[4], (SP + 56));
    PB_STR((cpu->regs[2] + 8), cpu->regs[21]);
    PB_STR((cpu->regs[3] + cpu->regs[1]), cpu->regs[4]);
    PB_STRW((SP + 152), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[28] = cpu->regs[28] + (cpu->regs[4] << 3);
    cpu->regs[1] = cpu->regs[4] << 3;
    if ((cpu->regs[21])==0) goto L_e5d28;
L_e6724:
    PB_LDR(cpu->regs[2], (SP + 56));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[1];
    goto L_e5d28;
L_e6730:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e5d74;
    if ((cpu->regs[21])==0) goto L_e6768;
L_e6740:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 504ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xe6758ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_e6758:
    PB_LDRW(cpu->regs[0], (SP + 52));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[27], 1ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_GT) goto L_e6ab0;
L_e6768:
    PB_LDR(cpu->regs[23], (SP + 4336));
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[24], (SP + 4344));
    goto L_e5d7c;
L_e6778:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e5d74;
L_e6784:
    if ((cpu->regs[21])!=0) goto L_e6740;
    goto L_e6758;
L_e678c:
    PB_STR((SP + 32), 0ULL);
    goto L_e6478;
L_e6794:
    cpu->regs[3] = ((uint32_t)(cpu->regs[0] - 2ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_NE) goto L_e69cc;
L_e679c:
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[24] = SP + 104ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe67acULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x12d1e0ULL);
    if ((cpu->regs[0])!=0) goto L_e67d4;
L_e67b0:
    PB_LDRW(cpu->regs[0], (SP + 152));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_e5d40;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 2ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_e6a08;
    cpu->regs[1] = 0ULL;
L_e67c8:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe67d0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x12d1e0ULL);
    if ((cpu->regs[0])==0) goto L_e67b0;
L_e67d4:
    cpu->regs[21] = 0ULL;
    goto L_e5d48;
L_e67dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2216));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_e6a80;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 200));
    cpu->regs[1] = PB_BASE + 0x251000ULL;
    cpu->regs[0] = PB_BASE + 0x14a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3824ULL;
    cpu->regs[0] = cpu->regs[0] + 608ULL;
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    PB_STR((SP + 4256), cpu->regs[0]);
    PB_STR((SP + 4264), cpu->regs[3]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_e5a40;
L_e6814:
    FLAG_CMP(cpu->regs[2], cpu->regs[10]);
    if (FLAG_EQ) goto L_e6a3c;
L_e681c:
    PB_LDR(cpu->regs[0], (SP + 4256));
L_e6820:
    cpu->regs[1] = PB_BASE + 0x149000ULL;
    cpu->regs[1] = cpu->regs[1] + 3616ULL;
    PB_STR((SP + 4256), cpu->regs[1]);
    PB_STR((SP + 4272), cpu->regs[0]);
    goto L_e5a40;
L_e6834:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_e6cc4;
    PB_LDR(cpu->regs[8], (cpu->regs[0] + 24));
    cpu->regs[3] = 1ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2280));
    cpu->regs[11] = cpu->regs[3];
    PB_LDR(cpu->regs[2], (cpu->regs[8] + 8));
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[9] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[9], (cpu->regs[9] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[6]);
    cpu->regs[6] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[0] = 0ULL;
    if (((cpu->regs[27] >> 0) & 1)) goto L_e68ac;
    cpu->regs[1] = cpu->regs[8];
    cpu->regs[0] = 1ULL;
    if ((((uint32_t)(cpu->regs[6])))==0) goto L_e6a60;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 16));
    FLAG_CMP(cpu->regs[8], 15ULL);
    if (FLAG_HI) goto L_e6aec;
    FLAG_CMP(cpu->regs[2], cpu->regs[9]);
    if (FLAG_EQ) goto L_e6a68;
    cpu->regs[3] = cpu->regs[0];
L_e6898:
    cpu->regs[0] = 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_GE) goto L_e6954;
L_e68a4:
    PB_LDR(cpu->regs[8], (cpu->regs[28] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 8));
L_e68ac:
    FLAG_CMP(cpu->regs[1], cpu->regs[10]);
    if (FLAG_NE) goto L_e6a94;
    PB_LDR(cpu->regs[8], (cpu->regs[28] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 16));
    if ((cpu->regs[1])==0) goto L_e6a94;
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 24));
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[8]);
    if (FLAG_NE) goto L_e6cd0;
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_e68f4;
    FLAG_CMP((((uint32_t)(cpu->regs[3]))) & (((uint32_t)(cpu->regs[6]))), 0);
    if (FLAG_EQ) goto L_e6980;
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[8], 15ULL);
    if (FLAG_HI) goto L_e6a48;
    FLAG_CMP(cpu->regs[2], cpu->regs[9]);
    if (FLAG_EQ) goto L_e6988;
    cpu->regs[3] = cpu->regs[4];
L_e68f4:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_GE) goto L_e6954;
    PB_LDR(cpu->regs[8], (cpu->regs[28] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[10]);
    if (FLAG_NE) goto L_e6a94;
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 16));
    if ((cpu->regs[1])==0) goto L_e6a94;
    PB_LDR(cpu->regs[1], (cpu->regs[8] + 24));
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[8]);
    if (FLAG_NE) goto L_e6c2c;
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_e694c;
    FLAG_CMP((((uint32_t)(cpu->regs[3]))) & (((uint32_t)(cpu->regs[6]))), 0);
    if (FLAG_EQ) goto L_e69a4;
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[8], 15ULL);
    if (FLAG_HI) goto L_e6ae0;
    FLAG_CMP(cpu->regs[2], cpu->regs[9]);
    if (FLAG_EQ) goto L_e69ac;
    cpu->regs[3] = cpu->regs[4];
L_e694c:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_e68a4;
L_e6954:
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_e6a50;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(cpu->regs[11]))), 0);
    if (FLAG_EQ) goto L_e5a28;
    cpu->regs[0] = PB_BASE + 0xe6000ULL;
    cpu->regs[0] = cpu->regs[0] + 3328ULL;
    PB_STR((SP + 4256), cpu->regs[0]);
    goto L_e6814;
L_e6980:
    FLAG_CMP(cpu->regs[2], cpu->regs[9]);
    if (FLAG_NE) goto L_e68f4;
L_e6988:
    if ((((uint32_t)(cpu->regs[11])))==0) goto L_e68f4;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[4] = cpu->regs[11];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 28ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    cpu->regs[11] = (FLAG_EQ) ? 1 : 0;
    goto L_e68f4;
L_e69a4:
    FLAG_CMP(cpu->regs[2], cpu->regs[9]);
    if (FLAG_NE) goto L_e694c;
L_e69ac:
    if ((((uint32_t)(cpu->regs[11])))==0) goto L_e694c;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[4] = cpu->regs[11];
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 28ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    cpu->regs[11] = (FLAG_EQ) ? 1 : 0;
    goto L_e68a4;
L_e69cc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[1] = SP + 160ULL;
    cpu->regs[2] = ((cpu->regs[3] & 0xffffffffULL) << 5);
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    cpu->regs[0] = (((uint64_t)(((int64_t)(cpu->regs[0] << 32)) >> 32) & 0xffffffffULL) << 5);
    cpu->regs[2] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    PB_STR((SP + 24), cpu->regs[3]);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + -16));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_GE) goto L_e679c;
    cpu->regs[0] = cpu->regs[3] - 1ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    goto L_e679c;
L_e6a08:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[2] = SP + 160ULL;
    cpu->regs[3] = ((cpu->regs[1] & 0xffffffffULL) << 5);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[0] = (((uint64_t)(((int64_t)(cpu->regs[0] << 32)) >> 32) & 0xffffffffULL) << 5);
    cpu->regs[3] = cpu->regs[2] + cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] + cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + -16));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_GE) goto L_e67c8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    goto L_e67c8;
L_e6a3c:
    cpu->regs[0] = PB_BASE + 0x251000ULL;
    cpu->regs[0] = cpu->regs[0] + 3824ULL;
    goto L_e6820;
L_e6a48:
    cpu->regs[3] = 0ULL;
    goto L_e68f4;
L_e6a50:
    cpu->regs[0] = PB_BASE + 0x251000ULL;
    cpu->regs[0] = cpu->regs[0] + 3824ULL;
    PB_STR((SP + 4256), cpu->regs[0]);
    goto L_e6814;
L_e6a60:
    FLAG_CMP(cpu->regs[2], cpu->regs[9]);
    if (FLAG_NE) goto L_e6898;
L_e6a68:
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[4] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 28ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    cpu->regs[11] = (FLAG_EQ) ? 1 : 0;
    goto L_e6898;
L_e6a80:
    cpu->regs[0] = PB_BASE + 0x179000ULL;
    cpu->regs[0] = cpu->regs[0] + 332ULL;
    PB_STR((SP + 4256), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_e5a40;
    goto L_e681c;
L_e6a94:
    cpu->regs[0] = PB_BASE + 0x251000ULL;
    cpu->regs[0] = cpu->regs[0] + 3824ULL;
    PB_STR((SP + 4256), cpu->regs[0]);
    goto L_e5a40;
L_e6aa4:
    cpu->regs[30] = PB_BASE + 0xe6aa8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((SP + 128), 0ULL);
    goto L_e5d8c;
L_e6ab0:
    cpu->regs[21] = 0ULL;
L_e6ab4:
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[27] << 3);
    cpu->regs[0] = cpu->regs[0] - 8ULL;
    goto L_e6ad4;
L_e6ac4:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR(cpu->regs[1], cpu->regs[3]); cpu->regs[1] += 8;
    PB_STR(cpu->regs[0], cpu->regs[2]); cpu->regs[0] += -8;
L_e6ad4:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_e6ac4;
    goto L_e5d74;
L_e6ae0:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[3] = 0ULL;
    goto L_e68a4;
L_e6aec:
    cpu->regs[3] = 0ULL;
    goto L_e6898;
L_e6af4:
    PB_STR((SP + 4336), cpu->regs[23]);
    PB_STR((SP + 4344), cpu->regs[24]);
    PB_STR((SP + 4352), cpu->regs[25]);
    PB_STR((SP + 4360), cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0xe6b08ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e6b08:
    cpu->regs[0] = SP + 3232ULL;
    cpu->regs[1] = 128ULL;
    PB_STR((SP + 136), cpu->regs[0]); PB_STR((SP + 136) + 8, cpu->regs[1]);
    cpu->regs[2] = SP + 2208ULL;
    PB_LDRW(cpu->regs[0], (SP + 52));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = 7ULL;
    PB_STR((SP + 72), cpu->regs[3]);
    PB_STR((SP + 104), cpu->regs[2]); PB_STR((SP + 104) + 8, cpu->regs[27]);
    PB_STR((SP + 120), cpu->regs[28]); PB_STR((SP + 120) + 8, cpu->regs[3]);
    PB_STRW((SP + 152), 0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e6478;
L_e6b38:
    PB_LDR(cpu->regs[3], (SP + 32));
    cpu->regs[0] = cpu->regs[27] << 3;
    cpu->regs[1] = cpu->regs[0] - 8ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    goto L_e6b60;
L_e6b50:
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR(cpu->regs[2], cpu->regs[4]); cpu->regs[2] += 8;
    PB_STR(cpu->regs[1], cpu->regs[3]); cpu->regs[1] += -8;
L_e6b60:
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LO) goto L_e6b50;
    goto L_e6bbc;
L_e6b6c:
    cpu->regs[3] = 0ULL;
    goto L_e59bc;
L_e6b74:
    cpu->regs[0] = cpu->regs[27] << 3;
    cpu->regs[30] = PB_BASE + 0xe6b7cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdbd90ULL);
    PB_STR((SP + 32), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e61f0;
    cpu->regs[30] = PB_BASE + 0xe6b88ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x22d780ULL);
L_e6b88:
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[21], (cpu->regs[19] + 16) + 8);
    PB_STR((cpu->regs[19] + 16), cpu->regs[27]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 80));
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    if ((cpu->regs[21])!=0) goto L_e6c74;
    PB_LDR(cpu->regs[23], (SP + 4336));
    PB_LDR(cpu->regs[24], (SP + 4344));
    goto L_e5db4;
L_e6bac:
    cpu->regs[2] = cpu->regs[10];
    goto L_e5cac;
L_e6bb4:
    cpu->regs[0] = cpu->regs[27] << 3;
    PB_STR((SP + 32), 0ULL);
L_e6bbc:
    PB_LDR(cpu->regs[2], (SP + 40));
    cpu->regs[0] = cpu->regs[0] - 8ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[2] + cpu->regs[0];
    goto L_e6be0;
L_e6bd0:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR(cpu->regs[1], cpu->regs[3]); cpu->regs[1] += 8;
    PB_STR(cpu->regs[0], cpu->regs[2]); cpu->regs[0] += -8;
L_e6be0:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_e6bd0;
    goto L_e646c;
L_e6bec:
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[25] = cpu->regs[28] + 8ULL;
    PB_LDR(cpu->regs[1], (SP + 88));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[0] : cpu->regs[1];
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[28] + (cpu->regs[0] << 3);
    PB_STR((SP + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_LS) goto L_e5d00;
    cpu->regs[20] = PB_BASE + 0x15d000ULL;
    goto L_e5b34;
L_e6c1c:
    cpu->regs[23] = cpu->regs[24] + 8ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_HI) goto L_e5bb0;
    goto L_e5cc0;
L_e6c2c:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[4] = 0ULL;
    goto L_e68a4;
L_e6c38:
    cpu->regs[21] = 1ULL;
L_e6c3c:
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e6ca8;
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[21] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e6c3c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e6c3c;
    cpu->regs[30] = PB_BASE + 0xe6c68ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e6c3c;
L_e6c6c:
    cpu->regs[21] = 0ULL;
    goto L_e6c3c;
L_e6c74:
    PB_LDR(cpu->regs[23], (SP + 4336));
    cpu->regs[20] = cpu->regs[21];
    PB_LDR(cpu->regs[24], (SP + 4344));
    cpu->regs[21] = 0ULL;
L_e6c84:
    cpu->regs[22] = cpu->regs[22] - 1ULL; FLAG_CMP(cpu->regs[22], 0);
    if (FLAG_LT) goto L_e6ce8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[22] << 3)));
    cpu->regs[30] = PB_BASE + 0xe6c94ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_e6c84;
L_e6c98:
    cpu->regs[21] = 5ULL;
    goto L_e6c3c;
L_e6ca0:
    cpu->regs[21] = 4ULL;
    goto L_e6c3c;
L_e6ca8:
    FLAG_CMP(cpu->regs[27], 127ULL);
    if (FLAG_LE) goto L_e6b88;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0xe6cb8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_e6b88;
L_e6cbc:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_e5db4;
L_e6cc4:
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[6] = 0ULL;
    goto L_e598c;
L_e6cd0:
    cpu->regs[4] = 0ULL;
    goto L_e68f4;
L_e6cd8:
    cpu->regs[21] = 3ULL;
    goto L_e6c3c;
L_e6ce0:
    cpu->regs[21] = 2ULL;
    goto L_e6c3c;
L_e6ce8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe6cf0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_e5da4;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    cpu->regs[2] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[19];
    if (!((cpu->regs[3] >> 5) & 1)) goto L_e6d88;
    if (!((cpu->regs[3] >> 6) & 1)) goto L_e6d74;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 32));
    cpu->regs[0] = cpu->regs[0] + 40ULL;
    if (!((cpu->regs[3] >> 5) & 1)) goto L_e6d80;
L_e6d34:
    if (!((cpu->regs[3] >> 6) & 1)) goto L_e6d54;
    cpu->regs[1] = cpu->regs[1] + 40ULL;
    cpu->regs[30] = PB_BASE + 0xe6d40ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x7ab70ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e6d60;
L_e6d44:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_e6d54:
    cpu->regs[1] = cpu->regs[1] + 56ULL;
L_e6d58:
    cpu->regs[30] = PB_BASE + 0xe6d5cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7ab70ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_e6d44;
L_e6d60:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    cpu->regs[0] = (FLAG_LT) ? 1 : 0;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_e6d74:
    cpu->regs[0] = cpu->regs[0] + 56ULL;
L_e6d78:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 32));
    if (((cpu->regs[3] >> 5) & 1)) goto L_e6d34;
L_e6d80:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 56));
    goto L_e6d58;
L_e6d88:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    goto L_e6d78;
}
