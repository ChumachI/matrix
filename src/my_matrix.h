#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <math.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

#define OK 0
#define ERROR_INVALID_MATRIX 1
#define ERROR_MATRIX_CALCULATION 2

#define SUCCESS 1
#define FAILURE 0


/*Создание матриц*/
int my_create_matrix(int rows, int columns, matrix_t *result);

/*Удалить матрицу*/
void my_remove_matrix(matrix_t *A);

/*Сравнение матриц*/
int my_eq_matrix(matrix_t *A, matrix_t *B);

/*Сложение матриц*/
int my_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/*Вычитание матриц*/
int my_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/*Умножение матрицы на число*/
int my_mult_number(matrix_t *A, double number, matrix_t *result);

/*Умножение двух матриц*/
int my_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/*Транспонирование матрицы*/
int my_transpose(matrix_t *A, matrix_t *result);

/*Минор матрицы*/
int my_calc_complements(matrix_t *A, matrix_t *result);

/*Определитель матрицы*/
int my_determinant(matrix_t *A, double *result);

/*Обратная матрица*/
int my_inverse_matrix(matrix_t *A, matrix_t *result);

/*HELPERS*/

/*Проверка матрицы на валидность*/
int _is_matrix_valid(matrix_t * A);

/*Высчитывает детерминант*/
double _calculate_determinant(matrix_t *A);

/*Возвращает подматрицу*/
matrix_t *_get_sub_matrix(matrix_t *A, int exclude_row, int exclude_col);

/*Возвращает минор матрицы*/
double _get_minor(matrix_t *A, int row, int col);
#endif