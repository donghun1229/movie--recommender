#pragma once

#include <vector>
#include <string>
#include "Movie.h"

class MovieManager {
private:
    std::vector<Movie> movies;

public:
    MovieManager();

    void addMovie(const Movie& movie);
    Movie* findByTitle(const std::string& title);
    void sortByRating();
    void printAll() const;
};