#pragma once
#include "../Include/Booking.h"
#include "../Include/Movie.h"
#include "../Libraries/Show.cpp"
#include "../Libraries/Customer.cpp"
#include "../Libraries/Screen.cpp"
#include "../Libraries/User.cpp"
#include <time.h>
#include "layout-select-seat.cpp"
#include "Combo.cpp"
#include "Payment.cpp"
#include "Coupon.cpp"
class Show;
class Screen;
class ShowSeat;
Booking::Booking()
{
    this->bookingNumber = "";
    this->numberOfSeats = 0;
    this->bookingTime = "";
    this->show = nullptr;
    this->totalPrice = 0;
    this->status = bookingSeat;
    this->payment = nullptr;
    this->appliedCoupon = new Coupon();
    this->customer = new Customer("Guest","");
    this->staff = nullptr;
    this->admin = nullptr;
}
Booking::Booking(string bookingNumber, int numberOfSeats, string bookingTime, Customer *customer, Show *show, DoubleLinkedList<ShowSeat> seats, double totalPrice, BookingStatus status, Payment *payment)
    : bookingNumber(bookingNumber), numberOfSeats(numberOfSeats), bookingTime(bookingTime), show(show), seats(seats), totalPrice(totalPrice)
{
    this->status = bookingSeat;
    this->payment = payment;
    this->customer = customer;
    this->staff = nullptr;
    this->admin = nullptr;

}
string Booking::getBookingNumber()
{
    return this->bookingNumber;
}
int Booking::getNumberOfSeats()
{
    return this->numberOfSeats;
}
string Booking::getBookingTime()
{
    return this->bookingTime;
}
// Customer *Booking::getCustomer()
// {
//     return this->customer;
// }
Show *Booking::getShow()
{
    return this->show;
}
Payment *Booking::getPayment()
{
    return this->payment;
}
DoubleLinkedList<ShowSeat>& Booking::getSeats()
{
    return this->seats;
}
double Booking::getTotalPrice()
{
    return this->totalPrice;
}
void Booking::setBookingNumber(string bookingNumber)
{
    this->bookingNumber = bookingNumber;
}
void Booking::setNumberOfSeats(int numberOfSeats)
{
    this->numberOfSeats = numberOfSeats;
}
void Booking::setBookingTime(string bookingTime)
{
    this->bookingTime = bookingTime;
}
// void Booking::setCustomer(Customer *customer)
// {
//     this->customer = customer;
// }
void Booking::setShow(Show *show)
{
    this->show = show;
}
void Booking::setSeats(DoubleLinkedList<ShowSeat> seats)
{
    this->seats = seats;
}
void Booking::setTotalPrice(double totalPrice)
{
    this->totalPrice = totalPrice;
}
void Booking::setBookingStatus(BookingStatus status)
{
    this->status = status;
}
void Booking::setPayment(Payment *payment)
{
    this->payment = payment;
}
Coupon *Booking::getAppliedCoupon()
{
    return this->appliedCoupon;
}
void Booking::setCustomer(Customer *user)
{
    this->customer = user;
}
void Booking::setStaff(Staff *user)
{
    this->staff = user;
}
void Booking::setAdmin(Admin *user)
{
    this->admin = user;
}
Customer *Booking::getCustomer()
{
    return this->customer;
}
Staff *Booking::getStaff()
{
    return this->staff;
}
Admin *Booking::getAdmin()
{
    return this->admin;
}
void Booking::setCombos(DoubleLinkedList<Combo>& combos)
{
    this->combos = combos;
}
void Booking::setAppliedCoupon(Coupon *coupon)
{
    this->appliedCoupon = coupon;
}

