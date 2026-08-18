/*
 * neon_convert_test.c — guest-side check of the AArch64 instructions added to
 * the iSH-ARM64 emulator for libvips/sharp:
 *   FCVTL/FCVTL2, FCVTN/FCVTN2, FCVTXN/FCVTXN2, the vector fixed-point
 *   conversions SCVTF/UCVTF/FCVTZS/FCVTZU Vd, Vn, #fbits, and the FMOV
 *   (scalar, immediate) decoding fix (bit 6 of imm8 is stored inverted).
 *
 * Compiled with gcc inside the Alpine guest and executed under the emulator
 * (tests/emu-test.sh); every result is compared against plain C.
 * Prints "NEON CONVERT OK" and exits 0 on success.
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <arm_neon.h>

static int failures = 0;

#define CHECK(cond, ...) do { if (!(cond)) { failures++; printf("FAIL %s:%d: ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); } } while (0)

static int feq(float a, float b) { return (isnan(a) && isnan(b)) || a == b; }
static int deq(double a, double b) { return (isnan(a) && isnan(b)) || a == b; }

static void test_fcvtl(void) {
    float in[4] = { 1.5f, -2.25f, 3.0e10f, 0.1f };
    float32x4_t v = vld1q_f32(in);
    double out[2];
    float64x2_t d;
    /* FCVTL Vd.2D, Vn.2S */
    __asm__ volatile("fcvtl %0.2d, %1.2s" : "=w"(d) : "w"(v));
    vst1q_f64(out, d);
    CHECK(deq(out[0], (double) in[0]) && deq(out[1], (double) in[1]), "fcvtl 2s->2d got %g %g", out[0], out[1]);
    /* FCVTL2 Vd.2D, Vn.4S */
    __asm__ volatile("fcvtl2 %0.2d, %1.4s" : "=w"(d) : "w"(v));
    vst1q_f64(out, d);
    CHECK(deq(out[0], (double) in[2]) && deq(out[1], (double) in[3]), "fcvtl2 4s->2d got %g %g", out[0], out[1]);

    /* half -> single via FCVTL Vd.4S, Vn.4H */
    uint16_t h[8] = { 0x3c00 /*1.0*/, 0xc000 /*-2.0*/, 0x3555 /*~0.333*/, 0x7c00 /*inf*/,
                      0x0001 /*denorm*/, 0x4900 /*10.0*/, 0x8000 /*-0*/, 0x3e00 /*1.5*/ };
    float32x4_t f;
    uint16x8_t hv = vld1q_u16(h);
    __asm__ volatile("fcvtl %0.4s, %1.4h" : "=w"(f) : "w"(hv));
    float fo[4]; vst1q_f32(fo, f);
    CHECK(fo[0] == 1.0f && fo[1] == -2.0f && isinf(fo[3]), "fcvtl 4h->4s got %g %g %g %g", fo[0], fo[1], fo[2], fo[3]);
    __asm__ volatile("fcvtl2 %0.4s, %1.8h" : "=w"(f) : "w"(hv));
    vst1q_f32(fo, f);
    CHECK(fo[1] == 10.0f && fo[3] == 1.5f && signbit(fo[2]), "fcvtl2 8h->4s got %g %g %g %g", fo[0], fo[1], fo[2], fo[3]);
}

static void test_fcvtn(void) {
    double in[2] = { 1.5, -123456.75 };
    float64x2_t v = vld1q_f64(in);
    float lo[4] = { 9, 9, 9, 9 };
    float32x4_t r = vld1q_f32(lo);
    /* FCVTN Vd.2S, Vn.2D: writes low half, zeroes high half */
    __asm__ volatile("fcvtn %0.2s, %1.2d" : "+w"(r) : "w"(v));
    float ro[4]; vst1q_f32(ro, r);
    CHECK(feq(ro[0], (float) in[0]) && feq(ro[1], (float) in[1]) && ro[2] == 0 && ro[3] == 0,
          "fcvtn 2d->2s got %g %g %g %g", ro[0], ro[1], ro[2], ro[3]);
    /* FCVTN2 Vd.4S, Vn.2D: writes high half, keeps low half */
    r = vld1q_f32(lo);
    __asm__ volatile("fcvtn2 %0.4s, %1.2d" : "+w"(r) : "w"(v));
    vst1q_f32(ro, r);
    CHECK(ro[0] == 9 && ro[1] == 9 && feq(ro[2], (float) in[0]) && feq(ro[3], (float) in[1]),
          "fcvtn2 2d->4s got %g %g %g %g", ro[0], ro[1], ro[2], ro[3]);

    /* single -> half: FCVTN Vd.4H, Vn.4S */
    float s[4] = { 1.0f, -2.0f, 65504.0f, 0.5f };
    float32x4_t sv = vld1q_f32(s);
    uint16x8_t hr = vdupq_n_u16(0xffff);
    __asm__ volatile("fcvtn %0.4h, %1.4s" : "+w"(hr) : "w"(sv));
    uint16_t ho[8]; vst1q_u16(ho, hr);
    CHECK(ho[0] == 0x3c00 && ho[1] == 0xc000 && ho[2] == 0x7bff && ho[3] == 0x3800 && ho[4] == 0 && ho[7] == 0,
          "fcvtn 4s->4h got %04x %04x %04x %04x %04x", ho[0], ho[1], ho[2], ho[3], ho[4]);
    hr = vdupq_n_u16(0x1111);
    __asm__ volatile("fcvtn2 %0.8h, %1.4s" : "+w"(hr) : "w"(sv));
    vst1q_u16(ho, hr);
    CHECK(ho[0] == 0x1111 && ho[3] == 0x1111 && ho[4] == 0x3c00 && ho[7] == 0x3800,
          "fcvtn2 4s->8h got %04x %04x %04x %04x", ho[0], ho[4], ho[6], ho[7]);
}

