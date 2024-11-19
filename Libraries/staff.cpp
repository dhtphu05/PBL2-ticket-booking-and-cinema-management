#include "../Include/Staff.h"
#include "customer.cpp"
#include <fstream>
#include <sstream>
#include "../Include/gotoXY.h"
#include <iomanip>

void menuEditCustomer(Customer &customer);
int Staff::countStaff = 3000;
Staff::Staff()
{
    // this->ID = count;
    // count++;
}
Staff::Staff(string &userName, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender)
    : User(username, password, fullName, phoneNumber, DOB, gender)
{
}
// void Staff::addCustomer()
// {
//     Customer customer;
//     cout << "Tao khach hang moi" << endl;
//     cin >> customer;
//     customer.savetoFile();
// }
void Staff::Display()
{
    int i;
    gotoXY(35, i++);
    cout << "-------------------" << endl;
    gotoXY(35, i++);
    cout << "Fullname: " << this->fullName << endl;
    gotoXY(35, i++);
    cout << "PhoneNumber: " << this->phoneNumber << endl;
    gotoXY(35, i++);
    cout << "Date of birth: " << this->dateOfBirth << endl;
    gotoXY(35, i++);
    cout << "Gender: " << this->gender << endl;
}
void Staff::addCustomer()
{
    Customer customer;
    DoubleLinkedList<Customer> listCustomer;
    customer.readfromFile(listCustomer);
    gotoXY(35, 5);
    cout << "Add new customer" << endl;
    cin >> customer;
    int newID = Customer::count + 1; // Khởi tạo ID mới bằng ID cao nhất + 1

    // Kiểm tra xem ID đã tồn tại chưa
    while (isIDExists(listCustomer, newID))
    {
        newID++; // Tăng ID cho đến khi tìm thấy ID không trùng
    }
    customer.setID(newID); // Gán ID duy nhất cho khách hàng mới

    // Lưu thông tin khách hàng vào file
    customer.savetoFile();
}

