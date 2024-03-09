#include "Matrix.h"
#include "ConsoleControl.h"


Matrix::Matrix(int rows, int cols)
{

		this->rows = rows;							//количество строчек
		this->cols = cols;							//количество столбиков

		matrix.resize(rows, vector<double>(cols));  //изменяем масив под нужный размер 

	
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		rows = other.rows;
		cols = other.cols;
		matrix = other.matrix;
		TrianglMatrix = other.TrianglMatrix;
		det = other.det;
	}
	return *this;
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
		throw std::invalid_argument("Matrices must have the same dimensions for addition");
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
		throw std::invalid_argument("Matrices must have the same dimensions for subtraction");
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
		throw std::invalid_argument("Number of columns in the first matrix must match the number of rows in the second matrix for multiplication");
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

bool Matrix::operator==(const Matrix& other) const {
	if (rows != other.rows || cols != other.cols) {
		return false; // Матрицы разного размера не могут быть равными
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] != other.matrix[i][j]) {
				return false; // Найден элемент, который не совпадает
			}
		}
	}
	return true; // Все элементы совпадают, матрицы равны
}


void Matrix::print()
{	
	setCursorPositionAbsolute(3, 5);


	for (int i = 0; i < rows; i++) {
		
		for (int j = 0; j < cols; j++) {

			cout << " " << matrix[i][j] << " ";
		}
						
		moveCursorDown();								// Перемещение курсора вниз

								
		setCursorPositionInLine(5);						// Возврат курсора в начало строки
	}
}

void Matrix::input()
{
	cout << endl << " Матрица " << matrix.size() << " на " << matrix[0].size() << endl;
	det = 1;
	for (int i = 0; i < rows; i++) {
		cout << "\t";
		for (int j = 0; j < cols; j++) {

			cin >> matrix[i][j];
		}
		cout << endl;
	}
}

void Matrix::detPrint()
{
	determinant();
	
	setCursorPositionAbsolute(3, 20);		// Установка позиции курсора для вывода матрицы
	
	for (int i = 0; i < rows; i++) {		// Вывод элементов матрицы с помощью cout
		cout << "->->    ";
		for (int j = 0; j < cols; j++) {
			std::cout << " " << TrianglMatrix[i][j] << " ";
		}

		moveCursorDown();					// Перемещение курсора вниз
									
		setCursorPositionInLine(20);		// Возврат курсора в начало строки(условной)
	}
	cout << endl;
	det_show();
}

void Matrix::resize_matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	matrix.resize(rows, vector<double>(cols));

}



void Matrix::det_show()
{
	cout << endl << " Determinant = " << det << endl;
}

void Matrix::determinant()
{
	TrianglMatrix = matrix;
	det = 1;

	for (int i = 0; i < rows; ++i) {
												// Если элемент на главной диагонали равен нулю, меняем строки
		if (TrianglMatrix[i][i] == 0) {			//делить на ноль нельзя, ну хоть и можно но мы не будем
			int swapRow = -1;
			for (int j = i + 1; j < rows; ++j) {
				if (TrianglMatrix[j][i] != 0) {
					swapRow = j;
					break;
				}
			}
			if (swapRow == -1) {
				det = 0;
				return;
			}
			swap(TrianglMatrix[i], TrianglMatrix[swapRow]);
			det *= -1;							// Меняем знак определителя при перестановке строк
		}

												// Приводим матрицу к верхнетреугольному виду
		for (int j = i + 1; j < rows; ++j) {
			double factor = TrianglMatrix[j][i] / TrianglMatrix[i][i];
			for (int k = i; k < cols; ++k) {
				TrianglMatrix[j][k] -= factor * TrianglMatrix[i][k];
			}
		}
	}

	for (int i = 0; i < rows; ++i) {
		det *= TrianglMatrix[i][i];
	}
}

vector<vector<double>> Matrix::get_matrix()
{
	return matrix;
}