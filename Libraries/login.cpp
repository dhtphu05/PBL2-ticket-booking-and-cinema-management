#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <windows.h>
#include <stdexcept>
#include "../Template/DoubleLinkedList.h"
#include "../Include/Admin.h"
#include "../Include/Staff.h"
#include "../Include/Customer.h"
#include "../Include/gotoXY.h"

using namespace std;
// void gotoXY(int x, int y)
// {
//     COORD CursorPosition;
//     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//     CursorPosition.X = x;
//     CursorPosition.Y = y;
//     SetConsoleCursorPosition(console, CursorPosition);
// }

void menu_footer()
{
    gotoXY(0.5, 32);
    cout << "___________________________________________________________________________________________________________________________________________________________" << endl;
    gotoXY(1.5, 34);
    cout << "INTRODUCTION " << endl;
    gotoXY(1.5, 36);
    cout << "About us" << endl;
    gotoXY(1.5, 38);
    cout << "Privacy Policy" << endl;
    gotoXY(1.5, 40);
    cout << "FAQ" << endl;
    gotoXY(60, 42);
    cout << "MOVIE TICKET SALES MANAGEMENT" << endl;
    gotoXY(50, 34);
    cout << "BUY TICKET" << endl;
    gotoXY(50, 36);
    cout << "Movie Showtimes" << endl;
    gotoXY(50, 38);
    cout << "Top Movies" << endl;
    gotoXY(50, 40);
    cout << "Movie Blog" << endl;
    gotoXY(95, 34);
    cout << "SUPPORT" << endl;
    gotoXY(95, 36);
    cout << "Feedback" << endl;
    gotoXY(95, 38);
    cout << "Sales & Services" << endl;
    gotoXY(130, 34);
    cout << "FOLLOW US" << endl;
    gotoXY(130, 36);
    cout << "Facebook" << endl;
    gotoXY(130, 38);
    cout << "Hotline: 0334105228" << endl;
}
void menu_header(string message1, string message2)
{
    gotoXY(115, 1);
    cout << "+---------------+" << endl;
    gotoXY(115, 2);
    cout << "|       " << left << setw(10) << message1 << "    |" << endl;
    gotoXY(115, 3);
    cout << "+---------------+" << endl;
    gotoXY(135, 1);
    cout << "+----------------+" << endl;
    gotoXY(135, 2);
    cout << "|       " << left << setw(10) << message2 << "    |" << endl;
    gotoXY(135, 3);
    cout << "+----------------+" << endl;
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
}
void menuDate_showmovie()
{
    gotoXY(70, 11);
    cout << "+---------+" << endl;
    gotoXY(70, 12);
    cout << "|  Today  |" << endl;
    gotoXY(70, 13);
    cout << "|  21/11  |" << endl;
    gotoXY(70, 14);
    cout << "+---------+" << endl;
    gotoXY(85, 11);
    cout << "+---------+" << endl;
    gotoXY(85, 12);
    cout << "|  Friday |" << endl;
    gotoXY(85, 13);
    cout << "|  22/11  |" << endl;
    gotoXY(85, 14);
    cout << "+---------+" << endl;
    gotoXY(100, 11);
    cout << "+----------+" << endl;
    gotoXY(100, 12);
    cout << "| Saturday |" << endl;
    gotoXY(100, 13);
    cout << "|  23/11   |" << endl;
    gotoXY(100, 14);
    cout << "+----------+" << endl;
    gotoXY(115, 11);
    cout << "+---------+" << endl;
    gotoXY(115, 12);
    cout << "|  Sunday |" << endl;
    gotoXY(115, 13);
    cout << "|  24/11  |" << endl;
    gotoXY(115, 14);
    cout << "+---------+" << endl;
}

void getchar(int n, int x, int y, char ch)
{
    gotoXY(x, y);
    if (ch != ' ')
        ;
    cout << "+";
    for (int i = 0; i < n; i++)
    {
        if (ch != ' ')
        {
            gotoXY(x + 1, y);
        }
        else
            gotoXY(x, y);
        cout << ch;
        x++;
    }
    if (ch != ' ')
    {
        gotoXY(x, y);
        cout << "+";
    }
    else
        cout << "|";
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
        throw runtime_error("Error opening file");
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
    getchar(155, 0, 15, '=');
    menuDate_showmovie();
    DoubleLinkedList<Movie> movie;
    importMovie(movie);
    ifstream inputFile("../Databases/conan.txt"); // File chứa ASCII Art đã chuyển đổi
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
    inputFile.close();
    inputFile.open("../Databases/toystory.txt");
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
    inputFile.close();
    inputFile.open("../Databases/anime1.txt");
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
    gotoXY(130, 25);
    cout << "+----------------+" << endl;
    gotoXY(130, 26);
    cout << "|    3.BUY NOW!! |" << endl;
    gotoXY(130, 27);
    cout << "+----------------+" << endl;
}
template <class T>
bool checkUser(DoubleLinkedList<T> &list, string userName, string password, int &k)
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
int logIn()
{
    menuLogin("LOGIN", "REGISTER");
    int choice;
    // cout << "Please enter your choice: ";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
    {
        string userName;
        int k;
        string password;
        gotoXY(50, 10);
        cout << "+-------------------------------+" << endl;
        gotoXY(50, 11);
        cout << "|           LOGIN               |" << endl;
        gotoXY(50, 12);
        cout << "+-------------------------------+" << endl;
        gotoXY(50, 13);
        cout << "| Username:                     | " << endl;
        gotoXY(50, 14);
        cout << "+-------------------------------+" << endl;
        gotoXY(50, 15);
        cout << "| Password:                     | " << endl;
        gotoXY(50, 16);
        cout << "+-------------------------------+" << endl;
        gotoXY(62, 13);
        gotoXY(62, 13);
        cin >> userName;
        gotoXY(62, 15);

        getPassword(password);
        DoubleLinkedList<Admin> adminList;
        DoubleLinkedList<Staff> staffList;
        DoubleLinkedList<Customer> customerList;
        readFileManagement(1, adminList, staffList, customerList);
        // cout << "1 oke" << endl;
        readFileManagement(2, adminList, staffList, customerList);
        // cout << "2 ooke" << endl;
        readFileManagement(3, adminList, staffList, customerList);
        if (checkUser(adminList, userName, password, k))
        {
            system("cls");
            // cin.ignore();
            // cin.get();
            // system("cls");
            return 1;
        }
        else if (checkUser(staffList, userName, password, k))
        {
            gotoXY(130, 1);
            cout << staffList[k].getFullName() << "<>" << endl;
            return 2;
        }
        else if (checkUser(customerList, userName, password, k))
        {
            gotoXY(130, 1);
            cout << customerList[k].getFullName() << "<>" << endl;
            return 3;
        }
        else
        {
            cout << "Username or password is incorrect." << endl;
            return 0;
        }

        break;
    }

    case 2:
    {
        Customer customer;
        gotoXY(50, 4);
        cout << "-----Register------" << endl;
        customer.resigter(customer);
        customer.savetoFile();
        // system("cls");
        // menuLogin(customer.getUserName(), "Log out");
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
        cout << "Invalid choice" << endl;
        return 0;
    }
    return 0;
}
