#include "s21_math_tst.h"

START_TEST(s21_fmod_test_1) {
    double x = Rand_R(-1e-11, 1e+11);
    double y = Rand_R(-1e-11, 1e+11);
    double n = Rand_R(-1e-11, 1e+11);
    double k = Rand_R(-1e-11, 1e+11);
    n = -n;
    k = -k;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1);
    ck_assert_ldouble_eq_tol(s21_fmod(n, k), fmod(n, k), 1);
}
END_TEST

START_TEST(s21_fmod_test_2) {
    ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
    ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
    ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
    ck_assert_ldouble_nan(fmod(NAN, NAN));
     ck_assert_ldouble_nan(s21_fmod(-1.0, 0.0));
     ck_assert_ldouble_nan(s21_fmod(-0.0, 0.0));
}
END_TEST

START_TEST(s21_fmod_test_3) {
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, 1.3), fmod(1.0, 1.3), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(100.0, 56.21), fmod(100.0, 56.21), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(-100.0, -56.21), fmod(-100.0, -56.21), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(256.43, 21.21), fmod(256.43, 21.21), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(-256.43, -21.21), fmod(-256.43, -21.21), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0, INFINITY), fmod(0.0, INFINITY), tst_EPS);
}
END_TEST

START_TEST(s21_fmod_test_nan_x) {
    double x = NAN;
    double y = 2.1;
    ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_inf_x) {
    double x = INFINITY;
    double y = 2.1;
    ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_inf_y) {
    double x = 2.1;
    double y = INFINITY;
    ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_null_x) {
    double x = 0.0;
    double y = 2.1;
    ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_null_y) {
    double x = 2.1;
    double y = 0.0;
    ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_loop) {
    double x = Rand_R(-1e+10 + tst_EPS, 1e+10 - tst_EPS);
    double y = Rand_R(-1e+10 + tst_EPS, 1e+10 - tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 10e4);
}
END_TEST

Suite *s21_fmod_ste(void) {
    Suite *s = suite_create("s21_fmod");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_fmod_test_1, 0, 1000);
    tcase_add_test(tc, s21_fmod_test_2);
    tcase_add_test(tc, s21_fmod_test_3);
    tcase_add_test(tc, s21_fmod_test_nan_x);
    tcase_add_test(tc, s21_fmod_test_inf_x);
    tcase_add_test(tc, s21_fmod_test_inf_y);
    tcase_add_test(tc, s21_fmod_test_null_x);
    tcase_add_test(tc, s21_fmod_test_null_y);
    tcase_add_loop_test(tc, s21_fmod_test_loop, 0, 1000);


    suite_add_tcase(s, tc);

    return s;
}
