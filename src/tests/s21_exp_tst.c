#include "s21_math_tst.h"

START_TEST(s21_exp_test_1) {
    double n = Rand_R(-56.06893873235, 56.06893873235);
    ck_assert_ldouble_eq_tol(s21_exp(n), exp(n), 10e11);
}
END_TEST

START_TEST(s21_exp_test_2) {
    ck_assert_ldouble_infinite(s21_exp(INFINITY));
    ck_assert_ldouble_infinite(exp(INFINITY));
    ck_assert_ldouble_nan(s21_exp(NAN));
    ck_assert_ldouble_nan(exp(NAN));
}
END_TEST

START_TEST(s21_exp_test_3) {
    ck_assert_ldouble_eq_tol(s21_exp(1.0), exp(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_exp(-1.0), exp(-1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_exp(100.0), exp(100.0), 10e30);
    ck_assert_ldouble_eq_tol(s21_exp(-100.0), exp(-100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_exp(256.43), exp(256.43), 10e95);
    ck_assert_ldouble_eq_tol(s21_exp(-256.43), exp(-256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_exp(-0.0), exp(-0.0), tst_EPS);
}
END_TEST

START_TEST(s21_exp_test_inf_plus) {
  double n = INFINITY;
  ck_assert_ldouble_eq(s21_exp(n), exp(n));
}
END_TEST

START_TEST(s21_exp_test_inf_minus) {
  double n = -INFINITY;
  ck_assert_ldouble_eq(s21_exp(n), exp(n));
}
END_TEST

START_TEST(s21_exp_test_null) {
  double n = 0.0;
  ck_assert_ldouble_eq(s21_exp(n), exp(n));
}
END_TEST

START_TEST(s21_exp_test_above_dblmax) {
  double n = 1.79769e+308 + 1;
  ck_assert_ldouble_eq(s21_exp(n), exp(n));
}
END_TEST


Suite *s21_exp_ste(void) {
    Suite *s = suite_create("s21_exp");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_exp_test_1, 0, 1000);
    tcase_add_test(tc, s21_exp_test_2);
    tcase_add_test(tc, s21_exp_test_3);
    tcase_add_test(tc, s21_exp_test_inf_plus);
    tcase_add_test(tc, s21_exp_test_inf_minus);
    tcase_add_test(tc, s21_exp_test_null);
    tcase_add_test(tc, s21_exp_test_above_dblmax);

    suite_add_tcase(s, tc);

    return s;
}