static void test_fcvtxn(void) {
    /* FCVTXN rounds to odd: 1 + 2^-30 (not representable in float) must map to
       the odd neighbour 1 + 2^-23, not to 1.0. */
    double in[2] = { 1.0 + ldexp(1.0, -30), -3.0 };
    float64x2_t v = vld1q_f64(in);
    float32x4_t r = vdupq_n_f32(7);
    __asm__ volatile("fcvtxn %0.2s, %1.2d" : "+w"(r) : "w"(v));
    float ro[4]; vst1q_f32(ro, r);
    CHECK(ro[0] == 1.0f + ldexpf(1.0f, -23) && ro[1] == -3.0f && ro[2] == 0 && ro[3] == 0,
          "fcvtxn got %.9g %g %g %g", ro[0], ro[1], ro[2], ro[3]);
    r = vdupq_n_f32(7);
    __asm__ volatile("fcvtxn2 %0.4s, %1.2d" : "+w"(r) : "w"(v));
    vst1q_f32(ro, r);
    CHECK(ro[0] == 7 && ro[1] == 7 && ro[2] == 1.0f + ldexpf(1.0f, -23) && ro[3] == -3.0f,
          "fcvtxn2 got %g %g %.9g %g", ro[0], ro[1], ro[2], ro[3]);
}

