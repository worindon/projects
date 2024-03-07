#include "Matrix.h"
#include "ConsoleControl.h"


Matrix::Matrix(int rows, int cols)
{
	

		this->rows = rows;							//���������� �������
		this->cols = cols;							//���������� ���������

		matrix.resize(rows, vector<double>(cols));  //�������� ����� ��� ������ ������

	
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

vector<vector<double>> Matrix::get_matrix()
{
	return matrix;
}

void Matrix::det_show()
{
	cout << endl << " Determinant = " << det << endl;
}

void Matrix::determinant()
{
	TrianglMatrix = matrix;

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
