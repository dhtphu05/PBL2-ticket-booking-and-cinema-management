#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <thread>
#include <stdexcept>
#include "../Template/DoubleLinkedList.h"
#include "../Include/Admin.h"
#include "../Include/Staff.h"
#include "../Include/Customer.h"
using namespace std;
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

void menuLogin()
{
    cout << "+============================================+" << endl;
    cout << "|  1. Login                                  |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "|  2. Register                               |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "|  3. Continue with logged-out status        |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "|  4. Exit                                   |" << endl;
    cout << "+============================================+" << endl;
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
