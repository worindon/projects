#pragma once
#include "matrix.h"


void matrix_input(Matrix& matrix);

void matrix_print(Matrix& matrix);

//void matrix_triangl_print(Matrix& matrix);

void matrix_print(vector<vector<double>> matrix);

bool matrix_gausse_method(Matrix& matrix);

void print_folder(int rows, int cols);

void print_two_matrix_non_multiplication(Matrix &A, Matrix &B, const char ch, const char chr);

void print_two_matrix_InColumn(Matrix A, Matrix B, const char ch, const char chr);