#include "s21_math_tst.h"

START_TEST(s21_atan_test_1) {
    double n = Rand_R(-1e+15, 1e+15);
    ck_assert_ldouble_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_2) {
    ck_assert_ldouble_nan(s21_atan(NAN));
    ck_assert_ldouble_nan(atan(NAN));
    ck_assert_ldouble_nan(s21_atan(-NAN));
    ck_assert_ldouble_nan(atan(-NAN));
    ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atan(INFINITY), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_3) {
    ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(100.0), atan(100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(-100.0), atan(-100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(256.43), atan(256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(-256.43), atan(-256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_5) {
    double n = Rand_R(-1.0, 1.0);
    ck_assert_ldouble_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_6) {
    double n = Rand_R(-0.9999, 0.9999);
    ck_assert_ldouble_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_7) {
    double n = Rand_R(-0.9999, 1e-8);
    ck_assert_ldouble_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_atan(n));
}
END_TEST

START_TEST(s21_atan_test_inf_plus) {
    double n = INFINITY;
    ck_assert_double_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_inf_minus) {
    double n = -INFINITY;
    ck_assert_double_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_null) {
    double n = 0.0;
    ck_assert_double_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_plus_one) {
    double n = 1;
    ck_assert_double_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_minus_one) {
    double n = -1;
    ck_assert_double_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_loop_above_plus_one) {
    double n = Rand_R(1 + 1e7, 1e7 - 1);
    ck_assert_ldouble_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_loop_less_minus_one) {
    double n = Rand_R(-1e-7 + 1, -1 - 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(n), atan(n), tst_EPS);
}
END_TEST

START_TEST(s21_atan_test_loop_less_one) {
    double n = Rand_R(-1 + 1e-7, 1 - 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(n), atan(n), 1);
}
END_TEST

Suite *s21_atan_ste(void) {
    Suite *s = suite_create("s21_atan");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_atan_test_1, 0, 100);
    tcase_add_loop_test(tc, s21_atan_test_2, 0, 100);
    tcase_add_test(tc, s21_atan_test_3);
    tcase_add_loop_test(tc, s21_atan_test_5, 0, 50);
    tcase_add_loop_test(tc, s21_atan_test_6, 0, 50);
    tcase_add_loop_test(tc, s21_atan_test_7, 0, 50);
    tcase_add_test(tc, s21_atan_test_nan);
    tcase_add_test(tc, s21_atan_test_inf_plus);
    tcase_add_test(tc, s21_atan_test_inf_minus);
    tcase_add_test(tc, s21_atan_test_null);
    tcase_add_test(tc, s21_atan_test_plus_one);
    tcase_add_test(tc, s21_atan_test_minus_one);
    tcase_add_loop_test(tc, s21_atan_test_loop_above_plus_one, 0, 100);
    tcase_add_loop_test(tc, s21_atan_test_loop_less_minus_one, 0, 100);
    tcase_add_loop_test(tc, s21_atan_test_loop_less_one, 0, 1000);

    suite_add_tcase(s , tc);

    return s;
}
