#define NOMINMAX
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0  //
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
using namespace std;
// void forchar(int n, int x, int y, char ch)
// {
//     gotoXY(x, y);
//     if (ch != ' ')
//         ;
//     cout << "+";
//     for (int i = 0; i < n; i++)
//     {
//         if (ch != ' ')
//         {
//             gotoXY(x + 1, y);
//         }
//         else
//             gotoXY(x, y);
//         cout << ch;
//         x++;
//     }
//     if (ch != ' ')
//     {
//         gotoXY(x, y);
//         cout << "+";
//     }
//     else
//         cout << "|";
// }