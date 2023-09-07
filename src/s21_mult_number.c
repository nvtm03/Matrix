#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ExitCode = OK;
  if (s21_check_matrix(A) || s21_create_matrix(A->rows, A->columns, result)) {
    ExitCode = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < result->rows; ++i) {
      for (int j = 0; j < result->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return ExitCode;
}
