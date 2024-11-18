#include "../Include/Movie.h"
#include "../Template/DoubleLinkedList.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
#include "../Include/gotoXY.h"

int Movie::countMovie = 2000;
void forChar(int n, int x, int y, char ch);

void menuEditFilm(Movie &movie)
{
    forChar(100, 40, 10, '-');
    gotoXY(40, 11);
    cout << "| Title: " << left << setw(91) << movie.getTitle() << "|";
    forChar(100, 40, 12, '-');
    gotoXY(40, 13);
    cout << "| Genre: " << left << setw(91) << movie.getGenre() << "|";
    forChar(100, 40, 14, '-');

    gotoXY(40, 15);
    cout << "| Duration: " << left << setw(90) << movie.getDuration() << "|";
    forChar(100, 40, 16, '-');
    gotoXY(40, 17);
    cout << "| Release Date: " << left << setw(84) << movie.getReleaseDate() << "|";
    forChar(100, 40, 18, '-');
    gotoXY(40, 19);
    cout << "| Director: " << left << setw(88) << movie.getDirector() << "|";
    forChar(100, 40, 20, '-');
    gotoXY(40, 21);

    cout << "| Actors: " << left << setw(90) << movie.getActor() << "|";
    forChar(100, 40, 22, '-');
    gotoXY(40, 23);
    cout << "| Country of Origin: " << left << setw(80) << movie.getCountry() << "|";
    forChar(100, 40, 24, '-');
    gotoXY(40, 25);
    cout << "| Description: " << left << setw(86) << movie.getDescription() << "|";
    forChar(100, 40, 26, '-');
    gotoXY(40, 27);
    cout << "| Rating: " << left << setw(90) << movie.getRating() << "|";
    forChar(100, 40, 28, '-');
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
    gotoXY(50, 5);
    cout << "--Add movie--";
    cin >> newMovie;
    gotoXY(90, 30);

    cout << "+-----------------+";
    gotoXY(90, 31);
    cout << "|   1. COMFIRM    |";
    gotoXY(90, 32);
    cout << "+-----------------+";
    gotoXY(120, 30);
    cout << "+-----------------+";
    gotoXY(120, 31);
    cout << "|    2. CANCEL    |";
    gotoXY(120, 32);
    cout << "+-----------------+";
    int choice;
    gotoXY(100, 34);
    cout << "Your choice: ";
    gotoXY(120, 34);
    cin >> choice;
    if (choice == 1)
    {
        newMovie.saveToFile(0);
    }
}
void subEditMovie(Movie &movie, string &line, string message)
{
    cout << message << " new: " << endl;
    cin.ignore();
    getline(cin, line);
}
void subSaveAgainFile(DoubleLinkedList<Movie> &movieList)
{
    ofstream out;
    out.open("../Databases/MovieList.txt"); // Mở file để ghi đè lên toàn bộ dữ liệu trong file
    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }

    for (int i = 0; i < movieList.getSize(); i++)
    {
        // Ghi thông tin của mỗi bộ phim vào file theo định dạng mới
        out << "#" << movieList[i].ID_Movie << endl;
        out << "Title: " << movieList[i].title << endl;
        out << "Genre: " << movieList[i].genre << endl;
        out << "Duration: " << movieList[i].duration << endl;
        out << "Release Date: " << movieList[i].releaseDate << endl;
        out << "Director: " << movieList[i].director << endl;
        out << "Actors: " << movieList[i].actor << endl;
        out << "Country of Origin: " << movieList[i].country << endl;
        out << "Description: " << movieList[i].description << endl;
        out << "Rating: " << movieList[i].rating << endl;
        out << endl;
    }

    out.close(); // Đóng file sau khi ghi
}

