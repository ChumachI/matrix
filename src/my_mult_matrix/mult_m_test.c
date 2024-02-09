#include "../_TESTS/test.h"

START_TEST(mult_m_1) {
  int rows = 2;
  int columns = 3;
  matrix_t A, B, C;
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
  my_remove_matrix(&A);
  my_remove_matrix(&B);
  my_remove_matrix(&C);
}
END_TEST

START_TEST(mult_m_2) {
  int rowsA = 2;
  int columnsA = 3;
  int rowsB = 2;
  int columnsB = 3;
  matrix_t A, B, C;
  my_create_matrix(rowsA, columnsA, &A);
  int counter = 1;
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = counter;
      counter++;
    }
  }
  my_create_matrix(rowsB, columnsB, &B);
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = counter;
      counter++;
    }
  }
  int result = my_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, ERROR_MATRIX_CALCULATION);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(mult_m_3) {
  int rowsA = 2;
  int columnsA = 3;
  int rowsB = 2;
  int columnsB = 3;
  matrix_t A, B, C;
  my_create_matrix(rowsA, columnsA, &A);
  int counter = 1;
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = counter;
      counter++;
    }
  }
  my_create_matrix(rowsB, columnsB, &B);
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = counter;
      counter++;
    }
  }
  A.rows = 0;
  int result = my_mult_matrix(&A, &B, &C);
  A.rows = rowsA;
  ck_assert_int_eq(result, ERROR_INVALID_MATRIX);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

Suite* st_mult_m() {
  Suite* s = suite_create("suite_mult_m");
  TCase* tc = tcase_create("tc_mult_m");
  tcase_add_test(tc, mult_m_1);
  tcase_add_test(tc, mult_m_2);
  tcase_add_test(tc, mult_m_3);
  suite_add_tcase(s, tc);
  return s;
}