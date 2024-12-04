#pragma once
#include "Show.h"
#include "Customer.h"
#include "Seat.h"
#include "Payment.h"
#include "Combo.h"
#include "Coupon.h"
#include "User.h"
#include "Staff.h"
#include "Admin.h"
#ifndef BOOKING_H
#define BOOKING_H
enum BookingStatus{
    bookingSeat,
    bookingProduct,
    paymentTime,
    done
};
class Combo;
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
    Staff* staff;
    Admin* admin;
    Show* show;
    DoubleLinkedList<ShowSeat> seats;
    double totalPrice;
    Payment* payment;
    Coupon* appliedCoupon;
    DoubleLinkedList<Combo> combos;
    //Coupon* appliedCoupon;
    BookingStatus status;
    public:
    Booking();
    Booking(string bookingNumber, int numberOfSeats, string bookingTime, Customer* customer, Show* show, DoubleLinkedList<ShowSeat> seats, double totalPrice,BookingStatus status, Payment* payment);
    //getter
    Customer* getCustomer();
    Staff* getStaff();
    Admin* getAdmin();

    Payment* getPayment();
    string getBookingNumber();
    int getNumberOfSeats();
    string getBookingTime();
    Show* getShow();
    DoubleLinkedList<ShowSeat>& getSeats();
    double getTotalPrice();
    
    Coupon* getAppliedCoupon();
    //setter
    void setCustomer(Customer* customer);
    void setStaff(Staff* staff);
    void setAdmin(Admin* admin);
    void setAppliedCoupon(Coupon* coupon);
    void setBookingNumber(string bookingNumber);
    void setNumberOfSeats(int numberOfSeats);
    void setBookingTime(string bookingTime);
    void setShow(Show* show);
    void setSeats(DoubleLinkedList<ShowSeat> seats);
    void setTotalPrice(double totalPrice);
    void setBookingStatus(BookingStatus status);
    void setPayment(Payment* payment);
    //method
    void displayBooking();
    void displayAllBooking(DoubleLinkedList<Booking> &bookings);
    void sellTicket(DoubleLinkedList<Show> &shows,DoubleLinkedList<Screen> &screens,DoubleLinkedList<Movie> &movies);
    void getRandomBookingNumber();
    DoubleLinkedList<Combo>& getCombos();
    void saveBookingToFile();
    void loadBookingFromFile(DoubleLinkedList<Booking> &bookings,DoubleLinkedList<Customer> &customers);
    void setCombos(DoubleLinkedList<Combo> &combos);
    
}; 

#endif