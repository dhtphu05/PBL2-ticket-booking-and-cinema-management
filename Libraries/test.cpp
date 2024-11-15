#include <iostream>
using namespace std;
// bool loggedIn = false;
    // if (logIn())
    // {
    //     loggedIn = true;
    // }
    // else
    // {
    //     loggedIn = false;
    // }
    // while (loggedIn)
    // {
    //     Movie movie;
    //     Staff staff;
    //     Admin admin;
    //     int choice;
    //     bool running = true;
    //     while (running)
    //     {
    //         displayMenu();
    //         cout << "Nhap lua chon: ";
    //         cin >> choice;

    //         switch (choice)
    //         {
    //         case 1:
    //             movie.addMovie();
    //             cout << "Them phim thanh cong!";
    //             Sleep(2000);
    //             system("cls");
    //             break;
    //         case 2:
    //             movie.editMovie();
    //             cout << "Sua phim thanh cong!";
    //             Sleep(2000);
    //             system("cls");
    //             break;
    //         case 3:
    //             movie.removeMovie();
    //             cout << "Xoa phim thanh cong!";
    //             Sleep(5000);
    //             system("cls");
    //             break;
    //         case 4:
    //             movie.show();
    //             Sleep(5000);
    //             system("cls");
    //             break;
    //         case 5:
    //             movie.searchMovie();
    //             Sleep(5000);
    //             system("cls");
    //             break;
    //         case 6:
    //             staff.addCustomer();
    //             cout << "Them khach hang thanh cong!";
    //             Sleep(5000);
    //             system("cls");
    //             break;
    //         case 7:
    //             staff.showCustomer();
    //             Sleep(5000);
    //             system("cls");
    //             break;
    //         case 8:
    //             staff.editCustomer();
    //             Sleep(5000);
    //             system("cls");
    //             break;
    //         case 9:
    //             admin.addStaff();
    //             cout << "Them nhan vien thanh cong!";
    //             break;
    //         case 10:
    //             admin.showStaff();
    //             break;
    //         case 11:
    //             admin.editStaff();
    //             break;
    //         case 12:
    //             admin.removeStaff();
    //             break;
    //         case 13:
    //             cout << "Dang xuat..." << endl;
    //             loggedIn = false;
    //             Sleep(2000);
    //             system("cls");
    //             main();
    //             break;

    //         default:
    //             cout << "Lua chon khong hop le!" << endl;
    //             Sleep(2000);
    //             system("cls");
    //             break;
    //         }
    //     }

    //     return 0;
    // }
void menuLogin()
{
    cout << "==========================================\n";
    cout << "|              MENU LOGIN               |\n";
    cout << "==========================================\n";
    cout << "|  1. Dang nhap                          |\n";
    cout << "------------------------------------------\n";
    cout << "|  2. Dang ky                            |\n";
    cout << "------------------------------------------\n";
    cout << "|  3. Tiep tuc voi trang thai dang xuat  |\n";
    cout << "------------------------------------------\n";
    cout << "|  4. Thoat                              |\n";
    cout << "==========================================\n";
}

//// void menuStaff()
// {
//     cout << "1. Them phim" << endl;
//     cout << "2. Sua phim" << endl;
//     cout << "3. Xoa phim" << endl;
//     cout << "4. Xem danh sach phim" << endl;
//     cout << "5. Tim kiem phim" << endl;
//     cout << "6. Them khach hang" << endl;
//     cout << "7. Xem danh sach khach hang" << endl;
//     cout << "8. Sua khach hang" << endl;
//     cout << "9. Login" << endl;
//     cout << "10. Dang xuat" << endl;
// }
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
int main(){
    cout<<"hí mọi người"<<endl;
}
