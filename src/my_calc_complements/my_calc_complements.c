#include "../my_matrix.h"

int my_calc_complements(matrix_t *A, matrix_t *result) {
  if (A->rows != A->columns) return 2;
  my_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double minor = _get_minor(A, i, j);
      result->matrix[i][j] = pow(-1, i + j) * minor;
    }
  }
  return 0;
}