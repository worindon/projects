#include <iostream>
#include <vector>

using namespace std;



template <typename T>  T abs(T a) {   //может понадобится(конечно же для костылей)

	if (a < 0) {
		return -a;
	}
	return a;

}

void cons_clear() { //очищаем консоль, но на самом деле просто прокручиваем ее 
	cout << "\033[2J\033[1;1H";

}



class Matrix
{
public:


	Matrix(int rows, int cols = 1) {

		this->rows = rows; //количество строчек
		this->cols = cols; //количество столбиков


		array.resize(rows, vector<double>(cols));  //изменяем масив под нужный размер

	}

	void print() { //вывод матрицы

		for (int i = 0; i < rows; i++) {
			cout << "\t";
			for (int j = 0; j < cols; j++) {

				cout << " " << array[i][j] << " ";
			}
			cout << endl;
		}

	}

	void input() { //ввод матрицы
		cons_clear();
		cout << endl << " Матрица " << array.size() << " на " << array[0].size() << endl;
		det = 1;
		for (int i = 0; i < rows; i++) {
			cout << "\t";
			for (int j = 0; j < cols; j++) {

				cin >> array[i][j];
			}
			cout << endl;
		}

	}

	void check() {  //пока что так

		detRess();
	}
;
private:

	long double det = 1; // поле определителя
	int rows, cols; //...
	vector < vector < double >> array;//но коментс


	



		void detRess() { // функция - прокладка

			cout << endl << " Determinant = " << determinant()<< endl;
			cons_clear(); //прокручиваем консоль чтобы красиво было
		}

		double  determinant() { //метод гаусса почти

			for (int i = 0; i < rows; ++i) {
				// Если элемент на главной диагонали равен нулю, меняем строки
				if (array[i][i] == 0) {
					int swapRow = -1;
					for (int j = i + 1; j < rows; ++j) {
						if (array[j][i] != 0) {
							swapRow = j;
							break;
						}
					}
					if (swapRow == -1)
						return 0; // Определитель равен нулю, если нет ненулевых элементов на главной диагонали
					swap(array[i], array[swapRow]);
					det *= -1; // Меняем знак определителя при перестановке строк
				}

				// Приводим матрицу к верхнетреугольному виду
				for (int j = i + 1; j < rows; ++j) {
					double factor = array[j][i] / array[i][i];
					for (int k = i; k < cols; ++k) {
						array[j][k] -= factor * array[i][k];
					}
				}
			}
			
			for (int i = 0; i < rows; ++i) {
				det *= array[i][i];
			}

			return det;

		}	


};



int main()
{
	
	setlocale(LC_ALL, "ru");
    
	Matrix A(4, 4); //инициализируем
	while (true) {
		A.input(); //вводим
		cons_clear(); //прокручиваем консоль чтобы красиво было
		system("pause"); //НАДА нажать кнопочку любую
		A.print(); //выводим
		A.check(); //запускаем

		cout << endl;
		A.print(); //выводим измененную
		system("pause"); //конец

	}


	return 0; //ну точно уж конец
}

