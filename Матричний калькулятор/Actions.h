#pragma once
#include <conio.h>
#include "ConsoleControl.h"
#include "matrix.h"

bool getAnswer(char yes, char no);

void actionDeterminant();

void menu();


int IndicatorForMenu(int zero_line, int end_poz);

bool main_menu(Matrix& A, Matrix& B);