#include "s21_math.h"
#include <math.h>

long double s21_atan(double x) {
    long double res = 0;
    if (s21_fabs(x) == 0) {
        res = x;
    } else if (__builtin_isnan(x)) {
        res = S21_NAN;
    } else if (!__builtin_isfinite(x) && !__builtin_signbit(x)) {
        res = S21_M_PI / 2;
    } else if (!__builtin_isfinite(x) && __builtin_signbit(x)) {
        res = -S21_M_PI / 2;
    } else if (s21_fabs(x) < 1) {
        long double element = 1 * s21_pow(x, 1 + 2 * 0) / (1 + 2 * 0);
        for (int i = 1; s21_fabs(element) > _EPS; ++i) {
            res += element;
            element = s21_pow(-1, i) * s21_pow(x, 1 + 2 * i) / (1 + 2 * i);
        }
    } else if (s21_fabs(x) > 1) {
        res = (S21_M_PI * s21_fabs(x)) / (2 * x);
        long double element = 1 * s21_pow(x, -2 * 0 - 1) / (2 * 0 + 1);
        for (int i = 1; s21_fabs(element) > _EPS; ++i) {
            res -= element;
            element = s21_pow(-1, i) * s21_pow(x, -2 * i - 1) / (2 * i + 1);
        }
    } else if (x == 1) {
        res = S21_M_PI / 4;
    } else {
        res = -S21_M_PI / 4;
    }
    return res;
}
