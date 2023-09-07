#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ExitCode = OK;
  if (s21_check_matrix(A) || s21_create_matrix(A->rows, A->columns, result)) {
    ExitCode = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < result->rows; ++i) {
      for (int j = 0; j < result->columns; ++j) {
        matrix_t minor;
        if (!s21_create_matrix(result->rows - 1, result->columns - 1, &minor)) {
          s21_get_minor(i, j, *A, &minor);
          double det_minor;
          if (!s21_determinant(&minor, &det_minor)) {
            result->matrix[i][j] = pow(-1, i + j) * det_minor;
          } else {
            ExitCode = CALCULATION_ERROR;
          }
          s21_remove_matrix(&minor);
        } else {
          ExitCode = CALCULATION_ERROR;
        }
      }
    }
  }
  return ExitCode;
}
