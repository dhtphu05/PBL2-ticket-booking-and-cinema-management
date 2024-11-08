#include "../Include/Screen.h"
#include "../Include/Show.h"

using namespace std;
Show::Show(std::string ID_Show, std::string date, std::string startTime, std::string endTime, Movie* movie, DoubleLinkedList<ShowSeat> seatLayout, Screen* screen)
    : ID_Show(ID_Show), date(date), startTime(startTime), endTime(endTime), movie(movie), screen(screen) {
    this->calculateEndTime();
    for (Node<ShowSeat>* node = seatLayout.begin(); node != nullptr; node = node->next) {
        ShowSeat seat = node->data;
        ShowSeat newSeat(seat.getSeatRow(), seat.getSeatColumn(), seat.getType(), seat.getIsBooked(), seat.getPrice(), seat.getTimeBooked());
        this->seats.push_back(newSeat);
    }
}
Show::Show(){
    this->ID_Show = "";
    this->date = "";
    this->startTime = "";
    this->endTime = "";
    this->movie = nullptr;
    this->screen = nullptr;
    
}
string Show::getID_Show(){
    return this->ID_Show;
}
string Show::getDate(){
    return this->date;
}
string Show::getEndTime(){
    return this->endTime;
}

string Show::getStartTime(){
    return this->startTime;
}
// Movie* Show::getMovie(){
//     return this->movie;
// }
// string Show::getEndTime(){
//     return this->endTime;
// }
DoubleLinkedList<ShowSeat> Show::getSeats(){
    return this->seats;
}
// Screen Show::getScreen(){
//     return this->screen;
// }
void Show::setID_Show(string ID_Show){
    this->ID_Show = ID_Show;
}
void Show::setDate(string date){
    this->date = date;
}
void Show::setEndTime(string endTime){
    this->endTime = endTime;
}
void Show::setStartTime(string startTime){
    this->startTime = startTime;
}
void Show::setMovie(Movie* movie){
    this->movie = movie;
}
void Show::setSeats(DoubleLinkedList<ShowSeat> seats){
    this->seats = seats;
}
// void Show::setScreen(Screen screen){
//     this->screen = screen;
// }
void Show::calculateEndTime(){
    //convert string to int
    int duration = stoi(this->movie->getDuration());
    //convert 17:30 to 17*60+30
    int start = stoi(this->startTime.substr(0,2))*60 + stoi(this->startTime.substr(3,2));
    //convert 17*60+30 + duration
    int end = start + duration;
    //convert 105 to 1:45
    int hour = end/60;
    int minute = end%60;
    this->endTime = to_string(hour) + ":" + to_string(minute);
}

// void Show::addShow(){
//     cout << "Enter ID Show: ";
//     cin >> this->ID_Show;
//     cout << "Enter Date: ";
//     cin >> this->date;
//     cout << "Enter Start Time: ";
//     cin >> this->startTime;
    
