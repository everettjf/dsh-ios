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

void ft_PyObject_Repr(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 48ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14d67cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x12cde0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14d784;
    if ((cpu->regs[19])==0) goto L_14d80c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 88));
    if ((cpu->regs[2])==0) goto L_14d78c;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x14d6a4ULL; PB_CALL(2, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[20], (cpu->regs[1] + cpu->regs[0]));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_14d73c;
    cpu->regs[0] = PB_BASE + 0x12d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3788ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_14d768;
L_14d6cc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = SP;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14d6e4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x12df40ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14d7ac;
    PB_LDR(cpu->regs[19], (SP + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[0]);
    if ((cpu->regs[19])==0) goto L_14d784;
L_14d700:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_14d7c0;
L_14d70c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_14d7a8;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_14d73c:
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 480ULL;
    cpu->regs[30] = PB_BASE + 0x14d74cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x26c444ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14d784;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x12d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3788ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 88));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_14d6cc;
L_14d768:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x14d770ULL; PB_CALL(5, cpu, tlb, cpu->regs[2]);
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 36));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[1]);
    if ((cpu->regs[0])!=0) goto L_14d700;
L_14d784:
    cpu->regs[19] = 0ULL;
    goto L_14d70c;
L_14d78c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_14d840;
L_14d7a8:
    cpu->regs[30] = PB_BASE + 0x14d7acULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_14d7ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[0]);
    goto L_14d70c;
L_14d7c0:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2736));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 24));
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    cpu->regs[2] = cpu->regs[2] + 520ULL;
    cpu->regs[30] = PB_BASE + 0x14d7e0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x225d40ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_14d784;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_14d784;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x14d808ULL; PB_CALL(8, cpu, tlb, cpu->regs[1]);
    goto L_14d70c;
L_14d80c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_14d7a8;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 824ULL;
    SP = SP + 48ULL;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
L_14d840:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    SP = SP + 48ULL;
    cpu->regs[0] = cpu->regs[0] + 456ULL;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    if (!((cpu->regs[20] >> 5) & 1)) goto L_14e05c;
    if (!((cpu->regs[20] >> 6) & 1)) goto L_14dcc8;
    cpu->regs[20] = ((uint32_t)(((cpu->regs[20] >> 2) & 0x7ULL)));
    cpu->regs[24] = cpu->regs[0] + 40ULL;
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_14dcd8;
L_14d89c:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14dde4;
    cpu->regs[7] = 9223372036854775807ULL;
    cpu->regs[6] = cpu->regs[24];
    cpu->regs[9] = cpu->regs[7] - 4ULL;
    cpu->regs[8] = cpu->regs[23] + cpu->regs[24];
    cpu->regs[1] = 127ULL;
    cpu->regs[12] = 0ULL;
    cpu->regs[11] = 0ULL;
    cpu->regs[19] = 0ULL;
    if (((cpu->regs[23] >> 0) & 1)) goto L_14daa0;
L_14d8c8:
    PB_LDRB(cpu->regs[5], (cpu->regs[6] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_14dd8c;
    if (FLAG_HI) goto L_14da18;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(10ULL)));
    if (FLAG_HI) goto L_14da80;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(8ULL)));
    if (FLAG_HI) goto L_14dd04;
    cpu->regs[10] = cpu->regs[9];
    cpu->regs[3] = 4ULL;
L_14d8f0:
    FLAG_CMP(cpu->regs[19], cpu->regs[10]);
    if (FLAG_GT) goto L_14da60;
    /* nop */
    /* nop */
L_14d900:
    PB_LDRB(cpu->regs[5], (cpu->regs[6] + 1));
    cpu->regs[19] = cpu->regs[19] + cpu->regs[3];
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_14dd7c;
    if (FLAG_HI) goto L_14d9d4;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(10ULL)));
    if (FLAG_LS) goto L_14da48;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_14dd14;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(31ULL)));
    if (FLAG_LS) goto L_14da08;
L_14d930:
    FLAG_CMP(cpu->regs[19], cpu->regs[7]);
    if (FLAG_EQ) goto L_14da60;
    cpu->regs[3] = 1ULL;
