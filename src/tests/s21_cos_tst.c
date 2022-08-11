#include "s21_math_tst.h"

START_TEST(s21_cos_test_1) {
    double n = Rand_R(-200 + 1, 200 - 1);
    ck_assert_double_eq_tol(s21_cos(n), cos(n), tst_EPS);
}
END_TEST

START_TEST(s21_cos_test_2) {
    ck_assert_ldouble_nan(s21_cos(INFINITY));
    ck_assert_ldouble_nan(cos(INFINITY));
    ck_assert_ldouble_nan(s21_cos(NAN));
    ck_assert_ldouble_nan(cos(NAN));
}
END_TEST

START_TEST(s21_cos_test_3) {
    ck_assert_double_eq_tol(s21_cos(1.0), cos(1.0), tst_EPS);
    ck_assert_double_eq_tol(s21_cos(-1.0), cos(-1.0), tst_EPS);
    ck_assert_double_eq_tol(s21_cos(100.0), cos(100.0), tst_EPS);
    ck_assert_double_eq_tol(s21_cos(-100.0), cos(-100.0), tst_EPS);
    ck_assert_double_eq_tol(s21_cos(256.43), cos(256.43), tst_EPS);
    ck_assert_double_eq_tol(s21_cos(-256.43), cos(-256.43), tst_EPS);
    ck_assert_double_eq_tol(s21_cos(0.0), cos(0.0), tst_EPS);
    ck_assert_double_eq_tol(s21_cos(-0.0), cos(-0.0), tst_EPS);
}
END_TEST

Suite *s21_cos_ste(void) {
    Suite *s = suite_create("s21_cos");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_cos_test_1, 0, 1000);
    tcase_add_test(tc, s21_cos_test_2);
    tcase_add_test(tc, s21_cos_test_3);

    suite_add_tcase(s, tc);

    return s;
}
