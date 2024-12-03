#pragma once
#include "Booking.h"


class Combo{
    protected:
    int ID_Combo;
    string comboName;
    double comboPrice;
    string comboDescription;
    int quantityBuy;
    int quantity;
    public:
    Combo();
    Combo(string comboName, double comboPrice, string comboDescription, int quantity, int quantityBuy);
    string getComboName();
    double getComboPrice();
    string getComboDescription();
    int getQuantity();
    int getQuantityBuy();
    int getID_Combo();
    void setComboName(string comboName);
    void setComboPrice(double comboPrice);
    void setComboDescription(string comboDescription);
    void setQuantity(int quantity);
    void setQuantityBuy(int quantityBuy);
    void displayCombo(int x,int y);
    void displayAllCombo(DoubleLinkedList<Combo> &combos);
    void addCombo();
    void editCombo();
    void deleteCombo();
    void saveComboToFile();
    void loadComboFromFile(DoubleLinkedList<Combo> &combos);
    void processCombo(Booking* booking);
    void displaySimpleCombo(int x,int y);

};
