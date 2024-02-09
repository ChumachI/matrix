#include "../my_matrix.h"

int my_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (rows < 1 || columns < 1) {
    status = ERROR_INVALID_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = malloc(rows * sizeof(double *));
    if (result->matrix == NULL) status = ERROR_INVALID_MATRIX;

    for (int i = 0; i < rows && status == OK; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) status = ERROR_INVALID_MATRIX;
    }
  }
  return status;
}