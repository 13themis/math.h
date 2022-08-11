#include "s21_math_tst.h"


START_TEST(s21_log_test_1) {
    double n = Rand_R(1e-10, 1e+10);
    if (n == 0.0) {
        ck_assert_ldouble_nan(s21_log(n));
        ck_assert_ldouble_nan(log(n));
        ck_assert_ldouble_eq(s21_log(n), log(n));
    } else if (n < 0.0) {
        ck_assert_ldouble_nan(s21_log(n));
        ck_assert_ldouble_nan(log(n));
        ck_assert_ldouble_eq(s21_log(n), log(n));
    } else {
        ck_assert_ldouble_eq_tol(s21_log(n), log(n), tst_EPS);
    }
}
END_TEST

START_TEST(s21_log_test_2) {
    ck_assert_ldouble_nan(s21_log(NAN));
    ck_assert_ldouble_nan(log(NAN));
    ck_assert_ldouble_nan(s21_log(-NAN));
    ck_assert_ldouble_nan(log(-NAN));
    ck_assert_ldouble_infinite(s21_log(INFINITY));
    ck_assert_ldouble_infinite(log(INFINITY));
    ck_assert_ldouble_nan(s21_log(-INFINITY));
    ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(s21_log_test_3) {
    ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_log(100.0), log(100.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_log(256.43), log(256.43), tst_EPS);
}
END_TEST

START_TEST(s21_floor_test_4) {
    double n = 888888888888888888888888.88888888888888888;
    ck_assert_ldouble_eq_tol(s21_log(n), log(n), tst_EPS);
}
END_TEST

START_TEST(s21_log_test_nan) {
    double n = NAN;
    ck_assert_ldouble_nan(s21_log(n));
}
END_TEST

START_TEST(s21_log_test_inf_plus) {
    double n = INFINITY;
    ck_assert_ldouble_eq(s21_log(n), log(n));
}
END_TEST

START_TEST(s21_log_test_inf_minus) {
    double n = -INFINITY;
    ck_assert_ldouble_nan(s21_log(n));
}
END_TEST

START_TEST(s21_log_test_one) {
    double n = 1.0;
    ck_assert_ldouble_eq(s21_log(n), log(n));
}
END_TEST

START_TEST(s21_log_test_null) {
    double n = 0.0;
    ck_assert_ldouble_eq(s21_log(n), log(n));
    }
END_TEST

START_TEST(s21_log_test_num_negative) {
    double n = -1.0;
    ck_assert_ldouble_nan(s21_log(n));
}
END_TEST

START_TEST(s21_log_test_loop_from_null_to_one) {
    double n = Rand_R(tst_EPS, 1 - tst_EPS);
    ck_assert_ldouble_eq_tol(s21_log(n), log(n), 1);
}
END_TEST

START_TEST(s21_log_test_loop_from_one) {
    double n = Rand_R(1 + tst_EPS, 1e+10 - tst_EPS);
    ck_assert_ldouble_eq_tol(s21_log(n), log(n), tst_EPS);
}
END_TEST

Suite *s21_log_ste(void) {
    Suite *s = suite_create("s21_log");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_log_test_1, 0, 1000);
    tcase_add_test(tc, s21_log_test_2);
    tcase_add_test(tc, s21_log_test_3);
    tcase_add_test(tc, s21_floor_test_4);
    tcase_add_test(tc, s21_log_test_nan);
    tcase_add_test(tc, s21_log_test_inf_plus);
    tcase_add_test(tc, s21_log_test_inf_minus);
    tcase_add_test(tc, s21_log_test_one);
    tcase_add_test(tc, s21_log_test_null);
    tcase_add_test(tc, s21_log_test_num_negative);
    tcase_add_loop_test(tc, s21_log_test_loop_from_null_to_one, 0, 1000);
    tcase_add_loop_test(tc, s21_log_test_loop_from_one, 0, 1000);

    suite_add_tcase(s, tc);

    return s;
}
