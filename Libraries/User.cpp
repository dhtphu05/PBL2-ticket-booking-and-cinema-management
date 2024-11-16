#include "../Include/User.h"
#include <fstream>
User::User()
{
    
}

User::User(string &username, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender)
    : fullName(fullName), dateOfBirth(DOB), gender(gender), phoneNumber(phoneNumber), username(username), password(password)
{
    // this->ID = count;
    // count++;
}
//??????????????????????????????? moi comment lai de test cai warining
// string &User::getID()
// {
//     string line = to_string(this->ID);
//     return line;
// }
int User::returnID()
{
    return this->ID;
}
void User::setFullName(string &fullName)
{
    this->fullName = fullName;
}
void User::setGender(string &gender)
{
    this->gender = gender;
}
void User::setDOB(string &dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}
//?? comment thu de tesst warning
// int &User::getAge() const
// {
//     // Chuyển chuỗi ngày sinh thành các giá trị ngày, tháng, năm
//     int day, month, year;
//     sscanf(dateOfBirth.c_str(), "%d/%d/%d", &day, &month, &year);

//     // Lấy ngày hiện tại
//     time_t t = time(0);
//     tm *now = localtime(&t);

//     // Tính tuổi
//     int age = (now->tm_year + 1900) - year;
//     if ((now->tm_mon + 1 < month) ||
//         (now->tm_mon + 1 == month && now->tm_mday < day))
//     {
//         age--; // Giảm 1 tuổi nếu chưa đến sinh nhật trong năm nay
//     }

//     return age;
// }
void User::setPhoneNumber(string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void User::setUserName(string &username)
{
    this->username = username;
}
void User::resetPassword(string &)
{
    this->password = password;
}

string &User::getFullName()
{
    return this->fullName;
}
string &User::getDOB()
{
    return this->dateOfBirth;
}
string &User::getGender()
{
    return this->gender;
}
string &User::getPhoneNumber()
{
    return this->phoneNumber;
}
string &User::getUserName()
{
    return this->username;
}
string &User::getPassword()
{
    return this->password;
}
void User::savetoFile()
{
}
void User::readfromFile()
{
}
void User::saveAgainFile()
{
}
void User::setPassword(string&password){
    this->password=password;
}