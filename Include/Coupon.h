#pragma once
#include "Booking.h"

class Coupon{
    protected:
    string couponCode;
    double discount;
    public:
    Coupon();
    Coupon(string couponCode, double discount);
    string getCouponCode();
    double getDiscount();
    void setCouponCode(string couponCode);
    void setDiscount(double discount);
    void loadCouponFromFile(DoubleLinkedList<Coupon> &coupons);
    void displayCoupon();
    void displayAllCoupon(DoubleLinkedList<Coupon> &coupons);
    void processCoupon(Booking* booking);
};