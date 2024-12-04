#pragma once
#include "User.h"
#include "gotoXY.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <ctime>
class Customer : public User
{
public:
static int count;
    Customer(string username = "user", string password = "12345678");
    Customer(string &ID, string &, string &, string &, string &, string &);
    void makePayment();
    void bookTicket();
    void savetoFile(bool);
    void readfromFile(DoubleLinkedList<Customer> &);
    void saveAgainFile(DoubleLinkedList<Customer> &);
    void Display();
    void readID(DoubleLinkedList<Customer> &); 
    bool resigter(Customer &customer);
    void editCustomer();
    friend istream &operator>>(istream &in, Customer &customer);
    friend ostream &operator<<(ostream &out, Customer &customer);
    Customer* getCustomerByUsername(DoubleLinkedList<Customer> &customerList,string username);
};
#endif
int getYear()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return 1900 +  localTime->tm_year;          // tm_year là số năm tính từ 1900
}
int getMonth()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return  1+localTime->tm_mon;          //
}
int getDay()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return localTime->tm_mday;          // 
}