// Hàm kiểm tra ID đã tồn tại
bool Staff::isIDExists(DoubleLinkedList<Customer> &listCustomer, int id)
{
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].returnID() == id) //
        {
            return true; // ID đã tồn tại
        }
    }
    return false; // ID không tồn tại
}
void Staff::showCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    m.readfromFile(listCustomer);
    gotoXY(50, 6);
    cout << "List of customers" << endl;
    forchar(83, 50, 8, '-');
    gotoXY(50, 9);
    int x = 10;
    cout << "| " << left << setw(3) << "NO." << "| " << left << setw(5) << "ID" << " |" << left << setw(30) << "FullName" << "| " << left << setw(12) << "Phone" << "| " << left << setw(15) << "Date of birth" << "| " << left << setw(5) << "Gender" << "|";
    for (int i = 0; i < listCustomer.getSize(); i++)
    {

        forchar(83, 50, x + i, '-');
        gotoXY(50, ++x + i);
        Customer customer = listCustomer[i];
        cout << "| " << left << setw(3) << i + 1 << "| " << left << setw(5) << customer.returnID() << " |" << left << setw(30) << customer.getFullName() << "| " << left << setw(12) << customer.getPhoneNumber() << "| " << left << setw(15) << customer.getDOB() << "| " << left << setw(5) << customer.getGender() << " |";
    }
    forchar(83, 50, x + listCustomer.getSize(), '-');
}
void Staff::savetoFile()
{
    DoubleLinkedList<Staff> staffs;
    readID(staffs);        // Đọc ID của các bộ phim hiện tại để cập nhật ID mới
    this->ID = countStaff; //

    ofstream out;
    if (0)
    {
        out.open("../Databases/StaffList.txt"); // Mở file để ghi (ghi đè)
    }
    else
    {
        out.open("../Databases/StaffList.txt", std::ios::app); // Mở file để ghi thêm (append)
    }

    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }

    // Ghi thông tin bộ phim vào file với định dạng: "#ID", "Title", "Genre", "Duration", ...
    out << "#" << this->ID << endl;
    out << "Username: " << this->username << endl;
    out << "Password: " << this->password << endl;
    out << "Fullname: " << this->fullName << endl;
    out << "Phone: " << this->phoneNumber << endl;
    out << "Date of birth: " << this->dateOfBirth << endl;
    out << "Gender: " << this->gender << endl;
    out.close();
}
void Staff::saveAgainFile(DoubleLinkedList<Staff> &staffs)
{
    ofstream out;
    out.open("../Databases/StaffList.txt"); // Mở file để ghi (ghi đè)
    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }
    for (int i = 0; i < staffs.getSize(); i++)
    {
        // Ghi thông tin bộ phim vào file với định dạng: "#ID", "Title", "Genre", "Duration", ...
        out << "#" << staffs[i].ID << endl;
        out << "Username: " << staffs[i].username << endl;
        out << "Password: " << staffs[i].password << endl;
        out << "Fullname: " << staffs[i].fullName << endl;
        out << "Phone: " << staffs[i].phoneNumber << endl;
        out << "Date of birth: " << staffs[i].dateOfBirth << endl;
        out << "Gender: " << staffs[i].gender << endl;
        out << endl;
    }
    out.close();
}
std::string mytrim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r"); // Tìm vị trí ký tự không phải khoảng trắng
    size_t end = str.find_last_not_of(" \t\n\r");    // Tìm vị trí ký tự không phải khoảng trắng ở cuối
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
void Staff::readfromFile(DoubleLinkedList<Staff> &staffs)
{
    ifstream in;
    in.open("../Databases/StaffList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }
    string line;
    Staff staff;
    while (getline(in, line))
    {
        if (!line.empty() && line[0] == '#')
        {
            staff.ID = stoi(line.substr(1));
        }
        else if (line.find("Username: ") == 0)
        {
            staff.username = mytrim(line.substr(10));
        }
        else if (line.find("Password: ") == 0)
        {
            staff.password = mytrim(line.substr(10));
        }
        else if (line.find("Fullname: ") == 0)
        {
            staff.fullName = mytrim(line.substr(10));
        }
        else if (line.find("Phone: ") == 0)
        {
            staff.phoneNumber = mytrim(line.substr(7));
        }
        else if (line.find("Date of birth: ") == 0)
        {
            staff.dateOfBirth = mytrim(line.substr(15));
        }
        else if (line.find("Gender:") == 0)
        {
            staff.gender = mytrim(line.substr(7));
            staffs.push_back(staff);
            staff = Staff();
        }
    }
    in.close();
}
void Staff::readID(DoubleLinkedList<Staff> &staffs)
{
    int is_read = false;
    ifstream in;
    in.open("../Databases/StaffList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }

    string line;
    int maxID = countStaff;
    while (getline(in, line))
    {
        if (line.substr(0, 1) == "#")
        {
            is_read = true;
            Staff staff;
            stringstream ss;
            ss.str(line);
            string idtemp;
            getline(ss, idtemp, ' ');
            staff.ID = stoi(idtemp.substr(1));
            if (staff.ID > maxID)
            {
                maxID = staff.ID;
            }
        }
    }
    in.close();
    countStaff = ++maxID;
}

void Staff::editCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    int count = false;
    m.readfromFile(listCustomer);
    int ID;
    gotoXY(50, 4);
    cout << "....Edit Customer....";
    gotoXY(50, 5);
    cout << "ID: ";
    gotoXY(50, 6);
    cout << "+-----------+" << endl;
    gotoXY(50, 7);
    cout << "|           |" << endl;
    gotoXY(50, 8);
    cout << "+-----------+" << endl;
    gotoXY(51, 7);
    cin >> ID;
    Customer customerTemp;
    int k;
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].returnID() == ID)
        {
            k = i;
            customerTemp = listCustomer[i];
            count = true;
            menuEditCustomer(listCustomer[i]);
            bool run = true;
            while (run)
            {
                gotoXY(0, 30);
                cout << "Choose your choice: ";
                int choice;
                cin >> choice;
                string temp;
                cin.ignore();
                switch (choice)
                {
                case 1:
                    gotoXY(55, 11);
                    cout << left << setw(25) << " ";
                    gotoXY(55, 11);
                    getline(cin, temp);
                    listCustomer[i].setFullName(temp);
                    gotoXY(10, 30);
                    break;
                case 2:
                    gotoXY(59, 13);
                    cout << left << setw(25) << " ";
                    gotoXY(59, 13);
                    getline(cin, temp);
                    listCustomer[i].setPhoneNumber(temp);
                    gotoXY(10, 30);
                    break;
                case 3:
                    gotoXY(60, 15);
                    cout << left << setw(25) << " ";
                    gotoXY(60, 15);
                    getline(cin, temp);
                    listCustomer[i].setDOB(temp);
                    gotoXY(10, 30);
                    break;
                case 4:
                    gotoXY(52, 17);
                    cout << left << setw(25) << " ";
                    gotoXY(52, 17);
                    getline(cin, temp);
                    listCustomer[i].setGender(temp);
                    gotoXY(10, 30);
                    break;
                default:
                    run = false;
                    break;
                }
            }
        }
    }
    if (count == false)
    {
        gotoXY(50, 10);
        cout << "No result" << endl;
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
            listCustomer[k] = customerTemp;
        }
        m.saveAgainFile(listCustomer); //
    }
}
void menuEditCustomer(Customer &customer)
{
    gotoXY(40, 10);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 11);
    cout << "| 1. Fullname: " << left << setw(25) << customer.getFullName() << "                         |";
    gotoXY(40, 12);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 13);
    cout << "| 2. Phone number: " << left << setw(25) << customer.getPhoneNumber() << "                     |";
    gotoXY(40, 14);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 15);
    cout << "| 3. Date of birth: " << left << setw(25) << customer.getDOB() << "                    |";
    gotoXY(40, 16);
    cout << "+----------------------------------------------------------------+";
    gotoXY(40, 17);
    cout << "| 4.Gender: " << left << setw(25) << customer.getGender() << "                            |";
    gotoXY(40, 18);
    cout << "+----------------------------------------------------------------+";
}

