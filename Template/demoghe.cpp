#include <iostream>
#include <vector>
#include <string>
#define byte windows_byte
#include <windows.h>
#undef byte
class ColoredCinemaSeat {
private:
    // Reset code
    const std::string RESET = "\033[0m";
    
    // Text colors
    const std::string FG_WHITE = "\033[97m";    // Trắng sáng
    const std::string FG_BLACK = "\033[30m";    // Đen
    const std::string FG_YELLOW = "\033[93m";   // Vàng sáng
    
    // Background colors
    const std::string BG_GOLD = "\033[43m";     // Vàng (cho VIP)
    const std::string BG_BLUE = "\033[44m";     // Xanh dương (ghế thường)
    const std::string BG_RED = "\033[41m";      // Đỏ (đã đặt)
    const std::string BG_GRAY = "\033[100m";    // Xám (ghế trống)
    
    // Box drawing
    const std::string TOP_LEFT = "╭";
    const std::string TOP_RIGHT = "╮";
    const std::string BOTTOM_LEFT = "╰";
    const std::string BOTTOM_RIGHT = "╯";
    const std::string HORIZONTAL = "─";
    const std::string VERTICAL = "│";
    
    // Seat symbols
    const std::string SEAT_SYMBOL = "◻";

    std::vector<std::string> drawSeat(const std::string& bgColor, const std::string& fgColor) {
        std::string style = bgColor + fgColor;
        return {
            style + TOP_LEFT + HORIZONTAL + TOP_RIGHT + RESET,
            style + VERTICAL + SEAT_SYMBOL + VERTICAL + RESET,
            style + BOTTOM_LEFT + HORIZONTAL + BOTTOM_RIGHT + RESET
        };
    }

public:
    void printSeatDemo() {
        // Vẽ và in tất cả loại ghế
        std::cout << "Demo các loại ghế:\n\n";
        
        // Ghế VIP
        std::vector<std::string> vipSeat = drawSeat(BG_GOLD, FG_BLACK);
        std::cout << "Ghế VIP:\n";
        for (const auto& line : vipSeat) {
            std::cout << line << "\n";
        }
        std::cout << "\n";
        
        // Ghế thường
        std::vector<std::string> normalSeat = drawSeat(BG_BLUE, FG_WHITE);
        std::cout << "Ghế thường:\n";
        for (const auto& line : normalSeat) {
            std::cout << line << "\n";
        }
        std::cout << "\n";
        
        // Ghế đã đặt
        std::vector<std::string> occupiedSeat = drawSeat(BG_RED, FG_WHITE);
        std::cout << "Ghế đã đặt:\n";
        for (const auto& line : occupiedSeat) {
            std::cout << line << "\n";
        }
        std::cout << "\n";
        
        // Ghế trống
        std::vector<std::string> emptySeat = drawSeat(BG_GRAY, FG_WHITE);
        std::cout << "Ghế trống:\n";
        for (const auto& line : emptySeat) {
            std::cout << line << "\n";
        }
        
        // Demo hàng ghế
        std::cout << "\nMột hàng ghế mẫu:\n";
        std::cout << vipSeat[0] << " " << normalSeat[0] << " " << occupiedSeat[0] << " " << emptySeat[0] << "\n";
        std::cout << vipSeat[1] << " " << normalSeat[1] << " " << occupiedSeat[1] << " " << emptySeat[1] << "\n";
        std::cout << vipSeat[2] << " " << normalSeat[2] << " " << occupiedSeat[2] << " " << emptySeat[2] << "\n";
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    ColoredCinemaSeat cinema;
    cinema.printSeatDemo();
    return 0;
}
