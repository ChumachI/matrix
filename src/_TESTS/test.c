#include "test.h"

int main() {
  int number_failed;
  Suite *crt, *rmv, *eq, *sum, *sub, *mul_n, *mul_m, *tran, *det, *calc_c,
      *invrs;
  crt = st_create();
  rmv = st_remove();
  eq = st_eq();
  sum = st_sum();
  sub = st_sub();
  mul_n = st_mul_num();
  mul_m = st_mult_m();
  tran = st_transpose();
  det = st_determinant();
  calc_c = st_calc_c();
  invrs = st_inverse();
  SRunner *sr = srunner_create(crt);
  srunner_add_suite(sr, rmv);
  srunner_add_suite(sr, eq);
  srunner_add_suite(sr, sum);
  srunner_add_suite(sr, sub);
  srunner_add_suite(sr, mul_n);
  srunner_add_suite(sr, mul_m);
  srunner_add_suite(sr, tran);
  srunner_add_suite(sr, det);
  srunner_add_suite(sr, calc_c);
  srunner_add_suite(sr, invrs);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed == 0 ? 0 : 1;
}