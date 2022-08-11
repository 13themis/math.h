#include "s21_math.h"
#include <math.h>

long double s21_sin(double x) {
    long double sum_raz = 0;

    if (x == +0 || x == -0) {
        sum_raz = x;
    } else if (x == +S21_INF || x == -S21_INF || __builtin_isnan(x)) {
        sum_raz = S21_NAN;
    } else {
        x = s21_fmod(x, 2 * S21_M_PI);
        long double element = x;
        for (int i = 1; s21_fabs(element * 3) > _EPS; ++i) {
            sum_raz += element;
            element *= -x * x / ((2 * i) * (2 * i + 1));
        }
    }
    return sum_raz;
}


