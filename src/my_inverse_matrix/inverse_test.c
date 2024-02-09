#include "../_TESTS/test.h"

START_TEST(inverse_1) {
  matrix_t A, B;
  my_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int status = my_inverse_matrix(&A, &B);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(B.matrix[0][0], 1.);
  ck_assert_double_eq(B.matrix[0][1], -1.);
  ck_assert_double_eq(B.matrix[0][2], 1.);

  ck_assert_double_eq(B.matrix[1][0], -38.);
  ck_assert_double_eq(B.matrix[1][1], 41.);
  ck_assert_double_eq(B.matrix[1][2], -34.);

  ck_assert_double_eq(B.matrix[2][0], 27.);
  ck_assert_double_eq(B.matrix[2][1], -29.);
  ck_assert_double_eq(B.matrix[2][2], 24.);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t A, B;
  my_create_matrix(3, 2, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;

  int status = my_inverse_matrix(&A, &B);
  ck_assert_int_eq(status, ERROR_INVALID_MATRIX);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t A, B;
  my_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  int status = my_inverse_matrix(&A, &B);
  ck_assert_int_eq(status, ERROR_MATRIX_CALCULATION);  // det == 0
  my_remove_matrix(&A);
}
END_TEST

Suite* st_inverse() {
  Suite* s = suite_create("suite_inverse");
  TCase* tc = tcase_create("tc_inverse");
  tcase_add_test(tc, inverse_1);
  tcase_add_test(tc, inverse_2);
  tcase_add_test(tc, inverse_3);
  suite_add_tcase(s, tc);
  return s;
}
