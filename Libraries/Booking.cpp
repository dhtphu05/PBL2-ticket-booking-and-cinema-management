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
#include "../Include/menu.h"
class Show;
class Screen;
class ShowSeat;
string BG_YELLOW_ = "\033[33m";
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
void cloneLayoutProcessBooking(int x, int y, int indexProcess=0, string colorAll = "", string colorChoose = BG_GREEN ) {
    borderLineWithTextAndColor(x, y, "Chọn phim/ suất chiếu 🎬", colorAll);
    gotoXY(x+25,y);
    
    borderLineWithTextAndColor(x + 30, y, "Chọn ghế 🎥", colorAll);
    borderLineWithTextAndColor(x + 30+20, y, "Chọn bắp/nước 🎁", colorAll);
    borderLineWithTextAndColor(x + 50+20, y, "Thanh toán 🍿", colorAll);
    borderLineWithTextAndColor(x + 70+20, y, "Xác nhận 💳", colorAll);
switch (indexProcess) {
    case 1:
        borderLineWithTextAndColor(x, y, "Chọn phim/ suất chiếu 🎬", colorChoose);
        break;
    case 2:
        borderLineWithTextAndColor(x + 30, y, "Chọn ghế 🎥", colorChoose);
        break;
    case 3:
        borderLineWithTextAndColor(x + 50, y, "Chọn bắp/nước 🎁", colorChoose);
        break;
    case 4:
        borderLineWithTextAndColor(x + 70, y, "Thanh toán 🍿", colorChoose);
        break;
    case 5:
        borderLineWithTextAndColor(x + 90, y, "Xác nhận 💳", colorChoose);
        break;
    default:
        break;
}
}
void cloneLayoutProcessAddShow(int x, int y, int indexProcess=0, string colorAll = "", string colorChoose = BG_GREEN ) {
    borderLineWithTextAndColor(x, y, "Chọn phim 🎬", colorAll);
    borderLineWithTextAndColor(x + 20, y, "Chọn ngày chiếu 🎥", colorAll);
    borderLineWithTextAndColor(x + 45, y, "Chọn phòng chiếu 🎥", colorAll);
    borderLineWithTextAndColor(x + 70, y, "Chọn thời gian bắt đầu suất chiếu 🎁", colorAll);
switch (indexProcess) {
    case 1:
        borderLineWithTextAndColor(x, y, "Chọn phim/ suất chiếu 🎬", colorChoose);
        break;
    case 2:
        borderLineWithTextAndColor(x + 20, y, "Chọn ngày chiếu 🎥", colorChoose);
        break;
    case 3:
        borderLineWithTextAndColor(x + 45, y, "Chọn phòng chiếu 🎥", colorChoose);
        break;
    case 4:
        borderLineWithTextAndColor(x + 70, y, "Chọn thời gian bắt đầu suất chiếu 🎁", colorChoose);
        break;
    default:
        break;
}
}
string makeSpaceToMoney(string money){
    string result="";
    int count=0;
    for(int i=money.length()-1;i>=0;i--){
        count++;
        result=money[i]+result;
        if(count%3==0 && i!=0){
            result=" "+result;
        }
    }
    return result;
}

//!TODO: 1 hóa đơn là tạo 1 file
void Booking::sellTicket(DoubleLinkedList<Show>& shows,DoubleLinkedList<Screen> &screens,DoubleLinkedList<Movie> &movies)
{   system("cls");
    if(this->getCustomer()->getUserName()!="Guest"){
    borderLineWithTextAndColor(120,1,"Khách hàng: "+this->getCustomer()->getFullName(),BG_CYAN);
    }
    if(this->getAdmin()!=nullptr){
        borderLineWithTextAndColor(120,2,"Nhân viên: "+this->getAdmin()->getFullName(),BG_CYAN);
    }
    Movie movieInstance;
    Movie* movie= &movieInstance;
    //movie->selectMovieToBooking(movies);
    
    //cout<<movie->getCountry()<<endl;
    Show showInstance;
    Show* show = new Show;
    // show->selectShow(movie, screens);
    show=this->getShow();
    system("cls");
    layoutBorderSeat(show);
    // this->setShow(show);
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
    cloneLayoutProcessBooking(20, 0, 2, BG_YELLOW_, BG_GREEN);
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
                //only get hour and minute of time
                
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
    cloneLayoutProcessBooking(20, 0, 3, BG_YELLOW_, BG_GREEN);

    combo.processCombo(this); 
    system("cls");
    Coupon coupon;
    cloneLayoutProcessBooking(20, 0, 4, BG_YELLOW_, BG_GREEN);
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
        cloneLayoutProcessBooking(20, 0, 5, BG_YELLOW_, BG_GREEN);
        this->setPayment(new CreditCardPayment());
        this->getPayment()->processPayment(this);
    this->saveBookingToFile();
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
    bookings.clear();
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
                string quantity;
                string comboName;
                quantity = linee.substr(0,1);
                comboName = linee.substr(3);
                comboName= " "+comboName;
                Combo combo;
                for(int i=0;i<comboList.getSize();i++){
                    
                    if(comboList[i].getComboName()==comboName){
                        comboList[i].setQuantityBuy(stoi(quantity));
                        booking->getCombos().push_back(comboList[i]);
                        break;
                    }
                }
                

            }
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
            if (paymentMethod == "Chuyển khoản")
            {   
                booking->setPayment(new CreditCardPayment());
            }
            else if (paymentMethod == "Tiền mặt")
            {
                booking->setPayment(new CashPayment());
            }
        }
        else if (line.find("Tổng cộng: ") != string::npos)
        {   
            booking->setTotalPrice(stod(line.substr(15)));
        }
        
    }
    if(booking!=nullptr){
        bookings.push_back(*booking);
    }
}

