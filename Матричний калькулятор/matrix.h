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

	void resize_matrix(int rows, int cols);
	vector <vector <double>> get_matrix();

	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	bool operator==(const Matrix& other) const;


private:

	long double det = 1; 
	int rows, cols; 
	vector < vector < double >> matrix;
	vector < vector < double >> TrianglMatrix;

	void det_show();
	void determinant();

};

