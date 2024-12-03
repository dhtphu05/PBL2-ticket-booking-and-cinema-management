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
void layoutChooseMethod(){
    int x=10;
    int y=17;
    gotoXY(x,y+5);
    cout<<"Chọn phương thức thanh toán";
    gotoXY(x,y+7);
    lineWidth(20,true,true);
    gotoXY(x,y+8);
    lineHeight(1,x,y+8);
    lineHeight(1,x+21,y+8);
    gotoXY(x,y+9);
    lineWidth(20,true,false);
    gotoXY(x+3,y+8);
    cout<<"1. Chuyển khoản";
    gotoXY(x+3,y+10);
    lineWidth(20,true,true);
    gotoXY(x,y+11);
    lineHeight(1,x,y+11);
    lineHeight(1,x+21,y+11);
    gotoXY(x,y+12);
    lineWidth(20,true,false);
    gotoXY(x+3,y+11);
    cout<<"2. Tiền mặt";
    gotoXY(x,y+13);


}
void layoutFinal(Booking *booking, Coupon* coupon){
    int x=115;
    int y=5;
    gotoXY(110,3);
    lineWidth(42,true,true);
    lineHeight(35,110,4);
    lineHeight(35,153,4);
    gotoXY(110,23);
    lineWidth(42,true,false);
    gotoXY(110,23);
    cout<<"├";
    gotoXY(153,23);
    cout<<"┤";
    gotoXY(x,y);
    cout<<"THÔNG TIN ĐẶT VÉ";
    gotoXY(x,y+2);
    cout<<"Mã vé: "<<BG_YELLOW<<booking->getBookingNumber()<<RESET;
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
    cout<<"GHẾ:";
    int countVIP=0;
    int countNormal=0;
    int countVIP_temp=0;
    int countNormal_temp=0;
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
        if(node->data.convertSeatTypeToSimpleString()=="V"){
            countVIP++;
        }
        else{
            countNormal++;
        }
    }
    countVIP_temp=countVIP;
    countNormal_temp=countNormal;
    double totalVIP=0;
    
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){\
        
        if(node->data.convertSeatTypeToSimpleString()=="V"){
            gotoXY(x-1+6+countVIP*4,y+14);
            totalVIP+=node->data.getPrice();
            countVIP--;
            cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
        }
    }

    gotoXY(x-1,y+14);
    if(totalVIP!=0){
    cout<<"x "<<countVIP_temp<<" VIP: ";
    gotoXY(144,y+14);
    cout<<totalVIP;
    }
    double totalNormal=0;
    
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
        
        if(node->data.convertSeatTypeToSimpleString()=="R"){
            gotoXY(x-1+9+countNormal*4,y+16);
            totalNormal+=node->data.getPrice();
        countNormal--;
            cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
        }
    }
    if(totalNormal!=0){
        gotoXY(x-1,y+16);
    cout<<"x "<<countNormal_temp<<" THƯỜNG: ";
    gotoXY(144,y+16);
    cout<<totalNormal;
    }
    int idxCombo=0;
    for(Node<Combo>* node = booking->getCombos().begin(); node != nullptr; node = node->next){
        node->data.displaySimpleCombo(114,25+idxCombo*2);
        idxCombo++;
    }
    gotoXY(110,y+26);
    cout<<"├";
    lineWidth(43,false,true);
    gotoXY(110+43,y+26);
    cout<<"┤";
    gotoXY(x,y+28);
    cout<<"Tạm tính:           ";
    gotoXY(114+30,y+28);
    cout<<BG_GREEN<<coupon->getDiscount()<<RESET;
    gotoXY(x+16,y+16);
    gotoXY(115, 33 +2);
    cout<<"Giảm giá: ";
    gotoXY(126, 33 +2);
    cout<<coupon->getCouponCode()<<"%";
    gotoXY(142, 33 +2 );
    cout<<"- "<<coupon->getDiscount()-booking->getTotalPrice();
    gotoXY(110, 33 +4);
    lineWidth(42, false, true);
    gotoXY(110, 33 +6);
    cout<<"Tổng cộng: ";
    gotoXY(144, 33 +6);
    cout<<BG_GREEN<<booking->getTotalPrice()<<RESET;
    gotoXY(110, 33 +8);
    lineWidth(42, true, false);

}
void CreditCardPayment::processPayment(Booking* booking)
{       
    layoutChooseMethod();
    click=processInputEvents();
    int x_click = click.X;
    int y_click = click.Y;
    if(isClickInRange(x_click,y_click,10,23,20,3)){
        this->setPaymentMethod("Chuyển khoản");
        system("cls");
    }
    else if(isClickInRange(x_click,y_click,10,11,20,2)){
        this->setPaymentMethod("Tiền mặt");
    }
    gotoXY(5,5);
    printQRCode(5,4);
    layoutFinal(booking, booking->getAppliedCoupon());
    int xPayment=115;
    int yPayment=10;
    borderLineWithTextAndColor(100, 44, "VUI LÒNG CHUYỂN KHOẢN VỚI DÒNG TIN NHẮN SAU", BG_GREEN);
    borderLineWithTextAndColor(100, 47, booking->getBookingNumber() , BG_GREEN);
    
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
    // lineHeight(10,xPayment,yPayment);
    // lineHeight(10,xPayment+15,yPayment);
    // gotoXY(x,yPayment+10);
    // lineWidth(20,true,false);

    gotoXY(0,0);
}

CashPayment::CashPayment()
{
}
void CashPayment::processPayment(Booking* booking){

}