void displayListBookingLikeTableOfCustomer(Customer *customer, DoubleLinkedList<Booking> &bookings, int x, int y){
    gotoXY(x,y);
    cout<<"Danh sách vé đã đặt: ";
    y+=2;
    borderLineWithTextAndColor(x,y,"Mã vé  ",BG_CYAN);
    borderLineWithTextAndColor(x+15,y,"Thời gian đặt vé    ",BG_CYAN);
    borderLineWithTextAndColor(x+50,y,"Tên phim",BG_CYAN);
    borderLineWithTextAndColor(x+90,y,"Thời gian chiếu",BG_CYAN);
    borderLineWithTextAndColor(x+120,y,"Tổng cộng",BG_CYAN);
    y+=4;

    // i want to display booking follow order early to late
    for(Node<Booking>* node = bookings.begin(); node != nullptr; node = node->next){
        if(node->data.getCustomer()->getUserName()==customer->getUserName()){
            borderLineWithTextAndColor(x,y,node->data.getBookingNumber());
            borderLineWithTextAndColor(x+15,y,convertDateDefalutToSimple(node->data.getBookingTime()));
            borderLineWithTextAndColor(x+40,y,node->data.getShow()->getMovie()->getTitle());
            borderLineWithTextAndColor(x+90,y,node->data.getShow()->getStartTime()+" ~ "+node->data.getShow()->getEndTime()+" "+node->data.getShow()->getDate());
            //convert double to string, and replace .00000
            borderLineWithTextAndColor(x+120,y,convertMoney(node->data.getTotalPrice()));
            
            borderLineWithTextAndColor(x+130,y, "Xem chi tiết");
            y+=5;
        }
    }
}
void getListBookingOfCustomer(Customer* customer, DoubleLinkedList<Booking>& bookings, DoubleLinkedList<Booking>& result){
    for(Node<Booking>* node = bookings.begin(); node != nullptr; node = node->next){
        if(node->data.getCustomer()->getUserName()==customer->getUserName()){
            result.push_back(node->data);
        }
    }
}
void displayBookingDetail(Booking* booking, int x, int y){
    gotoXY(x,y);
    cout<<"Chi tiết vé: ";
    y+=2;
    borderLineWithTextAndColor(x,y,"Mã vé: "+booking->getBookingNumber(),BG_CYAN);
    borderLineWithTextAndColor(x,y+2,"Thời gian đặt vé: "+convertDateDefalutToSimple(booking->getBookingTime()),BG_CYAN);
    borderLineWithTextAndColor(x,y+4,"Tên phim: "+booking->getShow()->getMovie()->getTitle(),BG_CYAN);
    borderLineWithTextAndColor(x,y+6,"Thời gian chiếu: "+booking->getShow()->getStartTime()+" ~ "+booking->getShow()->getEndTime()+" "+booking->getShow()->getDate(),BG_CYAN);
    borderLineWithTextAndColor(x,y+8,"Danh sách ghế: ",BG_CYAN);
    y+=10;
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
        borderLineWithTextAndColor(x,y,node->data.getSeatRow()+to_string(node->data.getSeatColumn()),BG_CYAN);
        y+=2;
    }
    borderLineWithTextAndColor(x,y,"Danh sách combo: ",BG_CYAN);
    y+=2;
    for(Node<Combo>* node = booking->getCombos().begin(); node != nullptr; node = node->next){
        borderLineWithTextAndColor(x,y,to_string(node->data.getQuantityBuy())+"x "+node->data.getComboName(),BG_CYAN);
        y+=2;
    }
    borderLineWithTextAndColor(x,y,"Mã giảm giá: "+booking->getAppliedCoupon()->getCouponCode(),BG_CYAN);
    borderLineWithTextAndColor(x,y+2,"Phương thức thanh toán: "+booking->getPayment()->getPaymentMethod(),BG_CYAN);
    borderLineWithTextAndColor(x,y+4,"Tổng cộng: "+convertMoney(booking->getTotalPrice()),BG_CYAN);
}
int getClickBookingDetail(DoubleLinkedList<Booking> bookingList,int x,int y){
    click=processInputEvents();
    int i=0;
    for(Node<Booking>* node = bookingList.begin(); node != nullptr; node = node->next){
        if(isClickInRange(click.X, click.Y, x+130, y+6+i*5, 7,1)){
            return i;
        }
        i++;
    }
}
void displayBookingDetailFollowIndex(DoubleLinkedList<Booking> bookingList, int index, int x, int y){
    int i=0;
    for(Node<Booking>* node = bookingList.begin(); node != nullptr; node = node->next){
        if(i==index){
            layoutFinal(&node->data,node->data.getAppliedCoupon());
            // displayBookingDetail(&node->data,x,y);
            break;
        }   
        i++;
    }
}

//! section select movie
void displayShowFollowMovie(Booking &booking,DoubleLinkedList<Show>&showList, Movie* movie, int x, int y, string Date);

