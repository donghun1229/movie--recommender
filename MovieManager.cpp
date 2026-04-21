#include "MovieManager.h"
#include <algorithm>
#include <iostream>

MovieManager::MovieManager() {
}

void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
}

Movie* MovieManager::findByTitle(const std::string& title) {
    for (int i=0; i<movies.size(); i++) {
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

    for (int i=0; i<movies.size(); i++) {
        movies[i].display();
    }
}