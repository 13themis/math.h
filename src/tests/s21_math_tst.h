#ifndef SRC_TESTS_S21_MATH_TST_H_
#define SRC_TESTS_S21_MATH_TST_H_
#include <math.h>
#include <stdlib.h>
#include <check.h>
#include <errno.h>
#include <time.h>
#include "../s21_math.h"

#define tst_EPS (10e-6)
#define S21_M_PI 3.14159265358979323846264338327950288

Suite *s21_abs_ste(void);
Suite *s21_acos_ste(void);
Suite *s21_asin_ste(void);
Suite *s21_atan_ste(void);
Suite *s21_ceil_ste(void);
Suite *s21_cos_ste(void);
Suite *s21_exp_ste(void);
Suite *s21_fabs_ste(void);
Suite *s21_floor_ste(void);
Suite *s21_fmod_ste(void);
Suite *s21_pow_ste(void);
Suite *s21_sin_ste(void);
Suite *s21_log_ste(void);
Suite *s21_sqrt_ste(void);
Suite *s21_tan_ste(void);

void run_tests(void);
void run_testcase(Suite *tc);

double Rand_R(double low, double high);
#endif  // SRC_TESTS_S21_MATH_TST_H_
