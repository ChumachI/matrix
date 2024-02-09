#include "../_TESTS/test.h"

START_TEST(remove_1) {
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
  ck_assert_int_eq(result.columns, 0);
  ck_assert_int_eq(result.rows, 0);
  ck_assert_ptr_null(result.matrix);
}
END_TEST

Suite* st_remove() {
  Suite* s = suite_create("suite_remove");
  TCase* tc = tcase_create("tc_remove");
  tcase_add_test(tc, remove_1);
  suite_add_tcase(s, tc);
  return s;
}