void Movie::editMovie()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    gotoXY(40, 5);
    cout << "--Edit movie---";
    gotoXY(40, 6);
    cout << "ID: ";
    gotoXY(40, 7);
    cout << "+--------------+";
    gotoXY(40, 8);
    cout << "|              |";
    gotoXY(40, 9);
    cout << "+--------------+";
    gotoXY(42, 8);
    int ID;
    cin >> ID;
    int find = false;
    int k;
    Movie tempMovie;
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            k = i;
            tempMovie = movieList[i];
            find = true;
            menuEditFilm(movieList[i]);
            bool run = true;
            while (run)
            {
                gotoXY(0, 30);
                cout << "Choose your choice: ";
                int choice;
                cin >> choice;
                cin.ignore();
                switch (choice)
                {

                case 1:
                    gotoXY(49, 11);
                    cout << left << setw(87) << " ";
                    gotoXY(49, 11);
                    getline(cin, movieList[i].title);
                    gotoXY(10, 30);
                    break;
                case 2:
                    gotoXY(49, 13);
                    cout << left << setw(87) << " ";
                    gotoXY(49, 13);
                    getline(cin, movieList[i].genre);
                    gotoXY(10, 30);
                    break;
                case 3:
                    gotoXY(52, 15);
                    cout << left << setw(80) << " ";
                    gotoXY(52, 15);
                    getline(cin, movieList[i].duration);
                    gotoXY(10, 30);
                    break;
                case 4:
                    gotoXY(56, 17);
                    cout << left << setw(83) << " ";
                    gotoXY(56, 17);
                    getline(cin, movieList[i].releaseDate);
                    gotoXY(10, 30);
                    break;
                case 5:
                    gotoXY(52, 19);
                    cout << left << setw(86) << " ";
                    gotoXY(52, 19);
                    getline(cin, movieList[i].director);
                    gotoXY(10, 30);
                    break;
                case 6:

                    gotoXY(50, 21);
                    cout << left << setw(88) << " ";
                    gotoXY(50, 21);
                    getline(cin, movieList[i].actor);
                    gotoXY(10, 30);
                    break;
                case 7:

                    gotoXY(61, 23);
                    cout << left << setw(77) << " ";
                    gotoXY(61, 23);
                    getline(cin, movieList[i].country);
                    gotoXY(10, 30);
                    break;
                case 8:

                    gotoXY(55, 25);
                    cout << left << setw(83) << " ";
                    gotoXY(55, 25);
                    getline(cin, movieList[i].description);
                    gotoXY(10, 30);
                    break;
                case 9:

                    gotoXY(50, 27);
                    cout << left << setw(87) << " ";
                    gotoXY(50, 27);
                    getline(cin, movieList[i].rating);
                    gotoXY(10, 30);
                    break;
                default:
                    run = false;
                    break;
                }
            }
        }
    }

    if (find == false)
    {
        gotoXY(40, 10);
        cout << "No result!" << endl;
    }
    else
    {
        gotoXY(90, 29);
        cout << "+---------------------------+";
        gotoXY(90, 30);
        cout << "|  1.SAVE    |   2. CANCEL  |";
        gotoXY(90, 31);
        cout << "+----------------------------+";
        int choice;
        gotoXY(90, 32);
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 1)
        {
        }
        else
        {
            movieList[k] = tempMovie;
        }
        subSaveAgainFile(movieList);
    }
}
void Movie::saveToFile(int i)
{
    DoubleLinkedList<Movie> movies;
    readID(movies);              // Đọc ID của các bộ phim hiện tại để cập nhật ID mới
    this->ID_Movie = countMovie; // Gán ID mới cho bộ phim

    ofstream out;
    if (i)
    {
        out.open("../Databases/MovieList.txt"); // Mở file để ghi (ghi đè)
    }
    else
    {
        out.open("../Databases/MovieList.txt", std::ios::app); // Mở file để ghi thêm (append)
    }

    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }

    // Ghi thông tin bộ phim vào file với định dạng: "#ID", "Title", "Genre", "Duration", ...
    out << "#" << this->ID_Movie << endl;
    out << "Title: " << this->title << endl;
    out << "Genre: " << this->genre << endl;
    out << "Duration: " << this->duration << endl;
    out << "Release Date: " << this->releaseDate << endl;
    out << "Director: " << this->director << endl;
    out << "Actors: " << this->actor << endl;
    out << "Country: " << this->country << endl;
    out << "Description: " << this->description << endl;
    out << "Rating: " << this->rating << endl;
    out.close();
}
void forChar(int n, int x, int y, char ch)
{
    gotoXY(x, y);
    if (ch != ' ')
        ;
    cout << "+";
    for (int i = 0; i < n; i++)
    {
        if (ch != ' ')
        {
            gotoXY(x + 1, y);
        }
        else
            gotoXY(x, y);
        cout << ch;
        x++;
    }
    if (ch != ' ')
    {
        gotoXY(x, y);
        cout << "+";
    }
    else
        cout << "|";
}
istream &operator>>(istream &in, Movie &m)
{
    in.ignore();
    forChar(100, 40, 10, '-');
    gotoXY(40, 11);
    cout << "| Title: " << right << setw(91) << "|";
    forChar(100, 40, 12, '-');
    gotoXY(40, 13);
    cout << "| Genre: " << right << setw(91) << "|";
    forChar(100, 40, 14, '-');

    gotoXY(40, 15);
    cout << "| Duration: " << right << setw(88) << "|";
    forChar(100, 40, 16, '-');
    gotoXY(40, 17);
    cout << "| Release Date: " << right << setw(84) << "|";
    forChar(100, 40, 18, '-');
    gotoXY(40, 19);
    cout << "| Director: " << right << setw(87) << "|";
    forChar(100, 40, 20, '-');
    gotoXY(40, 21);

    cout << "| Actors: " << right << setw(90) << "|";
    forChar(100, 40, 22, '-');
    gotoXY(40, 23);
    cout << "| Country of Origin: " << right << setw(79) << "|";
    forChar(100, 40, 24, '-');
    gotoXY(40, 25);
    cout << "| Description: " << right << setw(85) << "|";
    forChar(100, 40, 26, '-');
    gotoXY(40, 27);
    cout << "| Rating: " << right << setw(90) << "|";
    forChar(100, 40, 28, '-');
    gotoXY(53, 11);
    getline(in, m.title);
    gotoXY(49, 13);
    getline(in, m.genre);
    gotoXY(53, 15);
    getline(in, m.duration);
    gotoXY(57, 17);
    getline(in, m.releaseDate);
    gotoXY(54, 19);
    getline(in, m.director);
    gotoXY(50, 21);
    getline(in, m.actor);
    gotoXY(61, 23);
    getline(in, m.country);
    gotoXY(55, 25);
    getline(in, m.description);
    gotoXY(50, 27);
    getline(in, m.rating);

    return in;
}
ostream &operator<<(ostream &out, const Movie &m)
{
    out << "ID: " << m.ID_Movie << endl;
    out << "Title: " << m.title << endl;
    out << "Genre: " << m.genre << endl;
    out << "Duration: " << m.duration << endl;
    out << "Release Date: " << m.releaseDate << endl;
    out << "Director: " << m.director << endl;
    out << "Actors: " << m.actor << endl;
    out << "Country of Origin: " << m.country << endl;
    out << "Description: " << m.description << endl;
    out << "Rating: " << m.rating << endl;
    return out;
}
void Movie::removeMovie()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    int ID;
    cout << "Enter ID's movie that you want to remove: ";
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
std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r"); // Tìm vị trí ký tự không phải khoảng trắng
    size_t end = str.find_last_not_of(" \t\n\r");    // Tìm vị trí ký tự không phải khoảng trắng ở cuối
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
void Movie::readFile(DoubleLinkedList<Movie> &movieList)
{
    ifstream in("../Databases/MovieList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }
    string line;
    Movie m;

    while (getline(in, line))
    {
        // Xử lý ID (dòng bắt đầu bằng '#')
        if (!line.empty() && line[0] == '#')
        {
            m.ID_Movie = stoi(line.substr(1)); // Loại bỏ ký tự '#' và chuyển thành int
        }
        else if (line.find("Title:") == 0)
        {
            m.title = trim(line.substr(6)); // Loại bỏ khoảng trắng thừa ở đầu, cuối
        }
        else if (line.find("Genre:") == 0)
        {
            m.genre = trim(line.substr(6)); // Loại bỏ khoảng trắng thừa ở đầu, cuối
        }
        else if (line.find("Duration:") == 0)
        {
            m.duration = trim(line.substr(9));
        }
        else if (line.find("Release Date:") == 0)
        {
            m.releaseDate = trim(line.substr(13));
        }
        else if (line.find("Director:") == 0)
        {
            m.director = trim(line.substr(9));
        }
        else if (line.find("Actors:") == 0)
        {
            m.actor = trim(line.substr(7));
        }
        else if (line.find("Country of Origin:") == 0)
        {
            m.country = trim(line.substr(18));
        }
        else if (line.find("Description:") == 0)
        {
            m.description = trim(line.substr(12));
        }
        else if (line.find("Rating:") == 0)
        {
            m.rating = trim(line.substr(7));
            movieList.push_back(m);
            m = Movie();
        }
    }
    in.close();
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
    int maxID = countMovie; // Khởi tạo maxID bằng countMovie hiện tại

    while (getline(in, line))
    {
        // Kiểm tra xem dòng có bắt đầu với "#" (ID phim) không
        if (line.substr(0, 1) == "#")
        {
            is_read = true;
            Movie m;
            stringstream ss;
            ss.str(line);
            string idtemp;
            getline(ss, idtemp, ' ');            // Lấy phần ID sau dấu "#"
            m.ID_Movie = stoi(idtemp.substr(1)); // Chuyển đổi ID (cắt bỏ dấu '#')

            // Cập nhật maxID nếu cần
            if (m.ID_Movie > maxID)
            {
                maxID = m.ID_Movie;
            }
        }
    }

    in.close();

    // Cập nhật countMovie bằng ID lớn nhất tìm được
    countMovie = ++maxID; // Tạo ID mới cho bộ phim tiếp theo
}

void Movie::Display()
{

    cout << *this;
    cout << "---------------------------------" << endl;
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
    cout << "Enter the title of the movie you want to search: ";
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
        cout << "No result!" << endl;
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
string *Movie::getTitlePointer()
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
Movie *Movie::selectMovie(int ID)
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
    cout << m->getTitle() << endl;
}
void Movie::selectMovieToBooking()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    for (int i = 0; i < movieList.getSize(); i++)
    {
        cout << movieList[i].ID_Movie << ". " << movieList[i].title << endl;
    }
    cout << "Enter the ID of the movie you want to select: ";
    int ID;
    cin >> ID;
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            *this = movieList[i];
            return;
        }
    }
    cout << "Movie not found." << endl;
}