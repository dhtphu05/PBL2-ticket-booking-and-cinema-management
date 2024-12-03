#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <clocale>
#define byte windows_byte
#include <windows.h>
#undef byte
using namespace std;

class TerminalLineChart {
private:
    vector<double> data;
    int width;
    int height;

    pair<double, double> getMinMax() {
        if (data.empty()) return {0, 0};
        double min_val = data[0];
        double max_val = data[0];
        for (double val : data) {
            min_val = min(min_val, val);
            max_val = max(max_val, val);
        }
        return {min_val, max_val};
    }

    int getYPosition(double value, double min_val, double max_val) {
        if (max_val == min_val) return height / 2;
        return height - 1 - static_cast<int>((value - min_val) * (height - 2) / (max_val - min_val));
    }

public:
    TerminalLineChart(int w = 50, int h = 20) : width(w), height(h) {}

    void addData(double value) {
        data.push_back(value);
    }

    void draw() {
        if (data.empty()) {
            cout << "Không có dữ liệu để vẽ!\n";
            return;
        }

        // Lấy giá trị min và max
        auto [min_val, max_val] = getMinMax();
        vector<vector<char>> chart(height, vector<char>(width, ' '));

        // Vẽ trục tọa độ
        for (int i = 0; i < height; i++) {
            chart[i][0] = '│';
        }
        for (int j = 0; j < width; j++) {
            chart[height - 1][j] = '─';
        }
        chart[height - 1][0] = '└';

        // Vẽ đường
        for (size_t i = 0; i < data.size() && i < static_cast<size_t>(width - 2); i++) {
            int y = getYPosition(data[i], min_val, max_val);
            if (y >= 0 && y < height - 1) {
                chart[y][i + 1] = '●';
                
                // Vẽ đường nối nếu có điểm tiếp theo
                if (i + 1 < data.size() && i + 1 < static_cast<size_t>(width - 2)) {
                    int next_y = getYPosition(data[i + 1], min_val, max_val);
                    if (next_y >= 0 && next_y < height - 1) {
                        // Vẽ đường nối giữa hai điểm
                        int start_y = min(y, next_y);
                        int end_y = max(y, next_y);
                        for (int j = start_y; j <= end_y; j++) {
                            if (chart[j][i + 1] == ' ') {
                                chart[j][i + 1] = '│';
                            }
                        }
                    }
                }
            }
        }

        // In biểu đồ
        cout << fixed << setprecision(1);
        
        // In giá trị max
        cout << setw(8) << max_val << " ";
        for (int j = 0; j < width; j++) cout << chart[0][j];
        cout << endl;

        // In các hàng giữa
        for (int i = 1; i < height - 1; i++) {
            if (i == height / 2) {
                cout << setw(8) << (max_val + min_val) / 2 << " ";
            } else {
                cout << "         ";
            }
            for (int j = 0; j < width; j++) {
                cout << chart[i][j];
            }
            cout << endl;
        }

        // In giá trị min và trục x
        cout << setw(8) << min_val << " ";
        for (int j = 0; j < width; j++) cout << chart[height - 1][j];
        cout << endl;

        // In chỉ số trục x
        cout << "         ";
        for (int i = 0; i < width; i += width/5) {
            cout << setw(width/5) << i;
        }
        cout << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    
    setlocale(LC_ALL, "");

    TerminalLineChart chart(50, 20);

    // Dữ liệu mẫu
    vector<double> sample_data = {1, 4, 2, 8, 5, 7, 3, 6, 9, 5, 8, 3, 7, 4, 6};
    for (double value : sample_data) {
        chart.addData(value);
    }

    cout << "\nBiểu đồ đường:\n\n";
    chart.draw();

    return 0;
}