#include <iostream>
#include <string>
#include <string.h>

using namespace std;


//обов'язково визначте власну функцію обробки рядка
//варіант 27

void func(char* str) {
    int i, j;
    int len = strlen(str);
    for (i = 0, j = 0; i < len; ++i) {

        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

}

int main()
{

    
    char str[] = "fdssf  fdffdf sdfsf  sdfsdf"
        func(str);
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        cout << str[i];
    }

    

    return 0;
}