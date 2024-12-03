#pragma once
#include "../Include/Coupon.h"
#include "layout-select-seat.cpp"
// #include "Booking.cpp"
Coupon::Coupon()
{
    this->couponCode = "";
    this->discount = 0;
}
Coupon::Coupon(string couponCode, double discount)
    : couponCode(couponCode), discount(discount)
{
}
string Coupon::getCouponCode()
{
    return this->couponCode;
}
double Coupon::getDiscount()
{
    return this->discount;
}
void Coupon::setCouponCode(string couponCode)
{
    this->couponCode = couponCode;
}
void Coupon::setDiscount(double discount)
{
    this->discount = discount;
}
void Coupon::loadCouponFromFile(DoubleLinkedList<Coupon> &coupons)
{
    ifstream file("../Databases/Coupon.txt");
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    string line, key;
    Coupon *currentCoupon = nullptr;
    while (getline(file, line))
    {
        if (line.empty())
            continue;
        istringstream ss(line);
        if (line.rfind("CouponCode:", 0) == 0)
        {
            if (currentCoupon != nullptr)
            {
                coupons.push_back(*currentCoupon);
            }
            currentCoupon = new Coupon();
            ss >> key >> currentCoupon->couponCode;
        }
        else if (line.rfind("Discount:", 0) == 0)
        {
            ss >> key >> currentCoupon->discount;
        }
    }
    if (currentCoupon != nullptr)
    {
        coupons.push_back(*currentCoupon);
    }
    file.close();
}
void Coupon::displayCoupon()
{
    cout << "Coupon code: " << this->couponCode << endl;
    cout << "Discount: " << this->discount << endl;
}
void Coupon::displayAllCoupon(DoubleLinkedList<Coupon> &coupons)
{
    for (Node<Coupon> *node = coupons.begin(); node != nullptr; node = node->next)
    {
        node->data.displayCoupon();
    }
}
void layoutCoupon(Booking *booking)
{
    int x = 10;
    int y = 10;
    gotoXY(x,y);
    cout<<"Nhập mã khuyến mãi: ";
    string couponCode;
    gotoXY(x,y+2);
    lineWidth(20,true,true);
    lineHeight(1,x,y+3);
    lineHeight(1,x+21,y+3);
    gotoXY(x,y+4);
    lineWidth(20,true,false);
    gotoXY(x+30,y+2);
    lineWidth(15,true,true);
    lineHeight(1,x+30,y+3);
    lineHeight(1,x+46,y+3);
    gotoXY(x+30,y+4);
    lineWidth(15,true,false);
    gotoXY(x+32,y+3);
    cout<<"Áp dụng";

    gotoXY(x+3,y+3);
    // cin>>couponCode;
    // for(Node<Coupon>* node = booking->getCoupons().begin(); node != nullptr; node = node->next){
    //     if(node->data.getCouponCode() == couponCode){
    //         booking->setTotalPrice(booking->getTotalPrice()*(1-node->data.getDiscount()));
    //         cout<<"Giảm giá: "<<node->data.getDiscount()*100<<"%"<<endl;
    //         cout<<"Tổng giá sau khi giảm: "<<booking->getTotalPrice()<<endl;
    //         break;
    //     }
    // }
}

void layoutBillTempCoupon(Booking *booking){
    int x=115;
    int y=5;
    gotoXY(110,3);
    lineWidth(42,true,true);
    lineHeight(35,110,4);
    lineHeight(35,153,4);
    gotoXY(110,23);
    lineWidth(42,true,false);
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
    cout<<"GHẾ:";
    gotoXY(x-1,y+14);
    int countVIP=0;
    int countNormal=0;
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
        if(node->data.convertSeatTypeToSimpleString()=="V"){
            countVIP++;
        }
        else{
            countNormal++;
        }
    }
    cout<<"x "<<countVIP<<" VIP: ";
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){\
        
        if(node->data.convertSeatTypeToSimpleString()=="V"){
            gotoXY(x-1+6+countVIP*4,y+14);
            countVIP--;
            cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
        }
    }
    gotoXY(x-1,y+16);
    cout<<"x "<<countNormal<<" THƯỜNG: ";
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
        
        if(node->data.convertSeatTypeToSimpleString()=="R"){
            gotoXY(x-1+9+countNormal*4,y+16);
        countNormal--;
            cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
        }
    }
    int idxCombo=0;
    for(Node<Combo>* node = booking->getCombos().begin(); node != nullptr; node = node->next){
        node->data.displaySimpleCombo(114,25+idxCombo*2);
        idxCombo++;
    }
    gotoXY(110,y+26);
    lineWidth(42,false,true);
    gotoXY(x,y+28);
    cout<<"Tạm tính:           ";
    gotoXY(114+30,y+28);
    cout<<BG_GREEN<<booking->getTotalPrice()<<RESET;
    gotoXY(x+16,y+16);
}
void Coupon::processCoupon(Booking *booking)
{
    DoubleLinkedList<Coupon> coupons;
    Coupon coupon;
    coupon.loadCouponFromFile(coupons);
    // coupon.displayAllCoupon(coupons);
    string couponCode;
    // cout << "Enter coupon code: ";
    layoutCoupon(booking);
    layoutBillTempCoupon(booking);
    click=processInputEvents();
    int x_click = click.X;
    int y_click = click.Y;
    if(isClickInRange(x_click,y_click,10,12,20,2)){
        getString(couponCode,12,13);
    }
    
    // cin >> couponCode;
    double tienduocgiam=0;
    for (Node<Coupon> *node = coupons.begin(); node != nullptr; node = node->next)
    {
        if (node->data.getCouponCode() == couponCode)
        {   
            tienduocgiam=booking->getTotalPrice()*node->data.getDiscount();
            gotoXY(10, 17);
            cout<< "Nhập mã khuyến mãi: "<<couponCode<<" thành công.";
            gotoXY(10, 18);
            cout<<"Giảm giá: " << node->data.getDiscount() * 100 << "%" << endl;
            booking->setTotalPrice(booking->getTotalPrice() * (1 - node->data.getDiscount()));
            // cout << "Discount: " << node->data.getDiscount() * 100 << "%" << endl;
            // cout << "Total price after discount: " << booking->getTotalPrice() << endl;
            gotoXY(115, 33 +2);
            cout<<"Giảm giá: ";
            gotoXY(126, 33 +2);
            cout<<node->data.getDiscount()*100<<"%";
            gotoXY(142, 33 +2 );
            cout<<"- "<<tienduocgiam;
            break;
        }
    }
    // booking->setNumberOfSeats(tienduocgiam);
    this->discount=tienduocgiam;
    gotoXY(110, 33 +4);
    lineWidth(42, false, true);
    gotoXY(110, 33 +6);
    cout<<"Tổng cộng: ";
    gotoXY(144, 33 +6);
    cout<<BG_GREEN<<booking->getTotalPrice()<<RESET;
    gotoXY(110, 33 +8);
    lineWidth(42, true, false);
}