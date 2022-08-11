#include "s21_math_tst.h"

START_TEST(s21_pow_test_1) {
    long double exp = Rand_R(-10, 10);
    long double n = 20;
    ck_assert_double_eq_tol(s21_pow(n, exp), pow(n, exp), 10e7);
}
END_TEST

START_TEST(s21_pow_test_2) {
    long double n = -23.123123;
    long double exp = 8;
    ck_assert_double_eq_tol(s21_pow(n, exp), pow(n, exp), 10e2);
}
END_TEST

START_TEST(s21_pow_test_3) {
    long double n = -10.11123;
    long double exp = -0.23;
    ck_assert_double_nan(s21_pow(n, exp));
    ck_assert_double_nan(pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_4) {
    long double n = 0.0;
    long double exp = -0.33;
    ck_assert_ldouble_infinite(s21_pow(n, exp));
    ck_assert_ldouble_infinite(pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_5) {
    ck_assert_ldouble_eq_tol(s21_pow(1.0, 322), pow(1.0, 322), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_pow(-1.0, 322), pow(-1.0, 322), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_pow(100.0, 23), pow(100.0, 23), 10e33);
    ck_assert_ldouble_eq_tol(s21_pow(-100.0, 21), pow(-100.0, 21), 10e28);
    ck_assert_double_nan(s21_pow(0.0, NAN));
    ck_assert_ldouble_infinite(s21_pow(INFINITY, 2));
}
END_TEST

//  pow(+0, exp), where exp is a negative odd integer, returns +∞
START_TEST(s21_pow_test_pos_zero_n_neg_odd_int_exp) {
    long double n = 0.0;
    long double exp = -21;
    ck_assert_ldouble_infinite(s21_pow(n, exp));
}
END_TEST

//  pow(+0, exp), where exp is a positive odd integer, returns +0
START_TEST(s21_pow_test_pos_zero_n_pos_odd_int_exp) {
    long double n = 0.0;
    long double exp = 21;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

//  pow(-0, exp), where exp is a positive odd integer, returns -0
START_TEST(s21_pow_test_neg_zero_n_pos_odd_int_exp) {
    long double n = -0.0;
    long double exp = 21;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

//  pow(±0, exp), where exp is positive non-integer or a positive even integer,
//  returns +0
START_TEST(s21_pow_test_pos_zero_n_pos_even_int_exp) {
    long double n = 0.0;
    long double exp = 42;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

START_TEST(s21_pow_test_pos_zero_n_pos_not_int_exp) {
    long double n = 0.0;
    long double exp = 1.23456;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

START_TEST(s21_pow_test_neg_zero_n_pos_even_int_exp) {
    long double n = -0.0;
    long double exp = 42;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

START_TEST(s21_pow_test_neg_zero_n_pos_not_int_exp) {
    long double n = -0.0;
    long double exp = 1.23456;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

START_TEST(s21_pow_test_neg_one_n_neg_inf_exp) {
    long double n = -1.0;
    long double exp = -INFINITY;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

//  pow(+1, exp) returns 1 for any exp, even when exp is NaN
START_TEST(s21_pow_test_pos_one_n_pos_inf_exp) {
    long double n = 1.0;
    long double exp = INFINITY;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

START_TEST(s21_pow_test_pos_one_n_neg_inf_exp) {
    long double n = 1.0;
    long double exp = -INFINITY;
    ck_assert_ldouble_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

//  pow(n, ±0) returns 1 for any n, even when n is NaN
START_TEST(s21_pow_test_nan_n_pos_zero_exp) {
    long double n = NAN;
    long double exp = 0.0;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_nan_n_neg_zero_exp) {
    long double n = NAN;
    long double exp = -0.0;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_pos_inf_n_pos_zero_exp) {
    long double n = INFINITY;
    long double exp = 0.0;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_not_int_n_pos_zero_exp) {
    long double n = -1.23456;
    long double exp = 0.0;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_pos_not_int_n_neg_zero_exp) {
    long double n = 1.23456;
    long double exp = -0.0;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_not_int_n_neg_zero_exp) {
    long double n = -1.23456;
    long double exp = -0.0;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(n, exp) returns NaN and raises FE_INVALID if n is finite and
//  negative and exp is finite and non-integer
START_TEST(s21_pow_test_neg_int_n_pos_not_int_exp) {
    long double n = -21;
    long double exp = 1.23456;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_int_n_neg_not_int_exp) {
    long double n = -21;
    long double exp = -1.23456;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_not_int_n_pos_not_int_exp) {
    long double n = -1.23456;
    long double exp = 1.23456;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_not_int_n_neg_not_int_exp) {
    long double n = -1.23456;
    long double exp = -1.23456;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

//  pow(n, -∞) returns +∞ for any |n|<1

START_TEST(s21_pow_test_neg_not_int_less_one_n_neg_inf_exp) {
    long double n = -0.23456;
    long double exp = -INFINITY;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(n, -∞) returns +0 for any |n|>1
START_TEST(s21_pow_test_pos_not_int_above_one_n_neg_inf_exp) {
    long double n = 1.23456;
    long double exp = -INFINITY;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(n, +∞) returns +0 for any |n|<1
START_TEST(s21_pow_test_pos_not_int_less_one_n_pos_inf_exp) {
    long double n = 0.23456;
    long double exp = INFINITY;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(n, +∞) returns +∞ for any |n|>1
START_TEST(s21_pow_test_pos_not_int_above_one_n_pos_inf_exp) {
    long double n = 1.23456;
    long double exp = INFINITY;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_not_int_above_one_n_pos_inf_exp) {
    long double n = -1.23456;
    long double exp = INFINITY;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(-∞, exp) returns -0 if exp is a negative odd integer
START_TEST(s21_pow_test_neg_inf_n_neg_odd_int_exp) {
    long double n = -INFINITY;
    long double exp = -21;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(-∞, exp) returns +0 if exp is a negative non-integer or negative even
//  integer
START_TEST(s21_pow_test_neg_inf_n_neg_not_int_exp) {
    long double n = -INFINITY;
    long double exp = -1.23456;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_inf_n_neg_even_int_exp) {
    long double n = -INFINITY;
    long double exp = -42;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(-∞, exp) returns -∞ if exp is a positive odd integer
START_TEST(s21_pow_test_neg_inf_n_pos_odd_int_exp) {
    long double n = -INFINITY;
    long double exp = 21;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(-∞, exp) returns +∞ if exp is a positive non-integer or positive even
//  integer
START_TEST(s21_pow_test_neg_inf_n_pos_not_int_exp) {
    long double n = -INFINITY;
    long double exp = 1.23456;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_inf_n_pos_even_int_exp) {
    long double n = -INFINITY;
    long double exp = 42;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(+∞, exponent) returns +0 for any negative exponent
START_TEST(s21_pow_test_pos_inf_n_neg_int_exp) {
    long double n = INFINITY;
    long double exp = -21;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_pos_inf_n_neg_not_int_exp) {
    long double n = INFINITY;
    long double exp = -1.23456;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  pow(+∞, exponent) returns +∞ for any positive exponent
START_TEST(s21_pow_test_pos_inf_n_pos_int_exp) {
    long double n = INFINITY;
    long double exp = 21;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_pos_inf_n_pos_not_int_exp) {
    long double n = INFINITY;
    long double exp = 1.23456;
    ck_assert_ldouble_eq(s21_pow(n, exp), pow(n, exp));
}
END_TEST

//  except where specified above, if any argument is NaN, NaN is returne
START_TEST(s21_pow_test_nan_n_nan_exp) {
    long double n = NAN;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_pos_inf_n_nan_exp) {
    long double n = INFINITY;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_inf_n_nan_exp) {
    long double n = -INFINITY;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_nan_n_pos_inf_exp) {
    long double n = NAN;
    long double exp = INFINITY;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_nan_n_neg_inf_exp) {
    long double n = NAN;
    long double exp = -INFINITY;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_nan_n_pos_one_exp) {
    long double n = NAN;
    long double exp = 1.0;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_one_n_nan_exp) {
    long double n = -1.0;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_pos_zero_n_nan_exp) {
    long double n = 0.0;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_zero_n_nan_exp) {
    long double n = -0.0;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_pos_int_n_nan_exp) {
    long double n = 21;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_pos_not_int_n_nan_exp) {
    long double n = 1.23456;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_int_n_nan_exp) {
    long double n = -21;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_neg_not_int_n_nan_exp) {
    long double n = -1.23456;
    long double exp = NAN;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_nan_n_pos_int_exp) {
    long double n = NAN;
    long double exp = 21;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_nan_n_pos_not_int_exp) {
    long double n = NAN;
    long double exp = 1.23456;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_nan_n_neg_int_exp) {
    long double n = NAN;
    long double exp = -21;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

START_TEST(s21_pow_test_nan_n_neg_not_int_exp) {
    long double n = NAN;
    long double exp = -1.23456;
    ck_assert_ldouble_nan(s21_pow(n, exp));
}
END_TEST

// usual test cases: n is finite and positive non-integer; exponent is finite
// not-integer
START_TEST(s21_pow_test_loop_1) {
    long double n = Rand_R(0, 17);
    long double exp = Rand_R(-4, 7);
    ck_assert_double_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

// usual test cases: n is finite and negative; exponent is finite and
// positive int
START_TEST(s21_pow_test_loop_2) {
    long double n = Rand_R(-2.5, -0.5);
    long double exp = 21;
    ck_assert_double_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

// usual test cases: n is finite and negative int; exponent is finite and
// negative int
START_TEST(s21_pow_test_loop_3) {
    long double n = (int)Rand_R(-7, -2) / 1;
    long double exp = (int)Rand_R(-7, -2) / 1;
    ck_assert_double_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

// usual test cases: n is finite and negative int; exponent is finite and
// positive int
START_TEST(s21_pow_test_loop_4) {
    long double n = (int)Rand_R(-7, -2) / 1;
    long double exp = (int)Rand_R(2, 10) / 1;
    ck_assert_double_eq_tol(s21_pow(n, exp), pow(n, exp), tst_EPS);
}
END_TEST

Suite *s21_pow_ste(void) {
    Suite *s = suite_create("s21_pow");
    TCase *tc = tcase_create("Core");
    tcase_add_loop_test(tc, s21_pow_test_1, 0, 1000);
    tcase_add_test(tc, s21_pow_test_2);
    tcase_add_test(tc, s21_pow_test_3);
    tcase_add_test(tc, s21_pow_test_4);
    tcase_add_test(tc, s21_pow_test_5);
    tcase_add_test(tc, s21_pow_test_pos_zero_n_neg_odd_int_exp);
    tcase_add_test(tc, s21_pow_test_pos_zero_n_pos_odd_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_zero_n_pos_odd_int_exp);
    tcase_add_test(tc, s21_pow_test_pos_zero_n_pos_even_int_exp);
    tcase_add_test(tc, s21_pow_test_pos_zero_n_pos_not_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_zero_n_pos_even_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_zero_n_pos_not_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_one_n_neg_inf_exp);
    tcase_add_test(tc, s21_pow_test_pos_one_n_pos_inf_exp);
    tcase_add_test(tc, s21_pow_test_pos_one_n_neg_inf_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_pos_zero_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_neg_zero_exp);
    tcase_add_test(tc, s21_pow_test_pos_inf_n_pos_zero_exp);
    tcase_add_test(tc, s21_pow_test_neg_not_int_n_pos_zero_exp);
    tcase_add_test(tc, s21_pow_test_pos_not_int_n_neg_zero_exp);
    tcase_add_test(tc, s21_pow_test_neg_not_int_n_neg_zero_exp);
    tcase_add_test(tc, s21_pow_test_neg_int_n_pos_not_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_int_n_neg_not_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_not_int_n_pos_not_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_not_int_n_neg_not_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_not_int_less_one_n_neg_inf_exp);
    tcase_add_test(tc, s21_pow_test_pos_not_int_above_one_n_neg_inf_exp);
    tcase_add_test(tc, s21_pow_test_pos_not_int_less_one_n_pos_inf_exp);
    tcase_add_test(tc, s21_pow_test_pos_not_int_above_one_n_pos_inf_exp);
    tcase_add_test(tc, s21_pow_test_neg_not_int_above_one_n_pos_inf_exp);
    tcase_add_test(tc, s21_pow_test_neg_inf_n_neg_odd_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_inf_n_neg_not_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_inf_n_neg_even_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_inf_n_pos_odd_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_inf_n_pos_not_int_exp);
    tcase_add_test(tc, s21_pow_test_neg_inf_n_pos_even_int_exp);
    tcase_add_test(tc, s21_pow_test_pos_inf_n_neg_int_exp);
    tcase_add_test(tc, s21_pow_test_pos_inf_n_neg_not_int_exp);
    tcase_add_test(tc, s21_pow_test_pos_inf_n_pos_int_exp);
    tcase_add_test(tc, s21_pow_test_pos_inf_n_pos_not_int_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_pos_inf_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_neg_inf_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_pos_inf_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_neg_inf_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_pos_one_exp);
    tcase_add_test(tc, s21_pow_test_neg_one_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_pos_zero_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_neg_zero_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_pos_int_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_pos_not_int_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_neg_int_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_neg_not_int_n_nan_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_pos_int_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_pos_not_int_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_neg_int_exp);
    tcase_add_test(tc, s21_pow_test_nan_n_neg_not_int_exp);
    tcase_add_loop_test(tc, s21_pow_test_loop_1, 0, 1000);
    tcase_add_loop_test(tc, s21_pow_test_loop_2, 0, 1000);
    tcase_add_loop_test(tc, s21_pow_test_loop_3, 0, 100);
    tcase_add_loop_test(tc, s21_pow_test_loop_4, 0, 200);

    suite_add_tcase(s, tc);

    return s;
}
