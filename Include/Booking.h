#pragma once
#include "Show.h"
#include "Customer.h"
#include "Seat.h"
#include "Payment.h"
#include "Combo.h"


#ifndef BOOKING_H
#define BOOKING_H
enum BookingStatus{
    bookingSeat,
    bookingProduct,
    paymentTime,
    done
};
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
    Payment* payment;
    DoubleLinkedList<Combo> combos;
    //Coupon* appliedCoupon;
    BookingStatus status;
    public:
    Booking();
    Booking(string bookingNumber, int numberOfSeats, string bookingTime, Customer* customer, Show* show, DoubleLinkedList<ShowSeat> seats, double totalPrice,BookingStatus status, Payment* payment);
    //getter
    Payment* getPayment();
    string getBookingNumber();
    int getNumberOfSeats();
    string getBookingTime();
    Customer* getCustomer();
    Show* getShow();
    DoubleLinkedList<ShowSeat>& getSeats();
    double getTotalPrice();
    //setter
    void setBookingNumber(string bookingNumber);
    void setNumberOfSeats(int numberOfSeats);
    void setBookingTime(string bookingTime);
    void setCustomer(Customer* customer);
    void setShow(Show* show);
    void setSeats(DoubleLinkedList<ShowSeat> seats);
    void setTotalPrice(double totalPrice);
    void setBookingStatus(BookingStatus status);
    void setPayment(Payment* payment);
    //method
    void loadBookingFromFile(DoubleLinkedList<Booking> &bookings);
    void displayBooking();
    void displayAllBooking(DoubleLinkedList<Booking> &bookings);
    void sellTicket(DoubleLinkedList<Show> &shows,DoubleLinkedList<Screen> &screens,DoubleLinkedList<Movie> &movies);
    void getRandomBookingNumber();
    DoubleLinkedList<Combo>& getCombos();
}; 

#endif