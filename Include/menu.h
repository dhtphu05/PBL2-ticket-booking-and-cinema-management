
#include "layout.h"
#include "Admin.h"
#include "Staff.h"
#include "Customer.h"
#include "gotoXY.h"
#include "clickMouse.h"
#include <iostream>
#include <windows.h>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include "../Include/Booking.h"
#include "../Libraries/Booking.cpp"
using namespace std;
#ifndef MENU_H
#define MENU_H
int getClickProfile();
string BG_GREENN = "\033[32m";
string RESETT = "\033[0m";
void header_admin(string str1)
{
    lineWidth(120, 31, 3, false, false);

    gotoXY(0, 1);
    cout << "\033[1;37;44m"; // Màu nền xanh
    cout << " ◁ Quay lại ◁ " << "\033[0m" << endl;

    gotoXY(33, 1);
    cout << "💰 Doanh thu" << endl;
    gotoXY(50, 1);
    cout << "🎟️ Mã giảm giá  " << endl;
    gotoXY(71, 1);
    cout << "🎬 Rạp phim  " << endl;
    gotoXY(92, 1);
    cout << "🎫 Đặt vé  " << endl;
    gotoXY(112, 1);
    cout << "⚙️ Cài đặt  " << endl;
    gotoXY(130, 1);
    cout << "\033[1;31m" << "👤 " + str1 << "\033[0m" << endl;
}
int getClickAdmin_default()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 3 && x_click <= 20 && y_click >= 5 && y_click <= 5)
    {
        return 1; // Thêm nhân viên
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 6 && y_click <= 6)
    {
        return 2; // Xóa nhân viên
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 7 && y_click <= 7)
    {
        return 3; // Chỉnh sửa nhân viên
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 8 && y_click <= 8)
    {
        return 4; // Xem danh sách nhân viên
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 13 && y_click <= 13)
    {
        return 5; // Thêm khách hàng
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 14 && y_click <= 14)
    {
        return 6; // Xóa khách hàng
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 15 && y_click <= 15)
    {
        return 7; // Chỉnh sửa khách hàng
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 16 && y_click <= 16)
    {
        return 8; // Xem danh sách khách hàng
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 21 && y_click <= 21)
    {
        return 9; // Thêm show
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 22 && y_click <= 22)
    {
        return 10; // Xóa show
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 23 && y_click <= 23)
    {
        return 11; // Chỉnh sửa show
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 24 && y_click <= 24)
    {
        return 12; // Xem danh sách show
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 29 && y_click <= 29)
    {
        return 13; // Thêm phim
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 30 && y_click <= 30)
    {
        return 14; // Xóa phim
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 31 && y_click <= 31)
    {
        return 15; // Chỉnh sửa phim
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 32 && y_click <= 32)
    {
        return 16; // Xem danh sách phim
    }
    if (x_click >= 3 && x_click <= 20 && y_click >= 33 && y_click <= 33)
    {
        return 17; // Tìm kiếm phim
    }
    // quay lai
    if (x_click >= 0 && x_click <= 20 && y_click >= 1 && y_click <= 3)
    {
        return 18; // Quay lai
    }
    // doanh thu
    if (x_click >= 33 && x_click <= 45 && y_click >= 1 && y_click <= 3)
    {
        return 19; // Doanh thu
    }
    // ma giam gia
    if (x_click >= 50 && x_click <= 65 && y_click >= 1 && y_click <= 3)
    {
        return 20; // Ma giam
    }
    // rap ph
    if (x_click >= 71 && x_click <= 85 && y_click >= 1 && y_click <= 3)
    {
        return 21; // Rap phim
    }
    // dat ve
    if (x_click >= 92 && x_click <= 105 && y_click >= 1 && y_click <= 3)
    {
        return 22; // Dat ve
    }
    // cai dat
    if (x_click >= 112 && x_click <= 125 && y_click >= 1 && y_click <= 3)
    {
        return 23; // Cai dat
    }
    // biểu đồ
    if (x_click >= 3 && x_click <= 20 && y_click >= 17 && y_click <= 17)
    {
        return 24; // Bieu do
    }

    return 0;
}
void menuAdmin_default(Admin &admin)
{
    lineHeight_main(37, 30, 0);
    header_admin(admin.getFullName());
    // showString("*ADMINATOR*", 0, 0);
    lineWidth(14, 6, 2, true, true);
    showString("Nhân viên 👨‍💼", 8, 3);
    lineWidth(14, 6, 4, true, false);
    lineHeight(1, 6, 3, false, false, false);
    lineHeight(1, 21, 3, false, false, false);
    // khung nhan vien
    showString("• Thêm nhân viên", 3, 5);
    showString("• Xóa nhân viên", 3, 6);
    showString("• Chỉnh sửa nhân viên", 3, 7);
    showString("• Xem danh sách nhân viên", 3, 8);

    // khung khach hang
    lineWidth(14, 6, 10, true, true);
    showString("Khách hàng 👤", 8, 11);
    lineWidth(14, 6, 12, true, false);
    lineHeight(1, 6, 11, false, false, false);
    lineHeight(1, 21, 11, false, false, false);
    showString("• Thêm khách hàng", 3, 13);
    showString("• Xóa khách hàng", 3, 14);
    showString("• Chỉnh sửa khách hàng", 3, 15);
    showString("• Xem danh sách khách hàng", 3, 16);
    showString("• Biểu đồ tuổi", 3, 17);
    // khung show
    lineWidth(14, 6, 18, true, true);
    showString("Show 📺", 11, 19);
    lineWidth(14, 6, 20, true, false);
    lineHeight(1, 6, 19, false, false, false);
    lineHeight(1, 21, 19, false, false, false);
    showString("• Thêm show", 3, 21);
    showString("• Xóa show", 3, 22);
    showString("• Chỉnh sửa show", 3, 23);
    showString("• Xem danh sách show", 3, 24);
    // khung phim
    lineWidth(14, 6, 26, true, true);
    showString("Phim 🎬", 11, 27);
    lineWidth(14, 6, 28, true, false);
    lineHeight(1, 6, 27, false, false, false);
    lineHeight(1, 21, 27, false, false, false);
    showString("• Thêm phim", 3, 29);
    showString("• Xóa phim", 3, 30);
    showString("• Chỉnh sửa phim", 3, 31);
    showString("• Xem danh sách phim", 3, 32);
    showString("• Tìm kiếm phim", 3, 33);
    // khung screen
    lineWidth(14, 6, 35, true, true);
    showString("Screen 📽️", 11, 36);
    lineWidth(14, 6, 37, true, false);
    lineHeight(1, 6, 36, false, false, false);
    lineHeight(1, 21, 36, false, false, false);
}
int getClick_showMovie()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 80 && x_click <= 92 && y_click >= 22 && y_click <= 24)
    {
        return 1; // Previous
    }
    if (x_click >= 92 && x_click <= 101 && y_click >= 22 && y_click <= 24)
    {
        return 2; // Next
    }
    if (x_click >= 102 && x_click <= 115 && y_click >= 22 && y_click <= 24)
    {
        return 3; // Quit
    }
    if (x_click >= 35 && x_click <= 150 && y_click >= 10 && y_click <= 12)
    {
        return 11;
    }
    if (x_click >= 35 && x_click <= 150 && y_click >= 12 && y_click <= 14)
    {
        return 12;
    }
    if (x_click >= 35 && x_click <= 150 && y_click >= 14 && y_click <= 16)
    {
        return 13;
    }
    if (x_click >= 35 && x_click <= 150 && y_click >= 16 && y_click <= 18)
    {
        return 14;
    }
    if (x_click >= 35 && x_click <= 150 && y_click >= 18 && y_click <= 20)
    {
        return 15;
    }

    return 0;
}
int getClick_searchMovie()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 40 && x_click <= 80 && y_click >= 5 && y_click <= 7)
    {
        return 1; // ten phim
    }
    return 0;
}
int getClick_showDetailMovie()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 120 && x_click <= 138 && y_click >= 30 && y_click <= 32)
    {
        return 1; // dat ve
    }
    return 0;
}
void dashBoard_admin(Admin *admin, DoubleLinkedList<Movie> &movieList, DoubleLinkedList<Staff> &staffList, DoubleLinkedList<Customer> &customerList)
{
    bool loggedIn = true;
    int choice;
    {
        bool loggedIn = true;
        int choice;
    dashBoard_admin:
        menuAdmin_default(*admin); // hàm ở phía trên luôn nhé
        while (loggedIn)
        {
            choice = getClickAdmin_default(); // hàm ở phía trên luôn nhé
            switch (choice)
            {
            case 1:
            {
                system("cls");
                menuAdmin_default(*admin);
                admin->addStaff();
                goto dashBoard_admin;
                break;
            }
            case 2:
            {
                system("cls");
                menuAdmin_default(*admin);
                admin->removeStaff();
                goto dashBoard_admin;
                break;
            }
            case 3:
            {
                system("cls");
                menuAdmin_default(*admin);
                admin->editStaff();
                goto dashBoard_admin;
                break;
            }
            case 4:
            {
                int currentPage = 1;
                int staffPerPage = 5;
                int choice;
                while (true)
                {
                    admin->showStaff(staffList, currentPage, staffPerPage);
                    lineWidth(35, 80, 22, true, true);
                    gotoXY(80, 23);
                    cout << "│👈 Previous | Next 👉 |   Quit ❌  │";
                    lineWidth(35, 80, 24, true, false);

                    choice = getClick_showMovie();
                    if (choice == 2) 
                    {
                        if (currentPage * staffPerPage < staffList.getSize())
                        {
                            currentPage++;
                        }
                    }
                    else if (choice == 1) 
                    {
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                    }
                    else if (choice == 3) 
                    {
                        break;
                    }
                    system("cls");
                    menuAdmin_default(*admin);
                }
                system("cls");
                goto dashBoard_admin;
                break;
            }
            case 5:
            {
                system("cls");
                menuAdmin_default(*admin);
                admin->addCustomer();
                goto dashBoard_admin;
                break;
            }
            case 6:
            {
                system("cls");
                menuAdmin_default(*admin);
                admin->removeCustomer();
                goto dashBoard_admin;
                break;
            }
            case 7:
            {
                system("cls");
                menuAdmin_default(*admin);
                admin->editCustomer();
                goto dashBoard_admin;
                break;
            }
            case 8:
            {
                int currentPage = 1;
                int customerPerPage = 5;
                int choice;
                while (true)
                {
                    admin->showCustomer(customerList, currentPage, customerPerPage);
                    lineWidth(35, 80, 22, true, true);
                    gotoXY(80, 23);
                    cout << "│👈 Previous | Next 👉 |   Quit ❌  │";
                    lineWidth(35, 80, 24, true, false);

                    choice = getClick_showMovie();
                    if (choice == 2) 
                    {
                        if (currentPage * customerPerPage < customerList.getSize())
                        {
                            currentPage++;
                        }
                    }
                    else if (choice == 1) 
                    {
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                    }
                    else if (choice == 3) 
                    {
                        break;
                    }
                    system("cls");
                    menuAdmin_default(*admin);
                }
                system("cls");
                goto dashBoard_admin;
                break;
            }

            case 9:
            {
                // admin-> addShow();
                break;
            }
            case 10:
            {
                // admin-> removeShow();
                break;
            }
            case 11:
            {
                // admin-> editShow();
                break;
            }
            case 12:
            {
                // admin-> showShow();
                break;
            }
            case 13:
            {
                admin->addMovie();
                goto dashBoard_admin;
                break;
            }
            case 14:
            {
                admin->removeMovie();
                goto dashBoard_admin;
                break;
            }
            case 15:
            {
                admin->editMovie();
                goto dashBoard_admin;
                break;
            }
            case 16:
            {
                int currentPage = 1;
                int moviesPerPage = 5;
                int choice;
                while (true)
                {
                    admin->showMovie(movieList, currentPage, moviesPerPage, 0);
                    lineWidth(35, 80, 22, true, true);
                    gotoXY(80, 23);
                    cout << "│👈 Previous | Next 👉 |   Quit ❌  │";
                    lineWidth(35, 80, 24, true, false);
            
                    choice = getClick_showMovie();
                    if (choice == 11 || choice == 12 || choice == 13 || choice == 14 || choice == 15)
                    {
                        system("cls");
                        menuAdmin_default(*admin);
                        movieList[choice - 11 + (currentPage - 1) * 5].showDetailMovie();
                    }

                    choice = getClick_showMovie();
                    if (choice == 2) 
                    {
                        if (currentPage * moviesPerPage < movieList.getSize())
                        {
                            currentPage++;
                        }
                    }
                    else if (choice == 1) 
                    {
                        if (currentPage > 1)
                        {
                            currentPage--;
                        }
                    }
                    else if (choice == 3) 
                    {
                        break;
                    }
                    system("cls");
                    menuAdmin_default(*admin);
                }
                // system("cls");
                // goto dashBoard_admin;

                system("cls");
                goto dashBoard_admin;
                break;
            }

            case 17:
            {

                string line;
                gotoXY(40, 4);
                cout << "Tìm kiếm phim";
                lineWidth(38, 40, 5, true, true);
                gotoXY(40, 6);
                cout << "│                                      │";
                lineWidth(38, 40, 7, true, false);
                int choice = getClick_searchMovie();
                while (choice != 1)
                {
                    choice = getClick_searchMovie();
                }
                getString(line, 42, 6);
                admin->searchMovie(line);
                goto dashBoard_admin;
                break;
            }
            case 18:
            {
                loggedIn = false;
                break;
            }
            case 19:
            {
                // admin->revenue();
                break;
            }
            case 20:
            {
                // admin->discountCode();
                break;
            }
            case 21:
            {
                // admin->cinema();
                break;
            }
            case 22:
            {
                // admin->bookTicket();
                break;
            }
            case 23:
            {
                // admin->setting();
                break;
            }
            case 24:
            {
                system("cls");
                menuAdmin_default(*admin);
                showChartAgeCustomer(customerList);
                system("cls");
                goto dashBoard_admin;
                break;
            }

            default:
            {
                choice = getClickAdmin_default();
                break;
            }
            }
        }
    }
}
void menu_footer()
{

    lineWidth(128, 0, 32, false, false);
    gotoXY(1.5, 34);
    cout << "INTRODUCTION " << endl;
    gotoXY(1.5, 36);
    cout << "About us" << endl;
    gotoXY(1.5, 38);
    cout << "Privacy Policy" << endl;
    gotoXY(1.5, 40);
    cout << "FAQ" << endl;
    gotoXY(60, 42);
    cout << "MOVIE TICKET SALES MANAGEMENT" << endl;
    gotoXY(50, 34);
    cout << "BUY TICKET" << endl;
    gotoXY(50, 36);
    cout << "Movie Showtimes" << endl;
    gotoXY(50, 38);
    cout << "Top Movies" << endl;
    gotoXY(50, 40);
    cout << "Movie Blog" << endl;
    gotoXY(95, 34);
    cout << "SUPPORT" << endl;
    gotoXY(95, 36);
    cout << "Feedback" << endl;
    gotoXY(95, 38);
    cout << "Sales & Services" << endl;
    gotoXY(130, 34);
    cout << "FOLLOW US" << endl;
    gotoXY(130, 36);
    cout << "Facebook" << endl;
    gotoXY(130, 38);
    cout << "Hotline: 0334105228" << endl;
}
void menu_header(string message1, string message2)
{
    lineWidth(19, 100, 1, true, true);
    lineHeight(1, 100, 2, false, false, false);
    showString(message1, 105, 2);
    lineHeight(1, 100 + 20, 2, false, false, false);
    lineWidth(19, 100, 3, true, false);

    lineWidth(19, 130, 1, true, true);
    lineHeight(1, 130, 2, false, false, false);
    showString(message2, 135, 2);
    lineHeight(1, 130 + 20, 2, false, false, false);
    lineWidth(19, 130, 3, true, false);
    lineWidth(10, 8, 1, true, true);
    showString("MUA VÉ🎟️", 10, 2);
    lineHeight(1, 8, 2, false, false, false);
    lineHeight(1, 19, 2, false, false, false);
    lineWidth(10, 8, 3, true, false);
    gotoXY(30, 2.5);
    cout << "🎬 Phim" << endl;
    gotoXY(44, 2.5);
    cout << "🎉 Sự kiện" << endl;
    gotoXY(58, 2.5);
    cout << "🔍 Tìm kiếm" << endl;
}
void menu_middle_date_showmovie()
{
    cout << BG_GREENN;
    lineWidth(10, 60, 11, true, true);
    showString("│ Hôm nay  │", 60, 12);
    showString("│  28/11   │", 60, 13);
    lineWidth(10, 60, 14, true, false);
    cout << RESETT;
    lineWidth(10, 75, 11, true, true);
    showString("│ Thứ sáu  │", 75, 12);
    showString("│  29/11   │", 75, 13);
    lineWidth(10, 75, 14, true, false);
    lineWidth(10, 90, 11, true, true);
    showString("│  Thứ bảy │", 90, 12);
    showString("│  30/11   │", 90, 13);
    lineWidth(10, 90, 14, true, false);
    lineWidth(10, 105, 11, true, true);
    showString("│ Chủ nhật │", 105, 12);
    showString("│  01/12   │", 105, 13);
    lineWidth(10, 105, 14, true, false);
    lineWidth(10, 120, 11, true, true);
    showString("│ Thứ hai  │", 120, 12);
    showString("│  02/12   │", 120, 13);
    lineWidth(10, 120, 14, true, false);
    lineWidth(10, 135, 11, true, true);
    showString("│  Thứ ba  │", 135, 12);
    showString("│  03/12   │", 135, 13);
    lineWidth(10, 135, 14, true, false);
}
int getClickInfor()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 50 && x_click <= 119 && y_click >= 12 && y_click <= 14)
    {
        return 1; // ho ten
    }
    if (x_click >= 50 && x_click <= 119 && y_click >= 16 && y_click <= 18)
    {
        return 2; // so dien thoai
    }
    if (x_click >= 50 && x_click <= 119 && y_click >= 20 && y_click <= 22)
    {
        return 3; // ngay sinh
    }
    if (x_click >= 50 && x_click <= 119 && y_click >= 24 && y_click <= 26)
    {
        return 4; // gioi tinh
    }

    if (x_click >= 100 && x_click <= 115 && y_click >= 27 && y_click <= 29)
    {
        return 5; // cap nhat thong tin
    }
    if (x_click >= 130 && x_click <= 145 && y_click >= 27 && y_click <= 29)
    {
        return 6; // luu thong tin
    }
    return 0;
}

