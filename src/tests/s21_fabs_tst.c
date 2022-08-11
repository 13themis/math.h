#include "s21_math_tst.h"

START_TEST(s21_fabs_test_1) {
    double n = -3.12345634567876;
    ck_assert_ldouble_eq(s21_fabs(n), fabs(n));
}
END_TEST

START_TEST(s21_fabs_test_2) {
    ck_assert_ldouble_infinite(s21_fabs(INFINITY));
    ck_assert_ldouble_infinite(fabs(INFINITY));
    ck_assert_ldouble_nan(s21_fabs(NAN));
    ck_assert_ldouble_nan(fabs(NAN));
}
END_TEST

START_TEST(s21_fabs_test_3) {
    ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fabs(100.0), fabs(100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fabs(-100.0), fabs(-100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fabs(256.43), fabs(256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fabs(-256.43), fabs(-256.43), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), tst_EPS);
}
END_TEST

START_TEST(s21_fabs_test_4) {
    double n = Rand_R(-1e-6, 1e-6);
    n = -n;
    ck_assert_ldouble_eq_tol(s21_fabs(n), fabs(n), tst_EPS);
}
END_TEST

START_TEST(s21_fabs_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_fabs(n));
}
END_TEST

START_TEST(s21_fabs_test_inf_plus) {
    double n = INFINITY;
    ck_assert_ldouble_eq(s21_fabs(n), fabs(n));
}
END_TEST

START_TEST(s21_fabs_test_inf_minus) {
    double n = -INFINITY;
    ck_assert_ldouble_eq(s21_fabs(n), fabs(n));
}
END_TEST

START_TEST(s21_fabs_test_null_plus) {
    double n = 0.0;
    ck_assert_ldouble_eq(s21_fabs(n), fabs(n));
}
END_TEST

START_TEST(s21_fabs_test_null_minus) {
    double n = -0.0;
    ck_assert_ldouble_eq(s21_fabs(n), fabs(n));
}
END_TEST

START_TEST(s21_fabs_test_5) {
    double n = 987654321.123456789;
    ck_assert_ldouble_eq_tol(s21_fabs(n), fabs(n), tst_EPS);
}
END_TEST

START_TEST(s21_fabs_test_6) {
    double n = -987654321.123456789;
    ck_assert_ldouble_eq_tol(s21_fabs(n), fabs(n), tst_EPS);
}
END_TEST

START_TEST(s21_fabs_test_loop) {
    double n = Rand_R(-1e10 + 1, 1e10 - 1);
    ck_assert_ldouble_eq_tol(s21_fabs(n), fabs(n), tst_EPS);
}
END_TEST

Suite *s21_fabs_ste(void) {
    Suite *s = suite_create("s21_fabs");
    TCase *tc = tcase_create("Core");

    tcase_add_test(tc, s21_fabs_test_1);
    tcase_add_test(tc, s21_fabs_test_2);
    tcase_add_test(tc, s21_fabs_test_3);
    tcase_add_loop_test(tc, s21_fabs_test_4, 0, 1000);
    tcase_add_test(tc, s21_fabs_test_nan);
    tcase_add_test(tc, s21_fabs_test_inf_plus);
    tcase_add_test(tc, s21_fabs_test_inf_minus);
    tcase_add_test(tc, s21_fabs_test_null_plus);
    tcase_add_test(tc, s21_fabs_test_null_minus);
    tcase_add_test(tc, s21_fabs_test_5);
    tcase_add_test(tc, s21_fabs_test_6);
    tcase_add_loop_test(tc, s21_fabs_test_loop, 0, 1000);

    suite_add_tcase(s, tc);

    return s;
}
