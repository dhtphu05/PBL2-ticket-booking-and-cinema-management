#pragma once
#include "Screen.cpp"

#include<iostream>
using namespace std;
int main(){
    DoubleLinkedList<Screen> screens;
    Screen screen;
    screen.loadScreenFromFile(screens);
    screen.displayAllScreenSimpleLayout(screens);
    screen.addScreen(screens);
    screen.saveScreenToFile(screens);
    screen.displayAllScreenSimpleLayout(screens);
   
    // DoubleLinkedList<Show> shows;
    // Show show;
    // show.loadShowFromFile(shows);
    // show.displayAllShow(shows);
 
}

