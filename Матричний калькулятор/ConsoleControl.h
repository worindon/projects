#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


void setCursorPostionAbsolute(int row, int col);
void setCursorPositionInLine(int col);
void setCursorPositionShiftUp(int row);
void setCursorPositionShiftDown(int row);
void setCursorPositionShiftRight(int offset);
void clear();
void setTextColor(const char color[]);
void setFoneColor(const char color[]);
void setDefaultColor();