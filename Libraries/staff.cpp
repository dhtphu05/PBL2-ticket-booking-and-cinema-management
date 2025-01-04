#include "../Include/Staff.h"
#include "../Include/Customer.h"
#include <fstream>
#include <sstream>
#include <thread>
#include "../Include/gotoXY.h"
#include <iomanip>
#include "../Include/layout.h"
#include "../Include/clickMouse.h"
#include "../Include/menu.h"
#include <chrono>
void menuEditCustomer(Customer &customer);
int Staff::countStaff = 3000;
Staff::Staff()
{
}
Staff::Staff(string &userName, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender)
    : User(username, password, fullName, phoneNumber, DOB, gender)
{
}
int getClick_addCustomer()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 40 && x_click <= 120 && y_click >= 7 && y_click <= 9)
    {
        return 1; // ho ten
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 9 && y_click <= 11)
    {
        return 2; // so dien thoai
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 11 && y_click <= 13)
    {
        return 3; // ngay sinh
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 13 && y_click <= 15)
    {
        return 4; // gioi tinh
    }
    if (x_click >= 80 && x_click <= 94 && y_click >= 17 && y_click <= 19)
    {
        return 5; // luu
    }
    if (x_click >= 93 && x_click <= 107 && y_click >= 17 && y_click <= 19)
    {
        return 6; // huy
    }
    if (x_click >= 130 && x_click <= 131 && y_click > 4 && y_click < 6)
    {
        return 7; // X
    }
    return 0;
}
// todo : kiểm tra tính hợp lệ của mật khẩu, sdt, ngaỳ sinh
// todo : hướng phát triển cho hàm nhập: khi nhập xong một trường, nếu click chuột lại trường đó thì nội dung k bị xóa chỉ khi nào nguwoif dùng gõ nội dung mới thì mới xóa nội dung cũ
void Staff::addCustomer()
{
    Customer customer;
    DoubleLinkedList<Customer> listCustomer;
    customer.readfromFile(listCustomer);
    showString("Thêm khách hàng mới", 40, 6);
    lineWidth(80, 40, 7, true, true);
    showString("Họ và tên: ", 42, 8);
    lineWidth(81, 40, 9, false, false);
    showString("Số điện thoại: ", 42, 10);
    lineWidth(81, 40, 11, false, false);
    showString("Ngày sinh: ", 42, 12);
    lineWidth(81, 40, 13, false, false);
    showString("Giới tính: ", 42, 14);
    lineWidth(80, 40, 15, true, false);
    lineHeight(4, 40, 8, false, false, false);
    lineHeight(4, 121, 8, false, false, false);
    lineHeight(3, 40, 9, true, false, false);
    lineHeight(3, 121, 9, false, true, false);
    int newID = Customer::count + 1;
    while (isIDExists(listCustomer, newID))
    {
        newID++;
    }
    customer.setID(newID);
    lineWidth(27, 80, 17, true, true);
    gotoXY(80, 18);
    cout << "│     Lưu     │     Hủy     │";
    lineWidth(27, 80, 19, true, false);
    showString("┬", 94, 17);
    showString("┴", 94, 19);

    bool running = true, name = false, phone = false, dob = false, gender = false;
    int choice;
    string str;
    while (running)
    {

        choice = getClick_addCustomer();
        gotoXY(80, 23);
        cout << "                                 ";
        switch (choice)
        {
        case 1:
        {
            gotoXY(53, 8);
            cout << left << setw(25) << " ";
            getString(str, 53, 8);
            customer.setFullName(str);
            name = true;
            break;
        }
        case 2:
        {
            gotoXY(57, 10);
            cout << left << setw(25) << " ";
            getString(str, 57, 10);
            customer.setPhoneNumber(str);
            if (!isPhone(customer.getPhoneNumber()))
            {
                gotoXY(80, 23);
                cout << "\033[31mSố điện thoại không hợp lệ\033[0m";
                gotoXY(57, 10);
                cout << "                              ";
                break;
            }
            else
                phone = true;
            break;
        }
        case 3:
        {
            gotoXY(53, 12);
            cout << left << setw(25) << " ";
            getString(str, 53, 12);
            customer.setDOB(str);
            if (!isDOB(customer.getDOB()))
            {
                gotoXY(80, 23);
                cout << "\033[31mNgày sinh không hợp lệ\033[0m";
                gotoXY(53, 12);
                cout << "                                 ";
                break;
            }
            else
                dob = true;
            break;
        }
        case 4:
        {
            getString(str, 53, 14);
            customer.setGender(str);
            gender = true;
            break;
        }
        case 5:
        {
            if (name && phone && dob && gender)
            {
                customer.savetoFile(true);
                gotoXY(130, 25);
                cout << "Thêm thành công";
                this_thread::sleep_for(chrono::seconds(2));
                gotoXY(130, 25);
                cout << "               "; // Clear the success message
                running = false;
                break;
            }
            else
            {
                gotoXY(50, 25);
                cout << "\033[31mVui lòng nhập đầy đủ thông tin\033[0m";
                break;
            }
        }
        case 6:
        {
            running = false;
            break;
        }
        default:

            break;
        }
    }
    gotoXY(130, 5);
    cout << "❌";
    choice = getClick_addCustomer();
    while (choice != 7)
    {
        choice = getClick_addCustomer();
    }
    system("cls");
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
int getClick_showCustomer()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 37 && x_click <= 38 && y_click > 4 && y_click < 6)
    {
        return 1; // X
    }
    return 0;
}
void Staff::showCustomer(DoubleLinkedList<Customer> &listCustomer, int currentPage, int customerPerPage)
{
    for (int i = listCustomer.getSize() - 1; i >= 0; i--)
    {
        listCustomer.earse(i);
    }
    Customer m;
    m.readfromFile(listCustomer);
    gotoXY(70, 5);
    cout << "Danh sách khách hàng" << endl;
    lineWidth(87, 38, 6, true, true);
    gotoXY(50, 9);
    int x = 8;
    int totalPage = ceil((double)listCustomer.getSize() / customerPerPage);
    int start = (currentPage - 1) * customerPerPage;
    int end = min(start + customerPerPage, listCustomer.getSize());
    gotoXY(100, 30);
    lineHeight(end - start + 1, 38, 7, false, false, false);
    showString("STT", 40, 7);
    lineHeight(end - start + 1, 45, 7, false, false, false);
    showString("┬", 45, 6);
    showString("ID", 47, 7);
    lineHeight(end - start + 1, 52, 7, false, false, false);
    showString("┬", 52, 6);
    showString("Họ và tên", 62, 7);
    lineHeight(end - start + 1, 82, 7, false, false, false);
    showString("┬", 82, 6);
    showString("Số điện thoại", 84, 7);
    lineHeight(end - start + 1, 97, 7, false, false, false);
    showString("┬", 97, 6);
    showString("Ngày sinh", 99, 7);
    lineHeight(end - start + 1, 113, 7, false, false, false);
    showString("┬", 113, 6);
    showString("Giới tính", 114, 7);

    for (int i = start; i < end; i++)
    {

        lineWidth(87, 39, x + i - start, false, false);
        gotoXY(50, ++x + i - start);
        Customer customer = listCustomer[i];
        gotoXY(40, x + i - start);
        cout << i + 1;
        showString(to_string(customer.returnID()), 47, x + i - start);
        showString(customer.getFullName(), 59, x + i - start);
        showString(customer.getPhoneNumber(), 83, x + i - start);
        showString(customer.getDOB(), 99, x + i - start);
        showString(customer.getGender(), 114, x + i - start);
    }
    lineHeight(end - start + 1, 126, 7, false, false, false);
    lineHeight(end - start, 38, 8, true, false, false);
    lineHeight(end - start, 45, 8, false, false, true);
    lineHeight(end - start, 52, 8, false, false, true);
    lineHeight(end - start, 82, 8, false, false, true);
    lineHeight(end - start, 97, 8, false, false, true);
    lineHeight(end - start, 113, 8, false, false, true);
    lineHeight(end - start, 126, 8, false, true, false);

    lineWidth(87, 38, x + end - start, true, false);
    showString("┴", 45, x + end - start);
    showString("┴", 52, x + end - start);
    showString("┴", 82, x + end - start);
    showString("┴", 97, x + end - start);
    showString("┴", 113, x + end - start);
}
void Staff::savetoFile()
{
    DoubleLinkedList<Staff> staffs;
    readID(staffs);
    try
    {                          // Đọc ID của các bộ phim hiện tại để cập nhật ID mới
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
            throw runtime_error("\033[31mLỗi không thể mở file!\033[0m");
        }

        // Ghi thông tin bộ phim vào file với định dạng: "#ID", "Title", "Genre", "Duration", ...
        out << "#" << this->ID << endl;
        out << "Tên đăng nhập: " << this->username << endl;
        out << "Mật khẩu: " << this->password << endl;
        out << "Họ và tên: " << this->fullName << endl;
        out << "Số điện thoại: " << this->phoneNumber << endl;
        out << "Ngày sinh: " << this->dateOfBirth << endl;
        out << "Giới tính: " << this->gender << endl;
        out.close();
    }
    catch (...)
    {
        gotoXY(100, 4);
        cout << "\033[31mKhông thể mở file để lưu staff! Hãy kiểm tra lại!\033[0m" << endl;
    }
}
void Staff::saveAgainFile(DoubleLinkedList<Staff> &staffs)
{
    ofstream out;
    try
    {
        out.open("../Databases/StaffList.txt"); // Mở file để ghi (ghi đè)
        if (!out.is_open())
        {
            throw runtime_error("\033[31mLỗi không thể mở file\033[0m");
        }
        for (int i = 0; i < staffs.getSize(); i++)
        {
            // Ghi thông tin bộ phim vào file với định dạng: "#ID", "Title", "Genre", "Duration", ...
            out << "#" << staffs[i].ID << endl;
            out << "Tên đăng nhập: " << staffs[i].username << endl;
            out << "Mật khẩu: " << staffs[i].password << endl;
            out << "Họ và tên: " << staffs[i].fullName << endl;
            out << "Số điện thoại: " << staffs[i].phoneNumber << endl;
            out << "Ngày sinh: " << staffs[i].dateOfBirth << endl;
            out << "Giới tính: " << staffs[i].gender << endl;
            out << endl;
        }
        out.close();
    }
    catch (...)
    {
        gotoXY(100, 4);
        cout << "\033[31mKhông thể mở file để lưu staff! Hãy kiểm tra lại!\033[0m" << endl;
    }
}
bool is_whitespace_utf8_s(char c)
{
    return std::isspace(static_cast<unsigned char>(c));
}

