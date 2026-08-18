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

void ft_PyObject_ASCII(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x25bca0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x14d650ULL);
    if ((cpu->regs[0])==0) goto L_25bd34;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[19] = cpu->regs[0];
    if (!((cpu->regs[1] >> 6) & 1)) goto L_25bcc0;
L_25bcb0:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_25bcc0:
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 3016ULL;
    cpu->regs[30] = PB_BASE + 0x25bcccULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x14d360ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_25bcf4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_25bcf4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x25bcf4ULL; PB_CALL(3, cpu, tlb, cpu->regs[1]);
L_25bcf4:
    if ((cpu->regs[20])==0) goto L_25bd34;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[20] + 32ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x25bd08ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1c3ac0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_25bcb0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_25bcb0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x25bd30ULL; PB_CALL(5, cpu, tlb, cpu->regs[1]);
    goto L_25bcb0;
L_25bd34:
    cpu->regs[19] = 0ULL;
    goto L_25bcb0;
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[3] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[4], (cpu->regs[5] + 96));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_25bef4;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x25bda0ULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[6], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_NE) goto L_25be3c;
L_25bdb4:
    if ((cpu->regs[4])==0) goto L_25bf18;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 40));
    cpu->regs[0] = PB_BASE + 0x25b000ULL;
    cpu->regs[0] = cpu->regs[0] + 3392ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_25bf18;
L_25bdcc:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
L_25bde0:
    cpu->regs[22] = 0ULL;
L_25bde4:
    cpu->regs[6] = 31560ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[6];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x25bdf8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_25be9c;
L_25be04:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
L_25be0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_25bee8;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 112ULL;
    return;
L_25be3c:
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 96));
    if ((cpu->regs[0])==0) goto L_25bdb4;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 40));
    cpu->regs[0] = PB_BASE + 0x25b000ULL;
    cpu->regs[0] = cpu->regs[0] + 3392ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[4])==0) goto L_25beb4;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 40));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_25beb4;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_25bdcc;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[30] = PB_BASE + 0x25be84ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_25bf2c;
L_25be88:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[22] = 1ULL;
    goto L_25bde4;
L_25be9c:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_25bf18;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_25bfd0;
L_25beb4:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_25bf18;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[5] = 32560ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[5];
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x25bed8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x161820ULL);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    goto L_25be0c;
L_25bee8:
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x25bef4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c170ULL);
L_25bef4:
    if ((cpu->regs[4])==0) goto L_25bf0c;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 40));
    cpu->regs[0] = PB_BASE + 0x25b000ULL;
    cpu->regs[0] = cpu->regs[0] + 3392ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_25bfa4;
L_25bf0c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    goto L_25be0c;
L_25bf18:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    goto L_25be0c;
L_25bf2c:
    cpu->regs[8] = 32560ULL;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[24] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x25bf40ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x250360ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_25bfe4;
    if (FLAG_EQ) goto L_25be88;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[7] = 32560ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[7];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x25bf70ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_25be04;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[2], (SP + 8));
    if (((cpu->regs[0] >> 31) & 1)) goto L_25bde0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_25bde0;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x25bf9cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    goto L_25bde0;
L_25bfa4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 31560ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x25bfc8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = cpu->regs[0];
    goto L_25be0c;
L_25bfd0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_25beb4;
    cpu->regs[30] = PB_BASE + 0x25bfe0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_25beb4;
L_25bfe4:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    goto L_25be0c;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x25c010ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[1])!=0) goto L_25c074;
L_25c01c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x25c024ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x25c0a0ULL);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x25c038ULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[0] + (66ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 3072ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + -16));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(254ULL)));
    if (FLAG_GT) goto L_25c07c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + -24));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + -16), cpu->regs[1]);
    PB_STR((cpu->regs[19] + 32), cpu->regs[2]);
    PB_STR((cpu->regs[0] + -24), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_25c074:
    cpu->regs[30] = PB_BASE + 0x25c078ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_25c01c;
L_25c07c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
    /* nop */
L_25c0a0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])!=0) goto L_25c0ec;
L_25c0b8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_25c0dc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_25c0dc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_25c0dc;
    cpu->regs[30] = PB_BASE + 0x25c0dcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_25c0dc:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_25c0ec:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_25c0b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_25c0b8;
    cpu->regs[30] = PB_BASE + 0x25c108ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_25c0b8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 3240ULL;
    return;
    /* nop */
    { PB_CALL(22, cpu, tlb, PB_BASE + 0x16de80ULL); return; };
    cpu->regs[1] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x25c140ULL; PB_CALL(23, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[0] + (64ULL << 12);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 5280),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    { PB_CALL(24, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
    /* nop */
    /* nop */
    SP = SP - 48ULL;
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[2], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[1];
    if (FLAG_LE) goto L_25c240;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_25c240;
L_25c19c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x25c1a4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_25c214;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x25c1c4ULL; PB_CALL(26, cpu, tlb, cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(639ULL)));
    if (FLAG_LE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    if (FLAG_NE) goto L_25c21c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[2] = cpu->regs[2] + (64ULL << 12);
    PB_STRW((cpu->regs[2] + 5280), cpu->regs[1]);
L_25c1e8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_25c210;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_25c210:
    cpu->regs[30] = PB_BASE + 0x25c214ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7c170ULL);
L_25c214:
    cpu->regs[30] = PB_BASE + 0x25c218ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_25c238;
L_25c21c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29b000ULL;
    cpu->regs[2] = 640ULL;
    cpu->regs[1] = cpu->regs[1] + 3432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x25c238ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11f220ULL);
L_25c238:
    cpu->regs[0] = 0ULL;
    goto L_25c1e8;
L_25c240:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[6] = 1ULL;
    cpu->regs[4] = cpu->regs[4] + 680ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[7] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x25c26cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_25c19c;
    cpu->regs[0] = 0ULL;
    goto L_25c1e8;
    /* nop */
    /* nop */
}
