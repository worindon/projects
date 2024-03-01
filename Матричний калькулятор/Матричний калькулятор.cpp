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

		cout << endl << " Матрица " << array.size() << " на " << array[0].size() << endl;

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


		bool triangle() { //проверка на треугольный вид

		

		for (int i = 1; i <  rows; i++) {

			for (int j = 0; j < cols; j++) {

				if (array[i][j] != 0) {
					

					return 0; // логика в том что если встречаем не 0 в нужном диапазоне то возвращаем 0

				}
			}
			
		}//cout << "triangl" << endl; print();
		
			
			return 1; // возвращаем 1 если вид треугольный


	}

		int zeroInDiagonal() { // находим 0 в диагонали

			for (int i = 0; i < array.size(); i++) {

				if (!(array[i][i])) return i + 1;

			}

			return 0;
		}

		int colcheck(int param){ //проверяем наличие не 0 в столбике
			int i = 0;
			if (param) i++;
			for (; i < rows; i++) {

				if (array[i][param]) return i+1; //возвращаем индекс + 1 чтобы вернуть 0 если все числа 0

			}
			return 0;
		
		
		}

		int checkLine(int num) { //проверяем наличие не 0 в строчке

			for (int i = 0; i < cols; i++) {

				if (array[num][i]) return i+1;	//возвращаем индекс + 1 чтобы вернуть 0 если все числа 0

			}
			return 0;
		}

		void lineSwap(int param1, int param2) { //свапер строчек
			cout <<endl<< "Запуск свапера " << param1 << " " << param2 << endl;
			print();
			for (int i = 0; i < array.size(); i++) {

				swap(array[param1][i], array[param2][i]);

			}

			det *= -1; //при замене сточек меняем знак 

			cout << "->------->----->----->---"<<endl;
			print(); 
			cout << "-------------------------" << endl<<endl;
		}



		void detRess() { //сборная функция - прокладка, если num не будет равен нулю то перемножаем елементы гл. диагонали

			int num = determinant();

			if (num) {

				for (int i = 0; i < rows; i++) {

					det *= array[i][i];

				}
			}

			cout << endl << " Determinant = " << det * num<< endl; //умножаем на 0 или 1 в зависимости от результата функции determinant()
		}


		bool  determinant() { //метод гаусса

			while (!triangle()) { //делаем пока не добьемся треугольнова вида или не получим исключение

				for (int r = 0; r < rows; r++) {
					for (int i = r+1; i < rows; i++) {
						ST:
						if (array[r][r] == 0) { //делить на 0 нельзя
							cout << endl << "0" << endl;
							print();
							cout << endl <<r<<" "<< "0" << endl;
							cout << endl << "_" << endl;
							int temp = checkLine(r)-1; //находим индекс ненулевого ел. в строке
							int temp2 = colcheck(r)-1; //находим индекс ненулевого ел. в столбике
							
							if (temp  == -1) {cout <<   " Ряд нулей"   ;return 0;} //исключение : в  рядку нули
							if (temp2 == -1) {cout << " Стольбик нулей";return 0;} //исключение : в строке нули
							lineSwap(r, temp2);
							goto ST; //да, и что?

						}

						double k = array[i][r] / array[r][r]; //находим коэфициент


						for (int j = 0; j < rows; j++) {

							array[i][j] -= array[r][j] * k; //стандартный метод гаусса


						}
					}
				}
			}
			return 1; //возвращаем 1 если все хорошо
		}





	


};



int main()
{

	setlocale(LC_ALL, "ru");
    
	Matrix A(4, 4); //инициализируем

	A.input(); //вводим
	cons_clear(); //прокручиваем консоль чтобы красиво было
	system("pause"); //НАДА нажать кнопочку любую
	A.print(); //выводим
	A.check(); //запускаем

	cout << endl;
	A.print(); //выводим измененную
	system("pause"); //конец
	
	


	return 0; //ну точно уж конец
}

