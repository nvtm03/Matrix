#include "s21_matrix.h"

/**
 * @brief проверяет исходную матрицу и передает по ссылке ответ,
 * использую вспомогательную рекурентную функцию
 *
 * @param A
 * @param result
 * @return int
 */
int s21_determinant(matrix_t *A, double *result) {
  int ExitCode = OK;
  if (s21_check_matrix(A)) {
    ExitCode = INCORRECT_MATRIX;
  } else if (s21_is_squre_matrix(*A)) {
    *result = s21_get_det(*A);
  } else {
    ExitCode = CALCULATION_ERROR;
  }
  return ExitCode;
}

/**
 * @brief возвращает определитель матрицы
 *
 * @param A
 * @return double
 */
double s21_get_det(matrix_t A) {
  double result = 0.0;
  if (A.rows == 1) {
    result = A.matrix[0][0];
  } else if (A.rows == 2) {
    result = A.matrix[0][0] * A.matrix[1][1] - A.matrix[1][0] * A.matrix[0][1];
  } else {
    for (int j = 0; j < A.columns; ++j) {
      matrix_t temp;
      s21_create_matrix(A.rows - 1, A.columns - 1, &temp);
      s21_get_minor(0, j, A, &temp);
      if (j % 2) {
        result -= A.matrix[0][j] * s21_get_det(temp);
      } else {
        result += A.matrix[0][j] * s21_get_det(temp);
      }
      s21_remove_matrix(&temp);
    }
  }
  return result;
}