//!TODO: 1 hóa đơn là tạo 1 file
void Booking::sellTicket(DoubleLinkedList<Show>& shows,DoubleLinkedList<Screen> &screens,DoubleLinkedList<Movie> &movies)
{   system("cls");
    borderLineWithTextAndColor(120,1,"Khách hàng: "+this->getCustomer()->getFullName(),BG_CYAN);
    Movie movieInstance;
    Movie* movie= &movieInstance;
    movie->selectMovieToBooking(movies);
    
    //cout<<movie->getCountry()<<endl;
    Show showInstance;
    Show* show = new Show;
    show->selectShow(movie, screens);
    system("cls");
    layoutBorderSeat(show);
    this->setShow(show);
    this->setNumberOfSeats(numberOfSeats);
    this->setTotalPrice(totalPrice);
    this->getRandomBookingNumber();
    layoutBooking(this);
    //show->displaySeatStatus();
    bool statusSeatBeforeClick[101];
    for(Node<ShowSeat>* node = show->getSeats().begin(); node != nullptr; node = node->next){
        statusSeatBeforeClick[convertRowandColToInt(node->data.getSeatRow(),node->data.getSeatColumn())]=node->data.getIsBooked();
    }
    string row;
    int column;
    double totalPrice=0;
    // layoutBorderSeat(show);
    // showInstance.displayAllShow(shows);
    bool isEndBookSeat=false;
    bool isFirstClick=false;
    while(isEndBookSeat==false){
        
    // for(int i=0;i<numberOfSeats;i++){
        // displayAllSeatToBook(show);
        gotoXY(122+18, 39);
        cout<<"       ";
        gotoXY(122, 39);

        // cout<<"Nhập ghế muốn đặt: ";
        // string inputSeat;
        // cin>>inputSeat;
        // row = inputSeat.substr(0,1);
        // column = stoi(inputSeat.substr(1,1));
        click=processInputEvents();
        isEndBookSeat=isClickInRange(click.X, click.Y, 128, 42, 10, 10);
        if(isEndBookSeat){
            break;
        }
        setRowandColumnWhenClick(show,row,column);
        // cout<<row<<column<<endl;
        // ShowSeat& seat = show->getSeatByRowColumn(row, column);
        // seat.displaySeat();
        layoutBooking(this);
        
        if(show->getSeatByRowColumn(row,column).getIsBooked() && statusSeatBeforeClick[convertRowandColToInt(row,column)]==true){
            gotoXY(122, 41);
            cout<<"Ghế đã được đặt"<<endl;
            // i--;
        }
        else if(isClickInRange(click.X, click.Y, 10, 10, 90, 35)==true){
            // seat.setIsBooked(true);
            isFirstClick=true;
            if(show->getSeatByRowColumn(row,column).getIsBooked()==false){
                show->setSeatStatus(row, column, true);
                editSeatStatusInFile(show,shows,show->getID_Show(),row,column,true);
                int rowInt= (char)row[0]-'A';
                int colTemp=column+1;
                //D8
                //-->11+4*8, 15 + 3*8
                
                layoutOneSeat(11+(column+1)*8,15+(rowInt-1)*3,show->getSeatByRowColumn(row,column).getSeatRow(),show->getSeatByRowColumn(row,column).getSeatColumn(),BG_GREEN);
                this->seats.push_back(show->getSeatByRowColumn(row,column));
                time_t t = time(0);
                totalPrice+=show->getSeatByRowColumn(row,column).getPrice();
                this->setTotalPrice(totalPrice);
                this->setBookingTime(ctime(&t));
                this->setNumberOfSeats(this->getNumberOfSeats()+1);
                this->setShow(show);
                layoutBooking(this);
            }
            else{
                show->setSeatStatus(row, column, false);
                editSeatStatusInFile(show,shows,show->getID_Show(),row,column,false);
                int rowInt2= (char)row[0]-'A';
                int colTemp2=column+1;
                //D8
                //-->11+4*8, 15 + 3*8
                if(show->getSeatByRowColumn(row,column).convertSeatTypeToSimpleString()=="V"){
                    layoutOneSeat(11+(column+1)*8,15+(rowInt2-1)*3,show->getSeatByRowColumn(row,column).getSeatRow(),show->getSeatByRowColumn(row,column).getSeatColumn(),BG_RED);
                }
                else{
                    layoutOneSeat(11+(column+1)*8,15+(rowInt2-1)*3,show->getSeatByRowColumn(row,column).getSeatRow(),show->getSeatByRowColumn(row,column).getSeatColumn(),BG_BLUE);
                }
                //remove this seat
                for(Node<ShowSeat>* node = this->seats.begin(); node != nullptr; node = node->next){
                    if(node->data.getSeatRow()==row && node->data.getSeatColumn()==column){
                        this->seats.remove(node->data);
                        break;
                    }
                }
                time_t t = time(0);
                totalPrice-=show->getSeatByRowColumn(row,column).getPrice();
                this->setTotalPrice(totalPrice);
                this->setBookingTime(ctime(&t));
                this->setNumberOfSeats(this->getNumberOfSeats()-1);
                this->setShow(show);
                layoutBooking(this);
            }
        // }
            }
    }
            // int indexToPrint=0;
            // for(Node<ShowSeat>* node = this->seats.begin(); node != nullptr; node = node->next){
            //     gotoXY(135+indexToPrint,31);
            //     indexToPrint+=3;
            //     cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
            // }
    system("cls");
    Combo combo;
    combo.processCombo(this); 
    system("cls");
    Coupon coupon;
    coupon.processCoupon(this,this->getAppliedCoupon());
    // gotoXY(122,39);
    // cout<<"Chọn phương thức thanh toán";
    // gotoXY(122,41);
    // cout<<"1. Chuyển khoản";
    // gotoXY(122,43);
    // cout<<"2. Tiền mặt";
    // gotoXY(122,45);
    // cout<<"Nhập lựa chọn của bạn: ";
    gotoXY(142, 33 +2 );
    cout<<"- "<<coupon.getDiscount();
        this->setPayment(new CreditCardPayment());
        this->getPayment()->processPayment(this);
    

    this->saveBookingToFile();
    //calculate total price
    // cout<<"Total price: "<<totalPrice<<endl;
    // cout<<"Confirm booking? 1.Yes 2.No"<<endl;
    
    // cin>>opt;
    //layoutBooking(this);
    // if(opt==1){
    //     //save booking to file
    //     //edit in file
    //     //showInstance.displayAllShow(shows);
    //     //editSeatStatusInFile(show,shows,show->getID_Show(),row,column,true);
    //     //* chưa xử lý 2 ghế, cái ni mới dùng đc 1 ghế chơ mấy.
    //     //* oke mai xu ly cai vu show chui vo chung 1 lan 
    //     //update seat status
    //     //update booking list


    //     // cout<<"Booking confirmed."<<endl;
    //     // this->setShow(show);
    //     // this->setNumberOfSeats(numberOfSeats);
    //     // this->setTotalPrice(totalPrice);
    //     // cout<<"Booking number: "<<this->getBookingNumber()<<endl;
    //     // this->getShow()->displayShow();
    //     // cout<<"Number of seats: "<<this->getNumberOfSeats()<<endl;
    //     // cout<<"Seat: "<<endl;
    //     // cout<<"Row Column Type Price Status"<<endl;
    //     // cout<<"--------------------------------"<<endl;
    //     // for(Node<ShowSeat>* node = this->seats.begin(); node != nullptr; node = node->next){
    //     //     node->data.displaySeat();
    //     // }
    //     // cout<<"Total Price: "<<this->getTotalPrice();
        
    //     layoutBooking(this);

    //     //displayAllSeatToBook(show);
    // }
    
}
void Booking::getRandomBookingNumber()
{
    const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string randomString;
    srand(time(nullptr)); // Khởi tạo seed dựa trên thời gian thực
    
    for (int i = 0; i < 10; ++i) {
        randomString += charset[rand() % charset.size()];
    }
    this->bookingNumber = randomString;
    
}
DoubleLinkedList<Combo>& Booking::getCombos()
{
    return this->combos;
}

