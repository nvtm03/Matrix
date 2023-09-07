#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (!s21_check_matrix(A)) {
    for (int i = 0; i < A->rows; ++i) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    if (A->matrix != NULL) {
      free(A->matrix);
    }
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}
