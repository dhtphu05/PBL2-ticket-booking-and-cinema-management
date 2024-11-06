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
    cout << "Mat khau: ";
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

    if (i == 1)
    {
        in.open("../Databases/AdminList.txt");
        if (!in.is_open())
        {
            throw runtime_error("Error opening file");
        }
        string line;
        while (getline(in, line))
        {
            stringstream ss(line);
            Admin m;
            string id;
            getline(ss, id, ';');
            m.setID(stoi(id));
            getline(ss, m.getUserName(), ';');
            getline(ss, m.getPassword(), ';');
            getline(ss, m.getFullName(), ';');
            getline(ss, m.getPhoneNumber(), ';');
            getline(ss, m.getDOB(), ';');
            getline(ss, m.getGender());
            adminList.push_back(m);
        }
    }
    else if (i == 2)
    {
        in.open("../Databases/StaffList.txt");
        if (!in.is_open())
        {
            throw runtime_error("Error opening file");
        }
        string line;
        while (getline(in, line))
        {
            stringstream ss(line);
            Staff m;
            string id;
            getline(ss, id, ';');
            m.setID(stoi(id));
            getline(ss, m.getUserName(), ';');
            getline(ss, m.getPassword(), ';');
            getline(ss, m.getFullName(), ';');
            getline(ss, m.getPhoneNumber(), ';');
            getline(ss, m.getDOB(), ';');
            getline(ss, m.getGender());
            staffList.push_back(m);
        }
    }
    else if (i == 3)
    {
        in.open("../Databases/CustomerList.txt");
        if (!in.is_open())
        {
            throw runtime_error("Error opening file");
        }
        string line;
        while (getline(in, line))
        {
            stringstream ss(line);
            Customer m;
            string id;
            getline(ss, id, ';');
            m.setID(stoi(id));
            getline(ss, m.getUserName(), ';');
            getline(ss, m.getPassword(), ';');
            getline(ss, m.getFullName(), ';');
            getline(ss, m.getPhoneNumber(), ';');
            getline(ss, m.getDOB(), ';');
            getline(ss, m.getGender());
            customerList.push_back(m);
        }
    }
    in.close();
}
void menuLogin()
{
    cout << "------------------------------------------" << endl;
    cout << "|  1. Dang nhap                          |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|  2. Dang ky                            |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|  3. Tiep tuc voi trang thai dang xuat  |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|  4. Thoat                              |" << endl;
    cout << "------------------------------------------" << endl;
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
bool logIn()
{
    menuLogin();
    int choice;
    cout << "Nhap lua chon: ";
    cin >> choice;
    system("cls");
    // cout << "-----------Login---------------" << endl;
    // string userName;
    // string password;
    // cout << "Ten dang nhap: ";
    // cin >> userName;
    // getPassword(password);

    // DoubleLinkedList<Admin> adminList;
    // DoubleLinkedList<Staff> staffList;
    // DoubleLinkedList<Customer> customerList;

    // // Đọc danh sách người dùng

    // bool loggedIn = false;

    // // Kiểm tra thông tin đăng nhập
    // if (choice == 1)
    // {
    //     readFileManagement(1, adminList, staffList, customerList);
    //     for (int i = 0; i < adminList.getSize(); i++)
    //     {
    //         if (adminList[i].username == userName && adminList[i].password == password)
    //         {
    //             cout << "Chao " << adminList[i].getFullName() << "!" << endl;
    //             loggedIn = true;
    //             break;
    //         }
    //     }
    // }
    // else if (choice == 2)
    // {
    //     readFileManagement(2, adminList, staffList, customerList);
    //     for (int i = 0; i < staffList.getSize(); i++)
    //     {
    //         if (staffList[i].getUserName() == userName && staffList[i].getPassword() == password)
    //         {
    //             cout << "Chao " << staffList[i].getFullName() << "!" << endl;
    //             loggedIn = true;
    //             break;
    //         }
    //     }
    // }
    // else if (choice == 3)
    // {
    //     readFileManagement(3, adminList, staffList, customerList);
    //     for (int i = 0; i < customerList.getSize(); i++)
    //     {

    //         if (customerList[i].getUserName() == userName && customerList[i].getPassword() == password)
    //         {
    //             cout << "Chao " << customerList[i].getFullName() << "!" << endl;
    //             loggedIn = true;
    //             break;
    //         }
    //     }
    // }

    // if (!loggedIn)
    // {
    //     cout << "Ten dang nhap hoac mat khau khong chinh xac." << endl;
    // }
    // return loggedIn;
    switch (choice)
    {
    case 1:
    {
        string userName;
        string password;
        cout << "Ten dang nhap: ";
        cin >> userName;
        getPassword(password);
        DoubleLinkedList<Admin> adminList;
        DoubleLinkedList<Staff> staffList;
        DoubleLinkedList<Customer> customerList;
        readFileManagement(1, adminList, staffList, customerList);
        readFileManagement(2, adminList, staffList, customerList);
        readFileManagement(3, adminList, staffList, customerList);
        if (checkUser(adminList, userName, password))
        {
            cout << "Chao " << adminList[0].getFullName() << "!" << endl;
            cout << "Ban dang dang nhap tu cach Admin" << endl;
            
        }
        else if (checkUser(staffList, userName, password))
        {
            cout << "Chao " << staffList[0].getFullName() << "!" << endl;
            cout << "Ban dang dang nhap tu cach nhan vien" << endl;
            
        }
        else if (checkUser(customerList, userName, password))
        {
            cout << "Chao " << customerList[0].getFullName() << "!" << endl;
            cout << "Ban dang dang nhap tu cach khach hang" << endl;
            
        }
        else
        {
            cout << "Ten dang nhap hoac mat khau khong chinh xac." << endl;
            
        }
        break;
    }
        // readFileManagement(1, adminList, adminList, adminList);
        // for (int i = 0; i < adminList.getSize(); i++)
        // {
        //     if (adminList[i].getUserName() == userName && adminList[i].getPassword() == password)
        //     {
        //         cout << "Chao " << adminList[i].getFullName() << "!" << endl;
        //         return true;
        //     }
        // }
        // cout << "Ten dang nhap hoac mat khau khong chinh xac." << endl;
        
    case 2:
    {
        Customer customer;
        cin>>customer;
        customer.savetoFile();
        break;






    }


    
    }
}
