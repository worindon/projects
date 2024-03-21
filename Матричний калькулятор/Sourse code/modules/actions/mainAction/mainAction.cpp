#include "mainAction.h"




bool actionMain_menu(Matrix& A, Matrix& B) {

    clear();
    cout << "\t|A| have " << A.get_height() << " rows and " << A.get_width() << " coloums" <<
        "\t|B| have " << B.get_height() << " rows and " << B.get_width() << " coloums" << endl;

    setTextColor("green");
    cout << "\tOperations ->->  используйте стрелки" << endl;
    cout << "\tinput sizes of |A| and |B| (rows and colums <= 6)" << endl;//первая строчка меню
    cout << "\tinput |A| or |B| in serial mode " << endl;                  //2
    cout << "\tinput |A| or |B| in manual mode" << endl;
    cout << "\t|A| += |B| " << endl <<                                    //4
        "\t|A| -= |B| " << endl <<                                    //5
        "\t|A| *= |B|" << endl <<
        "\tdeterminant of |A| or |B|" << endl <<
        "\tExit" << endl;                                             //последняя строчка меню
    setTextColor("white");

    setCursorPositionAbsolute(2, 85);
    print_two_matrix_InColumn(A, B, 'A', 'B');

    short int check = actionIndicatorForMenu(3, 8); // в аргументах начальная строчка(абсолютная в консоли)
                                                    //  и количество пунктов меню   

    switch (check) {

    case 1:
        actionResizeMatrix(A, B);
        return false;
    case 2:
        actionInputMatrixInSerealMode(A, B);
        return false;
    case 3:
        actionInputMatrixInManualMode(A, B);
        return false;
    case 4:
        actionMatrixAddition(A, B);
        return false;
    case 5:
        actionMatrixSubtraction(A, B);
        return false;
    case 6:
        actionMatrixMultiplication(A, B);
        return false;
    case 7:
        actionSelectMatrixForDeterminant(A, B);
        return false;
    case 8:
        return actionExit();

    default:
        clear();
        system("echo Error nan ind parametr && pause"); return false;
    }
}