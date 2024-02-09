#include "../my_matrix.h"

int my_determinant(matrix_t *A, double *result) {
  int status = 0;
  if (_is_matrix_valid(A) == FAILURE) {
    status = ERROR_INVALID_MATRIX;
  } else if (A->rows != A->columns) {
    status = ERROR_MATRIX_CALCULATION;
  } else {
    *result = _calculate_determinant(A);
  }
  return status;
}