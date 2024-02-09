#include "../my_matrix.h"
int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (_is_matrix_valid(A) == FAILURE || _is_matrix_valid(B) == FAILURE) {
    status = ERROR_INVALID_MATRIX;
  } else if (A->columns != B->rows) {
    status = ERROR_MATRIX_CALCULATION;
  }
  if (status == OK) my_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows && status == OK; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return status;
}