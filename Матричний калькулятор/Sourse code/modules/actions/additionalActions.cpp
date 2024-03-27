#include "additionalActions.h"
#include <iomanip>
//therefore

bool getAnswer(char yes, char no) {
    char ch;
    // cout << "Пожалуйста, введите 'y' или 'n': \t";
    //cerr << "\033[?25l";
    //cerr << "\033[2K";
    while (true) {

        ch = _getch();                      // Получаем следующий символ без отображения ввода  
        cout << ch;                         // Выводим символ на экран

        // Проверяем валидность ввода
        if (ch == yes) {
            return true;
        }
        else if (ch == no) {
            return false;
        }

        setCursorPositionInLine(32);
        // cerr << "\033[2K";
    }
}

int actionIndicatorForMenu(int zero_line, int end_poz) {

    char ch; short num = 1;                   //чар и счетчик
    cerr << "\033[?25l";                    //чтобы скрыть курсор
    setCursorPositionAbsolute(zero_line, 1);
    char sumb[] = ">>>";                    //чтобы красиво было

    indicator_on(sumb);                     //показываем

    while (true) {
        ch = _getch();                      // Получаем следующий символ без отображения ввода
        if (ch == 'P' && num < end_poz) {   // движение вниз
            indicator_off();                //скрываем
            setCursorPositionShiftDown(1);  //двигаемся вниз
            num++;
            indicator_on(sumb);
        }
        else if (num > 1 && ch == 'H') {    // движение вверх
            indicator_off();
            setCursorPositionShiftUp(1);
            num--;
            indicator_on(sumb);

        }
        else if (ch == '\r') {               //выбрано
            indicator_off();                 //скрываем счетчик
            cerr << "\033[?25h";             //делаем опять видимым курсор
            return num;                      //возвращаем счетчик
        }
    }
}

void actionResizeMatrix(Matrix& A, Matrix& B)
{
    clear();
    char ch;
    cout << "Rows? ";
    do {
        ch = _getch();
        cout << ch;
        setCursorPositionInLine(7);

    } while (!isdigit(ch));
    int rows = atoi(&ch);
    cout << "\n";
    cout << "Colums? ";
    do {
        ch = _getch();
        cout << ch;
        setCursorPositionInLine(9);

    } while (!isdigit(ch));
    int cols = atoi(&ch);
    if (rows > 6) rows = 6;
    if (cols > 6) cols = 6;
    if (rows < 1) rows = 1;
    if (cols < 1) cols = 1;

    A.resize_matrix(rows, cols);
   // A.resize_matrix(rows, cols);
   // B.resize_matrix(rows, cols);
    B.resize_matrix(rows, cols);
    cout << "\n";
    system("echo press any botton && pause>nul");
}

void actionInputMatrixInSerealMode(Matrix& A, Matrix& B)
{
    clear();
    cout << "Select matrix ";
    setTextColor("green");
    cout << "|A|";
    setTextColor("white");
    cout << " or ";
    cout << "|B|";

    cout << "\t(press \'e\' for exit)";
    char ch; int num = 0;
    cerr << "\033[?25l";
    while (true) {
        ch = _getch();
        if (ch == 'E' or ch == 'e') { cerr << "\033[?25h"; return; }
        if (ch == 'K' && num) {
            setCursorPositionInLine(22);
            setTextColor("white");
            cout << "|B|";
            setCursorPositionInLine(15);
            setTextColor("green");
            cout << "|A|";
            num--;
            setTextColor("white");

        }
        else if (ch == 'M' && !num) {
            setCursorPositionInLine(15);
            setTextColor("white");
            cout << "|A|";
            setCursorPositionInLine(22);
            setTextColor("green");
            cout << "|B|";
            setTextColor("white");
            num++;
        }
        if (ch == '\r') {
            cerr << "\033[?25h";
            break;
        }
    }

    switch (num)
    {
    case 0:
        clear();
        matrix_input(A);
        break;
    case 1:
        clear();
        matrix_input(B);
        break;
    }


}

