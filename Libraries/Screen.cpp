#include "../include/Screen.h"

Screen::Screen(string ID_Screen, int totalSeats, DoubleLinkedList<Show> shows){
    this->ID_Screen = ID_Screen;
    this->totalSeats = totalSeats;
    this->shows = shows;
}
void Screen::getID_Screen(){
    return this->ID_Screen;
}
void Screen::getTotalSeats(){
    return this->totalSeats;
}
void Screen::getShows(){
    return this->shows;
}
void Screen::setID_Screen(string ID_Screen){
    this->ID_Screen = ID_Screen;
}
void Screen::setTotalSeats(int totalSeats){
    this->totalSeats = totalSeats;
}
void Screen::setShows(DoubleLinkedList<Show> shows){
    this->shows = shows;
}
void Screen::addScreen(){
    cout << "Enter ID Screen: ";
    cin >> this->ID_Screen;
    cout << "Enter total seats: ";
    cin >> this->totalSeats;
}

