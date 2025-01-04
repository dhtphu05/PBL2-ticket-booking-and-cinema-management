#pragma once
#include "../Include/gotoXY.h"
// #include "Booking.cpp"
#include "../Include/Show.h"
#include "../Include/Booking.h"
// #include "getMouseClick.cpp"
#include "../Include/clickMouse.h"
#include <iostream>
#include <string>
using namespace std;
#define byte windows_byte
#include <windows.h>
#undef byte

// const string BG_RED = "\033[41m";
// const string BG_BLUE = "\033[44m";
// const string BG_GREEN ="\033[42m";
// const string BG_GRAY = "\033[100m";
const string BG_RED="\033[31m";
const string BG_BLUE="\033[34m";
const string BG_GREEN="\033[32m";
const string BG_GRAY="\033[37m";
const string RESET  ="\033[0m";
const string BG_YELLOW="\033[33m";
const string BG_CYAN="\033[36m";
void lineWidth(int n,bool hasRadius,bool isTop){
    
    if(isTop){
        if(hasRadius){
            cout<<"╭";
        }
        for(int i=0;i<n;i++){
            cout<<"─";
        }
        if(hasRadius){
            cout<<"╮";
        }
    }
    else{
        if(hasRadius){
            cout<<"╰";
        }
        for(int i=0;i<n;i++){
            cout<<"─";
        }
        if(hasRadius){
            cout<<"╯";
        }
    }
   
}
void lineHeight(int n, int x,int y){
    for(int i=0;i<n;i++){
        gotoXY(x,y+i);
        cout<<"│"<<endl;

    }
}
void layoutScreen(){
    gotoXY(30,12);
    lineWidth(50,true,false);
    gotoXY(30,11);
    cout<<"│";
    gotoXY(81,11);
    cout<<"│";
    gotoXY(50,11);
    cout<<"Màn Hình";
}
void layoutScreen_ver2(){
    gotoXY(30,6);
    lineWidth(50,true,false);
    gotoXY(30,5);
    cout<<"│";
    gotoXY(81,5);
    cout<<"│";
    gotoXY(50,5);
    cout<<"Màn Hình";
}


void layoutOneSeat(int x,int y, string row, int col, string colorBackground=BG_GRAY){
    gotoXY(x,y);
    cout<<colorBackground<<"╭"<<"─"<<"─"<<"╮"<<RESET<<endl;
    gotoXY(x,y+1);
    cout<<colorBackground<<"│"<<row<<col<<"│"<<RESET<<endl;
    gotoXY(x,y+2);
    cout<<colorBackground<<"╰"<<"─"<<"─"<<"╯"<<RESET<<endl;
}

void layout10SeatInRow(Show* show,int rowIdx,int x,int y){
    for(int i=0;i<10;i++){
        layoutOneSeat(x+i*8,y,show->getSeatByRowColumn(to_string(rowIdx),i).getSeatRow(),show->getSeatByRowColumn(to_string(rowIdx),i).getSeatColumn());
    }
}
void descriptionSeat(){
    layoutOneSeat(20-3,46,"A",1,BG_RED);
    gotoXY(25-3,46);
    cout<<": Ghế VIP";
    layoutOneSeat(40-5,46,"A",2,BG_BLUE);
    gotoXY(45-5,46);
    cout<<": Ghế thường";
    layoutOneSeat(60-7,46,"A",3);
    gotoXY(65-7,46);
    cout<<": Ghế đã đặt";
    // gotoXY(75,48);
    // cout<<": Ghế bạn chọn";
    // layoutOneSeat(70,46,"A",4,BG_GREEN);

}
void descriptionSeat_ver2(){
    layoutOneSeat(20-3,46-6,"A",1,BG_RED);
    gotoXY(25-3,46-6);
    cout<<": Ghế VIP";
    layoutOneSeat(40-5,46-6,"A",2,BG_BLUE);
    gotoXY(45-5,46-6);
    cout<<": Ghế thường";
    layoutOneSeat(60-7,46-6,"A",3);
    gotoXY(65-7,46-6);
    cout<<": Ghế đã đặt";
    // gotoXY(75,48);
    // cout<<": Ghế bạn chọn";
    // layoutOneSeat(70,46,"A",4,BG_GREEN);

}

