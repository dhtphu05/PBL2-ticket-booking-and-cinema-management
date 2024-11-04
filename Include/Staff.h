
#include "User.h"
#include "Customer.h"
#include <iostream>
using namespace std;
#ifndef STAFF_H
#define STAFF_H
class Staff : public User
{
public:
    Staff();
    Staff(string &userName, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender);
    void addCustomer();
    void editCustomer();
    void removeCustomer();
    void showCustomer();
    void savetoFile();
    void readfromFile();
    void saveAgainFile(DoubleLinkedList<Customer> &);
    bool isIDExists(DoubleLinkedList<Customer> &,int );
};
#endif