std::string customInput(int x, int y)
{
    std::string input;
    char ch;

    gotoXY(x, y);
    while (true)
    {
        ch = _getch(); // Đọc từng ký tự

        if (ch == '\r')
        { // Enter để kết thúc nhập liệu
            break;
        }
        else if (ch == '\b' && !input.empty())
        { // Xóa ký tự
            input.pop_back();
            std::cout << '\b' << ' ' << '\b';
        }
        else if (isprint(ch))
        { // Chỉ nhận ký tự in được
            input += ch;
            std::cout << ch;
        }
    }
    return input;
}

void infor(Customer *customer, DoubleLinkedList<Customer> &customerList)
{
    lineWidth(69, 50, 12, true, true);
    showString("Họ và tên: ", 51, 11);
    showString(customer->getFullName(), 52, 13);
    lineWidth(69, 50, 14, true, false);
    lineHeight(1, 50, 13, false, false, false);
    lineHeight(1, 120, 13, false, false, false);
    lineWidth(69, 50, 16, true, true);
    showString("Số điện thoại: ", 51, 15);
    showString(customer->getPhoneNumber(), 52, 17);
    lineWidth(69, 50, 18, true, false);
    lineHeight(1, 50, 17, false, false, false);
    lineHeight(1, 120, 17, false, false, false);
    lineWidth(69, 50, 20, true, true);
    showString("Ngày sinh: ", 51, 19);
    showString(customer->getDOB(), 52, 21);
    lineWidth(69, 50, 22, true, false);
    lineHeight(1, 50, 21, false, false, false);
    lineHeight(1, 120, 21, false, false, false);
    lineWidth(69, 50, 24, true, true);

    showString("Giới tính: ", 51, 23);
    showString(customer->getGender(), 52, 25);
    lineWidth(69, 50, 26, true, false);
    lineHeight(1, 50, 25, false, false, false);
    lineHeight(1, 120, 25, false, false, false);
    // lineHeight(4, 50, 11, false, false, false);
    // lineHeight(4, 120, 11, false, false, false);
    // lineHeight(3, 50, 12, true, false, false);
    // lineHeight(3, 120, 12, false, true, false);
    lineWidth(11, 100, 27, true, true);
    showString("│ Chỉnh sửa │", 100, 28);
    lineWidth(11, 100, 29, true, false);
    lineWidth(11, 130, 27, true, true);
    showString("│   LƯU     │", 130, 28);
    lineWidth(11, 130, 29, true, false);

    bool running = true;
    int choice = getClickProfile(); // click vao ô cập nhật thông tin
    if (choice == 6)
    {
        while (running)
        {

            int choice_e = getClickInfor();

            // resetConsoleState();
            switch (choice_e)
            {
            case 1: // click vào ô họ và tên để sửa
            {
                string str;
                gotoXY(52, 13);
                cout << "                                ";
                getString(str, 52, 13);
                customer->setFullName(str);
                choice_e = getClickProfile();
                break;
            }
            case 2:
            {
                string str;
                gotoXY(52, 17);
                cout << "                                ";
                getString(str, 52, 17);
                customer->setPhoneNumber(str);
                choice_e = getClickProfile();
                break;
            }
            case 3:
            {
                string str;
                gotoXY(52, 21);
                cout << "                                ";
                getString(str, 52, 21);
                customer->setDOB(str);
                choice_e = getClickProfile();
                break;
            }
            case 4:
            {
                string str;
                gotoXY(52, 25);
                cout << "                                ";
                getString(str, 52, 25);
                customer->setGender(str);
                choice_e = getClickProfile();
            }
            case 5:
            {
                running = false;
                break;
            }
            case 6:
            {

                customer->saveAgainFile(customerList);
                running = false;
                break;
            }
            default:
                choice_e = getClickInfor();
                break;
            }
        }
    }
}
int getClickProfile()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;

    if (x_click >= 53 && x_click <= 73 && y_click >= 8 && y_click <= 10)
    {
        return 1; // lich su giao dich
    }
    if (x_click >= 75 && x_click <= 95 && y_click >= 8 && y_click <= 10)
    {
        return 2; // thong tin ca nhan
    }
    if (x_click >= 90 && x_click <= 110 && y_click >= 8 && y_click <= 10)
    {
        return 3; // qua tang
    }
    if (x_click >= 105 && x_click <= 125 && y_click >= 8 && y_click <= 10)
    {
        return 4; // thong bao
    }
    if (x_click >= 130 && x_click <= 150 && y_click >= 1 && y_click <= 3)
    {
        return 5; // back
    }
    if (x_click >= 100 && x_click <= 110 && y_click >= 27 && y_click <= 29)
    {
        return 6; // cap nhat thong tin
    }
    return 0;
    //! section xem thong tin ve ca nhan
}
void setTextColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void profilePage(Customer *customer, DoubleLinkedList<Customer> &customerList, DoubleLinkedList<Booking> bookingList)
{
dashboard_profile:
    Booking booking;
    booking.loadBookingFromFile(bookingList, customerList);
    showString("Lịch sử giao dịch", 53, 8);
    showString("Thông tin cá nhân", 75, 8);
    showString("Quà tặng", 97, 8);
    showString("Thông báo", 110, 8);
    lineWidth(70, 50, 9, false, false);
    int choice;
    choice = getClickProfile();
    bool runing = true;
dashBoard_while:
    while (runing)
    {

        switch (choice)
        {
        case 1:
        {
            // bắt đầu in ra từ đoạn ni
            DoubleLinkedList<Booking> bookingListOfCustomer;
            getListBookingOfCustomer(customer, bookingList, bookingListOfCustomer);
            cout << bookingListOfCustomer.getSize();
            displayListBookingLikeTableOfCustomer(customer, bookingList, 5, 20);
            int chooseBooking = getClickBookingDetail(bookingListOfCustomer, 5, 20);
            system("cls");
            cout << chooseBooking;
            displayBookingDetailFollowIndex(bookingListOfCustomer, chooseBooking, 5, 20);
            choice = getClickProfile();
            system("cls");
            menu_header("🧑" + customer->getUserName(), "Quay lại");
            goto dashboard_profile; // lich su giao dich
            break;
        }
        case 2:
        {
            // thong tin ca nhan
            infor(customer, customerList);
            choice = getClickProfile();
            system("cls");
            menu_header("🧑" + customer->getUserName(), "Quay lại");
            goto dashboard_profile; // lich su giao dich
            break;
        }
        case 3:
        {
            gotoXY(50, 20);
            cout << "Quà tặng"; // qua tang
            choice = getClickProfile();
            system("cls");
            menu_header("🧑" + customer->getUserName(), "Quay lại");
            goto dashboard_profile; // lich su giao dich
            break;
        }
        case 4:
        {
            // thong bao
            gotoXY(50, 20);
            cout << "Thông báo";
            choice = getClickProfile();
            system("cls");
            menu_header("🧑" + customer->getUserName(), "Quay lại");
            goto dashboard_profile; // lich su giao dich
            break;
        }
        case 5:
        {
            runing = false;
            break;
        }
        case 6:
        {
            runing = false;
            break;
        }
        default:
            system("cls");
            goto dashBoard_while; // lich su giao dich
            break;
        }
    }
}
int getClickTicktet()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 40 && x_click <= 58 && y_click >= 7 && y_click <= 9)
    {
        return 1; // chon phim
    }
    if (x_click >= 62 && x_click <= 80 && y_click >= 7 && y_click <= 9)
    {
        return 2; // chon ghe
    }
    if (x_click >= 74 && x_click <= 92 && y_click >= 7 && y_click <= 9)
    {
        return 3; // qua tang
    }
    if (x_click >= 87 && x_click <= 105 && y_click >= 7 && y_click <= 9)
    {
        return 4; // chon thuc an
    }
    if (x_click >= 105 && x_click <= 123 && y_click >= 7 && y_click <= 9)
    {
        return 5; // thanh toan
    }
    if (x_click >= 120 && x_click <= 138 && y_click >= 7 && y_click <= 9)
    {
        return 6; // xac nhan
    }
    if (x_click >= 130 && x_click <= 150 && y_click >= 1 && y_click <= 3)
    {
        return 7; // Quay lại
    }
    return 0;
}
void buyTicket(Customer *customer)
{

    showString("Chọn phim/ suất chiếu 🎬", 40, 8);
    showString("Chọn ghế 🎥", 62, 8);
    showString("Quà tặng 🎁", 74, 8);
    showString("Chọn thức ăn 🍿", 87, 8);
    showString("Thanh toán 💳", 105, 8);
    showString("Xác nhận ✅", 120, 8);
    lineWidth(90, 38, 10, false, false);

    int choice = getClickTicktet();
    bool runing = true;
    while (runing)
    {
        switch (choice)
        {
        case 1:
        {
            gotoXY(50, 20);
            cout << "Chọn phim/ suất chiếu"; // lich su giao dich
            choice = getClickTicktet();
            break;
        }
        case 2:
        {
            // thong tin ca nhan
            gotoXY(50, 20);
            cout << "Chọn ghế";
            choice = getClickTicktet();
            break;
        }
        case 3:
        {
            gotoXY(50, 20);
            cout << "Quà tặng"; // qua tang
            choice = getClickTicktet();
            break;
        }
        case 4:
        {
            // thong bao
            gotoXY(50, 20);
            cout << "Chọn thức ăn";
            choice = getClickTicktet();
            break;
        }
        case 5:
        {
            // thong bao
            gotoXY(50, 20);
            cout << "Thanh toán";
            choice = getClickTicktet();
            break;
        }
        case 6:
        {
            // thong bao
            gotoXY(50, 20);
            cout << "Xác nhận";
            choice = getClickTicktet();
            break;
        }
        case 7:
        {
            runing = false;
            break;
        }
        default:
            choice = getClickTicktet();
            break;
        }
        system("cls");
        menu_header("🧑" + customer->getUserName(), "Quay lại");
        showString("Chọn phim/ suất chiếu 🎬", 40, 8);
        showString("Chọn ghế 🎥", 62, 8);
        showString("Quà tặng 🎁", 74, 8);
        showString("Chọn thức ăn 🍿", 87, 8);
        showString("Thanh toán 💳", 105, 8);
        showString("Xác nhận ✅", 120, 8);
        lineWidth(90, 38, 10, false, false);
    }
}
// staff'
int getClick_menuHeader()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 0 && x_click <= 20 && y_click >= 1 && y_click <= 3)
    {
        return 1; // Quay lai
    }
    if (x_click >= 10 && x_click <= 20 && y_click >= 2 && y_click <= 4)
    {
        return 2; // Thong tin ca nhan
    }
    if (x_click >= 20 && x_click <= 30 && y_click >= 2 && y_click <= 4)
    {
        return 3; // Doanh thu
    }
    if (x_click >= 30 && x_click <= 40 && y_click >= 2 && y_click <= 4)
    {
        return 4; // Ma giam gia
    }
    if (x_click >= 40 && x_click <= 50 && y_click >= 2 && y_click <= 4)
    {
        return 5; // Rap phim
    }
    if (x_click >= 50 && x_click <= 60 && y_click >= 2 && y_click <= 4)
    {
        return 6; // Dat ve
    }
    if (x_click >= 60 && x_click <= 70 && y_click >= 2 && y_click <= 4)
    {
        return 7; // Cai dat
    }
    return 0;
}
void dashBoard_staff(Staff *staff)
{
    menu_header("👨‍💼" + staff->getFullName(), "Quay lại");
}
#endif