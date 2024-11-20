#include "../Include/Screen.h"
#include "../Include/Show.h"
#include "../Include/Movie.h"
#include "../Libraries/Movie.cpp"

#define green "\e[38:5:2m"
#define red "\e[38:5:1m"
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
Show::~Show(){
    //delete movie;
    //delete screen;
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
Movie* Show::getMovie(){
    return this->movie;
}
DoubleLinkedList<ShowSeat>& Show::getSeats(){
    return this->seats;
}
// string Show::getEndTime(){
//     return this->endTime;
// }

ShowSeat& Show::getSeat(int index){
    Node<ShowSeat> *current = this->seats.begin();
    for(int i=0;i<index;i++){
        current = current->next;
    }
    return current->data;
}
Screen* Show::getScreen(){
    return this->screen;
}
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
void Show::setScreen(Screen* screen){
    this->screen = screen;
}
void Show::setSeats(DoubleLinkedList<ShowSeat> seats){
    Node<ShowSeat> *current = seats.begin();
    while(current!=nullptr){
        this->seats.push_back(current->data);
        current = current->next;
    }   
}
//?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
// void Show::addShow(){
//     Movie movieInstance;
//     movie = new Movie(movieInstance.selectMovie());
//     cout<<"Enter start time: ";
//     cin>>startTime;
//     cout<<"Enter date: ";
//     cin>>date;
//     Screen screenInstance;
//     screen = new Screen(screenInstance.selectScreen());
//     cout<<"Enter the layout of the screen: "<<endl;
    

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
    cout<<"huhuhuhuh"<<endl;
    while(current!=nullptr){
        current->data.displaySeat();
        current = current->next;
    }
}
void Show::displayShow(){
    cout<<"#Show Details"<<endl;
    cout << "ID Show: " << this->ID_Show << endl;
    cout << "Date: " << this->date << endl;
    cout << "Start Time: " << this->startTime << endl;
    cout << "End Time: " << this->endTime << endl;
    cout << "Movie: ";
    printMovie(this->movie);
    cout<<endl;
    if(this->screen!=nullptr){
        cout << "Screen: ";
        printScreen(this->screen);
    }
    else cout << "Screen: " << "NULL" << endl;
    cout<<"# Seat List"<<endl;
    displaySeatStatus();
    cout<<endl;
    cout<<"-----------------------------------"<<endl;


}
void Show::displayAllShow(const DoubleLinkedList<Show> &shows){
    Node<Show> *current = shows.begin();
    while(current!=nullptr){
        current->data.displayShow();
        current = current->next;
    }
}
//write a function to load show from file and return a list of show, format of file is as follows: Databases/Show.txt
void Show::loadShowFromFile(DoubleLinkedList<Show> &shows, DoubleLinkedList<Screen> &screens){
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
                 int screenID = stoi(line.substr(8));
            // Tìm `Screen` trong danh sách `screens` bằng `selectScreen`
            Screen screenLoader;
            Screen* selectedScreen = screenLoader.selectScreen(screens, screenID);
            if (selectedScreen != nullptr) {
                currentShow->setScreen(selectedScreen); // Gán Screen vào Show
            } else {
                cout << "Error: Screen with ID " << screenID << " not found!" << endl;
            }
        }else if(line.rfind("Movie:", 0) == 0){
            int movieID = stoi(line.substr(7));
            Movie* movieInstance = new Movie();
            *movieInstance = *movieInstance->selectMovie(movieID);
            currentShow->setMovie(movieInstance);
            //cout<<"done read movie"<<endl;
        }
         else if (line.rfind("# SeatList", 0) == 0) {
            string line, key;
            ShowSeat seat;
            int rowIdx=0;
            
                //Seat: B 2 Regular 10.0 Available
                while(getline(file,line) && !line.empty() && rowIdx<100){
                    istringstream layoutStream(line);
                    //cout<<line<<endl;
                    string seatRow;
                    int seatColumn;
                    string seatTypeStr;
                    float price;
                    string isBookedStr;
                    bool isBooked;
                    layoutStream >> key >> seatRow >> seatColumn >> seatTypeStr >> price >> isBookedStr;
                    isBooked = isBookedStr == "Booked";
                    seat.setSeatRow(seatRow);
                    seat.setSeatColumn(seatColumn);
                    if(seatTypeStr=="Regular"){
                        seat.setType(SeatType::Regular);
                    } else if(seatTypeStr=="VIP"){
                        seat.setType(SeatType::VIP);
                    } else if(seatTypeStr=="Disable"){
                        seat.setType(SeatType::Disable);
                    }
                    seat.setPrice(price);
                    seat.setIsBooked(isBooked);
                    currentShow->seats.push_back(seat);
                }

            
        }
    }
    // Add the last show if there's one pending
    if (currentShow != nullptr) {
        shows.push_back(*currentShow);
    }
}
bool Show::saveShowToFile(DoubleLinkedList<Show> shows){
    ofstream file("../Databases/Show.txt");
    Node<Show> *current = shows.begin();
    while(current!=nullptr){
        file << "ShowID: " << current->data.getID_Show() << endl;
        file << "Date: " << current->data.getDate() << endl;
        file << "StartTime: " << current->data.getStartTime() << endl;
        file << "EndTime: " << current->data.getEndTime() << endl;
        if(current->data.getScreen()!=nullptr){
            file << "Screen: " << current->data.getScreen()<< endl;
        }
        else file << "Screen: " << "NULL" << endl;
        file << "Movie: " << current->data.getMovie()->getID_Movie() << endl;
        Node<ShowSeat> *currentSeat = current->data.getSeats().begin();
        while(currentSeat!=nullptr){
            file << "Seat: " << currentSeat->data.getSeatRow() << " " << currentSeat->data.getSeatColumn() << " " << currentSeat->data.convertSeatTypeToString()<< " " << currentSeat->data.getPrice() << " " << currentSeat->data.getIsBooked() << endl;
            currentSeat = currentSeat->next;
        }
        current = current->next;
    }
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
//* bỏ thêm cái & ở show để test
void Show::displayAllSimpleShow(DoubleLinkedList<Show> &shows){
    Node<Show> *current = shows.begin();
    while(current!=nullptr){
        cout << "ID Show: " << current->data.getID_Show() << endl;
        cout << "Date: " << current->data.getDate() << endl;
        cout << "Start Time: " << current->data.getStartTime() << endl;
        cout << "End Time: " << current->data.getEndTime() << endl;
        cout << "Movie: ";
        printMovie(current->data.getMovie());
        if(current->data.getScreen()!=nullptr){
            cout << "Screen: ";
            printScreen(current->data.getScreen());
        }
        else cout << "Screen: " << "NULL" << endl;
        cout<<"-----------------------------------"<<endl;
        current = current->next;
    }
}
void Show::displayAllSimpleShowFollowMovie(DoubleLinkedList<Show> &shows, Movie* movie){
    Node<Show> *current = shows.begin();
    while(current!=nullptr){
        if(current->data.getMovie()->getID_Movie()==movie->getID_Movie()){
            cout << "ID Show: " << current->data.getID_Show() << endl;
            cout << "Date: " << current->data.getDate() << endl;
            cout << "Start Time: " << current->data.getStartTime() << endl;
            cout << "End Time: " << current->data.getEndTime() << endl;
            cout << "Movie: ";
            printMovie(current->data.getMovie());
            if(current->data.getScreen()!=nullptr){
                cout << "Screen: ";
                printScreen(current->data.getScreen());
            }
            else cout << "Screen: " << "NULL" << endl;
            cout<<"-----------------------------------"<<endl;
        }
        current = current->next;
    }
}
void Show::selectShow(Movie* movie, DoubleLinkedList<Screen> &screens){
    DoubleLinkedList <Show> showList;
    this->loadShowFromFile(showList, screens);
    // this->displayAllSimpleShow(showList);
    this->displayAllSimpleShowFollowMovie(showList, movie);
    cin.ignore();
    cout<<"Enter the ID of the show you want to select: ";
    string ID;
    getline(cin,ID);
    for(int i=0;i<showList.getSize();i++){
        
        string showID = showList[i].getID_Show();
       
        if(showID==ID){
            cout<<"wft"<<endl;
            *this = showList[i];
            cout<<"heeee"<<endl;
            cout<<"Show selected: "<<this->getID_Show()<<endl;
            return;
        }
    }
    cout<<"Show not found."<<endl;
}

Show Show::getShowByID(string ID){
    DoubleLinkedList<Show> showList;
    //this->loadShowFromFile(showList);
    for(int i=0;i<showList.getSize();i++){
        if(showList[i].getID_Show()==ID){
            return showList[i];
        }
    }
    return Show();
}
void Show::setShow(Show show){
    *this = show;
    cout<<"hehehhehehheheee";
}
Show& Show::operator=(Show &show){
    if (this != &show) {
        this->setID_Show(show.getID_Show());
        this->setDate(show.getDate());
        this->setStartTime(show.getStartTime());
        this->setEndTime(show.getEndTime());
        this->setMovie(show.getMovie());
        this->setScreen(show.getScreen());
        Node<ShowSeat>* current = show.seats.begin();  // Lặp qua danh sách ghế của đối tượng `other`
        while (current != nullptr) {
            this->seats.push_back(current->data);  // Giả sử có phương thức `append` trong DoubleLinkedList
            current = current->next;
        }
    }
    return *this;
}
ShowSeat& Show::getSeatByRowColumn(string row, int column){
    Node<ShowSeat> *current = this->seats.begin();
    current->data.displaySeat();
    int i=0;
    while(current!=nullptr){
        cout<<"checkpoint huhuhu"<<++i<<endl;
        if(current->data.getSeatRow()==row && current->data.getSeatColumn()==column){
            return current->data;
        }
        current = current->next;
    }
    throw runtime_error("Seat not found.");
}
void Show::setSeatStatus(string row, int column, bool status){
    Node<ShowSeat> *current = this->seats.begin();
    while(current!=nullptr){
        if(current->data.getSeatRow()==row && current->data.getSeatColumn()==column){
            current->data.setIsBooked(status);
            return;
        }
        current = current->next;
    }
    throw runtime_error("Seat not found.");
}
void editSeatStatusInFile(Show* show, DoubleLinkedList<Show>&shows, string ID, std::string row, int column, bool status){
    Show showInstance;
    //showInstance.displayAllShow(shows);
    ofstream file("../Databases/Show.txt");
    
    
   // showInstance.displayAllSimpleShow(shows);
    Node<Show> *current = shows.begin();
    while(current!=nullptr){
        file<<"# Show Details"<<endl;
        file << "ShowID: " << current->data.getID_Show() << endl;
        file << "Date: " << current->data.getDate() << endl;
        file << "StartTime: " << current->data.getStartTime() << endl;
        file << "EndTime: " << current->data.getEndTime() << endl;
        if(current->data.getScreen()!=nullptr){
            file << "Screen: " << current->data.getScreen()->getID_screen()<< endl;
        }
        else file << "Screen: " << "NULL" << endl;
        file << "Movie: " << current->data.getMovie()->getID_Movie() << endl;
        file<< "# SeatList"<<endl;
        Node<ShowSeat> *currentSeat = current->data.getSeats().begin();
        //cout<<currentSeat->data.getSeatRow()<<currentSeat->data.getSeatColumn()<<currentSeat->data.getPrice()<<currentSeat->data.getIsBooked()<<endl;
        //currentSeat->data.displaySeat();
        // return;
        while(currentSeat!=nullptr){
            //currentSeat->data.displaySeat();
        //cout<<currentSeat->data.getSeatRow()<<currentSeat->data.getSeatColumn()<<currentSeat->data.getPrice()<<currentSeat->data.getIsBooked()<<endl;

            if(current->data.getID_Show()==ID && currentSeat->data.getSeatRow()==row && currentSeat->data.getSeatColumn()==column){
                currentSeat->data.setIsBooked(status);
            }
            file << "Seat: " << currentSeat->data.getSeatRow() << " " << currentSeat->data.getSeatColumn() << " " << currentSeat->data.convertSeatTypeToString() << " " << currentSeat->data.getPrice() << " " << (currentSeat->data.getIsBooked() ? "Booked" : "Available") << endl;
            currentSeat = currentSeat->next;
        }
        file<<endl;
        current = current->next;
    }
    
}
void displayAllSeatToBook(Show *show){
    Node<ShowSeat> *current = show->getSeats().begin();
    int colIdx = 0;
    while(current!=nullptr){
        if(colIdx==10){
            cout<<endl;
            colIdx = 0;
        }
        colIdx++;
        if(current->data.getIsBooked()){
            cout<<red<<current->data.convertSeatTypeToSimpleString()<<" ";
        }
        else{
            cout<<green<<current->data.convertSeatTypeToSimpleString()<<" ";    
        }
        current = current->next;
    }
}
void convertSeaTypeToSimpleString(SeatType type){
    if(type==SeatType::VIP){
        cout<<"V";
    } else if(type==SeatType::Regular){
        cout<<"R";
    } else if(type==SeatType::Disable){
        cout<<"D";
    }
}
