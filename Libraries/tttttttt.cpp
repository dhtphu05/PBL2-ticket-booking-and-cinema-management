#include <iostream>
#include <cmath>
#define byte windows_byte
#include <windows.h>
#undef byte
void drawUTF8PieChart(int radius) {
    // Các ký tự khác nhau để minh họa các phần của biểu đồ
    const char* chars[] = {"█", "▓", "▒", "░"};

    for (int y = -radius; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {
            double distance = std::hypot(x, y);
            if (distance <= radius) {
                // Tính góc để xác định phần của biểu đồ
                double angle = std::atan2(y, x) + M_PI;
                int section = static_cast<int>(angle / (2 * M_PI) * 4);
                std::cout << chars[section];
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    SetConsoleOutputCP(65001);

    int radius = 10;  // Bạn có thể thay đổi bán kính theo ý muốn
    drawUTF8PieChart(radius);
    return 0;
}
