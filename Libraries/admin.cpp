#include "../Include/Admin.h"
Admin::Admin()
{
    // this->ID = count;
    // count++;
}
Admin::Admin(string &userName, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender)
    : Staff(userName, password, fullName, phoneNumber, DOB, gender)
{
}
void Admin::addStaff()
{
    Staff staff;
    cin >> staff;
    staff.savetoFile();
}
void subEditStaff(Staff &staff, string &line, string message)
{
    cout << message << " moi: " << endl;
    cin.ignore();
    getline(cin, line);
}
void menu()
{
    cout << "1.Ten dang nhap" << endl;
    cout << "2.Mat khau" << endl;
    cout << "3.Ho va ten" << endl;
    cout << "4.So dien thoai" << endl;
    cout << "5.Ngay sinh" << endl;
    cout << "6.Gioi tinh" << endl;
}
void Admin::editStaff()
{
    DoubleLinkedList<Staff> staffList;
    Staff staff;
    staff.readfromFile(staffList);
    int ID;
    cout << "Nhap ID: ";
    cin >> ID;
    for (int i = 0; i < staffList.getSize(); i++)
    {
        if (staffList[i].returnID() == ID)
        {
            menu();
            cout << "Chon thong tin sua: " << endl;
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                subEditStaff(staffList[i], staffList[i].getUserName(), "Ten dang nhap");
                break;
            case 2:
                subEditStaff(staffList[i], staffList[i].getPassword(), "Mat khau");
                break;
            case 3:
                subEditStaff(staffList[i], staffList[i].getFullName(), "Ho va ten");
                break;
            case 4:
                subEditStaff(staffList[i], staffList[i].getPhoneNumber(), "So dien thoai");
                break;
            case 5:
                subEditStaff(staffList[i], staffList[i].getDOB(), "Ngay sinh");
                break;
            case 6:
                subEditStaff(staffList[i], staffList[i].getGender(), "Gioi tinh");
            }
        }
    }
    staff.saveAgainFile(staffList);
}

void Admin::removeStaff()
{
    DoubleLinkedList<Staff> staffList;
    Staff staff;
    staff.readfromFile(staffList);
    string ID;
    cout << "Nhap ID: ";
    cin >> ID;
    for (int i = 0; i < staffList.getSize(); i++)
    {
        if (staffList[i].getID() == ID)
        {
            staffList.earse(i);
        }
    }
}
void Admin::showStaff()
{
    cout << "Danh sach nhan vien: " << endl;
    DoubleLinkedList<Staff> staffList;
    Staff staff;
    staff.readfromFile(staffList);
    staffList.display();
}
void Admin::savetoFile()
{
}
void Admin::readfromFile()
{
}
void Admin::saveAgainFile(DoubleLinkedList<Staff> &)
{
}
