#include "../Include/Admin.h"
#include "../Include/gotoXY.h"
#include "../Include/layout.h"
#include "../Include/clickMouse.h"
#include "../Include/menu.h"
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <thread>
Admin::Admin()
{
    // this->ID = count;
    // count++;
}
Admin::Admin(string &userName, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender)
    : Staff(userName, password, fullName, phoneNumber, DOB, gender)
{
}
int getClick_addstaff()
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
    if (x_click >= 80 && x_click <= 92 && y_click >= 20 && y_click < 22)
    {
        return 7; // luu
    }
    if (x_click >= 93 && x_click <= 111 && y_click >= 21 && y_click < 22)
    {
        return 8; // huy
    }
    if (x_click >= 130 && x_click <= 131 && y_click > 4 && y_click < 6)
    {
        return 9; // X
    }
    return 0;
}
// todo tự nhiên nhấn xong name là bắt thoát rồi- xí xem lại- đi nấu cơm đã-done
void Admin::addStaff()
{
    Staff staff;
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
    lineWidth(27, 80, 20, true, true);
    gotoXY(80, 21);
    cout << "│     Lưu    │     Hủy      │";
    lineWidth(27, 80, 22, true, false);
    showString("┬", 93, 20);
    showString("┴", 93, 22);
    int choice;
    bool name = false, phone = false, dob = false, gender = false, username = false, password = false;
    bool run = true;
    while (run)
    {
        choice = getClick_addstaff();
        switch (choice)
        {
        case 1:
            gotoXY(54, 8);
            cout << left << setw(25) << " ";
            getString(staff.getFullName(), 54, 8);
            name = true;
            break;
        case 2:
            gotoXY(60, 10);
            cout << left << setw(25) << " ";
            getString(staff.getPhoneNumber(), 60, 10);

            while (!_regexPhoneNumber(staff.getPhoneNumber()))
            {
                gotoXY(80, 23);
                cout << "Số điện thoại không hợp lệ";
                gotoXY(60, 10);
                cout << "                              ";
                gotoXY(60, 10);
                getString(staff.getPhoneNumber(), 60, 10);
                gotoXY(80, 23);
                cout << "                                 ";
            }
            phone = true;
            break;
        case 3:
            gotoXY(54, 12);
            cout << left << setw(25) << " ";
            getString(staff.getDOB(), 54, 12);

            while (!_regexDOB(staff.getDOB()))
            {
                gotoXY(80, 23);
                cout << "Ngày sinh không hợp lệ";
                gotoXY(54, 12);
                cout << "                          ";
                gotoXY(54, 12);
                getString(staff.getDOB(), 54, 12);
                gotoXY(80, 23);
                cout << "                                 ";
            }
            dob = true;
            break;
        case 4:
            gotoXY(54, 14);
            cout << left << setw(25) << " ";
            getString(staff.getGender(), 54, 14);
            gender = true;

            break;
        case 5:
            gotoXY(57, 16);
            cout << left << setw(25) << " ";
            getString(staff.getUserName(), 57, 16);
            username = true;
            break;
        case 6:
            gotoXY(52, 18);
            cout << left << setw(25) << " ";
            getString(staff.getPassword(), 57, 18);
            while (!_isValidPassword(staff.getPassword()))
            {
                gotoXY(50, 23);
                cout << "Mật khẩu phải chứa ít nhất 1 chữ hoa, 1 chữ thường, 1 số và 1 ký tự đặc biệt";
                gotoXY(57, 18);
                cout << "                            ";
                gotoXY(57, 18);
                getString(staff.getPassword(), 57, 18);
                gotoXY(50, 23);
                cout << "                                                                                             ";
            }
            phone = true;

            break;
        case 7:
            if (name && phone && dob && gender && username && password)
            {
                staff.savetoFile();
                gotoXY(130, 25);
                cout << "Thành công";
                run = false;
                this_thread::sleep_for(chrono::seconds(2));
                gotoXY(130, 25);
                cout << "               "; // Clear the success message
                break;
            case 8:
                run = false;
                break;
            }
        }
    }
    gotoXY(130, 5);
    cout << "❌";
    choice = getClick_addstaff();
    while (choice != 9)
    {
        choice = getClick_addstaff();
    }
    system("cls");
    menuAdmin_default(*this);
}
void menu(Staff &staff)
{
    lineWidth(79, 40, 10, true, true);
    showString("Họ và tên: ", 42, 11);
    showString(staff.getFullName(), 54, 11);
    lineWidth(81, 40, 12, false, false);
    showString("Số điện thoại: ", 42, 13);
    showString(staff.getPhoneNumber(), 57, 13);
    lineWidth(81, 40, 14, false, false);
    showString("Ngày sinh: ", 42, 15);
    showString(staff.getDOB(), 53, 15);
    lineWidth(81, 40, 16, false, false);
    showString("Giới tính: ", 42, 17);
    showString(staff.getGender(), 53, 17);
    lineWidth(81, 40, 18, false, false);
    showString("Tên đăng nhập: ", 42, 19);
    showString(staff.getUserName(), 57, 19);
    lineWidth(81, 40, 20, false, false);
    showString("Mật khẩu: ", 42, 21);
    showString(staff.getPassword(), 52, 21);
    lineWidth(79, 40, 22, true, false);
    lineHeight(6, 40, 11, false, false, false);
    lineHeight(6, 120, 11, false, false, false);
    lineHeight(5, 40, 12, true, false, false);
    lineHeight(5, 120, 12, false, true, false);
}
int getclick_editStaff()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;

    if (x_click >= 40 && x_click <= 120 && y_click >= 10 && y_click < 12)
    {
        return 1; // ho ten
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 12 && y_click < 14)
    {
        return 2; // so dien thoai
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 14 && y_click < 16)
    {
        return 3; // ngay sinh
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 16 && y_click < 18)
    {
        return 4; // gioi tinh
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 18 && y_click < 20)
    {
        return 5; // ten dang nhap
    }
    if (x_click >= 40 && x_click <= 120 && y_click >= 20 && y_click < 22)
    {
        return 6; // mat khau
    }
    if (x_click >= 80 && x_click <= 92 && y_click >= 24 && y_click < 26)
    {
        return 7; // luu
    }
    if (x_click >= 93 && x_click <= 111 && y_click >= 24 && y_click <= 26)
    {
        return 8; // huy
    }
    if (x_click >= 40 && x_click <= 50 && y_click >= 6 && y_click < 8)
    {
        return 9; // Xoa
    }
    if (x_click >= 130 && x_click <= 131 && y_click > 4 && y_click < 6)
    {
        return 10; // X
    }
    return 0;
}
void Admin::editStaff()
{

    DoubleLinkedList<Staff> staffList;
    Staff staff;
    staff.readfromFile(staffList);
    int ID;
    gotoXY(40, 4);
    cout << "Chỉnh sửa thông tin nhân viên";
    gotoXY(40, 5);
    cout << "ID: ";
    lineWidth(10, 40, 6, true, true);
    gotoXY(40, 7);
    cout << "│          │" << endl;
    lineWidth(10, 40, 8, true, false);
    bool find = false;
    string str;
    int choice = getclick_editStaff();
    while (choice != 9)
    {
        choice = getclick_editStaff();
    }
    getString(str, 42, 7);
    ID = stoi(str);
    int k;
    Staff staffTemp;
    for (int i = 0; i < staffList.getSize(); i++)
    {
        if (staffList[i].returnID() == ID)
        {
            staffTemp = staffList[i];
            k = i;
            find = true;
            menu(staffList[i]);
            lineWidth(27, 80, 24, true, true);
            gotoXY(80, 25);
            cout << "│     Lưu    │     Hủy      │";
            lineWidth(27, 80, 26, true, false);
            showString("┬", 93, 24);
            showString("┴", 93, 26);
            int choicee;
            bool run = true;
            while (run)
            {
                string str_temp;
                choicee = getclick_editStaff();
                switch (choicee)
                {
                case 1:
                    gotoXY(54, 11);
                    cout << left << setw(25) << " ";
                    getString(str_temp, 54, 11);
                    staffList[i].setFullName(str_temp);
                    break;
                case 2:
                    gotoXY(57, 13);
                    cout << left << setw(25) << "";
                    getString(str_temp, 57, 13);
                    staffList[i].setPhoneNumber(str_temp);

                    break;
                case 3:
                    gotoXY(53, 15);
                    cout << left << setw(25) << " ";
                    getString(str_temp, 53, 15);
                    staffList[i].setDOB(str_temp);
                    break;
                case 4:
                    gotoXY(53, 17);
                    cout << left << setw(25) << " ";
                    getString(str_temp, 53, 17);
                    staffList[i].setGender(str_temp);
                    break;
                case 5:
                    gotoXY(57, 19);
                    cout << left << setw(25) << " ";
                    getString(str_temp, 57, 19);
                    staffList[i].setUserName(str_temp);
                    break;
                case 6:
                    gotoXY(52, 21);
                    cout << left << setw(25) << " ";
                    getString(str_temp, 52, 21);
                    staffList[i].setPassword(str_temp);
                    break;
                case 7:
                    staffList[i].saveAgainFile(staffList);
                    gotoXY(130, 25);
                    cout << "Sửa thành công";
                    this_thread::sleep_for(chrono::seconds(2));
                    gotoXY(130, 25);
                    cout << "               "; // Clear the success message
                    run = false;
                    break;
                case 8:

                    run = false;
                    break;
                }
            }
        }
    }
    if (find == false)
    {
        gotoXY(50, 10);
        cout << "Không tìm thấy thông tin!" << endl;
    }
    gotoXY(130, 5);
    cout << "❌";
    choice = getclick_editStaff();
    while (choice != 10)
    {
        choice = getclick_editStaff();
    }
    system("cls");
    menuAdmin_default(*this);
}
int getClick_removeStaff()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 40 && x_click <= 120 && y_click >= 7 && y_click <= 9)
    {
        return 1; // ID
    }
    if (x_click >= 120 && x_click <= 133 && y_click >= 23 && y_click <= 25)
    {
        return 2; // Xoa
    }
    if (x_click >= 133 && x_click <= 146 && y_click >= 23 && y_click <= 25)
    {
        return 3; // Huy
    }
    if (x_click >= 130 && x_click <= 131 && y_click > 4 && y_click < 6)
    {
        return 4; // X
    }
    return 0;
}
void Admin::removeStaff()
{
    DoubleLinkedList<Staff> staffList;
    bool count = false;
    Staff staff;
    staff.readfromFile(staffList);
    int ID;
    string str;
    gotoXY(40, 4);
    cout << "Xóa nhân viên";
    gotoXY(40, 5);
    cout << "Nhập ID ";
    lineWidth(10, 40, 6, true, true);
    gotoXY(40, 7);
    cout << "│          │" << endl;
    lineWidth(10, 40, 8, true, false);
    int choice = getClick_removeStaff();
    if (choice == 1)
    {
        getString(str, 42, 7);
    }
    ID = stoi(str);
    for (int i = 0; i < staffList.getSize(); i++)
    {
        if (staffList[i].returnID() == ID)
        {
            count = true;
            menu(staffList[i]);
            gotoXY(40, 23);
            lineWidth(27, 120, 23, true, true);
            gotoXY(120, 24);
            cout << "│     Xóa     │     Hủy     │";
            lineWidth(27, 120, 25, true, false);
            showString("┬", 134, 23);
            showString("┴", 134, 25);
            int choicee = getClick_removeStaff();
            if (choicee == 2)
            {
                staffList.earse(i);
                gotoXY(130, 27);
                cout << "Đã xóa thành công";
                this_thread::sleep_for(chrono::seconds(2));
                gotoXY(130, 27);
                cout << "                        "; // Clear the
            }
            else
                break;
        }
    }
    if (count == false)
    {
        gotoXY(50, 10);
        cout << "Không tìm thấy thông tin" << endl;
    }
    staff.saveAgainFile(staffList);
    gotoXY(130, 5);
    cout << "❌";
    choice = getClick_removeStaff();
    while (choice != 4)
    {
        choice = getClick_removeStaff();
    }
    system("cls");
    menuAdmin_default(*this);
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
int getClick_showStaff()
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
void Admin::showStaff(DoubleLinkedList<Staff> &staffList, int currentPage, int staffPerPage)
{
    for (int i = staffList.getSize() - 1; i >= 0; i--)
    {
        staffList.earse(i);
    }
    Staff staff;
    staff.readfromFile(staffList);
    int x = 8;
    int totalPage = ceil((double)staffList.getSize() / staffPerPage);
    int start = (currentPage - 1) * staffPerPage;
    int end = min(start + staffPerPage, staffList.getSize());
    showString("Danh sách nhân viên", 80, 5);
    lineWidth(113, 38, 6, true, true);
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
    lineHeight(end - start + 1, 126, 7, false, false, false);
    showString("┬", 126, 6);
    showString("Username", 128, 7);
    lineHeight(end - start + 1, 139, 7, false, false, false);
    showString("┬", 139, 6);
    showString("Password", 141, 7);
    lineHeight(end - start + 1, 152, 7, false, false, false);
    for (int i = start; i < end; i++)
    {

        lineWidth(113, 39, x + i - start, false, false);
        gotoXY(50, ++x + i - start);
        Staff staff = staffList[i];
        showString(to_string(i + 1), 40, x + i - start);
        showString(to_string(staff.returnID()), 47, x + i - start);
        showString(staff.getFullName(), 59, x + i - start);
        showString(staff.getPhoneNumber(), 83, x + i - start);
        showString(staff.getDOB(), 99, x + i - start);
        showString(staff.getGender(), 118, x + i - start);
        showString(staff.getUserName(), 128, x + i - start);
        showString(staff.getPassword(), 141, x + i - start);
    }
    lineHeight(end - start, 38, 8, true, false, false);
    lineHeight(end - start, 45, 8, false, false, true);
    lineHeight(end - start, 52, 8, false, false, true);
    lineHeight(end - start, 82, 8, false, false, true);
    lineHeight(end - start, 97, 8, false, false, true);
    lineHeight(end - start, 113, 8, false, false, true);
    lineHeight(end - start, 126, 8, false, false, true);
    lineHeight(end - start, 139, 8, false, false, true);
    lineHeight(end - start, 152, 8, false, true, false);
    lineWidth(113, 38, x + end - start, true, false);
    gotoXY(45, x + end - start);
    cout << "┴";
    gotoXY(52, x + end - start);
    cout << "┴";
    gotoXY(82, x + end - start);
    cout << "┴";
    gotoXY(97, x + end - start);
    cout << "┴";
    gotoXY(113, x + end - start);
    cout << "┴";
    gotoXY(126, x + end - start);
    cout << "┴";
    gotoXY(139, x + end - start);
    cout << "┴";
}
void Admin::savetoFile()
{
}
bool is_whitespace_utf8_a(char c)
{
    return std::isspace(static_cast<unsigned char>(c));
}

std::string Mytrim(const std::string &str)
{
    size_t start = 0;
    size_t end = str.size();

    // Loại bỏ khoảng trắng từ đầu chuỗi
    while (start < str.size() && is_whitespace_utf8_a(str[start]))
    {
        ++start;
    }

    // Loại bỏ khoảng trắng từ cuối chuỗi
    while (end > start && is_whitespace_utf8_a(str[end - 1]))
    {
        --end;
    }

    return str.substr(start, end - start);
}

void Admin::readfromFile(DoubleLinkedList<Admin> &admins)
{

    ifstream in;
    in.open("../Databases/AdminList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Lỗi không thể mở file");
    }
    string line;
    Admin admin;
    while (getline(in, line))
    {
        if (!line.empty() && line[0] == '#')
        {
            admin.ID = stoi(line.substr(1));
        }
        else if (line.find("Tên đăng nhập: ") == 0)
        {
            admin.username = Mytrim(line.substr(20));
        }
        else if (line.find("Mật khẩu: ") == 0)
        {
            admin.password = Mytrim(line.substr(13));
        }
        else if (line.find("Họ và tên: ") == 0)
        {
            admin.fullName = Mytrim(line.substr(15));
        }
        else if (line.find("Số điện thoại: ") == 0)
        {
            admin.phoneNumber = Mytrim(line.substr(22));
        }
        else if (line.find("Ngày sinh: ") == 0)
        {
            admin.dateOfBirth = Mytrim(line.substr(13));
        }
        else if (line.find("Giới tính: ") == 0)
        {
            admin.gender = Mytrim(line.substr(13));
            admins.push_back(admin);
            admin = Admin();
        }
    }
    in.close();
}
void Admin::saveAgainFile(DoubleLinkedList<Staff> &)
{
}
