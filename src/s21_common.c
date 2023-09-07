#include "s21_matrix.h"

/**
 * @brief задает стандартную матрицу( все нули)
 *
 * @param A
 */
void s21_default_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      A->matrix[i][j] = 0;
    }
  }
}

// 0 - всё хорошо  1 - есть ошибки
int s21_check_matrix(matrix_t *A) {
  int ExitCode = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    ExitCode = 1;
  }
  return ExitCode;
}

/**
 * проверяет совпадают ли размеры у матриц
 * @param A
 * @param B
 * @return 1 - совпадают  0 - не совпадают
 */
int s21_eq_size(matrix_t A, matrix_t B) {
  return A.rows == B.rows && A.columns == B.columns;
}

/**
 * @brief проверяет квадратная ли матрица
 *
 * @param A
 * @return int
 */
int s21_is_squre_matrix(matrix_t A) {
  int ExitCode = 0;
  if (A.rows == A.columns) {
    ExitCode = 1;
  }
  return ExitCode;
}

/**
 * @brief возвращает минор матрицы
 *
 * @param row
 * @param column
 * @param A
 * @param result
 * @return ** void
 */
void s21_get_minor(int row, int column, matrix_t A, matrix_t *result) {
  int result_row = 0;
  int result_column = 0;

  for (int i = 0; i < A.rows; ++i) {
    if (i != row) {
      result_column = 0;
      for (int j = 0; j < A.columns; ++j) {
        if (j != column) {
          result->matrix[result_row][result_column] = A.matrix[i][j];
          ++result_column;
        }
      }
      ++result_row;
    }
  }
}
