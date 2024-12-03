#pragma once
#include "Booking.h"
#include <iostream>
// #include "Coupon.cpp"
enum PaymentStatus {
    Pending,
    Paid,
    Cancelled,
    Refunded
};
class Booking;
class Payment {
protected:
    string paymentMethod;
    double finalPrice;
    string paymentTime;
    string paymentNumber;
    PaymentStatus status;
public:
    Payment();
    Payment(string paymentMethod, double finalPrice, string paymentTime, string paymentNumber, PaymentStatus status);
    string getPaymentMethod();
    double getFinalPrice();
    string getPaymentTime();
    string getPaymentNumber();
    PaymentStatus getStatus();
    void setPaymentMethod(string paymentMethod);
    void setFinalPrice(double finalPrice);
    void setPaymentTime(string paymentTime);
    void setPaymentNumber(string paymentNumber);
    void setStatus(PaymentStatus status);
    void displayPayment();
    virtual void processPayment(Booking* booking) = 0;
};
class CreditCardPayment : public Payment {
    public:
    CreditCardPayment();
    void processPayment(Booking* booking) override; 
};
class CashPayment : public Payment {
    public:
    CashPayment();
    void processPayment(Booking* booking) override; 
};