#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int ExitCode = OK;
  if (result != NULL) {
    if (rows > 0 && columns > 0) {
      result->rows = rows;
      result->columns = columns;
      result->matrix = malloc(rows * sizeof(double *));
      if (result->matrix != NULL) {
        for (int i = 0; i < rows; ++i) {
          result->matrix[i] = malloc(columns * sizeof(double));
        }
        s21_default_matrix(result);
      }
    } else {
      ExitCode = INCORRECT_MATRIX;
    }
  }
  return ExitCode;
}