L_14d93c:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[3];
    FLAG_CMP(cpu->regs[8], cpu->regs[6]);
    if (FLAG_NE) goto L_14d8c8;
L_14d94c:
    FLAG_CMP(cpu->regs[23], cpu->regs[19]);
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[11])!=0) goto L_14dd64;
    cpu->regs[0] = cpu->regs[19] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14d960ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14da78;
    cpu->regs[21] = 39ULL;
L_14d96c:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 32));
    cpu->regs[9] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_14e470;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_14db44;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[7] = cpu->regs[25] + 40ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14db54;
L_14d98c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[21] & 255ULL));
    PB_STRB((cpu->regs[7] + 0), cpu->regs[1]);
    PB_STRB((cpu->regs[7] + cpu->regs[19]), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_14db6c;
L_14d99c:
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x14d9b8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11ae68ULL);
L_14d9b8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_14d9d4:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(39ULL)));
    if (FLAG_EQ) goto L_14dd9c;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_14dd14;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(127ULL)));
    if (FLAG_EQ) goto L_14da08;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(126ULL)));
    if (FLAG_LS) goto L_14d930;
    cpu->regs[0] = cpu->regs[5];
    PB_STRW((SP + 108), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14da00ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x10a1d0ULL);
    PB_LDRW(cpu->regs[1], (SP + 108));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14dc88;
L_14da08:
    cpu->regs[10] = 18446744073709551611ULL;
    cpu->regs[3] = 4ULL;
    cpu->regs[10] = (cpu->regs[10] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14da58;
L_14da18:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(39ULL)));
    if (FLAG_EQ) goto L_14ddac;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_14dd04;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(127ULL)));
    if (FLAG_EQ) goto L_14da90;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_14db1c;
L_14da38:
    FLAG_CMP(cpu->regs[19], cpu->regs[7]);
    if (FLAG_EQ) goto L_14da60;
    cpu->regs[3] = 1ULL;
    goto L_14d900;
L_14da48:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(8ULL)));
    if (FLAG_HI) goto L_14dd14;
    cpu->regs[10] = cpu->regs[9];
    cpu->regs[3] = 4ULL;
L_14da58:
    FLAG_CMP(cpu->regs[19], cpu->regs[10]);
    if (FLAG_LE) goto L_14d93c;
L_14da60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 568ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x14da78ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_14da78:
    cpu->regs[25] = 0ULL;
    goto L_14d9b8;
L_14da80:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_14dd04;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(31ULL)));
    if (FLAG_HI) goto L_14da38;
L_14da90:
    cpu->regs[10] = 18446744073709551611ULL;
    cpu->regs[3] = 4ULL;
    cpu->regs[10] = (cpu->regs[10] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14d8f0;
L_14daa0:
    PB_LDRB(cpu->regs[5], (cpu->regs[24] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_14dffc;
    if (FLAG_HI) goto L_14dad0;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(10ULL)));
    if (FLAG_HI) goto L_14db08;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(8ULL)));
    if (FLAG_HI) goto L_14df90;
L_14dac0:
    cpu->regs[10] = cpu->regs[9];
    cpu->regs[3] = 4ULL;
    if (!((cpu->regs[10] >> 63) & 1)) goto L_14daf4;
    goto L_14da60;
L_14dad0:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(39ULL)));
    if (FLAG_EQ) goto L_14df7c;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_14df90;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(127ULL)));
    if (FLAG_EQ) goto L_14dac0;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_14dc9c;
L_14daf0:
    cpu->regs[3] = 1ULL;
L_14daf4:
    cpu->regs[6] = cpu->regs[24] + 1ULL;
    cpu->regs[19] = cpu->regs[3];
    FLAG_CMP(cpu->regs[8], cpu->regs[6]);
    if (FLAG_NE) goto L_14d8c8;
    goto L_14d94c;
L_14db08:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_14df90;
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(31ULL)));
    if (FLAG_HI) goto L_14daf0;
    goto L_14dac0;
