#include <iostream>
#include <string>


using namespace std;


//обов'язково визначте власну функцію обробки рядка
//варіант 27

void func(string &str) {

    int size = str.length();
    if (size < 4) return;
    char ch = str[size-1];
    str.erase(size - 1, 1);
    str.push_back(str[0]);
    str.push_back(str[1]);
    str.push_back(ch);

}

int main()
{

    
    string str;
    cout << "Введіть рядок: " << endl;
    getline(cin, str);
    func(str);   

    int len = str.length();

    for (int i = 0; i < len; i++) {

        cout << str[i];

    }

    

    return 0;
}