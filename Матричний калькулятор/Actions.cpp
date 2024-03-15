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

int IndicatorForMenu(int zero_line, int end_poz) {

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
bool main_menu(Matrix& A, Matrix& B) {
       
    clear();
    cout << "\t|A| have " << A.get_height() << " rows and " << A.get_width() <<" coloums" <<
            "\t|B| have " << B.get_height() << " rows and " << B.get_width() <<" coloums"<<endl;
       
                          setTextColor("green");
                          cout << "\tOperations ->->  ����������� �������" << endl;
                          cout << "\tinput sizes of |A| and |B| (rows and colums <= 6)" << endl;             //������ ������� ����
                          cout << "\tinput |A| or |B|" << endl;        //2
                          cout << "\t|A| + |B| " << endl <<            //3
                                  "\t|A| - |B| " << endl <<            //4
                                  "\t|A| * |B|" << endl <<
                                  "\tExit" << endl;                     //��������� ������� ����
                          setTextColor("white");
                          
                            setCursorPositionAbsolute(2, 85);
                            print_two_matrix_InColumn(A, B, 'A', 'B');
    short int check = IndicatorForMenu(3, 6);

    
    int rows = 3, cols = 3; char ch = '*';   int num = 0; char temp1;
    switch (check){

    case 1:       
        clear();
        cout << "Rows? ";
        do {
            ch = _getch();
            cout << ch;
            setCursorPositionInLine(7);

        } while (!isdigit(ch));
        rows = atoi(&ch);
        cout << "\n";
        cout << "Colums? ";
        do {
            ch = _getch();
            cout << ch;
            setCursorPositionInLine(9);

        } while (!isdigit(ch));
        cols = atoi(&ch);
        if (rows > 6) rows = 6;
        if (cols > 6) cols = 6;
        if (rows < 1) rows = 1;
        if (cols < 1) cols = 1;

        A.resize_matrix(rows, cols);
        A.resize_matrix(rows, cols);
        B.resize_matrix(rows, cols);
        B.resize_matrix(rows, cols);
        clear();
        return false;
    case 2:
        clear();   
        cout << "Select matrix ";
        setTextColor("green");
        cout << "|A|";
        setTextColor("white");
        cout << " or ";     
        cout << "|B|";

        cout << "\t(press \'e\' for exit)";
        
        cerr << "\033[?25l"; 
        while (true) {
            ch = _getch();
            if (ch == 'E' or ch == 'e') { cerr << "\033[?25h"; return false; }
            if (ch == 'K' && num) {  
                setCursorPositionInLine(22);
                setTextColor("white");
                cout << "|B|";
                setCursorPositionInLine(15);
                setTextColor("green");
                cout << "|A|";
                num--;

            }
            else if (ch == 'M'  && !num) {    
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
            return false;
        case 1:
            clear();
            matrix_input(B);
            return false;
        }
    case 3:
        clear();
        print_two_matrix_non_multiplication(A, B, '+', '=');
        system("echo press any botton && pause");
        return false;
    case 4:
        clear();
        print_two_matrix_non_multiplication(A, B, '-', '=');
        system("echo press any botton && pause");
        return false;

    case 6:

        clear();
        cout << "You really wanna go out?  <y:n>";
        if (getAnswer('y', 'n')) {
            clear(); return true;
        }
        clear();
        return false;

    default:
        clear();
        return true;
    } 
}