﻿#include <iostream>//6
#include <vector>
using namespace std;






vector<vector<double>> func(vector<vector<double>>& vec, const int n, int m)
{

	int t = m + 1;
	int b = m + 1;
	for (b; b < n; b++) {
		double k = -1 * vec[t][m] / vec[m][m];
		for (int i = 0; i < n; i++)
		{

			vec[b][i] += k * vec[m][i];

		}
		t++;
	}



	return vec;
}




int main()


{
	int n;
	cin >> n;
	vector < vector <double> > a(n, vector <double>(n));







	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << endl << "-----------------------------------------" << endl << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------------------" << endl << endl << endl;




	int m = 0;
	for (int i = 0; i <= n; i++)
	{
		a = func(a, n, m);
		m++;
	}
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

	long  long res = a[0][0];
	for (int i = 1, j = 1; i < n; i++, j++) {
		res *= a[i][j];

	}

	cout << "det " << res << " | ";

	for (int i = 0, j = 0; i < n; i++, j++)
	{
		cout << a[i][j] << " * ";
	}

	system("pause");
}




