#ifndef TEST_H
#define TEST_H
#include <check.h>
#include <stdlib.h>

#include "../my_matrix.h"
Suite* st_create();
Suite* st_remove();
Suite* st_eq();
Suite* st_sum();
Suite* st_sub();
Suite* st_mul_num();
Suite* st_mult_m();
Suite* st_transpose();
Suite* st_determinant();
Suite* st_calc_c();
Suite* st_inverse();
#endif