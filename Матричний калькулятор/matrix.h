#pragma once
#include <vector>
#include "ConsoleControl.h"

class Matrix
{
public:
	Matrix(int rows, int cols = 1);
	void print();
	void input();
	void detPrint();

private:

	long double det = 1; 
	int rows, cols; 
	vector < vector < double >> matrix;
	vector < vector < double >> TrianglMatrix;

	void det_show();
	void determinant();

};

