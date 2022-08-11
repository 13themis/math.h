#include "s21_math.h"

long double s21_sqrt(double x) {
    if (x == 0.0 && __builtin_signbit(x)) {
        x = S21_NAN;
    } else {
        x = x >= 0 ? s21_pow(x, 0.5) : 0.0 / 0.0;
    }
    return x;
}
