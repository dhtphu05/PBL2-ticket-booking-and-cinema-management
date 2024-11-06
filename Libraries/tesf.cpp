#pragma once
#include "Screen.cpp"
#include<iostream>
using namespace std;
int main(){
    DoubleLinkedList<Screen> screens;
    Screen screen;
    screen.loadScreenFromFile(screens);
    for(Node<Screen>* node = screens.begin(); node != nullptr; node = node->next){
        node->data.displayScreen();
        cout<<"# NextScreen"<<endl;
    }
    
    cout<<"helo";
  
}
///viet ham convert nguowc tuw casi seatlayout sang so do quy dinh