#include "../Include/Customer.h"
#include <regex>
#include <fstream>
#include <conio.h>
#include "../Include/gotoXY.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <thread>
#include "../Include/layout.h"
#include "../Include/clickMouse.h"
int Customer::count = 1000;
std::string c_trim(const std::string &str);
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
bool isValidPassword(const std::string &password)
{
    // Regex kiểm tra mật khẩu
    std::regex pattern("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,20}$");
    return std::regex_match(password, pattern);
}

istream &operator>>(istream &in, Customer &customer)
{

    lineWidth(70, 40, 7, true, true);
    gotoXY(40, 8);
    cout << "├";
    gotoXY(42, 8);
    cout << "Họ và tên: ";
    gotoXY(111, 8);
    cout << "┤";
    lineWidth(70, 40, 9, false, false);
    gotoXY(40, 10);
    cout << "├  Số điện thoại: ";
    gotoXY(111, 10);
    cout << "┤";
    lineWidth(70, 40, 11, false, false);
    gotoXY(40, 12);
    cout << "├ Ngày sinh: ";
    gotoXY(111, 12);
    cout << "┤";
    lineWidth(70, 40, 13, false, false);
    gotoXY(40, 14);
    cout << "├ Giới tính: ";
    gotoXY(111, 14);
    cout << "┤";
    lineWidth(70, 111, 15, true, false);
    in.ignore();
    gotoXY(52, 8);
    getline(in, customer.fullName);
    gotoXY(55, 10);
    getline(in, customer.phoneNumber);
    gotoXY(53, 12);
    getline(in, customer.dateOfBirth);
    gotoXY(53, 14);
    getline(in, customer.gender);
    return in;
}
void GetPassword(string &password)
{
    char ch;
    password.clear(); // Đảm bảo chuỗi bắt đầu rỗng
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
        else if (isprint(ch)) // Chỉ nhận các ký tự có thể in được
        {
            password += ch;
            cout << ch;
            this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\b*";
        }
    }
    password = c_trim(password); // Xóa khoảng trắng thừa (nếu cần)
    cout << endl;
}
int getClick_resigter()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 40 && x_click <= 120 && y_click >= 7 && y_click < 9)
    {
        return 1; // ho ten
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 9 && y_click < 11)
    {
        return 2; // so dien thoai
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 11 && y_click < 13)
    {
        return 3; // ngay sinh
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 13 && y_click < 15)
    {
        return 4; // gioi tinh
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 15 && y_click < 17)
    {
        return 5; // ten dang nhap
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 17 && y_click < 19)
    {
        return 6; // mat khau
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 19 && y_click < 21)
    {
        return 7; // nhap lai mat khau
    }
    // dăng ký
    if (x_click >= 40 && x_click <= 55 && y_click >= 22 && y_click < 24)
    {
        return 8; // luu
    }
    if (x_click >= 130 && x_click <= 140 && y_click >= 5 && y_click <= 7)
    {
        return 9;
    }

    return 0;
}
///// todo phải nhập hết thông tin rồi mới cho nhấn đăng ký thành công -done

