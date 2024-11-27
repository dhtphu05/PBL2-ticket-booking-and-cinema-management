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
// #include "../Include/Booking.h"
#include "Booking.cpp"
#define byte windows_byte
#include <windows.h>
#undef byte

using namespace std;

//!! ghe disable bi looix luc ghi lai vao file show.txt, kha nang la do ham editstatus
//!!
void header_admin(string str1)
{
    int x = 0;
    for (int i = 0; i < 155; i++)
    {
        gotoXY(x, 3); 
        cout << "_";
        x++;
    }
    gotoXY(0, 0);
    cout << "+-----------+" << endl;
    gotoXY(0, 1);
    cout << "| 0.BACK    |" << endl;
    gotoXY(0, 2);
    cout << "+-----------+" << endl;
    gotoXY(28, 1);
    cout << "1. VIEW BENEFITS <>" << endl;
    gotoXY(50, 1);
    cout << "2. VOUCHER <>" << endl;
    gotoXY(71, 1);
    cout << "3. CINEMA <>" << endl;
    gotoXY(92, 1);
    cout << "4. ROOM <>" << endl;
    gotoXY(112, 1);
    cout << "5. BOOKING <>" << endl;
    gotoXY(130, 1);
    cout << "\033[1;31m" << str1 + " <>" << "\033[0m" << endl;
}
void menuAdmin_default(Admin &admin)
{
    int y = 3;
    int x = 0;
    for (int i = 0; i < 38; i++)
    {
        gotoXY(28, y);
        cout << "|";
        y++;
    }
    header_admin(admin.getFullName());
    gotoXY(5, 5);
    cout << "I.STAFF MANAGEMENT" << endl;
    gotoXY(5, 7);
    cout << "11 Remove staff" << endl;
    gotoXY(5, 8);
    cout << "12 Add staff" << endl;
    gotoXY(5, 9);
    cout << "13 Edit staff" << endl;
    gotoXY(5, 10);
    cout << "14 View staff list" << endl;
    gotoXY(5, 12);
    cout << "II.CUSTOMER MANAGEMENT" << endl;
    gotoXY(5, 14);
    cout << "21 Remove customer" << endl;
    gotoXY(5, 15);
    cout << "22 Add customer" << endl;
    gotoXY(5, 16);
    cout << "23 Edit customer" << endl;
    gotoXY(5, 17);
    cout << "24 View customer list" << endl;
    gotoXY(5, 19);
    cout << "III.MOVIE MANAGEMENT" << endl;
    gotoXY(5, 21);
    cout << "31 Remove movie" << endl;
    gotoXY(5, 22);
    cout << "32 Add movie" << endl;
    gotoXY(5, 23);
    cout << "33 Edit movie" << endl;
    gotoXY(5, 24);
    cout << "34 Top movie " << endl;
    gotoXY(5, 25);
    cout << "35 View movie" << endl;

    gotoXY(5, 26);
    cout << "36 Search movie" << endl;
}

