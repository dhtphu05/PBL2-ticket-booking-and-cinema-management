#include "../Include/Customer.h"
#include <fstream>
#include <sstream>
int Customer::count = 1000;
Customer::Customer(string &username, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender)
    : User(username, password, fullName, phoneNumber, DOB, gender)
{
}
Customer::Customer(string username, string password)
{
    this->password = password;
    // this->ID = count;
    // count++;
}
istream &operator>>(istream &in, Customer &customer)
{
    cout << "Nhap ten khach hang: ";
    in.ignore();
    getline(in, customer.fullName);
    cout << "Nhap so dien thoai khach hang: ";
    getline(in, customer.phoneNumber);
    cout << "Nhap ngay sinh: ";
    getline(in, customer.dateOfBirth);
    cout << "Nhap gioi tinh khach hang: ";
    getline(in, customer.gender);
    return in;
}
ostream &operator<<(ostream &out, Customer &customer)
{
    out << "-------------------" << endl;
    out << "ID: " << customer.ID << endl;
    out << "Ten: " << customer.fullName << endl;
    out << "So dien thoai: " << customer.phoneNumber << endl;
    out << "Ngay sinh: " << customer.dateOfBirth << endl;
    out << "Gioi tinh: " << customer.gender << endl;
    return out;
}
void Customer::savetoFile()
{
    DoubleLinkedList<Customer> customers;
    readID(customers);
    this->ID = count;
    this->username = "username" + to_string(count);
    ofstream out;
    out.open("../Databases/CustomerList.txt", std::ios::app);

    if (!out.is_open())
    {
        throw runtime_error("Khong the mo file");
    }
    out << this->ID << ";" << this->username << ";"
        << this->password << ";" << this->fullName << ";"
        << this->phoneNumber << ";"
        << this->dateOfBirth << ";" << this->gender << endl;
    out.close();
}

void Customer::readfromFile(DoubleLinkedList<Customer> &listCustomer)
{
    ifstream in;
    in.open("../Databases/CustomerList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }

    string line;
    // int maxID = 0;
    while (getline(in, line))
    {
        Customer m;
        stringstream ss(line);
        string idStr;
        getline(ss, idStr, ';');
        m.ID = std::stoi(idStr);
        // if (m.ID > maxID)
        // {
        //     maxID = m.ID;
        // }

        getline(ss, m.username, ';');
        getline(ss, m.password, ';');
        getline(ss, m.fullName, ';');
        getline(ss, m.phoneNumber, ';');
        getline(ss, m.dateOfBirth, ';');
        getline(ss, m.gender);

        listCustomer.push_back(m);
    }

    in.close();

    // Cập nhật count để đảm bảo ID mới không bị trùng
    // count = ++maxID;
}
void Customer::readID(DoubleLinkedList<Customer> &listCustomer)
{
    ifstream in;
    in.open("../Databases/CustomerList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }

    string line;
    int maxID = count;
    while (getline(in, line))
    {
        Customer m;
        stringstream ss(line);
        string idStr;
        getline(ss, idStr, ';');
        m.ID = std::stoi(idStr);
        if (m.ID > maxID)
        {
            maxID = m.ID;
        }

        getline(ss, m.username, ';');
        getline(ss, m.password, ';');
        getline(ss, m.fullName, ';');
        getline(ss, m.phoneNumber, ';');
        getline(ss, m.dateOfBirth, ';');
        getline(ss, m.gender);

        listCustomer.push_back(m);
    }

    in.close();

    // Cập nhật count để đảm bảo ID mới không bị trùng
    count = ++maxID;
}
void Customer::Display()
{
    cout << *this;
}
void Customer::saveAgainFile(DoubleLinkedList<Customer> &listCustomer)
{
    ofstream out;
    out.open("../Databases/CustomerList.txt");
    if (!out.is_open())
    {
        throw runtime_error("Khong the mo file");
    }
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        out << listCustomer[i].ID << ";" << listCustomer[i].username << ";" << listCustomer[i].password << ";" << listCustomer[i].fullName << ";"
            << listCustomer[i].phoneNumber << ";"
            << listCustomer[i].dateOfBirth << ";" << listCustomer[i].gender << endl;
    }
    out.close();
}