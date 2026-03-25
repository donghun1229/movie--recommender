#include "Movie.h"
#include "User.h"
#include "Rating.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Movie> movies;
    std::vector<User> users;
    std::vector<Rating> ratings;

    movies.push_back(Movie(1, "기생충", "드라마", 2019));
    movies.push_back(Movie(2, "인터스텔라", "SF", 2014));

    users.push_back(User(1, "강동헌", "greatkdh107@gmail.com"));
    users.push_back(User(2, "이동헌", "greatldh107@gmail.com"));

    ratings.push_back(Rating(1, 1, 4.8));
    ratings.push_back(Rating(2, 1, 5.0));
    ratings.push_back(Rating(1, 2, 4.9));
    ratings.push_back(Rating(1, 2, 3.7));

    for (int i=0; i<ratings.size(); i++) {
        int movieid=ratings[i].getMovieId();
        double score=ratings[i].getScore();
    
        for (int j=0; j<movies.size(); j++) {
            if (movies[j].getId()==movieid) {
                movies[j].addRating(score);
            }
        }
    }

    std::cout << "===Movie Information ==="  << std::endl;
    for (int i=0; i<movies.size(); i++) {
        movies[i].display();
    }

    std::cout << std::endl;

    std::cout << "===User Information ==="  << std::endl;
    for (int i=0; i<users.size(); i++) {
        users[i].display();
    }

    std::cout << std::endl;

    std::cout << "===Rating Information ==="  << std::endl;
    for (int i=0; i<ratings.size(); i++) {
        ratings[i].display();
    }

    std::cout << std::endl;

    for (int i=0; i<movies.size(); i++) {
        std::cout << movies[i].getTitle() << "평균 평점: "
                  << movies[i].getAverageRating() << std::endl;
    }

    return 0;
}