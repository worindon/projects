#pragma once
#include "../options/console/ConsoleControl.h"

class Matrix
{
public:

	Matrix(int rows, int cols);
	Matrix();

	void resize_matrix(int rows, int cols);

	int get_height() const;
	int get_width() const;
	
	
	
	vector <vector <double>> get_matrix();
	vector <vector <double>> get_Triangle_matrix();
	double get_det();

	void set_matrix(vector < vector < double >> matrix);
	void set_det(long double det = 1);
	void set_triangl_matrix(vector < vector < double >> TrianglMatrix);


	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	vector<double>& operator[](int index);
	bool operator==(const Matrix& other) const;


;
private:

	double det = 1; 
	int rows=3, cols=3; 
	vector < vector < double >> matrix;
	vector < vector < double >> TrianglMatrix;
};

