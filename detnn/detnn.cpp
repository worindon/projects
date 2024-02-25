#include <iostream>
#include <vector>
using namespace std;




double detetrminant = 1.0;
int paramsize;



void det(vector<vector<double>>& matrix) {

	int size = matrix.size(); 

	for (int r = 0; r < size; r++) {

		for (int i = r+1; i < size; i++) {

			double k = matrix[i][r] / matrix[r][r];

			for (int j = r; j < size; j++) {

				matrix[i][j] -= matrix[r][j] * k;
				
			}			
		}
	}	

	for (int i = 0; i < size; i++) {

		detetrminant *= matrix[i][i];

	}
}


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


void input_matrix(vector<vector <double>> &matrix) {
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			cin >> matrix[i][j];
		}
	}
}


void print_matrix(vector<vector <double>> matrix) {

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


bool matrix_triangle_check(vector<vector <double>>& matrix) {

	double k = matrix.size();

	for (int i = 1; i < k; i++) {

		for (int j = 0; j <= i; j++) {

			if (matrix[i][j]) return 1;
		
		}
	}

	return 0;
}


int matrix_diagonal_check(vector<vector <double>>& matrix) {

	for (int i = 0; i < matrix.size(); i++) {

		if (!(matrix[i][i])) return i;

	}
}


void matrix_line_swap(vector<vector <double>>& matrix) {

	int a, b, size = matrix.size();

	cout << "Message";

	do {
		cin >> a >> b;

	} while (!(a < size && b < size));

	a--; b--;

		for (int i = 0; i < matrix.size(); i++) {
		
			swap(matrix[i][a], matrix[i][b]);

		}	

detetrminant *= -1;

}


int main(){

	setlocale(LC_ALL, "ru");
	cin >> paramsize;



	//cout << "fefe" << endl;
	vector < vector <double> > matrix1(paramsize, vector <double>(paramsize));
	
	input_matrix(matrix1);

	



// = multiplication_matrix(a1, a2);
//vector < vector <double> > a1(n, vector <double>(n));
	





	system("pause");
}




