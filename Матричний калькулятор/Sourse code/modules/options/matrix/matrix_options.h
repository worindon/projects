#pragma once
#include <conio.h>
#include <iomanip> // Для управления выводом формата
#include "../../matrix/matrix.h"
//therefore


void matrix_input(Matrix& matrix);
void matrix_input_character_by_character(Matrix& matrix);


void matrix_print(Matrix& matrix);

void matrix_det(Matrix matrix);


//void matrix_triangl_print(Matrix& matrix);

void matrix_print(vector<vector<double>> matrix);

bool matrix_gausse_method(Matrix& matrix);

bool isTriangular(vector<vector<double>> matrix);

void print_two_matrix_non_multiplication(Matrix &A, Matrix &B, const char ch, const char chr);

void print_two_matrix_InColumn(Matrix A, Matrix B, const char ch, const char chr);

void drawTableFrame(int numRows, int numCols);
