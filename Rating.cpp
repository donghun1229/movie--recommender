#include "Rating.h"
#include <iostream>

Rating::Rating()
    : userid(0), movieid(0), score(0.0) {}
      
Rating::Rating(int userid, int movieid, double s)
    : userid(userid), movieid(movieid), score(0.0) {
    if (s >= 0.0 && s <= 5.0) {
        score=s;
    }
}

int Rating::getUserId()            const { return userid;}
int Rating::getMovieId()           const { return movieid;}
double Rating::getScore()          const { return score;}

void Rating::display() const {           
    std::cout << "User ID:" << userid
              << ", Movie ID: " << movieid
              << ", Score: " << score
              << std::endl;
}