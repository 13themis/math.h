#include "s21_math_tst.h"

START_TEST(s21_sin_test_1) {
    double n = Rand_R(-1e10, 1e10);
    ck_assert_double_eq_tol(s21_sin(n), sin(n), tst_EPS);
}
END_TEST

START_TEST(s21_sin_test_2) {
    ck_assert_ldouble_nan(s21_sin(INFINITY));
    ck_assert_ldouble_nan(sin(INFINITY));
    ck_assert_ldouble_nan(s21_sin(NAN));
    ck_assert_ldouble_nan(sin(NAN));
}
END_TEST

START_TEST(s21_sin_test_3) {
    ck_assert_ldouble_eq_tol(s21_sin(1.0), sin(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_sin(-1.0), sin(-1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_sin(100.0), sin(100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_sin(-100.0), sin(-100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_sin(256.43), sin(256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_sin(-256.43), sin(-256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_sin(0.0), sin(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_sin(-0.0), sin(-0.0), tst_EPS);
}
END_TEST

START_TEST(s21_sin_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_sin(n));
}
END_TEST

START_TEST(s21_sin_test_inf_plus) {
    double n = INFINITY;
    ck_assert_ldouble_nan(s21_sin(n));
}
END_TEST

START_TEST(s21_sin_test_inf_minus) {
    double n = -INFINITY;
    ck_assert_ldouble_nan(s21_sin(n));
}
END_TEST

START_TEST(s21_sin_test_null) {
    double n = 0.0;
    ck_assert_double_eq_tol(s21_sin(n), sinl(n), tst_EPS);
}
END_TEST

START_TEST(s21_sin_test_loop) {
    double n = Rand_R(-1e10 + 1, 1e10 - 1);
    ck_assert_ldouble_eq_tol(s21_sin(n), sinl(n), tst_EPS);
}
END_TEST

Suite *s21_sin_ste(void) {
    Suite *s = suite_create("s21_sin");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_sin_test_1, 0, 1000);
    tcase_add_test(tc, s21_sin_test_2);
    tcase_add_test(tc, s21_sin_test_3);
    tcase_add_test(tc, s21_sin_test_nan);
    tcase_add_test(tc, s21_sin_test_inf_plus);
    tcase_add_test(tc, s21_sin_test_inf_minus);
    tcase_add_test(tc, s21_sin_test_null);
    tcase_add_loop_test(tc, s21_sin_test_loop, 0, 1000);

    suite_add_tcase(s, tc);

    return s;
}
