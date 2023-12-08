

#include <iostream>
using namespace std;


void zig_zag_matrix()
{
	int arr[7][7];
	int t = 1;
	bool flag = true;
	int a = 0; int  b = 6; int k = 1;
	int d = 6; int m = 6; int e = 0;

	for (int i = 0; i < 11; i++)
	{

		for (int q = a, r = b; r <= m; q++, r++, t++)
		{
			arr[q][r] = t;
		}
		for (int q = k, r = d; q >= e; q--, r--, t++)
		{
			arr[q][r] = t;
		}
		if (flag == true) {
			b -= 2; k += 2;
		}
		else
		{
			a += 2; d -= 2;
			m -= 2; e += 2;

		}

		if (flag == true and t > 20)
		{
			d = 5; k = 6;
			b = 0; e = 1;
			flag = false;
		}


	}






	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << " ";
			if (arr[i][j] < 10)
			{
				cout << " ";
			}
			cout << arr[i][j];
		}
		cout << endl;
	}
}



int main()
{
	
	zig_zag_matrix();



}

