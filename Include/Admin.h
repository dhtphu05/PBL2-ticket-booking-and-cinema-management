#include "User.h"
#include"Staff.h"

#ifndef ADMIN_H
#define ADMIN_H
class Admin:public Staff{
    // string IDAdmin;
    public:
    Admin();
    Admin(string &userName, string&password, string &fullName, string &phoneNumber,string &DOB, string &gender);
    void addStaff();
    void editStaff();
    void removeStaff();
    void showStaff();
    void savetoFile();
    void readfromFile();
    void saveAgainFile(DoubleLinkedList<Staff>&);
    

    friend int logIn();
    // template <class T>
    // friend void getInf(DoubleLinkedList<T> &list, ifstream &in););
};
#endif