#include "../my_matrix.h"

int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (_is_matrix_valid(A) == FAILURE || _is_matrix_valid(B) == FAILURE) {
    status = ERROR_INVALID_MATRIX;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    status = ERROR_MATRIX_CALCULATION;
  }
  if (status == OK) my_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows && status == OK; i++) {
    for (int j = 0; j < A->columns; j++) {
      double sum = A->matrix[i][j] + B->matrix[i][j];
      result->matrix[i][j] = sum;
    }
  }
  return status;
}