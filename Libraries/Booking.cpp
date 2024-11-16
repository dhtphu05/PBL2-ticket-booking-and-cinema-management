#include "../Include/Booking.h"
#include "../Include/Movie.h"
#include "../Libraries/Show.cpp"
#include "../Libraries/Customer.cpp"
#include "../Libraries/Screen.cpp"
#include "../Libraries/User.cpp"
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
void Booking::sellTicket()
{   Movie movieInstance;
    Movie* movie= &movieInstance;
    movie->selectMovieToBooking();
    //cout<<movie->getCountry()<<endl;
    
    
    Show* show = new Show;
    show->selectShow(movie);

    cout<<"check"<<endl;
    //show->displaySeatStatus();
    cout<<"Enter the number of seats you want to book: ";
    int numberOfSeats;
    cin>>numberOfSeats;
    double totalPrice=0;
    for(int i=0;i<numberOfSeats;i++){
        cout<<"Enter the row and column of the seat you want to book: ";
        string inputSeat;
        cin>>inputSeat;
        string row = inputSeat.substr(0,1);
        int column = stoi(inputSeat.substr(1,1));
        cout<<row<<column<<endl;
        cout<<"hay noi 1 loi di huhuhu"<<endl;
        ShowSeat& seat = show->getSeatByRowColumn(row, column);
        seat.displaySeat();
        if(seat.getIsBooked()){
            cout<<"Seat is already booked."<<endl;
            i--;
        }
        else{
            seat.setIsBooked(true);

            totalPrice+=seat.getPrice();
        }
    }
    
    //calculate total price
    cout<<"Total price: "<<totalPrice<<endl;
    cout<<"Confirm booking? 1.Yes 2.No"<<endl;
    int opt;
    cin>>opt;
    if(opt==1){
        //save booking to file
        //update seat status
        //update booking list
        cout<<"Booking confirmed."<<endl;
    }
    else{
        cout<<"Booking cancelled."<<endl;
    }

    

}


