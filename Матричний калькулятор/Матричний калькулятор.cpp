#include <iostream>
#include <vector>

using namespace std;



template <typename T>  T abs(T a) {

	if (a < 0) {
		return -a;
	}
	return a;

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

		for (int i = 0; i < array.size(); i++) {
			cout << "\t";
			for (int j = 0; j < array[0].size(); j++) {

				cin >> array[i][j];
			}
			cout << endl;
		}

	}

	void check() {

		checkCols();
		checkLine();
		determinant();
		detRess();
	}


	;

private:

	int det = 1;
	int rows, cols;
	vector < vector < double >> array;


	bool triangle() {

		int k = array.size();

		for (int i = 1; i < k; i++) {

			for (int j = 0; j <= i; j++) {

				if (array[i][j]) return 1;

			}
		}

		return 0;
	}

	int zeroInDiagonal() {

		for (int i = 0; i < array.size(); i++) {

			if (!(array[i][i])) return i + 1;

		}

		return 0;
	}

	int checkLine(int num) {

		num--;

		for (int i = 0; i < array.size(); i++) {

			if (array[num][i]) return i + 1;

		}

		return 0;

	}

	void lineSwap(int param1, int param2) {

		for (int i = 0; i < array.size(); i++) {

			swap(array[param1][i], array[param2][i]);

		}

		det *= -1;

		//cons_clear();

		//print_matrix(matrix);

	}

	bool checkCols() {

		
		int num = zeroInDiagonal() - 1;
		if (num < 0) num = 0;
		cout << "colstart" << endl;

		for (int i = 0; i < array.size(); i++) {
			 
			if (array[i][num]) {
				cout << "col"<<endl;
				return 0;
			}
		}
		
		return 1;	
	}

	bool checkLine() {

		int num = zeroInDiagonal() - 1;
		if (num < 0) num = 0;
		cout << "linestart" << endl;

		for (int i = 0; i < array.size(); i++) {

			if (array[num][i]) {
				cout << "line";
				return 0;
			}
		}

		return 1;
	}

	void detRess() {
		for (int i = 0; i < rows; i++) {

			det *= array[i][i];
			
		}
		cout << endl << " Deterrminant = " << det << endl;
	}


	void determinant() {




		for (int r = 0; r < rows; ++r) {
			for (int i = r + 1; i < rows; ++i) {

				double k = array[i][r] / array[r][r];

				for (int j = r; j < cols; ++j) {

					array[i][j] -= array[r][j] * k;

				}
			}
			cout << endl;
			print();

		}
		


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
    
	Matrix A(3, 3);

	A.input();A.print();
	A.check();

	cout << endl;
	A.print();
	 
	



   
}

