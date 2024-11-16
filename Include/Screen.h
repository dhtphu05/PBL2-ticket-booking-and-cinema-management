#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "Show.h"
#include "Seat.h"

class Seat;
class ShowSeat;
class Show;
class Screen{
    public:
    int ID_Screen;
    DoubleLinkedList<Seat> seatLayout;

    Screen();
    Screen(int ID_Screen, DoubleLinkedList<Seat> seatLayout);
    int getID_screen();
    DoubleLinkedList<Seat> getSeatLayout();
    void setID_Screen(int ID_screen);
    void updateSeatLayout(DoubleLinkedList<Seat> seatLayout);
    void loadScreenFromFile(DoubleLinkedList<Screen> &screens);
    void displayScreen();
    void displayAllScreen(DoubleLinkedList<Screen> &screens);
    void addScreen(DoubleLinkedList<Screen> &screens);
    void updateScreen(DoubleLinkedList<Screen> &screens);
    void deleteScreen(DoubleLinkedList<Screen> &screens);
    bool saveScreenToFile(DoubleLinkedList<Screen> screens);
    Screen selectScreen();
    void displayScreenSimpleLayout();
    void displayAllScreenSimpleLayout(DoubleLinkedList<Screen> &screens);
    Screen* selectScreen(int ID_screen);
    friend void printScreen(Screen* screen);
    

};
#endif