L_14db1c:
    cpu->regs[0] = cpu->regs[5];
    PB_STRW((SP + 108), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14db28ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x10a1d0ULL);
    PB_LDRW(cpu->regs[1], (SP + 108));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14da90;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[5])));
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : cpu->regs[5];
    cpu->regs[3] = 1ULL;
    goto L_14d8f0;
L_14db44:
    cpu->regs[7] = cpu->regs[25] + 56ULL;
L_14db48:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_14d98c;
L_14db54:
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_14e024;
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] & 65535ULL));
    PB_STRH((cpu->regs[7] + 0), cpu->regs[0]);
    PB_STRH((cpu->regs[7] + (cpu->regs[19] << 1)), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_14d99c;
L_14db6c:
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_14d9b8;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14e120;
    cpu->regs[12] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[12], (cpu->regs[12] + 2576));
    cpu->regs[23] = cpu->regs[24] + cpu->regs[23];
    cpu->regs[6] = 1ULL;
L_14db8c:
    PB_LDRB(cpu->regs[4], (cpu->regs[24] + 0));
    cpu->regs[8] = cpu->regs[6] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(92ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_14ddbc;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_14dd3c;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_14dc60;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_14e034;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(127ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], 31ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_14dfa0;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_14dbfc;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14dbec;
    PB_STRB((cpu->regs[7] + cpu->regs[6]), cpu->regs[4]);
L_14dbd8:
    cpu->regs[6] = cpu->regs[8];
L_14dbdc:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[24]);
    if (FLAG_NE) goto L_14db8c;
    goto L_14d9b8;
L_14dbec:
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_14dd74;
    PB_STRH((cpu->regs[7] + (cpu->regs[6] << 1)), cpu->regs[4]);
    goto L_14dbd8;
L_14dbfc:
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x14dc04ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x10a1d0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14dd24;
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x14dc1cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[3] = 120ULL;
    cpu->regs[30] = PB_BASE + 0x14dc28ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11ce20ULL);
    PB_LDR(cpu->regs[13], (cpu->regs[12] + 0));
    cpu->regs[3] = ((cpu->regs[4] >> 4) & 0xfULL);
    cpu->regs[11] = cpu->regs[6] + 2ULL;
    cpu->regs[4] = cpu->regs[4] & 15ULL;
    cpu->regs[2] = cpu->regs[11];
    cpu->regs[8] = cpu->regs[6] + 3ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[13] + cpu->regs[3]));
    cpu->regs[6] = cpu->regs[6] + 4ULL;
    cpu->regs[30] = PB_BASE + 0x14dc4cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[8];
    PB_LDR(cpu->regs[3], (cpu->regs[12] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[4]));
    cpu->regs[30] = PB_BASE + 0x14dc5cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14dbdc;
L_14dc60:
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[6] = cpu->regs[6] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14dc78ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[3] = 110ULL;
    cpu->regs[30] = PB_BASE + 0x14dc84ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14dbdc;
L_14dc88:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[5])));
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : cpu->regs[5];
    cpu->regs[3] = 1ULL;
    goto L_14da58;
L_14dc9c:
    cpu->regs[0] = cpu->regs[5];
    PB_STRW((SP + 108), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14dca8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x10a1d0ULL);
    PB_LDRW(cpu->regs[1], (SP + 108));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14dac0;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[5])));
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : cpu->regs[5];
    cpu->regs[3] = 1ULL;
    if (!((cpu->regs[10] >> 63) & 1)) goto L_14daf4;
    goto L_14da60;
L_14dcc8:
    cpu->regs[24] = cpu->regs[0] + 56ULL;
L_14dccc:
    cpu->regs[20] = ((uint32_t)(((cpu->regs[20] >> 2) & 0x7ULL)));
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_GT) goto L_14d89c;
L_14dcd8:
    FLAG_CMP(cpu->regs[23], 0ULL);
    cpu->regs[1] = 127ULL;
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[21] = 39ULL;
    cpu->regs[19] = 0ULL;
L_14dcec:
    cpu->regs[0] = cpu->regs[19] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14dcf4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_14d96c;
    cpu->regs[25] = 0ULL;
    goto L_14d9b8;
