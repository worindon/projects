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

        setCursorPositionInLine(41);
                                            // cerr << "\033[2K";
    }
}

int getAnswerForMenu(int zero_line, int end_poz) {

    char ch;

    int num = 1;                            //�������

    cerr << "\033[?25l";                    //����� ������ ������

    setCursorPositionAbsolute(zero_line, 1);

    char sumb[] = ">>>";

    indicator_on(sumb);

    while (true) {
        ch = _getch();                      // �������� ��������� ������ ��� ����������� �����
        if (ch == 'P' && num < end_poz) {   // �������� ����
            indicator_off();                //��������
            setCursorPositionShiftDown(1);  //��������� ����
            num++;
            indicator_on(sumb);             //����������
        }
        else if (num > 1 && ch == 'H') {    // �������� �����
            indicator_off();
            setCursorPositionShiftUp(1);
            num--;
            indicator_on(sumb);

        }
        else if (ch == ' ') {               //�������
            indicator_off();                //�������� �������
            cerr << "\033[? 25h";           //������ ����� ������� ������
            return num;                     //���������� �������
        }
    }
                                            // setCursorPositionInLine(41);
     
}



void menu()
{
    cerr << "\033[?25l";
    int num = 1;
    /*while (true) {
        indicatorOn(num);
        if (getAnswer('P', 'H')) {
            indicatorOff(num);
            num++;
            indicatorOn(num);
        }
        else if (num > 1) {
            indicatorOff(num);
            num--;
            indicatorOn(num);
        }

        

    }*/



}
void actionDeterminant() {

	setTextColor("green");//��� ������ ���������� ��� ����� ����� ������������� ��������� �������		

	//reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1


	Matrix A(3, 3);
	A.input();
	system("echo ������� ����� ������� ��� �����������... && pause > nul");
	clear();
	A.print();
	cout << endl;

	A.detPrint();
    cout << endl;


}