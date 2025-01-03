#include "User.h"
#include "Staff.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#ifndef ADMIN_H
#define ADMIN_H
#include<regex>
#include "clickMouse.h"
class Admin : public Staff
{
    // string IDAdmin;
public:
    Admin();
    Admin(string &userName, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender);
    void addStaff();
    void editStaff();
    void removeStaff();
    void showStaff(DoubleLinkedList<Staff> &, int, int);
    void savetoFile();
    void readfromFile(DoubleLinkedList<Admin> &);
    void saveAgainFile(DoubleLinkedList<Staff> &);
    friend int logIn();
    // template <class T>
    // friend void getInf(DoubleLinkedList<T> &list, ifstream &in););
};
int getCurrentYear()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return 1900 +  localTime->tm_year;          // tm_year là số năm tính từ 1900
}
int getCurrentMonth()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return  1+localTime->tm_mon;          //
}
int getCurrentDay()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return localTime->tm_mday;          // 
}

void GotoXY(int x, int y)
{
    std::cout << "\033[" << y << ";" << x << "H";
}
void showChartAgeCustomer(DoubleLinkedList<Customer> &customer)
{
    int customerSize = customer.getSize();
    int *age = new int[customerSize];
    int Age[] = {0, 12, 18, 25, 35, 100}; // Added 100 to represent ages greater than 35
    int ageGroupCount = sizeof(Age) / sizeof(Age[0]) - 1;
    int *Count = new int[ageGroupCount]();

    for (int i = 0; i < customerSize; i++)
    {
        string year = customer[i].getDOB().substr(6, 4);
        int yearInt = stoi(year);
        int nowYear = getCurrentYear();
        age[i] = nowYear - yearInt;
    }

    // Count the number of customers in each age group
    for (int i = 0; i < ageGroupCount; i++)
    {
        for (int j = 0; j < customerSize; j++)
        {
            if (age[j] >= Age[i] && age[j] < Age[i + 1])
            {
                Count[i]++;
            }
        }
    }

    // Display the bar chart
    int maxCount = *std::max_element(Count, Count + ageGroupCount);
    int chartHeight = 10; // Height of the chart in terminal lines
    int chartWidth = 50;  // Width of the chart in terminal columns

    for (int i = chartHeight; i >= 0; i--)
    {
        GotoXY(52, 10 + (chartHeight - i));
        for (int j = 0; j < ageGroupCount; j++)
        {
            if (Count[j] > 0 && Count[j] * chartHeight / maxCount >= i)
            {
                std::cout << "\033[1;31m\u2588\u2588\u2588\u2588\u2588\u2588\033[0m"; // Unicode solid block with red color
            }
            else
            {
                std::cout << "      ";
            }
            std::cout << "   "; // Space between columns
        }
        std::cout << std::endl;
    }

    // Display the counts on top of each column
    for (int j = 0; j < ageGroupCount; j++)
    {
        if (Count[j] > 0)
        {
            GotoXY(53 + j * 9, 10 + chartHeight - (Count[j] * chartHeight / maxCount) - 1);
            std::cout << Count[j];
        }
    }

    // Display the age groups at the bottom
    GotoXY(53, 10 + chartHeight + 1);
    for (int j = 0; j < ageGroupCount; j++)
    {
        if (j == ageGroupCount - 1)
        {
            std::cout << ">" << Age[j];
        }
        else
        {
            std::cout << "" << Age[j] << "-" << Age[j + 1] << "";
        }
        std::cout << "     "; // Space between columns
    }
    std::cout << std::endl;

    // Display the horizontal line at the bottom
    GotoXY(52, 10 + chartHeight + 2);
    for (int j = 0; j < ageGroupCount; j++)
    {
        std::cout << "──────";
        std::cout << "   "; // Space between columns
    }
    std::cout << std::endl;

    // Display the chart title at the bottom
    GotoXY(56, 10 + chartHeight + 4);
    std::cout << "\033[1;34mBiểu đồ độ tuổi khách hàng\033[0m" << std::endl;

    delete[] age;
    delete[] Count;
    gotoXY(130, 5);
    cout << "❌";
    COORD choice= processInputEvents();
    while (choice.X<130||choice.X>141||choice.Y<5||choice.Y>6)
    {
        choice= processInputEvents();
    }
    system("cls");
}
bool _regexPhoneNumber(string &phone)
{
    std::regex patter(R"(^0(3|5|7|8|9)\d{8}$)");
    return std::regex_match(phone, patter) ? true : false;
}
bool _regexDOB(string &DOB)
{

    std::regex patter("\\d{2}[/]\\d{2}[/]\\d{4}");

    if (std::regex_match(DOB, patter))
    {
        string day = DOB.substr(0, 2);
        string month = DOB.substr(3, 2);
        string year = DOB.substr(6, 4);
        if (stoi(year) > getCurrentYear())
            return false;
        else if (stoi(year) == getCurrentYear())
        {
            if (stoi(month) > getCurrentMonth())
            {
                return false;
            }
            else if (stoi(month) == getCurrentMonth())
            {
                if (stoi(day) > getCurrentDay())
                {
                    return false;
                }
            }
        }
        else
        {   
            if(stoi (month)>12)
            return false;
            else {
                if(stoi(day)>31)
                return false;
            }
        }
        return true;
        
    }
    else
        return false;
}
bool _isValidPassword(const std::string &password)
{
    // Regex kiểm tra mật khẩu
    std::regex pattern("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,20}$");
    return std::regex_match(password, pattern);
}
#endif