L_14dd04:
    cpu->regs[10] = 18446744073709551613ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[10] = (cpu->regs[10] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14d8f0;
L_14dd14:
    cpu->regs[10] = 18446744073709551613ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[10] = (cpu->regs[10] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14da58;
L_14dd24:
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x14dd38ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14dbd8;
L_14dd3c:
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[6] = cpu->regs[6] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14dd54ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[3] = 116ULL;
    cpu->regs[30] = PB_BASE + 0x14dd60ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14dbdc;
L_14dd64:
    if ((cpu->regs[12])!=0) goto L_14de98;
    cpu->regs[22] = 0ULL;
    cpu->regs[21] = 34ULL;
    goto L_14dcec;
L_14dd74:
    PB_STRW((cpu->regs[7] + (cpu->regs[6] << 2)), cpu->regs[4]);
    goto L_14dbd8;
L_14dd7c:
    cpu->regs[12] = cpu->regs[12] + 1ULL;
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[3] = 1ULL;
    goto L_14da58;
L_14dd8c:
    cpu->regs[12] = cpu->regs[12] + 1ULL;
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[3] = 1ULL;
    goto L_14d8f0;
L_14dd9c:
    cpu->regs[11] = cpu->regs[11] + 1ULL;
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[3] = 1ULL;
    goto L_14da58;
L_14ddac:
    cpu->regs[11] = cpu->regs[11] + 1ULL;
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[3] = 1ULL;
    goto L_14d8f0;
L_14ddbc:
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[6] = cpu->regs[6] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14ddd4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x14dde0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14dbdc;
L_14dde4:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_14ded4;
    cpu->regs[7] = 18446744073709551611ULL;
    cpu->regs[5] = cpu->regs[24];
    cpu->regs[6] = cpu->regs[24] + (cpu->regs[23] << 1);
    cpu->regs[12] = 0ULL;
    cpu->regs[11] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = 127ULL;
    cpu->regs[7] = (cpu->regs[7] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14de40;
L_14de10:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(10ULL)));
    if (FLAG_HI) goto L_14de80;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(8ULL)));
    if (FLAG_HI) goto L_14de88;
    cpu->regs[2] = cpu->regs[7];
    cpu->regs[0] = 4ULL;
L_14de28:
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_GT) goto L_14da60;
    cpu->regs[5] = cpu->regs[5] + 2ULL;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_EQ) goto L_14d94c;
L_14de40:
    PB_LDRH(cpu->regs[4], (cpu->regs[5] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_14e064;
    if (FLAG_LS) goto L_14de10;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(39ULL)));
    if (FLAG_EQ) goto L_14e084;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_14de88;
L_14de60:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(127ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], 31ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_14e074;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_14dea8;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[0] = 1ULL;
    goto L_14de28;
L_14de80:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(13ULL)));
    if (FLAG_NE) goto L_14de60;
L_14de88:
    cpu->regs[2] = 18446744073709551613ULL;
    cpu->regs[0] = 2ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14de28;
L_14de98:
    cpu->regs[19] = cpu->regs[19] + cpu->regs[11];
    cpu->regs[22] = 0ULL;
    cpu->regs[21] = 39ULL;
    goto L_14dcec;
L_14dea8:
    cpu->regs[0] = cpu->regs[4];
    PB_STRW((SP + 108), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14deb4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x10a1d0ULL);
    PB_LDRW(cpu->regs[1], (SP + 108));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14e010;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_14e074;
    cpu->regs[2] = 18446744073709551609ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14de28;
L_14ded4:
    cpu->regs[6] = 18446744073709551611ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[12] = 0ULL;
    cpu->regs[11] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = 127ULL;
    cpu->regs[6] = (cpu->regs[6] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14df24;
L_14def4:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(10ULL)));
    if (FLAG_HI) goto L_14df64;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(8ULL)));
    if (FLAG_HI) goto L_14df6c;
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[0] = 4ULL;
L_14df0c:
    FLAG_CMP(cpu->regs[2], cpu->regs[19]);
    if (FLAG_LT) goto L_14da60;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
    FLAG_CMP(cpu->regs[5], cpu->regs[23]);
    if (FLAG_EQ) goto L_14d94c;
