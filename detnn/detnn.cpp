#include <iostream>
#include <vector>
using namespace std;






void det(vector<vector<double>>& matrix) {

	for (int r = 0; r < matrix.size(); r++) {

		for (int i = r+1; i < matrix.size(); i++) {

			double k = matrix[i][r] / matrix[r][r];

			for (int j = r; j < matrix.size(); j++) {

				matrix[i][j] -= matrix[r][j] * k;
				
			}			
		}
	}	
}


bool qwest() {

	char i;
	do {
		scanf_s("%c", &i, sizeof(i));
	} while (!(i == 'Y' || i == 'N' || i == 'y' || i == 'n'));

	if (i == 'y' || i == 'Y') return 1;
	return 0;

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

int main(){



	cout << "Write size of your square matrix and them write your numbers" << endl;
	int n;
	cin >> n;
	vector < vector <double> > a(n, vector <double>(n));



	input_matrix(a);

	cout << endl << endl << endl << endl;
	
	print_matrix(a);

	cout << endl << endl << endl << endl;
	
	det(a);
	
	
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	long  long res = 1;
	for (int i = 0, j = 0; i < n; i++, j++) {
		res *= a[i][j];

	}

	cout << "det " << res << " | ";

	for (int i = 0, j = 0; i < n; i++, j++)
	{
		cout << a[i][j];
		if (j < n - 1) {
			cout << " * ";
		}
	}
	
	cout << endl;
	system("pause");
}




