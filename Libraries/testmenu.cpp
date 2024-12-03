#include "../Include/layout.h"
#define byte windows_byte

#include <windows.h>
#undef byte
int main()
{
    int a;
    SetConsoleOutputCP(65001);
    showString("*ADMINATOR*", 0, 0);
    lineWidth(13, 6, 2, true, true);
    showString("Nhân viên", 9, 3);
    lineWidth(13, 6, 4, true, false);
    lineHeight(1, 6, 3, false, false, false);
    lineHeight(1, 20, 3, false, false, false);
    // khung nhan vien
    showString("• Thêm nhân viên", 3, 5);
    showString("• Xóa nhân viên", 3, 6);
    showString("• Chỉnh sửa nhân viên", 3, 7);
    showString("• Xem danh sách nhân viên", 3, 8);
    // khung khach hang
    lineWidth(13, 6, 10, true, true);
    showString("Khách hàng", 8, 11);
    lineWidth(13, 6, 12, true, false);
    lineHeight(1, 6, 11, false, false, false);
    lineHeight(1, 20, 11, false, false, false);
    showString("• Thêm khách hàng", 3, 13);
    showString("• Xóa khách hàng", 3, 14);
    showString("• Chỉnh sửa khách hàng", 3, 15);
    showString("• Xem danh sách khách hàng", 3, 16);
    // khung show
    lineWidth(13, 6, 18, true, true);
    showString("Show", 11, 19);
    lineWidth(13, 6, 20, true, false);
    lineHeight(1, 6, 19, false, false, false);
    lineHeight(1, 20, 19, false, false, false);
    showString("• Thêm show", 3, 21);
    showString("• Xóa show", 3, 22);
    showString("• Chỉnh sửa show", 3, 23);
    showString("• Xem danh sách show", 3, 24);
    // khung phim
    lineWidth(13, 6, 26, true, true);
    showString("Phim", 11, 27);
    lineWidth(13, 6, 28, true, false);
    lineHeight(1, 6, 27, false, false, false);
    lineHeight(1, 20, 27, false, false, false);
    showString("• Thêm phim", 3, 29);
    showString("• Xóa phim", 3, 30);
    showString("• Chỉnh sửa phim", 3, 31);
    showString("• Xem danh sách phim", 3, 32);
    showString("• Tìm kiếm phim", 3, 33);
}
// #include <iostream>
// #include <windows.h>
// using namespace std;

// Hàm di chuyển con trỏ đến vị trí x, y

// int main() {
//     SetConsoleOutputCP(65001); // Bật mã Unicode để hỗ trợ tiếng Việt và ký tự đặc biệt

//     // Vẽ viền trên
//     gotoXY(5, 3);
//     cout << "┌───────────────┐";

//     // Vẽ nội dung với màu nền xanh và chữ trắng
//     gotoXY(5, 4);
//     cout << "│";                // Viền trái
//     cout << "\033[1;37;44m  Nhân viên   \033[0m"; // Tô nền xanh chữ trắng, vừa khít
//     cout << " │";               // Viền phải

//     // Vẽ viền dưới
//     gotoXY(5, 5);
//     cout << "└───────────────┘";

//     // Giữ màn hình để xem kết quả
//     cin.get();
//     return 0;
// }
