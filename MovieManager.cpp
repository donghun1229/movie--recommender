#include "MovieManager.h"

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
}

void MovieManager::printAll() const {
}