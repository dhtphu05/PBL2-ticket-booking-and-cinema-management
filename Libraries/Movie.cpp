#include "../Include/Movie.h"
#include "../Template/DoubleLinkedList.h"
#include <fstream>
#include <sstream>
#include <cctype>

int Movie::countMovie = 2000;
// void menuStaff()
// {
//     cout << "1. Them phim" << endl;
//     cout << "2. Sua phim" << endl;
//     cout << "3. Xoa phim" << endl;
//     cout << "4. Xem danh sach phim" << endl;
//     cout << "5. Tim kiem phim" << endl;
//     cout << "6. Them khach hang" << endl;
//     cout << "7. Xem danh sach khach hang" << endl;
//     cout << "8. Sua khach hang" << endl;
//     cout << "9. Them nhan vien" << endl;
//     cout << "10. Xem nhan vien" << endl;
//     cout << "11. Sua nhan vien" << endl;
//     cout << "12. Xoa nhan vien " << endl;
// }
void menuEditFilm()
{
    cout << "1. ID" << endl;
    cout << "2. Ten phim" << endl;
    cout << "3. The loai" << endl;
    cout << "4. Thoi luong" << endl;
    cout << "5. Ngay phat hanh" << endl;
    cout << "6. Dao dien" << endl;
    cout << "7. Dien vien" << endl;
    cout << "8. Nuoc san xuat" << endl;
    cout << "9. Mo ta" << endl;
    cout << "10. Rating" << endl;
}

