
#include "Booking.cpp"

#define byte windows_byte

#include <windows.h>
#undef byte

int main(){
    SetConsoleOutputCP(65001);
    cout<<"██"<<endl;
    cout<<"xin chào các bạn trẻ mình là thiên phú";
    Booking booking;
    DoubleLinkedList<Screen> screens;
    Screen screen;
    screen.loadScreenFromFile(screens);
    DoubleLinkedList<Movie> movies;
    Movie movie;
    movie.readFile(movies); 
    DoubleLinkedList<Show> shows;
    Show show;
    show.loadShowFromFile(shows,screens);
    show.displayAllShow(shows);
    booking.sellTicket(shows,screens,movies);


    // DoubleLinkedList<Screen> screens;
    // Screen screen;
    // screen.loadScreenFromFile(screens);
    // screen.displayAllScreenSimpleLayout(screens);
    // screen.addScreen(screens);
    // screen.saveScreenToFile(screens);
    // screen.displayAllScreenSimpleLayout(screens);
    
    // DoubleLinkedList<Show> shows;
    // Show show;
    // show.loadShowFromFile(shows);
    // show.displayAllShow(shows);

}