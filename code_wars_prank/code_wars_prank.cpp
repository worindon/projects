#include <iostream>
#include<vector>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

vector <int> absurt(vector<int> vec) {
    bool flag;
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
    return vec;
}


int ass(vector<int> &arr)
{
	if(arr.size()<=1)
	{
        return 0;
	}
    int res = 0;
    vector<int> b=absurt(arr);

    for (int i = 0;i<b.size()-1; i++)
    {
        res += b[i] - b[i + 1];
    }

    return res;
}


int main()
{

	vector<int> vec = { -3, -2, -1 };
    cout << ass(vec);
}
