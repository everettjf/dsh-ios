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

void ft_PyPickleBuffer_Release(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2776));
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_97904;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1528ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x978fcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_97910;
L_97904:
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x9790cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = 0ULL;
L_97910:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_97918:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 2872));
    PB_STRW((cpu->regs[19] + 8), 0ULL);
    cpu->regs[30] = PB_BASE + 0x97944ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x90a78ULL);
    if ((cpu->regs[0])!=0) goto L_97954;
L_97948:
    PB_LDRH(cpu->regs[0], (cpu->regs[19] + 8));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_97b10;
    goto L_97a50;
L_97954:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    cpu->regs[1] = 24152ULL;
    cpu->regs[26] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[25] = 12ULL;
    cpu->regs[24] = 65535ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x97970ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x280648ULL);
    cpu->regs[22] = cpu->regs[0];
L_97974:
    PB_LDRH(cpu->regs[23], (cpu->regs[19] + 8));
    if ((cpu->regs[22])==0) goto L_97948;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 2712));
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_GE) goto L_97a2c;
    cpu->regs[23] = cpu->regs[19] + (uint64_t)(uint32_t)cpu->regs[23] * (uint64_t)(uint32_t)cpu->regs[25];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((cpu->regs[23] + 12), cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x97998ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x2273c0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & ~(((uint64_t)((int64_t)cpu->regs[0] >> 31)))));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 112));
    PB_STRW((cpu->regs[23] + 20), cpu->regs[0]);
    if ((cpu->regs[20])==0) goto L_97a20;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_97a20;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2864));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x979c8ULL; PB_CALL(6, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_979d4;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    goto L_97a1c;
L_979d4:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2864));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_979e8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_979e8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x979f4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xd8a64ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_97a1c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_97a20;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_97a20;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x97a18ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_97a20;
L_97a1c:
    PB_STR((cpu->regs[23] + 12), cpu->regs[20]);
L_97a20:
    PB_LDRH(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRH((cpu->regs[19] + 8), cpu->regs[0]);
L_97a2c:
    PB_LDRH(cpu->regs[0], (cpu->regs[19] + 10));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[24])));
    if (FLAG_EQ) goto L_97a40;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRH((cpu->regs[19] + 10), cpu->regs[0]);
L_97a40:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[30] = PB_BASE + 0x97a48ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x280648ULL);
    cpu->regs[22] = cpu->regs[0];
    goto L_97974;
L_97a50:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x97a58ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1827a0ULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2880));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x97a6cULL; PB_CALL(11, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_97a78;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    goto L_97b14;
L_97a78:
    PB_LDRH(cpu->regs[22], (cpu->regs[19] + 8));
    cpu->regs[3] = 12ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2760));
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] - 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 2768));
    cpu->regs[1] = 24ULL;
    cpu->regs[22] = cpu->regs[1] + (uint64_t)((int64_t)(int32_t)cpu->regs[22] * (int64_t)(int32_t)cpu->regs[3]);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x97a9cULL; PB_CALL(12, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_97b08;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_LS) goto L_97abc;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[22];
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_HS) goto L_97ad0;
    goto L_97acc;
L_97abc:
    if (FLAG_HS) goto L_97ad0;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[22];
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HS) goto L_97ad0;
L_97acc:
    __builtin_trap();
L_97ad0:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x97ae0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2880));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97af0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xd8a64ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_97b14;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2760));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 2792));
    cpu->regs[30] = PB_BASE + 0x97b08ULL; PB_CALL(15, cpu, tlb, cpu->regs[2]);
L_97b08:
    cpu->regs[20] = 0ULL;
    goto L_97b14;
L_97b10:
    cpu->regs[20] = cpu->regs[21] + 2904ULL;
L_97b14:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_97b30:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x97b54ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x97918ULL);
    if ((cpu->regs[0])==0) goto L_97ba0;
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x97b64ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x8f5acULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_97ba8;
    cpu->regs[30] = PB_BASE + 0x97b70ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18268cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_97ba0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2896));
    cpu->regs[30] = PB_BASE + 0x97b90ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xd8a64ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_97ba8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x97ba0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x144810ULL);
L_97ba0:
    cpu->regs[0] = 4294967295ULL;
    goto L_97c3c;
L_97ba8:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[30] = PB_BASE + 0x97bbcULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xd88a4ULL);
    if ((cpu->regs[0])==0) goto L_97bd8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 2848));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2];
    PB_STR((cpu->regs[20] + 2848), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 0), cpu->regs[21]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[23]);
    goto L_97c1c;
L_97bd8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2760));
    cpu->regs[1] = 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 2768));
    cpu->regs[30] = PB_BASE + 0x97be8ULL; PB_CALL(22, cpu, tlb, cpu->regs[2]);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_97ba0;
    PB_STR((cpu->regs[0] + 0), cpu->regs[21]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[23]);
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x97c04ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xd8a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_97c1c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2760));
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 2792));
    cpu->regs[30] = PB_BASE + 0x97c18ULL; PB_CALL(24, cpu, tlb, cpu->regs[2]);
    goto L_97ba0;