L_14df24:
    PB_LDRW(cpu->regs[4], (cpu->regs[24] + (cpu->regs[5] << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_14e094;
    if (FLAG_LS) goto L_14def4;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(39ULL)));
    if (FLAG_EQ) goto L_14e0ec;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_14df6c;
L_14df44:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(127ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], 31ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_14e0dc;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_14e0a4;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[0] = 1ULL;
    goto L_14df0c;
L_14df64:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(13ULL)));
    if (FLAG_NE) goto L_14df44;
L_14df6c:
    cpu->regs[2] = 18446744073709551613ULL;
    cpu->regs[0] = 2ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14df0c;
L_14df7c:
    cpu->regs[11] = 1ULL;
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[3] = cpu->regs[11];
    if (!((cpu->regs[10] >> 63) & 1)) goto L_14daf4;
    goto L_14da60;
L_14df90:
    cpu->regs[10] = cpu->regs[9] + 2ULL;
    cpu->regs[3] = 2ULL;
    if (!((cpu->regs[10] >> 63) & 1)) goto L_14daf4;
    goto L_14da60;
L_14dfa0:
    cpu->regs[11] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[11], (cpu->regs[11] + 2576));
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x14dfbcULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[3] = 120ULL;
    cpu->regs[30] = PB_BASE + 0x14dfc8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[3] = ((cpu->regs[4] >> 4) & 0xfULL);
    PB_LDR(cpu->regs[13], (cpu->regs[11] + 0));
    cpu->regs[2] = cpu->regs[6] + 2ULL;
    cpu->regs[4] = cpu->regs[4] & 15ULL;
    cpu->regs[8] = cpu->regs[6] + 3ULL;
    cpu->regs[6] = cpu->regs[6] + 4ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[13] + cpu->regs[3]));
    cpu->regs[30] = PB_BASE + 0x14dfe8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[8];
    PB_LDR(cpu->regs[3], (cpu->regs[11] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[4]));
    cpu->regs[30] = PB_BASE + 0x14dff8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14dbdc;
L_14dffc:
    cpu->regs[12] = 1ULL;
    cpu->regs[10] = 9223372036854775806ULL;
    cpu->regs[3] = cpu->regs[12];
    if (!((cpu->regs[10] >> 63) & 1)) goto L_14daf4;
    goto L_14da60;
L_14e010:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[4])));
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : cpu->regs[4];
    cpu->regs[0] = 1ULL;
    goto L_14de28;
L_14e024:
    PB_STRW((cpu->regs[7] + 0), cpu->regs[21]);
    PB_STRW((cpu->regs[7] + (cpu->regs[19] << 2)), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_14d99c;
    goto L_14db6c;
L_14e034:
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[6] = cpu->regs[6] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14e04cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[8];
    cpu->regs[3] = 114ULL;
    cpu->regs[30] = PB_BASE + 0x14e058ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14dbdc;
L_14e05c:
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 56));
    goto L_14dccc;
L_14e064:
    cpu->regs[12] = cpu->regs[12] + 1ULL;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[0] = 1ULL;
    goto L_14de28;
L_14e074:
    cpu->regs[2] = 18446744073709551611ULL;
    cpu->regs[0] = 4ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14de28;
L_14e084:
    cpu->regs[11] = cpu->regs[11] + 1ULL;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[0] = 1ULL;
    goto L_14de28;
L_14e094:
    cpu->regs[12] = cpu->regs[12] + 1ULL;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[0] = 1ULL;
    goto L_14df0c;
L_14e0a4:
    cpu->regs[0] = cpu->regs[4];
    PB_STRW((SP + 108), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x14e0b0ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x10a1d0ULL);
    PB_LDRW(cpu->regs[1], (SP + 108));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14e10c;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_14e0dc;
    cpu->regs[0] = 65535ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_14e0fc;
    cpu->regs[2] = 18446744073709551609ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14df0c;
