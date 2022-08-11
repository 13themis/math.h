#include "s21_math.h"

long double s21_exp(double x) {
    long double sum = 1.0;
    long double fuck_torial = 1;
    long double pow_x = s21_fabs(x);
    int sign = x >= 0 ? 1 : 0;

    if (x == 0) {
        sum = 1;
    } else if (__builtin_isnan(x)) {
        sum = S21_NAN;
    } else if (x == -S21_INF) {
        sum = 0;
    } else if (x == S21_INF) {
        sum = S21_INF;
    } else {
        x = s21_fabs(x);
        for (int i = 1; i < 1000; ++i) {
            fuck_torial *= i;
            sum += pow_x / fuck_torial;
            pow_x *= x;
        }
        sum = sign ? sum : 1 / sum;
    }
    return sum;
}
