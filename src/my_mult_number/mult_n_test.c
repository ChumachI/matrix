#include "../_TESTS/test.h"

START_TEST(mul_num_1) {
  int rows = 3;
  int columns = 3;
  matrix_t A, B, C;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  my_create_matrix(rows, columns, &C);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i;
      C.matrix[i][j] = A.matrix[i][j] * 3;
    }
  }
  int status = my_mult_number(&A, 3, &B);
  int result = my_eq_matrix(&B, &C);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_int_eq(status, OK);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&C);
}
END_TEST

START_TEST(mul_num_2) {
  int rows = 3;
  int columns = 3;
  matrix_t A, B, C;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  my_create_matrix(rows, columns, &C);
  A.columns = 0;
  int status = my_mult_number(&A, 3, &B);
  A.columns = columns;
  int result = my_eq_matrix(&B, &C);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_int_eq(status, ERROR_INVALID_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&C);
}
END_TEST

Suite* st_mul_num() {
  Suite* s = suite_create("suite_mul_num");
  TCase* tc = tcase_create("tc_mul_num");
  tcase_add_test(tc, mul_num_1);
  tcase_add_test(tc, mul_num_2);
  suite_add_tcase(s, tc);
  return s;
}