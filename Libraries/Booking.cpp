#include "../Include/Booking.h"
#include "../Include/Movie.h"
#include "../Libraries/Show.cpp"
#include "../Libraries/Customer.cpp"
#include "../Libraries/Screen.cpp"
#include "../Libraries/User.cpp"
#include <time.h>
class Show;
class Screen;
class ShowSeat;
Booking::Booking()
{
    this->bookingNumber = "";
    this->numberOfSeats = 0;
    this->bookingTime = "";
    this->customer = nullptr;
    this->show = nullptr;
    this->totalPrice = 0;
}
Booking::Booking(string bookingNumber, int numberOfSeats, string bookingTime, Customer *customer, Show *show, DoubleLinkedList<ShowSeat> seats, double totalPrice)
    : bookingNumber(bookingNumber), numberOfSeats(numberOfSeats), bookingTime(bookingTime), customer(customer), show(show), seats(seats), totalPrice(totalPrice)
{
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
Customer *Booking::getCustomer()
{
    return this->customer;
}
Show *Booking::getShow()
{
    return this->show;
}
DoubleLinkedList<ShowSeat> Booking::getSeats()
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
void Booking::setCustomer(Customer *customer)
{
    this->customer = customer;
}
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
void Booking::sellTicket(DoubleLinkedList<Show>& shows,DoubleLinkedList<Screen> &screens,DoubleLinkedList<Movie> &movies)
{   Movie movieInstance;
    Movie* movie= &movieInstance;
    movie->selectMovieToBooking(movies);
    //cout<<movie->getCountry()<<endl;
    Show showInstance;
    Show* show = new Show;
    show->selectShow(movie, screens);
    
    //show->displaySeatStatus();
    cout<<"Enter the number of seats you want to book: ";
    int numberOfSeats;
    cin>>numberOfSeats;
    string row;
    int column;
    double totalPrice=0;
    // showInstance.displayAllShow(shows);

    for(int i=0;i<numberOfSeats;i++){
        displayAllSeatToBook(show);
        cout<<"Enter the row and column of the seat you want to book: ";
        string inputSeat;
        cin>>inputSeat;
        row = inputSeat.substr(0,1);
        column = stoi(inputSeat.substr(1,1));
        cout<<row<<column<<endl;
        
        // ShowSeat& seat = show->getSeatByRowColumn(row, column);
        // seat.displaySeat();
        if(show->getSeatByRowColumn(row,column).getIsBooked()){
            cout<<"Seat is already booked."<<endl;
            i--;
        }
        else{
            // seat.setIsBooked(true);
            show->setSeatStatus(row, column, true);
            editSeatStatusInFile(show,shows,show->getID_Show(),row,column,true);
            this->seats.push_back(show->getSeatByRowColumn(row,column));
            //time_t t = time(0);

            totalPrice+=show->getSeatByRowColumn(row,column).getPrice();
        }
    }
    //calculate total price
    cout<<"Total price: "<<totalPrice<<endl;
    cout<<"Confirm booking? 1.Yes 2.No"<<endl;
    int opt;
    cin>>opt;
    if(opt==1){
        //save booking to file
        //edit in file
        //showInstance.displayAllShow(shows);
        //editSeatStatusInFile(show,shows,show->getID_Show(),row,column,true);
        //* chưa xử lý 2 ghế, cái ni mới dùng đc 1 ghế chơ mấy.
        //* oke mai xu ly cai vu show chui vo chung 1 lan 
        //update seat status
        //update booking list
        cout<<"Booking confirmed."<<endl;
        this->setShow(show);
        this->setNumberOfSeats(numberOfSeats);
        this->setTotalPrice(totalPrice);
        this->getRandomBookingNumber();
        cout<<"Booking number: "<<this->getBookingNumber()<<endl;
        this->getShow()->displayShow();
        cout<<"Number of seats: "<<this->getNumberOfSeats()<<endl;
        cout<<"Seat: "<<endl;
        cout<<"Row Column Type Price Status"<<endl;
        cout<<"--------------------------------"<<endl;
        for(Node<ShowSeat>* node = this->seats.begin(); node != nullptr; node = node->next){
            node->data.displaySeat();
        }
        cout<<"Total Price: "<<this->getTotalPrice();
        //displayAllSeatToBook(show);
    }
    else{
        cout<<"Booking cancelled."<<endl;
    }
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


