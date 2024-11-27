#pragma once
#include "../Include/Movie.h"
#include "../Template/DoubleLinkedList.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
#include "../Include/gotoXY.h"
#include "../Include/layout.h"
#include <cmath>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define _HAS_STD_BYTE 0 //

int Movie::countMovie = 2000;
void forChar(int n, int x, int y, char ch);

void menuEditFilm(Movie &movie)
{
    lineWidth(99, 40, 10, true, true);
    showString("Tên phim: ", 42, 11);
    showString(movie.getTitle(), 52, 11);
    lineWidth(100, 40, 12, false, false);
    showString("Thể loại: ", 42, 13);
    showString(movie.getGenre(), 52, 13);
    lineWidth(100, 40, 14, false, false);
    showString("Thời lượng: ", 42, 15);
    showString(movie.getDuration(), 54, 15);
    lineWidth(100, 40, 16, false, false);
    showString("Ngày phát hành: ", 42, 17);
    showString(movie.getReleaseDate(), 58, 17);
    lineWidth(100, 40, 18, false, false);
    showString("Đạo diễn: ", 42, 19);
    showString(movie.getDirector(), 52, 19);
    lineWidth(100, 40, 20, false, false);
    showString("Diễn viên: ", 42, 21);
    showString(movie.getActor(), 54, 21);
    lineWidth(100, 40, 22, false, false);
    showString("Quốc gia: ", 42, 23);
    showString(movie.getCountry(), 52, 23);
    lineWidth(100, 40, 24, false, false);
    showString("Nội dung: ", 42, 25);
    showString(movie.getDescription(), 54, 25);
    lineWidth(100, 40, 26, false, false);
    showString("Đánh giá: ", 42, 27);
    showString(movie.getRating(), 52, 27);
    lineWidth(99, 40, 28, true, false);
    lineHeight(9, 40, 11, false, false, false);
    lineHeight(9, 140, 11, false, false, false);
    lineHeight(8, 40, 12, true, false, false);
    lineHeight(8, 140, 12, false, true, false);
}
void menuMovie()
{
    lineWidth(99, 40, 10, true, true);
    showString("Tên phim: ", 42, 11);
    lineWidth(100, 40, 12, false, false);
    showString("Thể loại: ", 42, 13);
    lineWidth(100, 40, 14, false, false);
    showString("Thời lượng: ", 42, 15);
    lineWidth(100, 40, 16, false, false);
    showString("Ngày phát hành: ", 42, 17);
    lineWidth(100, 40, 18, false, false);
    showString("Đạo diễn: ", 42, 19);
    lineWidth(100, 40, 20, false, false);
    showString("Diễn viên: ", 42, 21);
    lineWidth(100, 40, 22, false, false);
    showString("Quốc gia: ", 42, 23);
    lineWidth(100, 40, 24, false, false);
    showString("Nội dung: ", 42, 25);
    lineWidth(100, 40, 26, false, false);
    showString("Đánh giá: ", 42, 27);
    lineWidth(99, 40, 28, true, false);
    lineHeight(9, 40, 11, false, false, false);
    lineHeight(9, 140, 11, false, false, false);
    lineHeight(8, 40, 12, true, false, false);
    lineHeight(8, 140, 12, false, true, false);
}
void view_detail_movie(Movie &movie)
{
    gotoXY(40, 10);
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
    this->fileImage = "";
}
int getclick_addMovie()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 40 && x_click <= 140 && y_click >= 10 && y_click <= 12)
    {
        return 1; // ten phim
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 12 && y_click <= 14)
    {
        return 2; // the loai
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 14 && y_click <= 16)
    {
        return 3; // thoi luong
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 16 && y_click <= 18)
    {
        return 4; // ngay phat hanh
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 18 && y_click <= 20)
    {
        return 5; // dao dien
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 20 && y_click <= 22)
    {
        return 6; // dien vien
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 22 && y_click <= 24)
    {
        return 7; // quoc gia
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 24 && y_click <= 26)
    {
        return 8; // noi dung
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 26 && y_click <= 28)
    {
        return 9; // danh gia
    }
    if (x_click >= 90 && x_click <= 105 && y_click >= 30 && y_click <= 32)
    {
        return 10; // luu
    }
    if (x_click >= 120 && x_click <= 135 && y_click >= 30 && y_click <= 32)
    {
        return 11; // huy
    }
    if (x_click >= 130 && x_click <= 131 && y_click > 4 && y_click < 6)
    {
        return 12; // X
    }

    return 0;
}
void Movie::addMovie()
{
    Movie newMovie;
    gotoXY(50, 7);
    cout << "Thêm phim";
    menuMovie();
    lineWidth(15, 90, 30, true, true);
    gotoXY(90, 31);
    cout << "│      LƯU      │";
    lineWidth(15, 90, 32, true, false);
    lineWidth(15, 120, 30, true, true);
    gotoXY(120, 31);
    cout << "│      HỦY      │";
    lineWidth(15, 120, 32, true, false);
    int choice;
    bool run = true;
    while (run)
    {
        int choicee = getclick_addMovie();
        switch (choicee)
        {
        case 1:
            gotoXY(52, 11);
            cout << left << setw(50) << " ";
            getString(newMovie.title, 52, 11);
            break;
        case 2:
            gotoXY(52, 13);
            cout << left << setw(50) << " ";
            getString(newMovie.genre, 52, 13);
            break;
        case 3:
            gotoXY(54, 15);
            cout << left << setw(50) << " ";
            getString(newMovie.duration, 54, 15);
            break;
        case 4:

            gotoXY(58, 17);
            cout << left << setw(50) << " ";
            getString(newMovie.releaseDate, 58, 17);
            break;
        case 5:

            gotoXY(54, 19);
            cout << left << setw(50) << " ";
            getString(newMovie.director, 54, 19);
            break;
        case 6:
            gotoXY(56, 21);
            cout << left << setw(50) << " ";
            getString(newMovie.actor, 56, 21);
            break;
        case 7:
            gotoXY(52, 23);
            cout << left << setw(50) << " ";
            getString(newMovie.country, 52, 23);
            break;
        case 8:
            gotoXY(54, 25);
            cout << left << setw(50) << " ";
            getString(newMovie.description, 54, 25);
            break;
        case 9:
            gotoXY(52, 27);
            cout << left << setw(50) << " ";
            getString(newMovie.rating, 52, 27);
            break;
        case 10:
            newMovie.saveToFile(0);
            gotoXY(130, 30);
            cout << "Thêm thành công";
            this_thread::sleep_for(chrono::seconds(2));
            gotoXY(130, 30);
            cout << "               "; // Clear the success message
            run = false;
            break;
        case 11:
            run = false;
            break;
        }
    }
    gotoXY(130, 5);
    cout << "❌";
    choice = getclick_addMovie();
    while (choice != 12)
    {
        choice = getclick_addMovie();
    }
    system("cls");
}
void Movie::subSaveAgainFile(DoubleLinkedList<Movie> &movieList)
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
        out << "Tên phim: " << movieList[i].title << endl;
        out << "Thể loại: " << movieList[i].genre << endl;
        out << "Thời lượng: " << movieList[i].duration << endl;
        out << "Ngày phát hành: " << movieList[i].releaseDate << endl;
        out << "Đạo diễn: " << movieList[i].director << endl;
        out << "Diễn viên: " << movieList[i].actor << endl;
        out << "Quốc gia: " << movieList[i].country << endl;
        out << "Nội dung: " << movieList[i].description << endl;
        out << "Đánh giá: " << movieList[i].rating << endl;
        out << "File ảnh: " << movieList[i].fileImage << endl;
        out << endl;
    }

    out.close(); // Đóng file sau khi ghi
}
int getClick_editMovie()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    if (x_click >= 40 && x_click <= 140 && y_click >= 10 && y_click <= 12)
    {
        return 1; // ten phim
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 12 && y_click <= 14)
    {
        return 2; // the loai
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 14 && y_click <= 16)
    {
        return 3; // thoi luong
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 16 && y_click <= 18)
    {
        return 4; // ngay phat hanh
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 18 && y_click <= 20)
    {
        return 5; // dao dien
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 20 && y_click <= 22)
    {
        return 6; // dien vien
    }

    if (x_click >= 40 && x_click <= 140 && y_click >= 22 && y_click <= 24)
    {
        return 7; // quoc gia
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 24 && y_click <= 26)
    {
        return 8; // noi dung
    }
    if (x_click >= 40 && x_click <= 140 && y_click >= 26 && y_click <= 28)
    {
        return 9; // danh gia
    }
    if (x_click >= 90 && x_click <= 105 && y_click >= 29 && y_click <= 30)
    {
        return 10; // luu
    }
    if (x_click >= 107 && x_click <= 120 && y_click >= 29 && y_click <= 30)
    {
        return 11; // huy
    }
    if (x_click >= 130 && x_click <= 131 && y_click >= 4 && y_click <= 6)
    {
        return 12; // X
    }
    // id
    if (x_click >= 40 && x_click <= 50 && y_click >= 7 && y_click <= 9)
    {
        return 13;
    }
    return 0;
}
void Movie::editMovie()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    gotoXY(40, 5);
    cout << "Chỉnh sửa phim";
    gotoXY(40, 6);
    cout << "ID: ";
    lineWidth(10, 40, 7, true, true);
    gotoXY(40, 8);
    cout << "│          │";
    lineWidth(10, 40, 9, true, false);
    string str;
    int ID;
    int choice = getClick_editMovie();
    while (choice != 13)
    {
        choice = getClick_editMovie();
    }
    getString(str, 42, 8);
    ID = stoi(str);
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
            lineWidth(27, 90, 29, true, true);
            gotoXY(90, 30);
            cout << "│    LƯU      │     HỦY     │";
            lineWidth(27, 90, 31, true, false);
            showString("┬", 104, 29);
            showString("┴", 104, 31);
            bool run = true;
            while (run)
            {
                int choicee = getClick_editMovie();
                switch (choicee)
                {

                case 1:
                    gotoXY(52, 11);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].title, 52, 11);
                    break;
                case 2:
                    gotoXY(52, 13);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].genre, 52, 13);
                    break;
                case 3:
                    gotoXY(54, 15);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].duration, 54, 15);
                    break;
                case 4:
                    gotoXY(58, 17);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].releaseDate, 58, 17);
                    break;
                case 5:
                    gotoXY(54, 19);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].director, 54, 19);
                    break;
                case 6:
                    gotoXY(56, 21);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].actor, 56, 21);
                    break;
                case 7:
                    gotoXY(52, 23);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].country, 52, 23);
                    break;
                case 8:
                    gotoXY(54, 25);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].description, 54, 25);
                    break;
                case 9:
                    gotoXY(52, 27);
                    cout << left << setw(50) << " ";
                    getString(movieList[i].rating, 52, 27);
                    break;
                case 10:
                    movieList[i].subSaveAgainFile(movieList);
                    gotoXY(130, 30);
                    cout << "Chỉnh sửa thành công";
                    this_thread::sleep_for(chrono::seconds(2));
                    gotoXY(130, 30);
                    cout << "               "; // Clear the success message
                    run = false;
                    break;
                case 11:
                    run = false;
                    break;
                default:

                    break;
                }
            }
        }
    }
    if (find == false)
    {
        gotoXY(40, 10);
        cout << "Không tìm thấy phim!" << endl;
    }
    gotoXY(130, 5);
    cout << "❌";
    choice = getClick_editMovie();
    while (choice != 12)
    {
        choice = getClick_editMovie();
    }
    system("cls");
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
    out << "Tên phim: " << this->title << endl;
    out << "Thể loại: " << this->genre << endl;
    out << "Thời lượng: " << this->duration << endl;
    out << "Ngày phát hành: " << this->releaseDate << endl;
    out << "Đạo diễn: " << this->director << endl;
    out << "Diễn viên: " << this->actor << endl;
    out << "Quốc gia: " << this->country << endl;
    out << "Nội dung: " << this->description << endl;
    out << "Đánh giá: " << this->rating << endl;
    out << "File ảnh: " << this->fileImage << endl;
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
        cout << "│";
}
istream &operator>>(istream &in, Movie &m)
{
    // lineWidth(80,36, 6, true, true);
    // showString("Tên phim: ", 37, 7);
    // lineWidth(82,36, 8, false, false);
    // showString("Thể loại: ", 37, 9);
    // lineWidth(82,36, 10, false, false);
    // showString("Thời lượng: ", 37, 11);
    // lineWidth(82,36, 12, false, false);
    // showString("Ngày phát hành: ", 37, 13);
    // lineWidth(82,36, 14, false, false);
    // showString("Đạo diễn: ", 37, 15);
    // lineWidth(82,36, 16, false, false);
    // showString("Diễn viên: ", 37, 17);
    // lineWidth(82,36, 18, false, false);
    // showString("Quốc gia: ", 37, 19);
    // lineWidth(82,36, 20, false, false);
    // showString("Nội dung: ", 37, 21);
    // lineWidth(82,36, 22, false, false);
    // showString("Đánh giá: ", 37, 23);
    // lineWidth(80,36, 24, true, false);
    // gotoXY(37, 8);
}
ostream &operator<<(ostream &out, const Movie &m)
{
    out << "ID: " << m.ID_Movie << endl;
    out << "Tên phim: " << m.title << endl;
    out << "Thể loại: " << m.genre << endl;
    out << "Thời lượng: " << m.duration << endl;
    out << "Ngày phát hành: " << m.releaseDate << endl;
    out << "Đạo diễn: " << m.director << endl;
    out << "Diễn viên: " << m.actor << endl;
    out << "Quốc gia: " << m.country << endl;
    out << "Nội dung: " << m.description << endl;
    out << "Đánh giá: " << m.rating << endl;
    return out;
}

