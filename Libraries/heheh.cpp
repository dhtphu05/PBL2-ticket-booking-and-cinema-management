#include "Show.cpp"

DoubleLinkedList<Show> loadShowFromFile(string fileName){
    ifstream file(fileName);
    string line;
    DoubleLinkedList<Show> shows;
    Show* currentShow = nullptr;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string key;

        if (line.rfind("ShowID:", 0) == 0) {
            if (currentShow != nullptr) {  // Add the current show to the list before creating a new one
                shows.push_back(*currentShow);
            }
            currentShow = new Show();
            currentShow->getID_Show() = line.substr(8);
        } else if (line.rfind("Date:", 0) == 0) {
            currentShow->getDate() = line.substr(6);
        } else if (line.rfind("StartTime:", 0) == 0) {
            currentShow->getStartTime() = line.substr(11);
        } else if (line.rfind("EndTime:", 0) == 0) {
            currentShow->getEndTime() = line.substr(9);
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

    return shows;
}
void saveShowToFile(DoubleLinkedList<Show> shows, string fileName){
    ofstream file(fileName);
    Node<Show> *current = shows.begin();
    while(current!=nullptr){
        file << "ShowID: " << current->data.getID_Show() << endl;
        file << "Date: " << current->data.getDate() << endl;
        file << "StartTime: " << current->data.getStartTime() << endl;
        file << "EndTime: " << current->data.getEndTime() << endl;
        //file << "Screen: " << current->data.getScreen().getID_Screen() << endl;
        Node<ShowSeat> *currentSeat = current->data.getSeats().begin();
        while(currentSeat!=nullptr){
            file << "Seat: " << currentSeat->data.getSeatRow() << " " << currentSeat->data.getSeatColumn() << " " << currentSeat->data.convertSeatTypeToString()<< " " << currentSeat->data.getPrice() << " " << currentSeat->data.getIsBooked() << endl;
            currentSeat = currentSeat->next;
        }
        current = current->next;
    }
}

int main(){
    DoubleLinkedList<Show> shows = loadShowFromFile("..Databases/Show.txt");
    saveShowToFile(shows, "showw.txt");
    return 0;
}