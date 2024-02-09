#include "../_TESTS/test.h"

START_TEST(eq_1) {
  int rows = 3;
  int columns = 3;
  matrix_t A;
  my_create_matrix(rows, columns, &A);
  matrix_t B;
  my_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = i;
      A.matrix[i][j] = i;
    }
  }
  int result = my_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(eq_2) {
  int rows = 3;
  int columns = 3;
  matrix_t A;
  my_create_matrix(rows, columns + 1, &A);
  matrix_t B;
  my_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = i;
      A.matrix[i][j] = i;
    }
  }
  int result = my_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(eq_3) {
  int rows = 3;
  int columns = 3;
  matrix_t A;
  my_create_matrix(rows + 1, columns, &A);
  matrix_t B;
  my_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = i;
      A.matrix[i][j] = i;
    }
  }
  int result = my_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(eq_4) {
  int rows = 3;
  int columns = 3;
  matrix_t A, B;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = i;
      A.matrix[i][j] = i;
    }
  }
  B.matrix[0][0] += 1e-7;
  int result = my_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(eq_5) {
  int rows = 3;
  int columns = 3;
  matrix_t A, B;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = i;
      A.matrix[i][j] = i;
    }
  }
  B.matrix[0][0] += 1e-8;
  int result = my_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(eq_6) {
  int rows = 3;
  int columns = 3;
  matrix_t A, B;
  my_create_matrix(rows, columns, &A);
  my_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = i;
      A.matrix[i][j] = i;
    }
  }
  A.columns = 0;
  int result = my_eq_matrix(&A, &B);
  A.columns = columns;
  ck_assert_int_eq(result, FAILURE);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

Suite* st_eq() {
  Suite* s = suite_create("suite_eq");
  TCase* tc = tcase_create("tc_eq");
  tcase_add_test(tc, eq_1);
  tcase_add_test(tc, eq_2);
  tcase_add_test(tc, eq_3);
  tcase_add_test(tc, eq_4);
  tcase_add_test(tc, eq_5);
  tcase_add_test(tc, eq_6);
  suite_add_tcase(s, tc);
  return s;
}