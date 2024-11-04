#include "../Include/Seat.h"

ostream& operator<<(std::ostream& os, const SeatType& type) {
    switch (type) {
        case SeatType::Regular:
            os << "Regular";
            break;
        case SeatType::VIP:
            os << "VIP";
            break;
        case SeatType::Disable:
            os << "Disabled";
            break;
        default:
            os << "Unknown";
            break;
    }
    return os;
}
Seat::Seat(string seatRow, int seatColumn,  SeatType type){
    this->seatRow=seatRow;
    this->seatColumn=seatColumn;
    this->type=type;
}
string Seat::getSeatRow(){
    return this->seatRow;
}
int Seat::getSeatColumn(){
    return this->seatColumn;
}
SeatType Seat::getType(){
    return this->type;
}
void Seat::setSeatRow(string seatRow){
    this->seatRow = seatRow;
}
void Seat::setSeatColumn(int seatColumn){
    this->seatColumn = seatColumn;
}
void Seat::setType(SeatType type){
    this->type = type;
}
void Seat::displaySeat() const {
    cout << "Seat Row: " << this->seatRow << endl;
    cout << "Seat Column: " << this->seatColumn << endl;
    cout << "Seat Type: " << this->type<< endl;
}
void Seat::loadSeatFromFile(){
    //load seat from file
}





//* ShowSeat

bool ShowSeat::getIsBooked(){
    return this->isBooked;
}

double ShowSeat::getPrice(){
    return this->price;
}
void ShowSeat::setIsBooked(bool isBooked){
    this->isBooked = isBooked;
}
void ShowSeat::setPrice(double price){
    this->price = price;
}

void ShowSeat::bookSeat(const string time){
    if(isBooked){
        cout << "Seat is already booked" << endl;
    }
    else{
        //update booking list
        //update seat status
        isBooked = true;
        timeBooked = time;
        cout<<"Seat booked successfully at "<< timeBooked <<endl;

    }
    //update booking list
    //update seat status
}
void ShowSeat::cancelSeat(){
    if(isBooked){
        
        isBooked = false;
        timeBooked = "";
        cout<<"Seat canceled successfully"<<endl;
    }
    else{
        cout << "Seat is not booked" << endl;
    }
    //update booking list
    //update seat status
}
void ShowSeat::displaySeat() const {
    Seat::displaySeat();
    cout << "Seat Status: " << (isBooked ? "Booked" : "Available") << endl;
}
string ShowSeat::convertSeatTypeToString(){
    switch (ShowSeat::getType()) {
        case SeatType::Regular:
            return "Regular";
        case SeatType::VIP:
            return "VIP";
        case SeatType::Disable:
            return "Disabled";
        default:
            return "Unknown";
    }
}