L_14e0dc:
    cpu->regs[2] = 18446744073709551611ULL;
    cpu->regs[0] = 4ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14df0c;
L_14e0ec:
    cpu->regs[11] = cpu->regs[11] + 1ULL;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[0] = 1ULL;
    goto L_14df0c;
L_14e0fc:
    cpu->regs[2] = 18446744073709551605ULL;
    cpu->regs[0] = 10ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_14df0c;
L_14e10c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[4])));
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : cpu->regs[4];
    cpu->regs[0] = 1ULL;
    goto L_14df0c;
L_14e120:
    cpu->regs[12] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[12], (cpu->regs[12] + 2576));
    cpu->regs[8] = 0ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[22] = 65535ULL;
    PB_STR((SP + 80), cpu->regs[27]);
L_14e138:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_14e468;
    PB_LDRH(cpu->regs[4], (cpu->regs[24] + (cpu->regs[8] << 1)));
L_14e144:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(92ULL)));
    cpu->regs[6] = cpu->regs[5] + 1ULL;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_14e440;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_14e418;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_14e3f0;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_14e3c8;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(127ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], 31ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_14e260;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(126ULL)));
    if (FLAG_HI) goto L_14e1b4;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_14e1a4;
    PB_STRB((cpu->regs[7] + cpu->regs[5]), cpu->regs[4]);
L_14e18c:
    cpu->regs[5] = cpu->regs[6];
L_14e190:
    cpu->regs[8] = cpu->regs[8] + 1ULL;
    FLAG_CMP(cpu->regs[23], cpu->regs[8]);
    if (FLAG_NE) goto L_14e138;
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_14d9b8;
L_14e1a4:
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_14e2bc;
    PB_STRH((cpu->regs[7] + (cpu->regs[5] << 1)), cpu->regs[4]);
    goto L_14e18c;
L_14e1b4:
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x14e1bcULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x10a1d0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14e3b0;
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[3] = 92ULL;
    cpu->regs[30] = PB_BASE + 0x14e1d4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[10] = ((uint32_t)(cpu->regs[4] >> 4));
    cpu->regs[14] = cpu->regs[4] & 15ULL;
    cpu->regs[18] = cpu->regs[5] + 2ULL;
    cpu->regs[15] = cpu->regs[5] + 3ULL;
    cpu->regs[13] = cpu->regs[5] + 4ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(255ULL)));
    if (FLAG_LS) goto L_14e374;
    cpu->regs[10] = cpu->regs[10] & 15ULL;
    cpu->regs[11] = ((uint32_t)(cpu->regs[4] >> 12));
    cpu->regs[27] = ((cpu->regs[4] >> 8) & 0xfULL);
    cpu->regs[26] = cpu->regs[5] + 5ULL;
    cpu->regs[19] = cpu->regs[5] + 6ULL;
    cpu->regs[2] = cpu->regs[6];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_HI) goto L_14e2c4;
    cpu->regs[3] = 117ULL;
    cpu->regs[30] = PB_BASE + 0x14e218ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x11ce20ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[12] + 0));
    cpu->regs[2] = cpu->regs[18];
    cpu->regs[5] = cpu->regs[19];
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[11]));
    cpu->regs[30] = PB_BASE + 0x14e22cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[15];
    PB_LDR(cpu->regs[3], (cpu->regs[12] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[27]));
    cpu->regs[30] = PB_BASE + 0x14e23cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[13];
    PB_LDR(cpu->regs[3], (cpu->regs[12] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[10]));
    cpu->regs[30] = PB_BASE + 0x14e24cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[26];
    PB_LDR(cpu->regs[3], (cpu->regs[12] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[14]));
    cpu->regs[30] = PB_BASE + 0x14e25cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e190;
