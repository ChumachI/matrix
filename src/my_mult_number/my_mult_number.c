#include "../my_matrix.h"

int my_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;
  if (_is_matrix_valid(A) == FAILURE) {
    status = ERROR_INVALID_MATRIX;
  }
  if(status == OK) my_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows && status == OK; i++) {
    for (int j = 0; j < A->columns; j++) {
      double mul = A->matrix[i][j] * number;
      result->matrix[i][j] = mul;
    }
  }
  return status;
}