void displayMovieFollowStartDateShow(Booking& booking,DoubleLinkedList<Show> &showList, DoubleLinkedList<Movie>&movieList, int x, int y,string Date){
    // list of movies having shows today
    time_t timeinDay= time(0);
    tm *ltm = localtime(&timeinDay);
    string date= convertDateDefalutToSimple(ctime(&timeinDay));
    //get only day month year
    date=date.substr(9);
    if(Date!=date){
        date=Date;
    }
    // cout<<date;
    
    DoubleLinkedList<Movie> movieListToday;
    
    for(Node<Show>* node = showList.begin(); node != nullptr; node = node->next){
        if(node->data.getDate()==date){
            // cout<<"------"<<node->data.getMovie()->getTitle()<<"//"<<endl;
            movieListToday.push_back(*node->data.getMovie());
        }
    }
    //delete duplicate movies
    for(Node<Movie>* node = movieListToday.begin(); node != nullptr; node = node->next){
        for(Node<Movie>* node2 = node->next; node2 != nullptr; node2 = node2->next){
            if(node->data.getTitle()==node2->data.getTitle() ){
                // cout<<"delete"<<node2->data.getTitle()<<endl;   
                movieListToday.remove(node2->data);
            }
        }
    }
    //display list of movies
    int i=0,j=0;
    //i want to display 3 movies in a row
    i=0;j=0;
    for(Node<Movie>* node = movieListToday.begin(); node != nullptr; node = node->next){
        if(i==3){
            i=0;
            j+=20;
        }
        borderLineWithTextAndColor(x+i*60,y+j,node->data.getTitle(),BG_CYAN);
        displayImageFile(node->data, x-6+i*60, y+j+2);
        i++;
    }
    if(movieListToday.getSize()==0){
        borderLineWithTextAndColor(50,27,"Không có suất chiếu phim nào trong hôm nay",BG_RED);
    }
    //select movie
    while(booking.getShow()==nullptr){
        click=processInputEvents();
        if(isClickInRange(click.X, click.Y, 135, 2, 10,3)){
            return;
        }
        i=0;j=0;
        for(Node<Movie>* node = movieListToday.begin(); node != nullptr; node = node->next){
            if(i==3){
                i=0;
                j+=20;
            }
            borderLineWithTextAndColor(x+i*60,y+j,node->data.getTitle(),BG_CYAN);
            displayImageFile(node->data, x-6+i*60, y+j+2);
            i++;
        }
        
        if(isClickInRange(click.X, click.Y, 135, 2, 10,3)){
            return;
        }
        system("cls");
        i=0;
        j=0;
        for(Node<Movie>* node = movieListToday.begin(); node != nullptr; node = node->next){
            if(i==3){
                i=0;
                j+=20;
            }
            if(isClickInRange(click.X, click.Y, x-6+i*60, y+j+2, 30,20)){
                displayShowFollowMovie(booking,showList,&node->data,x+15,y+15, Date);
                
                // displayShowFollowMovie(booking,showList,&node->data, x, y);
                break;
            }
            i++;
        }
    }
}
void displayShowFollowMovie(Booking &booking,DoubleLinkedList<Show>&showList, Movie* movie, int x, int y, string Date){
    // system("cls");
    cloneLayoutProcessBooking(20, 0, 1, BG_RED, BG_GREEN);
    //get time to hide the layout
    time_t t = time(0);
    tm* now = localtime(&t);
    int hour = now->tm_hour;
    int minute = now->tm_min;
    // cout<<hour<<":"<<minute<<endl;
    //get time to compare start time of show
    int i=0,j=0;
    for(Node<Show>* node = showList.begin(); node != nullptr; node = node->next){
        if(node->data.getMovie()->getTitle()==movie->getTitle() && node->data.getDate()==Date){
            borderLineWithTextAndColor(x+i*20,y+j+3,node->data.getStartTime()+" ~ "+node->data.getEndTime(),BG_CYAN);
            i++;
        }
    }
    borderLineWithTextAndColor(135,2,"Quay lại",BG_CYAN);

    if(movie != nullptr) {
        movie->showDetailMovie(); 
    }
    //select show
    bool isClear=false;
    while(booking.getShow()==nullptr){
        click=processInputEvents();
        if(isClickInRange(click.X, click.Y, 135, 2, 8,3)){
            return;
        }
        isClear=true;
        i=0;
        for(Node<Show>* node = showList.begin(); node != nullptr; node = node->next){
            if(node->data.getMovie()->getTitle()==movie->getTitle() && node->data.getDate()==Date){
                if(isClickInRange(click.X, click.Y, x+i*20, y+3, 20,1)){
                    booking.setShow(&node->data);
                    break;
                }
                i++;
            }
            
        }
    }
}
void layoutListDate(int x = 0, int y = 0, const string& today = "07/12/2023")
{   
    cloneLayoutProcessBooking(20, 0, 1, BG_RED, BG_GREEN);

    // Parse the input date
    
    int day = stoi(today.substr(0, 2));
    int month = stoi(today.substr(3, 2));
    int year = stoi(today.substr(6, 4));

    // Array of day names
    string daysOfWeek[] = {"Chủ nhật", "Thứ hai", "Thứ ba", "Thứ tư", "Thứ năm", "Thứ sáu", "Thứ bảy"};

    // Calculate the day of the week for the given date
    tm time_in = { 0, 0, 0, day, month - 1, year - 1900 };
    time_t time_temp = mktime(&time_in);
    const tm * time_out = localtime(&time_temp);
    int todayIndex = time_out->tm_wday;

    cout << BG_GREEN;
    bool isToday = true;
    for (int i = 0; i < 7; ++i)
    {
        int currentDay = day + i;
        int currentMonth = month;
        int currentYear = year;

        // Adjust the day and month if necessary
        if (currentDay > 30) // Simplified month length, you can add more precise calculation
        {
            currentDay -= 30;
            currentMonth++;
            if (currentMonth > 12)
            {
                currentMonth = 1;
                currentYear++;
            }
        }
        
        lineWidth(10, x + (i * 15), y, true, true);
        if(isToday){
                    showString("│ " + daysOfWeek[(todayIndex + i) % 7] + "  │", x + (i * 15), y + 1);
                    isToday=false;
        }
        else{
        showString("│ " + daysOfWeek[(todayIndex + i) % 7] + "  │", x + (i * 15), y + 1);
        }
        std::ostringstream oss;
        oss << "│  " << (currentDay < 10 ? "0" : "") << currentDay << "/" << (currentMonth < 10 ? "0" : "") << currentMonth << "   │";
        showString(oss.str(), x + (i * 15), y + 2);
        lineWidth(10, x + (i * 15), y + 3, true, false);
    }
    cout << RESET;
}
void onlyLayoutDate(int x = 0, int y = 0, const string& today = "07/12/2023"){
    // Parse the input date
    
    int day = stoi(today.substr(0, 2));
    int month = stoi(today.substr(3, 2));
    int year = stoi(today.substr(6, 4));

    // Array of day names
    string daysOfWeek[] = {"Chủ nhật", "Thứ hai", "Thứ ba", "Thứ tư", "Thứ năm", "Thứ sáu", "Thứ bảy"};

    // Calculate the day of the week for the given date
    tm time_in = { 0, 0, 0, day, month - 1, year - 1900 };
    time_t time_temp = mktime(&time_in);
    const tm * time_out = localtime(&time_temp);
    int todayIndex = time_out->tm_wday;

    cout << BG_GREEN;
    bool isToday = true;
    for (int i = 0; i < 7; ++i)
    {
        int currentDay = day + i;
        int currentMonth = month;
        int currentYear = year;

        // Adjust the day and month if necessary
        if (currentDay > 30) // Simplified month length, you can add more precise calculation
        {
            currentDay -= 30;
            currentMonth++;
            if (currentMonth > 12)
            {
                currentMonth = 1;
                currentYear++;
            }
        }
        
        lineWidth(10, x + (i * 15), y, true, true);
        if(isToday){
                    showString("│ " + daysOfWeek[(todayIndex + i) % 7] + "  │", x + (i * 15), y + 1);
                    isToday=false;
        }
        else{
        showString("│ " + daysOfWeek[(todayIndex + i) % 7] + "  │", x + (i * 15), y + 1);
        }
        std::ostringstream oss;
        oss << "│  " << (currentDay < 10 ? "0" : "") << currentDay << "/" << (currentMonth < 10 ? "0" : "") << currentMonth << "   │";
        showString(oss.str(), x + (i * 15), y + 2);
        lineWidth(10, x + (i * 15), y + 3, true, false);
    }
    cout << RESET;

}
string dateOfClick(int x,int y){
    int i=0;
    //i want to return date in format dd/mm/yyyy
    time_t timeinDay= time(0);
    tm *ltm = localtime(&timeinDay);
    string date= convertDateDefalutToSimple(ctime(&timeinDay));
    //get only day month year
    date=date.substr(9);
    click=processInputEvents();
    for(int i=0;i<7;i++){
        if(isClickInRange(click.X, click.Y, x+i*15, y, 20,3)){
            int day = stoi(date.substr(0, 2));
            int month = stoi(date.substr(3, 2));
            int year = stoi(date.substr(6, 4));
            // Adjust the day and month if necessary
            if (day+i > 30) // Simplified month length, you can add more precise calculation
            {
                day += i-30;
                month++;
                if (month > 12)
                {
                    month = 1;
                    year++;
                }
            }
            string dayStr = to_string(day+i);
            string monthStr = to_string(month);
            if(day+i<10){
                dayStr="0"+dayStr;
            }
            if(month<10){
                monthStr="0"+monthStr;
            }
            //i want to color the date that i click
            std::ostringstream oss;
            lineWidth(10, x + 10+ (i * 15), y, true, true);
            oss << "│  "<<BG_RED << dayStr << "/" << monthStr <<RESET<< "   │";

            return dayStr+"/"+monthStr+"/"+to_string(year);
        }
    }
}

