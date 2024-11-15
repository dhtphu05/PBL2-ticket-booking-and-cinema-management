#include "../Include/Staff.h"
#include "customer.cpp"
#include <fstream>
#include <sstream>

void menuEditCustomer();
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
    cout << "-------------------" << endl;
    cout << "Fullname: " << this->fullName << endl;
    cout << "PhoneNumber: " << this->phoneNumber << endl;
    cout << "Date of birth: " << this->dateOfBirth << endl;
    cout << "Gender: " << this->gender << endl;
}
void Staff::addCustomer()
{
    Customer customer;
    DoubleLinkedList<Customer> listCustomer;
    customer.readfromFile(listCustomer);

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
    listCustomer.display();
}
void Staff::savetoFile()
{
    DoubleLinkedList<Staff> staffs;
    readID(staffs);        // Đọc ID của các bộ phim hiện tại để cập nhật ID mới
    this->ID = countStaff; // Gán ID mới cho bộ phim

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
    cout << "Enter ID: ";
    cin >> ID;
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].returnID() == ID)
        {
            count = true;
            menuEditCustomer();
            cout << "Choose imformation to edit:  " << endl;
            int choice;
            cin >> choice;
            string temp;
            switch (choice)
            {
            case 1:
                cout << "New Name: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setFullName(temp);
                break;
            case 2:
                cout << "New phone number: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setPhoneNumber(temp);
                break;
            case 3:
                cout << "New date of birth: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setDOB(temp);
            case 4:
                cout << "New gender: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setGender(temp);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    if (count == false)
    {
        cout << "No result" << endl;
    } else 
    m.saveAgainFile(listCustomer); //
}
void menuEditCustomer()
{
    cout << "1.Fullname" << endl;
    cout << "2.PhoneNumber" << endl;
    cout << "3.Date of birth" << endl;
    cout << "4.Gender" << endl;
}

void Staff::removeCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    m.readfromFile(listCustomer);
    int ID;
    cout << "Enter ID: ";
    cin >> ID;
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].returnID() == ID)
        {
            listCustomer.earse(i);
            cout << "Remove successfully" << endl;
        }
    }
    m.saveAgainFile(listCustomer);
}
ostream &operator<<(ostream &out, Staff &staff)
{
    cout << "-------------------" << endl;
    cout << "Fullname: " << staff.fullName << endl;
    cout << "Phone: " << staff.phoneNumber << endl;
    cout << "Date of birth: " << staff.dateOfBirth << endl;
    cout << "Gender: " << staff.gender << endl;
}
istream &operator>>(istream &in, Staff &staff)
{
    cout << "--------Add new staff----------" << endl;
    cout << "Username: ";
    in.ignore();
    getline(in, staff.username);
    cout << "Password: ";
    getline(in, staff.password);
    cout << "Fullname: ";
    getline(in, staff.fullName);
    cout << "Phonenumber: ";
    getline(in, staff.phoneNumber);
    cout << "Date of birth: ";
    getline(in, staff.dateOfBirth);
    cout << "Gender: ";
    getline(in, staff.gender);
}