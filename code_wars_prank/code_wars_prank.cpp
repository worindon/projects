#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Erase all digits from string.
string eraseDigits1(string str) // pure function, not change str
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (isdigit(str[i]))
        {
            str.erase(i, 1);
        }
    }
    return str;
}


int main() {
    string str = "Hello, 123456789!";
    cout << eraseDigits1(str) << endl; //not change str
    cout << str << endl;

    /*char cstr[] = "Hello World!";
    //cout << eraseDigits1c(cstr) << endl; //change str

    char * result = eraseDigits3c(cstr); //not change str
    cout << result << endl;
    free (result);
    cout << cstr << endl;

    char dest[strlen(cstr) + 1];
    eraseDigits4(dest, cstr); //not change str
    cout << dest << endl;
    */
    return 0;
}