#include <windows.h>
#ifndef GOTOXY_H
#define GOTOXY_H
void gotoXY(int x, int y)
{
    COORD CursorPosition;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
#endif