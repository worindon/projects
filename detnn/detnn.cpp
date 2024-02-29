#include <iostream>
#include <vector>
using namespace std;




double detetrminant = 1.0;
int paramsize;

double my_abs(double a) {
	if (a < 0) return -a;

	return a;
}

void cons_clear() {
	cout << "\033[2J\033[1;1H";

}

bool qwest() {

	cout << endl;
	char i;
	do {
		scanf_s("%c", &i, sizeof(i));
	} while (!(i == 'Y' || i == 'N' || i == 'y' || i == 'n'));

	if (i == 'y' || i == 'Y') return 1;
	return 0;

}

void print_matrix(vector<vector <double>> matrix) {

	cout << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << "\t";
		for (int j = 0; j < matrix.size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}
void determ(vector<vector<double>>& matrix, bool param = 1) {

	int size = matrix.size();

	

	for (int r = 0; r < size; r++) {
	
		if (matrix_diagonal_check(matrix) ) {

			int num = matrix_diagonal_check(matrix) - 1;

			if (matrix_check_line(matrix) == 0) {    //весь рядок 0

				cout << "check";

				if (matrix_column_check(matrix, num) == 0) {

					cout << endl << "det = 0" << endl;

					detetrminant = 0;

					return;
				}

			}
			else {   

				print_matrix(matrix);

				int temp = matrix_check_line(matrix) - 1;
				cout <<endl<< "запуск свапера\t"<<num+1<<"   "<<temp+1<<"\n" << endl;
				line_swaper(matrix, num, temp);

				determ(matrix);
				print_matrix(matrix);

				

			}
		}
		else {

			cout << "исключение 2"<<endl;
			for (int i = r + 1; i < size; i++) {

				double k = matrix[i][r] / matrix[r][r];

				for (int j = r; j < size; j++) {

					matrix[i][j] -= matrix[r][j] * k;

				}
			}				
		}		
	}	
}
void input_matrix(vector<vector <double>>& matrix) {
	

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			cin >> matrix[i][j];
		}
	}

	cons_clear();

	cout << endl << "\n";

	print_matrix(matrix);

}

bool matrix_triangle_check(vector<vector <double>>& matrix) {

	int k = matrix.size();

	for (int i = 1; i < k; i++) {

		for (int j = 0; j <= i; j++) {

			if (matrix[i][j]) return 1;

		}
	}

	return 0;
}
int matrix_check_line(vector<vector <double>>& matrix) {

	int num = matrix_diagonal_check(matrix) - 1;

	for (int i = 0; i < matrix.size(); i++) {

		if (matrix[num][i]) return i+1;
		
	}

	return 0;	

}
int matrix_diagonal_check(vector<vector <double>>& matrix) {

	for (int i = 0; i < matrix.size(); i++) {

		if (!(matrix[i][i])) return i + 1;

	}

	return 0;
}



bool matrix_column_check(vector<vector <double>>& matrix, int num) {
	

	if (num >= 0 and num < matrix.size()) {


		for (int i = 0; i < matrix.size(); i++) {

			if (matrix[i][num]) return 1;

		}
	}

	return 0;

}

void matrix_line_swap(vector<vector <double>>& matrix, int checker) {

	int b, size = matrix.size();

	//cons_clear();

	cout << endl << "Ведите число ";

	do {
		cin >> b;

	} while (!(b <= size && checker != b));

	checker--; b--;

	for (int i = 0; i < matrix.size(); i++) {

		swap(matrix[checker][i], matrix[b][i]);

	}

	detetrminant *= -1;

	//cons_clear();

	print_matrix(matrix);

}

void line_swaper(vector<vector <double>>& matrix, int param1, int param2 ){

	for (int i = 0; i < matrix.size(); i++) {

		swap(matrix[param1][i], matrix[param2][i]);

	}

	detetrminant *= -1;

	//cons_clear();

	//print_matrix(matrix);

}
//void hand_swap(vector<vector <double>>& matrix) {
//
//	int checker = matrix_diagonal_check(matrix);
//
//
//	if (checker != 0 && paramsize > 2) {
//
//		cout << endl << checker << "-й элемент главной диагонали равен 0, введите номер строки с которой хотите поменять даную" << endl;
//
//
//
//		matrix_line_swap(matrix, checker);
//
//	}
//
//
//
//	if (matrix_diagonal_check(matrix)) hand_swap(matrix);
//
//}






vector <vector <double>>  multiplication_matrix(vector<vector <double>>& matrix1, vector<vector <double>>& matrix2) {

	int n = matrix1.size();
	vector<vector <double>> resmatrix(n, vector <double>(n));

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			for (int k = 0; k < n; k++) {

				resmatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}

		}
	}

	return resmatrix;
}




void determ_res(vector<vector<double>>& matrix) {

	int size = matrix.size();

	if (detetrminant) {

		for (int i = 0; i < size; i++) {

			detetrminant *= matrix[i][i];

		}
	}

	cout << endl << " det  = " << detetrminant << endl;

}




void main() {

	setlocale(LC_ALL, "ru");

	cout << "Введите размер матрицы а затем сами элементы матрицы ";

	cin >> paramsize;

	vector < vector <double> > matrix1(paramsize, vector <double>(paramsize));

	input_matrix(matrix1);	

	determ(matrix1);

	//matrix_column_check(matrix1);

	determ_res(matrix1);

	print_matrix(matrix1);


	system("pause");
}




