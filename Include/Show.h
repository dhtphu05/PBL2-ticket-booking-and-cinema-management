
#include <iostream>
#include <string>
#include <math.h>
#include "../Template/DoubleLinkedList.h"
#include "Seat.h"
#include "Screen.h"
#include "Movie.h"
#include <fstream>
using namespace std;
#ifndef SHOW_H
#define SHOW_H
class Show{
    private:
    string ID_Show;
    string startTime;
//endtime = start + duration of movie
    string endTime;
    string date;
    Movie* movie;
    DoubleLinkedList<ShowSeat> seats;
    Screen* screen;
//list booking 
    public:
    Show();
    Show(string ID_Show, string date, string startTime,string endTime="", Movie* movie, DoubleLinkedList<ShowSeat> seatLayout, Screen* screen);
    //getter
    string getID_Show();
    string getStartTime();
    Movie* getMovie();
    DoubleLinkedList<ShowSeat> getSeats();
    Screen getScreen();
    string getEndTime();
    string getDate();
    //setter
    void setID_Show(string ID_Show);
    void setStartTime(string startTime);
    void setMovie(Movie* movie);
    void setSeats(DoubleLinkedList<ShowSeat> seats);
    void setScreen(Screen screen);
    void setEndTime(string endTime);
    void setDate(string date);
    //method
    void calculateEndTime();
    void displayShow();//da co
    void addShow();
    void updateShow();
    void deleteShow();
    void displayAllShow();
    void displaySeatStatus();//da co //hien thi tat ca cac ghe trong phong chieu   
    void addBooking();

    void bookedSeat(string seatRow, int seatColumn);
    void cancelBooked(string seatRow, int seatColumn);
    void displayShowInfo();
    
    void saveShowToFile(string fileName);
    
    // Destructor
    ~Show();

};

#endif // SHOW_H