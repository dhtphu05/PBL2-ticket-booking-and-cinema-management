#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <windows.h>
// #include "Movie.cpp"
// #include "customer.cpp"
#include "staff.cpp"
#include "admin.cpp"
#include "login.cpp"
// #include "User.cpp"
#include "conio.h"  
#include "movie.cpp"
#include <cmath>
#include "../Include/menu.h"
// #include "../Include/Booking.h"
#include "Booking.cpp"
#define byte windows_byte
#include <windows.h>
#undef byte 
using namespace std;
// todo: chỉnh sửa exception ở movie và thêm events nữa với làm báo cáo nữa chứ sắp hết time ôn thi rồi huhuh
// todo: còn cái kiểm tra username tồn tại hay chưa nữa, à và cái regex cho them file chỗ phim nữa

int getMouseDashBoardCustomer()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 100 && x_click <= 120 && y_click >= 1 && y_click <= 3)
    {
        return 1; // trang ca nhan
    }
    if (x_click >= 130 && x_click <= 150 && y_click >= 1 && y_click <= 3)
    {

        return 2; // dang xuat
    }
    if (x_click >= 8 && x_click <= 18 && y_click >= 1 && y_click <= 3)
    {
        return 3; // mua ve
    }
    if (x_click >= 30 && x_click <= 40 && y_click >= 1 && y_click <= 3)
    {
        return 4; // phim
    }
    if (x_click >= 45 && x_click <= 55 && y_click >= 1 && y_click <= 3)
    {
        return 5; // su kien
    }
    if (x_click >= 60 && x_click <= 70 && y_click >= 1 && y_click <= 3)
    {
        return 6; // tim kiem;
    }
    return 0;
}
void dashBoard_customer(Customer *customer, DoubleLinkedList<Customer> &customerList,DoubleLinkedList<Booking> &bookingList, DoubleLinkedList<Show> &shows, DoubleLinkedList<Screen> &screens, DoubleLinkedList<Movie> &movies)
{
    bool loggedIn = true;
    int choice;

    while (loggedIn)
    {
        // Hiển thị menu chính
        system("cls");
        menuLogin("🧑" + customer->getUserName(), "Đăng xuất");

        // int a;cin>>a;
        // return;
        // Lấy lựa chọn từ người dùng
        choice = getMouseDashBoardCustomer();

        // Xử lý lựa chọn                   
        Booking booking;
        switch (choice)
        {
        case 1:
            // Hiển thị thông tin cá nhân 
            system("cls");
            menu_header("🧑" + customer->getUserName(), "Quay lại");
            // choice = getMouseDashBoardCustomer();
            // hàm này ở menu.h nhé
            profilePage(customer, customerList, bookingList); // hàm này ở menu.h nhé
            //! chui vo day
            break;
        case 4:
            // Thêm chức năng khác, ví dụ: Xem dịch vụ
            system("cls");
            menu_header("🧑" + customer->getUserName(), "Quay lại");
            gotoXY(50, 20);
            cout << "Phim";
            choice = getMouseDashBoardCustomer();
            // viewServices(customer); // Hàm xử lý dịch vụ
            break;

        case 3:
            //! mua vé
            system("cls");
            booking.setCustomer(customer);
            menu_header("🧑" + customer->getUserName(), "Quay lại");
            buyTicket(customer, booking, shows,screens,movies);
            choice = getMouseDashBoardCustomer();
            // viewTransactionHistory(customer); // Hàm xử lý lịch sử
            break;

        case 2:
            // Đăng xuất
            loggedIn = false;

            break;
        default:
            // Lựa chọn không hợp lệ
            choice = getMouseDashBoardCustomer();
            break;
        }
    }
}

int main()
{
    DoubleLinkedList<Admin> adminList;
    DoubleLinkedList<Staff> staffList;
    DoubleLinkedList<Customer> customerList;
    DoubleLinkedList<Movie> movieList;
    DoubleLinkedList<Booking> bookingList;
    
    int k;
    User *user = new User();
    SetConsoleOutputCP(65001);
    SetConsoleCP(CP_UTF8);
    //    cout <<"HIHI XIN CHÀO MỌI NGƯỜI";
    Booking booking;
    DoubleLinkedList<Screen> screens;
    Screen screen;
    screen.loadScreenFromFile(screens);
    Movie movie;
    movie.readFile(movieList);
    DoubleLinkedList<Show> shows;
    Show show;
    show.loadShowFromFile(shows, screens);

// booking.sellTicket(shows,screens,movieList);

// show.displayAllShow(shows);
// Node<Show> *current = shows.begin();

// layoutBorderSeat(&current->data);
// booking.sellTicket(shows,screens,movies);
dashboard:
    bool loggedIn = false;
dashboard_main:

    int log = logIn(adminList, staffList, customerList, k);
    // int log =1;

    if (log == 1) // nguoi dung là admin
    {
        Admin *admin = &adminList[k];
        dashBoard_admin(admin,bookingList,shows,screens, movieList,staffList,customerList);//hàm này ở menu.h nhé
        system("cls");
        menuLogin("Đăng nhập", "Đăng ký");

        goto dashboard_main;
    }
    else if (log == 2) // nguoi dung là staff
    {
    }
    else if (log == 3)
    {
        
        Customer *customerPtr = &customerList[k]; 
        dashBoard_customer(customerPtr, customerList, bookingList, shows, screens, movieList);
        system("cls");

        goto dashboard_main;
    }
    else if (log == 4)
    {

        Customer *customer = &customerList[customerList.getSize() - 1];
        dashBoard_customer(customer, customerList, bookingList, shows, screens, movieList);
        // system("cls");
        click = processInputEvents();
        int xclick, yclick;
        xclick = click.X;
        yclick = click.Y;
        if (xclick > 10 && xclick < 100 && yclick > 25 && yclick < 40)
        {
            booking.sellTicket(shows, screens, movieList);
            return 0;
        }
        goto dashboard_main;
    }
    else
    {
        cout << "Lựa chọn không hợp lệ!" << endl;
    }
    return 0;
}
