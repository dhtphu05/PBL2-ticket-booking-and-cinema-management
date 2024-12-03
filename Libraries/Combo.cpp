#pragma once
#include "../Include/Combo.h"
#include "layout-select-seat.cpp"
// #include "getMouseClick.cpp"
#define byte windows_byte
#include <windows.h>
#undef byte
Combo::Combo()
{
    this->comboName = "";
    this->comboPrice = 0;
    this->comboDescription = "";
    this->quantity = 0;
    this->quantityBuy = 0;
    this->ID_Combo = 0;
}
Combo::Combo(string comboName, double comboPrice, string comboDescription, int quantity, int quantityBuy)
    : comboName(comboName), comboPrice(comboPrice), comboDescription(comboDescription), quantity(quantity), quantityBuy(quantityBuy)
{
}
string Combo::getComboName()
{
    return this->comboName;
}
double Combo::getComboPrice()
{
    return this->comboPrice;
}
string Combo::getComboDescription()
{
    return this->comboDescription;
}
int Combo::getQuantity()
{
    return this->quantity;
}
void Combo::setComboName(string comboName)
{
    this->comboName = comboName;
}
void Combo::setComboPrice(double comboPrice)
{
    this->comboPrice = comboPrice;
}
void Combo::setComboDescription(string comboDescription)
{
    this->comboDescription = comboDescription;
}
void Combo::setQuantity(int quantity)
{
    this->quantity = quantity;
}
int Combo::getQuantityBuy()
{
    return this->quantityBuy;
}
void Combo::setQuantityBuy(int quantityBuy)
{
    this->quantityBuy = quantityBuy;
}
int Combo::getID_Combo()
{
    return this->ID_Combo;
}

void Combo::loadComboFromFile(DoubleLinkedList<Combo> &combos){
    ifstream file("../Databases/Combo.txt");
    if (!file.is_open()) {
        cout << "Error opening Combo.txt for reading" << endl;
        return;
    }
    string line, key;
    Combo* currentCombo = nullptr;
    while(getline(file, line)){
        if(line.empty()) continue;
        istringstream ss(line);
        if(line.rfind("ID_Combo:", 0) == 0){
            if(currentCombo != nullptr){
                combos.push_back(*currentCombo);
            }
            currentCombo = new Combo();
            ss >> key >> currentCombo->ID_Combo;
        } else if(line.rfind("ComboName:", 0) == 0){
            ss >> key;
            getline(ss, currentCombo->comboName);
        } else if(line.rfind("ComboPrice:", 0) == 0){
            ss >> key >> currentCombo->comboPrice;
        } else if(line.rfind("ComboDescription:", 0) == 0){
            ss >> key;
            getline(ss, currentCombo->comboDescription);
        } else if(line.rfind("Quantity:", 0) == 0){
            ss >> key >> currentCombo->quantity;
        } else if(line.rfind("QuantityBuy:", 0) == 0){
            ss >> key >> currentCombo->quantityBuy;
        }
    }
    if(currentCombo != nullptr){
        combos.push_back(*currentCombo);
    }
    file.close();
}
void Combo::displayAllCombo(DoubleLinkedList<Combo> &combos){
    int x=5;
    int y=5;
    int i=0;
    for(Node<Combo>* node = combos.begin(); node != nullptr; node = node->next){
        node->data.displayCombo(x,y+i*10);
        i++;
    }
}
void buttonAcceptCombo(){
    gotoXY(134,46);
    cout<<BG_GREEN;
    lineWidth(12,true,true);
    lineHeight(1,134,47);
    lineHeight(1,147,47);
    gotoXY(134,48);
    lineWidth(12,true,false);
    gotoXY(137,47);
    cout<<"Xác nhận";
    cout<<RESET;
}

void Combo::displayCombo(int x,int y){
    gotoXY(x,y);
    lineWidth(50,true,true);
    lineHeight(6,x,y+1);
    lineHeight(6,x+51,y+1);
    gotoXY(x,y+7);
    lineWidth(50,true,false);
    gotoXY(x+2,y+2);
    cout<<this->comboName;
    gotoXY(x+2,y+4);
    cout<<this->comboDescription;
    gotoXY(x+2,y+6);
    cout<<"Giá: "<<this->comboPrice;
    int Dis=60;
    gotoXY(x+Dis,y+2);
    lineWidth(23,true,true);
    lineHeight(1,x+Dis,y+3);
    lineHeight(1,x+Dis+24,y+3);
    gotoXY(x+Dis,y+4);
    lineWidth(23,true,false);
    gotoXY(x+Dis+2,y+3);
    cout<<"  - ";
    gotoXY(x+Dis+7,y+2);
    cout<<"┬";
    gotoXY(x+Dis+7,y+3);
    cout<<"│";
    gotoXY(x+Dis+7,y+4);
    cout<<"┴";
    gotoXY(x+Dis+12,y+3);
    cout<<this->quantityBuy;
    gotoXY(x+Dis+18,y+3);
    cout<<"  +  ";
    gotoXY(x+Dis+17,y+2);
    cout<<"┬";
    gotoXY(x+Dis+17,y+4);
    cout<<"┴";
    buttonAcceptCombo();
}
void setIDComboWhenClick(Booking* booking,DoubleLinkedList<Combo> &combos, int &ID){
    int x=5;
    int y=5;
    int i=0;
    Combo combo;
    int x_click = click.X;
    int y_click = click.Y;
    for(Node<Combo>* node = combos.begin(); node != nullptr; node = node->next){
        
            if(isClickInRange(x_click, y_click, x+62, y+3+i*10, 4, 4)){
                node->data.setQuantityBuy(node->data.getQuantityBuy()-1);
                gotoXY(x+72,y+3+i*10);
                cout<<"   ";
                gotoXY(x+72,y+3+i*10);
                if(node->data.getQuantityBuy()<0){
                    node->data.setQuantityBuy(0);
                }
                cout<<node->data.getQuantityBuy();
                // cout<<"heheeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
                
            }
            if(isClickInRange(x_click, y_click, x+78, y+3+i*10, 4, 4)){
                node->data.setQuantityBuy(node->data.getQuantityBuy()+1);
                gotoXY(x+72,y+3+i*10);
                cout<<"    ";
                gotoXY(x+72,y+3+i*10);
                cout<<node->data.getQuantityBuy();
                // cout<<"hêweeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
            }
            
        i++;
    }
  
}