// todo nhập số điện thoại theo format
bool regexPhoneNumber(string &phone)
{

    std::regex patter(R"(^0(3|5|7|8|9)\d{8}$)");

    return std::regex_match(phone, patter) ? true : false;
}
bool regexDOB(string &DOB)
{

    std::regex patter("\\d{2}[/]\\d{2}[/]\\d{4}");

    if (std::regex_match(DOB, patter))
    {
        string day = DOB.substr(0, 2);
        string month = DOB.substr(3, 2);
        string year = DOB.substr(6, 4);
        if (stoi(year) > getYear())
            return false;
        else if (stoi(year) == getYear())
        {
            if (stoi(month) > getMonth())
            {
                return false;
            }
            else if (stoi(month) == getMonth())
            {
                if (stoi(day) > getDay())
                {
                    return false;
                }
            }
        }
        else
        {
            if (stoi(month) > 12)
                return false;
            else
            {
                if (stoi(day) > 31)
                    return false;
            }
        }
        return true;
    }
    else
        return false;
}
// todo còn lại chọn giới tính cho tích chọn nữ hay nam
bool Customer::resigter(Customer &customer)
{
    string passwordTemp;
    // todo thêm thoát
    lineWidth(8, 130, 5, true, true);
    showString("│ Thoát  │", 130, 6);
    lineWidth(8, 130, 7, true, false);

    ///////////////////////////////
    lineWidth(79, 40, 7, true, true);
    showString("Họ và tên: ", 42, 8);
    lineWidth(80, 40, 9, false, false);
    showString("Số điện thoại: ", 42, 10);
    lineWidth(80, 40, 11, false, false);
    showString("Ngày sinh: ", 42, 12);
    lineWidth(80, 40, 13, false, false);
    showString("Giới tính: ", 42, 14);
    lineWidth(80, 40, 15, false, false);
    showString("Tên đăng nhập: ", 42, 16);
    lineWidth(80, 40, 17, false, false);
    showString("Mật khẩu: ", 42, 18);
    lineWidth(80, 40, 19, false, false);
    showString("Nhập lại mật khẩu: ", 42, 20);
    lineWidth(79, 40, 21, true, false);
    lineHeight(7, 40, 8, false, false, false);
    lineHeight(6, 40, 9, true, false, false);
    lineHeight(7, 120, 8, false, false, false);
    lineHeight(6, 120, 9, false, true, false);
    lineWidth(15, 40, 22, true, true);
    showString("🔒 Đăng kí", 42, 23);
    lineWidth(15, 40, 24, true, false);
    lineHeight(1, 40, 23, false, false, false);
    lineHeight(1, 56, 23, false, false, false);
    bool fullname = false, phoneNumber = false, dateOfBirth = false, gender = false, username = false, password = false, _passwordTemp = false;
    int choice;
    bool run = true;
    bool check = false;
    while (run)
    {
        choice = getClick_resigter();
        switch (choice)
        {
        case 1:
            gotoXY(54, 8);
            cout << left << setw(25) << " ";
            getString(customer.fullName, 54, 8);
            fullname = true;
            break;
        case 2:

            gotoXY(57, 10);
            cout << left << setw(25) << " ";
            getString(customer.phoneNumber, 57, 10);
            while (!regexPhoneNumber(customer.phoneNumber))
            {
                gotoXY(70, 23);
                cout << "Số điện thoại không hợp lệ";
                gotoXY(57, 10);
                cout << "                            ";
                gotoXY(57, 10);
                getString(customer.phoneNumber, 57, 10);
                gotoXY(70, 23);
                cout << "                                ";
            }
            phoneNumber = true;
            break;
        case 3:
            gotoXY(54, 12);
            cout << left << setw(25) << " ";
            getString(customer.dateOfBirth, 54, 12);
            while (!regexDOB(customer.dateOfBirth))
            {
                gotoXY(50, 25);
                cout << "Ngày sinh không hợp lệ hoặc không đúng định dạng, định dạng ngày sinh là dd/mm/yyyy";
                gotoXY(54, 12);
                cout << "                                                 ";
                gotoXY(54, 12);
                getString(customer.dateOfBirth, 54, 12);
                gotoXY(50, 25);
                cout << "                                                                                                    ";
            }
            dateOfBirth = true;
            break;
        case 4:
            gotoXY(54, 14);
            cout << left << setw(25) << " ";
            getString(customer.gender, 54, 14);
            gender = true;
            break;
        case 5:
            gotoXY(57, 16);
            cout << left << setw(25) << " ";
            getString(customer.username, 57, 16);
            username = true;
            break;
        case 6:
            gotoXY(51, 18);
            cout << left << setw(25) << " ";
            gotoXY(51, 18);
            GetPassword(customer.password);
            while (!isValidPassword(customer.password))
            {
                gotoXY(70, 23);
                cout << ("Mật khẩu phải chứa ít nhất 1 chữ hoa, 1 chữ thường, 1 số và 1 ký tự đặc biệt");
                gotoXY(51, 18);
                cout << "                            ";
                gotoXY(51, 18);
                GetPassword(customer.password);
                gotoXY(70, 23);
                cout << ("                                                                                                ");
            }
            check = true;
            password = true;
            break;
        case 7:
            if (check == false)
            {
                gotoXY(70, 23);
                cout << "Mật khẩu chưa được nhập";
                this_thread::sleep_for(chrono::seconds(2));
                break;
            }
            gotoXY(63, 20);
            cout << left << setw(25) << " ";
            gotoXY(63, 20);
            GetPassword(passwordTemp);
            while (customer.password != passwordTemp)
            {
                gotoXY(80, 23);
                cout << ("Mật khẩu không khớp! Vui lòng nhập lại");
                gotoXY(63, 20);
                cout << "                            ";
                gotoXY(63, 20);
                GetPassword(passwordTemp);
                gotoXY(80, 23);
                cout << ("                                                            ");
            }
            _passwordTemp = true;
            break;
        case 8:
            if (fullname && phoneNumber && dateOfBirth && gender && username && password && _passwordTemp)
            {
                customer.savetoFile(false);
                gotoXY(130, 25);
                cout << "Thành công";
                run = false;
                this_thread::sleep_for(chrono::seconds(1));
                gotoXY(130, 25);
                cout << "               "; // Clear the success message
            }
            else
            {
                gotoXY(50, 25);
                cout << "Bạn chưa điền đầy đủ thông tin";
                this_thread::sleep_for(chrono::seconds(1));
                gotoXY(50, 25);
                cout << "                                              "; // Clear the success message
            }
            break;
        case 9:
            system("cls");
            return false;
            break;
        }
    }
    return true;
}
void Customer::editCustomer()
{
    lineWidth(69, 50, 10, true, true);
    showString("Họ và tên: ", 51, 11);
    showString(this->getFullName(), 62, 11);
    lineWidth(71, 50, 12, false, false);
    showString("Số điện thoại: ", 51, 13);
    showString(this->getPhoneNumber(), 65, 13);
    lineWidth(71, 50, 14, false, false);
    showString("Ngày sinh: ", 51, 15);
    showString(this->getDOB(), 62, 15);
    lineWidth(71, 50, 16, false, false);
    showString("Giới tính: ", 51, 17);
    showString(this->getGender(), 62, 17);
    lineWidth(69, 50, 18, true, false);
    lineHeight(4, 50, 11, false, false, false);
    lineHeight(4, 120, 11, false, false, false);
    lineHeight(3, 50, 12, true, false, false);
    lineHeight(3, 120, 12, false, true, false);
    bool run = true;
    while (run)
    {
        gotoXY(0, 30);
        cout << "Nhập sự lựa chọn: ";
        int choice;
        cin >> choice;
        string temp;
        cin.ignore();
        switch (choice)
        {
        case 1:
            gotoXY(65, 11);
            cout << left << setw(25) << " ";
            gotoXY(65, 11);
            getline(cin, temp);
            this->setFullName(temp);
            gotoXY(10, 30);
            break;
        case 2:
            gotoXY(69, 13);
            cout << left << setw(25) << " ";
            gotoXY(69, 13);
            getline(cin, temp);
            this->setPhoneNumber(temp);
            gotoXY(10, 30);
            break;
        case 3:
            gotoXY(70, 15);
            cout << left << setw(25) << " ";
            gotoXY(70, 15);
            getline(cin, temp);
            this->setDOB(temp);
            gotoXY(10, 30);
            break;
        case 4:
            gotoXY(62, 17);
            cout << left << setw(25) << " ";
            gotoXY(62, 17);
            getline(cin, temp);
            this->setGender(temp);
            gotoXY(10, 30);
            break;
        default:
            run = false;
            break;
        }
    }
}
ostream &operator<<(ostream &out, Customer &customer)
{
    out << "-------------------" << endl;
    out << "ID: " << customer.ID << endl;
    out << "Họ và tên: " << customer.fullName << endl;
    out << "Số điện thoại: " << customer.phoneNumber << endl;
    out << "Ngày sinh: " << customer.dateOfBirth << endl;
    out << "Giới tính: " << customer.gender << endl;
    return out;
}
void Customer::savetoFile(bool yesAutoSaveUsername)
{
    DoubleLinkedList<Customer> customers;
    readID(customers);
    this->ID = count;
    if (yesAutoSaveUsername)
    {
        this->username = "user" + to_string(count);
    }
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

    out << "#" << this->ID << endl;
    out << "Tên đăng nhập: " << this->username << endl;
    out << "Mật khẩu: " << this->password << endl;
    out << "Họ và tên: " << this->fullName << endl;
    out << "Số điện thoại: " << this->phoneNumber << endl;
    out << "Ngày sinh: " << this->dateOfBirth << endl;
    out << "Giới tính: " << this->gender << endl;
    out << endl;
    out.close();
}
bool is_whitespace_utf8_c(char c)
{
    return std::isspace(static_cast<unsigned char>(c));
}

