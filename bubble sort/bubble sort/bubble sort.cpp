#include <iostream>
#include <iomanip>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int* bubbleSort(int* arr, int n) {
    bool flag;

    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
    return arr;
}


int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);





    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}