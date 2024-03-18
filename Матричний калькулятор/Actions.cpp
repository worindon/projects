#include "Actions.h"
#include <iomanip>


bool getAnswer(char yes, char no) {
    char ch;
    // cout << "����������, ������� 'y' ��� 'n': \t";
    //cerr << "\033[?25l";
    //cerr << "\033[2K";
    while (true) {

        ch = _getch();                      // �������� ��������� ������ ��� ����������� �����  
        cout << ch;                         // ������� ������ �� �����

        // ��������� ���������� �����
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

    char ch; int num = 1;                            //��� � �������
    cerr << "\033[?25l";                    //����� ������ ������
    setCursorPositionAbsolute(zero_line, 1);
    char sumb[] = ">>>";                    //����� ������� ����

    indicator_on(sumb);                     //����������

    while (true) {
        ch = _getch();                      // �������� ��������� ������ ��� ����������� �����
        if (ch == 'P' && num < end_poz) {   // �������� ����
            indicator_off();                //��������
            setCursorPositionShiftDown(1);  //��������� ����
            num++;
            indicator_on(sumb);
        }
        else if (num > 1 && ch == 'H') {    // �������� �����
            indicator_off();
            setCursorPositionShiftUp(1);
            num--;
            indicator_on(sumb);

        }
        else if (ch == '\r') {               //�������
            indicator_off();                //�������� �������
            cerr << "\033[?25h";           //������ ����� ������� ������
            return num;                     //���������� �������
        }
    }
    // setCursorPositionInLine(41);

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

void actionCelectMatrixForInput(Matrix& A, Matrix& B)
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

void actionCelectMatrixForInputSeparateNumbers(Matrix& A, Matrix& B) {
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

bool actionMain_menu(Matrix& A, Matrix& B) {

    clear();
    cout << "\t|A| have " << A.get_height() << " rows and " << A.get_width() << " coloums" <<
        "\t|B| have " << B.get_height() << " rows and " << B.get_width() << " coloums" << endl;

    setTextColor("green");
    cout << "\tOperations ->->  ����������� �������" << endl;
    cout << "\tinput sizes of |A| and |B| (rows and colums <= 6)" << endl;//������ ������� ����
    cout << "\tinput |A| or |B| in serial mode "<< endl;                  //2
    cout << "\tinput |A| or |B| in manual mode" << endl;
    cout << "\t|A| += |B| " << endl <<                                    //4
            "\t|A| -= |B| " << endl <<                                    //5
            "\t|A| *= |B|" << endl <<
            "\tExit" << endl;                                             //��������� ������� ����
    setTextColor("white");

    setCursorPositionAbsolute(2, 85);
    print_two_matrix_InColumn(A, B, 'A', 'B');

    short int check = actionIndicatorForMenu(3, 7); // � ���������� ��������� �������(���������� � �������)
    //  � ���������� ������� ����   

    switch (check) {

    case 1:
        actionResizeMatrix(A, B);
        return false;
    case 2:
        actionCelectMatrixForInput(A, B);
        return false;
    case 3:
        actionCelectMatrixForInputSeparateNumbers(A, B);
        return false;
    case 4:
        actionMatrixAddition(A, B);
        return false;
    case 5:
        actionMatrixSubtraction(A, B);
        return false;
    case 6:
        if (A.get_width() != B.get_height()) {
            clear();
            cout << "��������� ����������, " <<
                "��������� ������� ������ ������� �� ����� ���������� ������� ������, �������� ������� �� ����������\n\n\n\n";
            system("echo press any botton && pause>nul"); return false;
        }
        actionMatrixMultiplication(A, B);
        return false;
    case 7:
        return actionExit();

    default:
        clear();
        system("echo Error nan ind parametr && pause"); return false;
    }
}