std::string c_trim(const std::string &str)
{
    size_t start = 0;
    size_t end = str.size();

    // Loại bỏ khoảng trắng từ đầu chuỗi
    while (start < str.size() && is_whitespace_utf8_c(str[start]))
    {
        ++start;
    }

    // Loại bỏ khoảng trắng từ cuối chuỗi
    while (end > start && is_whitespace_utf8_c(str[end - 1]))
    {
        --end;
    }

    return str.substr(start, end - start);
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
        else if (line.find("Tên đăng nhập: ") == 0)
        {
            customer.username = c_trim(line.substr(20));
        }
        else if (line.find("Mật khẩu: ") == 0)
        {
            customer.password = c_trim(line.substr(14));
        }
        else if (line.find("Họ và tên: ") == 0)
        {
            customer.fullName = c_trim(line.substr(15));
        }
        else if (line.find("Số điện thoại: ") == 0)
        {
            customer.phoneNumber = c_trim(line.substr(21));
        }
        else if (line.find("Ngày sinh: ") == 0)
        {
            customer.dateOfBirth = c_trim(line.substr(12));
        }
        else if (line.find("Giới tính:") == 0)
        {
            customer.gender = c_trim(line.substr(13));
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
        throw runtime_error("Lỗi không thể mở file");
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
        throw runtime_error("Lỗi không thể mở file");
    }
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        // Ghi thông tin bộ phim vào file với định dạng: "#ID", "Title", "Genre", "Duration", ...
        out << "#" << listCustomer[i].ID << endl;
        out << "Tên đăng nhập: " << listCustomer[i].username << endl;
        out << "Mật khẩu: " << listCustomer[i].password << endl;
        out << "Họ và tên: " << listCustomer[i].fullName << endl;
        out << "Số điện thoại: " << listCustomer[i].phoneNumber << endl;
        out << "Ngày sinh: " << listCustomer[i].dateOfBirth << endl;
        out << "Giới tính: " << listCustomer[i].gender << endl;
        out << endl;
    }
    out.close();
}
Customer *Customer::getCustomerByUsername(DoubleLinkedList<Customer> &customerList, string username)
{
    for (int i = 0; i < customerList.getSize(); i++)
    {
        if (customerList[i].getUserName() == username)
        {
            return &customerList[i];
        }
    }
    return nullptr;
}