#include "s21_math.h"

long double s21_asin(double x) {
    long double res = 0;
    if (__builtin_isnan(x)) {
        res = S21_NAN;
    } else if (s21_fabs(x) < 1) {
        res = s21_atan(x / s21_sqrt(1 - x * x));;
    } else if (x == 1) {
        res = S21_M_PI / 2;
    } else if (x == -1) {
        res = -S21_M_PI / 2;
    } else {
        res = S21_NAN;
    }
    return res;
}
