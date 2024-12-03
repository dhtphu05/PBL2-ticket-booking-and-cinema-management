#include "Booking.cpp" 
#include "../Include/Payment.h"
#include "Payment.cpp"
#include "Combo.cpp"
#include "Coupon.cpp" 
// #include "layout-select-seat.cpp"
#define byte windows_byte
#include <windows.h>
#undef byte 
int getMouseClick(int &x_click, int &y_click);
int main()
{
    SetConsoleOutputCP(65001);

    int x_click, y_click;
    Booking booking;
    DoubleLinkedList<Booking> bookings;
    
    DoubleLinkedList<Screen> screens;
    DoubleLinkedList<Customer> customers;
    Customer customer;
    customer.readfromFile(customers);
    Customer* customerTest = &customers[3];
    booking.setCustomer(customerTest);
    // booking.getUser()->Display();
    // Replace with an existing function or add Display function to User class
    booking.setCustomer(customerTest);
    Screen screen;
    screen.loadScreenFromFile(screens); 
    DoubleLinkedList<Movie> movies; 
    Movie movie;
    movie.readFile(movies); 
    DoubleLinkedList<Show> shows;  
    Show show;
    show.loadShowFromFile(shows,screens);
    //!
    booking.sellTicket(shows,screens,movies);
    booking.loadBookingFromFile(bookings,customers);

    cout<<bookings.getSize()<<endl;
    cout<<bookings[0].getSeats().getSize()<<endl;

    cout<<bookings[0].getCustomer()->getUserName()<<endl;
    cout<<bookings[0].getShow()->getMovie()->getID_Movie()<<endl;

    cout<<bookings[1].getCustomer()->getFullName();
    cout<<bookings[2].getSeats().getSize();

    return 0;
    //!
    // gotoXY(0,0);
    // booking.setPayment(new CreditCardPayment());
    // booking.getPayment()->processPayment(&booking); 
    // Combo combo;
    // combo.processCombo(&booking);
    // int opt;
    // cin>>opt;
    // system("cls");
    // displayAllCombo(booking.getCombos());
    // Combo combo;
    // combo.processCombo(&booking); 
    // displayAllCombo(booking.getCombos());


    return 0;
    
    //d
   

}


int getMouseClick(int &x_click, int &y_click)
{   
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if(x_click <10 && y_click <10){
        return 1;
    }
    else{
        return 0;
    }
}
