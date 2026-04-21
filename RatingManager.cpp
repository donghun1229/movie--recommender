#include "RatingManager.h"
#include <iostream>

RatingManager::RatingManager() {
}

void RatingManager::addRating(const User& user, Movie& movie, double score) {
    if (score < 0.0 || score > 5.0) {
        std::cout << "평점은 0점 이상 5점 이하만 입력할 수 있습니다." << std::endl;
        return;
    }

    Rating rating(user.getId(), movie.getId(), score);
    ratings.push_back(rating);

    movie.addRating(score);

    std::cout << "평점이 등록되었습니다." << std::endl;
}

void RatingManager::printRatingsByMovie(const Movie& movie) const {
    bool found = false;

    std::cout << "[" << movie.getTitle() << " 평점 목록]" << std::endl;

    for (int i = 0; i < ratings.size(); i++) {
        if (ratings[i].getMovieId() == movie.getId()) {
            std::cout << "평점: " << ratings[i].getScore() << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "등록된 평점이 없습니다." << std::endl;
    }

    std::cout << "평균 평점: " << movie.getAverageRating() << std::endl;
}