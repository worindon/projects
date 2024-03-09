#include "Matrix.h"
#include "ConsoleControl.h"


Matrix::Matrix(int rows, int cols)
{

		this->rows = rows;							//���������� �������
		this->cols = cols;							//���������� ���������

		matrix.resize(rows, vector<double>(cols));  //�������� ����� ��� ������ ������ 

	
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		rows = other.rows;
		cols = other.cols;
		matrix = other.matrix;
		TrianglMatrix = other.TrianglMatrix;
		det = other.det;
	}
	return *this; //������������� �� ����� ��� ��������� �� ���� A=B=C     
				  //����� ������� ���������, ����� ��������� �������� �������� �, ��� ��� ���������� ���������� � �����
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

vector<double>& Matrix::operator[](int index) {
	if (index < 0 || index >= rows) {
		throw out_of_range("Index out of range");
	}
	return matrix[index];
}

bool Matrix::operator==(const Matrix& other) const {
	if (rows != other.rows || cols != other.cols) {
		return false; // ������� ������� ������� �� ����� ���� �������
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] != other.matrix[i][j]) {
				return false; // ������ �������, ������� �� ���������
			}
		}
	}
	return true; // ��� �������� ���������, ������� �����
}


void Matrix::print()
{	
	setCursorPositionAbsolute(3, 5);


	for (int i = 0; i < rows; i++) {
		
		for (int j = 0; j < cols; j++) {

			cout << " " << matrix[i][j] << " ";
		}
						
		moveCursorDown();								// ����������� ������� ����

								
		setCursorPositionInLine(5);						// ������� ������� � ������ ������
	}
}

void Matrix::input()
{
	cout << endl << " ������� " << matrix.size() << " �� " << matrix[0].size() << endl;
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
	
	setCursorPositionAbsolute(3, 20);		// ��������� ������� ������� ��� ������ �������
	
	for (int i = 0; i < rows; i++) {		// ����� ��������� ������� � ������� cout
		cout << "->->    ";
		for (int j = 0; j < cols; j++) {
			std::cout << " " << TrianglMatrix[i][j] << " ";
		}

		moveCursorDown();					// ����������� ������� ����
									
		setCursorPositionInLine(20);		// ������� ������� � ������ ������(��������)
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
												// ���� ������� �� ������� ��������� ����� ����, ������ ������
		if (TrianglMatrix[i][i] == 0) {			//������ �� ���� ������, �� ���� � ����� �� �� �� �����
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
			det *= -1;							// ������ ���� ������������ ��� ������������ �����
		}

												// �������� ������� � ������������������ ����
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