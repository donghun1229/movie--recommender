#include "Movie.h"
 
Movie::Movie(string t, string g,
    string d, int y, double r) {
    title = t; genre = g;
    director = d; year = y;
    setRating(r); // setter로 검증!
}
 
void Movie::display() {
    cout << title << " (" << year
         << ") [" << genre << "] "
         << "평점: " << rating << endl;
}
 
void Movie::setRating(double r) {
    if (r < 0.0) r = 0.0;
    if (r > 5.0) r = 5.0;
    rating = r;
}

string Movie::getTitle() {return title;}
double Movie::getRating() {return rating;}
int Movie::getYear() {return year;}