#include "../_TESTS/test.h"

START_TEST(determinant_1) {
  matrix_t A;
  my_create_matrix(2, 2, &A);
  double det;
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 1;
  int status = my_determinant(&A, &det);
  ck_assert_double_eq(det, -10);
  ck_assert_int_eq(status, OK);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A;
  my_create_matrix(3, 3, &A);
  double det;
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  int status = my_determinant(&A, &det);
  ck_assert_double_eq(det, 0);
  ck_assert_int_eq(status, OK);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A;
  my_create_matrix(3, 3, &A);
  double det;
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 1;

  A.matrix[1][0] = 1;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = -1;

  A.matrix[2][0] = -1;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 5;
  int status = my_determinant(&A, &det);
  ck_assert_double_eq(det, 45);
  ck_assert_int_eq(status, OK);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t A;
  my_create_matrix(4, 4, &A);
  double det;
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 3;

  A.matrix[1][0] = 1;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = -1;
  A.matrix[1][3] = 2;

  A.matrix[2][0] = -1;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 5;
  A.matrix[2][3] = 0;

  A.matrix[3][0] = 3;
  A.matrix[3][1] = -2;
  A.matrix[3][2] = 4;
  A.matrix[3][3] = 1;
  int status = my_determinant(&A, &det);
  ck_assert_double_eq(det, -150);
  ck_assert_int_eq(status, OK);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A;
  my_create_matrix(4, 4, &A);
  double det;
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 3;

  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 2;

  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 1;
  int status = my_determinant(&A, &det);
  ck_assert_double_eq(det, 1);
  ck_assert_int_eq(status, OK);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_6) {
  matrix_t A;
  my_create_matrix(4, 3, &A);
  double det;
  int status = my_determinant(&A, &det);
  ck_assert_int_eq(status, ERROR_MATRIX_CALCULATION);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_7) {
  matrix_t A;
  my_create_matrix(3, 3, &A);
  A.columns = 0;
  double det;
  int status = my_determinant(&A, &det);
  A.columns = 3;
  ck_assert_int_eq(status, ERROR_INVALID_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_8) {
  matrix_t A;
  my_create_matrix(1, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;

  double det;
  int status = my_determinant(&A, &det);
  ck_assert_int_eq(status, ERROR_MATRIX_CALCULATION);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_9) {
  matrix_t A;
  my_create_matrix(1, 1, &A);
  double det;
  int status = my_determinant(&A, &det);
  ck_assert_int_eq(status, OK);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_10) {
  matrix_t A;
  my_create_matrix(1, 2, &A);
  double det;
  int status = my_determinant(&A, &det);
  ck_assert_int_eq(status, ERROR_MATRIX_CALCULATION);
  my_remove_matrix(&A);
}
END_TEST

Suite* st_determinant() {
  Suite* st = suite_create("suite_determinant");
  TCase* tc = tcase_create("tc_determinant");
  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);
  tcase_add_test(tc, determinant_6);
  tcase_add_test(tc, determinant_7);
  tcase_add_test(tc, determinant_8);
  tcase_add_test(tc, determinant_9);
  tcase_add_test(tc, determinant_10);

  suite_add_tcase(st, tc);
  return st;
}