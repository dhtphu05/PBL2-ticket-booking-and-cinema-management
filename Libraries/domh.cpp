#include <iostream>
#include <stdio.h>
#include <windows.h>

// Khai báo các biến toàn cục
HANDLE hStdin;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

// Ghi lỗi và thoát ra
VOID WriteError(LPSTR lpszMessage)
{
    printf("%s\n", lpszMessage);
    ExitProcess(0);
}

// Hàm này cho phép di chuyển con trỏ ghi của std lên bất cứ vị trí x,y nào trên console
void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

// hàm này để lấy vị trí chuột trên std
void GetMousePosWin(MOUSE_EVENT_RECORD mer)
{
    // Khai báo các biến mà hàm cần
    int x, y;
    INPUT_RECORD Inrec;
    DWORD eventRead;
    HANDLE hStdIn;
    DWORD dwMode;
    bool Captured = false;
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    dwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

    // Kiểm tra xem console đã ở chế độ chấp nhận input từ chuột chưa
    if (SetConsoleMode(hStdIn, dwMode | ENABLE_MOUSE_INPUT) == TRUE)

        GetConsoleMode(hStdIn, &dwMode);
    SetConsoleMode(hStdIn, (dwMode & (ENABLE_MOUSE_INPUT)));

    // vòng lặp này sẽ lấy các event của trong bộ nhớ ra để xử lý
    do
    {
        PeekConsoleInput(hStdIn, &Inrec, 1, &eventRead);
        if (eventRead)
        {
            ReadConsoleInput(hStdIn, &Inrec, 1, &eventRead);
            x = Inrec.Event.MouseEvent.dwMousePosition.X;
            y = Inrec.Event.MouseEvent.dwMousePosition.Y;
            switch (Inrec.EventType)
            {

            case MOUSE_EVENT:
            {
                Captured = true;
                gotoXY(0, 0);
                std::cout << "x location  " << x << " ";
                gotoXY(0, 1);
                std::cout << "y location  " << y << " ";
                break;
            }
            }
        }

    } while (!Captured);
}

int main()
{
    SetConsoleCP(CP_UTF8);
   
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    int counter = 0;

    // Get the standard input handle.

    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE)
        WriteError("GetStdHandle");

    // Mở cửa sổ ở chế độ mở
    fdwMode = ENABLE_EXTENDED_FLAGS;
    if (!SetConsoleMode(hStdin, fdwMode))
    {
        WriteError("SetConsoleMode");
    }

    // Mở cửa sổ ở chế độ chấp nhận input

    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(hStdin, fdwMode))
    {
        WriteError("SetConsoleMode");
    }

    // Vòng lặp để quét qua các event
    while (!counter)
    {
        // đọc event vào
        if (!ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead))
        {
            WriteError("ReadConsoleInput");
        }
        // xử lý từng event một
        for (i = 0; i < cNumRead; i++)
        {
            switch (irInBuf[i].EventType)
            {
            case MOUSE_EVENT: // khi có event của chuột
                GetMousePosWin(irInBuf[i].Event.MouseEvent);
                break;
            // ngoài ra còn có event của bàn phím, của chuột
            default:
                break;
            }
        }
    }

    return 0;
}
