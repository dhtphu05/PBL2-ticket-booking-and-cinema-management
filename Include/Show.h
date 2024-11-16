
#ifndef SHOW_H
#define SHOW_H
#pragma once
#include <iostream>

#include "Seat.h"

#include "Movie.h"
#include <fstream>
#include <sstream>

class Screen;
class ShowSeat;
using namespace std;
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
    Show(string ID_Show, string date, string startTime,string endTime, Movie* movie, DoubleLinkedList<ShowSeat> seatLayout, Screen* screen);
    //getter
    string getID_Show();
    string getStartTime();
    Movie* getMovie();
    DoubleLinkedList<ShowSeat> getSeats();
    ShowSeat& getSeat(int index);
    Screen* getScreen();
    string getEndTime();
    string getDate();

    //setter
    void setID_Show(string ID_Show);
    void setStartTime(string startTime);
    void setMovie(Movie* movie);
    void setSeats(DoubleLinkedList<ShowSeat> seats);
    void setScreen(Screen* screen);
    void setEndTime(string endTime);
    void setDate(string date);
    void setShow(Show show);
    //method
    void loadShowFromFile(DoubleLinkedList<Show> &shows);
    void calculateEndTime();
    static void displayAllShow(const DoubleLinkedList<Show> &shows);//da co
    void addShow();
    void updateShow();
    static void deleteShow(DoubleLinkedList<Show> &shows);
    void displayShow();
    void displaySeatStatus();//da co //hien thi tat ca cac ghe trong phong chieu   
    void addBooking();
    string getShow();
    bool saveShowToFile(DoubleLinkedList<Show> shows);
    static bool overwriteFile(DoubleLinkedList<Show> shows);
    void selectShow(Movie* movie);
    void displayAllSimpleShow(DoubleLinkedList<Show> &shows);
    Show getShowByID(string ID);
    Show& operator=(Show &show);
    ShowSeat& getSeatByRowColumn(string row, int column);
    
    // Destructor
    ~Show();

};

#endif // SHOW_H