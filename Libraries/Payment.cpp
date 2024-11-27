#pragma once
#include "../Include/Payment.h"
#include "layout-select-seat.cpp"
// #include "../Include/Booking.h"
using namespace std;
#define byte windows_byte
#include <windows.h>
#undef byte
Payment::Payment()
{
    this->paymentMethod = "";
    this->finalPrice = 0.1;
    this->paymentTime = "";
    this->paymentNumber = "";
    // this->status = Pending;
}
Payment::Payment(string paymentMethod, double finalPrice, string paymentTime, string paymentNumber, PaymentStatus status)
    : paymentMethod(paymentMethod), finalPrice(finalPrice), paymentTime(paymentTime), paymentNumber(paymentNumber), status(status)
{
}
string Payment::getPaymentMethod()
{
    return this->paymentMethod;
}
double Payment::getFinalPrice()
{
    return this->finalPrice;
}
string Payment::getPaymentTime()
{
    return this->paymentTime;
}
string Payment::getPaymentNumber()
{
    return this->paymentNumber;
}
PaymentStatus Payment::getStatus()
{
    return this->status;
}
void Payment::setPaymentMethod(string paymentMethod)
{
    this->paymentMethod = paymentMethod;
}
void Payment::setFinalPrice(double finalPrice)
{
    this->finalPrice = finalPrice;
}
void Payment::setPaymentTime(string paymentTime)
{
    this->paymentTime = paymentTime;
}
void Payment::setPaymentNumber(string paymentNumber)
{
    this->paymentNumber = paymentNumber;
}
void Payment::setStatus(PaymentStatus status)
{
    this->status = status;
}
void Payment::displayPayment()
{
    cout << "Payment Method: " << this->paymentMethod << endl;
    cout << "Final Price: " << this->finalPrice << endl;
    cout << "Payment Time: " << this->paymentTime << endl;
    cout << "Payment Number: " << this->paymentNumber << endl;
    cout << "Status: " << this->status << endl;
}
CreditCardPayment::CreditCardPayment() : Payment()
{
}
void printQRCode(int x,int y){
    ifstream file("../Databases/testQRCode.txt");
    string line;
    while (std::getline(file, line)) {
        gotoXY(x,y);
        cout<<line<<endl;
        y++;
    }
}
void CreditCardPayment::processPayment(Booking* booking)
{       
    DoubleLinkedList<Combo> combos;
    combos=booking->getCombos();
    for(Node<Combo>* node = combos.begin(); node != nullptr; node = node->next){
        this->finalPrice+=node->data.getComboPrice();
    }
    
    gotoXY(5,5);
    printQRCode(5,4);
    int x=115;
    int y=5;
    gotoXY(110,3);
    lineWidth(40,true,true);
    lineHeight(22,110,3);
    lineHeight(22,151,3);
    gotoXY(110,23);
    lineWidth(40,true,false);
    gotoXY(x,y);
    cout<<"THÔNG TIN ĐẶT VÉ";
    gotoXY(x,y+2);
    cout<<"Mã vé: "<<booking->getBookingNumber();
    gotoXY(x,y+4);
    cout<<"Tên phim: "<<booking->getShow()->getMovie()->getTitle();
    gotoXY(x,y+6);
    cout<<"THỜI GIAN               NGÀY CHIẾU";
    gotoXY(x-2,y+8);
    cout<<booking->getShow()->getStartTime()<<" ~ "<<booking->getShow()->getEndTime()<<"            ";
    cout<<booking->getShow()->getDate();
    gotoXY(x,y+10);
    cout<<"PHÒNG CHIẾU: "<<booking->getShow()->getScreen()->getID_screen();
    gotoXY(x,y+12);
    cout<<"GHẾ:"<<"A1, B2";
    gotoXY(x+16,y+12);
    cout<<booking->getTotalPrice();
    // for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
    //     gotoXY(x,y);
    //     cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
    //     y++;
    // }
    // gotoXY(x,y+18);
    // cout<<"Tổng tiền: "<<booking->getTotalPrice();
    int xPayment=115;
    int yPayment=10;
    // gotoXY(xPayment,yPayment);
    // lineWidth(20,true,true);
    // gotoXY(xPayment,yPayment+2);
    // cout<<"THÔNG TIN THANH TOÁN";
    // gotoXY(xPayment,yPayment+4);
    // cout<<"Phương thức thanh toán: Chuyển khoản";
    // gotoXY(xPayment,yPayment+6);
    // cout<<"Thông tin STK: 1041534471";
    // gotoXY(xPayment,yPayment+8);
    // cout<<"Ngân hàng: Vietcombank";
    // gotoXY(xPayment,yPayment+10);
    // cout<<"Chủ tài khoản: DOAN HOANG THIEN PHU";
    // gotoXY(xPayment,yPayment+12);
    // cout<<"Nội dung chuyển khoản: "<<booking->getBookingNumber();
    // gotoXY(xPayment,yPayment+14);
    // cout<<"Tổng tiền: "<<booking->getTotalPrice();
    // gotoXY(xPayment,yPayment+16);
    // cout<<"Thời gian thanh toán: "<<booking->getBookingTime();
    // gotoXY(xPayment,yPayment+18);
    // cout<<"Trạng thái: Đang chờ xử lý";
    // gotoXY(xPayment,yPayment+20);
    // cout<<"Mã giao dịch: "<<booking->getBookingNumber();
    // gotoXY(xPayment,yPayment+22);
    // cout<<"QR Code: ở phía bên trái";
    lineHeight(10,xPayment,yPayment);
    lineHeight(10,xPayment+15,yPayment);
    gotoXY(x,yPayment+10);
    lineWidth(20,true,false);

    gotoXY(0,0);
}

CashPayment::CashPayment()
{
}
void CashPayment::processPayment(Booking* booking){

}
