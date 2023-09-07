#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ExitCode = OK;
  if (s21_check_matrix(A)) {
    ExitCode = INCORRECT_MATRIX;
  } else {
    double det_A;
    if (s21_determinant(A, &det_A)) {
      ExitCode = CALCULATION_ERROR;
    } else {
      matrix_t M;
      matrix_t M_transpose;
      if (s21_calc_complements(A, &M) || s21_transpose(&M, &M_transpose)) {
        ExitCode = CALCULATION_ERROR;
      } else {
        if (s21_mult_number(&M_transpose, 1.0 / det_A, result)) {
          ExitCode = CALCULATION_ERROR;
        }
      }
      s21_remove_matrix(&M_transpose);
      s21_remove_matrix(&M);
    }
  }
  return ExitCode;
}
