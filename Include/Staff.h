
#include "User.h"
#include "Customer.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <regex>
#include <iostream>
using namespace std;
#ifndef STAFF_H
#define STAFF_H
class Staff : public User
{
public:
    static int countStaff;
    Staff();
    Staff(string &userName, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender);
    void addCustomer();
    void editCustomer();
    void removeCustomer();
    void showCustomer(DoubleLinkedList<Customer> &, int, int);
    void savetoFile();
    void Display();
    void readID(DoubleLinkedList<Staff> &);
    void readfromFile(DoubleLinkedList<Staff> &);
    void saveAgainFile(DoubleLinkedList<Staff> &);
    bool isIDExists(DoubleLinkedList<Customer> &, int);
    friend ostream &operator<<(ostream &out, Staff &staff);
    friend istream &operator>>(istream &in, Staff &staff);
};
int Year()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return 1900 + localTime->tm_year;          // tm_year là số năm tính từ 1900
}
int Month()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return 1 + localTime->tm_mon;              //
}
int Day()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return localTime->tm_mday;                 //
}

bool isPhone(string &phone)
{

    std::regex patter(R"(^0(3|5|7|8|9)\d{8}$)");

    return std::regex_match(phone, patter) ? true : false;
}
bool isDOB(string &DOB)
{

    std::regex patter("\\d{2}[/]\\d{2}[/]\\d{4}");

    if (std::regex_match(DOB, patter))
    {
        string day = DOB.substr(0, 2);
        string month = DOB.substr(3, 2);
        string year = DOB.substr(6, 4);
        if (stoi(year) > Year())
            return false;
        else if (stoi(year) == Year())
        {
            if (stoi(month) > Month())
            {
                return false;
            }
            else if (stoi(month) == Month())
            {
                if (stoi(day) > Day())
                {
                    return false;
                }
            }
        }
        else
        {
            if (stoi(month) > 12)
                return false;
            else
            {
                if (stoi(day) > 31)
                    return false;
            }
        }
        return true;
    }
    else
        return false;
}
bool isPassword(const std::string &password)
{
    // Regex kiểm tra mật khẩu
    std::regex pattern("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,20}$");
    return std::regex_match(password, pattern);
}
#endif