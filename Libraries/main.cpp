#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <windows.h>
#include "Movie.cpp"
#include "staff.cpp"
#include "admin.cpp"
#include "login.cpp"
#include "User.cpp"
using namespace std;

void menuStaff()
{
    cout << "+==========================================+" << endl;
    cout << "|            SYSTEM MANAGEMENT             |" << endl;
    cout << "+==========================================+" << endl;
    cout << "|  1. Manage MOVIES                       |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  2. Manage CUSTOMERS                    |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  3. LOG OUT                             |" << endl;
    cout << "+==========================================+" << endl;
}

void menuAdmin_default()
{
    int y = 3;
    int x = 0;
    for (int i = 0; i < 38; i++)
    {
        gotoXY(28, y);
        cout << "|";
        y++;
    }
    for (int i = 0; i < 155; i++)
    {
        gotoXY(x, 2);
        cout << "_";
        x++;
    }
    gotoXY(130, 1);
    cout << "(*_*)" << " Admin" << endl;
    gotoXY(0, 0);
    cout << "+-----------+" << endl;
    gotoXY(0, 1);
    cout << "| 0.BACK    |" << endl;
    gotoXY(0, 2);
    cout << "+-----------+" << endl;
    gotoXY(30, 1);
    cout << "VIEW BENEFITS <>" << endl;
    gotoXY(50, 1);
    cout << "VOUCHER <>" << endl;
    gotoXY(70, 1);
    cout << "CINEMA <>" << endl;
    gotoXY(90, 1);
    cout << "ROOM <>" << endl;
    gotoXY(110, 1);
    cout << "BOOKING <>" << endl;
    gotoXY(5, 5);
    cout << "I.STAFF MANAGEMENT" << endl;
    gotoXY(5, 7);
    cout << "1.1 Remove staff" << endl;
    gotoXY(5, 8);
    cout << "1.2 Add staff" << endl;
    gotoXY(5, 9);
    cout << "1.3 Edit staff" << endl;
    gotoXY(5, 10);
    cout << "1.4 View staff list" << endl;
    gotoXY(5, 12);
    cout << "II.CUSTOMER MANAGEMENT" << endl;
    gotoXY(5, 14);
    cout << "2.1 Remove customer" << endl;
    gotoXY(5, 15);
    cout << "2.2 Add customer" << endl;
    gotoXY(5, 16);
    cout << "2.3 Edit customer" << endl;
    gotoXY(5, 17);
    cout << "2.4 View customer list" << endl;
    gotoXY(5, 19);
    cout << "III.MOVIE MANAGEMENT" << endl;
    gotoXY(5, 21);
    cout << "3.1 Remove movie" << endl;
    gotoXY(5, 22);
    cout << "3.2 Add movie" << endl;
    gotoXY(5, 23);
    cout << "3.3 Edit movie" << endl;
    gotoXY(5, 24);
    cout << "3.4 View movie list" << endl;
    gotoXY(5, 25);
    cout << "3.5 Search movie" << endl;
    gotoXY(5, 26);
}

int main()
{

    bool loggedIn = false;
    int log = logIn();
    // int log =1;
    if (log == 1)
    {
        loggedIn = true;
        Admin admin;
        Movie movie;
        Staff staff;
        bool running = true;
        while (loggedIn)
        {
            bool running = true;
            while (running)
            {
                menuAdmin_default();
                int choice;
                // cout << "Please enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 12:
                    system("cls");
                    menuAdmin_default();
                    admin.addStaff();
                    gotoXY(130, 4);
                    cout << "DONE";
                    Sleep(2000);
                    system("cls");
                    break;
                case 14:
                    system("cls");
                    // menuAdmin_default();
                    admin.showStaff();
                    // gotoXY(130, 4);
                    // cout << "DONE";
                    // Sleep(2000);
                    // system("cls");
                    break;
                case 13:
                    system("cls");
                    menuAdmin_default();
                    admin.editStaff();
                    Sleep(2000);
                    system("cls");
                    break;
                case 11:
                    system("cls");
                    menuAdmin_default();
                    admin.removeStaff();
                    Sleep(2000);
                    system("cls");
                    break;
                case 22:
                    system("cls");
                    menuAdmin_default();
                    admin.addCustomer();
                    gotoXY(130, 4);
                    cout << "DONE";
                    Sleep(2000);
                    system("cls");
                    break;
                case 24:
                    system("cls");
                    admin.showCustomer();
                    break;
                case 23:
                    system("cls");
                    menuAdmin_default();
                    admin.editCustomer();
                    Sleep(2000);
                    system("cls");
                    break;
                case 21:
                    system("cls");
                    menuAdmin_default();
                    admin.removeCustomer();
                    Sleep(2000);
                    system("cls");
                    break;
                case 32:
                    system("cls");
                    menuAdmin_default();
                    movie.addMovie();
                    Sleep(2000);
                    system("cls");
                    break;
                case 33:
                    system("cls");
                    menuAdmin_default();
                    movie.editMovie();
                    Sleep(2000);
                    system("cls");
                    break;
                case 31:
                    system("cls");
                    menuAdmin_default();
                    movie.removeMovie();
                    Sleep(2000);
                    system("cls");
                    break;

                case 34:
                    system("cls");
                    movie.show();
                    break;
                case 35:
                    system("cls");
                    movie.searchMovie();
                    break;
                default:
                    running = false;
                    break;
                }
            }
            running = true;
        }
    }
    else if (log == 2)
    {
        loggedIn = true;
        Staff staff;
        bool running = true;
        while (loggedIn)
        {
            // bool running = true;
            while (running)
            {
                menuStaff();
                int choice;
                cout << "Please enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    system("cls");
                    Movie movie;
                    int choice;
                    // menuAdmin_f();
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        movie.addMovie();
                        break;
                    case 2:
                        system("cls");
                        movie.editMovie();
                        break;
                    case 3:
                        system("cls");
                        movie.removeMovie();
                        break;
                    case 4:
                        system("cls");
                        movie.show();
                        break;
                    case 5:
                        system("cls");
                        movie.searchMovie();
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
                        staff.addCustomer();
                        break;
                    case 2:
                        system("cls");
                        staff.showCustomer();
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;

                    case 3:
                        system("cls");
                        staff.editCustomer();
                        break;
                    case 4:
                        system("cls");
                        staff.removeCustomer();
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
        main();
    }
    else if (log == 4)
    {
        cout << "WELCOME TO OUR PROGRAM" << endl;
        main();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
    return 0;
}
