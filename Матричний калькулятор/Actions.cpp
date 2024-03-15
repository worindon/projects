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

        setCursorPositionInLine(32);
        // cerr << "\033[2K";
    }
}

int IndicatorForMenu(int zero_line, int end_poz) {

    char ch; int num = 1;                            //чар и счетчик
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
bool main_menu(Matrix& A, Matrix& B) {
       

    cout << "\t|A| have " << A.get_height() << " rows and " << A.get_width() <<" coloums" <<
            "\t|B| have " << B.get_height() << " rows and " << B.get_width() <<" coloums"<<endl;
       
                          setTextColor("green");
                          cout << "\tOperations ->->  используйте стрелки и пробел" << endl;
                          cout << "\tinput sizes of |A| and |B| (rows and colums <= 6)" << endl;             //первая строчка меню
                          cout << "\tinput |A| or |B|" << endl;
                          cout << "\t|A| += |B| " << endl <<
                                  "\t|A| -= |B| " << endl <<
                                  "\t|A| *= |B|" << endl <<
                                  "\tExit" << endl;                     //последняя строчка меню
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
        while (!(cin >> element)) {                                // Проверка ввода
            cin.clear();                                          // Сброс состояния потока
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
        }
        if (element > 6) element = 6;
        if (element < 1) element = 1;
        rows = element;
        cout << "How many colums?";
        while (!(cin >> element)) {                                // Проверка ввода
            cin.clear();                                          // Сброс состояния потока
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
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