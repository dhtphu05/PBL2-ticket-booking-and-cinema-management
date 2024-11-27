#include <iostream>
#include <regex>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <windows.h>
#include <stdexcept>
#include "../Template/DoubleLinkedList.h"
#include "../Include/convertToUTF8.h"
#include "../Include/clickMouse.h"
#include "../Include/menu.h"
using namespace std;
int click_login()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 100 && x_click <= 125 && y_click >= 1 && y_click <= 3)
    {
        return 1;
    }
    if (x_click >= 130 && x_click <= 150 && y_click >= 1 && y_click <= 3)
    {
        return 2;
    }
}



void getPassword(string &password)
{
    char ch;
    while (true)
    {
        ch = _getch();
        if (ch == 13)
        { // Phím Enter
            break;
        }
        else if (ch == 8)
        { // Phím Backspace
            if (!password.empty())
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password += ch;
            cout << ch;
            this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\b*";
        }
    }
    cout << endl;
    // return password;
}

void readFileManagement(int i, DoubleLinkedList<Admin> &adminList, DoubleLinkedList<Staff> &staffList, DoubleLinkedList<Customer> &customerList)
{
    ifstream in;
    string line;
    if (i == 1)
    {
        in.open("../Databases/AdminList.txt");
        Admin admin;
        admin.readfromFile(adminList);
    }
    else if (i == 2)
    {
        in.open("../Databases/StaffList.txt");
        Staff staff;
        staff.readfromFile(staffList);
    }
    else if (i == 3)
    {
        in.open("../Databases/CustomerList.txt");
        Customer customer;
        customer.readfromFile(customerList);
    }

    if (!in.is_open())
    {
        throw runtime_error("Lỗi không thể mở file");
    }

    // Đọc dữ liệu từ file
}
void importMovie(DoubleLinkedList<Movie> &movie)
{
    Movie m;
    m.readFile(movie);
}
void menuLogin(string str1, string str2)
{
    menu_header(str1, str2);
    lineWidth(156, 0, 15, false, false);
    menu_middle_date_showmovie();
    DoubleLinkedList<Movie> movie;
    importMovie(movie);
    ifstream inputFile("../Databases/" + movie[1].getfileImange()); // File chứa ASCII Art đã chuyển đổi
    if (!inputFile)
    {
        cerr << "Không thể mở file ASCII!" << endl;
    }

    int startX = 3, startY = 17; // Tọa độ ban đầu
    int currentY = startY;

    string line;
    while (getline(inputFile, line))
    {
        gotoXY(startX, currentY);
        cout << line << endl;
        currentY++;
    }
    gotoXY(startX + 6, currentY + 1);
    cout << "\033[1;31m" << movie[1].getTitle() << "\033[0m" << endl;

    inputFile.close();
    inputFile.open("../Databases/" + movie[2].getfileImange());
    if (!inputFile)
    {
        cerr << "Không thể mở file ASCII!" << endl;
    }
    currentY = 17;
    while (getline(inputFile, line))
    {
        gotoXY(startX + 45, currentY);
        cout << line << endl;
        currentY++;
    }
    gotoXY(startX + 45 + 5, currentY + 1);
    cout << "\033[1;31m" << movie[2].getTitle() << "\033[0m" << endl;

    inputFile.close();
    inputFile.open("../Databases/" + movie[3].getfileImange());
    if (!inputFile)
    {
        cerr << "Không thể mở file ASCII!" << endl;
    }
    currentY = 17;
    while (getline(inputFile, line))
    {
        gotoXY(startX + 80, currentY);
        cout << line << endl;
        currentY++;
    }
    gotoXY(startX + 80 + 5, currentY + 1);
    cout << "\033[1;31m" << movie[3].getTitle() << "\033[0m" << endl;
    lineWidth(16, 127, 25, true, true);
    gotoXY(127, 26);
    cout << "│" << "\033[1;32m🎫MUA VÉ NGAY!🎫\033[0m" << "│" << endl;
    lineWidth(16, 127, 27, true, false);
}

