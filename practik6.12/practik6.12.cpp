#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int func1(int a) {
	if (a >= -2 and a < 2) {
		return a * a;
	}
	return 4;
}

long long func2(int x) {
	long long a = 1, b = 1;
	for (int i = 2; i <= 64; i *= 2) {
		a *= x - i;
	}
	for (int i = 1; i <= 63; i *= 2, i++) {

	}
	return a / b;
	}

double func3(int n) {
	int a = n / 100;
	int b = n % 100 / 10;
	int c = n % 10;
	if (a == 0) {
		if (b == 0) {
			return c;
		}
		else {
			return b * c;
		}
	}
	else {
		return a * b * c;
	}

}

double func4(int arr[]) { //6-сте завдання
	double res=0;
	for (int i = 0; i < 19; i++) {
		res += arr[i];
	}
	return res / 19;

}



int main()
{
	cout << "Write a, x, and n " << "\t";
	int a, x, n; cin >> a>>x>>n;
	

	

	int* arr = new int[20];
	cout << "Elements in array\t";
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "function1\t" << func1(a) << endl << "function2\t" << func2(x);
	cout << endl << "function3\t" << func3(n) << endl << "function4\t" << func4(arr);
}




