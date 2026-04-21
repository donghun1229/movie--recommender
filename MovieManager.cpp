#include "MovieManager.h"

MovieManager::MovieManager() {
}

void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
}

Movie* MovieManager::findByTitle(const std::string& title) {
    return nullptr;
}

void MovieManager::sortByRating() {
}

void MovieManager::printAll() const {
}