std::string mytrim(const std::string &str)
{
    size_t start = 0;
    size_t end = str.size();
    while (start < str.size() && is_whitespace_utf8_s(str[start]))
    {
        ++start;
    }

    // Loại bỏ khoảng trắng từ cuối chuỗi
    while (end > start && is_whitespace_utf8_s(str[end - 1]))
    {
        --end;
    }

    return str.substr(start, end - start);
}

void Staff::readfromFile(DoubleLinkedList<Staff> &staffs)
{
    ifstream in;
    try
    {
        in.open("../Databases/StaffList.txt");
        if (!in.is_open())
        {
            throw runtime_error("\033[31mLỗi không thể mở file\033[0m");
        }
        string line;
        Staff staff;
        while (getline(in, line))
        {
            if (!line.empty() && line[0] == '#')
            {
                staff.ID = stoi(line.substr(1));
            }
            else if (line.find("Tên đăng nhập: ") == 0)
            {
                staff.username = mytrim(line.substr(20));
            }
            else if (line.find("Mật khẩu: ") == 0)
            {
                staff.password = mytrim(line.substr(13));
            }
            else if (line.find("Họ và tên: ") == 0)
            {
                staff.fullName = mytrim(line.substr(15));
            }
            else if (line.find("Số điện thoại: ") == 0)
            {
                staff.phoneNumber = mytrim(line.substr(21));
            }
            else if (line.find("Ngày sinh: ") == 0)
            {
                staff.dateOfBirth = mytrim(line.substr(11));
            }
            else if (line.find("Giới tính:") == 0)
            {
                staff.gender = mytrim(line.substr(13));
                staffs.push_back(staff);
                staff = Staff();
            }
        }
        in.close();
    }
    catch (...)
    {
        gotoXY(100, 4);
        cout << "\033[31mKhông thể mở file để đọc staff! Hãy kiểm tra lại!\033[0m" << endl;
    }
}
void Staff::readID(DoubleLinkedList<Staff> &staffs)
{
    int is_read = false;
    try
    {
        ifstream in;
        in.open("../Databases/StaffList.txt");
        if (!in.is_open())
        {
            throw runtime_error("\033[31mLỗi không thể mở file\033[0m");
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
    catch (...)
    {
        gotoXY(100, 4);
        cout << "\033[31mKhông thể mở file để đọc staff! Hãy kiểm tra lại!\033[0m" << endl;
    }
}
int getClick_editCustomer()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 51 && x_click <= 120 && y_click >= 10 && y_click <= 12)
    {
        return 1; // ho ten
    }
    if (x_click >= 51 && x_click <= 120 && y_click >= 12 && y_click <= 14)
    {
        return 2; // so dien thoai
    }
    if (x_click >= 51 && x_click <= 120 && y_click >= 14 && y_click <= 16)
    {
        return 3; // ngay sinh
    }
    if (x_click >= 51 && x_click <= 120 && y_click >= 16 && y_click <= 18)
    {
        return 4; // gioi tinh
    }
    if (x_click >= 120 && x_click <= 133 && y_click >= 20 && y_click <= 22)
    {
        return 5; // luu
    }
    if (x_click >= 133 && x_click <= 146 && y_click >= 20 && y_click <= 22)
    {
        return 6; // huy
    }
    if (x_click >= 140 && x_click <= 141 && y_click > 4 && y_click < 6)
    {
        return 7; // X
    }
    // id
    if (x_click >= 36 && x_click <= 46 && y_click >= 7 && y_click <= 9)
    {
        return 8;
    }

    return 0;
}

