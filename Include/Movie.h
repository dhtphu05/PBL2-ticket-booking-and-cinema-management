#include <iostream>
#include <string>
#include "../Template/DoubleLinkedList.h"
using namespace std;
#ifndef MOVIE_H
#define MOVIE_H
#include <regex>
#include <ctime>
class Movie
{
private:
    static int countMovie;
    int ID_Movie;
    string title;
    string genre;
    string duration;
    string releaseDate;
    string director;
    string actor;
    string country;
    string description;
    string language;
    string rating;
    string fileImage;

public:
    Movie();
    Movie(const string &title, const string &genre, string &duration, const string &releaseDate, const string &Rating, string &director, string &actor, string &language, string &decription);
    void addMovie();
    void editMovie();
    void removeMovie();
    void readID(DoubleLinkedList<Movie> &);
    void viewMovie();
    void searchMovie(string &line);
    void saveToFile(int i);
    void readFile(DoubleLinkedList<Movie> &);
    Movie *selectMovie(int ID);
    void getMovie();
    void setID_Movie()
    {
        this->ID_Movie = countMovie;
    };
    void setTitle();
    void setGenre();
    void setReleaseDate();
    void setDirector();
    void setRating();
    void setDuration();
    void setActor();
    void setLanguage();
    void setDescription();
    void Display();
    void show(DoubleLinkedList<Movie> &movieList,int , int ,  int k);
    string getID_Movie();
    string getTitle();
    string *getTitlePointer();
    string getGenre();
    string getDuration();
    string getReleaseDate();
    string getDirector();
    string getActor();
    string getCountry();
    string getDescription();
    string getRating();
    string getfileImange()
    {
        return this->fileImage;
    }
    void sort_rating(DoubleLinkedList<Movie> &movieList);
    void showCurrentMovie();
    void showDetailMovie();
    friend ostream &operator<<(ostream &out, const Movie &m);
    friend istream &operator>>(istream &in, Movie &m);
    friend void subSaveAgainFile(DoubleLinkedList<Movie> &movieList);
    friend void printMovie(Movie *m);
    void selectMovieToBooking(DoubleLinkedList<Movie> &movieList);
    void subSaveAgainFile(DoubleLinkedList<Movie> &movieList);
    friend class User;
};
int get_year()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return 1900 +  localTime->tm_year;          // tm_year là số năm tính từ 1900
}
int get_month()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return  1+localTime->tm_mon;          //
}
int get_day()
{
    // Lấy thời gian hiện tại
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now); // Lấy thời gian local
    return localTime->tm_mday;          // 
}
bool isNameFile(string &str){
    std::regex pattern(R"(^[^\/:*?<>|]+\.txt$)");
    return std::regex_match(str, pattern);
}
bool _regexRLD(string &DOB)
{
    std::regex patter("\\d{2}[/]\\d{2}[/]\\d{4}");

    if (std::regex_match(DOB, patter))
    {
        string day = DOB.substr(0, 2);
        string month = DOB.substr(3, 2);
        string year = DOB.substr(6, 4);
        if (stoi(year) > get_year())
            return false;
        else if (stoi(year) == get_year())
        {
            if (stoi(month) > get_month())
            {
                return false;
            }
            else if (stoi(month) == get_month())
            {
                if (stoi(day) > get_day())
                {
                    return false;
                }
            }
        }
        else
        {   
            if(stoi (month)>12)
            return false;
            else {
                if(stoi(day)>31)
                return false;
            }
        }
        return true;
        
    }
    else
        return false;
}
#endif
