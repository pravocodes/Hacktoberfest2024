#include <iostream>
#include <vector>
#include <string>

class User {
private:
    int id;
    std::string name;

public:
    User(int id, const std::string& name) : id(id), name(name) {}

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }
};

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& user) {
        users.push_back(user);
        std::cout << "User added: " << user.getName() << std::endl;
    }

    void listUsers() const {
        std::cout << "List of users:" << std::endl;
        for (const auto& user : users) {
            std::cout << "ID: " << user.getId() << ", Name: " << user.getName() << std::endl;
        }
    }
};

int main() {
    UserManager userManager;

    User user1(1, "Alice");
    User user2(2, "Bob");

    userManager.addUser(user1);
    userManager.addUser(user2);

    userManager.listUsers();

    return 0;
}
