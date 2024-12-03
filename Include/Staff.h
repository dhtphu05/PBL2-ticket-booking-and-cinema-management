
#include "User.h"
#include "Customer.h"
#include <iostream>
#include <cmath>
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
#endif