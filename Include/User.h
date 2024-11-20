#include "Movie.h"
#include "../Template/DoubleLinkedList.h"
#include <iostream>
#include <ctime>
using namespace std;
#ifndef USER_H
#define USER_H

class User
{
protected:
    int ID;
    string fullName;
    string dateOfBirth;
    string email;
    string phoneNumber;
    string gender;
    string username;
    string password;

public:
    User();
    User(string &, string &, string &, string &, string &, string &);
    void setFullName(string &);
    int &getAge() const;
    void setDOB(string &);
    void setID(int id)
    {
        this->ID = id;
    }
    void setGender(string &);
    void setPassword(string &);
    void setPhoneNumber(string &);
    void setUserName(string &);
    void resetPassword(string &);
    string &getID();
    int returnID();
    string &getDOB();
    string &getFullName();
    string &getGender();
    string &getEmail();
    string &getPhoneNumber();
    string &getUserName();
    string &getPassword();
    virtual void savetoFile();
    virtual void readfromFile();
    virtual void saveAgainFile();
     void addMovie()
    {
        Movie movie;
        movie.addMovie();
    }
    void editMovie()
    {
        Movie movie;
        movie.editMovie();
    }
    void removeMovie()
    {
        Movie movie;
        movie.removeMovie();
    }
    void showMovie(DoubleLinkedList<Movie> &movieList,int k)
    {
        Movie movie;
        movie.show(movieList,k);
    }
    void searchMovie()
    {
        Movie movie;
        movie.searchMovie();
    }
    void sort_rating(DoubleLinkedList<Movie> &movieList)
    {
        Movie movie;
        movie.sort_rating(movieList);
    }   
};

// class Management
// {
// public:
//     void addMovie(DoubleLinkedList<Movie> &);
//     void editMovie(DoubleLinkedList<Movie> &);
//     void removeMovie(Movie);
//     void showMovie(DoubleLinkedList<Movie> &);
//     void showCustomer(Customer);
//     void bookTicket();
//     void cancelBooking();
//     void makePayment();
//     void handlePayment();
// };

// class Staff : public Person, public Management
// {
// protected:
//     int IDStaff;
// };
// class Admin : public Person, public Management
// {
// private:
//     int IDAdmin;

// public:
//     void addStaff();
//     void removeStaff();
//     void editStaff();
//     void getRevenueReport();
// };
#endif