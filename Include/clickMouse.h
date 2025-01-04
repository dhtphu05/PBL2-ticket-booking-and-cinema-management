#include <windows.h>
#ifndef CLICKMOUSE_H
#define CLICKMOUSE_H
HANDLE hStdin;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
COORD click;
int x_click, y_click;
VOID WriteError(LPCSTR lpszMessage)
{
    printf("%s\n", lpszMessage);
    ExitProcess(0);
}
COORD processInputEvents()
{
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];

    // Get the standard input handle.
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE)
        WriteError("GetStdHandle");

    // Set the console mode
    fdwMode = ENABLE_EXTENDED_FLAGS;
    if (!SetConsoleMode(hStdin, fdwMode))
    {
        WriteError("SetConsoleMode");
    }

    // Set the console mode to accept input
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(hStdin, fdwMode))
    {
        WriteError("SetConsoleMode");
    }

    // Loop until a mouse click event is detected
    while (true)
    {
        // Peek at the event
        if (!PeekConsoleInput(hStdin, irInBuf, 128, &cNumRead))
        {
            WriteError("PeekConsoleInput");
        }
        // Process each event
        for (i = 0; i < cNumRead; i++)
        {
            if (irInBuf[i].EventType == MOUSE_EVENT &&
                irInBuf[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED &&
                irInBuf[i].Event.MouseEvent.dwEventFlags == 0) // Check if it's a click event
            {
                // Remove the event from the buffer
                INPUT_RECORD dummy;
                DWORD dummyNumRead;
                ReadConsoleInput(hStdin, &dummy, 1, &dummyNumRead);

                // Flush the console input buffer
                FlushConsoleInputBuffer(hStdin);

                return irInBuf[i].Event.MouseEvent.dwMousePosition;
            }
        }
    }
    COORD defaultCoord = {100, 100};
    return defaultCoord;
}
void getMouseClick()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
}
int click_registerCustomer()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 42 && x_click <= 120 && y_click >= 7 && y_click <= 9)
    {
        return 1;
    }
    if (x_click >= 42 && x_click <= 120 && y_click >= 9 && y_click <= 11)
    {
        return 2;
    }
    if (x_click >= 42 && x_click <= 120 && y_click >= 11 && y_click <= 13)
    {
        return 3;
    }
    if (x_click >= 42 && x_click <= 120 && y_click >= 13 && y_click <= 15)
    {
        return 4;
    }
    if (x_click >= 42 && x_click <= 120 && y_click >= 15 && y_click <= 17)
    {
        return 5;
    }
    if (x_click >= 42 && x_click <= 120 && y_click >= 17 && y_click <= 19)
    {
        return 6;
    }
    if (x_click >= 42 && x_click <= 120 && y_click >= 19 && y_click <= 21)
    {
        return 7;
    }
    return 0;
}

void getString(string &str, int x, int y)
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdin, ENABLE_PROCESSED_INPUT | ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);

    // Clear buffers
    FlushConsoleInputBuffer(hStdin);
    cin.clear();
    cin.sync();
    gotoXY(x, y);
    getline(cin, str);
}
bool isClickInRange(int xClick, int yClick, int x, int y, int width, int height)
{   
    
    if(xClick >= x && xClick <= x + width && yClick >= y && yClick <= y + height)
    {
        return true;
    }
    return false;
}
#endif