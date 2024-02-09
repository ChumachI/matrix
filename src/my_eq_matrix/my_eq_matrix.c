#include "../my_matrix.h"

int my_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if (_is_matrix_valid(A) == FAILURE || _is_matrix_valid(B) == FAILURE) {
    status = FAILURE;
  }
  if (A->columns != B->columns || A->rows != B->rows) {
    status = FAILURE;
  }

  for (int i = 0; i < A->rows && status == SUCCESS; i++) {
    for (int j = 0; j < A->columns && status == SUCCESS; j++) {
      double substraction = A->matrix[i][j] - B->matrix[i][j];
      if (fabs(substraction) >= 1e-7) {
        status = FAILURE;
      }
    }
  }
  return status;
}