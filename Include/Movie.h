#include <iostream>
#include <string>
#include"../Template/DoubleLinkedList.h"
using namespace std;
#ifndef MOVIE_H
#define MOVIE_H
class Movie{
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
    string rating;

    public:
    Movie();
    Movie(const string& title, const string& genre, string &duration, const string& releaseDate, const string& Rating, string &director, string &actor, string &language, string &decription);
    void addMovie();
    void editMovie();
    void removeMovie();
    void readID(DoubleLinkedList<Movie> &);
    void viewMovie();
    void searchMovie();
    void saveToFile(int i);
    void readFile(DoubleLinkedList<Movie>&);
    void selectMovie();
    void getMovie();
    void setID_Movie(){
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
    void show();
    string getID_Movie();
    string getTitle();
    string getGenre();
    string getDuration();
    string getReleaseDate();
    string getDirector();
    string getActor();
    string getCountry();
    string getDescription();
    string getRating();
    friend ostream &operator<<(ostream& out, const Movie& m);
    friend istream &operator>>(istream& in, Movie& m);
    friend void subSaveAgainFile(DoubleLinkedList<Movie> &movieList);
};
#endif