#include <iostream>
#include <windows.h>
using namespace std;

void gotoXY(int x, int y);
void printResponsiveText(const string &text, float x_percent, float y_percent);

// Hàm gotoXY để điều chỉnh vị trí con trỏ
void gotoXY(int x, int y)
{
    COORD CursorPosition;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

int main()
{
    gotoXY(115,1);
    cout <<"+---------------+"<<endl;
    gotoXY(115,2);
    cout <<"|    Login      |" << endl;
    gotoXY(115,3);
    cout <<"+---------------+" << endl;
    gotoXY(135,1);
    cout << "+----------------+" << endl;
    gotoXY(135,2);
    cout << "|    Register    |" << endl;
    gotoXY(135,3);
    cout << "+----------------+" << endl;
}
