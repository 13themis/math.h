#include "s21_math_tst.h"

START_TEST(s21_tan_test_1) {
    double n = Rand_R(-2 * S21_M_PI, 2 * S21_M_PI);
    ck_assert_ldouble_eq_tol(s21_tan(n), tan(n), 10e5);
}
END_TEST

START_TEST(s21_tan_test_2) {
    ck_assert_ldouble_eq_tol(s21_tan(1.0), tan(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(-1.0), tan(-1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(100.0), tan(100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(-100.0), tan(-100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(256.43), tan(256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(-256.43), tan(-256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(0.0), tan(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(-0.0), tan(-0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(10e+15), tan(10e+15), 2);
}
END_TEST

START_TEST(s21_tan_test_3) {
    ck_assert_ldouble_nan(s21_tan(NAN));
    ck_assert_ldouble_nan(tan(NAN));
    ck_assert_ldouble_nan(s21_tan(-NAN));
    ck_assert_ldouble_nan(tan(-NAN));
    ck_assert_ldouble_nan(s21_tan(INFINITY));
    ck_assert_ldouble_nan(tan(INFINITY));
    ck_assert_ldouble_nan(s21_tan(-INFINITY));
    ck_assert_ldouble_nan(tan(-INFINITY));
}
END_TEST

START_TEST(s21_tan_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_tan(n));
}
END_TEST

START_TEST(s21_tan_test_inf_plus) {
    double n = INFINITY;
    ck_assert_ldouble_nan(s21_tan(n));
}
END_TEST

START_TEST(s21_tan_test_inf_minus) {
    double n = -INFINITY;
    ck_assert_ldouble_nan(s21_tan(n));
}
END_TEST

START_TEST(s21_tan_test_null) {
    double n = 0.0;
    ck_assert_double_eq_tol(s21_tan(n), tan(n), tst_EPS);
}
END_TEST

START_TEST(s21_tan_test_plus_half_pi) {
    double n = S21_M_PI * S21_M_PI;
    ck_assert_double_eq_tol(s21_tan(n), tan(n), tst_EPS);
}
END_TEST

START_TEST(s21_tan_test_minus_half_pi) {
    double n = S21_M_PI * S21_M_PI;
    ck_assert_double_eq_tol(s21_tan(n), tan(n), tst_EPS);
}
END_TEST

START_TEST(s21_tan_test_loop) {
    double n = Rand_R(-(S21_M_PI * S21_M_PI) + tst_EPS, (S21_M_PI * S21_M_PI)- tst_EPS);
    ck_assert_ldouble_eq_tol(s21_tan(n), tan(n), 1);
}
END_TEST

Suite *s21_tan_ste(void) {
    Suite *s = suite_create("s21_tan");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_tan_test_1, 0, 1000);
    tcase_add_test(tc, s21_tan_test_2);
    tcase_add_test(tc, s21_tan_test_3);
    tcase_add_test(tc, s21_tan_test_nan);
    tcase_add_test(tc, s21_tan_test_inf_plus);
    tcase_add_test(tc, s21_tan_test_inf_minus);
    tcase_add_test(tc, s21_tan_test_null);
    tcase_add_test(tc, s21_tan_test_plus_half_pi);
    tcase_add_test(tc, s21_tan_test_minus_half_pi);
    tcase_add_loop_test(tc, s21_tan_test_loop, 0, 1000);

    suite_add_tcase(s, tc);

    return s;
}
