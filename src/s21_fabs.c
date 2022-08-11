#include "s21_math.h"

long double s21_fabs(double x) {
    long double res = 0;
    if (x == S21_NAN) {
        res = x;
    } else {
        res = x >= 0 ? x : -x;
    }
    return res;
}
