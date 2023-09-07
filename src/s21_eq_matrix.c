#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ExitCode = SUCCESS;
  if (!s21_check_matrix(A) && !s21_check_matrix(B) && s21_eq_size(*A, *B)) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 0.0000001) {
          ExitCode = FAILURE;
          // break;
        }
      }
    }
  } else {
    ExitCode = FAILURE;
  }
  return ExitCode;
}
