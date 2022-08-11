#include "s21_math_tst.h"

START_TEST(s21_abs_test_1) {
    ck_assert_int_eq(s21_abs(0), abs(0));
    ck_assert_int_eq(s21_abs(-1), abs(-1));
}
END_TEST

START_TEST(s21_abs_test_3) {
  int n = 0;
  ck_assert_int_eq(s21_abs(n), abs(n));
}
END_TEST

START_TEST(s21_abs_test_4) {
  int n = -1234;
  ck_assert_int_eq(abs(n), s21_abs(n));
}
END_TEST

START_TEST(s21_abs_test_5) {
  int n = -2147483648;
  ck_assert_int_eq(abs(n), s21_abs(n));
}
END_TEST

START_TEST(s21_abs_test_6) {
  int n = 1234;
  ck_assert_int_eq(abs(n), s21_abs(n));
}
END_TEST

START_TEST(s21_abs_test_7) {
  int n = 2147483647;
  ck_assert_int_eq(abs(n), s21_abs(n));
}
END_TEST

Suite *s21_abs_ste(void) {
    Suite *s = suite_create("s21_abs");
    TCase *tc = tcase_create("Core");
    tcase_add_test(tc, s21_abs_test_1);
    tcase_add_test(tc, s21_abs_test_3);
    tcase_add_test(tc, s21_abs_test_4);
    tcase_add_test(tc, s21_abs_test_5);
    tcase_add_test(tc, s21_abs_test_6);
    tcase_add_test(tc, s21_abs_test_7);
    suite_add_tcase(s, tc);

    return s;
}
