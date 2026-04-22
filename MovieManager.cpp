#include "MovieManager.h"
#include <algorithm>
#include <iostream>

MovieManager::MovieManager() {
}

void MovieManager::addMovie(const Movie& movie) {
    for (size_t i=0; i<movies.size(); i++) {
        if (movies[i] == movie) {
            std::cout << "이미 등록된 영화입니다." << std::endl;
            return;
        }
    }
    movies.push_back(movie);
}

Movie* MovieManager::findByTitle(const std::string& title) {
    for (size_t i=0; i<movies.size(); i++) {
        if (movies[i].getTitle() == title) {
            return &movies[i];
        }
    }
    return nullptr;
}

void MovieManager::sortByRating() {
    std::sort(movies.begin(), movies.end());
}

void MovieManager::printAll() const {
    if (movies.empty()) {
        std::cout << "등록된 영화가 없습니다." << std::endl;
        return;
    }

    for (size_t i=0; i<movies.size(); i++) {
        std::cout << movies[i] << std::endl;
    }
}