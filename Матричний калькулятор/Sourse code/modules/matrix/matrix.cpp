#include "Matrix.h"


Matrix::Matrix(int rows, int cols)
{

		this->rows = rows;							//количество строчек
		this->cols = cols;							//количество столбиков

		matrix.resize(rows, vector<double>(cols));  //измен€ем масив под нужный размер 

	
}

Matrix::Matrix(){

	matrix.resize(3, vector<double>(3));
	this->TrianglMatrix = this->matrix;

}





Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		rows = other.rows;
		cols = other.cols;
		matrix = other.matrix;
		TrianglMatrix = other.TrianglMatrix;
		det = other.det;
	}
	return *this; //необ€зательно но нужно дл€ выражений по типу A=B=C     
				  //нужно вернуть указатель, чтобы присвоить значени€ елементу ј, так как присвоение начинаетс€ с конца
}
Matrix Matrix::operator+(const Matrix& other) const {
	if (rows != other.rows || cols != other.cols) {
		throw invalid_argument("Matrices must have the same dimensions for addition");
	}

	Matrix result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}
	return result;
}
Matrix Matrix::operator-(const Matrix& other) const {
	if (rows != other.rows || cols != other.cols) {
		throw invalid_argument("Matrices must have the same dimensions for subtraction");
	}

	Matrix result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}
	return result;
}
Matrix Matrix::operator*(const Matrix& other) const {
	if (cols != other.rows) {
		throw invalid_argument("Number of columns in the first matrix must match the number of rows in the second matrix for multiplication");
	}

	Matrix result(rows, other.cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < other.cols; ++j) {
			for (int k = 0; k < cols; ++k) {
				result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	return result;
}
Matrix& Matrix::operator+=(const Matrix& other) {
	if (rows != other.rows || cols != other.cols) {
		throw invalid_argument("Matrices must have the same dimensions for addition");
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] += other.matrix[i][j];
		}
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& other) {
	if (rows != other.rows || cols != other.cols) {
		throw invalid_argument("Matrices must have the same dimensions for subtraction");
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] -= other.matrix[i][j];
		}
	}
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& other) {
	if (cols != other.rows) {
		throw invalid_argument("Number of columns in the first matrix must match the number of rows in the second matrix for multiplication");
	}

	Matrix result(rows, other.cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < other.cols; ++j) {
			for (int k = 0; k < cols; ++k) {
				result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	*this = result; // Assigning the result back to this matrix
	return *this;
}
vector<double>& Matrix::operator [] (int index) {
	if (index < 0 || index >= rows) {
		throw out_of_range("Index out of range");
	}
	return matrix[index];
}
bool Matrix::operator==(const Matrix& other) const {
	if (rows != other.rows || cols != other.cols) {
		return false;		  // ћатрицы разного размера не могут быть равными
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] != other.matrix[i][j]) {
				return false; // Ќайден элемент, который не совпадает
			}
		}
	}
	return true;			  // ¬се элементы совпадают, матрицы равны
}

int Matrix::get_height() const
{
	return rows;
}



int Matrix::get_width() const
{
	return cols;
}

vector<vector<double>> Matrix::get_matrix()
{
	return matrix;
}

vector <vector <double>> Matrix::get_Triangle_matrix() {
	return TrianglMatrix;
}

double Matrix::get_det()
{
	return this->det;
}

void Matrix::set_matrix(vector<vector<double>> matrix)
{
	this->matrix = matrix;
}
void Matrix::set_triangl_matrix(vector < vector < double >> TrianglMatrix) {
	this->TrianglMatrix = TrianglMatrix;
}
void Matrix::set_det(long double det)
{
	this->det = det;
}

void Matrix::resize_matrix(int rows, int cols)
{
	vector<vector<double>> newMatrix(rows, vector<double>(cols));

	
	int minRows = min(this->rows, rows);
	int minCols = min(this->cols, cols);
	for (int i = 0; i < minRows; ++i) {
		for (int j = 0; j < minCols; ++j) {
			newMatrix[i][j] = matrix[i][j];
		}
	}

	
	this->rows = rows;
	this->cols = cols;
	this->matrix = newMatrix;

}