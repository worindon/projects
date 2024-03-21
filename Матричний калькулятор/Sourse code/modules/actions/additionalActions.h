#pragma once
#include "../options/matrix/matrix_options.h"

bool getAnswer(char yes, char no);

//void actionDeterminant();

int actionIndicatorForMenu(int zero_line, int end_poz);
void actionSelectMatrixForDeterminant(Matrix& A, Matrix& B);

bool actionMain_menu(Matrix& A, Matrix& B);

void actionResizeMatrix(Matrix& A, Matrix& B);

void actionInputMatrixInSerealMode(Matrix& A, Matrix& B);

void actionMatrixAddition(Matrix& A, Matrix& B);

void actionMatrixSubtraction(Matrix& A, Matrix& B);

void actionMatrixMultiplication(Matrix& A, Matrix& B);


bool actionExit();

void actionInputMatrixInManualMode(Matrix& A, Matrix& B);
