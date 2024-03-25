#include "ConsoleControl.h"


void setCursorPositionAbsolute(int row, int col) {


	cerr <<  "\033[" << row << ";" << col << "H";
	
	
}

void setCursorPositionInLine(int col) {

	
 	cerr <<"\033[" << col << "G";

}

void setCursorPositionShiftUp(int row) {

	ostringstream oss;
	oss << "\033[" << row << "A";
	const string ansi_sequence = oss.str();
	cerr << ansi_sequence;

}

void setCursorShiftUpOneLine() {

	cerr << "\033[A";
}

void clearOurAllLine()
{
	cerr << "\033[2K";
}

void setCursorPositionShiftDown(int row) {

	
	cerr << "\033[" << row << "B";
	
	

}

void setCursorPositionShiftRight(int offset) {
	cout << "\033[" << offset << "C";
}

void clear() {
	//cout << "\033[2J\033[1;1H";
	system("cls");
}

void setTextColor(const char color[]) {

	if (color == "black") {
		cerr << "\033[30m";
	}
	else if (color == "red") {
		cerr << "\033[31m";
	}
	else if (color == "green") {
		cerr << "\033[32m";
	}
	else if (color == "yellow") {
		cerr << "\033[33m";
	}
	else if (color == "blue") {
		cerr << "\033[34m";
	}
	else if (color == "purple") {
		cerr << "\033[35m";
	}
	else if (color == "white") {
		cerr << "\033[37m";
	}
	else cerr << "nan undefind text color";
}

void setFoneColor(const char color[]) {

	if (color == "black") {
		cerr << "\033[40m";
	}
	else if (color == "red") {
		cerr << "\033[41m";
	}
	else if (color == "green") {
		cerr << "\033[42m";
	}
	else if (color == "yellow") {
		cerr << "\033[43m";
	}
	else if (color == "blue") {
		cerr << "\033[44m";
	}
	else if (color == "purple") {
		cerr << "\033[45m";
	}
	else if (color == "white") {
		cerr << "\033[47m";
	}
	else cerr << "nan undefind fone color";
}

void setDefaultColor() {

	cerr << "\033[0m";
}

void moveCursorDown() {

	cerr << "\033[B";

}

void indicator_on(const char sumbol[]) {


	
	setCursorPositionInLine(1);
	setFoneColor("green");
	cout <<"   " << sumbol << " ";
	setCursorPositionInLine(1);
	setFoneColor("black");

}

void indicator_off() {

	setCursorPositionInLine( 1);
	//setFoneColor("black");
	cout << "       ";
	setCursorPositionInLine(1);
}

void saveCursorPosition() {
	printf("\033[s"); // ANSI escape sequence для сохранения позиции курсора
}

void restoreCursorPosition() {
	printf("\033[u"); // ANSI escape sequence для восстановления позиции курсора
}