void Staff::editCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    int count = false;
    m.readfromFile(listCustomer);
    string str;
    int ID;
    gotoXY(36, 5);
    cout << "Chỉnh sửa thông tin khách hàng";
    gotoXY(36, 6);
    cout << "ID: ";
    lineWidth(10, 36, 7, true, true);
    gotoXY(36, 8);
    cout << "│          │" << endl;
    lineWidth(10, 36, 9, true, false);
    int choice;
    // getString(str, 37, 8);
    // ID = stoi(str);
    bool validInput = false;
    while (!validInput)
    {
        try
        {
            choice = getClick_editCustomer();
            while (choice != 8)
            {
                choice = getClick_editCustomer();
            }
            gotoXY(40, 10);
            cout << "                              ";
            gotoXY(37, 8);
            cout << "         ";
            getString(str, 37, 8); // Lấy chuỗi từ người dùng
            if (std::all_of(str.begin(), str.end(), ::isdigit))
            {
                ID = stoi(str);
            }
            else
            {
                throw std::invalid_argument("Lỗi: Vui lòng chỉ nhập số!");
            } //      // Chuyển đổi chuỗi sang số
            validInput = true; // Nếu thành công, thoát vòng lặp
        }
        catch (const std::invalid_argument &e)
        {
            gotoXY(40, 10); // Hiển thị thông báo lỗi tại vị trí thích hợp
            cout << "\033[31mVui lòng nhập số hợp lệ!\033[0m";
            // Xóa thông báo lỗi
        }
        catch (const std::out_of_range &e)
        {
            gotoXY(40, 10);
            cout << "Số nhập quá lớn!";
        }
    }
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
            lineWidth(27, 120, 20, true, true);
            gotoXY(120, 21);
            cout << "│     Lưu     │     Hủy     │";
            lineWidth(27, 120, 22, true, false);
            showString("┬", 134, 20);
            showString("┴", 134, 22);
            bool run = true;
            while (run)
            {

                int choicee = getClick_editCustomer();

                gotoXY(80, 23);
                cout << "                                 ";
                string temp;

                switch (choicee)
                {
                case 1:
                    gotoXY(62, 11);
                    cout << left << setw(25) << " ";
                    getString(temp, 62, 11);
                    listCustomer[i].setFullName(temp);
                    break;
                case 2:
                    gotoXY(65, 13);
                    cout << left << setw(25) << " ";
                    getString(temp, 65, 13);
                    if (!isPhone(temp))
                    {
                        gotoXY(80, 23);
                        cout << "\033[31mSố điện thoại không hợp lệ\033[0m";
                        gotoXY(65, 13);
                        cout << "                              ";
                        break;
                    }
                    else
                        listCustomer[i].setPhoneNumber(temp);

                    break;
                case 3:
                    gotoXY(62, 15);
                    cout << left << setw(25) << " ";
                    getString(temp, 62, 15);
                    if (!isDOB(temp))
                    {
                        gotoXY(80, 23);
                        cout << "\033[31mNgày sinh không hợp lệ\033[0m";
                        gotoXY(62, 15);
                        cout << "                              ";
                        break;
                    }
                    else
                        listCustomer[i].setDOB(temp);

                    break;
                case 4:
                    gotoXY(62, 17);
                    cout << left << setw(25) << " ";
                    getString(temp, 62, 17);
                    listCustomer[i].setGender(temp);

                    break;
                case 5:
                    listCustomer[i].saveAgainFile(listCustomer);
                    gotoXY(130, 25);
                    cout << " Sửa thành công";
                    this_thread::sleep_for(chrono::seconds(2));
                    gotoXY(130, 25);
                    cout << "               "; // Clear the success message
                    run = false;
                    break;
                case 6:
                    run = false;
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
        cout << "\033[31mKhông tìm thấy khách hàng có ID:  \033[0m" << ID << endl;
    }
    gotoXY(140, 5);
    cout << "❌";
    choice = getClick_editCustomer();
    while (choice != 7)
    {
        choice = getClick_editCustomer();
    }
    system("cls");
}
void menuEditCustomer(Customer &customer)
{
    lineWidth(69, 50, 10, true, true);
    // gotoXY(40, 11);
    // cout << "| 1. Họ và tên: " << left << setw(25) << customer.getFullName() << "                         |";
    showString("Họ và tên: ", 51, 11);
    showString(customer.getFullName(), 62, 11);
    lineWidth(71, 50, 12, false, false);
    showString("Số điện thoại: ", 51, 13);
    showString(customer.getPhoneNumber(), 65, 13);
    lineWidth(71, 50, 14, false, false);
    showString("Ngày sinh: ", 51, 15);
    showString(customer.getDOB(), 62, 15);
    lineWidth(71, 50, 16, false, false);
    showString("Giới tính: ", 51, 17);
    showString(customer.getGender(), 62, 17);
    lineWidth(69, 50, 18, true, false);
    lineHeight(4, 50, 11, false, false, false);
    lineHeight(4, 120, 11, false, false, false);
    lineHeight(3, 50, 12, true, false, false);
    lineHeight(3, 120, 12, false, true, false);
}
int getclick_removeCustomer()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 36 && x_click <= 46 && y_click >= 7 && y_click <= 9)
    {
        return 1; // id
    }
    if (x_click >= 130 && x_click <= 141 && y_click > 4 && y_click < 6)
    {
        return 2; // X
    }
    if (x_click >= 120 && x_click <= 133 && y_click >= 20 && y_click <= 22)
    {
        return 3; // luu
    }
    if (x_click >= 133 && x_click <= 146 && y_click >= 20 && y_click <= 22)
    {
        return 4; // huy
    }
    return 0;
}

