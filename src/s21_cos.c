#include "s21_math.h"

long double s21_cos(double x) {
    long double sum_raz = 0.0;

    if (s21_fabs(x) < _EPS) {
        sum_raz = 1.0;
    } else  if (__builtin_isnan(x)) {
        sum_raz = S21_NAN;
    } else if (!__builtin_isfinite(x)) {
        sum_raz = S21_NAN;
    } else {
        x = s21_fmod(x, 2 * S21_M_PI);
        long double element = 1;
        for (int i = 1; s21_fabs(element * 3) > _EPS; ++i) {
            sum_raz += element;
            element *= -x * x / (2 * i * (2 * i - 1));
        }
    }
    return sum_raz;
}
