#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "../Template/DoubleLinkedList.h"
#include "../Libraries/Show.cpp"
using namespace std;

class Screen{
    private:
    string ID_Screen;
    int totalSeats;
    DoubleLinkedList<Show> shows;

    public:
    Screen();
    Screen(string ID_Screen, int totalSeats, DoubleLinkedList<Show> shows);
    //getter
    string getID_Screen();
    int getTotalSeats();
    DoubleLinkedList<Show> getShows();
    //setter
    void setID_Screen(string ID_Screen);
    void setTotalSeats(int totalSeats);
    void setShows(DoubleLinkedList<Show> shows);
    //method
    void addScreen();
    void editScreen();
    void deleteScreen();
    void searchScreen();
    void showScreen();
    void getScreen();
    void displayScreen();
    ~Screen();
    void addShow();
    void updateShow();
    void deleteShow();
    void displayAllShow();
    

};