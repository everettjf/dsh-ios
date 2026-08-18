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

void ft__PyErr_DisplayException(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x7cf74ULL); return; };
    SP = SP - 112ULL;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32));
    PB_STR((SP + 96), cpu->regs[25]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_d72ec;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 4088ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd72e8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_d732c;
L_d72ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3448));
    PB_LDR(cpu->regs[22], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_d7398;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[3] = 57792ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[2] + 48));
    cpu->regs[1] = SP;
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 32)); PB_LDR(cpu->regs[24], (cpu->regs[2] + 32) + 8);
    cpu->regs[0] = cpu->regs[21] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xd7324ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_d7334;
L_d732c:
    cpu->regs[0] = 0ULL;
    goto L_d7534;
L_d7334:
    PB_LDR(cpu->regs[19], (SP + 0));
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    if ((cpu->regs[19])==0) goto L_d734c;
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_NE) goto L_d73a4;
L_d734c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd7354ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18d760ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[25]);
    if (FLAG_EQ) goto L_d7398;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x2a9000ULL;
    cpu->regs[1] = cpu->regs[1] + 48ULL;
    cpu->regs[30] = PB_BASE + 0xd736cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11d200ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d732c;
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_NE) goto L_d73a4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_d7398;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d7398;
    cpu->regs[30] = PB_BASE + 0xd7398ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d7398:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_d7534;
L_d73a4:
    cpu->regs[0] = PB_BASE + 0x2a9000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[30] = PB_BASE + 0xd73b4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d750c;
    PB_STR((SP + 8), 0ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[25]);
    if (FLAG_NE) goto L_d73d4;
L_d73c8:
    PB_LDR(cpu->regs[20], (SP + 8));
    if ((cpu->regs[20])!=0) goto L_d73f4;
    goto L_d7414;
L_d73d4:
    cpu->regs[1] = 51144ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xd73e8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_d73c8;
    goto L_d750c;
L_d73f4:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xd7404ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_d7464;
    goto L_d7448;
L_d7414:
    cpu->regs[30] = PB_BASE + 0xd7418ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd7750ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 928ULL;
    cpu->regs[30] = PB_BASE + 0xd7428ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d7480;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xd743cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_d7464;
L_d7448:
    if (((cpu->regs[1] >> 31) & 1)) goto L_d750c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d750c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd7460ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d750c;
L_d7464:
    if (((cpu->regs[1] >> 31) & 1)) goto L_d749c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d749c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd747cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d749c;
L_d7480:
    cpu->regs[30] = PB_BASE + 0xd7484ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = PB_BASE + 0x2a9000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 80ULL;
    cpu->regs[30] = PB_BASE + 0xd7494ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d750c;
L_d749c:
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1328ULL;
    cpu->regs[30] = PB_BASE + 0xd74acULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d750c;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd74c8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7cf74ULL);
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[0] = 44840ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[30] = PB_BASE + 0xd74e4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_d750c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_d74f8;
L_d74f0:
    cpu->regs[20] = 0ULL;
    goto L_d7510;
L_d74f8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d74f0;
    cpu->regs[30] = PB_BASE + 0xd7508ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d74f0;
L_d750c:
    cpu->regs[20] = 4294967295ULL;
L_d7510:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d752c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d752c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd752cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d752c:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_d7398;
    goto L_d732c;
L_d7534:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_d7554;
    cpu->regs[30] = PB_BASE + 0xd7554ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_d7554:
    PB_LDR(cpu->regs[25], (SP + 96));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xd7594ULL; PB_CALL(23, cpu, tlb, cpu->regs[4]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a9000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] + 112ULL;
    cpu->regs[30] = PB_BASE + 0xd75bcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d75c8;
L_d75c0:
    cpu->regs[0] = 4294967295ULL;
    goto L_d7674;
L_d75c8:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    PB_LDRB(cpu->regs[21], (cpu->regs[19] + 20));
    cpu->regs[30] = PB_BASE + 0xd75d8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7d0e4ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 0));
    PB_STRB((cpu->regs[19] + 20), cpu->regs[21]);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[2] + 36), cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d75c0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd7600ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x7e788ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d75c0;
    cpu->regs[21] = PB_BASE + 0x2a2000ULL;
    cpu->regs[21] = cpu->regs[21] + 1024ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd761cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d75c0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd7630ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7e788ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d75c0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd7644ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d75c0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd7658ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7e788ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d75c0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd766cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1e3340ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 0xffffffffULL : 0;
L_d7674:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
}
