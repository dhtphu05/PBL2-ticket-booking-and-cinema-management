#pragma once
#include "User.h"
#include "gotoXY.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H
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
    void resigter(Customer &customer);
    void editCustomer();
    friend istream &operator>>(istream &in, Customer &customer);
    friend ostream &operator<<(ostream &out, Customer &customer);
    Customer* getCustomerByUsername(DoubleLinkedList<Customer> &customerList,string username);
};
#endif
void forchar(int n, int x, int y, char ch)
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