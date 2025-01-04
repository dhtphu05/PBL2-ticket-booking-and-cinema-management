#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#define byte windows_byte

#include <windows.h>
#undef byte

using namespace std;

// ANSI Color codes
const string RESET = "\033[0m";
const string BG_BLUE = "\033[44m";
const string BG_GREEN = "\033[42m";
const string BG_RED = "\033[41m";
const string BG_YELLOW = "\033[43m";
const string BG_CYAN = "\033[46m";
const string FG_WHITE = "\033[97m";
const string FG_BLACK = "\033[30m";

// Utility function to enable ANSI escape codes on Windows
void setupConsole() {
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    #endif
}

void printHeader() {
    cout << BG_BLUE << FG_WHITE
         << "╭────────────────── TERMINAL UI DEMO ───────────────────╮\n"
         << "│                                                       │\n"
         << "╰─────────────────────────────────────╯"
         << RESET << endl << endl;
}

void printButton(const string& text, const string& bgColor, const string& fgColor = FG_WHITE) {
    int width = 20;
    int padding = (width - text.length()) / 2;
    string spaces(padding, ' ');
    string extraSpace((width - text.length() - padding), ' ');
    
    cout << bgColor << fgColor
         << "╭" << string(width, '─') << "╮\n"
         << "│" << spaces << text << extraSpace << "│\n"
         << "╰" << string(width, '─') << "╯"
         << RESET << endl;
}

void loadingBar() {
    const int width = 40;
    cout << "\nLoading... \n";
    
    for (int i = 0; i <= width; ++i) {
        float percentage = (float)i / width * 100;
        string progress(i, '█');
        string remaining(width - i, '░');
        
        cout << "\r" << BG_BLUE << FG_WHITE 
             << "[" << progress << remaining << "] " 
             << percentage << "%" << RESET << flush;
        
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl << endl;
}

void mainDemo() {
    // Clear screen (works on most terminals)
    cout << "\033[2J\033[H";
    
    printHeader();
    
    // Menu buttons
    cout << BG_BLUE << FG_WHITE << "┌─ Main Menu ─┐" << RESET << endl << endl;
    
    printButton("LOGIN", BG_GREEN);
    cout << endl;
    
    printButton("SETTINGS", BG_CYAN);
    cout << endl;
    
    printButton("EXIT", BG_RED);
    cout << endl;
    
    // Status indicators
    cout << "\n" 
         << BG_GREEN << FG_BLACK << " ● Online " << RESET << "  "
         << BG_YELLOW << FG_BLACK << " ● Away " << RESET << "  "
         << BG_RED << FG_WHITE << " ● Offline " << RESET << endl;
    
    // Loading bar
    loadingBar();
    
    // Notifications
    cout << BG_YELLOW << FG_BLACK << "  ⚠ WARNING: System update required  " << RESET << endl
         << BG_GREEN << FG_BLACK << "  ✓ Connection secure  " << RESET << endl;
    
    cout << "\nPress Enter to exit..." << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    setupConsole();  // Setup ANSI support for Windows
    mainDemo();
    cin.get();
    return 0;
}