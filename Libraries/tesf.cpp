
#include "Booking.cpp"


int main(){
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