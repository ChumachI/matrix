#include "../_TESTS/test.h"

START_TEST(sum_1) {
  int rows = 3;
  int columns = 3;
  matrix_t A, B, C, D;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  my_create_matrix(rows, columns, &C);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = i;
      A.matrix[i][j] = i + 3;
      C.matrix[i][j] = B.matrix[i][j] + A.matrix[i][j];
    }
  }
  int status = my_sum_matrix(&A, &B, &D);
  int result = my_eq_matrix(&C, &D);
  ck_assert_int_eq(result, SUCCESS);
  ck_assert_int_eq(status, OK);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&C);
  my_remove_matrix(&D);
}
END_TEST

START_TEST(sum_2) {
  int rows = 3;
  int columns = 3;
  matrix_t A, B, D;
  int a = my_create_matrix(rows + 1, columns, &A);
  ck_assert_int_eq(a, OK);
  int b = my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(b, OK);
  int d = my_create_matrix(rows, columns, &D);
  ck_assert_int_eq(d, OK);
  int status = my_sum_matrix(&A, &B, &D);
  ck_assert_int_eq(status, ERROR_MATRIX_CALCULATION);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&D);
}
END_TEST

START_TEST(sum_3) {
  int rows = 3;
  int columns = 3;
  matrix_t A, B, C;
  int a = my_create_matrix(rows, columns, &A);
  ck_assert_int_eq(a, OK);
  int b = my_create_matrix(rows, columns, &B);
  ck_assert_int_eq(b, OK);
  int c = my_create_matrix(rows, columns, &C);
  ck_assert_int_eq(c, OK);
  A.columns = 0;
  int status = my_sum_matrix(&A, &B, &C);
  A.columns = columns;
  ck_assert_int_eq(status, ERROR_INVALID_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&C);
}
END_TEST

Suite* st_sum() {
  Suite* s = suite_create("suite_sum");
  TCase* tc = tcase_create("tc_sum");
  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  tcase_add_test(tc, sum_3);
  suite_add_tcase(s, tc);
  return s;
}