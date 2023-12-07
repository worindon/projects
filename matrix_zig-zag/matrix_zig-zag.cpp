

#include <iostream>
using namespace std;
int main()
{
	int arr[7][7];
	arr[0][6] = 1;
	int t = 2;
	int a = 1, j = 4;	
	for(int q=0; q<3;q++)
	{	
		for (int d = a, r = 6; d >= 0; t++)
		{
			arr[d][r] = t;
			d--; r--;
		}
		a+=2;
		for (int d = 0, r = j; r <= 6;t++)
		{
			arr[d][r] = t;
			d++; r++;
		}
		j-=2;
	}

	  int b = 5;
	  int i = 2;
	for(int q = 0; q<4; q++)
	{
		for (int d = 6, r = b; r >= 0; t++)
		{
			arr[d][r] = t;
			d--; r--;
		}
		b-=2;
		for (int d = i, r = 0; d <= 6; t++)
		{
			arr[d][r] = t;
			d++; r++;
		}
		i += 2;
	}



	for(int i=0; i<7; i++)
	{
		for (int j = 0; j < 7; j++)
		{

			cout <<" "<< arr[i][j];
			if (arr[i][j] < 10)
			{
				cout << " ";
			}
			
		}
		cout << endl;
	}



}

