#include "../Include/Screen.h"
#include "Seat.cpp"
Screen::Screen(int ID_Screen, DoubleLinkedList<Seat> seatLayout)
    : ID_Screen(ID_Screen) {
    for (Node<Seat>* node = seatLayout.begin(); node != nullptr; node = node->next) {
        Seat seat = node->data;
        Seat newSeat(seat.getSeatRow(), seat.getSeatColumn(), seat.getType());
        this->seatLayout.push_back(newSeat);
    }   
}
Screen::Screen(){
    this->ID_Screen = 0;
    this->seatLayout = DoubleLinkedList<Seat>();
}

void Screen::loadScreenFromFile(DoubleLinkedList<Screen> &screens) {
    ifstream file("../Databases/Screen.txt");
    if (!file.is_open()) {
        cout << "Error opening Screen.txt for reading" << endl;
        return;
    }

    string line, key;
    Screen* currentScreen = nullptr;

    while (getline(file, line)) {
        // Kiểm tra dòng đọc từ file
       // cout << "Read line: " << line << endl;

        if (line.empty()) continue;  // Skip empty lines

        istringstream ss(line);

        // Kiểm tra nếu dòng bắt đầu với "ID_Screen: "
        if (line.rfind("ID_Screen: ", 0) == 0) {
            // Lưu màn hình hiện tại vào danh sách và reset nếu có
            if (currentScreen != nullptr) {
                screens.push_back(*currentScreen);
                delete currentScreen; // Free the previous screen's memory
            }
            currentScreen = new Screen();
            ss >> key >> currentScreen->ID_Screen;

            // Kiểm tra ID_Screen vừa đọc
            //cout << "Loaded Screen ID: " << currentScreen->ID_Screen << endl;

        } else if (line.rfind("Layout:", 0) == 0 && currentScreen != nullptr) {
            // Đọc layout
           // cout << "Layout section begins." << endl;
            int rowIdx = 0;
            while (getline(file, line) && !line.empty() && rowIdx < 10) {  // 10 hàng layout
                //cout << "Reading row " << rowIdx + 1 << ": " << line << endl; // In ra dòng layout

                istringstream layoutStream(line);
                string seatTypeStr;
                int colIdx = 0;

                // Đọc các seatTypeStr (R, V, D) trong mỗi dòng layout
                while (layoutStream >> seatTypeStr && colIdx < 10) { // 10 cột trong layout
                    Seat seat;
                    if (seatTypeStr == "V") {
                        seat.setType(SeatType::VIP);
                    } else if (seatTypeStr == "R") {
                        seat.setType(SeatType::Regular);
                    } else if (seatTypeStr == "D") {
                        seat.setType(SeatType::Disable);
                    }

                    // Kiểm tra seatRow cho ghế
                    string seatRow;
                    if (rowIdx < 26) {  // Chỉ từ A đến Z
                        seatRow = string(1, 'A' + rowIdx);  // Ví dụ: A, B, C, ...
                    } else {
                        // Đối với rowIdx >= 26, bạn có thể xử lý như AA, AB, ...
                        int firstChar = 'A' + (rowIdx / 26) - 1;
                        int secondChar = 'A' + (rowIdx % 26);
                        seatRow = string(1, firstChar) + string(1, secondChar);
                    }
                    colIdx++;
                    seat.setSeatColumn(colIdx - 1);  // Đặt seatColumn cho ghế
                    seat.setSeatRow(seatRow);  // Đặt seatRow cho ghế
                    currentScreen->seatLayout.push_back(seat);  // Thêm ghế vào layout
                    
                    //seat.displaySeat();

                    // Kiểm tra seatType và seatRow
                   // cout << "Seat added: " << seatRow << " Type: " << seatTypeStr << endl;
                }
                rowIdx++;
            }
        }
    }

    // Thêm màn hình cuối cùng vào danh sách nếu có
    

    file.close();
}

void Screen::displayScreen(){
    cout<<"Screen ID: "<<this->ID_Screen<<endl;
    cout<<"Screen Layout: "<<endl;
    for(Node<Seat>* node = this->seatLayout.begin(); node != nullptr; node = node->next){
        Seat seat = node->data;
        seat.displaySeat();
    }
}
void Screen::displayAllScreen(DoubleLinkedList<Screen> &screens){
    for(Node<Screen>* node = screens.begin(); node != nullptr; node = node->next){
        node->data.displayScreen();
        cout<<"# NextScreen"<<endl;
    }
}

void Screen::addScreen(DoubleLinkedList<Screen> &screens){
    Screen screen;
    cout<<"Enter the ID of the screen: ";
    cin>>screen.ID_Screen;
    cout<<"Enter the layout of the screen: "<<endl;
    cout<<"Enter V for VIP seat, R for Regular seat, D for Disable seat"<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<"Enter the type of seat at row "<<to_string(i+'A')<<" and column "<<j<<": ";
            string type;
            cin>>type;
            Seat seat;
            seat.setSeatRow(to_string(i+'A'));
            seat.setSeatColumn(j);
            if(type=="V"){
                seat.setType(SeatType::VIP);
            } else if(type=="R"){
                seat.setType(SeatType::Regular);
            } else if(type=="D"){
                seat.setType(SeatType::Disable);
            }
            screen.seatLayout.push_back(seat);
        }
    }
    if(!screen.saveScreenToFile(screens)){
        cout<<"Failed to save screen record."<<endl;
    }
}
bool Screen::saveScreenToFile(DoubleLinkedList<Screen> screens){
    ofstream file("../Databases/Screen.txt");
    Node<Screen> *current = screens.begin();
    while(current!=nullptr){
        file << "ID_Screen: " << current->data.ID_Screen << endl;
        file << "Layout:" << endl;
        for(Node<Seat>* node = current->data.seatLayout.begin(); node != nullptr; node = node->next){
            Seat seat = node->data;
            if(seat.getType()==SeatType::VIP){
                file << "V ";
            } else if(seat.getType()==SeatType::Regular){
                file << "R ";
            } else if(seat.getType()==SeatType::Disable){
                file << "D ";
            }
            if(seat.getSeatColumn()==9){
                file << endl;
            }
        }
        file << endl;
        current = current->next;
    }
    file.close();
    return true;
}
Screen Screen::selectScreen(){
    DoubleLinkedList<Screen> screens;
    Screen screen;
    screen.loadScreenFromFile(screens);
    screen.displayAllScreen(screens);
    cout<<"Enter the ID of the screen you want to select: ";
    int ID;
    cin>>ID;
    for(Node<Screen>* node = screens.begin(); node != nullptr; node = node->next){
        if(node->data.ID_Screen==ID){
            return node->data;
        }
    }
    cout<<"Screen not found."<<endl;
    return Screen();
}
int* Screen::getID_screen(){
    return &ID_Screen;
}