static void test_fixpt(void) {
    /* FCVTZS Vd.4S, Vn.4S, #12 (the exact encoding libvips trips on: 0x4f74fc63 is the .2D form) */
    float in[4] = { 1.5f, -2.75f, 1000.123f, 0.0f };
    float32x4_t v = vld1q_f32(in);
    int32x4_t r;
    __asm__ volatile("fcvtzs %0.4s, %1.4s, #12" : "=w"(r) : "w"(v));
    int32_t ro[4]; vst1q_s32(ro, r);
    for (int i = 0; i < 4; i++)
        CHECK(ro[i] == (int32_t) truncf(in[i] * 4096.0f), "fcvtzs.4s #12 lane %d got %d", i, ro[i]);

    /* .2S form zeroes the upper half */
    int32x4_t r2 = vdupq_n_s32(-1);
    __asm__ volatile("fcvtzs %0.2s, %1.2s, #4" : "+w"(r2) : "w"(v));
    vst1q_s32(ro, r2);
    CHECK(ro[0] == 24 && ro[1] == -44 && ro[2] == 0 && ro[3] == 0, "fcvtzs.2s #4 got %d %d %d %d", ro[0], ro[1], ro[2], ro[3]);

    /* 64-bit lanes: FCVTZS Vd.2D, Vn.2D, #12 */
    double din[2] = { 3.5, -0.001220703125 /* -5/4096 */ };
    float64x2_t dv = vld1q_f64(din);
    int64x2_t dr;
    __asm__ volatile("fcvtzs %0.2d, %1.2d, #12" : "=w"(dr) : "w"(dv));
    int64_t dro[2]; vst1q_s64(dro, dr);
    CHECK(dro[0] == 14336 && dro[1] == -5, "fcvtzs.2d #12 got %lld %lld", (long long) dro[0], (long long) dro[1]);

    /* FCVTZU saturates negatives to 0 */
    uint32x4_t ur;
    __asm__ volatile("fcvtzu %0.4s, %1.4s, #8" : "=w"(ur) : "w"(v));
    uint32_t uro[4]; vst1q_u32(uro, ur);
    CHECK(uro[0] == 384 && uro[1] == 0 && uro[2] == 256031 && uro[3] == 0, "fcvtzu.4s #8 got %u %u %u %u", uro[0], uro[1], uro[2], uro[3]);

    /* SCVTF Vd.4S, Vn.4S, #16 : int/65536 */
    int32_t si[4] = { 65536, -32768, 1, 0 };
    int32x4_t sv = vld1q_s32(si);
    float32x4_t sf;
    __asm__ volatile("scvtf %0.4s, %1.4s, #16" : "=w"(sf) : "w"(sv));
    float sfo[4]; vst1q_f32(sfo, sf);
    CHECK(sfo[0] == 1.0f && sfo[1] == -0.5f && sfo[2] == ldexpf(1.0f, -16) && sfo[3] == 0, "scvtf.4s #16 got %g %g %g %g", sfo[0], sfo[1], sfo[2], sfo[3]);

    /* UCVTF Vd.2D, Vn.2D, #32 with a value above 2^32 */
    uint64_t ui[2] = { 1ULL << 40, 3 };
    uint64x2_t uv = vld1q_u64(ui);
    float64x2_t uf;
    __asm__ volatile("ucvtf %0.2d, %1.2d, #32" : "=w"(uf) : "w"(uv));
    double ufo[2]; vst1q_f64(ufo, uf);
    CHECK(ufo[0] == 256.0 && ufo[1] == ldexp(3.0, -32), "ucvtf.2d #32 got %g %g", ufo[0], ufo[1]);

    /* fbits at the maximum (32 for .4S) must not wrap the shift */
    float big[4] = { 4.0f, 0, 0, 0 };
    float32x4_t bv = vld1q_f32(big);
    int32x4_t br;
    __asm__ volatile("fcvtzs %0.4s, %1.4s, #32" : "=w"(br) : "w"(bv));
    int32_t bro[4]; vst1q_s32(bro, br);
    CHECK(bro[0] == INT32_MAX, "fcvtzs.4s #32 saturation got %d", bro[0]);
    int32_t one[4] = { 1, 0, 0, 0 };
    float32x4_t of;
    __asm__ volatile("scvtf %0.4s, %1.4s, #32" : "=w"(of) : "w"(vld1q_s32(one)));
    float ofo[4]; vst1q_f32(ofo, of);
    CHECK(ofo[0] == ldexpf(1.0f, -32), "scvtf.4s #32 got %g", ofo[0]);
}

/* FMOV (scalar, immediate): every VFPExpandImm constant gcc likes to emit.
   Compared as raw bits so the check itself cannot depend on a broken FMOV. */
static void test_fmov_imm(void) {
    static const struct { double v; uint64_t bits; } dv[] = {
        { 2.25, 0x4002000000000000ULL }, { -2.25, 0xc002000000000000ULL },
        { 31.0, 0x403f000000000000ULL }, { 0.140625, 0x3fc2000000000000ULL },
        { 1.125, 0x3ff2000000000000ULL }, { 5.5, 0x4016000000000000ULL },
        { 1.5, 0x3ff8000000000000ULL }, { -1.0, 0xbff0000000000000ULL },
        { 0.5, 0x3fe0000000000000ULL }, { -8.0, 0xc020000000000000ULL },
        { 0.125, 0x3fc0000000000000ULL }, { 30.0, 0x403e000000000000ULL },
    };
    for (unsigned i = 0; i < sizeof(dv) / sizeof(dv[0]); i++) {
        volatile double d = dv[i].v;
        uint64_t b; memcpy(&b, (const void *) &d, 8);
        CHECK(b == dv[i].bits, "fmov d, #%g gave bits %016llx", dv[i].v, (unsigned long long) b);
    }
    static const struct { float v; uint32_t bits; } fv[] = {
        { 2.25f, 0x40100000u }, { 31.0f, 0x41f80000u }, { 1.9375f, 0x3ff80000u },
        { -0.140625f, 0xbe100000u }, { 1.5f, 0x3fc00000u }, { 3.5f, 0x40600000u },
    };
    for (unsigned i = 0; i < sizeof(fv) / sizeof(fv[0]); i++) {
        volatile float f = fv[i].v;
        uint32_t b; memcpy(&b, (const void *) &f, 4);
        CHECK(b == fv[i].bits, "fmov s, #%g gave bits %08x", (double) fv[i].v, b);
    }
}

int main(void) {
    test_fmov_imm();
    test_fcvtl();
    test_fcvtn();
    test_fcvtxn();
    test_fixpt();
    if (failures) {
        printf("NEON CONVERT FAILED (%d)\n", failures);
        return 1;
    }
    printf("NEON CONVERT OK\n");
    return 0;
}
