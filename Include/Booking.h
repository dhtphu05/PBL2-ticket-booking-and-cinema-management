#include <iostream>
#include <string>
#include <math.h>
#include "../Template/DoubleLinkedList.h"
// #include "User.h"
#include "Ticket.h"
using namespace std;

class Booking{
    int ID_Booking;
    DoubleLinkedList<Ticket> Tickets;
    // DoubleLinkedList<Voucher> Vouchers;
    // DoubleLinkedList<Product> Products;
    //User user;
    int numberofSeats;
    double totalPayment;
    string createdOn;
    public:
    Booking(int ID_Booking, DoubleLinkedList<Ticket> Tickets,   int numberofSeats, double totalPayment, string createdOn) : ID_Booking(ID_Booking), Tickets(Tickets), numberofSeats(numberofSeats), totalPayment(totalPayment), createdOn(createdOn) {}
    ~Booking(){}
    int getID_Booking() const;
    DoubleLinkedList<Ticket> getTickets() const;
    //DoubleLinkedList<Voucher> getVouchers() const;
    //DoubleLinkedList<Product> getProducts() const;
    // User getUser() const;
    int getNumberofSeats() const;
    double getTotalPayment() const;
    string getCreatedOn() const;
    void setID_Booking(int ID_Booking);
    void setTickets(DoubleLinkedList<Ticket> Tickets);
    // void setVouchers(DoubleLinkedList<Voucher> Vouchers);
    // void setProducts(DoubleLinkedList<Product> Products);
    // void setUser(User user);
    void setNumberofSeats(int numberofSeats);
    void setTotalPayment(double totalPayment);
    void setCreatedOn(string createdOn);
    void getShow();
    
};