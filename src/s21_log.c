#include "s21_math.h"


long double s21_log(double x) {
    const long double log_2 = 0.693147180559945309417232121458;
    long double p = x;
    long int k = 0;
    long double sum = 0;
    long double res = 0;
    int pow_1 = 1;
    long double pow_p = 0;

    if (x == 0) {
        res = -S21_INF;
    } else if (x == 1) {
        res = +0;
    } else if (x < 0 || __builtin_isnan(x)) {
        res = S21_NAN;
    } else if (!__builtin_finite(x)) {
        res = S21_INF;
    } else {
        for (; p >= 2; ++k) {
            p /= 2;
        }
        res = k * log_2;
        pow_p = p - 1;
        for (int i = 1; i < 45000; ++i) {
            sum += pow_1 * pow_p / i;
            pow_p *= p - 1;
            pow_1 *= -1;
        }
        res += sum;
    }

    return res;
}
