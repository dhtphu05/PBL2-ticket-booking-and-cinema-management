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

void displayMenu()
{
    menuStaff();
}

int main()
{
    bool loggedIn = false;
    if (logIn())
    {
        loggedIn = true;
        cout << "Dang nhap thanh cong!" << endl;
    }
    else
    {
        loggedIn = false;
    }
    while (loggedIn)
    {
        Movie movie;
        Staff staff;
        Admin admin;
        int choice;
        bool running = true;
        while (running)
        {
            displayMenu();
            cout << "Nhap lua chon: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                movie.addMovie();
                cout << "Them phim thanh cong!";
                Sleep(2000);
                system("cls");
                break;
            case 2:
                movie.editMovie();
                cout << "Sua phim thanh cong!";
                Sleep(2000);
                system("cls");
                break;
            case 3:
                movie.removeMovie();
                cout << "Xoa phim thanh cong!";
                Sleep(5000);
                system("cls");
                break;
            case 4:
                movie.show();
                Sleep(5000);
                system("cls");
                break;
            case 5:
                movie.searchMovie();
                Sleep(5000);
                system("cls");
                break;
            case 6:
                staff.addCustomer();
                cout << "Them khach hang thanh cong!";
                Sleep(5000);
                system("cls");
                break;
            case 7:
                staff.showCustomer();
                Sleep(5000);
                system("cls");
                break;
            case 8:
                staff.editCustomer();
                Sleep(5000);
                system("cls");
                break;
            case 9:
                admin.addStaff();
                cout << "Them nhan vien thanh cong!";
                break;
            case 10:
                admin.showStaff();
                break;
            case 11:
                admin.editStaff();
                break;
            case 12:
                admin.removeStaff();
                break;
            case 13:
                cout << "Dang xuat..." << endl;
                loggedIn = false;
                Sleep(2000);
                system("cls");
                main();
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
                Sleep(2000);
                system("cls");
                break;
            }
        }

        return 0;
    }
}
