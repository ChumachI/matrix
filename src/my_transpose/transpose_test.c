#include "../_TESTS/test.h"

START_TEST(transpose_1) {
  int rows = 2;
  int columns = 3;
  matrix_t A, B, C, D;
  my_create_matrix(rows, columns, &A);
  int counter = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = counter;
      counter++;
    }
  }
  my_create_matrix(columns, rows, &B);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      B.matrix[i][j] = counter;
      counter++;
    }
  }
  int result = my_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, OK);
  ck_assert_double_eq(C.matrix[0][0], 58);
  ck_assert_double_eq(C.matrix[0][1], 64);
  ck_assert_double_eq(C.matrix[1][0], 139);
  ck_assert_double_eq(C.matrix[1][1], 154);
  int res_tran = my_transpose(&C, &D);
  ck_assert_double_eq(D.matrix[0][0], 58);
  ck_assert_double_eq(D.matrix[0][1], 139);
  ck_assert_double_eq(D.matrix[1][0], 64);
  ck_assert_double_eq(D.matrix[1][1], 154);
  ck_assert_int_eq(res_tran, OK);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&C);
  my_remove_matrix(&D);
}
END_TEST

START_TEST(transpose_2) {
  int rows = 2;
  int columns = 3;
  matrix_t A, B, C, D;
  my_create_matrix(rows, columns, &A);
  int counter = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = counter;
      counter++;
    }
  }
  my_create_matrix(columns, rows, &B);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      B.matrix[i][j] = counter;
      counter++;
    }
  }
  int result = my_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, OK);
  ck_assert_double_eq(C.matrix[0][0], 58);
  ck_assert_double_eq(C.matrix[0][1], 64);
  ck_assert_double_eq(C.matrix[1][0], 139);
  ck_assert_double_eq(C.matrix[1][1], 154);
  C.columns = 0;
  int res_tran = my_transpose(&C, &D);
  C.columns = columns;
  ck_assert_int_eq(res_tran, ERROR_INVALID_MATRIX);

  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&C);
}
END_TEST

Suite* st_transpose() {
  Suite* s = suite_create("suite_transpose");
  TCase* tc = tcase_create("tc_transpose");
  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  suite_add_tcase(s, tc);
  return s;
}