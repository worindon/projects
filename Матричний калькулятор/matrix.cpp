#include "Matrix.h"
#include "ConsoleControl.h"






Matrix::Matrix(int rows, int cols = 1)
{
	

		this->rows = rows; //количество строчек
		this->cols = cols; //количество столбиков

		matrix.resize(rows, vector<double>(cols));  //изменяем масив под нужный размер

	
}

void Matrix::print()
{
	setCursorPostionAbsolute(3, 5);


	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << " " << matrix[i][j] << " ";
		}
		// Перемещение курсора вниз
		std::cerr << "\033[B";

		// Возврат курсора в начало строки
		setCursorPositionInLine(5);
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

	// Установка позиции курсора для вывода матрицы
	setCursorPostionAbsolute(3, 20);

	// Вывод элементов матрицы с помощью cout
	for (int i = 0; i < rows; i++) {
		cout << "->->    ";
		for (int j = 0; j < cols; j++) {
			std::cout << " " << TrianglMatrix[i][j] << " ";
		}

		// Перемещение курсора вниз
		cerr << "\033[B";

		// Возврат курсора в начало строки
		cerr << "\033[20G";
	}
	cout << endl;
	det_show();
}

void Matrix::det_show()
{
	cout << endl << " Determinant = " << det << endl;
}

void Matrix::determinant()
{
	TrianglMatrix = matrix;

	for (int i = 0; i < rows; ++i) {
		// Если элемент на главной диагонали равен нулю, меняем строки
		if (TrianglMatrix[i][i] == 0) { //делить на ноль нельзя, ну хоть и можно но мы не будем
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
			det *= -1; // Меняем знак определителя при перестановке строк
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
