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

void ft_PyCodec_RegisterError(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1c7984ULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1248));
    if ((cpu->regs[0])==0) goto L_1c79c4;
L_1c799c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c79a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11d7acULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c79d0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 1264));
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x18eaf0ULL); return; };
L_1c79c4:
    cpu->regs[30] = PB_BASE + 0x1c79c8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1c7680ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c799c;
    goto L_1c79e8;
L_1c79d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 352ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c79e8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1c79e8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    SP = SP - 80ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[20]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1c7aec;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[5] = 57792ULL;
    cpu->regs[0] = cpu->regs[23] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1c7a5cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c7cb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c7b70;
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_EQ) goto L_1c7c18;
L_1c7a6c:
    cpu->regs[4] = 44424ULL;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[23] + cpu->regs[4];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[24] = SP;
    PB_STR((SP + 0), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1c7a8cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c7bc0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_1c7ba0;
    cpu->regs[30] = PB_BASE + 0x1c7aa4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x129680ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[2] = 2147483646ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_HI) goto L_1c7ba4;
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1c7be4;
L_1c7abc:
    cpu->regs[0] = 44840ULL;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1c7ad8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1c7b94;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1c7c3c;
L_1c7ae4:
    PB_STR((cpu->regs[22] + 0), cpu->regs[19]);
    goto L_1c7b14;
L_1c7aec:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_1c7b78;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c7b00ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c7b50;
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c7b58;
    PB_STR((cpu->regs[22] + 0), 0ULL);
L_1c7b14:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1c7b4c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_1c7b4c:
    cpu->regs[30] = PB_BASE + 0x1c7b50ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c7b50:
    cpu->regs[30] = PB_BASE + 0x1c7b54ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1c7b70;
L_1c7b58:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 408ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c7b70ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1c7b70:
    cpu->regs[20] = 4294967295ULL;
    goto L_1c7b14;
L_1c7b78:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1c7a6c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1c7a6c;
L_1c7b94:
    cpu->regs[30] = PB_BASE + 0x1c7b98ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_STR((cpu->regs[22] + 0), cpu->regs[19]);
    goto L_1c7b14;
L_1c7ba0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
L_1c7ba4:
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1c7c04;
L_1c7ba8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 448ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c7bc0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1c7bc0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c7b70;
L_1c7bc8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c7b70;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1c7be0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c7b14;
L_1c7be4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1c7abc;
L_1c7bf0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c7bf8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1c7abc;
    goto L_1c7ba8;
L_1c7c04:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1c7ba8;
    cpu->regs[20] = 4294967295ULL;
    goto L_1c7bf0;
L_1c7c18:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 384ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c7c30ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1c7bc8;
    goto L_1c7b70;
L_1c7c3c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1c7ae4;
    cpu->regs[30] = PB_BASE + 0x1c7c4cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_STR((cpu->regs[22] + 0), cpu->regs[19]);
    goto L_1c7b14;
    /* nop */
    /* nop */
    /* nop */
}
