#pragma once
#include "Show.h"
#include "Customer.h"
#include "Seat.h"



#ifndef BOOKING_H
#define BOOKING_H

class Seat;
class Show;
class Customer;
class Movie;
class ShowSeat;
class Booking{
    private:
    string bookingNumber;
    int numberOfSeats;
    string bookingTime;
    Customer* customer;
    Show* show;
    DoubleLinkedList<ShowSeat> seats;
    double totalPrice;
    //Payment* payment;
    //Coupon* appliedCoupon;
    //BookingStatus status;
    public:
    Booking();
    Booking(string bookingNumber, int numberOfSeats, string bookingTime, Customer* customer, Show* show, DoubleLinkedList<ShowSeat> seats, double totalPrice);
    //getter
    string getBookingNumber();
    int getNumberOfSeats();
    string getBookingTime();
    Customer* getCustomer();
    Show* getShow();
    DoubleLinkedList<ShowSeat> getSeats();
    double getTotalPrice();
    //setter
    void setBookingNumber(string bookingNumber);
    void setNumberOfSeats(int numberOfSeats);
    void setBookingTime(string bookingTime);
    void setCustomer(Customer* customer);
    void setShow(Show* show);
    void setSeats(DoubleLinkedList<ShowSeat> seats);
    void setTotalPrice(double totalPrice);
    //method
    void loadBookingFromFile(DoubleLinkedList<Booking> &bookings);
    void displayBooking();
    void displayAllBooking(DoubleLinkedList<Booking> &bookings);
    void sellTicket(DoubleLinkedList<Show> &shows,DoubleLinkedList<Screen> &screens,DoubleLinkedList<Movie> &movies);

};

#endif