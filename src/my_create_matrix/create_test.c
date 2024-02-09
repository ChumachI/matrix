#include "../_TESTS/test.h"

START_TEST(create_1) {
  int rows = 3;
  int columns = 3;
  matrix_t result;
  int status = my_create_matrix(rows, columns, &result);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(status, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  }
  my_remove_matrix(&result);
}
END_TEST

START_TEST(create_2) {
  int rows = 8;
  int columns = 3;
  matrix_t result;
  int status = my_create_matrix(rows, columns, &result);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_int_eq(result.rows, 8);
  ck_assert_int_eq(status, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  }
  my_remove_matrix(&result);
}
END_TEST

START_TEST(create_3) {
  int rows = 3;
  int columns = 8;
  matrix_t result;
  int status = my_create_matrix(rows, columns, &result);
  ck_assert_int_eq(result.columns, 8);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(status, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  }
  my_remove_matrix(&result);
}
END_TEST

START_TEST(create_4) {
  int rows = 0;
  int columns = 8;
  matrix_t result;
  int status = my_create_matrix(rows, columns, &result);
  ck_assert_int_eq(status, ERROR_INVALID_MATRIX);
}
END_TEST

Suite* st_create() {
  Suite* s = suite_create("suite_create");
  TCase* tc = tcase_create("tc_create");
  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, create_4);
  suite_add_tcase(s, tc);
  return s;
}