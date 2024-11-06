#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <windows.h>
#include "Movie.cpp"
#include "staff.cpp"
#include "admin.cpp"
#include "login.cpp"
#include "User.cpp"
using namespace std;

void menuStaff()
{
    cout << "---Quan ly---" << endl;
    cout << "1.PHIM" << endl;
    cout << "2.KHACH HANG" << endl;
    cout << "3.DANG XUAT" << endl;
}
void menuAdmin()
{
    cout << "---Quan ly---" << endl;
    cout << "1.NHAN VIEN" << endl;
    cout << "2.KHACH HANG" << endl;
    cout << "3.PHIM" << endl;
    cout << "4.DANG XUAT" << endl;
}
void menuAdmin_s()
{
    cout << "1. Them nhan vien" << endl;
    cout << "2. Xem danh sach nhan vien" << endl;
    cout << "3. Sua nhan vien" << endl;
    cout << "4. Xoa nhan vien" << endl;
    cout << "5. Thoat" << endl;
}
void menuAdmin_c()
{
    cout << "1. Them khach hang" << endl;
    cout << "2. Xem danh sach khach hang" << endl;
    cout << "3. Sua khach hang" << endl;
    cout << "4. Xoa khach hang" << endl;
    cout << "5. Thoat" << endl;
}
void menuAdmin_f()
{
    cout << "1. Them phim" << endl;
    cout << "2. Sua phim" << endl;
    cout << "3. Xoa phim" << endl;
    cout << "4. Xem danh sach phim" << endl;
    cout << "5. Tim kiem phim" << endl;
    cout << "6. Thoat" << endl;
}
int main()
{

    bool loggedIn = false;
    int log = logIn();
    if (log == 1)
    {
        loggedIn = true;
        Admin admin;
        bool running = true;
        while (loggedIn)
        {
            // bool running = true;
            while (running)
            {
                menuAdmin();
                int choice;
                cout << "Nhap lua chon: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    system("cls");
                    menuAdmin_s();
                    int choice;
                    cout << "Nhap lua chon: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        admin.addStaff();
                        cout << "Them nhan vien thanh cong!" << endl;
                        break;
                    case 2:
                        system("cls");
                        admin.showStaff();
                        break;
                    case 3:
                        system("cls");
                        admin.editStaff();
                        break;
                    case 4:
                        system("cls");
                        admin.removeStaff();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                    }
                    break;
                }
                case 2:
                {
                    system("cls");
                    int choice;
                    menuAdmin_c();
                    cout << "Nhap lua chon: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        admin.addCustomer();
                        cout << "Them khach hang thanh cong" << endl;
                        break;
                    case 2:
                        system("cls");
                        admin.showCustomer();
                        break;
                    case 3:
                        system("cls");
                        admin.editCustomer();
                        break;
                    case 4:
                        system("cls");
                        admin.removeCustomer();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                    }
                    break;
                }
                case 3:
                {
                    system("cls");
                    Movie movie;
                    int choice;
                    menuAdmin_f();
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        movie.addMovie();
                        cout << "Them phim thanh cong!";
                        break;
                    case 2:
                        system("cls");
                        movie.editMovie();
                        cout << "Sua phim thanh cong!";
                        break;
                    case 3:
                        system("cls");
                        movie.removeMovie();
                        cout << "Xoa phim thanh cong!";
                        break;
                    case 4:
                        system("cls");
                        movie.show();
                        break;
                    case 5:
                        system("cls");
                        movie.searchMovie();
                        break;
                    case 6:
                        break;
                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                    }
                    break;
                }
                case 4:
                {
                    running = false;
                    loggedIn = false;
                    main();
                    break;
                }

                break;
                }
            }
        }
    }
    else if (log == 2)
    {
        loggedIn = true;
        Staff staff;
        bool running = true;
        while (loggedIn)
        {
            // bool running = true;
            while (running)
            {
                menuStaff();
                int choice;
                cout << "Nhap lua chon: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    system("cls");
                    Movie movie;
                    int choice;
                    menuAdmin_f();
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        movie.addMovie();
                        cout << "Them phim thanh cong!";
                        break;
                    case 2:
                        system("cls");
                        movie.editMovie();
                        cout << "Sua phim thanh cong!";
                        break;
                    case 3:
                        system("cls");
                        movie.removeMovie();
                        cout << "Xoa phim thanh cong!";
                        break;
                    case 4:
                        system("cls");
                        movie.show();
                        break;
                    case 5:
                        system("cls");
                        movie.searchMovie();
                        break;
                    case 6:
                        break;
                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                    }
                    break;
                }

                case 2:
                {
                    system("cls");
                    int choice;
                    menuAdmin_c();
                    cout << "Nhap lua chon: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        staff.addCustomer();
                        cout << "Them khach hang thanh cong" << endl;
                        break;
                    case 2:
                        system("cls");
                        staff.showCustomer();
                        cout << "Nhan Enter de tiep tuc" << endl;
                        cin.ignore();
                        cin.get();
                        break;

                    case 3:
                        system("cls");
                        staff.editCustomer();
                        break;
                    case 4:
                        system("cls");
                        staff.removeCustomer();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                    }
                    break;
                }
                case 3:
                {
                    running = false;
                    loggedIn = false;
                    main();
                    break;
                }
                default:
                    cout << "Lua chon khong hop le!" << endl;
                    break;
                }
            }
        }
    }
    else if (log == 3)
    {
        main();
    }
    else if (log == 4)
    {
        cout << "Chao mung khach hang moi den voi he thong cua chung toi" << endl;
        main();
    }
}
