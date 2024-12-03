#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#define byte windows_byte

#include <windows.h>
#undef byte
int main()
{
    SetConsoleOutputCP(65001); // Bật mã Unicode để hỗ trợ tiếng Việt và ký tự đặc biệt

    std::vector<int> ages = {16, 21, 18, 24, 30, 35, 42, 50, 60};
    std::vector<int> age_groups = {0, 18, 25, 35, 45, 60, 100};
    std::vector<int> counts(age_groups.size(), 0);

    // Phân loại khách hàng vào các nhóm tuổi
    for (int age : ages) {
        for (size_t i = 0; i < age_groups.size() - 1; ++i) {
            if (age >= age_groups[i] && age < age_groups[i + 1]) {
                counts[i]++;
                break;
            }
        }
    }

    // Tìm số lượng khách hàng lớn nhất để xác định chiều cao của biểu đồ
    int max_count = *std::max_element(counts.begin(), counts.end());

    // Hiển thị biểu đồ cột dọc với giá trị trên đầu cột
    std::vector<std::string> labels = {"<18", "18-25", "26-35", "36-45", "46-60", "60+"};
    std::string colors[] = {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m"};
    std::string reset = "\033[0m";

    std::cout << "Biểu đồ độ tuổi của khách hàng:\n\n";

    // Hiển thị giá trị trên đầu mỗi cột
    for (size_t j = 0; j < counts.size(); ++j) {
        std::cout << std::setw(4) << counts[j] << " ";
    }
    std::cout << "\n";

    // Hiển thị các cột dọc
    for (int i = max_count; i > 0; --i) {
        for (size_t j = 0; j < counts.size(); ++j) {
            if (counts[j] >= i) {
                std::cout << colors[j % 6] << "\u2588" << reset << " ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "\n";
    }

    // Hiển thị nhãn nhóm tuổi
    for (size_t i = 0; i < labels.size(); ++i) {
        std::cout << std::setw(4) << labels[i] << " ";
    }
    std::cout << "\n";

    return 0;

}
