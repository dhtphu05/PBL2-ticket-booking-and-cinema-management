#include <iostream>
#include <fstream>
using namespace std;
#define byte windows_byte
#include <windows.h>
#undef byte

int main(){
    SetConsoleOutputCP(65001);
    ifstream file("../Databases/testQRCode.txt");
    string line;
    while (std::getline(file, line)) {
        cout<<line<<endl;
    }
}