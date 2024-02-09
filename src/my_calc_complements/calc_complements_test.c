#include "../_TESTS/test.h"

START_TEST(calc_c_1) {
  matrix_t A, B;
  my_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  int status = my_calc_complements(&A, &B);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(B.matrix[0][0], 0);
  ck_assert_int_eq(B.matrix[0][1], 10);
  ck_assert_int_eq(B.matrix[0][2], -20);

  ck_assert_int_eq(B.matrix[1][0], 4);
  ck_assert_int_eq(B.matrix[1][1], -14);
  ck_assert_int_eq(B.matrix[1][2], 8);

  ck_assert_int_eq(B.matrix[2][0], -8);
  ck_assert_int_eq(B.matrix[2][1], -2);
  ck_assert_int_eq(B.matrix[2][2], 4);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

START_TEST(calc_c_2) {
  matrix_t A, B;
  my_create_matrix(3, 2, &A);
  int status = my_calc_complements(&A, &B);
  ck_assert_int_eq(status, ERROR_MATRIX_CALCULATION);
  my_remove_matrix(&A);
}
END_TEST

START_TEST(calc_c_3) {
  matrix_t A, B;
  my_create_matrix(4, 4, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 3;

  A.matrix[1][0] = 1;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = -1;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = 2;

  A.matrix[3][0] = 0;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 1;
  A.matrix[3][3] = -2;
  int status = my_calc_complements(&A, &B);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(B.matrix[0][0], 15);
  ck_assert_int_eq(B.matrix[0][1], -7);
  ck_assert_int_eq(B.matrix[0][2], -17);

  ck_assert_int_eq(B.matrix[1][0], -11);
  ck_assert_int_eq(B.matrix[1][1], 11);
  ck_assert_int_eq(B.matrix[1][2], -11);

  ck_assert_int_eq(B.matrix[2][0], -21);
  ck_assert_int_eq(B.matrix[2][1], 1);
  ck_assert_int_eq(B.matrix[2][2], 15);
  my_remove_matrix(&A);
  my_remove_matrix(&B);
}
END_TEST

Suite* st_calc_c() {
  Suite* s = suite_create("suite_calc_c");
  TCase* tc = tcase_create("tc_calc_c");
  tcase_add_test(tc, calc_c_1);
  tcase_add_test(tc, calc_c_2);
  tcase_add_test(tc, calc_c_3);

  suite_add_tcase(s, tc);
  return s;
}

