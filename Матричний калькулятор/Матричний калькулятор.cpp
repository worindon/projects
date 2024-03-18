#include <windows.h>
#include "Actions.h"
int main() {
    system("chcp 1251");
    SetConsoleTitle(L"Матричный калькулятор");

    // Получаем дескриптор консольного окна
    HWND consoleWindow = GetConsoleWindow();

    // Получаем дескриптор стандартного вывода
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    // Устанавливаем размеры окна консоли
    RECT rect;
    GetWindowRect(consoleWindow, &rect);
    MoveWindow(consoleWindow, rect.left, rect.top, 1300, 600, TRUE);    
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_SIZEBOX);

    //setlocale(LC_ALL, "ru");
    Matrix A(6, 6);
    Matrix B(6, 6);
    while(!main_menu(A, B)){}
    
    return 0;
}
