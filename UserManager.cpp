#include "UserManager.h"
#include <iostream>

UserManager::UserManager() {
}

void UserManager::addUser(const User& user) {
    users.push_back(user);
}

User* UserManager::findByName(const std::string& name) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getName() == name) {
            return &users[i];
        }
    }

    return nullptr;
}

void UserManager::printAll() const {
    if (users.empty()) {
        std::cout << "등록된 사용자가 없습니다." << std::endl;
        return;
    }

    for (size_t i = 0; i < users.size(); i++) {
        users[i].display();
    }
}