int main()
{
    DoubleLinkedList<Admin> adminList;
    DoubleLinkedList<Staff> staffList;
    DoubleLinkedList<Customer> customerList;
    DoubleLinkedList<Movie> movieList34;
    int k;
    SetConsoleOutputCP(65001);
    //    cout <<"HIHI XIN CHÀO MỌI NGƯỜI";
    Booking booking;
    DoubleLinkedList<Screen> screens;
    Screen screen;
    screen.loadScreenFromFile(screens); 
    Movie movie;
    movie.readFile(movieList34); 
    DoubleLinkedList<Show> shows;
    Show show;
    show.loadShowFromFile(shows,screens);
    // show.displayAllShow(shows);
    // Node<Show> *current = shows.begin();
    
    // layoutBorderSeat(&current->data);
    //booking.sellTicket(shows,screens,movies);
    dashboard: 
    bool loggedIn = false;
    int log = logIn(adminList, staffList, customerList, k);
    // int log =1;
    if (log == 1 )

    {
        loggedIn = true;
        bool running = true;

        while (loggedIn)
        {
            

            bool running = true;
            while (running)
            {

                menuAdmin_default(adminList[k]);
                int choice, _choice34;
                // cout << "Please enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 99:
                    system("cls");
                    running = true;
                    loggedIn = true;
                    goto dashboard;
                    break;
                case 12:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].addStaff();
                    gotoXY(130, 4);
                    cout << "DONE";
                    Sleep(2000);
                    system("cls");
                    break;
                case 14:
                    system("cls");
                    // menuAdmin_default();
                    adminList[k].showStaff();
                    // gotoXY(130, 4);
                    // cout << "DONE";
                    // Sleep(2000);
                    // system("cls");
                    break;
                case 13:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].editStaff();
                    Sleep(2000);
                    system("cls");
                    break;
                case 11:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].removeStaff();
                    Sleep(2000);
                    system("cls");
                    break;
                case 22:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].addCustomer();
                    gotoXY(130, 4);
                    cout << "DONE";
                    Sleep(2000);
                    system("cls");
                    break;
                case 24:
                {

                    system("cls");
                    adminList[k].showCustomer();
                    break;
                }
                case 23:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].editCustomer();
                    Sleep(2000);
                    system("cls");
                    break;
                case 21:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].removeCustomer();
                    Sleep(2000);
                    system("cls");
                    break;
                case 32:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].addMovie();
                    Sleep(2000);
                    system("cls");
                    break;
                case 33:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].editMovie();
                    Sleep(2000);
                    system("cls");
                    break;
                case 31:
                    system("cls");
                    menuAdmin_default(adminList[k]);
                    adminList[k].removeMovie();
                    Sleep(2000);
                    system("cls");
                    break;

                case 34:
                {
                    system("cls");
                    bool running = true;
                    while (running)
                    {
                        menuAdmin_default(adminList[k]);
                        adminList[k].showMovie(movieList34, 1);
                        gotoXY(40, 40);
                        cout << "Choose to see detail..";
                        cin >> _choice34;
                        switch (_choice34)
                        {
                        case 1:
                            system("cls");
                            header_admin(adminList[k].getFullName());
                            movieList34[0].showDetailMovie();
                            movieList34[1].showCurrentMovie();
                            _getch();
                            system("cls");

                            break;
                        case 2:
                            system("cls");
                            header_admin(adminList[k].getFullName());
                            movieList34[1].showDetailMovie();
                            movieList34[2].showCurrentMovie();
                            _getch();
                            system("cls");
                            break;
                        case 3:
                            system("cls");
                            header_admin(adminList[k].getFullName());
                            movieList34[2].showDetailMovie();
                            movieList34[3].showCurrentMovie();
                            _getch();
                            system("cls");
                            break;
                        case 4:
                            system("cls");
                            header_admin(adminList[k].getFullName());
                            movieList34[3].showDetailMovie();
                            movieList34[4].showCurrentMovie();
                            _getch();
                            system("cls");
                            break;
                        case 5:
                            system("cls");
                            header_admin(adminList[k].getFullName());
                            movieList34[4].showDetailMovie();
                            movieList34[0].showCurrentMovie();
                            _getch();
                            system("cls");
                            break;
                        default:
                            running = false;
                            break;
                        }
                    }
                    system("cls");
                    break;
                }
                case 35:
                    system("cls");
                    // menuAdmin_default(adminList[k]);
                    adminList[k].showMovie(movieList34, 0);
                    gotoXY(40, 40);

                    break;
                case 36:
                    system("cls");
                    header_admin(adminList[k].getFullName());
                    adminList[k].searchMovie();
                    gotoXY(12, 40);
                    cout << "Press Enter to continue...";
                    _getch();
                    system("cls");
                    break;
                case 0:
                    running = false;
                    loggedIn = false;
                    break;
                }
            }
            // running = true;
        }
    }
    else if (log == 2)
    {
        loggedIn = true;
        system("cls");
        bool running = true;
        while (loggedIn)
        {
            menuLogin(staffList[k].getFullName(), "Log out");
            while (running)
            {
                // menuStaff();
                int choice;
                gotoXY(5, 40);
                cout << "Please enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    system("cls");

                    int choice;
                    // menuAdmin_f();
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        staffList[k].addMovie();
                        break;
                    case 2:
                        system("cls");
                        staffList[k].editMovie();
                        break;
                    case 3:
                        system("cls");
                        staffList[k].removeMovie();
                        break;
                    case 4:
                        system("cls");
                        // movie.show();
                        break;
                    case 5:
                        system("cls");
                        staffList[k].searchMovie();
                        break;
                    case 6:
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                    }
                    break;
                }

                case 2:
                {
                    system("cls");
                    int choice;

                    cout << "Please enter your choice: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        staffList[k].addCustomer();
                        break;
                    case 2:
                        system("cls");
                        staffList[k].showCustomer();
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;

                    case 3:
                        system("cls");
                        staffList[k].editCustomer();
                        break;
                    case 4:
                        system("cls");
                        staffList[k].removeCustomer();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                    }
                    break;
                }
                case 3:
                {
                    running = false;
                    loggedIn = false;
                    main();
                    break;
                }
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
            }
        }
    }
    else if (log == 3)
    {
        loggedIn = true;
        system("cls");
        bool running = true;
        while (loggedIn)
        {
            menuLogin(customerList[k].getFullName(), "Log out");
            while (running)
            {
                // menuStaff();
                int choice;
                gotoXY(5, 40);
                cout << "Please enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 3:
                {
                    system("cls");
                    customerList[k].showMovie(movieList34,0);
                    break;
                }
                }
            }
        }
    }
    else if (log == 4)
    {
        main();
    }
    else
    {
        booking.sellTicket(shows, screens, movieList34);
    }
    return 0;
}