void layoutWhenClickToDate(Booking& booking, DoubleLinkedList<Show> &showList, DoubleLinkedList<Movie> &movieList, int x, int y){
    string today;
    //dd/mm/yyyy
    Show showInstance;
    Screen screenInstance;
    DoubleLinkedList<Screen> screenList;
    screenInstance.loadScreenFromFile(screenList);
    showInstance.loadShowFromFile(showList,screenList);
    time_t timeinDay= time(0);
    tm *ltm = localtime(&timeinDay);
    today= convertDateDefalutToSimple(ctime(&timeinDay));
    //get only day month year
    today=today.substr(9);
    borderLineWithTextAndColor(135,2,"Quay lại",BG_CYAN);
    label:
    while(booking.getShow()==nullptr){
        cloneLayoutProcessBooking(20, 0, 1, BG_YELLOW_, BG_GREEN);
        layoutListDate(x+10,y,today);
        borderLineWithTextAndColor(135,2,"Quay lại",BG_CYAN);

        string date = dateOfClick(x,y);
        if(isClickInRange(click.X, click.Y, 135, 2, 7,2)){
            goto label;
        }
        displayMovieFollowStartDateShow(booking,showList,movieList,x,y+10,date);
        system("cls");
    }
}
void displayBarTimeInDay(Screen *screen,string date,DoubleLinkedList<Show>& showList, int x,int y){
    //i want to display 3 movies in a row
    system("cls");
    gotoXY(x,y);
    for(int i=1;i<=96/2;i++){
        cout<<"│██";
    }
    gotoXY(x,y+3);
    int indexPrint=0;
    for(int i=1;i<=96/2;i++){
        // gotoXY(x+indexPrint*3,y+3);
        cout<<"│██";
    }
    int check=0;
    //1 block is 15 minutes
    //1 hour is 8 blocks
    //time show get from show start time and end time then round to 15 minutes --> convert to block
    for(Node<Show>* node = showList.begin(); node != nullptr; node = node->next){
        if (node->data.getScreen()->ID_Screen == screen->ID_Screen && node->data.getDate() == date)
        {   

            int startHour=stoi(node->data.getStartTime().substr(0,2));
            int startMinute=stoi(node->data.getStartTime().substr(3,2));
            int endHour=stoi(node->data.getEndTime().substr(0,2));
            int endMinute=stoi(node->data.getEndTime().substr(3,2));
            int startBlock=(startHour)*4+(startMinute+14)/15;
            int endBlock=(endHour)*4+(endMinute+14)/15;
            
            if(startHour<12){
                for(int i=startBlock;i<endBlock;i++){
                    gotoXY(x+i*3,y);
                    cout<<BG_CYAN<<"│██"<<RESET;
                }       
            }
            else{
                for(int i=startBlock;i<endBlock;i++){
                    gotoXY(x+(i-48)*3,y+3);
                    cout<<BG_CYAN<<"│██"<<RESET;
                }
            }
        }
    }
    // caption for time bar, it only caption like 8:00, 9:00, 10:00, 11:00, 12:00, 13:00, 14:00, 15:00, 16:00
    for(int i=0;i<=12;i++){
        gotoXY(x+i*12,y+1);
        cout<<i<<"h";
    }
    for(int i=12;i<=24;i++){
        gotoXY(x+(i-12)*12,y+4);
        if(i==24){
            cout<<"0h";
            break;
        }
        cout<<i<<"h";
    }
}
void deleteSpaceAdmin(){
    int x=0;
    int y=0;
    gotoXY(80,22);
    for(int i=1;i<=22;i++){
        gotoXY(80,22+i);
        cout<<" ";
    }
}

