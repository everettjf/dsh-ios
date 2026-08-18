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

void ft__PyCodec_LookupTextEncoding(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d6a78ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1c7344ULL);
    if ((cpu->regs[0])==0) goto L_1d6b4c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2640));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_1d6ad8;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    cpu->regs[1] = 35544ULL;
    cpu->regs[2] = SP;
    cpu->regs[1] = cpu->regs[3] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d6aacULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d6b78;
    PB_LDR(cpu->regs[20], (SP + 0));
    if ((cpu->regs[20])==0) goto L_1d6ad8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d6ac4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1d6b60;
L_1d6ad0:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1d6b14;
L_1d6ad8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1d6b10;
    PB_LDR(cpu->regs[23], (SP + 64));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_1d6b10:
    cpu->regs[30] = PB_BASE + 0x1d6b14ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d6b14:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d6b28;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d6b54;
L_1d6b28:
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1d6b4c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2784));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[1] + 904ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d6b4cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1d6b4c:
    cpu->regs[19] = 0ULL;
    goto L_1d6ad8;
L_1d6b54:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d6b5cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d6b28;
L_1d6b60:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d6ad0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d6b74ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d6ad0;
L_1d6b78:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d6b4c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d6b4c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d6b98ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d6ad8;
    /* nop */
    cpu->regs[2] = cpu->regs[0];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d6c14;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_1d6bc0;
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 1));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d6be8;
    return;
L_1d6bc0:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(13ULL)));
    if (FLAG_NE) goto L_1d6be8;
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + 1));
    cpu->regs[0] = 0ULL;
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1d6bd8;
L_1d6bd4:
    return;
L_1d6bd8:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_1d6be8;
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + 2));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1d6bd4;
L_1d6be8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d6c08ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1d6c14:
    cpu->regs[0] = 0ULL;
    return;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 64));
    if ((cpu->regs[1])!=0) goto L_1d6c70;
    cpu->regs[1] = 257ULL;
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 64), 0ULL);
    PB_STRH((cpu->regs[19] + 90), cpu->regs[1]);
    PB_STRB((cpu->regs[19] + 92), cpu->regs[0]);
L_1d6c50:
    PB_STR((cpu->regs[19] + 80), 0ULL);
L_1d6c54:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d6c5cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
L_1d6c60:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1d6c70:
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d6c7cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdea4cULL);
    PB_STR((cpu->regs[19] + 64), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d6cdc;
    PB_LDRB(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STRB((cpu->regs[19] + 91), 0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    PB_STRB((cpu->regs[19] + 90), cpu->regs[2]);
    PB_LDRB(cpu->regs[2], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    cpu->regs[2] = (FLAG_NE) ? 1 : 0;
    PB_STRB((cpu->regs[19] + 92), cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1d6c50;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_1d6ce8;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_1d6cc4:
    PB_STR((cpu->regs[19] + 80), cpu->regs[0]);
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x1d6cd4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d6c50;
    goto L_1d6c54;
L_1d6cdc:
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[19] + 64), cpu->regs[21]);
    goto L_1d6c60;
L_1d6ce8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    goto L_1d6cc4;
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[1] = 54760ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    PB_STR((SP + 64), cpu->regs[23]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = SP;
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1d6d50ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1d6e54;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1d6d5cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1d6e3c;
L_1d6d68:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d6e54;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1d6de0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])!=0) goto L_1d6e1c;
L_1d6d80:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d6d8cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d6f20ULL);
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d6e54;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 90));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d6de0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 192));
    cpu->regs[3] = 0ULL;
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + 91));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3664));
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1d6dccULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1987c8ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d6e54;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_STR((cpu->regs[19] + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1d6de0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18d760ULL);
L_1d6de0:
    cpu->regs[0] = 0ULL;
L_1d6de4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d6e18;
    PB_LDR(cpu->regs[23], (SP + 64));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_1d6e18:
    cpu->regs[30] = PB_BASE + 0x1d6e1cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d6e1c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 56), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d6d80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d6d80;
    cpu->regs[30] = PB_BASE + 0x1d6e38ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d6d80;
L_1d6e3c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d6d68;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d6e50ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d6d68;
L_1d6e54:
    cpu->regs[0] = 4294967295ULL;
    goto L_1d6de4;
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
    if (FLAG_LE) goto L_1d6ee0;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = 54760ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x1d6eb4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x147564ULL);
L_1d6eb4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1d6edc;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_1d6edc:
    cpu->regs[30] = PB_BASE + 0x1d6ee0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d6ee0:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 28));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1d6f08;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x1d6f00ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d6eb4;
L_1d6f08:
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0x1d6f14ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d6eb4;
    /* nop */
}