void Combo::displaySimpleCombo(int x,int y){
    gotoXY(x,y);
    cout<<"x";
    gotoXY(x+2,y);
    cout<<this->getQuantityBuy();
    gotoXY(x+5,y);
    cout<<this->getComboName();
    gotoXY(x+30,y);
    cout<<this->getComboPrice()*this->getQuantityBuy();
}
void layoutBillTemp(Booking* booking){
    int x=115;
    int y=5;
    gotoXY(110,3);
    lineWidth(42,true,true);
    lineHeight(35,110,4);
    lineHeight(35,153,4);
    gotoXY(110,23);
    lineWidth(42,true,false);
    gotoXY(x,y);
    cout<<"THÔNG TIN ĐẶT VÉ";
    gotoXY(x,y+2);
    cout<<"Mã vé: "<<booking->getBookingNumber();
    gotoXY(x,y+4);
    cout<<"Tên phim: "<<booking->getShow()->getMovie()->getTitle();
    gotoXY(x,y+6);
    cout<<"THỜI GIAN               NGÀY CHIẾU";
    gotoXY(x-2,y+8);
    cout<<booking->getShow()->getStartTime()<<" ~ "<<booking->getShow()->getEndTime()<<"            ";
    cout<<booking->getShow()->getDate();
    gotoXY(x,y+10);
    cout<<"PHÒNG CHIẾU: "<<booking->getShow()->getScreen()->getID_screen();
    gotoXY(x,y+12);
    cout<<"GHẾ:";
    gotoXY(x-1,y+14);
    int countVIP=0;
    int countNormal=0;
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
        if(node->data.convertSeatTypeToSimpleString()=="V"){
            countVIP++;
        }
        else{
            countNormal++;
        }
    }
    cout<<"x "<<countVIP<<" VIP: ";
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){\
        
        if(node->data.convertSeatTypeToSimpleString()=="V"){
            gotoXY(x-1+6+countVIP*4,y+14);
            countVIP--;
            cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
        }
    }
    gotoXY(x-1,y+16);
    cout<<"x "<<countNormal<<" THƯỜNG: ";
    for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
        
        if(node->data.convertSeatTypeToSimpleString()=="R"){
            gotoXY(x-1+9+countNormal*4,y+16);
        countNormal--;
            cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
        }
    }


    // gotoXY(x+16,y+12);
    // cout<<booking->getTotalPrice();
}
void Combo::processCombo(Booking* booking){
    DoubleLinkedList<Combo> combos;
    Combo combo;
    combo.loadComboFromFile(combos);
    combo.displayAllCombo(combos);
    int ID;
    layoutBillTemp(booking);
    bool isEndBookCombo=false;    // cin>>ID;
    while(isEndBookCombo==false){
    click=processInputEvents();

    setIDComboWhenClick(booking,combos,ID);
    
    // for(int j=0;j<5;j++){
    //     gotoXY(50,50+j);
    //     cout<<"                                                    ";
    // }
    // Clear previous display area
    // for(int j = 50; j < 70; j++) {
    //     gotoXY(120, j);
    //     cout << "                                                  ";
    // }
    //clear area cũ
    for(int j=0;j<5;j++){
        gotoXY(114,25+j);
        cout<<"                                      ";                                   
    }
    int i=0;
    for(Node<Combo>* node = combos.begin(); node != nullptr; node = node->next){
        if(node->data.getQuantityBuy()>0){
            node->data.displaySimpleCombo(114,25+i*2);
            i++;
        }
    }
    // click=processInputEvents();
    isEndBookCombo=isClickInRange(click.X, click.Y, 134, 46, 5, 2);
    }
    
    gotoXY(130,20);
    for(Node<Combo>* node = combos.begin(); node != nullptr; node = node->next){
        if(node->data.getQuantityBuy()>0){
            booking->getCombos().push_back(node->data);
            booking->setTotalPrice(booking->getTotalPrice()+node->data.getComboPrice()*node->data.getQuantityBuy());
        }
    }

}
// void displayAllCombo(DoubleLinkedList<Combo> &combos){
//     for(Node<Combo>* node = combos.begin(); node != nullptr; node = node->next){
//         node->data.displayCombo();
//     }
// }