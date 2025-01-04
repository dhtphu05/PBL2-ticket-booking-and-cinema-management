#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "../Template/DoubleLinkedList.h"
#include <fstream>
#include <sstream>
#include "Screen.h"
using namespace std;

class Screen;
enum class SeatType{
    VIP,
    Regular,
    Couple,
    Disable
};

class Seat{
    string seatRow;
    int seatColumn;
    SeatType type;

    public:
    Seat(){
        this->seatRow="";
        this->seatColumn=0;
        this->type=SeatType::Regular;
    }
    Seat(string seatRow, int seatColumn,  SeatType type); 
    string getSeatRow();
    int getSeatColumn();
    SeatType getType();

    void setSeatRow(string seatRow);
    void setSeatColumn(int seatColumn);
    void setType(SeatType type);

    virtual void displaySeat() ;
    void loadSeatFromFile();
    string convertSeatTypeToString();

};

class ShowSeat: public Seat{
    private:
    bool isBooked;
    double price;
    string timeBooked;
    //promotioncode
    public:
    ShowSeat(){
        this->isBooked = false;
        this->price = 0.0;
        this->timeBooked = "";

    }
    ShowSeat(string seatRow, int seatColumn, SeatType type, bool isBooked, double price, string timeBooked): Seat(seatRow, seatColumn, type){
        this->isBooked = isBooked;
        this->price = price;
        this->timeBooked = timeBooked;
    }
    bool getIsBooked();
    string getTimeBooked();
    int getSeatNumber();
    double getPrice();
    void setIsBooked(bool isBooked);
    void setPrice(double price);
    void setTimeBooked(string timeBooked);
    string convertSeatTypeToString();

    //method
    void bookSeat(const string time="");
    void cancelSeat();
    void displaySeat()  override;
    string convertSeatTypeToSimpleString();
    bool operator==(ShowSeat& seat) ;

};