void Movie::removeMovie()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    bool find = false;
    int ID;
    gotoXY(40, 5);
    cout << "Xóa phim";
    gotoXY(40, 6);
    cout << "ID: ";
    lineWidth(10, 40, 7, true, true);
    gotoXY(40, 8);
    cout << "│         │";
    lineWidth(10, 40, 9, true, false);
    string str;
    int choice = getClick_editMovie();
    while (choice != 13)
    {
        choice = getClick_editMovie();
    }
    getString(str, 42, 8);
    ID = stoi(str);
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            find = true;
            menuEditFilm(movieList[i]);
            gotoXY(40, 30);
            cout << "Bạn có muốn xóa phim này không?";
            lineWidth(10, 40, 31, true, true);
            gotoXY(40, 32);
            cout << "│    Yes   │";
            lineWidth(10, 40, 33, true, false);
            lineWidth(10, 60, 31, true, true);
            gotoXY(60, 32);
            cout << "│    No    │";
            lineWidth(10, 60, 33, true, false);

            int choice = 0;
            while (choice != 1 && choice != 2)
            {
                click = processInputEvents();
                x_click = click.X;
                y_click = click.Y;
                if (x_click >= 40 && x_click <= 50 && y_click >= 31 && y_click <= 33)
                {
                    choice = 1; // Yes
                }
                else if (x_click >= 60 && x_click <= 70 && y_click >= 31 && y_click <= 33)
                {
                    choice = 2; // No
                }
            }

            if (choice == 1)
            {
                movieList.earse(i);
                gotoXY(130, 4);
                cout << "Xóa thành công!!";
                this_thread::sleep_for(chrono::seconds(2));
                gotoXY(130, 4);
                cout << "               "; // Clear the success message
                break;
            }
            else
            {
                break;
            }
        }
    }
    if (!find)
    {
        gotoXY(50, 10);
        cout << "Không tìm thấy phim!!";
    }
    subSaveAgainFile(movieList);
    gotoXY(130, 5);
    cout << "❌";
    choice = getClick_editMovie();
    while (choice != 12)
    {
        choice = getClick_editMovie();
    }
    system("cls");
}
bool is_whitespace_utf8(char c)
{
    return std::isspace(static_cast<unsigned char>(c));
}

