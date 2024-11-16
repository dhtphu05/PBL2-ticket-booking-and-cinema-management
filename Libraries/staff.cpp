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
    cout << "Ho va Ten: " << this->fullName << endl;
    cout << "So dien thoai: " << this->phoneNumber << endl;
    cout << "Ngay sinh: " << this->dateOfBirth << endl;
    cout << "Gioi tinh: " << this->gender << endl;
}
void Staff::addCustomer()
{
    Customer customer;
    DoubleLinkedList<Customer> listCustomer;
    customer.readfromFile(listCustomer);

    cout << "Tao khach hang moi" << endl;
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
    readID(staffs);
    this->ID = countStaff;
    ofstream out;
    out.open("../Databases/StaffList.txt", ios::app);
    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }
    out << this->ID << ";" << this->username << ";" << this->password << ";" << this->fullName << ";" << this->phoneNumber << ";" << this->dateOfBirth << ";" << this->gender << endl;
}
void Staff::saveAgainFile(DoubleLinkedList<Staff> &staffs)
{
    ofstream out;
    out.open("../Databases/StaffList.txt");
    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }
    for (int i = 0; i < staffs.getSize(); i++)
    {
        out << staffs[i].ID << ";" << staffs[i].username << ";" << staffs[i].password << ";" << staffs[i].fullName << ";" << staffs[i].phoneNumber << ";" << staffs[i].dateOfBirth << ";" << staffs[i].gender << endl;
        }
    out.close();
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
    while (getline(in, line))
    {
        Staff staff;
        stringstream ss(line);
        string idStr;
        getline(ss, idStr, ';');
        staff.ID = stoi(idStr);
        getline(ss, staff.username, ';');
        getline(ss, staff.password, ';');
        getline(ss, staff.fullName, ';');
        getline(ss, staff.phoneNumber, ';');
        getline(ss, staff.dateOfBirth, ';');
        getline(ss, staff.gender);
        staffs.push_back(staff);
    }
    in.close();
}
void Staff::readID(DoubleLinkedList<Staff> &staffs)
{
    ifstream in;
    in.open("../Databases/StaffList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }
    string line;
    int ID = countStaff;
    while (getline(in, line))
    {
        Staff staff;
        stringstream ss(line);
        string idStr;
        getline(ss, idStr, ';');
        staff.ID = stoi(idStr);
        if (staff.ID > ID)
        {
            ID = staff.ID;
        }
        getline(ss, staff.username, ';');
        getline(ss, staff.password, ';');
        getline(ss, staff.fullName, ';');
        getline(ss, staff.phoneNumber, ';');
        getline(ss, staff.dateOfBirth, ';');
        getline(ss, staff.gender);
        staffs.push_back(staff);
    }
    countStaff = ++ID;
    in.close();
}

void Staff::editCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    int count = false;
    m.readfromFile(listCustomer);
    int ID;
    cout << "Nhap ID: ";
    cin >> ID;
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].returnID() == ID)
        {
            count = true;
            menuEditCustomer();
            cout << "Chon thong tin sua  " << endl;
            int choice;
            cin >> choice;
            string temp;
            switch (choice)
            {
            case 1:
                cout << "Nhap ten moi: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setFullName(temp);
                break;
            case 2:
                cout << "Nhap so dien thoai moi: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setPhoneNumber(temp);
                break;
            case 3:
                cout << "Nhap ngay sinh moi: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setDOB(temp);
            case 4:
                cout << "Nhap gioi tinh moi: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setGender(temp);
                break;
            default:
                cout << "Lua chon khong hop le" << endl;
                break;
            }
        }
    }
    if (count == false)
    {
        cout << "Khong tim thay khach hang" << endl;
    }
    m.saveAgainFile(listCustomer); //
}
void menuEditCustomer()
{
    cout << "1.Ten" << endl;
    cout << "2.So dien thoai" << endl;
    cout << "3.Ngay sinh" << endl;
    cout << "4.Gioi tinh" << endl;
}

void Staff::removeCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    m.readfromFile(listCustomer);
    string ID;
    cout << "Nhap ID: ";
    cin >> ID;
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].getID() == ID)
        {
            listCustomer.earse(i);
            cout << "Xoa thanh cong" << endl;
            break;
        }
    }
    m.saveAgainFile(listCustomer);
}
ostream &operator<<(ostream &out, Staff &staff)
{
    cout << "-------------------" << endl;
    cout << "Ho va Ten: " << staff.fullName << endl;
    cout << "So dien thoai: " << staff.phoneNumber << endl;
    cout << "Ngay sinh: " << staff.dateOfBirth << endl;
    cout << "Gioi tinh: " << staff.gender << endl;
    return out;
}
istream &operator>>(istream &in, Staff &staff)
{
    cout << "--------Them mot nhan vien moi----------" << endl;
    cout << "Ten dang nhap: ";
    in.ignore();
    getline(in, staff.username);
    cout << "Mat khau: ";
    getline(in, staff.password);
    cout << "Ho va Ten: ";
    getline(in, staff.fullName);
    cout << "So dien thoai: ";
    getline(in, staff.phoneNumber);
    cout << "Ngay sinh: ";
    getline(in, staff.dateOfBirth);
    cout << "Gioi tinh: ";
    getline(in, staff.gender);
    return in;
}