Movie::Movie(const string &title, const string &genre, string &duration, const string &releaseDate, const string &Rating, string &director, string &actor, string &country, string &decription)
    : title(title), genre(genre), duration(duration), releaseDate(releaseDate), rating(Rating), director(director), actor(actor), country(country), description(description)
{
    // countMovie++;
    // this->ID_Movie = this->getCountMovie();
}
Movie::Movie()
{   
    this->ID_Movie = countMovie;
    countMovie++;
    this->title = "";
    this->genre = "";
    this->duration = "";
    this->releaseDate = "";
    this->rating = "";
    this->director = "";
    this->actor = "";
    this->country = "";
    this->description = "";
    this->rating = "";
}
void Movie::addMovie()
{
    Movie newMovie;
    cin >> newMovie;
    newMovie.saveToFile(0);
}
void subEditMovie(Movie &movie, string &line, string message)
{
    cout << message << " moi: " << endl;
    cin.ignore();
    getline(cin, line);
}
void subSaveAgainFile(DoubleLinkedList<Movie> &movieList)
{
    ofstream out;
    out.open("../Databases/MovieList.txt");
    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }
    for (int i = 0; i < movieList.getSize(); i++)
    {
        out << movieList[i].ID_Movie << ";" << movieList[i].title << ";" << movieList[i].genre << ";" << movieList[i].duration << ";" << movieList[i].releaseDate << ";" << movieList[i].director << ";" << movieList[i].actor << ";" << movieList[i].country << ";" << movieList[i].description << ";" << movieList[i].rating << endl;
    }
    out.close();
}
void Movie::editMovie()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    system("cls");
    cout << "Nhap ID phim can sua: ";
    int ID;
    cin >> ID;
    int count = false;
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            count = true;
            menuEditFilm();
            cout << "Chon thong tin sua  " << endl;
            int choice;
            cin >> choice;
            switch (choice)
            {

            case 1:
                subEditMovie(movieList[i], movieList[i].title, "Ten phim");
                break;
            case 2:
                subEditMovie(movieList[i], movieList[i].genre, "The Loai");
                break;
            case 3:
                subEditMovie(movieList[i], movieList[i].duration, "Thoi luong");
                break;
            case 4:
                subEditMovie(movieList[i], movieList[i].releaseDate, "Ngay san xuat");
                break;
            case 5:
                subEditMovie(movieList[i], movieList[i].director, "Dao dien");
                break;
            case 6:
                subEditMovie(movieList[i], movieList[i].actor, "Dien vien");
                break;
            case 7:
                subEditMovie(movieList[i], movieList[i].country, "Nuoc san xuat");
                break;
            case 8:
                subEditMovie(movieList[i], movieList[i].description, "Mo ta");
                break;
            case 9:
                subEditMovie(movieList[i], movieList[i].rating, "Rating");
                break;
                break;
            }
        }
    }
    if (count == false)
    {
        cout << "Khong tim thay phim" << endl;
    }
    else
    {
        subSaveAgainFile(movieList);
    }
}
void Movie::saveToFile(int i)
{
    DoubleLinkedList<Movie> movies;
    readID(movies);
    this->ID_Movie = countMovie;
    ofstream out;
    if (i)
    {
        out.open("../Databases/MovieList.txt");
    }
    else
    {
        out.open("../Databases/MovieList.txt", std::ios::app);
    }
    if (!out.is_open())
    {
        throw runtime_error("Khong the mo file");
    }
    out << this->ID_Movie << ";" << this->title << ";"
        << this->genre << ";" << this->duration << ";"
        << this->releaseDate << ";" << this->director << ";"
        << this->actor << ";" << this->country << ";"
        << this->description << ";" << this->rating << endl;
    out.close();
}
istream &operator>>(istream &in, Movie &m)
{
    cout << "Ten phim: ";
    in.ignore();
    getline(in, m.title);
    cout << "The loai: ";
    getline(in, m.genre);
    cout << "Thoi luong: ";
    getline(in, m.duration);
    cout << "Ngay phat hanh: ";
    getline(in, m.releaseDate);
    cout << "Dao dien: ";
    getline(in, m.director);
    cout << "Dien vien: ";
    getline(in, m.actor);
    cout << "Nuoc san xuat:";
    getline(in, m.country);
    cout << "Mo ta: ";
    getline(in, m.description);
    cout << "Rating: ";
    getline(in, m.rating);
    return in;
}
ostream &operator<<(ostream &out, const Movie &m)
{   
    out<< "ID: " << m.ID_Movie << endl;
    out << "Ten phim: " << m.title << endl;
    out << "The loai: " << m.genre << endl;
    out << "Thoi luong: " << m.duration << endl;
    out << "Ngay phat hanh: " << m.releaseDate << endl;
    out << "Dao dien: " << m.director << endl;
    out << "Dien vien: " << m.actor << endl;
    out << "Nuoc san xuat: " << m.country << endl;
    out << "Mo ta: " << m.description << endl;
    out << "Rating: " << m.rating << endl;
    out << "-----------------------------------" << endl;
    return out;
}
void Movie::removeMovie()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    int ID;
    cout << "Nhap ID phim can xoa: ";
    cin >> ID;
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            movieList.earse(i);
        }
    }
    subSaveAgainFile(movieList);
}
void Movie::readFile(DoubleLinkedList<Movie> &movieList)
{
    ifstream in;
    in.open("../Databases/MovieList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }
    string line;
    // int maxID = countMovie;
    while (getline(in, line))
    {
        Movie m;
        stringstream ss(line);
        string idtemp;
        getline(ss, idtemp, ';');
        m.ID_Movie = stoi(idtemp);
        // if (m.ID_Movie > maxID)
        // {
        //     maxID = m.ID_Movie;
        // }
        getline(ss, m.title, ';');
        getline(ss, m.genre, ';');
        getline(ss, m.duration, ';');
        getline(ss, m.releaseDate, ';');
        getline(ss, m.director, ';');
        getline(ss, m.actor, ';');
        getline(ss, m.country, ';');
        getline(ss, m.description, ';');
        getline(ss, m.rating);
        movieList.push_back(m);
    }
    in.close();
    // countMovie = ++maxID;
}
void Movie::readID(DoubleLinkedList<Movie> &movieList)
{
    int is_read = false;
    ifstream in;
    in.open("../Databases/MovieList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }
    string line;
    int maxID = countMovie;
    while (getline(in, line))
    {
        is_read = true;
        Movie m;
        stringstream ss(line);
        string idtemp;
        getline(ss, idtemp, ';');
        m.ID_Movie = stoi(idtemp);
        if (m.ID_Movie > maxID)
        {
            maxID = m.ID_Movie;
        }
        getline(ss, m.title, ';');
        getline(ss, m.genre, ';');
        getline(ss, m.duration, ';');
        getline(ss, m.releaseDate, ';');
        getline(ss, m.director, ';');
        getline(ss, m.actor, ';');
        getline(ss, m.country, ';');
        getline(ss, m.description, ';');
        getline(ss, m.rating);
        movieList.push_back(m);
    }
    in.close();
    countMovie = ++maxID;
    // return is_read;
}
void Movie::Display()
{
    cout << *this;
}
void Movie::show()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    movieList.display();
}
std::string toLowerCase(const std::string &str)
{
    std::string result = str;
    for (char &c : result)
    {
        c = std::tolower(c); // Chuyển từng ký tự sang chữ thường
    }
    return result;
}
void Movie::searchMovie()
{
    int count = false;
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    string title;
    cout << "Nhap ten phim can tim: ";
    cin.ignore();
    getline(cin, title);
    title = toLowerCase(title);
    for (int i = 0; i < movieList.getSize(); i++)
    {

        if (toLowerCase(movieList[i].title) == title)
        {
            count = true;
            cout << movieList[i];
            break;
        }
    }
    if (count == false)
    {
        cout << "Khong tim thay phim" << endl;
    }
}

string Movie::getID_Movie()
{
    return to_string(this->ID_Movie);
}
string Movie::getTitle()
{
    return this->title;
}
string* Movie::getTitlePointer()
{
    return &this->title;
}
string Movie::getGenre()
{
    return this->genre;
}
string Movie::getDuration() 
{
    return this->duration;
}
string Movie::getReleaseDate()
{
    return this->releaseDate;
}
string Movie::getDirector()
{
    return this->director;
}
string Movie::getActor()
{
    return this->actor;
}
string Movie::getCountry()
{
    return this->country;
}
string Movie::getDescription()
{
    return this->description;
}
string Movie::getRating()
{
    return this->rating;
}
Movie* Movie::selectMovie(int ID)
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            // Tạo một đối tượng Movie mới trên heap và sao chép dữ liệu
            return new Movie(movieList[i]);
        }
    }
    return nullptr;
}
void printMovie(Movie *m)
{
    cout<<m->getTitle()<<endl;
}
void Movie::selectMovieToBooking(){
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    for(int i=0;i<movieList.getSize();i++){
        cout<<movieList[i].ID_Movie<<". "<<movieList[i].title<<endl;
    }
    cout<<"Enter the ID of the movie you want to select: ";
    int ID;
    cin>>ID;
    for(int i=0;i<movieList.getSize();i++){
        if(movieList[i].ID_Movie==ID){
            *this = movieList[i];
            return;
        }
    }
    cout<<"Movie not found."<<endl;
}