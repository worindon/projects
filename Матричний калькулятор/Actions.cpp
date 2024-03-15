#include "Actions.h"
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
        else if (ch == ' ') {               //�������
            indicator_off();                //�������� �������
            cerr << "\033[?25h";           //������ ����� ������� ������
            return num;                     //���������� �������
        }
    }
    // setCursorPositionInLine(41);

}
bool main_menu(Matrix& A, Matrix& B) {
       

    cout << "\t|A| have " << A.get_height() << " rows and " << A.get_width() <<" coloums" <<
            "\t|B| have " << B.get_height() << " rows and " << B.get_width() <<" coloums"<<endl;
       
                          setTextColor("green");
                          cout << "\tOperations ->->  ����������� ������� � ������" << endl;
                          cout << "\tinput sizes of |A| and |B| (rows and colums <= 6)" << endl;             //������ ������� ����
                          cout << "\tinput |A| or |B|" << endl;
                          cout << "\t|A| += |B| " << endl <<
                                  "\t|A| -= |B| " << endl <<
                                  "\t|A| *= |B|" << endl <<
                                  "\tExit" << endl;                     //��������� ������� ����
                          setTextColor("white");
                          
                            setCursorPositionAbsolute(2, 85);
                            print_two_matrix_InColumn(A, B, 'A', 'B');
    short int check = IndicatorForMenu(3, 6);

    
    restoreCursorPosition();
    int rows = 3 , cols = 3;
    switch (check){

    case 1:       
        clear(); 
        cout << "How many rows? ";
        int element;
        while (!(cin >> element)) {                                // �������� �����
            cin.clear();                                          // ����� ��������� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������ �����
        }
        if (element > 6) element = 6;
        if (element < 1) element = 1;
        rows = element;
        cout << "How many colums?";
        while (!(cin >> element)) {                                // �������� �����
            cin.clear();                                          // ����� ��������� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������ �����
        }
        if (element > 6) element = 6;
        if (element < 1) element = 1;
        cols = element;
        
        A.resize_matrix(rows, cols);
        B.resize_matrix(rows, cols);
        clear();
        return false;

    case 2:

     

    case 5:

        clear();
        cout << "You really wanna go out?  <y:n>";
        if (getAnswer('y', 'n')) {
            clear(); return true;
        }
        clear();
        return false;

    default:

        return true;
    } 
}