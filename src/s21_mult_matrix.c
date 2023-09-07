#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ExitCode = OK;

  if (!s21_check_matrix(A) && !s21_check_matrix(B)) {
    if (A->columns == B->rows &&
        !s21_create_matrix(A->rows, B->columns, result)) {
      for (int i = 0; i < result->rows; ++i) {
        for (int j = 0; j < result->columns; ++j) {
          for (int k = 0; k < A->columns; ++k) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      ExitCode = CALCULATION_ERROR;
    }
  } else {
    ExitCode = INCORRECT_MATRIX;
  }

  return ExitCode;
}
