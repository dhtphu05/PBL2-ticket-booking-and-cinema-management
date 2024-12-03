#include <iostream>
#include <vector>
#include <algorithm> // Bao gồm thư viện này để sử dụng max_element
#include <string>
#define byte windows_byte
#include <windows.h>
#undef byte

// Mã ANSI cho màu sắc
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";

// Hàm vẽ biểu đồ cột
void drawBarChart(const std::string& title, const std::vector<int>& values, const std::string& color) {
    int max_value = *std::max_element(values.begin(), values.end());
    int chart_height = max_value / 10 + 1;

    std::cout << color << title << RESET << '\n';

    for (int i = chart_height; i > 0; --i) {
        for (size_t j = 0; j < values.size(); ++j) {
            if (values[j] / 10 >= i) {
                std::cout << color << "███" << RESET;
            } else {
                std::cout << "   ";
            }
        }
        std::cout << '\n';
    }

    for (size_t j = 0; j < values.size(); ++j) {
        std::cout << "---";
    }
    std::cout << '\n';

    for (size_t j = 0; j < values.size(); ++j) {
        std::cout << color << " " << values[j] << " " << RESET;
    }
    std::cout << "\n\n";
}

int main() {
    SetConsoleOutputCP(65001);

    std::vector<int> frequency = {100, 150, 120, 180, 130};
    std::vector<int> utilization = {30, 60, 50, 70, 40};
    std::vector<int> ram = {10, 28, 72, 40, 51};

    drawBarChart("Frequency [MHz]", frequency, RED);
    drawBarChart("Utilization [%]", utilization, GREEN);
    drawBarChart("Ram [Mo]", ram, BLUE);

    return 0;
}
