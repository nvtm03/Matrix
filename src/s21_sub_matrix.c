#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ExitCode = OK;
  if (s21_check_matrix(A) || s21_check_matrix(B) ||
      s21_create_matrix(A->rows, A->columns, result)) {
    ExitCode = INCORRECT_MATRIX;
  } else if (s21_eq_size(*A, *B)) {
    for (int i = 0; i < result->rows; ++i) {
      for (int j = 0; j < result->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    ExitCode = CALCULATION_ERROR;
  }
  return ExitCode;
}
