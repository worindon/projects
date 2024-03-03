﻿#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


void console_abs_pos(int row, int col) {

	ostringstream oss;
	oss << "\033[" << row << ";" << col << "H";
	string ansi_sequence = oss.str();
	cerr << ansi_sequence;
}

void console_pos_in_line(int col) {

	ostringstream oss;
	oss << "\033[" << col << "G";
	string ansi_sequence = oss.str();
	cerr << ansi_sequence;

}


template <typename T>  T abs(T a) {   //может понадобится(конечно же для костылей)

	if (a < 0) {
		return -a;
	}
	return a;

}

void cons_clear() { //очищаем консоль
	cerr << "\033[1J\033[1;1H";
	

}


class console {

public:
	
	void setCursorPostionAbsolute(int row, int col) {

		ostringstream oss;
		oss << "\033[" << row << ";" << col << "H";
		string ansi_sequence = oss.str();
		cerr << ansi_sequence;
	}
	void setCursorPositionInLine(int col) {

		ostringstream oss;
		oss << "\033[" << col << "G";
		string ansi_sequence = oss.str();
		cerr << ansi_sequence;

	}
	void setCursorPositionShiftUp(int row) {

		ostringstream oss;
		oss << "\033[" << row << "A";
		string ansi_sequence = oss.str();
		cerr << ansi_sequence;
		
	}
	void setCursorPositionShiftDown(int row) {

		ostringstream oss;
		oss << "\033[" << row << "B";
		string ansi_sequence = oss.str();
		cerr << ansi_sequence;
		
	}
	void setCursorPositionShiftRight(int offset) {

		ostringstream oss;
		oss << "\033[C" << "<" << offset << ">";
		string ansi_sequence = oss.str();
		cerr << ansi_sequence;
		
	}

	void clear() {
		cerr << "\033[1J\033[1;1H";
	}

	void setColorDefault() {

		cerr << "\033[0m";

	}

	void setTextColor(const char color[]) {

		if (color == "black") {
			cerr << "\033[30m";
		}
		else if (color == "red") {
			cerr << "\033[31m";
		}
		else if (color == "green") {
			cerr << "\033[32m";
		}
		else if (color == "yellow") {
			cerr << "\033[33m";
		}
		else if (color == "blue") {
			cerr << "\033[34m";
		}
		else if (color == "purple") {
			cerr << "\033[35m";
		}
		else if (color == "white") {
			cerr << "\033[37m";
		}
		else cerr << "nan undefind text color";
	}

	void setFoneColor(const char color[]) {

		if (color == "black") {
			cerr << "\033[40m";
		}
		else if (color == "red") {
			cerr << "\033[41m";
		}
		else if (color == "green") {
			cerr << "\033[42m";
		}
		else if (color == "yellow") {
			cerr << "\033[43m";
		}
		else if (color == "blue") {
			cerr << "\033[44m";
		}
		else if (color == "purple") {
			cerr << "\033[45m";
		}
		else if (color == "white") {
			cerr << "\033[47m";
		}
		else cerr << "nan undefind text color";
	}
	
	
	
	
	;






};






class Matrix{


public:


	Matrix(int rows, int cols = 1) {

		this->rows = rows; //количество строчек
		this->cols = cols; //количество столбиков

		matrix.resize(rows, vector<double>(cols));  //изменяем масив под нужный размер

	}

	void print() { //вывод матрицы
		console_abs_pos(3, 5);
	

		for (int i = 0; i < rows; i++) {
			
			for (int j = 0; j < cols; j++) {

				cout << " " << matrix[i][j] << " ";
			}
			// Перемещение курсора вниз
			std::cerr << "\033[B";

			// Возврат курсора в начало строки
			console_pos_in_line(5);
		}

	}

	void input() { //ввод матрицы
		//cons_clear();
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

	void det_print() {
    
    determinant();

    // Установка позиции курсора для вывода матрицы
	console_abs_pos(3, 20);

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

	


;
private:

	long double det = 1; // поле определителя
	int rows, cols; //...
	vector < vector < double >> matrix;//но коментс
	vector < vector < double >> TrianglMatrix;

	
		
	






		void det_show() { // функция - прокладка
			//cons_clear(); //прокручиваем консоль чтобы красиво было
			
			cout << endl << " Determinant = " << det<< endl;
			
		}

		void  determinant() { //метод гаусса 

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
						return ;
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


};



int main()
{
	
	setlocale(LC_ALL, "ru");
	Matrix A(3, 3);
	A.input();
	system("pause");
	cons_clear();
	A.print();
	cout << endl;

	A.det_print();
	cout << endl;

	return 0;
}


//\033: Это символ Escape(также обозначается как \e или \x1B), который сообщает терминалу, что следующие символы будут командами управления.
//[1; 1H:Команда установки курсора в верхний левый угол экрана(строка 1, столбец 1).
//\033[K:Очистка от текущего положения курсора до конца строки. 
//\033[A:Перемещение курсора вверх на одну строку.				
//\033[B:Перемещение курсора вниз на одну строку.				
//\033[C:Перемещение курсора вправо на один символ.
//\033[D:Перемещение курсора влево на один символ.
//\033[s: Сохранение текущего положения курсора.
//\033[u:Восстановление предыдущего сохраненного положения курсора.
//\033[A<количество>:Перемещение курсора вверх на указанное количество строк.
//\033[B<количество>:Перемещение курсора вниз на указанное количество строк.
//\033[C<количество>:Перемещение курсора вправо на указанное количество символов.
//\033[D<количество>:Перемещение курсора влево на указанное количество символов.
//\033[<строка>; <столбец>H или \033[<строка>; <столбец>f: Перемещение курсора в указанную позицию(строка, столбец).
//\033[<цвет>m:Изменение цвета текста или фона.Например, \033[31m устанавливает красный цвет текста, а \033[41m устанавливает красный цвет фона.
//\033[0m:Сброс настроек цвета текста и фона к значениям по умолчанию.
//\033[? 25l : Скрыть курсор.
//\033[? 25h : Показать курсор.
//\033[2J:Очистка всего экрана.
//\033[? 1049h : Сохранение текущего состояния экрана.
//\033[? 1049l : Восстановление сохраненного состояния экрана.
//\033[2K:Очистка строки, на которой находится курсор.
//\033[<n>G:Перемещение курсора в указанный столбец текущей строки.
//\033[<n>A:Перемещение курсора на указанное количество строк вверх.
//\033[<n>B:Перемещение курсора на указанное количество строк вниз.
//\033[<n>C:Перемещение курсора на указанное количество символов вправо.
//\033[<n>D:Перемещение курсора на указанное количество символов влево.
//\033[<n>S:Прокрутка содержимого экрана вверх на указанное количество строк.
//\033[<n>T:Прокрутка содержимого экрана вниз на указанное количество строк.
//\033[3J:Очистка экрана и буфера экрана.   