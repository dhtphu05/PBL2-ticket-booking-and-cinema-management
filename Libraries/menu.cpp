#include <iostream>
using namespace std;

void menuLogin()
{
    cout << " ----------------------------------" << endl;
    cout << "|  1. Dang nhap                   |" << endl;
    cout << "|---------------------------------|" << endl;
    cout << "|  2. Dang ky                     |" << endl;
    cout << "|---------------------------------|" << endl;
    cout << "|  3. Tiep tuc voi trang thai dang xuat|" << endl;
    cout << "|---------------------------------|" << endl;
    cout << "|  4. Thoat                       |" << endl;
    cout << "----------------------------------" << endl;
}
void menuStaff()
{
    cout <<"Ban muon lam gi?" << endl;
    cout << "1.PHIM" << endl;
    cout << "2.KHACH HANG" << endl;
    cout << "3.DANG XUAT" << endl;
}
void menuAdmin_s(){
    cout << "1. Them nhan vien" << endl;
    cout << "2. Xem danh sach nhan vien" << endl;
    cout << "3. Sua nhan vien" << endl;
    cout << "4. Xoa nhan vien" << endl;
    cout << "5. Thoat" << endl;
}
void menuAdmin_c(){
    cout << "1. Them khach hang" << endl;
    cout << "2. Xem danh sach khach hang" << endl;
    cout << "3. Sua khach hang" << endl;
    cout << "4. Xoa khach hang" << endl;
    cout << "5. Thoat" << endl;
}
void menuAdmin()
{
    cout << "Ban muon lam gi?" << endl;
    cout << "1.NHAN VIEN" << endl;
    cout << "2.KHACH HANG" << endl;
    cout << "3.PHIM" << endl;
}
void menuCustomer()
{
    cout << "1. Xem phim" << endl;
    cout << "2. Tim phim" << endl;
    cout << "3. Dat ve" << endl;
    cout << "4. Huy ve" << endl;
    cout << "5. Thanh toan" << endl;
    cout << "6. Dang xuat" << endl;
}
void menuEditFilm()
{
    cout << "1. ID" << endl;
    cout << "2. Ten phim" << endl;
    cout << "3. The loai" << endl;
    cout << "4. Thoi luong" << endl;
    cout << "5. Ngay phat hanh" << endl;
    cout << "6. Dao dien" << endl;
    cout << "7. Dien vien" << endl;
    cout << "8. Nuoc san xuat" << endl;
    cout << "9. Mo ta" << endl;
    cout << "10. Rating" << endl;
}
void menuEditCustomer()
{
    cout << "1.ID" << endl;
    cout << "2.Ten" << endl;
    cout << "3.So dien thoai" << endl;
    cout << "4.Ngay sinh" << endl;
    cout << "5.Gioi tinh" << endl;
}
