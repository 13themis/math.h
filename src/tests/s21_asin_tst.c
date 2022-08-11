#include "s21_math_tst.h"

START_TEST(s21_asin_test_1) {
    ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), tst_EPS);
    ck_assert_ldouble_nan(s21_asin(100.0));
    ck_assert_ldouble_nan(s21_asin(-100.0));
    ck_assert_ldouble_nan(s21_asin(256.43));
    ck_assert_ldouble_nan(s21_asin(-256.43));
    ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), tst_EPS);
}
END_TEST

START_TEST(s21_asin_test_2) {
    double n = Rand_R(-1, 1);
    ck_assert_ldouble_eq_tol(s21_asin(n), asin(n), tst_EPS);}
END_TEST

START_TEST(s21_asin_test_3) {
    double n = Rand_R(-1, 1);
    if (s21_fabs(n) > 1) {
        ck_assert_ldouble_nan(s21_asin(n));
        ck_assert_ldouble_nan(asin(n));
    }
}
END_TEST

START_TEST(s21_asin_test_4) {
    double n = Rand_R(0.1, 0.8);
    ck_assert_ldouble_eq_tol(s21_asin(n), asin(n), tst_EPS);
}
END_TEST

START_TEST(s21_asin_test_5) {
    double n = Rand_R(-1, 1);
    ck_assert_ldouble_eq_tol(s21_asin(n), asin(n), tst_EPS);
}
END_TEST

START_TEST(s21_asin_test_6) {
    double n = Rand_R(-0.9, 0.9);
    ck_assert_ldouble_eq_tol(s21_asin(n), asin(n), tst_EPS);
}
END_TEST

START_TEST(s21_asin_test_7) {
    ck_assert_ldouble_nan(s21_asin(NAN));
    ck_assert_ldouble_nan(s21_asin(-NAN));
    ck_assert_ldouble_nan(s21_asin(INFINITY));
    ck_assert_ldouble_nan(s21_asin(-INFINITY));
}
END_TEST

START_TEST(s21_asin_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_asin(n));
}
END_TEST

START_TEST(s21_asin_test_inf_plus) {
    double n = INFINITY;
    ck_assert_ldouble_nan(s21_asin(n));
}
END_TEST

START_TEST(s21_asin_test_inf_minus) {
    double n = -INFINITY;
    ck_assert_ldouble_nan(s21_asin(n));
}
END_TEST

START_TEST(s21_asin_test_above_one) {
    double x = 2.1;
    double n = -2.1;
    ck_assert_ldouble_nan(s21_asin(x));
    ck_assert_ldouble_nan(s21_asin(n));
}
END_TEST

START_TEST(s21_asin_test_plus_one) {
    double n = 1;
    ck_assert_double_eq_tol(s21_asin(n), asin(n), tst_EPS);
}
END_TEST

START_TEST(s21_asin_test_minus_one) {
    double n = -1;
    ck_assert_double_eq_tol(s21_asin(n), asin(n), tst_EPS);
}
END_TEST

START_TEST(s21_asin_test_null) {
    double n = 0.0;
    ck_assert_double_eq_tol(s21_asin(n), asin(n), tst_EPS);
}
END_TEST

START_TEST(s21_asin_test_loop) {
    double n = Rand_R(-1 + tst_EPS, 1 - tst_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(n), asin(n), tst_EPS);
}
END_TEST

Suite *s21_asin_ste(void) {
    Suite *s = suite_create("s21_asin");
    TCase *tc = tcase_create("Core");

    tcase_add_test(tc, s21_asin_test_1);
    tcase_add_loop_test(tc, s21_asin_test_2, 0, 400);
    tcase_add_loop_test(tc, s21_asin_test_3, 0, 400);
    tcase_add_loop_test(tc, s21_asin_test_4, 0, 400);
    tcase_add_loop_test(tc, s21_asin_test_5, 0, 400);
    tcase_add_loop_test(tc, s21_asin_test_6, 0, 400);
    tcase_add_test(tc, s21_asin_test_7);
    tcase_add_test(tc, s21_asin_test_nan);
    tcase_add_test(tc, s21_asin_test_inf_plus);
    tcase_add_test(tc, s21_asin_test_inf_minus);
    tcase_add_test(tc, s21_asin_test_above_one);
    tcase_add_test(tc, s21_asin_test_plus_one);
    tcase_add_test(tc, s21_asin_test_minus_one);
    tcase_add_test(tc, s21_asin_test_null);
    tcase_add_loop_test(tc, s21_asin_test_loop, 0, 1000);

    suite_add_tcase(s, tc);

    return s;
}
