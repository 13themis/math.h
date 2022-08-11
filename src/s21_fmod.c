#include "s21_math.h"

long double s21_fmod(double x, double y) {
    if (!__builtin_isfinite(y) && __builtin_isfinite(x)) {
        x = x;
    } else if (!__builtin_isfinite(x) || !__builtin_isfinite(y) ||
        x == S21_NAN || __builtin_isnan(y)) {
        x = S21_NAN;
    } else if (y == 0) {
        x = S21_NAN;
    } else {
        x = x - (long long int)(x / y) * y;
    }
    return x;
}

