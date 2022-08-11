#include "s21_math.h"

long double s21_tan(double x) {
    long double res = 0;
    if (x == +0 || x == -0) {
        res = x;
    } else if (!__builtin_isfinite(x) || __builtin_isnan(x)) {
        res = S21_NAN;
    } else {
        x = s21_fmod(x, 2 * S21_M_PI);
        if ((s21_fabs(x) == S21_M_PI / 2) || (s21_fabs(x) == (3 * S21_M_PI) / 2)) {
            res = S21_NAN;
        } else {
        res = s21_sin(x) / s21_cos(x);
        }
    }
    return res;
}
