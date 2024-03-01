#include <iostream>
#include <vector>

using namespace std;



template <typename T>  T abs(T a) {

	if (a < 0) {
		return -a;
	}
	return a;

}

void cons_clear() {
	cout << "\033[2J\033[1;1H";

}



class Matrix
{
public:


	Matrix(int rows, int cols = 1) {

		this->rows = rows;
		this->cols = cols;


		array.resize(rows, vector<double>(cols));

	}

	void print() {

		for (int i = 0; i < rows; i++) {
			cout << "\t";
			for (int j = 0; j < cols; j++) {

				cout << " " << array[i][j] << " ";
			}
			cout << endl;
		}

	}

	void input() {

		cout << endl << " Матрица " << array.size() << " на " << array[0].size() << endl;

		for (int i = 0; i < rows; i++) {
			cout << "\t";
			for (int j = 0; j < cols; j++) {

				cin >> array[i][j];
			}
			cout << endl;
		}

	}

	void check() {

		triangle();
		detRess();
	}
;
private:

	long double det = 1;
	int rows, cols;
	vector < vector < double >> array;


		bool triangle() {

		int k = array.size();

		for (int i = 1; i < k; i++) {

			for (int j = 0; j < i; j++) {

				if (array[i][j] != 0) {
					//cout << "Nontr" <<i<<" "<<j<< endl;
					//	print();
					return 0;

				}
			}
			
		}
		
			//cout << "triangl" << endl;
			//print();
			return 1;


	}

		int zeroInDiagonal() {

			for (int i = 0; i < array.size(); i++) {

				if (!(array[i][i])) return i + 1;

			}

			return 0;
		}

		int colcheck(int param){
			int i = 0;
			if (param) i++;
			for (; i < rows; i++) {

				if (array[i][param]) return i+1;

			}
			return 0;
		
		
		}

		int checkLine(int num) {

			for (int i = 0; i < cols; i++) {

				if (array[num][i]) return i+1;

			}
			return 0;
		}

		void lineSwap(int param1, int param2) {
			cout << "Запуск свапера " << param1 << " " << param2 << endl;

			for (int i = 0; i < array.size(); i++) {

				swap(array[param1][i], array[param2][i]);

			}

			det *= -1;

			cout << "---------------------";
			print(); 
			cout << "---------------------" << endl<<endl;
		}



		void detRess() {

			int num = determinant();

			if (num) {

				for (int i = 0; i < rows; i++) {

					det *= array[i][i];

				}
			}

			cout << endl << " Determinant = " << det * num<< endl;
		}


		bool  determinant() {
			while (!triangle()) {

				for (int r = 0; r < rows; r++) {
					for (int i = r+1; i < rows; i++) {
						ST:
						if (array[r][r] == 0) {
														
							int temp = checkLine(r)-1;
							int temp2 = colcheck(r)-1;
							if (temp  == -1) {cout << " ?";return 0;}
							if (temp2 == -1) {cout << " !";return 0;}
							lineSwap(r, temp);
							goto ST;

						}

						double k = array[i][r] / array[r][r];


						for (int j = 0; j < rows; j++) {

							array[i][j] -= array[r][j] * k;


						}
					}
				}
			}
			return 1;
		}





	


};

void   foo(int a) {

	Matrix b(a);
	b.input();
	b.print();
}

int main()
{

	setlocale(LC_ALL, "ru");
    
	Matrix A(4, 4);

	A.input();
	cons_clear();
	system("pause");
	A.print();
	A.check();

	cout << endl;
	A.print();
	system("pause");
	
	


   
}

