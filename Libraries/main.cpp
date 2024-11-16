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

void menuAdmin()
{
    cout << "+==========================================+" << endl;
    cout << "|              SYSTEM MANAGEMENT            |" << endl;
    cout << "+==========================================+" << endl;
    cout << "|  1. Manage EMPLOYEES                    |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  2. Manage CUSTOMERS                    |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  3. Manage MOVIES                       |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  4. LOG OUT                             |" << endl;
    cout << "+==========================================+" << endl;
}

void menuAdmin_s()
{
    cout << "+==========================================+" << endl;
    cout << "|  1. Add Staff                            |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  2. View Staff List                      |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  3. Edit Staff                           |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  4. Delete Staff                         |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  5. Exit                                |" << endl;
    cout << "+==========================================+" << endl;
}

void menuAdmin_c()
{
    cout << "+==========================================+" << endl;
    cout << "|  1. Add Customer                         |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  2. View Customer List                   |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  3. Edit Customer                        |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  4. Delete Customer                      |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  5. Exit                                |" << endl;
    cout << "+==========================================+" << endl;
}

void menuAdmin_f()
{
    cout << "+==========================================+" << endl;
    cout << "|  1. Add Movie                           |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  2. Edit Movie                          |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  3. Delete Movie                        |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  4. View Movie List                     |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  5. Search Movie                        |" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "|  6. Exit                                |" << endl;
    cout << "+==========================================+" << endl;
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
        bool running = true;
        while (loggedIn)
        {
            // bool running = true;
            while (running)
            {
                menuAdmin();
                int choice;
                cout << "Please enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    system("cls");
                    menuAdmin_s();
                    int choice;
                    cout << "Please enter your choice: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        admin.addStaff();
                        break;
                    case 2:
                        system("cls");
                        admin.showStaff();
                        break;
                    case 3:
                        system("cls");
                        admin.editStaff();
                        break;
                    case 4:
                        system("cls");
                        admin.removeStaff();
                        break;
                    case 5:
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
                    menuAdmin_c();
                    cout << "Please enter your choice: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        admin.addCustomer();
                        break;
                    case 2:
                        system("cls");
                        admin.showCustomer();
                        break;
                    case 3:
                        system("cls");
                        admin.editCustomer();
                        break;
                    case 4:
                        system("cls");
                        admin.removeCustomer();
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
                    system("cls");
                    Movie movie;
                    int choice;
                    menuAdmin_f();
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
                case 4:
                {
                    running = false;
                    loggedIn = false;
                    main();
                    break;
                }

                break;
                }
            }
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
                    menuAdmin_f();
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
                    menuAdmin_c();
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