void addShow(DoubleLinkedList<Show>& showList, Movie movieSelected, DoubleLinkedList<Screen>& screenList){
    Show show;
    int x=0;
    int y=0;
    Show showInstance;
    Screen screenInstance;
    screenInstance.loadScreenFromFile(screenList);
    showInstance.loadShowFromFile(showList,screenList);
    system("cls");
    string today;
    cloneLayoutProcessAddShow(20, 0, 2, BG_YELLOW_, BG_GREEN);
    //dd/mm/yyyy
    time_t timeinDay= time(0);
    tm *ltm = localtime(&timeinDay);
    today= convertDateDefalutToSimple(ctime(&timeinDay));
    today=today.substr(9);
    onlyLayoutDate(x+10,y+10,today);
    string date=dateOfClick(x,y+10);
    system("cls");
    Movie *movie=&movieSelected;

    //*select screen
    Screen *screen;
    //* lost function validate duplicate show
    //*display screen to choose
    label_choose_screen:
    int i=0,j=0;
    int xScreen=20;
    int yScreen=10;
    //* id screen, number of seat, number of regular seat, number of vip seat
    system("cls");
    cloneLayoutProcessAddShow(20, 0, 3, BG_YELLOW_, BG_GREEN);

    for(Node<Screen>* node = screenList.begin(); node != nullptr; node = node->next){
        if(i==3){
            i=0;
            j+=20;
        }
        lineWidth(25, xScreen, yScreen+j-1, true, true);
        gotoXY(xScreen,yScreen+j+1);
        borderLineWithTextAndColor(xScreen+3,yScreen+j,"Tên phòng chiếu: "+to_string(node->data.ID_Screen),BG_CYAN);
        gotoXY(xScreen+2,yScreen+j+3);
        cout<<"Tổng số ghế:        "<<BG_GREEN<<node->data.getNumberOfSeat()<<RESET;
        gotoXY(xScreen+2,yScreen+j+5);
        cout<<"Tổng số ghế thường: "<<node->data.getNumberOfRegularSeat();
        gotoXY(xScreen+2,yScreen+j+7);
        cout<<"Tổng số ghế VIP:    "<<node->data.getNumberOfVIPSeat();
        gotoXY(xScreen,yScreen+j);
        lineHeight_main(9,xScreen,yScreen+j);
        lineHeight_main(9,xScreen+26,yScreen+j);
        lineWidth(25,xScreen,yScreen+j+8,true,false);
        borderLineWithTextAndColor(xScreen+30,yScreen+j+3,"Xem chi tiết",BG_CYAN);
        i++;
        //xuong dong list ngang
        j+=13;
    }
    // layout xem chi tiết phòng chiếu
    
    //select screen
    // gotoXY(80,22);
    // cout<<"done display screen";
    
    screen=nullptr;
    bool isSeenDetail=false;
    while(screen==nullptr){
        click=processInputEvents();
        i=0;
        j=0;
        
        for(Node<Screen>* node = screenList.begin(); node != nullptr; node = node->next){
            if(i==3){
                i=0;
                j+=20;
            }
            if(isClickInRange(click.X, click.Y, xScreen+2, yScreen+j, 25,10)){
                screen=&node->data;
                break;
            }
            if(isClickInRange(click.X,click.Y,xScreen+30, yScreen+j+3, 12, 1)){
                system("cls");
                screen=&node->data;
                onlyLayoutSeat(screen);
                screen=nullptr;
                isSeenDetail=true;
                click=processInputEvents();
            }
            i++;
            j+=13;
        }
        if(isSeenDetail)
        goto label_choose_screen;
        
    }
    

    // gotoXY(80,22);
    // cout<<"done select screen";
    //select start time
    cloneLayoutProcessAddShow(20, 0, 4, BG_YELLOW_, BG_GREEN);
    int xTime=5;
    int yTime=10;
    i=0;
    j=0;
    displayBarTimeInDay(screen,date,showList,xTime,yTime);
    string startTime="";
    string endTime;
    bool isValidStartTime=false;
    gotoXY(80,22);
    // cout<<"done display bar time";  

    borderLineWithTextAndColor(xTime+20,yTime+10,"Nhập thời gian bắt đầu suất chiếu (XX:YY):      ", BG_GREEN);
    while(!isValidStartTime){
    click=processInputEvents();
    i=0;
    j=0;
    if(isClickInRange(click.X,click.Y, xTime+20, yTime+10,62,3)){
        isValidStartTime=true;
        getString(startTime,xTime+20+43,yTime+11);
        string durationMovie=to_string(movie->getDurationInt());
            // Add duration (in minutes) to startTime to get endTime
            int startHour = stoi(startTime.substr(0,2));
            int startMinute = stoi(startTime.substr(3,2)); 
            int duration = stoi(durationMovie);

            int totalMinutes = startHour * 60 + startMinute + duration;
            int endHour = totalMinutes / 60;
            int endMinute = totalMinutes % 60;
            // Format hours and minutes with leading zeros if needed
            string endHourStr = (endHour < 10) ? "0" + to_string(endHour) : to_string(endHour);
            string endMinuteStr = (endMinute < 10) ? "0" + to_string(endMinute) : to_string(endMinute);
            endTime = endHourStr + ":" + endMinuteStr;
            if(endMinute==0){
                endTime=endTime+"0";
            }
        for(Node<Show>* node= showList.begin();node!=nullptr; node= node->next ){
            if(node->data.getScreen()->ID_Screen== screen->ID_Screen && node->data.getDate()==date){
                int startHour=stoi(node->data.getStartTime().substr(0,2));
                int startMinute=stoi(node->data.getStartTime().substr(3,2));
                
                int endHour=stoi(node->data.getEndTime().substr(0,2));
                int endMinute=stoi(node->data.getEndTime().substr(3,2));
                int totalMinutesStart=startHour*60+startMinute;
                int totalMinutesEnd=endHour*60+endMinute;
                int totalMinutesStartInput=stoi(startTime.substr(0,2))*60+stoi(startTime.substr(3,2));
                int totalMinutesEndInput=stoi(endTime.substr(0,2))*60+stoi(endTime.substr(3,2));
                if((totalMinutesStartInput>=totalMinutesStart && totalMinutesStartInput<=totalMinutesEnd) || (totalMinutesEndInput>=totalMinutesStart && totalMinutesEndInput<=totalMinutesEnd)){
                    isValidStartTime=false;
                    borderLineWithTextAndColor(80,22,"Khung giờ đã có suất chiếu",BG_RED);
                    gotoXY(xTime+20+43,yTime+11);
                    cout<<"     ";
                    break;
                }
            }
        }
    }
    if(isValidStartTime){
            int startHour=stoi(startTime.substr(0,2));
            int startMinute=stoi(startTime.substr(3,2));
            int endHour=stoi(endTime.substr(0,2));
            int endMinute=stoi(endTime.substr(3,2));
            int startBlock=(startHour)*4+(startMinute+14)/15;
            int endBlock=(endHour)*4+(endMinute+14)/15;
            for(int i=startBlock;i<endBlock;i++){
                if(startHour<12){
                    gotoXY(xTime+i*3,yTime);
                    cout<<BG_GREEN<<"│██"<<RESET;
                }
                else{
                    gotoXY(xTime+(i-48)*3,yTime+3);
                    cout<<BG_GREEN<<"│██"<<RESET;
                }
            }
    }

    // if(isClickInRange(click.X, click.Y, xTime, yTime, 48*3,2) || isClickInRange(click.X, click.Y, xTime, yTime+3, 48*3,2)){
    //     isValidStartTime=true;
        

    //     if(isValidStartTime){
    //         if(click.Y==yTime+3){
    //             startTime=to_string((click.X-xTime)/12+12)+":"+to_string((click.X-xTime)%12/3*15);
                
    //         }
    //         else{
    //             startTime=to_string((click.X-xTime)/12)+":"+to_string((click.X-xTime)%12/3*15);
    //         }
    //         string durationMovie=to_string(movie->getDurationInt());
        
    //         // Add duration (in minutes) to startTime to get endTime
    //         int startHour = stoi(startTime.substr(0,2));
    //         int startMinute = stoi(startTime.substr(3,2)); 
    //         int duration = stoi(durationMovie);

    //         int totalMinutes = startHour * 60 + startMinute + duration;
    //         int endHour = totalMinutes / 60;
    //         int endMinute = totalMinutes % 60;
            
    //         // Format hours and minutes with leading zeros if needed
    //         string endHourStr = (endHour < 10) ? "0" + to_string(endHour) : to_string(endHour);
    //         string endMinuteStr = (endMinute < 10) ? "0" + to_string(endMinute) : to_string(endMinute);
    //         endTime = endHourStr + ":" + endMinuteStr;
    //         if(((click.X-xTime)%12/3*15)==0){
    //                 startTime=startTime+ "0";
    //         }
    //         if( (((click.X-xTime)/12+12)<10) && click.Y==yTime ){
    //                 startTime="0"+startTime;
    //         }
            
    //     }



    //     for(Node<Show>* node = showList.begin(); node != nullptr; node = node->next){
    //     if (node->data.getScreen()->ID_Screen == screen->ID_Screen && node->data.getDate() == date)
    //     {   
            
    //         int startHour=stoi(node->data.getStartTime().substr(0,2));
    //         int startMinute=stoi(node->data.getStartTime().substr(3,2));
    //         int endHour=stoi(node->data.getEndTime().substr(0,2));
    //         int endMinute=stoi(node->data.getEndTime().substr(3,2));
    //         int startBlock=(startHour)*4+(startMinute+14)/15;
    //         int endBlock=(endHour)*4+(endMinute+14)/15;
            
    //             int endHourOfEndTime=stoi(endTime.substr(0,2));
    //             int endMinuteOfEndTime=stoi(endTime.substr(3,2));
    //             int startBlockOfEndTime=(endHourOfEndTime)*4+(endMinuteOfEndTime+14)/15;

    //         if(startHour<12){
    //             for(int i=startBlock;i<endBlock;i++){
    //                 if(i==startBlockOfEndTime){
    //                     isValidStartTime=false;
    //                 }
    //                 if(isClickInRange(click.X, click.Y, xTime+i*3, yTime,3,1)){
    //                     isValidStartTime=false;
    //                 gotoXY(80,22);
    //                 cout<<"Khung giờ đã có suất chiếu";
    //                 break;
    //             }  
    //         }
    //         }
    //         else{
    //             for(int i=startBlock;i<endBlock;i++){
    //                 if(i==startBlockOfEndTime){
    //                     isValidStartTime=false;
    //                 }
    //                 if(isClickInRange(click.X, click.Y, xTime+(i-48)*3, yTime+3, 3,1)){
    //                     isValidStartTime=false;
    //                 gotoXY(80,24);
    //                 cout<<"Khung giờ đã có suất chiếu";
    //                 break;
    //             }  
    //             }
    //         }
    //     }
    //     if(isValidStartTime){
    //         if(click.Y==yTime+3){
    //             startTime=to_string((click.X-xTime)/12+12)+":"+to_string((click.X-xTime)%12/3*15);
                
    //         }
    //         else{
    //             startTime=to_string((click.X-xTime)/12)+":"+to_string((click.X-xTime)%12/3*15);
                
                
    //         }
    //         string durationMovie=to_string(movie->getDurationInt());
        
    //         // Add duration (in minutes) to startTime to get endTime
    //         int startHour = stoi(startTime.substr(0,2));
    //         int startMinute = stoi(startTime.substr(3,2)); 
    //         int duration = stoi(durationMovie);

    //         int totalMinutes = startHour * 60 + startMinute + duration;
    //         int endHour = totalMinutes / 60;
    //         int endMinute = totalMinutes % 60;
            
    //         // Format hours and minutes with leading zeros if needed
    //         string endHourStr = (endHour < 10) ? "0" + to_string(endHour) : to_string(endHour);
    //         string endMinuteStr = (endMinute < 10) ? "0" + to_string(endMinute) : to_string(endMinute);
    //         endTime = endHourStr + ":" + endMinuteStr;
    //         if(((click.X-xTime)%12/3*15)==0){
    //                 startTime=startTime+ "0";
    //         }
    //         if( (((click.X-xTime)/12+12)<10) && click.Y==yTime ){
    //                 startTime="0"+startTime;
    //         }
            
    //     }
    //     gotoXY(100,25);
    //     cout<<"haha"<<isValidStartTime;
    // }
    
    // }
    // cout<<"hihi"<<isValidStartTime;
    
    }
    borderLineWithTextAndColor(70,22+2, "Tên phim: "+movie->getTitle(),BG_CYAN);
    borderLineWithTextAndColor(70,26+2, "Ngày chiếu: "+date,BG_CYAN);
    borderLineWithTextAndColor(70,30+2, "Thời gian bắt đầu của suất chiếu: "+startTime,BG_CYAN);
    borderLineWithTextAndColor(70,34+2, "Thời gian kết thúc của suất chiếu: "+endTime,BG_CYAN);
    borderLineWithTextAndColor(65,38+2, "Thêm suất chiếu thành công",BG_GREEN);
    // cout<<"done select time";
    // screen->displayScreen();
    ofstream file("../Databases/Show.txt", ios::app);
    file <<endl;
    file<< "#Show Details"<<endl;
    file<< "ShowID: " << "S"+to_string(showList.getSize() + 1) << endl;
    file<< "Date: " << date << endl;
    file<< "StartTime: " << startTime << endl;
    file<< "EndTime: " << endTime << endl;
    file<< "Screen: " << screen->ID_Screen << endl;
    file<< "Movie: " << movie->getID_Movie() << endl;
    file<<"# SeatList"<<endl;
    for(Node<Seat>* node = screen->getSeatLayout().begin(); node != nullptr; node = node->next){
        if(convertSeatTypeToString(node->data.getType())=="Regular"){
            file<<"Seat: "<<node->data.getSeatRow()<<" "<<node->data.getSeatColumn()<<" "<<convertSeatTypeToString(node->data.getType())<<" "<<"50000"<<" "<< "Available"<<endl;
        }
        else if(convertSeatTypeToString(node->data.getType())=="VIP"){
            file<<"Seat: "<<node->data.getSeatRow()<<" "<<node->data.getSeatColumn()<<" "<<convertSeatTypeToString(node->data.getType())<<" "<<"90000"<<" "<< "Available"<<endl;
        }
        else{
            file<<"Seat: "<<node->data.getSeatRow()<<" "<<node->data.getSeatColumn()<<" "<<convertSeatTypeToString(node->data.getType())<<" "<<"50000"<<" "<< "Available"<<endl;
        }
        
    }
    
    ///save show to File

}

