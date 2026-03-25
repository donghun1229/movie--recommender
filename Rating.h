#pragma once
#include <string>

class Rating {
private:
    int userid;
    int movieid;
    double score;
    
public:
    Rating();                    
    Rating(int userid, int movieid, double score);

    int getUserId()             const;
    int getMovieId()            const;
    double getScore()           const;

    void display()               const;
};