#include <check.h>
#include <time.h>

#include "s21_matrix.h"

void random_init(matrix_t *A);

START_TEST(s21_create_test) {
  matrix_t test1, test2, test3, test4, test5;
  int test1_ret = s21_create_matrix(1, 1, &test1);
  int test2_ret = s21_create_matrix(5, 4, &test2);
  int test3_ret = s21_create_matrix(2, 10, &test3);
  int test4_ret = s21_create_matrix(-3, 4, &test4);
  int test5_ret = s21_create_matrix(4, 0, &test5);
  ck_assert_int_eq(0, test1_ret);
  ck_assert_int_eq(0, test2_ret);
  ck_assert_int_eq(0, test3_ret);
  ck_assert_int_eq(1, test4_ret);
  ck_assert_int_eq(1, test5_ret);
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
  s21_remove_matrix(&test3);
}
END_TEST

START_TEST(s21_eq_test) {
  matrix_t result, test2, test3, test4, test5, test6;
  s21_create_matrix(5, 5, &result);
  s21_create_matrix(5, 5, &test2);
  s21_create_matrix(10, 10, &test3);
  s21_create_matrix(10, 10, &test4);
  s21_create_matrix(10, 10, &test5);
  s21_create_matrix(10, 3, &test6);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      result.matrix[i][j] = 1;
    }
  }
  for (int i = 0; i < 50; i++) {
    random_init(&test2);
    ck_assert_int_eq(0, s21_eq_matrix(&result, &test2));
  }
  ck_assert_int_eq(1, s21_eq_matrix(&test3, &test4));
  ck_assert_int_eq(0, s21_eq_matrix(&test6, &test5));
  s21_remove_matrix(&result);
  s21_remove_matrix(&test2);
  s21_remove_matrix(&test3);
  s21_remove_matrix(&test4);
  s21_remove_matrix(&test5);
  s21_remove_matrix(&test6);
}
END_TEST

START_TEST(s21_sum_test) {
  matrix_t test1, test2, result;
  s21_create_matrix(4, 6, &test1);
  s21_create_matrix(4, 6, &test2);
  for (int i = 0; i < 50; i++) {
    random_init(&test1);
    random_init(&test2);
    int result_sum = s21_sum_matrix(&test1, &test2, &result);
    ck_assert_int_eq(0, result_sum);
    for (int a = 0; a < test1.rows; a++) {
      for (int b = 0; b < test1.rows; b++) {
        ck_assert_ldouble_eq_tol((test1.matrix[a][b] + test2.matrix[a][b]),
                                 result.matrix[a][b], 0.000001);
      }
    }
    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
}
END_TEST

START_TEST(s21_sub_test) {
  matrix_t test1, test2, result;
  s21_create_matrix(4, 6, &test1);
  s21_create_matrix(4, 6, &test2);
  for (int i = 0; i < 50; i++) {
    random_init(&test1);
    random_init(&test2);
    int result_sub = s21_sub_matrix(&test1, &test2, &result);
    ck_assert_int_eq(0, result_sub);
    for (int a = 0; a < test1.rows; a++) {
      for (int b = 0; b < test1.rows; b++) {
        ck_assert_ldouble_eq_tol((test1.matrix[a][b] - test2.matrix[a][b]),
                                 result.matrix[a][b], 0.000001);
      }
    }
    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&test1);
  s21_remove_matrix(&test2);
}
END_TEST

START_TEST(s21_mult_number_test) {
  matrix_t test1, result;
  s21_create_matrix(4, 6, &test1);
  for (int i = 0; i < 50; i++) {
    random_init(&test1);
    double number = (rand() % 100) + (rand() % 100 / 100.0);
    int result_mult = s21_mult_number(&test1, number, &result);
    ck_assert_int_eq(0, result_mult);
    for (int a = 0; a < test1.rows; a++) {
      for (int b = 0; b < test1.rows; b++) {
        ck_assert_ldouble_eq_tol((test1.matrix[a][b] * number),
                                 result.matrix[a][b], 0.000001);
      }
    }
    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&test1);
}
END_TEST

START_TEST(s21_inverse_test_1) {
  matrix_t test1, result, check, mult;
  s21_create_matrix(5, 5, &test1);
  s21_create_matrix(5, 5, &check);
  for (int i = 0; i < check.rows; i++) {
    check.matrix[i][i] = 1;
  }
  for (int t1 = 0; t1 < 500; t1++) {
    random_init(&test1);
    ck_assert_int_eq(0, s21_inverse_matrix(&test1, &result));
    ck_assert_int_eq(0, s21_mult_matrix(&test1, &result, &mult));
    ck_assert_int_eq(1, s21_eq_matrix(&mult, &check));
    s21_remove_matrix(&result);
    s21_remove_matrix(&mult);
  }
  s21_remove_matrix(&test1);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_inverse_test_2) {
  matrix_t test1, result;
  test1.matrix = NULL;
  s21_create_matrix(3, 3, &result);
  ck_assert_int_eq(1, s21_inverse_matrix(&test1, &result));
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_test_3) {
  matrix_t test1, result;
  s21_create_matrix(3, 2, &test1);
  s21_create_matrix(3, 3, &result);
  ck_assert_int_eq(2, s21_inverse_matrix(&test1, &result));
  s21_remove_matrix(&test1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_test) {
  matrix_t A, result;
  A.matrix = NULL;
  ck_assert_int_eq(1, s21_calc_complements(&A, &result));
}
END_TEST

void random_init(matrix_t *A) {
  srand(time(NULL));
  double first_num = 0, second_num = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      first_num = (rand() % 30 + 1);
      second_num = (rand() % 30 + 1);
      if ((i + j) % 2) {
        A->matrix[i][j] = (first_num + second_num) * (first_num - second_num);
      } else {
        A->matrix[i][j] = (first_num + second_num) * 4 / first_num;
      }
    }
  }
}

Suite *matrix_test(void) {
  Suite *s;
  TCase *tc_core;
  srand(time(NULL));
  s = suite_create("s21_matrix");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_create_test);
  tcase_add_test(tc_core, s21_eq_test);
  tcase_add_test(tc_core, s21_sum_test);
  tcase_add_test(tc_core, s21_sub_test);
  tcase_add_test(tc_core, s21_mult_number_test);
  tcase_add_test(tc_core, s21_inverse_test_1);
  tcase_add_test(tc_core, s21_inverse_test_2);
  tcase_add_test(tc_core, s21_inverse_test_3);
  tcase_add_test(tc_core, calc_complements_test);
  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;
  s = matrix_test();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_VERBOSE);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  no_failed == 0 ? printf("Success\n") : printf("fail\n");
  return 0;
}
