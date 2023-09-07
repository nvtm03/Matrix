#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1  //  Ошибка, некорректная матрица
#define CALCULATION_ERROR \
  2  //  Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
     //  нельзя провести вычисления и т.д.)

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);
//
//  support functions
//
//  устанавливает значение каждого элемента равным 0
void s21_default_matrix(matrix_t *A);

//  проверяет совпадают ли размеры у матриц
int s21_eq_size(matrix_t A, matrix_t B);

// проверяет матрицу на NULL, A->matrix == NULL и sizes > 0
int s21_check_matrix(matrix_t *A);

// проверяет квадратная ли матрица
int s21_is_squre_matrix(matrix_t A);

//  возвращает минор матрицы
void s21_get_minor(int row, int column, matrix_t A, matrix_t *result);

//  для подсчета определителя матрицы
double s21_get_det(matrix_t A);

#endif  //  S21_MATRIX_H_