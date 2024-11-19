#include "../Include/Admin.h"
#include "../Include/gotoXY.h"

#include <fstream>
#include <iomanip>
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
void menu(Staff &staff)
{
    gotoXY(40, 10);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 11);
    cout << "| 1. Fullname: " << left << setw(25) << staff.getFullName() << "                         |";
    gotoXY(40, 12);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 13);
    cout << "| 2. Phone number: " << left << setw(25) << staff.getPhoneNumber() << "                     |";
    gotoXY(40, 14);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 15);
    cout << "| 3. Date of birth: " << left << setw(25) << staff.getDOB() << "                    |";
    gotoXY(40, 16);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 17);
    cout << "| 4.Gender: " << left << setw(25) << staff.getGender() << "                            |";
    gotoXY(40, 18);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 19);
    cout << "| 5. Username: " << left << setw(25) << staff.getUserName() << "                         |";
    gotoXY(40, 20);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 21);
    cout << "| 6. Password: " << left << setw(25) << staff.getPassword() << "                         |";
    gotoXY(40, 22);
    cout << "+----------------------------------------------------------------+";
}
void Admin::editStaff()
{
    DoubleLinkedList<Staff> staffList;
    Staff staff;
    staff.readfromFile(staffList);
    int ID;
    gotoXY(50, 4);
    cout << "....Edit Staff....";
    gotoXY(50, 5);
    cout << "ID: ";
    gotoXY(50, 6);
    cout << "+-----------+" << endl;
    gotoXY(50, 7);
    cout << "|           |" << endl;
    gotoXY(50, 8);
    cout << "+-----------+" << endl;
    bool find = false;
    gotoXY(51, 7);
    cin >> ID;
    int k;
    Staff staffTemp;
    for (int i = 0; i < staffList.getSize(); i++)
    {
        if (staffList[i].returnID() == ID)
        {   
            staffTemp=staffList[i];
            k=i;
            find = true;
            menu(staffList[i]);
            // gotoXY(100, 35);
            // cout << "Choose your choice: " << endl;
            bool run = true;
            while (run)
            {
                gotoXY(0, 30);
                cout << "Choose your choice: ";

                int choice;
                cin >> choice;
                cin.ignore();
                switch (choice)
                {
                case 1:
                    gotoXY(55, 11);
                    cout << left << setw(25) << " ";
                    gotoXY(55, 11);
                    getline(cin, staffList[i].getFullName());
                    gotoXY(10, 30);
                    break;
                case 2:
                    gotoXY(59, 13);
                    cout << left << setw(25) << " ";
                    gotoXY(59, 13);
                    getline(cin, staffList[i].getPhoneNumber());
                    gotoXY(10, 30);
                    break;
                case 3:
                    gotoXY(60, 15);
                    cout << left << setw(25) << " ";
                    gotoXY(60, 15);
                    getline(cin, staffList[i].getDOB());
                    gotoXY(10, 30);
                    break;
                case 4:
                    gotoXY(52, 17);
                    cout << left << setw(25) << " ";
                    gotoXY(52, 17);
                    getline(cin, staffList[i].getGender());
                    gotoXY(10, 30);
                    break;
                case 5:
                    gotoXY(55, 19);
                    cout << left << setw(25) << " ";
                    gotoXY(55, 19);
                    getline(cin, staffList[i].getUserName());
                    gotoXY(10, 30);
                    break;
                case 6:
                    gotoXY(55, 21);
                    cout << left << setw(25) << " ";
                    gotoXY(55, 21);
                    getline(cin, staffList[i].getPassword());
                    gotoXY(10, 30);
                    break;
                default:
                    run = false;
                    break;
                }
            }
        }
    }
    if (find = false)
    {
        gotoXY(50, 10);
        cout << "No result!!" << endl;
    }
    else
    {
        gotoXY(120, 20);
        cout << "+------------------------------------+";
        gotoXY(120, 21);
        cout << "|    1. SAVE    |    2.CANCLE         |";
        gotoXY(120, 22);
        cout << "+------------------------------------+";
        gotoXY(120, 23);
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            gotoXY(130, 4);
            cout << "DONE";
        }
        else
        {
            staffList[k] = staffTemp;
        }
    staff.saveAgainFile(staffList);
    }
}