void Staff::removeCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    m.readfromFile(listCustomer);
    int ID;
    string str;
    gotoXY(36, 5);
    cout << "Xóa khách hàng";
    lineWidth(10, 36, 7, true, true);
    gotoXY(36, 8);
    cout << "│          │" << endl;
    lineWidth(10, 36, 9, true, false);
    int choice;
    bool validInput = false;
    while (!validInput)
    {
        try
        {
            choice = getclick_removeCustomer();
            while (choice != 1)
            {
                choice = getclick_removeCustomer();
            }
            gotoXY(40, 10);
            cout << "                                ";
            gotoXY(37, 8);
            cout << "         ";
            getString(str, 37, 8); // Lấy chuỗi từ người dùng
            if (std::all_of(str.begin(), str.end(), ::isdigit))
            {
                ID = stoi(str);
            }
            else
            {
                throw std::invalid_argument("Lỗi: Vui lòng chỉ nhập số!");
            } // Chuyển đổi chuỗi sang số
            validInput = true; // Nếu thành công, thoát vòng lặp
        }
        catch (const std::invalid_argument &e)
        {
            gotoXY(40, 10); // Hiển thị thông báo lỗi tại vị trí thích hợp
            cout << "\033[31mVui lòng nhập số hợp lệ!\033[0m";
            // Xóa thông báo lỗi
        }
        catch (const std::out_of_range &e)
        {
            gotoXY(40, 10);
            cout << "\033[31mSố nhập quá lớn!\033[0m";
        }
    }
    bool find = false;
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].returnID() == ID)

        {
            find = true;
            menuEditCustomer(listCustomer[i]);
            lineWidth(27, 120, 20, true, true);
            gotoXY(120, 21);
            cout << "│     Xóa     │     Hủy     │";
            lineWidth(27, 120, 22, true, false);
            showString("┬", 134, 20);
            showString("┴", 134, 22);
            int choicee = getclick_removeCustomer();
            if (choicee == 3)
            {
                listCustomer.earse(i);
                gotoXY(130, 25);
                cout << "Đã xóa thành công";
                this_thread::sleep_for(chrono::seconds(2));
                gotoXY(130, 25);
                cout << "               "; // Clear the success message
                m.saveAgainFile(listCustomer);
                break;
            }
            else
                break;
        }
    }
    if (find == false)
    {
        gotoXY(50, 10);
        cout << "\033[31mKhông tìm thấy người dùng!\033[0m" << endl;
    }
    gotoXY(130, 5);
    cout << "❌";
    choice = getclick_removeCustomer();
    while (choice != 2)
    {
        choice = getclick_removeCustomer();
    }
    system("cls");
}
ostream &operator<<(ostream &out, Staff &staff)
{
    gotoXY(30, 3);
}
istream &operator>>(istream &in, Staff &staff)
{

    showString("Thêm nhân viên mới", 40, 6);
    lineWidth(80, 40, 7, true, true);
    showString("Họ và tên: ", 42, 8);
    lineWidth(81, 40, 9, false, false);
    showString("Số điện thoại: ", 42, 10);
    lineWidth(81, 40, 11, false, false);
    showString("Ngày sinh: ", 42, 12);
    lineWidth(81, 40, 13, false, false);
    showString("Giới tính: ", 42, 14);
    lineWidth(81, 40, 15, false, false);
    showString("Tên đăng nhập: ", 42, 16);
    lineWidth(81, 40, 17, false, false);
    showString("Mật khẩu: ", 42, 18);
    lineWidth(80, 40, 19, true, false);
    lineHeight(6, 40, 8, false, false, false);
    lineHeight(6, 121, 8, false, false, false);
    lineHeight(5, 40, 9, true, false, false);
    lineHeight(5, 121, 9, false, true, false);
}