void buttonAccept(){
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

void layoutBorderSeat(Show* show){
    gotoXY(10,10);
    lineWidth(90,true,true);
    lineHeight(35,10,11);
    lineHeight(35,101,11);
    gotoXY(10,45);
    lineWidth(90,true,false);
    layoutScreen();
    buttonAccept();
    Node<ShowSeat> *current = show->getSeats().begin();
    int colIdx=0;
    int x=11;
    int y=15;
    int i=0,j=0;
    while(current!=nullptr){
        if (colIdx==10){
            colIdx=0;
            i=0;
            j++;
        }
        i++;
        colIdx++;

        if(current->data.convertSeatTypeToSimpleString()=="V" ){
            layoutOneSeat(x+i*8,y+j*3,current->data.getSeatRow(),current->data.getSeatColumn(),BG_RED);
        }
        else if(current->data.convertSeatTypeToSimpleString()=="R"){
            layoutOneSeat(x+i*8,y+j*3,current->data.getSeatRow(),current->data.getSeatColumn(),BG_BLUE);
        }
        else if(current->data.convertSeatTypeToSimpleString()=="D"){
        }
        
        if(current->data.getIsBooked()==true && current->data.convertSeatTypeToSimpleString()!="D"){
            layoutOneSeat(x+i*8,y+j*3,current->data.getSeatRow(),current->data.getSeatColumn(),BG_GRAY);
            //gotoXY(x+i*8,y+j*3);
            // cout<<current->data.convertSeatTypeToSimpleString()<<endl;
        }   
        current = current->next;
    }
    descriptionSeat();
}
int getTextWidth(const string& text) {
    int width = 0;
    for (size_t i = 0; i < text.length();) {
        if ((unsigned char)text[i] < 0x80) {
            width += 1;
            i += 1;
        } else {
            width += 1;  // Most Vietnamese characters take up one display width
            i += 2;  // Skip the UTF-8 bytes
        }
    }
    return width;
}
void onlyLayoutSeat(Screen* screen){
    gotoXY(10,4);
    lineWidth(90,true,true);
    lineHeight(35,10,5);
    lineHeight(35,101,5);
    gotoXY(10,39);
    lineWidth(90,true,false);
    layoutScreen_ver2();
    // buttonAccept();
    Node<Seat> *current = screen->getSeatLayout().begin();
    int colIdx=0;
    int x=11;
    int y=9;
    int i=0,j=0;
    // current->data.displaySeat();
    while(current!=nullptr){
        if (colIdx==10){
            colIdx=0;
            i=0;
            j++;
        }
        i++;
        colIdx++;

        if(current->data.convertSeatTypeToString()=="V" ){
            layoutOneSeat(x+i*8,y+j*3,current->data.getSeatRow(),current->data.getSeatColumn(),BG_RED);
        }
        else if(current->data.convertSeatTypeToString()=="R"){
            layoutOneSeat(x+i*8,y+j*3,current->data.getSeatRow(),current->data.getSeatColumn(),BG_BLUE);
        }
        else if(current->data.convertSeatTypeToString()=="D"){
        }
        current = current->next;
    }
    descriptionSeat();
}
void borderLineWithTextAndColor(int x, int y, string text, string color=RESET){
    SetConsoleCP(65001);
    int textWidth = getTextWidth(text);
    gotoXY(x,y);
    cout<<color;
    cout<<"╭";
    for(int i=0;i<textWidth;i++){
        cout<<"─";
    }
    cout<<"╮";
    gotoXY(x,y+1);
    cout<<"│"<<text<<"│";
    gotoXY(x,y+2);
    cout<<"╰";
    for(int i=0;i<textWidth;i++){
        cout<<"─";
    }
    cout<<"╯";
    cout<<RESET;
}
string addSpaceToPrintMoney(double money){
    string str=to_string(money);
    //delete .00000
    str=str.substr(0,str.find("."));
    string result="";
    int count=0;
    for(int i=str.length()-1;i>=0;i--){
        count++;
        result=str[i]+result;
        if(count%3==0 && i!=0){
            result=" "+result;
        }
    }
    return result;
}
string getHourAndMinuteOfTimeT(time_t t){
    struct tm * now = localtime( & t );
    string hour=to_string(now->tm_hour);
    string minute=to_string(now->tm_min);
    if(hour.length()==1){
        hour="0"+hour;
    }
    if(minute.length()==1){
        minute="0"+minute;
    }
    return hour+":"+minute;
}
void layoutBooking(Booking* booking){
    gotoXY(115,15);
    lineWidth(35,true,true);
    lineHeight(22,115,16);
    lineHeight(22,151,16);
    gotoXY(115,37);
    lineWidth(35,true,false);
    gotoXY(120,17);
    cout<<"THÔNG TIN ĐẶT VÉ";
    gotoXY(120,19);
    cout<<"Mã vé: "<<booking->getBookingNumber();
    gotoXY(120,21);
    cout<<"Tên phim: "<<booking->getShow()->getMovie()->getTitle();
    gotoXY(120,23);
    cout<<"Ngày chiếu: "<<booking->getShow()->getDate();
    gotoXY(120,25);
    cout<<"Giờ chiếu: "<<booking->getShow()->getStartTime();
    gotoXY(120,27);
    cout<<"Phòng chiếu: "<<booking->getShow()->getScreen()->getID_screen();
    gotoXY(120,29);
    cout<<"Số ghế: "<<booking->getNumberOfSeats();
    gotoXY(120,31);
    cout<<"Danh sách ghế: ";
    int x=120;
    int y=33;
    // for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
    //     gotoXY(x,y);
    //     cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
    //     y++;
    // }
    int indexToPrint=0;
    gotoXY(135,31);
    cout<<"                 ";
            for(Node<ShowSeat>* node = booking->getSeats().begin(); node != nullptr; node = node->next){
                gotoXY(135+indexToPrint,31);
                indexToPrint+=3;
                cout<<node->data.getSeatRow()<<node->data.getSeatColumn()<<" ";
            }
    gotoXY(120,33);
    time_t t = time(0);
    cout<<"Đặt vé lúc: "<<getHourAndMinuteOfTimeT(t);
    gotoXY(130,35);
    cout<<"            ";
    gotoXY(120,35);
    cout<<"Tổng tiền: "<<addSpaceToPrintMoney(booking->getTotalPrice());
}




void setRowandColumnWhenClick(Show* show,string &row, int &column){
    int x_click, y_click;
    int colIdx=0;
    int x=11;
    int y=15;
    int i=0,j=0;
    bool check=false;
        x_click = click.X;
        y_click = click.Y;
    Node<ShowSeat> *current = show->getSeats().begin();
    while(current!=nullptr){
        if (colIdx==10){
            colIdx=0;
            i=0;
            j++;
        }
        i++;
        colIdx++;
        
        // check=isClickInRange(x+i*8,y+j*3,x_click,y_click,3,2);
        check=isClickInRange(x_click,y_click,x+i*8,y+(j-1)*3,2,1); 
        if(check){
            row=current->data.getSeatRow();
            column=current->data.getSeatColumn();
            return;
        }
        current = current->next;
    }
}
int convertRowandColToInt(string row, int col){
    int rowInt= (char)row[0]-'A';
    int colTemp=col+1;
    return rowInt*10+colTemp;
}
string convertMoney(double money){
    // chuyen thanh VND có cach moi 3 chu so
    string str=to_string(money);
    //delete .00000
    str=str.substr(0,str.find("."));
    string result="";
    int count=0;
    for(int i=str.length()-1;i>=0;i--){
        count++;
        result=str[i]+result;
        if(count%3==0 && i!=0){
            result=" "+result;
        }
    }
    return result;
}
string convertDateDefalutToSimple (string date){
    //Sun Dec 20 00:00:00 2020 to 00:00:00 20/12/2020
    //it don't convert Dec to 12 ??
    string result="";
    string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    string monthNumber[] = {"01","02","03","04","05","06","07","08","09","10","11","12"};
    string day = date.substr(8,2);
    string month = date.substr(4,3);
    string year = date.substr(20,4);
    for(int i=0;i<12;i++){
        if(month==months[i]){
            month = monthNumber[i];
            break;
        }
    }
    result = date.substr(11,8)+" "+day+"/"+month+"/"+year;
    return result;
}









// int main(){
//     SetConsoleOutputCP(CP_UTF8);
//     // layoutBorderSeat();
//     return 0;
// }