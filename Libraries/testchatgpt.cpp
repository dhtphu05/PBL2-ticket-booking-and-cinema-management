
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
void gotoXY(int x, int y)
{
    COORD CursorPosition;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
// int main()
// {
//     string username;
//     string password;
//     gotoXY(50, 10);
//     cout << "+-------------------------------+" << endl;
//     gotoXY(50, 11);
//     cout << "|           LOGIN                |" << endl;
//     gotoXY(50, 12);
//     cout << "+-------------------------------+" << endl;
//     gotoXY(50, 13);
//     cout << "| Username:                      + " << endl;
//     gotoXY(50, 14);
//     cout << "+-------------------------------+" << endl;
//     gotoXY(50, 15);
//     cout << "| Password:                      + " << endl;
//     gotoXY(50, 16);
//     cout << "+-------------------------------+" << endl;
//     gotoXY(62, 13);
//     gotoXY(62, 13);
//     cin >> username;
//     gotoXY(62, 15);
//     cin >> password;
//     return 0;
// // }
// #include <iostream>
// #include <windows.h>

// using namespace std;

void clearLine() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Lấy vị trí con trỏ hiện tại
    COORD cursorPosition = csbi.dwCursorPosition;

    // Di chuyển con trỏ về đầu dòng
    cursorPosition.X = 0;
    SetConsoleCursorPosition(hConsole, cursorPosition);

    // Xóa dòng
    for (int i = 0; i < csbi.dwSize.X; ++i) {
        cout << " ";
    }

    // Đưa con trỏ trở lại đầu dòng
    SetConsoleCursorPosition(hConsole, cursorPosition);
}

int main() {
    string username;
    string password;
    cout << "+-------------------------------+" << endl;
    gotoXY(50, 11);
    cout << "|           LOGIN                |" << endl;
    gotoXY(50, 12);
    cout << "+-------------------------------+" << endl;
    gotoXY(50, 13);
    cout << "| Username:                      + " << endl;
    gotoXY(50, 14);
    cout << "+-------------------------------+" << endl;
    gotoXY(50, 15);
    cout << "| Password:                      + " << endl;
    gotoXY(50, 16);
    cout << "+-------------------------------+" << endl;
    gotoXY(62, 13);
    Sleep(1000);
    gotoXY(51, 13);
    cout <<"            ";
    gotoXY(51, 13);
    cin >> username;
    gotoXY(51, 15);
    cout <<"            ";
    gotoXY(51, 15);
    cin >> password;

    return 0;
}

