

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

void Comb_nums(int* nums, int n, int x, int y) {

    for (int i = 0; i <= n; i++) {

        nums[i] = comb(n, i) * pow(x, n - i) * pow(y, i);

    }

}

void print_pre(int x, int y, int n) {


    cout << "(";



    if (x < 0) {

        cout << "- " << -x << "a";

    }

    else if (x > 0) {
        if (x > 1) cout << x;
        cout << "a";

    }




    if (y < 0) {

        cout << " - " << -y << "b";
    }

    else if (y > 0) {

        if (x)  cout << " + ";

        if (y > 1) cout << y;

        cout << "b";

    }


    if (!x and !y) {
        cout << "0 + 0";

    }



    cout << ") ^ " << n;

    cout << " = ";

    if (!n) {
        cout << " 1 ";
    }

    else if (!x and !y) {
        cout << " 0 ";
    }


}

void print_res(int x, int y, int n, int* nums) {

    if (x or y) {
        for (int i = 0; i <= n; i++) {


            if (i and nums[i] > 0) cout << " + ";

            if (nums[i] > 1) cout << nums[i];
            else
                cout << " - " << nums[i] * (-1);

            if (i > 1) cout << "(a)^" << i;

            else if (i == 1) cout << "(a)";

            if ((n - i) > 1) cout << "(b)^" << n - i;

            else if ((n - i) == 1) cout << "(b)";
        }

    }


}



int main()
{

    int x, y, n;


    cout << endl << "\t " << "In this aplication Newton`s binom present as\t(xa + yb) ^ n" <<
        endl << " \t n must be > or = 0" << endl << endl << "\t" << " Write your \"x\"\t";  cin >> x;

    cout << endl << "\t" << " Write your \"y\"\t";      cin >> y;

    cout << endl << "\t" << " Write your \"n\"\t";      cin >> n;

    cout << endl;

    cout << endl << "\t" << "It`s -- \t ";


    print_pre(x, y, n);

    if (n > 0) {
        int* nums = new int[n];
        Comb_nums(nums, n, x, y);
        print_res(x, y, n, nums);
    }
    cout << endl << endl << endl;
    system("pause");
}