std::string trim(const std::string &str)
{
    size_t start = 0;
    size_t end = str.size();

    // Loại bỏ khoảng trắng từ đầu chuỗi
    while (start < str.size() && is_whitespace_utf8(str[start]))
    {
        ++start;
    }

    // Loại bỏ khoảng trắng từ cuối chuỗi
    while (end > start && is_whitespace_utf8(str[end - 1]))
    {
        --end;
    }

    return str.substr(start, end - start);
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
        else if (line.find("Tên phim: ") == 0)
        {
            m.title = trim(line.substr(11)); // Loại bỏ khoảng trắng thừa ở đầu, cuối
        }
        else if (line.find("Thể loại: ") == 0)
        {
            m.genre = trim(line.substr(13)); // Loại bỏ khoảng trắng thừa ở đầu, cuối
        }
        else if (line.find("Thời lượng: ") == 0)
        {
            m.duration = trim(line.substr(16));
        }
        else if (line.find("Ngày phát hành: ") == 0)
        {
            m.releaseDate = trim(line.substr(19));
        }
        else if (line.find("Đạo diễn: ") == 0)
        {
            m.director = trim(line.substr(14));
        }
        else if (line.find("Diễn viên: ") == 0)
        {
            m.actor = trim(line.substr(14));
        }
        else if (line.find("Quốc gia: ") == 0)
        {
            m.country = trim(line.substr(12));
        }
        else if (line.find("Nội dung: ") == 0)
        {
            m.description = trim(line.substr(12));
        }
        else if (line.find("Đánh giá: ") == 0)
        {
            m.rating = trim(line.substr(13));
        }
        else if (line.find("File ảnh: ") == 0)
        {
            m.fileImage = trim(line.substr(12));
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
void printBox(string label, string content, int x, int y, int maxWidth = 40)
{
    // int startX = x + label.length() + 1;
    // int contentWidth = content.length();
    // int boxWidth = min(contentWidth + 4, maxWidth); // Đảm bảo khung không vượt quá maxWidth
    // string displayContent = content;

    // // Nếu nội dung vượt quá maxWidth - 4, cắt bớt và thêm "..."
    // if (contentWidth > maxWidth - 4)
    // {
    //     displayContent = content.substr(0, maxWidth - 7) + "...";
    //     contentWidth = displayContent.length();
    // }

    // // In khung
    // gotoXY(startX, y); // Góc trên bên trái của khung
    // cout << "╭" << string(boxWidth - 2, '─') << "╮";
    // gotoXY(startX, y + 1);
    // cout << "│ " << left << setw(boxWidth - 4) << displayContent << "   │";
    // gotoXY(startX, y + 2);
    // cout << "╰" << string(boxWidth - 2, '─') << "╯";

    // // In nhãn (label) tại vị trí thẳng hàng với nội dung
    // int labelPosition = x + 2; // Vị trí bắt đầu của nội dung trong khung
    // gotoXY(x, y + 1);
    // cout << label;

    lineWidth(40, x, y, true, true);
    gotoXY(x + 2, y + 1);
    cout << content;
    lineWidth(40, x, y + 2, true, false);
    lineHeight(1, x, y + 1, false, false, false);
    lineHeight(1, x + 41, y + 1, false, false, false);
}
void printFormattedText(const string &text, int maxLineLength, int x, int y)
{
    istringstream stream(text); // Chuyển chuỗi thành một stream
    string word;
    string line;

    while (stream >> word)
    {
        // Kiểm tra nếu việc thêm từ vào dòng hiện tại sẽ vượt quá giới hạn dòng
        if (line.length() + word.length() + 1 > maxLineLength)
        {
            gotoXY(x, y);
            cout << line;
            line = word;
            y++;
            // Khởi tạo dòng mới với từ hiện tại
        }
        else
        {
            // Nếu không, thêm từ vào dòng hiện tại
            if (!line.empty())
            {
                line += " "; // Thêm khoảng trắng giữa các từ
            }
            line += word;
        }
    }

    // In dòng cuối cùng (nếu có)
    if (!line.empty())

    {
        gotoXY(x, y);
        cout << line;
    }
}
void Movie::showCurrentMovie()
{
    gotoXY(100, 5);
    cout << "*PHIM ĐANG CHIẾU*";
    string line;
    fstream in;
    int x;
    in.open("../Databases/" + this->fileImage);
    if (!in)
    {
        cerr << "Không thể mở file ASCII" << endl;
    }
    int startX = 95, startY = 7;
    int currentY = startY;
    while (getline(in, line))
    {
        x = line.length();
        gotoXY(startX, currentY);
        cout << line << endl;
        currentY++;
    }
    x = x + startX + 4;
    in.close();
    gotoXY(100, currentY + 1);
    cout << "*" << "\033[1;31m" << this->title << "\033[0m" << "*";
    gotoXY(115, currentY + 3);
    cout << "+--------------------+";
    gotoXY(115, currentY + 4);
    cout << "│       MUA VÉ!!     │";
    gotoXY(115, currentY + 5);
    cout << "+--------------------+";
}
void Movie::showDetailMovie()
{
    string line;
    fstream in;
    int x = 35;
    in.open("../Databases/" + this->fileImage);
    if (!in)
    {
        cerr << "Không thể mở file ASCII" << endl;
    }
    int startX = 34, startY = 6;
    int currentY = startY;
    while (getline(in, line))
    {
        x = line.length();
        gotoXY(startX, currentY);
        cout << line << endl;
        currentY++;
    }
    x = x + startX + 4;
    in.close();
    int a;
    int pos = this->rating.find("/");
    string temp1 = this->rating.substr(0, pos);
    a = stod(temp1);

    gotoXY(x, 8);
    cout << "*" << "\033[1;31m" << this->title << "\033[0m" << "*";
    gotoXY(x, 10);
    cout << "⏳" + this->duration;
    gotoXY(x, 12);
    // cout << "\033[33m" << this->rating << "\033[0m";
    for (int i = 0; i < a; i++)
    {
        cout << "★";
    }
    for (int j = a; j < 5; j++)
    {
        cout << "☆";
    }

    gotoXY(x, 14);
    cout << "Quốc gia: " << this->country;
    printBox("Thể loại: ", this->genre, x, 16);
    printBox("Đạo diễn: ", this->director, x, 19);

    printBox("Diễn viên: ", this->actor, x, 22);

    gotoXY(35, currentY + 3);
    cout << "*Nội dung: ";
    // gotoXY(6, startY + 4);
    printFormattedText(this->description, 50, 35, currentY + 4);
}
void Movie::show(DoubleLinkedList<Movie> &movieList, int currentPage, int moviesPerPage, int k)
{

    for (int i = movieList.getSize() - 1; i >= 0; i--)
    {
        movieList.earse(i);
    }
    this->readFile(movieList);
    if (k)
    {
        this->sort_rating(movieList);
    }
    int totalPage = ceil((double)movieList.getSize() / moviesPerPage);
    int start = (currentPage - 1) * moviesPerPage;
    int end = min(start + moviesPerPage, movieList.getSize());
    showString("Danh sách phim", 40, 6);
    lineWidth(115, 35, 8, true, true);
    showString("┬", 39, 8);
    showString("┬", 46, 8);
    showString("┬", 81, 8);
    showString("┬", 116, 8);
    showString("┬", 131, 8);
    showString("┬", 141, 8);
    showString("STT", 36, 9);
    showString("ID", 40, 9);
    showString("Tên phim", 50, 9);
    showString("Thể loại", 87, 9);
    showString("Thời lượng", 118, 9);
    showString("Quốc gia", 133, 9);
    showString("Đánh giá", 142, 9);

    int x = 10;
    for (int i = start; i < end; i++)
    {
        lineWidth(117, 35, x + i - start, false, false);

        gotoXY(37, ++x + i - start);
        cout << i + 1;
        gotoXY(41, x + i - start);
        cout << movieList[i].ID_Movie;
        gotoXY(47, x + i - start);
        cout << movieList[i].title;
        gotoXY(82, x + i - start);
        cout << movieList[i].genre;
        gotoXY(118, x + i - start);
        cout << movieList[i].duration;
        gotoXY(132, x + i - start);
        cout << movieList[i].country;
        gotoXY(144, x + i - start);
        cout << movieList[i].rating;
    }
    lineWidth(115, 35, x + end - start, true, false);
    showString("┴", 39, x + end - start);
    showString("┴", 46, x + end - start);
    showString("┴", 81, x + end - start);
    showString("┴", 116, x + end - start);
    showString("┴", 131, x + end - start);
    showString("┴", 141, x + end - start);
    lineHeight(end - start + 1, 35, 9, false, false, false);
    lineHeight(end - start + 1, 39, 9, false, false, false);
    lineHeight(end - start + 1, 46, 9, false, false, false);
    lineHeight(end - start + 1, 81, 9, false, false, false);
    lineHeight(end - start + 1, 116, 9, false, false, false);
    lineHeight(end - start + 1, 131, 9, false, false, false);
    lineHeight(end - start + 1, 141, 9, false, false, false);
    lineHeight(end - start + 1, 151, 9, false, false, false);
    lineHeight(end - start, 35, 10, true, false, false);
    lineHeight(end - start, 39, 10, false, false, true);
    lineHeight(end - start, 46, 10, false, false, true);
    lineHeight(end - start, 81, 10, false, false, true);
    lineHeight(end - start, 116, 10, false, false, true);
    lineHeight(end - start, 131, 10, false, false, true);
    lineHeight(end - start, 141, 10, false, false, true);
    lineHeight(end - start, 151, 10, false, true, false);
}
std::string toLowerCase(const std::string &input)
{
    std::string result;
    for (size_t i = 0; i < input.size();)
    {
        unsigned char c = input[i];

        // Xử lý ký tự ASCII (1 byte)
        if ((c & 0x80) == 0)
        {
            result += std::tolower(c); // Chuyển thường
            i++;
        }
        // Xử lý ký tự tiếng Việt (UTF-8, 2 bytes)
        else if ((c & 0xE0) == 0xC0 && i + 1 < input.size())
        {
            unsigned char c2 = input[i + 1];

            // Chuyển đổi thủ công cho một số ký tự viết hoa tiếng Việt
            if (c == 0xC4 && c2 == 0x90) // 'Đ' => 'đ'
            {
                result += '\xC4';
                result += '\x91';
            }
            else if (c == 0xC3 && c2 >= 0x80 && c2 <= 0x9E) // Xử lý 'Á', 'É', 'Ì',...
            {
                result += c;
                result += c2 + 0x20; // Chuyển thường bằng cách tăng offset
            }
            else
            {
                result += c;
                result += c2; // Giữ nguyên nếu không xử lý được
            }
            i += 2;
        }
        else
        {
            result += c; // Giữ nguyên ký tự khác
            i++;
        }
    }
    return result;
}
int getClick_search()
{
    click = processInputEvents();
    x_click = click.X;
    y_click = click.Y;
    // dat ve
    if (x_click >= 120 && x_click <= 138 && y_click >= 30 && y_click <= 32)
    {
        return 1;
    }
    if (x_click >= 130 && x_click <= 131 && y_click >= 4 && y_click <= 6)
    {
        return 2;
    }
}
void Movie::searchMovie(string &line)
{

    bool found = false;
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    line = toLowerCase(line);
    line = trim(line);
    for (int i = 0; i < movieList.getSize(); i++)
    {

        if (toLowerCase(movieList[i].title) == line)
        {
            gotoXY(40, 4);
            cout << "                     ";
            gotoXY(40, 5);
            cout << "                                                           ";
            gotoXY(40, 6);
            cout << "                                                           ";
            gotoXY(40, 7);
            cout << "                                                           ";
            found = true;
            movieList[i].showDetailMovie();
            lineWidth(18, 120, 30, true, true);
            gotoXY(120, 31);
            cout << "│      Đặt vé      │";
            lineWidth(18, 120, 32, true, false);
            break;
        }
    }
    if (!found)
    {
        gotoXY(50, 10);
        cout << "Không tìm thấy kết quả!" << endl;
    }
    else
    {
        int choice = getClick_search();
        if (choice == 1)
        {
            gotoXY(120, 31);
            cout << "Đặt vé thành công!";
        }
    }
    gotoXY(130, 5);
    cout << "❌";
    int choice = getClick_search();
    while (choice != 2)
    {
        choice = getClick_search();
    }
    system("cls");
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
void Movie::selectMovieToBooking(DoubleLinkedList<Movie> &movieList)
{
    for (int i = 0; i < movieList.getSize(); i++)
    {
        cout << movieList[i].ID_Movie << ". " << movieList[i].title << endl;
    }
    cout << "Nhập ID phim bạn muốn chọn: ";
    int ID;
    cin >> ID;
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            *this = movieList[i];
            cout << "Phim đã đặt: " << this->title << endl;
            return;
        }
    }
    cout << "Không tìm thấy phim." << endl;
}
void Movie::sort_rating(DoubleLinkedList<Movie> &movieList)
{

    // this->readFile(movieList);
    double a, b;
    string temp1, temp2;
    for (int i = 0; i < movieList.getSize(); i++)
    {
        int pos = movieList[i].rating.find("/");
        temp1 = movieList[i].rating.substr(0, pos);
        a = stod(temp1);
        for (int j = i + 1; j < movieList.getSize(); j++)
        {
            int pos = movieList[j].rating.find("/");
            temp2 = movieList[j].rating.substr(0, pos);
            b = stod(temp2);
            if (a < b)
            {
                Movie temp = movieList[i];
                movieList[i] = movieList[j];
                movieList[j] = temp;
            }
        }
    }
    // subSaveAgainFile(movieList);
}