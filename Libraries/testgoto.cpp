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

// Hàm lấy kích thước hiện tại của console
COORD getConsoleSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &csbi);
    COORD consoleSize;
    consoleSize.X = csbi.srWindow.Right - csbi.srWindow.Left + 1; // Chiều ngang của console
    consoleSize.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Chiều dọc của console
    return consoleSize;
}

// Hàm in text theo phần trăm tọa độ
void printResponsiveText(const string &text, float x_percent, float y_percent)
{
    COORD consoleSize = getConsoleSize();                // Lấy kích thước console hiện tại
    int x = static_cast<int>(consoleSize.X * x_percent); // Tính tọa độ X
    int y = static_cast<int>(consoleSize.Y * y_percent); // Tính tọa độ Y
    gotoXY(x, y);
    cout << text;
}

int main()
{
    // Ví dụ in dòng chữ ở các vị trí tùy chỉnh (theo phần trăm)
    printResponsiveText("+------------+", 0.80f, 0.02f);  //
    printResponsiveText("|   Log in   |", 0.80f, 0.045f); //
    printResponsiveText("+------------+", 0.80f, 0.065f); //

    printResponsiveText("+------------+", 0.90f, 0.02f);  //
    printResponsiveText("|   Log up   |", 0.90f, 0.045f); //
    printResponsiveText("+------------+", 0.90f, 0.065f);
    printResponsiveText("+--------------------------------------+", 0.2f, 0.02f);
    printResponsiveText("|Search                                |", 0.2f, 0.04f);
    printResponsiveText("+--------------------------------------+", 0.2f, 0.06f);
    printResponsiveText("HINH ANH PHIM", 0.3f, 0.30f);
    printResponsiveText("+---------------+", 0.85f, 0.28f);
    printResponsiveText("|   BUY NOW!!!  |", 0.85f, 0.33f);
    printResponsiveText("+---------------+", 0.85f, 0.38f);                                                                                                                                           //
    printResponsiveText("____________________________________________________________________________________________________________________________________________________________", 0.0f, 0.70f); //
    printResponsiveText("Introduction ", 0.05f, 0.74f);
    printResponsiveText("About us", 0.05f, 0.78f); //

    gotoXY(40, 1);
    string s;
    cin >> s;            //
    system("pause>nul"); //
    return 0;
}
