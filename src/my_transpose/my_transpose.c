#include "../my_matrix.h"

int my_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (_is_matrix_valid(A) == FAILURE) {
    status = ERROR_INVALID_MATRIX;
  } else {
    my_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return status;
}