void Staff::removeCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    m.readfromFile(listCustomer);
    int ID;
    gotoXY(50, 4);
    cout << "Enter ID: ";
    gotoXY(50, 5);
    cout << "+-----------+" << endl;
    gotoXY(50, 6);
    cout << "|           |" << endl;
    gotoXY(50, 7);
    cout << "+-----------+" << endl;
    gotoXY(51, 6);
    cin >> ID;
    bool find = false;
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].returnID() == ID)

        {
            find = true;
            menuEditCustomer(listCustomer[i]);
            gotoXY(40, 20);
            cout << "Are you sure you want to remove this customer? ";
            gotoXY(40, 21);
            cout << "1. Yes";
            gotoXY(40, 22);
            cout << "2. No";
            int choice;
            gotoXY(40, 23);
            cout << "Choose: ";
            cin >> choice;
            if (choice == 1)
            {
                listCustomer.earse(i);
                gotoXY(130, 4);
                cout << "Remove successfully" << endl;
            }
            else
                break;
        }
    }
    if (find == false)
    {
        gotoXY(50, 10);
        cout << "No result!!" << endl;
    }

    m.saveAgainFile(listCustomer);
}
// ostream &operator<<(ostream &out, Staff &staff)
// {
//     gotoXY(30, 3);
// }
istream &operator>>(istream &in, Staff &staff)
{
    gotoXY(40, 6);
    cout << "--------Add new staff----------" << endl;
    gotoXY(40, 7);
    forchar(80, 40, 7, '-');
    gotoXY(40, 8);
    cout << "| Fullname:";
    forchar(68, 52, 8, ' ');
    forchar(80, 40, 9, '-');
    gotoXY(40, 10);
    cout << "| Phone number: ";
    forchar(63, 57, 10, ' ');
    forchar(80, 40, 11, '-');
    gotoXY(40, 12);
    cout << "| Date of birth: ";
    forchar(62, 58, 12, ' ');
    forchar(80, 40, 13, '-');
    gotoXY(40, 14);
    cout << "| Gender: ";
    forchar(69, 51, 14, ' ');
    forchar(80, 40, 15, '-');
    gotoXY(40, 16);
    cout << "| Username: ";
    forchar(69, 51, 16, ' ');
    forchar(80, 40, 17, '-');
    gotoXY(40, 18);
    cout << "| Password: ";
    forchar(68, 52, 18, ' ');
    forchar(80, 40, 19, '-');
    in.ignore();
    gotoXY(52, 8);
    getline(in, staff.fullName);
    gotoXY(57, 10);
    getline(in, staff.phoneNumber);
    gotoXY(58, 12);
    getline(in, staff.dateOfBirth);
    gotoXY(52, 14);
    getline(in, staff.gender);
    gotoXY(51, 16);
    getline(in, staff.username);
    gotoXY(57, 18);
    getline(in, staff.password);
    return in;
}