void topBestSellingTicket(DoubleLinkedList<Booking> &bookingList, DoubleLinkedList<Movie> &movieList, int x, int y){
    
    double totalMoneyOfMovie[100]={0};  // Khởi tạo với giá trị 0
    int totalTicketOfMovie[100]={0};    // Khởi tạo với giá trị 0
    DoubleLinkedList<Movie> movies;                      // Vector để lưu trữ phim và thông tin tương ứng
    int movieCount = movieList.getSize();
    int bookingCount = bookingList.getSize();
    // Bước 1: Tính tổng doanh thu và số vé cho mỗi phim
    int index = 0;
    for(Node<Movie>* movieNode = movieList.begin(); movieNode != nullptr; movieNode = movieNode->next) {
        double currentRevenue = 0;
        int currentTickets = 0;

        // Tính tổng cho phim hiện tại
        for(Node<Booking>* bookingNode = bookingList.begin(); bookingNode != nullptr; bookingNode = bookingNode->next) {
            if(movieNode->data.getTitle() == bookingNode->data.getShow()->getMovie()->getTitle()) {
                currentRevenue += bookingNode->data.getTotalPrice();
                currentTickets += bookingNode->data.getSeats().getSize();
            }
        }
        
        totalMoneyOfMovie[index] = currentRevenue;
        totalTicketOfMovie[index] = currentTickets;
        movies.push_back(movieNode->data);
        index++;
    }
    // Bước 2: Sắp xếp theo doanh thu (sử dụng bubble sort)
    for(int i = 0; i < movieCount - 1; i++) {
        for(int j = 0; j < movieCount - i - 1; j++) {
            if(totalMoneyOfMovie[j] < totalMoneyOfMovie[j + 1]) {
                // Hoán đổi doanh thu
                swap(totalMoneyOfMovie[j], totalMoneyOfMovie[j + 1]);
                // Hoán đổi số vé
                swap(totalTicketOfMovie[j], totalTicketOfMovie[j + 1]);
                // Hoán đổi thông tin phim
                swap(movies[j], movies[j + 1]);
            }
        }
    }
    for(int i=0; i<index;i++){
        borderLineWithTextAndColor(x,y+i*3,"Tên phim: "+movies[i].getTitle(),BG_GRAY);
        borderLineWithTextAndColor(x+50,y+i*3,"Tổng vé đã bán: "+addSpaceToPrintMoney(totalTicketOfMovie[i]),BG_CYAN);
        borderLineWithTextAndColor(x+80,y+i*3,"Tổng doanh thu: "+addSpaceToPrintMoney(totalMoneyOfMovie[i]),BG_GREEN);
    }
}
string convertBookingTimeToSimple(string bookingTime){
    string result="";
    result+=bookingTime.substr(0,2)+"/"+bookingTime.substr(3,2)+"/"+bookingTime.substr(6,4);
    return result;
}
bool compareDate(string date1, string date2){
    if(stoi(date1.substr(6,4))>stoi(date2.substr(6,4))){
        return true;
    }
    else if(stoi(date1.substr(6,4))==stoi(date2.substr(6,4))){
        if(stoi(date1.substr(3,2))>stoi(date2.substr(3,2))){
            return true;
        }
        else if(stoi(date1.substr(3,2))==stoi(date2.substr(3,2))){
            if(stoi(date1.substr(0,2))>stoi(date2.substr(0,2))){
                return true;
            }
        }
    }
    return false;
}
void totalMoneyOf12MonthsInYear(DoubleLinkedList<Booking> bookingList, int x, int y){
    string dateStart="01/06/2024";
    string dateEnd="04/01/2025";
    int totalMoneyOf12Months[14]={0};
    int totalTicketOf12Months[14]={0};
    int i=0;
    for(Node<Booking>* node = bookingList.begin(); node != nullptr; node = node->next){
        if(compareDate(node->data.getShow()->getDate(),dateStart)==true && compareDate(node->data.getShow()->getDate(),dateEnd)==false){
            // cout<<"checkkkk"<<endl;
            int month=stoi(node->data.getShow()->getDate().substr(3,2));
            // cout<<"ono"<<month<<endl;
            if(month==1){
                totalMoneyOf12Months[12]+=node->data.getTotalPrice();
                totalTicketOf12Months[12]+=node->data.getSeats().getSize();
            }
            totalMoneyOf12Months[month-1]+=node->data.getTotalPrice();
            totalTicketOf12Months[month-1]+=node->data.getNumberOfSeats();
        }
    }
    for(int i=12;i>=8;i--){
        if(i==12){
            borderLineWithTextAndColor(x,y+i*3,"Tháng "+to_string(1)+"/2025",BG_CYAN);
            borderLineWithTextAndColor(x+50,y+i*3,"Tổng vé đã bán: "+to_string(totalTicketOf12Months[i]),BG_CYAN);
            borderLineWithTextAndColor(x+80,y+i*3,"Tổng doanh thu: "+addSpaceToPrintMoney(totalMoneyOf12Months[i]),BG_CYAN);
        }
        else{
            borderLineWithTextAndColor(x,y+i*3,"Tháng "+to_string(i+1)+"/2024",BG_CYAN);
            borderLineWithTextAndColor(x+50,y+i*3,"Tổng vé đã bán: "+to_string(totalTicketOf12Months[i]),BG_CYAN);
            borderLineWithTextAndColor(x+80,y+i*3,"Tổng doanh thu: "+addSpaceToPrintMoney(totalMoneyOf12Months[i]),BG_CYAN);
        }
    }
}
void totalMoneyOfWeek(DoubleLinkedList<Booking> bookingList,int month, int x, int y){
    // get monday and sunday of week in parameter month
    string pairMondayAndSunday[10];
    if(month==12){
        pairMondayAndSunday[0]="02/12/2024";
        pairMondayAndSunday[1]="08/12/2024";
        pairMondayAndSunday[2]="09/12/2024";
        pairMondayAndSunday[3]="15/12/2024";
        pairMondayAndSunday[4]="16/12/2024";
        pairMondayAndSunday[5]="22/12/2024";
        pairMondayAndSunday[6]="23/12/2024";
        pairMondayAndSunday[7]="29/12/2024";
    }
    else if (month==11){
        pairMondayAndSunday[0]="04/11/2024";
        pairMondayAndSunday[1]="10/11/2024";
        pairMondayAndSunday[2]="11/11/2024";
        pairMondayAndSunday[3]="17/11/2024";
        pairMondayAndSunday[4]="18/11/2024";
        pairMondayAndSunday[5]="24/11/2024";
        pairMondayAndSunday[6]="25/11/2024";
        pairMondayAndSunday[7]="01/12/2024";
    }
    else if (month==10){
        pairMondayAndSunday[0]="07/10/2024";
        pairMondayAndSunday[1]="13/10/2024";
        pairMondayAndSunday[2]="14/10/2024";
        pairMondayAndSunday[3]="20/10/2024";
        pairMondayAndSunday[4]="21/10/2024";
        pairMondayAndSunday[5]="27/10/2024";
        pairMondayAndSunday[6]="28/10/2024";
        pairMondayAndSunday[7]="03/11/2024";

    }
    else if( month==9){
        pairMondayAndSunday[0]="02/09/2024";
        pairMondayAndSunday[1]="08/09/2024";
        pairMondayAndSunday[2]="09/09/2024";
        pairMondayAndSunday[3]="15/09/2024";
        pairMondayAndSunday[4]="16/09/2024";
        pairMondayAndSunday[5]="22/09/2024";
        pairMondayAndSunday[6]="23/09/2024";
        pairMondayAndSunday[7]="29/09/2024";
    }
    int totalMoneyOfWeek[10]={0};
    int totalTicketOfWeek[10]={0};
    int i=0;
    for(Node<Booking>* node = bookingList.begin(); node != nullptr; node = node->next){
        if(compareDate(node->data.getShow()->getDate(), pairMondayAndSunday[0]) && !compareDate(node->data.getShow()->getDate(), pairMondayAndSunday[1])){
            totalMoneyOfWeek[0]+=node->data.getTotalPrice();
            totalTicketOfWeek[0]+=node->data.getSeats().getSize();
        }
        if(compareDate(node->data.getShow()->getDate(), pairMondayAndSunday[2]) && !compareDate(node->data.getShow()->getDate(), pairMondayAndSunday[3])){
            totalMoneyOfWeek[1]+=node->data.getTotalPrice();
            totalTicketOfWeek[1]+=node->data.getSeats().getSize();
        }
        if(compareDate(node->data.getShow()->getDate(), pairMondayAndSunday[4]) && !compareDate(node->data.getShow()->getDate(), pairMondayAndSunday[5])){
            totalMoneyOfWeek[2]+=node->data.getTotalPrice();
            totalTicketOfWeek[2]+=node->data.getSeats().getSize();
        }
        if(compareDate(node->data.getShow()->getDate(), pairMondayAndSunday[6]) && !compareDate(node->data.getShow()->getDate(), pairMondayAndSunday[7])){
            totalMoneyOfWeek[3]+=node->data.getTotalPrice();
            totalTicketOfWeek[3]+=node->data.getSeats().getSize();
        }
    }
    for(int i=0;i<4;i++){
        borderLineWithTextAndColor(x,y+i*3,"Tuần "+to_string(i+1) + " Tháng "+ to_string(month),BG_CYAN);
        borderLineWithTextAndColor(x+30,y+i*3,"Tổng vé đã bán: "+to_string(totalTicketOfWeek[i]),BG_CYAN);
        borderLineWithTextAndColor(x+50,y+i*3,"Tổng doanh thu: "+addSpaceToPrintMoney(totalMoneyOfWeek[i]),BG_CYAN);
    }
}
