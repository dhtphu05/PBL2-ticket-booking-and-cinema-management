#include "../Include/Customer.h"
#include <fstream>
#include <conio.h>
#include "../Include/gotoXY.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <thread>
int Customer::count = 1000;
Customer::Customer(string &username, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender)
    : User(username, password, fullName, phoneNumber, DOB, gender)
{
}
Customer::Customer(string username, string password)
{
    this->password = password;
    // this->ID = count;
    // count++;
}
void forchar(int n, int x, int y, char ch)
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
istream &operator>>(istream &in, Customer &customer)
{
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
    in.ignore();
    gotoXY(52, 8);
    getline(in, customer.fullName);
    gotoXY(57, 10);
    getline(in, customer.phoneNumber);
    gotoXY(58, 12);
    getline(in, customer.dateOfBirth);
    gotoXY(52, 14);
    getline(in, customer.gender);
    return in;
}
void GetPassword(string &password)
{
    char ch;
    while (true)
    {
        ch = _getch();
        if (ch == 13)
        { // Phím Enter
            break;
        }
        else if (ch == 8)
        { // Phím Backspace
            if (!password.empty())
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password += ch;
            cout << ch;
            this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\b*";
        }
    }
    cout << endl;
    // return password;
}
void Customer::resigter(Customer &customer)
{
    string passwordTemp;
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
    forchar(68, 51, 16, ' ');
    forchar(80, 40, 17, '-');
    gotoXY(40, 18);
    cout << "| Password: ";
    forchar(68, 51, 18, ' ');
    forchar(80, 40, 19, '-');
    gotoXY(40, 20);
    cout << "| Confirm password: ";
    forchar(63, 59, 20, ' ');
    forchar(80, 40, 21, '-');

    cin.ignore();
    gotoXY(52, 8);
    getline(cin, customer.fullName);
    gotoXY(57, 10);
    getline(cin, customer.phoneNumber);
    gotoXY(58, 12);
    getline(cin, customer.dateOfBirth);
    gotoXY(52, 14);
    getline(cin, customer.gender);
    gotoXY(51, 16);
    getline(cin, customer.username);
    gotoXY(51, 18);
    GetPassword(customer.password);
    gotoXY(59, 20);
    GetPassword(passwordTemp);
    while (passwordTemp != customer.password)
    {
        gotoXY(40, 22);
        cout << "Password does not match. Please enter again!";
        gotoXY(59, 20);
        cout << left << setw(10) << " ";
        gotoXY(59, 20);
        GetPassword(passwordTemp);
    }
}
ostream &operator<<(ostream &out, Customer &customer)
{
    out << "-------------------" << endl;
    out << "ID: " << customer.ID << endl;
    out << "Fullname: " << customer.fullName << endl;
    out << "Phone number: " << customer.phoneNumber << endl;
    out << "Date of birth: " << customer.dateOfBirth << endl;
    out << "Geder: " << customer.gender << endl;
    return out;
}
void Customer::savetoFile()
{
    DoubleLinkedList<Customer> customers;
    readID(customers);
    this->ID = count;
    this->username = "user" + to_string(count);
    ofstream out;
    if (0)
    {
        out.open("../Databases/CustomerList.txtList.txt"); // Mở file để ghi (ghi đè)
    }
    else
    {
        out.open("../Databases/CustomerList.txt", std::ios::app); // Mở file để ghi thêm (append)
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
    out << endl;
    out.close();
}
std::string c_trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r"); // Tìm vị trí ký tự không phải khoảng trắng
    size_t end = str.find_last_not_of(" \t\n\r");    // Tìm vị trí ký tự không phải khoảng trắng ở cuối
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

void Customer::readfromFile(DoubleLinkedList<Customer> &listCustomer)
{

    ifstream in;
    in.open("../Databases/CustomerList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }
    string line;
    Customer customer;
    while (getline(in, line))
    {
        if (!line.empty() && line[0] == '#')
        {
            customer.ID = stoi(line.substr(1));
        }
        else if (line.find("Username: ") == 0)
        {
            customer.username = c_trim(line.substr(10));
        }
        else if (line.find("Password: ") == 0)
        {
            customer.password = c_trim(line.substr(10));
        }
        else if (line.find("Fullname: ") == 0)
        {
            customer.fullName = c_trim(line.substr(10));
        }
        else if (line.find("Phone: ") == 0)
        {
            customer.phoneNumber = c_trim(line.substr(7));
        }
        else if (line.find("Date of birth: ") == 0)
        {
            customer.dateOfBirth = c_trim(line.substr(15));
        }
        else if (line.find("Gender:") == 0)
        {
            customer.gender = c_trim(line.substr(7));
            listCustomer.push_back(customer);
        }
    }
    in.close();
}
void Customer::readID(DoubleLinkedList<Customer> &listCustomer)
{
    ifstream in;
    in.open("../Databases/CustomerList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }

    string line;
    int maxID = count;
    while (getline(in, line))
    {
        // Kiểm tra xem dòng có bắt đầu với "#" (ID phim) không
        if (line.substr(0, 1) == "#")
        {
            Customer customer;
            stringstream ss;
            ss.str(line);
            string idtemp;
            getline(ss, idtemp, ' ');             // Lấy phần ID sau dấu "#"
            customer.ID = stoi(idtemp.substr(1)); // Chuyển đổi ID (cắt bỏ dấu '#')

            // Cập nhật maxID nếu cần
            if (customer.ID > maxID)
            {
                maxID = customer.ID;
            }
        }
    }

    in.close();

    // Cập nhật countMovie bằng ID lớn nhất tìm được
    count = ++maxID;
}
void Customer::Display()
{
    cout << *this;
}
void Customer::saveAgainFile(DoubleLinkedList<Customer> &listCustomer)
{
    ofstream out;

    out.open("../Databases/CustomerList.txt"); // Mở file để ghi (ghi đè)
    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        // Ghi thông tin bộ phim vào file với định dạng: "#ID", "Title", "Genre", "Duration", ...
        out << "#" << listCustomer[i].ID << endl;
        out << "Username: " << listCustomer[i].username << endl;
        out << "Password: " << listCustomer[i].password << endl;
        out << "Fullname: " << listCustomer[i].fullName << endl;
        out << "Phone: " << listCustomer[i].phoneNumber << endl;
        out << "Date of birth: " << listCustomer[i].dateOfBirth << endl;
        out << "Gender: " << listCustomer[i].gender << endl;
        out << endl;
    }
    out.close();
}