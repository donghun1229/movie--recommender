#pragma once

#include <vector>
#include "Rating.h"
#include "Movie.h"
#include "User.h"

class RatingManager {
private:
    std::vector<Rating> ratings;

public:
    RatingManager();

    void addRating(const User& user, Movie& movie, double score);
    void printRatingsByMovie(const Movie& movie) const;
};