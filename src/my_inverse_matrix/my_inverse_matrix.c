#include "../my_matrix.h"

int my_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  double determinant;
  matrix_t complement, transposed;
  if (A == NULL || result == NULL || A->rows != A->columns) {
    status = ERROR_INVALID_MATRIX;
  }
  if (status == OK &&
      (my_determinant(A, &determinant) != OK || determinant == 0.0)) {
    status = ERROR_MATRIX_CALCULATION;
  }
  if (status == OK) {
    status = my_calc_complements(A, &complement);
  }
  if (status == OK) {
    status = my_transpose(&complement, &transposed);
  }
  if (status == OK) {
    for (int i = 0; i < transposed.rows; i++) {
      for (int j = 0; j < transposed.columns; j++) {
        transposed.matrix[i][j] *= 1 / determinant;
      }
    }
    my_create_matrix(transposed.rows, transposed.columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->rows; j++) {
        result->matrix[i][j] = transposed.matrix[i][j];
      }
    }
    my_remove_matrix(&complement);
    my_remove_matrix(&transposed);
  }
  return status;
}