template <class T>
bool checkUser(DoubleLinkedList<T> &list, string &userName, string &password, int &k)
{
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list[i].getUserName() == userName && list[i].getPassword() == password)
        {
            k = i;
            return true;
        }
    }
    return false;
}
string showName(string &s)
{
    return s;
}
int getclick_login()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 52 && x_click <= 93 && y_click >= 16 && y_click <= 19)
    {
        return 1;
    }
    if (x_click >= 52 && x_click <= 93 && y_click >= 18 && y_click <= 20)
    {
        return 2;
    }
    if (x_click >= 64 && x_click <= 79 && y_click >= 21 && y_click <= 23)
    {
        return 3;
    }
    if (x_click >= 66 && x_click <= 79 && y_click >= 23 && y_click <= 25)
    {
        return 4;
    }
    if(x_click >= 81 && x_click <= 90 && y_click >= 26 && y_click <= 26)
    {
        return 5;
    }
}
int logIn(DoubleLinkedList<Admin> &adminList, DoubleLinkedList<Staff> &staffList, DoubleLinkedList<Customer> &customerList, int &k)
{
    menuLogin("Đăng nhập", "Đăng kí");
    int choice = click_login();

    bool running = true;
    while (running)
    {
        switch (choice)
        {
        case 1:
        {
            system("cls");
            string userName;
            string password;
            lineWidth(41, 52, 14, true, true);
            showString("Đăng nhập", 70, 15);
            lineWidth(42, 52, 16, false, false);
            showString("Tên đăng nhập: ", 54, 17);
            lineWidth(42, 52, 18, false, false);
            showString("Mật khẩu: ", 54, 19);
            lineWidth(41, 52, 20, true, false);
            lineHeight(3, 52, 15, false, false, false);
            lineHeight(3, 94, 15, false, false, false);
            lineHeight(2, 52, 16, true, false, false);
            lineHeight(2, 94, 16, false, true, false);
            lineWidth(15, 64, 21, true, true);
            showString("🔒 Đăng nhập", 65, 22);
            lineWidth(15, 64, 23, true, false);
            lineHeight(1, 64, 22, false, false, false);
            lineHeight(1, 80, 22, false, false, false);
            gotoXY(66, 24);
            cout << "\033[4mQuên mật khẩu\033[0m" << endl;
            gotoXY(60, 26);
            cout << "Bạn chưa có tài khoản?" << "\033[4mĐăng ký\033[0m" << endl;
            gotoXY(69, 17);
            cin >> userName;
            wchar_to_utf8(userName);
            gotoXY(63, 19);
            getPassword(password);
            wchar_to_utf8(password);
            // int choice = getclick_login();
            // bool run = true;
            // while(run){
            //     switch(choice){
            //         case 1: 
            //         run = false;
            //         break;
            //         case 2:
                    
            //     }
            // }
            readFileManagement(1, adminList, staffList, customerList);
            readFileManagement(2, adminList, staffList, customerList);
            readFileManagement(3, adminList, staffList, customerList);
            gotoXY(100, 31);
            cout << adminList.getSize() << " " << staffList.getSize() << " " << customerList.getSize() << endl;
            bool run = true;
            while (run)
            {
                if (checkUser(adminList, userName, password, k))
                {
                    system("cls");
                    run = false;
                    return 1;
                }
                else if (checkUser(staffList, userName, password, k))
                {
                    gotoXY(130, 1);
                    cout << staffList[k].getFullName() << "<>" << endl;
                    run = false;
                    return 2;
                }
                else if (checkUser(customerList, userName, password, k))
                {
                    gotoXY(130, 1);
                    cout << customerList[k].getFullName() << "<>" << endl;
                    run = false;
                    return 3;
                }
                else
                {
                    cin.ignore();
                    gotoXY(50, 22);
                    cout << "Tên đăng nhập hoặc mật khẩu không đúng" << endl;
                    gotoXY(68, 17);
                    cout << "                   ";
                    gotoXY(68, 17);
                    userName = "";
                    cin >> userName;
                    wchar_to_utf8(userName);
                    gotoXY(63, 19);
                    cout << "                   ";
                    gotoXY(63, 19);
                    password = "";
                    getPassword(password);
                    wchar_to_utf8(password);
                }
            }
            break;
        }

        case 2:
        {
            Customer customer;
            system("cls");
            gotoXY(50, 4);
            cout << "Đăng ký";
            customer.resigter(customer);
            // customer.savetoFile();
            for (int i = customerList.getSize() - 1; i >= 0; i--)
            {
                customerList.earse(i);
            }
            customer.readfromFile(customerList);

            system("cls");
            return 4;
            break;
        }
        case 3:
        {
            return 5;
            break;
        }
        default:
            choice = click_login();
            break;
        }
    }
    return 0;
}
