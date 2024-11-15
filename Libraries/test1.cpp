#include <iostream>
#include <fstream>
using namespace std;

// int main() {
//     ofstream outFile("Movie.txt", ios::app);  // Mở file để ghi thêm dữ liệu

//     if (outFile.is_open()) {
//         outFile << "#2001\n";
//         outFile << "Ten phim: hihi\n";
//         outFile << "The loai: Hai\n";
//         outFile << "Thoi luong: 120phut\n";
//         outFile << "Ngay phat hanh: 3-5-2021\n";
//         outFile << "Dao dien: andu\n";
//         outFile << "Dien vien: hfeies\n";
//         outFile << "Nuoc san xuat: vien\n";
//         outFile << "Mo ta: hdidshiif\n";
//         outFile << "rating: 9.4\n";
//         outFile.close();
//         cout << "Dữ liệu đã được lưu vào file.\n";
//     } else {
//         cout << "Không thể mở file để ghi.\n";
//     }

//     return 0;
// }
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("MovieList.txt");

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            // Kiểm tra nếu dòng bắt đầu bằng "#", đó là ID phim
            if (line[0] == '#') {
                string id = line;
                cout << "ID phim: " << id << "\n";
            }
            else if (line.find("Ten phim:") != string::npos) {
                cout << line << "\n";
            }
            else if (line.find("The loai:") != string::npos) {
                cout << line << "\n";
            }
            else if (line.find("Thoi luong:") != string::npos) {
                cout << line << "\n";
            }
            else if (line.find("Ngay phat hanh:") != string::npos) {
                cout << line << "\n";
            }
            else if (line.find("Dao dien:") != string::npos) {
                cout << line << "\n";
            }
            else if (line.find("Dien vien:") != string::npos) {
                cout << line << "\n";
            }
            else if (line.find("Nuoc san xuat:") != string::npos) {
                cout << line << "\n";
            }
            else if (line.find("Mo ta:") != string::npos) {
                cout << line << "\n";
            }
            else if (line.find("rating:") != string::npos) {
                cout << line << "\n";
            }
        }
        inFile.close();
    } else {
        cout << "Không thể mở file để đọc.\n";
    }

    return 0;
}