//     movie=Movie::selectMovie();
//     screen=Screen::selectScreen();
//     if(!savetoFile()){
//         cout<<"Failed to save show to file."<<endl;
//     }
//     // cout << "Enter Movie: ";
//     // cin >> this->movie;
//     // cout << "Enter Screen: ";
//     // cin >> this->screen;
// }
// void displayAllShow(){
//     Node<Show> *current = this->shows.begin();
//     while(current!=nullptr){
//         current->data.displayShow();
//         current = current->next;
//     }
// }
void Show::displaySeatStatus(){
    Node<ShowSeat> *current = this->seats.begin();
    while(current!=nullptr){
        current->data.displaySeat();
        current = current->next;
    }
}
void Show::displayShow(){
    cout << "ID Show: " << this->ID_Show << endl;
    cout << "Date: " << this->date << endl;
    cout << "Start Time: " << this->startTime << endl;
    cout << "End Time: " << this->endTime << endl;
    cout << "Movie: " << this->movie->getTitle() << endl;
    if(this->screen!=nullptr)
        cout << "Screen: " << this->screen->getID_screen() << endl;
    else cout << "Screen: " << "NULL" << endl;
}
void Show::displayAllShow(const DoubleLinkedList<Show> &shows){
    Node<Show> *current = shows.begin();
    while(current!=nullptr){
        current->data.displayShow();
        current = current->next;
    }
}
//write a function to load show from file and return a list of show, format of file is as follows: Databases/Show.txt
void Show::loadShowFromFile(DoubleLinkedList<Show> &shows){
    ifstream file("../Databases/Show.txt");
    string line;
    Show* currentShow = nullptr;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string key;
        if (line.rfind("ShowID:", 0) == 0) {
            if (currentShow != nullptr) {  // Add the current show to the list before creating a new one
                shows.push_back(*currentShow);
            }
            currentShow = new Show();
            currentShow->setID_Show(line.substr(8));
        } else if (line.rfind("Date:", 0) == 0) {
            currentShow->setDate(line.substr(6));
        } else if (line.rfind("StartTime:", 0) == 0) {
            currentShow->setStartTime(line.substr(11));
        } else if (line.rfind("EndTime:", 0) == 0) {
            currentShow->setEndTime(line.substr(9));
        } else if (line.rfind("Screen:", 0) == 0) {
            // currentShow->Screen.getID_Screen = line.substr(12);
        } else if (line.rfind("Seat:", 0) == 0) {
            ShowSeat seat;
            std::string status;
            seat.setIsBooked(false);
            std::string seatRow, seatType;
            int seatColumn;
            double seatPrice;
            bool isBooked;
            ss >> key >> seatRow >> seatColumn >> seatType >> seatPrice >> isBooked;
            seat.setSeatRow(seatRow);
            seat.setSeatColumn(seatColumn);
            if (seatType == "VIP") {
                seat.setType(SeatType::VIP);
            } else if (seatType == "Regular") {
                seat.setType(SeatType::Regular);
            } 
            seat.setPrice(seatPrice);
            seat.setIsBooked(isBooked);
            seat.setIsBooked(seat.getIsBooked() == true);
            currentShow->getSeats().push_back(seat);
        }
    }
    // Add the last show if there's one pending
    if (currentShow != nullptr) {
        shows.push_back(*currentShow);
    }
}
bool Show::saveShowToFile(DoubleLinkedList<Show> shows){
    ofstream file("../Databases/Show.txt");
    Node<Show> *current=shows.begin();
    int count=0;
    while(current!=nullptr){
        if(count!=0){
            file<< "#NextShow" << endl;
        }
        file << "ShowID: " << current->data.getID_Show() << endl;
        file << "Date: " << current->data.getDate() << endl;
        file << "StartTime: " << current->data.getStartTime() << endl;
        file << "EndTime: " << current->data.getEndTime() << endl;
        //file << "Screen: " << current->data.getScreen().getID_Screen() << endl;

        Node<ShowSeat> *currentSeat = current->data.getSeats().begin();
        file<< "#Seats" << endl;
        while(currentSeat!=nullptr){
            file << "Seat: " << currentSeat->data.getSeatRow() << " " << currentSeat->data.getSeatColumn() << " " << currentSeat->data.convertSeatTypeToString()<< " " << currentSeat->data.getPrice() << " " << currentSeat->data.getIsBooked() << endl;
            currentSeat = currentSeat->next;
        }
        current = current->next;
    }
    return true;

}


// void saveShowToFile(DoubleLinkedList<Show> shows, string fileName){
//     ofstream file(fileName);
//     Node<Show> *current = shows.begin();
//     while(current!=nullptr){
//         file << "ShowID: " << current->data.getID_Show() << endl;
//         file << "Date: " << current->data.getDate() << endl;
//         file << "StartTime: " << current->data.getStartTime() << endl;
//         file << "EndTime: " << current->data.getEndTime() << endl;
//         //file << "Screen: " << current->data.getScreen().getID_Screen() << endl;
//         Node<ShowSeat> *currentSeat = current->data.getSeats().begin();
//         while(currentSeat!=nullptr){
//             file << "Seat: " << currentSeat->data.getSeatRow() << " " << currentSeat->data.getSeatColumn() << " " << currentSeat->data.convertSeatTypeToString()<< " " << currentSeat->data.getPrice() << " " << currentSeat->data.getIsBooked() << endl;
//             currentSeat = currentSeat->next;
//         }
//         current = current->next;
//     }
// }
