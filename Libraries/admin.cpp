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
    cout << message << " new: " << endl;
    cin.ignore();
    getline(cin, line);
}
void menu()
{
    cout << "1.Username" << endl;
    cout << "2.Password" << endl;
    cout << "3.Fullname" << endl;
    cout << "4.Phone number" << endl;
    cout << "5.Date of birth" << endl;
    cout << "6.Gender" << endl;
}
void Admin::editStaff()
{
    DoubleLinkedList<Staff> staffList;
    Staff staff;
    staff.readfromFile(staffList);
    int ID;
    cout << "Enter ID: ";
    cin >> ID;
    for (int i = 0; i < staffList.getSize(); i++)
    {
        if (staffList[i].returnID() == ID)
        {
            menu();
            cout << "Choose your choice: " << endl;
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                subEditStaff(staffList[i], staffList[i].getUserName(), "Username");
                break;
            case 2:
                subEditStaff(staffList[i], staffList[i].getPassword(), "Password");
                break;
            case 3:
                subEditStaff(staffList[i], staffList[i].getFullName(), "Fullname");
                break;
            case 4:
                subEditStaff(staffList[i], staffList[i].getPhoneNumber(), "Phone number");
                break;
            case 5:
                subEditStaff(staffList[i], staffList[i].getDOB(), "Date of birth");
                break;
            case 6:
                subEditStaff(staffList[i], staffList[i].getGender(), "Gender");
            }
        }
    }
    staff.saveAgainFile(staffList);
}

void Admin::removeStaff()
{
    DoubleLinkedList<Staff> staffList;
    bool count = false;
    Staff staff;
    staff.readfromFile(staffList);
    int ID;
    cout << "Enter ID: ";
    cin >> ID;
    for (int i = 0; i < staffList.getSize(); i++)
    {
        if (staffList[i].returnID() == ID)
        {
            staffList.earse(i);
            count = true;
        }
    }
    if (count == false)
    {
        cout << "No result!!" << endl;
    }
    else
    {
        cout << "Remove successfully!!" << endl;
    }
    staff.saveAgainFile(staffList);
}
void Admin::showStaff()
{
    cout << "List of staffs: " << endl;
    DoubleLinkedList<Staff> staffList;
    Staff staff;
    staff.readfromFile(staffList);
    staffList.display();
}
void Admin::savetoFile()
{
}
void Admin::readfromFile(DoubleLinkedList<Admin> &admins)
{

    ifstream in;
    in.open("../Databases/AdminList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }
    string line;
    Admin admin;
    while (getline(in, line))
    {
        if (!line.empty() && line[0] == '#')
        {
            admin.ID = stoi(line.substr(1));
        }
        else if (line.find("Username: ") == 0)
        {
            admin.username = mytrim(line.substr(10));
        }
        else if (line.find("Password: ") == 0)
        {
            admin.password = mytrim(line.substr(10));
        }
        else if (line.find("Fullname: ") == 0)
        {
            admin.fullName = mytrim(line.substr(10));
        }
        else if (line.find("Phone: ") == 0)
        {
            admin.phoneNumber = mytrim(line.substr(7));
        }
        else if (line.find("Date of birth: ") == 0)
        {
            admin.dateOfBirth = mytrim(line.substr(15));
        }
        else if (line.find("Gender:") == 0)
        {
            admin.gender = mytrim(line.substr(7));
            admins.push_back(admin);
            admin = Admin();
        }
    }
    in.close();
}
void Admin::saveAgainFile(DoubleLinkedList<Staff> &)
{
}