void Booking::saveBookingToFile()
{
    ofstream file("../Databases/Booking.txt", ios::app);
    file << "Mã vé: " << this->bookingNumber << endl;
    file << "Thời gian đặt vé: " << this->bookingTime << endl;
    file << "Khách hàng: " << this->customer->getUserName() << endl;
    file << "Mã suất chiếu: " << this->show->getID_Show() << endl;
    file << "Tên phim:"<<this->show->getMovie()->getTitle()<<endl;
    file << "Thời gian chiếu: " << this->show->getStartTime() << " - " << this->show->getEndTime() << " " << this->show->getDate() << endl;
    file << "Danh sách ghế: ";
    for(Node<ShowSeat>* node = this->seats.begin(); node != nullptr; node = node->next){
        file << node->data.getSeatRow() << node->data.getSeatColumn() << " ";
    }
    file<<endl;
    file << "Danh sách các combo: "<<endl;
    for(Node<Combo>* node = this->combos.begin(); node != nullptr; node = node->next){
        file <<node->data.getQuantityBuy()<<"x" <<node->data.getComboName();
        file<<endl;
    }
    file<<"/"<<endl;
    file << "Mã giảm giá: " << this->appliedCoupon->getCouponCode() << endl;
    file << "Phương thức thanh toán: " << this->payment->getPaymentMethod() << endl;
    file << "Tổng cộng: " << this->totalPrice << endl;
    // file << "BookingStatus: " << this->status << endl;
    file << "--------------------------------" << endl;
    file.close();
}
void Booking::loadBookingFromFile(DoubleLinkedList<Booking>& bookings,DoubleLinkedList<Customer>& customers)
{
    ifstream file("../Databases/Booking.txt");
    string line;
    Booking* booking = nullptr;
    string lineCoupon;
    while (getline(file, line))
    {   
        istringstream ss(line);
        string key;

        if (line.find("Mã vé: ",0) == 0)
        {   
            if(booking!=nullptr){
                bookings.push_back(*booking);
            }
            booking = new Booking();
            booking->setBookingNumber(line.substr(9));
            
        }
        else if (line.find("Thời gian đặt vé: ") != string::npos)
        {
            booking->setBookingTime(line.substr(24));
        }
        else if (line.find("Khách hàng: ") != string::npos)
        {
            Customer* customer;
            // customer.selectCustomer();
            booking->setCustomer(customer->getCustomerByUsername(customers,line.substr(14)));
        }
        ///! fix được tới đay rồi
        //!lỗi do mấy cái hàm line bị sai thôi
        else if (line.find("Mã suất chiếu: ") != string::npos)
        {
            Show show;
            Show* showTemp = selectShowByID(line.substr(20));
            booking->setShow(showTemp);
            
        }
        else if (line.find("Thời gian chiếu: ") != string::npos)
        {
            string time = line.substr(21);
            string startTime = time.substr(0, 5);
            string endTime = time.substr(8, 5);
            string date = time.substr(14);
            booking->getShow()->setStartTime(startTime);
            booking->getShow()->setEndTime(endTime);
            booking->getShow()->setDate(date);
        }
        else if (line.find("Danh sách ghế: ") != string::npos)
        {
            string seats = line.substr(18);
            for(int i=0;i<seats.size();i+=3){
                string seatRow = seats.substr(i,1);
                int seatColumn = stoi(seats.substr(i+1,1));
                ShowSeat seat = booking->getShow()->getSeatByRowColumn(seatRow,seatColumn);
                booking->getSeats().push_back(seat);
            }
            cout<<"huhuhu"<<endl;
            cout<<booking->getSeats().getSize()<<endl;
        }
        else if (line.find("Danh sách các combo: ") != string::npos)
        {
            //Danh sách các combo: 
            //1x Combo Vui vẻ
            //1x Combo Hẹn hò
            string linee="d";
            DoubleLinkedList<Combo> comboList;
            Combo comboInstance;
            comboInstance.loadComboFromFile(comboList);
            streampos pos;
            while(!linee.empty()){
                pos = file.tellg();

                getline(file,linee);

                if(linee.find("/") != string::npos ){
                    // file.seekg(pos);
                    
                    break;
                }
                cout<<linee<<endl;
                string quantity;
                string comboName;
                quantity = linee.substr(0,1);
                cout<<quantity<<endl;
                comboName = linee.substr(3);
                cout<<comboName<<endl;
                
                Combo combo;
                for(int i=0;i<comboList.getSize();i++){
                    string name = comboList[i].getComboName().substr(1);
                    if(comboList[i].getComboName()==comboName){
                        combo = comboList[i];
                        break;
                    }
                }
                combo.setQuantityBuy(stoi(quantity));
                booking->getCombos().push_back(combo);
                cout<<booking->getCombos().getSize()<<endl;
                

            }
            cout<<"combo size: "<<booking->getCombos().getSize()<<endl;
        }
        /////! fix được tới đây rồi
        else if(line.find("Mã giảm giá: ") != string::npos)
        {   
            string couponCode = line.substr(17);
            Coupon* coupon = new Coupon();
            coupon->setCouponCode(couponCode);
            booking->setAppliedCoupon(coupon);
            
        }
        else if (line.find("Phương thức thanh toán: ") != string::npos)
        {
            string paymentMethod = line.substr(29);
            cout<<paymentMethod<<endl;
            if (paymentMethod == "Chuyển khoản")
            {   
                booking->setPayment(new CreditCardPayment());
            }
            else if (paymentMethod == "Tiền mặt")
            {
                booking->setPayment(new CashPayment());
            }
            cout<<booking->getPayment()->getPaymentMethod()<<endl;
        }
        else if (line.find("Tổng cộng: ") != string::npos)
        {   
            cout<<line.substr(15)<<endl;
            booking->setTotalPrice(stod(line.substr(15)));
            cout<<booking->getTotalPrice()<<endl;
        }
        
    }
    if(booking!=nullptr){
        bookings.push_back(*booking);
    }
}