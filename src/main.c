#include "./tests/s21_math_tst.h"

int main(void) {
    srand(time(NULL));
    run_tests();
    return 0;
}

void run_testcase(Suite *testcase) {
    static int counter_testcase = 1;
    if (counter_testcase > 1) counter_testcase++;
    SRunner *sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {
      s21_abs_ste(),  s21_acos_ste(), s21_asin_ste(), s21_atan_ste(),
      s21_cos_ste(),  s21_fabs_ste(), s21_exp_ste(), s21_ceil_ste(),
      s21_fmod_ste(), s21_floor_ste(), s21_log_ste(), s21_pow_ste(),
      s21_sin_ste(),  s21_sqrt_ste(), s21_tan_ste(), NULL,
  };

  for (Suite **current_testcase = list_cases; *current_testcase;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

double Rand_R(double a, double b) {
    double m = (double)rand() / RAND_MAX;
    double num = a + m * (b - a);
    return num;
}
