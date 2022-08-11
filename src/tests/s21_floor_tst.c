#include "s21_math_tst.h"

START_TEST(s21_floor_test_1) {
    double n = Rand_R(-1e17 + 1, 1e17 - 1);
    double x = Rand_R(-1e17 + 1, 1e17 - 1);
    x = -x;
    ck_assert_ldouble_eq_tol(s21_floor(n), floor(n), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), tst_EPS);
}
END_TEST

START_TEST(s21_floor_test_2) {
    ck_assert_ldouble_infinite(s21_floor(INFINITY));
    ck_assert_ldouble_infinite(floor(INFINITY));
    ck_assert_ldouble_nan(s21_floor(NAN));
    ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(s21_floor_test_3) {
    ck_assert_ldouble_eq_tol(s21_floor(1.0), floor(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(-1.0), floor(-1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(100.0), floor(100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(-100.0), floor(-100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(256.43), floor(256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(-256.43), floor(-256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(0.0), floor(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(-0.0), floor(-0.0), tst_EPS);
}
END_TEST

START_TEST(s21_floor_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_floor(n));
}
END_TEST

START_TEST(s21_floor_test_inf) {
    double n = INFINITY;
    ck_assert_ldouble_infinite(s21_floor(n));
}
END_TEST

START_TEST(s21_floor_test_null) {
    double n = 0.0;
    ck_assert_ldouble_eq(s21_floor(n), floor(n));
}
END_TEST

START_TEST(s21_floor_test_4) {
    double n = 987654321.123456789;
    ck_assert_ldouble_eq_tol(s21_floor(n), floor(n), tst_EPS);
}
END_TEST

START_TEST(s21_floor_test_5) {
    double n = -987654321.123456789;
    ck_assert_ldouble_eq_tol(s21_floor(n), floor(n), tst_EPS);
}
END_TEST

START_TEST(s21_floor_test_loop) {
    double n = Rand_R(-1e10 + 1, 1e10 - 1);
    ck_assert_ldouble_eq_tol(s21_floor(n), floor(n), tst_EPS);
}
END_TEST

Suite *s21_floor_ste(void) {
    Suite *s = suite_create("s21_floor");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_floor_test_1, 0, 1000);
    tcase_add_test(tc, s21_floor_test_2);
    tcase_add_test(tc, s21_floor_test_3);
    tcase_add_test(tc, s21_floor_test_nan);
    tcase_add_test(tc, s21_floor_test_inf);
    tcase_add_test(tc, s21_floor_test_null);
    tcase_add_test(tc, s21_floor_test_4);
    tcase_add_test(tc, s21_floor_test_5);
    tcase_add_loop_test(tc, s21_floor_test_loop, 0, 1000);

    suite_add_tcase(s, tc);

    return s;
}
