#include <iostream>
#include <cmath>

using namespace std;

int factorial(int a) {
    int res = 1;
    for (int i = 1; i <= a; i++) {
        res = res * i; 
    }
    return res;
}
int comb(int n, int k) {
    return  factorial(n) / (factorial(k) * (factorial(n - k)));
}

int main()

{
    int x, y, n, k = 0;

    cout << endl << "\t " << "In this aplication Newton`s binom present as\t(xa + yb) ^ n" << endl << endl << "\t" << "Write your \"x\"\t";  cin >> x;
    cout << endl << "\t" << "Write your \"y\"\t";      cin >> y;
    cout << endl << "\t" << "Write your \"n\"\t";      cin >> n;
    if (n < 0) {
        n = -n;
    }
    cout << endl << "\t" << "It`s -- \t ";
    if (x != 0 or y != 0) {
        if (x != 0 and y != 0) {
            cout << "(";
        }
        if (x == 1) {

            cout << "a";
        }

        else if (x != 0) {
            if (x == -1) {
                cout << "-a";
            }
            else {
                cout << x << "a";
            }
        }
        if (y == 1 and x != 0) {
            cout << "+b";
        }
        else if (y == -1) {
            cout << "-b";
        }
        else {
            if (y > 0 and x != 0) {
                cout << "+" << y << "b";
            }
            else if (y < 0 and x != 0) {
                cout << "-" << -y << "b";
            }
            else if (y != 0) {
                cout << y << "b";
            }
        }
        if (x != 0 and y != 0) {
            cout << ")";
        }
        cout << "^" << n << " = ";
    }
    else {
        if (x == 0 and y == 0) {
            cout << 0;
        }
        else {
            cout << "1" << endl;
        }
    }
    int nn = n;
    int kk = k;
    if (x != 0 or y != 0) {
        if (n == 0) {
            cout << "1";
        }
        else if (x == 0 and y == 0) {
            cout << 0;
        }
        else {

            for (n, k; k != nn + 1; n--, k++) {

                if (pow(x, n) * pow(y, k) != 0) {

                    if (pow(x, n) * pow(y, k) >= 1) {

                        if (k != 0 and k != nn + 1) {


                            if (k != nn + 1 and x != 0) {
                                cout << " + ";
                            }
                            if (comb(nn, k) * pow(x, n) * pow(y, k) != 1) {


                                cout << comb(nn, k) * pow(x, n) * pow(y, k);

                            }

                        }
                        else if (pow(x, n) * pow(y, k) > 1) {
                            cout << comb(nn, k) * pow(x, n) * pow(y, k);

                        }
                    }
                    else if (pow(x, n) * pow(y, k) < 1) {
                        if (comb(nn, k) * pow(x, n) * pow(y, k) == -1) {
                            cout << " - ";
                        }
                        else {
                            cout << " - " << (-1) * (comb(nn, k) * pow(x, n) * pow(y, k));
                        }
                    }
                }
                else {
                    continue;
                }
                if (n * comb(nn, k) * pow(x, n) * pow(y, k) != 0) {
                    if (n == 1) {
                        cout << "a";
                    }
                    else {
                        cout << "(a^" << n << ")";
                    }
                }
                if (k * comb(nn, k) * pow(x, n) * pow(y, k) != 0) {
                    if (k == 1) {
                        cout << "b";
                    }
                    else {
                        cout << "(b^" << k << ")";
                    }
                }
            }
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
//bimbimbambam