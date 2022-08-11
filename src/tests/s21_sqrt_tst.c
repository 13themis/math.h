#include "s21_math_tst.h"

START_TEST(s21_sqrt_test_1) {
    double n = Rand_R(10e-16, 10e+16);
    if (n < 0) {
        ck_assert_ldouble_nan(s21_sqrt(n));
        ck_assert_ldouble_nan(sqrt(n));
    } else {
        ck_assert_ldouble_eq_tol(s21_sqrt(n), sqrt(n), 1);
    }
}
END_TEST

START_TEST(s21_sqrt_test_2) {
    ck_assert_ldouble_nan(s21_sqrt(NAN));
    ck_assert_ldouble_nan(sqrt(NAN));
    ck_assert_ldouble_nan(s21_sqrt(-NAN));
    ck_assert_ldouble_nan(sqrt(-NAN));
    ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
    ck_assert_ldouble_infinite(sqrt(INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test_3) {
    ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), tst_EPS);
    ck_assert_ldouble_nan(s21_sqrt(-1.0));
    ck_assert_ldouble_eq_tol(s21_sqrt(100.0), sqrt(100.0), tst_EPS);
    ck_assert_ldouble_nan(s21_sqrt(-100.0));
    ck_assert_ldouble_eq_tol(s21_sqrt(256.43), sqrt(256.43), tst_EPS);
    ck_assert_ldouble_nan(s21_sqrt(-256.43));
    ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), tst_EPS);
    ck_assert_ldouble_nan(s21_sqrt(-0.0));
    ck_assert_ldouble_eq_tol(s21_sqrt(10e+20), sqrt(10e+20), 10e-3);
}
END_TEST

START_TEST(s21_sqrt_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_sqrt(n));
}
END_TEST

START_TEST(s21_sqrt_test_inf) {
    double n = INFINITY;
    ck_assert_ldouble_infinite(s21_sqrt(n));
}
END_TEST

START_TEST(s21_sqrt_test_num_negative) {
    double n = -1.0;
    ck_assert_ldouble_nan(s21_sqrt(n));
}
END_TEST

START_TEST(s21_sqrt_test_null) {
    double n = 0.0;
    ck_assert_ldouble_eq(s21_sqrt(n), sqrt(n));
}
END_TEST

START_TEST(s21_sqrt_test_loop_from_null_to_one) {
    double n = Rand_R(tst_EPS, 1 - tst_EPS);
    ck_assert_ldouble_eq_tol(s21_sqrt(n), sqrt(n), 10e-4);
}
END_TEST

START_TEST(s21_sqrt_test_loop_from_one) {
    double n = Rand_R(1 + tst_EPS, 1e+16);
    ck_assert_ldouble_eq_tol(s21_sqrt(n), sqrt(n), tst_EPS);
}
END_TEST


Suite *s21_sqrt_ste(void) {
    Suite *s = suite_create("s21_sqrt");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_sqrt_test_1, 0, 1000);
    tcase_add_test(tc, s21_sqrt_test_2);
    tcase_add_test(tc, s21_sqrt_test_3);
    tcase_add_test(tc, s21_sqrt_test_nan);
    tcase_add_test(tc, s21_sqrt_test_inf);
    tcase_add_test(tc, s21_sqrt_test_num_negative);
    tcase_add_test(tc, s21_sqrt_test_null);
    tcase_add_loop_test(tc, s21_sqrt_test_loop_from_null_to_one, 0, 1000);
    tcase_add_loop_test(tc, s21_sqrt_test_loop_from_one, 0, 1000);

    suite_add_tcase(s, tc);

    return s;
}