L_14e260:
    cpu->regs[10] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[10], (cpu->regs[10] + 2576));
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x14e27cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 120ULL;
    cpu->regs[30] = PB_BASE + 0x14e288ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] >> 4));
    PB_LDR(cpu->regs[11], (cpu->regs[10] + 0));
    cpu->regs[2] = cpu->regs[5] + 2ULL;
    cpu->regs[4] = cpu->regs[4] & 15ULL;
    cpu->regs[6] = cpu->regs[5] + 3ULL;
    cpu->regs[5] = cpu->regs[5] + 4ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[11] + cpu->regs[3]));
    cpu->regs[30] = PB_BASE + 0x14e2a8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[6];
    PB_LDR(cpu->regs[3], (cpu->regs[10] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[4]));
    cpu->regs[30] = PB_BASE + 0x14e2b8ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e190;
L_14e2bc:
    PB_STRW((cpu->regs[7] + (cpu->regs[5] << 2)), cpu->regs[4]);
    goto L_14e18c;
L_14e2c4:
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2576));
    cpu->regs[3] = 85ULL;
    cpu->regs[30] = PB_BASE + 0x14e2d4ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] >> 28));
    cpu->regs[2] = cpu->regs[18];
    cpu->regs[11] = cpu->regs[11] & 15ULL;
    PB_LDR(cpu->regs[16], (cpu->regs[6] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[16] + cpu->regs[3]));
    cpu->regs[30] = PB_BASE + 0x14e2ecULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[3] = ((cpu->regs[4] >> 24) & 0xfULL);
    PB_LDR(cpu->regs[16], (cpu->regs[6] + 0));
    cpu->regs[2] = cpu->regs[15];
    PB_LDRB(cpu->regs[3], (cpu->regs[16] + cpu->regs[3]));
    cpu->regs[30] = PB_BASE + 0x14e300ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[3] = ((cpu->regs[4] >> 20) & 0xfULL);
    PB_LDR(cpu->regs[15], (cpu->regs[6] + 0));
    cpu->regs[2] = cpu->regs[13];
    cpu->regs[4] = ((cpu->regs[4] >> 16) & 0xfULL);
    PB_LDRB(cpu->regs[3], (cpu->regs[15] + cpu->regs[3]));
    cpu->regs[30] = PB_BASE + 0x14e318ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[26];
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[4]));
    cpu->regs[4] = cpu->regs[5] + 9ULL;
    cpu->regs[30] = PB_BASE + 0x14e32cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[11]));
    cpu->regs[30] = PB_BASE + 0x14e33cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[5] + 7ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[27]));
    cpu->regs[30] = PB_BASE + 0x14e34cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[5] + 8ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 0));
    cpu->regs[5] = cpu->regs[5] + 10ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[10]));
    cpu->regs[30] = PB_BASE + 0x14e360ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[4];
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[14]));
    cpu->regs[30] = PB_BASE + 0x14e370ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e190;
L_14e374:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2576));
    cpu->regs[3] = 120ULL;
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x14e388ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[18];
    cpu->regs[5] = cpu->regs[13];
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[10]));
    cpu->regs[30] = PB_BASE + 0x14e39cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[15];
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 0));
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + cpu->regs[14]));
    cpu->regs[30] = PB_BASE + 0x14e3acULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e190;
L_14e3b0:
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x14e3c4ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e18c;
L_14e3c8:
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[5] = cpu->regs[5] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14e3e0ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 114ULL;
    cpu->regs[30] = PB_BASE + 0x14e3ecULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e190;
L_14e3f0:
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[5] = cpu->regs[5] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14e408ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 110ULL;
    cpu->regs[30] = PB_BASE + 0x14e414ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e190;
L_14e418:
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[5] = cpu->regs[5] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14e430ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[3] = 116ULL;
    cpu->regs[30] = PB_BASE + 0x14e43cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e190;
L_14e440:
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[3] = 92ULL;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[5] = cpu->regs[5] + 2ULL;
    cpu->regs[30] = PB_BASE + 0x14e458ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x14e464ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_14e190;
L_14e468:
    PB_LDRW(cpu->regs[4], (cpu->regs[24] + (cpu->regs[8] << 2)));
    goto L_14e144;
L_14e470:
    PB_LDR(cpu->regs[7], (cpu->regs[25] + 56));
    goto L_14db48;
    /* nop */
    /* nop */
}
