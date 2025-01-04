#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Hàm hiển thị một trang phim
void showPage(const vector<string>& movies, int currentPage, int moviesPerPage) {
    int totalPages = ceil((double)movies.size() / moviesPerPage);
    int start = (currentPage - 1) * moviesPerPage;
    int end = min(start + moviesPerPage, (int)movies.size());

    // In header
    cout << "================ DANH SACH PHIM ================" << endl;
    cout << "Trang " << currentPage << " / " << totalPages << endl;

    // Hiển thị danh sách phim trong trang hiện tại
    for (int i = start; i < end; i++) {
        cout << i + 1 << ". " << movies[i] << endl;
    }

    // In footer
    cout << "=============================" << endl;
    cout << "Nhập 'n' để tiếp, 'p' để quay lại, 'q' để thoát." << endl;
}

int main() {
    vector<string> movies = {
        "Phim 1", "Phim 2", "Phim 3", "Phim 4", "Phim 5",
        "Phim 6", "Phim 7", "Phim 8", "Phim 9", "Phim 10",
        "Phim 11"
    };

    int moviesPerPage = 5;
    int currentPage = 1;
    char command;

    while (true) {
        // Hiển thị trang hiện tại
        showPage(movies, currentPage, moviesPerPage);

        // Nhận lệnh từ người dùng
        cin >> command;
        if (command == 'n') {
            if (currentPage * moviesPerPage < movies.size()) {
                currentPage++;
            } else {
                cout << "Ban dang o trang cuoi cung!" << endl;
            }
        } else if (command == 'p') {
            if (currentPage > 1) {
                currentPage--;
            } else {
                cout << "Ban dang o trang dau tien!" << endl;
            }
        } else if (command == 'q') {
            break;
        } else {
            cout << "Lenh khong hop le, vui long nhap lai!" << endl;
        }
    }

    return 0;
}