void actionMatrixDeterminant(Matrix& A, Matrix& B){

    clear();
    cout << "Select matrix ";
    setTextColor("green");
    cout << "|A|";
    setTextColor("white");
    cout << " or ";
    cout << "|B|";

    cout << "\t(press \'e\' for exit)";
    char ch; int num = 0;
    cerr << "\033[?25l";
    while (true) {
        ch = _getch();
        if (ch == 'E' or ch == 'e') { cerr << "\033[?25h"; return; }
        if (ch == 'K' && num) {
            setCursorPositionInLine(22);
            setTextColor("white");
            cout << "|B|";
            setCursorPositionInLine(15);
            setTextColor("green");
            cout << "|A|";
            num--;
            setTextColor("white");

        }
        else if (ch == 'M' && !num) {
            setCursorPositionInLine(15);
            setTextColor("white");
            cout << "|A|";
            setCursorPositionInLine(22);
            setTextColor("green");
            cout << "|B|";
            setTextColor("white");
            num++;
        }
        if (ch == '\r') {
            cerr << "\033[?25h";
            break;
        }
    }

    switch (num)
    {
    case 0:
        clear();
        matrix_det(A);
        break;
    case 1:
        clear();
        matrix_det(B);
        break;
    }
}

void actionMatrixAddition(Matrix& A, Matrix& B)
{
    clear();
    print_two_matrix_non_multiplication(A, B, '+', '=');
    system("echo press any botton && pause>nul");
}

void actionMatrixSubtraction(Matrix& A, Matrix& B)
{
    clear();
    print_two_matrix_non_multiplication(A, B, '-', '=');
    system("echo press any botton && pause>nul");
}

void actionMatrixMultiplication(Matrix& A, Matrix& B)
{
    clear();
    if (A.get_width() != B.get_height()) {
        clear();
        cout << "Умножение невозможно, " <<
            "количесво строчек первой матрицы не равно количеству столбцов второй, измените матрицы на квадратные\n\n\n\n";
        system("echo press any botton && pause>nul"); return;
    }
    int widthA = A.get_width(), heigthA = A.get_height(),
        widthB = B.get_width(), heigthB = B.get_height();

    if (heigthB > heigthA) setCursorPositionShiftDown((heigthB - heigthA + 5) / 2);


    matrix_print(A);
    setCursorPositionShiftDown(heigthA);
    setCursorPositionShiftRight(widthA * 9 + 1);
    cout << " * ";


    if (heigthB >= heigthA) setCursorPositionShiftUp((heigthB * 2 + 1) / 2);
    if(heigthA > heigthB) setCursorPositionShiftUp((heigthA - heigthB) / 2);
    matrix_print(B);
    setCursorPositionShiftDown(heigthB);
    setCursorPositionShiftRight(widthB * 9 + 1);
    A *= B;
    cout << " = ";
    setCursorPositionShiftUp((A.get_height()*2 + 1) / 2);
    matrix_print(A);

    setCursorPositionShiftDown(heigthA*3);
    setCursorPositionInLine(1);
    system("echo press any botton && pause>nul");

    
}

void actionInputMatrixInManualMode(Matrix& A, Matrix& B) {
    clear();
    cout << "Select matrix ";
    setTextColor("green");
    cout << "|A|";
    setTextColor("white");
    cout << " or ";
    cout << "|B|";

    cout << "\t(press \'e\' for exit)";
    char ch; int num = 0;
    cerr << "\033[?25l";
    while (true) {
        ch = _getch();
        if (ch == 'E' or ch == 'e') { cerr << "\033[?25h"; return; }
        if (ch == 'K' && num) {
            setCursorPositionInLine(22);
            setTextColor("white");
            cout << "|B|";
            setCursorPositionInLine(15);
            setTextColor("green");
            cout << "|A|";
            num--;
            setTextColor("white");

        }
        else if (ch == 'M' && !num) {
            setCursorPositionInLine(15);
            setTextColor("white");
            cout << "|A|";
            setCursorPositionInLine(22);
            setTextColor("green");
            cout << "|B|";
            setTextColor("white");
            num++;
        }
        if (ch == '\r') {
            cerr << "\033[?25h";
            break;
        }
    }

    switch (num)
    {
    case 0:
        clear();
        matrix_input_character_by_character(A);
        break;
    case 1:
        clear();
        matrix_input_character_by_character(B);
        break;
    }

}

bool actionExit()
{
    clear();
    cout << "You really wanna go out?  <y:n>";
    if (getAnswer('y', 'n')) {
        clear(); return true;
    }
    clear();
    return false;

}