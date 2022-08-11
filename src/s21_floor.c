#include "s21_math.h"

long double s21_floor(double x) {
    if (!__builtin_isfinite(x)) {
        x = x;
    } else if (x == 0.0) {
        x = x;
    } else if (x == S21_NAN) {
        x = S21_NAN;
    } else if (x < 0 && (x - (long long int)x != 0)) {
        x = (long long int)x - 1;
    } else {
        x = (long long int) x;
    }
    return x;
}
