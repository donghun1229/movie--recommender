#include <iostream>
#include <string>

#include "Movie.h"
#include "User.h"
#include "MovieManager.h"
#include "UserManager.h"
#include "RatingManager.h"

int main() {
    MovieManager movieManager;
    UserManager userManager;
    RatingManager ratingManager;

    int nextMovieId = 1;
    int nextUserId = 1;

    int choice;

    while (true) {
        std::cout << "\n===== Movie Recommender =====" << std::endl;
        std::cout << "1. 영화 추가" << std::endl;
        std::cout << "2. 영화 검색" << std::endl;
        std::cout << "3. 영화 전체 출력" << std::endl;
        std::cout << "4. 평점순 정렬" << std::endl;
        std::cout << "5. 사용자 추가" << std::endl;
        std::cout << "6. 사용자 전체 출력" << std::endl;
        std::cout << "7. 평점 입력" << std::endl;
        std::cout << "8. 영화별 평점 조회" << std::endl;
        std::cout << "0. 종료" << std::endl;
        std::cout << "선택: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 0) {
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        }

        else if (choice == 1) {
            std::string title;
            std::string genre;
            int year;

            std::cout << "영화 제목: ";
            std::getline(std::cin, title);

            std::cout << "장르: ";
            std::getline(std::cin, genre);

            std::cout << "개봉 연도: ";
            std::cin >> year;
            std::cin.ignore();

            Movie movie(nextMovieId, title, genre, year);
            movieManager.addMovie(movie);
            nextMovieId++;

            std::cout << "영화가 추가되었습니다." << std::endl;
        }

        else if (choice == 2) {
            std::string title;

            std::cout << "검색할 영화 제목: ";
            std::getline(std::cin, title);

            Movie* movie = movieManager.findByTitle(title);

            if (movie == nullptr) {
                std::cout << "영화를 찾을 수 없습니다." << std::endl;
            }
            else {
                movie->display();
            }
        }

        else if (choice == 3) {
            movieManager.printAll();
        }

        else if (choice == 4) {
            movieManager.sortByRating();
            std::cout << "평점순으로 정렬했습니다." << std::endl;
            movieManager.printAll();
        }

        else if (choice == 5) {
            std::string name;

            std::cout << "사용자 이름: ";
            std::getline(std::cin, name);

            User user(nextUserId, name);
            userManager.addUser(user);
            nextUserId++;

            std::cout << "사용자가 추가되었습니다." << std::endl;
        }

        else if (choice == 6) {
            userManager.printAll();
        }

        else if (choice == 7) {
            std::string userName;
            std::string movieTitle;
            double score;

            std::cout << "사용자 이름: ";
            std::getline(std::cin, userName);

            std::cout << "영화 제목: ";
            std::getline(std::cin, movieTitle);

            std::cout << "평점 입력(0~5): ";
            std::cin >> score;
            std::cin.ignore();

            User* user = userManager.findByName(userName);
            Movie* movie = movieManager.findByTitle(movieTitle);

            if (user == nullptr) {
                std::cout << "사용자를 찾을 수 없습니다." << std::endl;
            }
            else if (movie == nullptr) {
                std::cout << "영화를 찾을 수 없습니다." << std::endl;
            }
            else {
                ratingManager.addRating(*user, *movie, score);
            }
        }

        else if (choice == 8) {
            std::string movieTitle;

            std::cout << "평점을 조회할 영화 제목: ";
            std::getline(std::cin, movieTitle);

            Movie* movie = movieManager.findByTitle(movieTitle);

            if (movie == nullptr) {
                std::cout << "영화를 찾을 수 없습니다." << std::endl;
            }
            else {
                ratingManager.printRatingsByMovie(*movie);
            }
        }

        else {
            std::cout << "잘못된 메뉴 번호입니다." << std::endl;
        }
    }

    return 0;
}