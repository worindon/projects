#pragma once
#include "matrix_options.h"

bool getAnswer(char yes, char no);

//void actionDeterminant();

int IndicatorForMenu(int zero_line, int end_poz);

bool main_menu(Matrix& A, Matrix& B);

void actionResizeMatrix(Matrix& A, Matrix& B);

void actionCelectMatrixForInput(Matrix& A, Matrix& B);

void actionMatrixAddition(Matrix& A, Matrix& B);

void actionMatrixSubtraction(Matrix& A, Matrix& B);

void actionMatrixMultiplication(Matrix& A, Matrix& B);

bool actionExit();

void actionCelectMatrixForInputSeparateNumbers(Matrix& A, Matrix& B);