void Admin::removeStaff()
{
    DoubleLinkedList<Staff> staffList;
    bool count = false;
    Staff staff;
    staff.readfromFile(staffList);
    int ID;
    gotoXY(50, 4);
    cout << "....Remove Staff....";
    gotoXY(50, 5);
    cout << "Enter ID: ";
    gotoXY(50, 6);
    cout << "+-----------+" << endl;
    gotoXY(50, 7);
    cout << "|           |" << endl;
    gotoXY(50, 8);
    cout << "+-----------+" << endl;
    gotoXY(51, 7);
    cin >> ID;

    for (int i = 0; i < staffList.getSize(); i++)
    {
        if (staffList[i].returnID() == ID)
        {
            count = true;
            menu(staffList[i]);
            gotoXY(40, 23);
            cout << "Do you want to remove this staff?" << endl;
            gotoXY(40, 24);
            cout << "1. Yes" << endl;
            gotoXY(40, 25);
            cout << "2. No" << endl;
            int choice;
            gotoXY(40, 26);
            cout << "Choose: ";
            cin >> choice;
            if (choice == 1)
            {

                staffList.earse(i);
                gotoXY(130, 4);
                cout << "Remove successfully" << endl;
            }
            else
                break;
        }
    }
    if (count == false)
    {
        gotoXY(50, 10);
        cout << "No result!!" << endl;
    }
    staff.saveAgainFile(staffList);
}
void ForChar(int n, int x, int y, char ch)
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
void Admin::showStaff()
{

    DoubleLinkedList<Staff> staffList;
    Staff staff;
    staff.readfromFile(staffList);
    gotoXY(30, 6);
    cout << "List of staffs" << endl;
    ForChar(118, 30, 8, '-');
    gotoXY(30, 9);
    int x = 10;
    cout << "| " << left << setw(3) << "NO." << "| " << left << setw(5) << "ID" << " |" << left << setw(30) << "FullName" << "| " << left << setw(12) << "Phone" << "| " << left << setw(15) << "Date of birth" << "| " << left << setw(5) << "Gender" << "| " << left << setw(15) << "Username" << "| " << left << setw(15) << "Password" << " |";
    for (int i = 0; i < staffList.getSize(); i++)
    {
        ForChar(118, 30, x + i, '-');
        gotoXY(30, ++x + i);
        Staff staff = staffList[i];
        cout << "| " << left << setw(3) << i + 1 << "| " << left << setw(5) << staff.returnID() << " |" << left << setw(30) << staff.getFullName() << "| " << left << setw(12) << staff.getPhoneNumber() << "| " << left << setw(15) << staff.getDOB() << "| " << left << setw(5) << staff.getGender() << "| " << left << setw(15) << staff.getUserName() << "| " << left << setw(15) << staff.getPassword() << "  |";
    }
    ForChar(118, 30, x + staffList.getSize(), '-');
}
void Admin::savetoFile()
{
}
std::string Mytrim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r"); // Tìm vị trí ký tự không phải khoảng trắng
    size_t end = str.find_last_not_of(" \t\n\r");    // Tìm vị trí ký tự không phải khoảng trắng ở cuối
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
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
            admin.username = Mytrim(line.substr(10));
        }
        else if (line.find("Password: ") == 0)
        {
            admin.password = Mytrim(line.substr(10));
        }
        else if (line.find("Fullname: ") == 0)
        {
            admin.fullName = Mytrim(line.substr(10));
        }
        else if (line.find("Phone: ") == 0)
        {
            admin.phoneNumber = Mytrim(line.substr(7));
        }
        else if (line.find("Date of birth: ") == 0)
        {
            admin.dateOfBirth = Mytrim(line.substr(15));
        }
        else if (line.find("Gender:") == 0)
        {
            admin.gender = Mytrim(line.substr(7));
            admins.push_back(admin);
            admin = Admin();
        }
    }
    in.close();
}
void Admin::saveAgainFile(DoubleLinkedList<Staff> &)
{
}
