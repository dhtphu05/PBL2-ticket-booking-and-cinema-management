#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <thread>
#include <stdexcept>
#include <windows.h>
#include "../Template/DoubleLinkedList.h"
#include "../Include/Admin.h"
#include "../Include/Staff.h"
#include "../Include/Customer.h"
using namespace std;
void gotoXY(int x, int y)
{
    // Lấy handle đến console
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Tạo biến COORD để chứa tọa độ
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;

    // Thiết lập vị trí con trỏ
    SetConsoleCursorPosition(console, CursorPosition);
}

void getPassword(string &password)
{
    char ch;
    cout << "Password: ";
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
        throw runtime_error("Error opening file");
    }

    // Đọc dữ liệu từ file
}
void importMovie(DoubleLinkedList<Movie> &movie)
{
    Movie m;
    m.readFile(movie);
}
void menuLogin()
{
    DoubleLinkedList<Movie> movie;
    importMovie(movie);
    ifstream inputFile("../Databases/CONAN.txt"); // File chứa ASCII Art đã chuyển đổi
    if (!inputFile)
    {
        cerr << "Không thể mở file ASCII!" << endl;
    }

    int startX = 3, startY = 10; // Tọa độ ban đầu
    int currentY = startY;

    string line;
    gotoXY(3, 8);
    // cout << "+------------------------------------------+" << endl;
    cout <<"============================================"<<endl;
    gotoXY(3, 9);
    cout << "|                   " << movie[1].getTitle() << "                  |" << endl;
    while (getline(inputFile, line))
    {
        gotoXY(startX, currentY);
        cout << "| " << line << " |" << endl;
        currentY++;
    }
    gotoXY(3, currentY);
    // cout << "+------------------------------------------+" << endl;
    cout <<"============================================"<<endl;

    inputFile.close();
    inputFile.open("../Databases/toystory.txt");
    if (!inputFile)
    {
        cerr << "Không thể mở file ASCII!" << endl;
    }
    gotoXY(50, 8);
    // cout << "+--------------------------------+" << endl;
    cout <<"================================="<<endl;
    gotoXY(50, 9);
    cout << "|             " << movie[2].getTitle() << "          |" << endl;
    currentY = 10;
    while (getline(inputFile, line))
    {
        gotoXY(50, currentY);
        cout << "| " << line << " |" << endl;
        currentY++;
    }
    gotoXY(50, currentY);
    // cout << "+--------------------------------+" << endl;
    cout <<"================================="<<endl;

    gotoXY(115, 1);
    cout << "+---------------+" << endl;
    gotoXY(115, 2);
    cout << "|   1.Log in    |" << endl;
    gotoXY(115, 3);
    cout << "+---------------+" << endl;
    gotoXY(135, 1);
    cout << "+----------------+" << endl;
    gotoXY(135, 2);
    cout << "|    2.Register  |" << endl;
    gotoXY(135, 3);
    cout << "+----------------+" << endl;
    // gotoXY(45, 13);
    // cout << "+----------------+" << endl;
    // gotoXY(45, 14);
    // cout << "|    MOVIES      |" << endl;
    // gotoXY(45, 15);
    // cout << "+----------------+" << endl;
    gotoXY(110, 14);
    cout << "+----------------+" << endl;
    gotoXY(110, 15);
    cout << "|    3.BUY NOW!! |" << endl;
    gotoXY(110, 16);
    cout << "+----------------+" << endl;
    // gotoXY(20, 1);
    // cout << "+---------------------------------------------+" << endl;
    // gotoXY(20, 2);
    // cout << "| Search                                      |" << endl;
    // gotoXY(20, 3);
    // cout << "+---------------------------------------------+" << endl;
    gotoXY(8, 1.5);
    cout << "**************" << endl;
    gotoXY(8, 2.5);
    cout << "* BUY TICKET *" << endl;
    gotoXY(8, 3.5);
    cout << "**************" << endl;
    gotoXY(30, 2.5);
    cout << "3.Movies <>" << endl;
    gotoXY(45, 2.5);
    cout << "4.Events <>" << endl;
    gotoXY(60, 2.5);
    cout << "5.Search <>" << endl;
    gotoXY(0.5, 30);
    cout << "___________________________________________________________________________________________________________________________________________________________" << endl;
    gotoXY(1.5, 32);
    cout << "INTRODUCTION " << endl;
    gotoXY(1.5, 34);
    cout << "About us" << endl;
    gotoXY(1.5, 36);
    cout << "Privacy Policy" << endl;
    gotoXY(1.5, 38);
    cout << "FAQ" << endl;
    gotoXY(60, 40);
    cout << "MOVIE TICKET SALES MANAGEMENT" << endl;
    gotoXY(50, 32);
    cout << "BUY TICKET" << endl;
    gotoXY(50, 34);
    cout << "Movie Showtimes" << endl;
    gotoXY(50, 36);
    cout << "Top Movies" << endl;
    gotoXY(50, 38);
    cout << "Movie Blog" << endl;
    gotoXY(95, 32);
    cout << "SUPPORT" << endl;
    gotoXY(95, 34);
    cout << "Feedback" << endl;
    gotoXY(95, 36);
    cout << "Sales & Services" << endl;
    gotoXY(130, 32);
    cout << "FOLLOW US" << endl;
    gotoXY(130, 34);
    cout << "Facebook" << endl;
    gotoXY(130, 36);
    cout << "Instagram" << endl;
    gotoXY(130, 38);
    cout << "Hotline: 0334105228" << endl;
}

template <class T>
bool checkUser(DoubleLinkedList<T> &list, string userName, string password)
{
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list[i].getUserName() == userName && list[i].getPassword() == password)
        {
            return true;
        }
    }
    return false;
}
int logIn()
{
    menuLogin();
    cin.get();
    system("cls");
    int choice;
    cout << "Please enter your choice: ";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
    {
        string userName;
        string password;
        // goto(50,50);
        cout << "Username: ";
        cin >> userName;
        getPassword(password);
        DoubleLinkedList<Admin> adminList;
        DoubleLinkedList<Staff> staffList;
        DoubleLinkedList<Customer> customerList;
        readFileManagement(1, adminList, staffList, customerList);
        // cout << "1 oke" << endl;
        readFileManagement(2, adminList, staffList, customerList);
        // cout << "2 ooke" << endl;
        readFileManagement(3, adminList, staffList, customerList);
        if (checkUser(adminList, userName, password))
        {
            cout << "Hello " << adminList[0].getFullName() << "!" << endl;
            cout << "You are logged in as Admin" << endl;
            cout << " Press Enter to continue" << endl;
            cin.ignore();
            cin.get();
            system("cls");
            return 1;
        }
        else if (checkUser(staffList, userName, password))
        {
            cout << "Hello " << staffList[0].getFullName() << "!" << endl;
            cout << "You are logged in as Staff" << endl;
            return 2;
        }
        else if (checkUser(customerList, userName, password))
        {
            cout << "Hello " << customerList[0].getFullName() << "!" << endl;
            cout << "You are logged in as Customer" << endl;
            return 3;
        }
        else
        {
            cout << "Username or password is incorrect." << endl;
            return 0;
        }

        break;

        // gi
    }

    case 2:
    {
        Customer customer;
        cout << "Add new customer" << endl;
        cin >> customer;
        customer.savetoFile();
        return 4;
        break;
    }
    case 3:
    {
        return 5;
        break;
    }
    default:
        cout << "Invalid choice" << endl;
        return 0;
    }
    return 0;
}
