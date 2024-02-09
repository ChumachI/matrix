#include "../my_matrix.h"

int _is_matrix_valid(matrix_t *A) {
  int status = SUCCESS;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1)
    status = FAILURE;
  return status;
}

double _get_minor(matrix_t *A, int row, int col) {
  matrix_t *sub_matrix = _get_sub_matrix(A, row, col);
  double minor = _calculate_determinant(sub_matrix);
  my_remove_matrix(sub_matrix);
  free(sub_matrix);
  return minor;
}

double _calculate_determinant(matrix_t *A) {
  if (A->rows == 1) {
    return A->matrix[0][0];
  }
  if (A->rows == 2) {
    return A->matrix[0][0] * A->matrix[1][1] -
           A->matrix[0][1] * A->matrix[1][0];
  }
  double determinant = 0.0;
  for (int j = 0; j < A->columns; j++) {
    matrix_t *sub_matrix = _get_sub_matrix(A, 0, j);
    double minor = _calculate_determinant(sub_matrix);
    /*по первой строке*/
    determinant += pow(-1, j) * A->matrix[0][j] * minor;
    my_remove_matrix(sub_matrix);
    free(sub_matrix);
  }
  return determinant;
}

matrix_t *_get_sub_matrix(matrix_t *A, int exclude_row, int exclude_col) {
  matrix_t *sub_matrix = malloc(sizeof(matrix_t));
  my_create_matrix(A->rows - 1, A->columns - 1, sub_matrix);
  int sub_i = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == exclude_row) continue;
    int sub_j = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == exclude_col) continue;
      sub_matrix->matrix[sub_i][sub_j] = A->matrix[i][j];
      sub_j++;
    }
    sub_i++;
  }
  return sub_matrix;
}
