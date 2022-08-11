#include "s21_math.h"
#define EPS 10e-8
long double s21_pow(double base, double exp) {
    long double result_value  = 0;
    if ((__builtin_isfinite(base) && base < 0 && __builtin_isfinite(exp) &&
              (int)exp != exp)) {
        result_value = S21_NAN;
    } else if ((base == +0 || base == -0) && (exp == -S21_INF)) {
        result_value = +S21_INF;
    } else if ((base == +0) && (!s21_fmod(exp, 2)) && (exp < 0)
    && ((exp - (long long int)exp) == 0)) {
        result_value = +S21_INF;
    } else if ((base == -0) && (!s21_fmod(exp, 2)) && (exp < 0)
    && ((exp - (long long int)exp) == 0)) {
        result_value = -S21_INF;
    } else if (base == +0 && exp > 0 && s21_fmod(exp, 2)
    && ((exp - (long long int)exp) == 0)) {
        result_value = +0;
    } else if (base == -0 && exp > 0 && s21_fmod(exp, 2)
    && ((exp - (long long int)exp) == 0)) {
        result_value = -0;
    } else if ((base == +0 || base == -0) && exp > 0
    && ((exp - (long long int)exp) || (((exp - (long long int)exp) == 0)
    && (long long int)exp % 2 == 0))) {
        result_value = +0;
    } else if (base == -1 && (exp == +S21_INF || exp == -S21_INF)) {
        result_value = 1;
    } else if (base == +1) {
        result_value = 1;
    } else if (exp == +0 || exp == -0) {
        result_value = 1;
    } else if (exp == -S21_INF && s21_fabs(base) < 1) {
        result_value = +S21_INF;
    } else if (exp == -S21_INF && s21_fabs(base) > 1) {
        result_value = +0;
    } else if (exp == +S21_INF && s21_fabs(base) < 1) {
        result_value = +0;
    } else if (exp == +S21_INF && s21_fabs(base) > 1) {
        result_value = +S21_INF;
    } else if (base == -S21_INF && exp < 0
    && (exp - (long long int)exp) == 0 && s21_fmod(exp, 2)) {
        result_value = -0;
    } else if (base == -S21_INF && exp < 0
    && (exp - (long long int)exp) && s21_fmod(exp, 2) == 0) {
        result_value = +0;
    } else if ((base == -S21_INF && exp > 0
    && (exp - (long long int)exp) == 0 && s21_fmod(exp, 2))) {
        result_value = -S21_INF;
    } else if (base == -S21_INF && exp > 0
    && ((exp - (long long int)exp) || ((exp - (long long int)exp == 0 && s21_fmod(exp, 2) == 0)))) {
        result_value = +S21_INF;
    } else if (base == +S21_INF && exp < 0) {
        result_value = +0;
    } else if (base == +S21_INF && exp > 0) {
        result_value = +S21_INF;
    } else if (__builtin_isnan(base)|| __builtin_isnan(exp)) {
        result_value = S21_NAN;
    } else if (base >= 0) {
        if (exp < 0) {
            result_value =  1 / s21_exp(-exp * s21_log(base));
        } else {
            result_value = s21_exp(exp * s21_log(base));
        }
    } else if (base <= 0) {
        if ((long long int)(exp / exp) < 0) {
            result_value = 0.0/0.0;
        } else if (exp < 0) {
            result_value =  1 / s21_exp(-exp * s21_log(-base));
            int minus = (long long int) -exp % 2 ? -1 : 1;
            result_value *= minus;
        } else {
            result_value = s21_exp(exp * s21_log(-base));
            int minus = (long long int) exp % 2 ? -1 : 1;
            result_value *= minus;
        }
    } else {
        result_value = 0.0 / 0.0;
    }
    return result_value;
}
