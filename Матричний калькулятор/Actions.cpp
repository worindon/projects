#include "Actions.h"



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

        setCursorPositionInLine(41);
                                            // cerr << "\033[2K";
    }
}

int getAnswerForMenu(int zero_line, int end_poz) {

    char ch;

    int num = 1;                            //счетчик

    cerr << "\033[?25l";                    //чтобы скрыть курсор

    setCursorPositionAbsolute(zero_line, 1);

    char sumb[] = ">>>";

    indicator_on(sumb);

    while (true) {
        ch = _getch();                      // Получаем следующий символ без отображения ввода
        if (ch == 'P' && num < end_poz) {   // движение вниз
            indicator_off();                //скрываем
            setCursorPositionShiftDown(1);  //двигаемся вниз
            num++;
            indicator_on(sumb);             //показываем
        }
        else if (num > 1 && ch == 'H') {    // движение вверх
            indicator_off();
            setCursorPositionShiftUp(1);
            num--;
            indicator_on(sumb);

        }
        else if (ch == ' ') {               //выбрано
            indicator_off();                //скрываем счетчик
            cerr << "\033[? 25h";           //делаем опять видимым курсор
            return num;                     //возвращаем счетчик
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

	setTextColor("green");//для работы приложения без среды может потребоваться следующая команда		

	//reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1


	Matrix A(3, 3);
	A.input();
	system("echo Нажмите любую клавишу для продолжения... && pause > nul");
	clear();
	A.print();
	cout << endl;

	A.detPrint();
    cout << endl;


}