#include "s21_math.h"

long long s21_fuck_torial(int n) {
    long long x = 1;
    for (int i = 1; i <= n; ++i) {
        x *= i;
    }
    return x;
}
