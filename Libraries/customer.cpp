#include "../Include/Customer.h"
#include <fstream>
#include <sstream>
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
istream &operator>>(istream &in, Customer &customer)
{
    cout << "Fullname: ";
    in.ignore();
    getline(in, customer.fullName);
    cout << "Phone number: ";
    getline(in, customer.phoneNumber);
    cout << "Date of birth: ";
    getline(in, customer.dateOfBirth);
    cout << "Gender: ";
    getline(in, customer.gender);
    return in;
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