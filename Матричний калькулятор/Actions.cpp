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

int IndicatorForMenu(int zero_line, int end_poz) {

    char ch;int num = 1;                            //чар и счетчик
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
        else if (ch == ' ') {               //выбрано
            indicator_off();                //скрываем счетчик
            cerr << "\033[?25h";           //делаем опять видимым курсор
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



bool main_menu(Matrix& A, Matrix& B) {
       

    cout <<"\tMatrix A have sizes "<<A.get_size(1)<<" "<<A.get_size()<<
     "\tMatrix B have sizes " << B.get_size(1) << " " << B.get_size()<<"\n"
                                
                                "\tOperations ->->\n"<<
                                "\tinput sizes\n"<<
                                "\t + \n"<<
                                "\t - \n"<<
                                "\t * \n"<<
                                "\tExit\n";


    short int check = IndicatorForMenu(3, 5);

    switch (check){

    case 1:

        clear();
        int rows, cols;
        cin >> rows >> cols;
        A.resize_matrix(rows, cols);
        B = A;        
        clear();
        return false;

    case 2:

        clear();  
       
        A.input();
        clear();
        B.input();
        clear();
        A += B;
        A.print();
        system("pause");
        clear();
        return false;
        

    case 3:

        clear();
       
        A.input();
        clear();
        B.input();
        clear();
        A -= B;
        A.print();
        system("pause");
        clear();
        return false;
        

    case 4:

        clear();
       
        A.input();
        clear();
        B.input();
        clear();
        A *= B;
        A.print();
        system("pause");
        clear();
        return false;
        

    case 5:

        return true;

    default:

        return true;
    }
    
    


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