#include "User.h"
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
    void savetoFile();
    void readfromFile(DoubleLinkedList<Customer> &);
    void saveAgainFile(DoubleLinkedList<Customer> &);
    void Display();
    void readID(DoubleLinkedList<Customer> &); 
    friend istream &operator>>(istream &in, Customer &customer);
    friend ostream &operator<<(ostream &out, Customer &customer);
};
#endif
