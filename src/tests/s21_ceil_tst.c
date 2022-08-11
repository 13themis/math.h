#include "s21_math_tst.h"

START_TEST(s21_ceil_test_1) {
    double n = Rand_R(-10e10, 10e10);
    n = -n;
    ck_assert_ldouble_eq(s21_ceil(n), ceil(n));
}
END_TEST

START_TEST(s21_ceil_test_2) {
    ck_assert_ldouble_infinite(s21_ceil(INFINITY));
    ck_assert_ldouble_infinite(ceil(INFINITY));
    ck_assert_ldouble_nan(s21_ceil(NAN));
    ck_assert_ldouble_nan(ceil(NAN));
}
END_TEST

START_TEST(s21_ceil_test_3) {
    ck_assert_ldouble_eq_tol(s21_ceil(1.0), ceil(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(-1.0), ceil(-1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(100.0), ceil(100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(-100.0), ceil(-100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(256.43), ceil(256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(-256.43), ceil(-256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceil(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(-0.0), ceil(-0.0), tst_EPS);
}
END_TEST

START_TEST(s21_ceil_test_4) {
    double n = 8888888888888888.88888888888888888;
    ck_assert_ldouble_eq(s21_ceil(n), ceil(n));
}
END_TEST

START_TEST(s21_ceil_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_ceil(n));
}
END_TEST

START_TEST(s21_ceil_test_inf) {
    double n = INFINITY;
    ck_assert_ldouble_infinite(s21_ceil(n));
}
END_TEST

START_TEST(s21_ceil_test_null) {
    double n = 0.0;
    ck_assert_ldouble_eq(s21_ceil(n), ceil(n));
}
END_TEST

START_TEST(s21_ceil_test_5) {
    double n = 987654321.123456789;
    ck_assert_ldouble_eq_tol(s21_ceil(n), ceil(n), tst_EPS);
}
END_TEST

START_TEST(s21_ceil_test_6) {
    double n = -987654321.123456789;
    ck_assert_ldouble_eq_tol(s21_ceil(n), ceil(n), tst_EPS);
}
END_TEST

START_TEST(s21_ceil_test_loop) {
    double n = Rand_R(-1e10 + 1, 1e10 - 1);
    ck_assert_ldouble_eq_tol(s21_ceil(n), ceil(n), tst_EPS);
}
END_TEST

Suite *s21_ceil_ste(void) {
    Suite *s = suite_create("s21_ceil");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_ceil_test_1, 0, 1000);
    tcase_add_test(tc, s21_ceil_test_2);
    tcase_add_test(tc, s21_ceil_test_3);
    tcase_add_test(tc, s21_ceil_test_4);
    tcase_add_test(tc, s21_ceil_test_nan);
    tcase_add_test(tc, s21_ceil_test_inf);
    tcase_add_test(tc, s21_ceil_test_null);
    tcase_add_test(tc, s21_ceil_test_5);
    tcase_add_test(tc, s21_ceil_test_6);
    tcase_add_loop_test(tc, s21_ceil_test_loop, 0, 1000);

    suite_add_tcase(s, tc);

    return s;
}
