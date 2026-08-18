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

void ft__PyImport_ClearExtension(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xac274ULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[20], (cpu->regs[2] + 16));
    cpu->regs[30] = PB_BASE + 0xac28cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1a2770ULL);
    if ((cpu->regs[0])!=0) goto L_ac2a0;
    cpu->regs[30] = PB_BASE + 0xac294ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
    goto L_ac370;
L_ac2a0:
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if ((cpu->regs[0])==0) goto L_ac2cc;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 32), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_ac2cc;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_ac2cc;
    cpu->regs[30] = PB_BASE + 0xac2ccULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_ac2cc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])!=0) goto L_ac2f4;
L_ac2d4:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1920));
    cpu->regs[30] = PB_BASE + 0xac2e8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1928));
    if ((cpu->regs[0])!=0) goto L_ac31c;
    goto L_ac330;
L_ac2f4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 952));
    if ((cpu->regs[0])==0) goto L_ac2d4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_ac2d4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xac310ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xa0c4cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ac2d4;
    goto L_ac370;
L_ac31c:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xac328ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x190e28ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_ac338;
L_ac330:
    cpu->regs[19] = 0ULL;
    goto L_ac358;
L_ac338:
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1928));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0xac348ULL; PB_CALL(8, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_ac358;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_ac358;
    PB_STR((cpu->regs[0] + 24), 0ULL);
L_ac358:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1920));
    cpu->regs[30] = PB_BASE + 0xac360ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x17faa0ULL);
    if ((cpu->regs[19])==0) goto L_ac36c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xac36cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd7784ULL);
L_ac36c:
    cpu->regs[0] = 0ULL;
L_ac370:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_EQ) goto L_ac3d4;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1480ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xac3d0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ac404;
L_ac3d4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_ac40c;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = cpu->regs[0] + 1480ULL;
    cpu->regs[30] = PB_BASE + 0xac404ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x23b310ULL);
L_ac404:
    cpu->regs[0] = 0ULL;
    goto L_ac460;
L_ac40c:
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xac414ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ac404;
    cpu->regs[30] = PB_BASE + 0xac420ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_ac448;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xac444ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_ac404;
L_ac448:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xac454ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1c7960ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ac404;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ac460:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ac480;
    cpu->regs[30] = PB_BASE + 0xac480ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ac480:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 96ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_ac4fc;
L_ac4c8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 28) & 1)) goto L_ac51c;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 1496ULL;
    cpu->regs[30] = PB_BASE + 0xac4f8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_ac630;
L_ac4fc:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1496ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xac514ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ac4c8;
    goto L_ac630;
L_ac51c:
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0xac524ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ac630;
    cpu->regs[30] = PB_BASE + 0xac530ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[2], (SP + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_ac558;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xac554ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_ac630;
L_ac558:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0xac564ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ac630;
    PB_LDRW(cpu->regs[22], (SP + 8));
    cpu->regs[21] = SP + 12ULL;
    cpu->regs[1] = 65537ULL;
L_ac574:
    PB_STRW((SP + 12), cpu->regs[1]);
L_ac578:
    if (((cpu->regs[1] >> 31) & 1)) goto L_ac5cc;
    cpu->regs[0] = ((cpu->regs[1] & 0xffffffffULL) << 2);
    cpu->regs[30] = PB_BASE + 0xac584ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ac5cc;
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[23], (SP + 12));
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xac5a4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7b9c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ac5e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xac5b4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[1], (SP + 12));
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LT) goto L_ac578;
    cpu->regs[0] = 1073741823ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_ac5d8;
L_ac5cc:
    cpu->regs[30] = PB_BASE + 0xac5d0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_ac658;
L_ac5d8:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] << 1));
    goto L_ac574;
L_ac5e0:
    do { int32_t _s=0; tlb_read(tlb,(SP + 12),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xac5ecULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_ac604;
    goto L_ac628;
L_ac5f8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_STR((cpu->regs[1] + (cpu->regs[22] << 3)), cpu->regs[0]);
L_ac604:
    PB_LDRW(cpu->regs[0], (SP + 12));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_GE) goto L_ac650;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 2)));
    cpu->regs[22] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    cpu->regs[30] = PB_BASE + 0xac61cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x7aff0ULL);
    if ((cpu->regs[0])!=0) goto L_ac5f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ac638;
L_ac628:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xac630ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_ac630:
    cpu->regs[19] = 0ULL;
    goto L_ac658;
L_ac638:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_ac628;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xac64cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_ac628;
L_ac650:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xac658ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_ac658:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_ac678;
    cpu->regs[30] = PB_BASE + 0xac678ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ac678:
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
    SP = SP - 144ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[1];
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[26], (cpu->regs[24] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    FLAG_CMP(cpu->regs[26], 749ULL);
    if (FLAG_GT) goto L_ac7cc;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xac6e8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ac7cc;
    cpu->regs[0] = 320ULL;
    cpu->regs[30] = PB_BASE + 0xac6f8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_ac7d4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_ac828;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    SP = SP + 144ULL;
    { PB_CALL(36, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_ac73c:
    PB_LDR(cpu->regs[1], (SP + 24)); PB_LDR(cpu->regs[3], (SP + 24) + 8);
    cpu->regs[4] = cpu->regs[21] - 1ULL;
    cpu->regs[5] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[6] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[6] = cpu->regs[6] + 3ULL;
    cpu->regs[6] = cpu->regs[6] << 1;
    cpu->regs[6] = (cpu->regs[27] ? (uint64_t)((int64_t)cpu->regs[6] / (int64_t)cpu->regs[27]) : 0);
    FLAG_CMP(cpu->regs[4], cpu->regs[6]);
    cpu->regs[4] = (FLAG_LE) ? cpu->regs[4] : cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0xac768ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x87a20ULL);
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_LT) goto L_ac788;
    FLAG_CMP(cpu->regs[28], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    cpu->regs[20] = (FLAG_GT) ? cpu->regs[20] : cpu->regs[28];
    cpu->regs[0] = (FLAG_GT) ? cpu->regs[0] : cpu->regs[21];
    cpu->regs[28] = cpu->regs[20];
    cpu->regs[21] = cpu->regs[0];
L_ac788:
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
L_ac78c:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    FLAG_CMP(cpu->regs[26], cpu->regs[22]);
    if (FLAG_LE) goto L_ac7f0;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 24));
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[20], (cpu->regs[2] + (cpu->regs[1] << 3)));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xac7acULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x12b670ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ac788;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xac7bcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_ac73c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xac7ccULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_ac7cc:
    cpu->regs[28] = 0ULL;
    goto L_ac80c;
L_ac7d4:
    cpu->regs[0] = SP + 32ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[28] = 0ULL;
    cpu->regs[21] = 9223372036854775807ULL;
    cpu->regs[27] = 6ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    goto L_ac78c;
L_ac7f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xac7f8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    if ((cpu->regs[28])==0) goto L_ac7cc;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_ac80c;
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
L_ac80c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_ac82c;
L_ac828:
    cpu->regs[30] = PB_BASE + 0xac82cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ac82c:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[28];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    SP = SP + 144ULL;
    return;
}
