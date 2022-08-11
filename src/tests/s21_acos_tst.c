#include "s21_math_tst.h"

START_TEST(s21_acos_test_1) {
    ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), tst_EPS);
    ck_assert_ldouble_nan(s21_acos(100.0));
    ck_assert_ldouble_nan(s21_acos(-100.0));
    ck_assert_ldouble_nan(s21_acos(256.43));
    ck_assert_ldouble_nan(s21_acos(-256.43));
    ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), tst_EPS);
    ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), tst_EPS);
}
END_TEST

START_TEST(s21_acos_test_2) {
    ck_assert_ldouble_nan(s21_acos(NAN));;
    ck_assert_ldouble_nan(s21_acos(INFINITY));
}
END_TEST

START_TEST(s21_acos_test_4) {
    double n = Rand_R(-1.0, 1.0);
    if (fabs(n) > 1.0) {
        ck_assert_ldouble_nan(s21_acos(n));
        ck_assert_ldouble_nan(acos(n));
    } else {
        ck_assert_ldouble_eq_tol(s21_acos(n), acos(n), tst_EPS);
    }
}
END_TEST

START_TEST(s21_acos_test_5) {
    double n = Rand_R(-0.2, 1.0);

    if (fabs(n) > 1.0) {
        ck_assert_ldouble_nan(s21_acos(n));
        ck_assert_ldouble_nan(acos(n));
    } else {
        ck_assert_ldouble_eq_tol(s21_acos(n), acos(n), tst_EPS);
    }
}
END_TEST

START_TEST(s21_acos_test_6) {
    double n = Rand_R(-1e-6, 1e-6);

    if (fabs(n) > 1.0) {
        ck_assert_ldouble_nan(s21_acos(n));
        ck_assert_ldouble_nan(acos(n));
    } else {
        ck_assert_ldouble_eq_tol(s21_acos(n), acos(n), tst_EPS);
    }
}
END_TEST

START_TEST(s21_acos_test_7) {
    double n = Rand_R(DBL_MIN, DBL_MAX);

    if (s21_fabs(n) > 1.0) {
        ck_assert_ldouble_nan(s21_acos(n));
        ck_assert_ldouble_nan(acos(n));
    } else {
        ck_assert_ldouble_eq_tol(s21_acos(n), acos(n), tst_EPS);
    }
}
END_TEST

START_TEST(s21_acos_test_nan) {
  double n = NAN;
  ck_assert_ldouble_nan(s21_acos(n));
}
END_TEST

START_TEST(s21_acos_test_inf_plus) {
  double n = INFINITY;
  ck_assert_ldouble_nan(s21_acos(n));
}
END_TEST

START_TEST(s21_acos_test_inf_minus) {
  double n = -INFINITY;
  ck_assert_ldouble_nan(s21_acos(n));
}
END_TEST

START_TEST(s21_acos_test_above_one) {
  double x = 2.1;
  double n = -2.1;
  ck_assert_ldouble_nan(s21_acos(x));
  ck_assert_ldouble_nan(s21_acos(n));
}
END_TEST

START_TEST(s21_acos_test_plus_one) {
  double n = 1;
  ck_assert_double_eq_tol(s21_acos(n), acos(n), tst_EPS);
}
END_TEST

START_TEST(s21_acos_test_minus_one) {
  double n = -1;
  ck_assert_double_eq_tol(s21_acos(n), acos(n), tst_EPS);
}
END_TEST

START_TEST(s21_acos_test_null) {
  double n = 0.0;
  ck_assert_double_eq_tol(s21_acos(n), acos(n), tst_EPS);
}
END_TEST

START_TEST(s21_acos_test_loop) {
  double n = Rand_R(-1 + tst_EPS, 1 - tst_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(n), acos(n), tst_EPS);
}
END_TEST


Suite *s21_acos_ste(void) {
    Suite *s = suite_create("s21_acos");
    TCase *tc = tcase_create("Core");

    tcase_add_loop_test(tc, s21_acos_test_1, 0, 100);
    tcase_add_test(tc, s21_acos_test_2);
    tcase_add_loop_test(tc, s21_acos_test_4, 0, 500);
    tcase_add_loop_test(tc, s21_acos_test_5, 0, 500);
    tcase_add_loop_test(tc, s21_acos_test_6, 0, 500);
    tcase_add_loop_test(tc, s21_acos_test_7, 0, 500);
    tcase_add_test(tc, s21_acos_test_nan);
    tcase_add_test(tc, s21_acos_test_inf_plus);
    tcase_add_test(tc, s21_acos_test_inf_minus);
    tcase_add_test(tc, s21_acos_test_above_one);
    tcase_add_test(tc, s21_acos_test_plus_one);
    tcase_add_test(tc, s21_acos_test_minus_one);
    tcase_add_test(tc, s21_acos_test_null);
    tcase_add_loop_test(tc, s21_acos_test_loop, 0, 100);

    suite_add_tcase(s, tc);

    return s;
}
