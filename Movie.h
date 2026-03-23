#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
using namespace std;
 
class Movie {
private:
    string title;
    string genre;
    string director;
    int year;
    double rating;   // 0.0 ~ 5.0
public:
    // 생성자
    Movie(string t, string g, string d,
          int y, double r);
    // 정보 출력
    void display();
    // Getters
    string getTitle();
    double getRating();
    int getYear();
    // Setter (유효성 검사)
    void setRating(double r);
};
#endif