#include "matrix_options.h"

void matrix_input_character_by_character(Matrix& matrix)
{
	clear();

	int rows = matrix.get_height();
	int cols = matrix.get_width();
	matrix.set_det(1);

	int currentRow = 0; // Текущая строка
	int currentCol = 0; // Текущий столбец

	cout << endl << " Матрица " << rows << " на " << cols << endl;
	cerr << "\033[?25l";
	while (true) {
		clear(); // Очистка экрана перед каждым обновлением

		// Отображение матрицы
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (i == currentRow && j == currentCol) {
					cout << "[" << setw(6) << matrix[i][j] << "]";
				}
				else {
					cout << " " << setw(6) << matrix[i][j] << " ";
				}
			}
			cout << endl;
		}

		cout << "\n Используйте клавиши управления для перемещения по матрице." <<  endl;
		cout << " Нажмите Enter для ввода значения. Нажмите 'E' для завершения." << endl;

		char ch = _getch(); // Получение нажатой клавиши

		if (ch == 'E' || ch == 'e') {
			break; // Завершить ввод матрицы
		}
		if (ch == '\r') { // Если нажата клавиша Enter
			cout << "\n Введите значение: ";
			double element;
			while (!(cin >> element)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			matrix[currentRow][currentCol] = element;
		}
		if (ch == 'H' && currentRow > 0) { // Стрелка вверх
			currentRow--;
					
		}
		if (ch == 'P' && currentRow < rows - 1) { // Стрелка вниз
			currentRow++;
					
		}
		if (ch == 'K' && currentCol > 0) { // Стрелка влево
			currentCol--;
					
		}
		if (ch == 'M' && currentCol < cols - 1) { 
			currentCol++;
					
		}
		
	}
	cerr << "\033[?25h";
}

void matrix_input(Matrix& matrix){
	clear();
	int rows = matrix.get_height();
	int cols = matrix.get_width();
	matrix.set_det(1);
	cout << endl << " Матрица " << rows << " на " << cols << endl;


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			double element;
			while (!(cin >> element)) { 
				cin.clear();			
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

			}
			matrix[i][j] = element;

		}
	}
}

void matrix_print(Matrix& matrix)
{
	
	int rows = matrix.get_height();
	int cols = matrix.get_width();
	saveCursorPosition();
	drawTableFrame(rows, cols);
	
	for (int i = 0; i < rows; i++) {	

		

		for (int j = 0; j < cols; j++) {

		restoreCursorPosition();
		setCursorPositionShiftDown(2*(i+1) - 1);
		setCursorPositionShiftRight(1 + j * 10 - j);
		cout << matrix[i][j];
			
		}
		
		setCursorPositionShiftDown(i+1);

				
	}
	restoreCursorPosition();
}

void matrix_print(vector<vector<double>>  matrix)
{

	int rows = matrix.size();
	int cols = matrix[0].size();
	saveCursorPosition();
	drawTableFrame(rows, cols);
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			restoreCursorPosition();
			setCursorPositionShiftDown(2 * i + 1);
			setCursorPositionShiftRight(1 + j * 10 - j);
			cout << matrix[i][j];
		}
		setCursorPositionShiftDown(i + 1);
	}
	
	
	
}

bool matrix_gausse_method(Matrix& matrix)
{
	
	vector<vector<double>> trimatrix = matrix.get_matrix();

	double det = 1;
	int rows = matrix.get_height();
	int cols = matrix.get_width();

	
	for (int i = 0; i < rows; ++i) {
		
		if (trimatrix[i][i] == 0) {			
			int swapRow = -1;
			for (int j = i + 1; j < rows; ++j) {
				if (trimatrix[j][i] != 0) {
					swapRow = j;
					break;
				}
			}
			if (swapRow == -1) {
				
				matrix.set_det(0);
				matrix.set_triangl_matrix(trimatrix);
				
				return false;
			}
			swap(trimatrix[i], trimatrix[swapRow]);
			det *= -1;							// Меняем знак определителя при перестановке строк
		}

		// Приводим матрицу к верхнетреугольному виду
		for (int j = i + 1; j < rows; ++j) {
			double factor = trimatrix[j][i] / trimatrix[i][i];
			for (int k = i; k < cols; ++k) {
				trimatrix[j][k] -= factor * trimatrix[i][k];
			}
		}
	}

	
	matrix.set_triangl_matrix(trimatrix);
	
	for (int i = 0; i < rows; ++i) {
		det *= trimatrix[i][i];
	}
	matrix.set_det(det);
	cout << "Determinant = " << det;
	return true;

}

void print_folder(int rows, int cols) {

	cout << string(5 * cols, '-') << endl;
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
			cout << "|     ";
		}
		cout << endl << string(5 * cols, '-') << endl;
	
	}

}

void print_two_matrix_non_multiplication(Matrix &A, Matrix &B, const char ch, const char chr) {


	
	matrix_print(A);
	setCursorPositionShiftRight(A.get_width()*9 + 1 );
	cout << "  ";
	saveCursorPosition();
	setCursorPositionShiftDown(A.get_height());
	cout <<ch<<"  ";
	restoreCursorPosition();
	setCursorPositionShiftRight(3);
	matrix_print(B);
	setCursorPositionShiftRight(B.get_width() * 9 + 1);
	cout << "  ";
	saveCursorPosition();
	setCursorPositionShiftDown(B.get_height() );
	cout << chr << "  ";
	restoreCursorPosition();
	setCursorPositionShiftRight(3);
	if(ch == '+'){A += B;}
	else if (ch == '-') { A -= B; }	
	matrix_print(A);
	setCursorPositionShiftDown(A.get_width() * 2 + 1);
	setCursorPositionShiftDown(A.get_height() * 2 + 1);
	cout << '\n';
	

}

void print_two_matrix_InColumn(Matrix A, Matrix B, const char ch, const char chr) {
	cout << '|' << ch << "|= ";
	matrix_print(A);
	setCursorPositionShiftDown(A.get_height() * 2 + 1);
	cout << "\033[5D";
	cout << '|' << chr << "|= ";	
	matrix_print(B);	
}

// Функция для отрисовки рамки таблицы
void drawTableFrame(int numRows, int numCols) {
	// Верхняя горизонтальная линия
	setTextColor("green");
	saveCursorPosition();
	cout << "+";
	for (int i = 0; i < numCols; ++i) {
		cout << "--------+";
	}


	int k = 1;
	for (int i = 0; i < numRows; i++, k++) {

		restoreCursorPosition();
		setCursorPositionShiftDown(i + k);

		cout << "|";
		for (int j = 0; j < numCols; ++j) {
			cout << "        |";
		}
		restoreCursorPosition();
		setCursorPositionShiftDown(i + k + 1);


		cout << "+";
		for (int j = 0; j < numCols; ++j) {
			cout << "--------+";
		}

	}
	setTextColor("white");
}