L_97c1c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 2848));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2856));
    cpu->regs[21] = cpu->regs[21] + cpu->regs[1];
    PB_STR((cpu->regs[20] + 2848), cpu->regs[21]);
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LS) goto L_97c38;
    PB_STR((cpu->regs[20] + 2856), cpu->regs[21]);
L_97c38:
    cpu->regs[0] = 0ULL;
L_97c3c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_97c50:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 24));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x97c7cULL; PB_CALL(25, cpu, tlb, cpu->regs[3]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_97d1c;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 2840));
    cpu->regs[30] = PB_BASE + 0x97c98ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 2708));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_97d14;
    if ((cpu->regs[21])==0) goto L_97ce8;
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    if (FLAG_EQ) goto L_97cb8;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97cb8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x8f5ccULL);
L_97cb8:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97cc8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x97b30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_97d14;
    cpu->regs[0] = PB_BASE + 0x2b9000ULL;
    cpu->regs[0] = cpu->regs[0] + 2352ULL;
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1344ULL;
    cpu->regs[1] = cpu->regs[1] + 2544ULL;
    cpu->regs[30] = PB_BASE + 0x97ce8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x91ebcULL);
L_97ce8:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97cf8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x97b30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_97d14;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97d14ULL; PB_CALL(31, cpu, tlb, cpu->regs[2]);
L_97d14:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 2840));
    cpu->regs[30] = PB_BASE + 0x97d1cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x17faa0ULL);
L_97d1c:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[20] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x97d60ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x182a60ULL);
    if ((cpu->regs[0])==0) goto L_97d8c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x97d78ULL; PB_CALL(34, cpu, tlb, cpu->regs[3]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[19] = cpu->regs[0];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_97de8;
    goto L_97dc0;
L_97d8c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = cpu->regs[20] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x97d9cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x182ae0ULL);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x97dacULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x97c50ULL);
    cpu->regs[1] = 0ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x97dbcULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x182ae0ULL);
    goto L_97de8;
L_97dc0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2840));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x97dccULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 2708));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_97de0;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97de0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x8f5ccULL);
L_97de0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2840));
    cpu->regs[30] = PB_BASE + 0x97de8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x17faa0ULL);
L_97de8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[20] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x97e28ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x182a60ULL);
    if ((cpu->regs[0])==0) goto L_97e54;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x97e40ULL; PB_CALL(42, cpu, tlb, cpu->regs[3]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[19] = cpu->regs[0];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_97ec0;
    goto L_97e98;
L_97e54:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = cpu->regs[20] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x97e64ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x182ae0ULL);
    cpu->regs[30] = PB_BASE + 0x97e68ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x208c80ULL);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x97e7cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x97c50ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x97e88ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x20b604ULL);
    cpu->regs[0] = cpu->regs[20] + 2928ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97e94ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x182ae0ULL);
    goto L_97ec0;
L_97e98:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2840));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x97ea4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 2708));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_97eb8;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97eb8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x8f5ccULL);
L_97eb8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 2840));
    cpu->regs[30] = PB_BASE + 0x97ec0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x17faa0ULL);
L_97ec0:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_97ed4:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[3];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((SP + 48), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_97f18;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0x97f10ULL; PB_CALL(51, cpu, tlb, cpu->regs[3]);
    cpu->regs[19] = cpu->regs[0];
    goto L_97f28;
L_97f18:
    cpu->regs[1] = cpu->regs[2] * cpu->regs[3];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x97f24ULL; PB_CALL(52, cpu, tlb, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
L_97f28:
    if ((cpu->regs[19])==0) goto L_97f7c;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 2840));
    cpu->regs[30] = PB_BASE + 0x97f40ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 2708));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_97f74;
    cpu->regs[2] = cpu->regs[22] * cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97f58ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x97b30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_97f74;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x97f74ULL; PB_CALL(55, cpu, tlb, cpu->regs[2]);
L_97f74:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 2840));
    cpu->regs[30] = PB_BASE + 0x97f7cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x17faa0ULL);
L_97f7c:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[22] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x97fc0ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x182a60ULL);
    if ((cpu->regs[0])==0) goto L_97fe8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[21];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_97fe8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = cpu->regs[22] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x97ff8ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x182ae0ULL);
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x9800cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x97ed4ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[22] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x9801cULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x182ae0ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_98030:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[23] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x98064ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x182a60ULL);
    if ((cpu->regs[0])==0) goto L_980b4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_98094;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_98094:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[21] * cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[16] = cpu->regs[2];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_980b4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = cpu->regs[23] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x980c4ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x182ae0ULL);
    cpu->regs[30] = PB_BASE + 0x980c8ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x208c80ULL);
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x980e0ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x97ed4ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x980ecULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x20b604ULL);
    cpu->regs[0] = cpu->regs[23] + 2928ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x980f8ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x182ae0ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[0] = 1ULL;
    goto L_98030;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    goto L_98030;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[21] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x98164ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x182a60ULL);
    if ((cpu->regs[0])==0) goto L_98184;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_98184:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = cpu->regs[21] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x98194ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x182ae0ULL);
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x981a8ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x97ed4ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[21] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x981b8ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x182ae0ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
