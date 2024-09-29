#include <iostream>
#include <vector>
#include <algorithm>

//Sorts elements in a range using the default or a custom comparison function.

int main() {
    std::vector<int> numbers = {5, 3, 8, 1, 2};
    
    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());
    
    std::cout << "Sorted numbers: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}


struct User {
    std::string name;
    int age;
};

int main() {
    std::vector<User> users = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 30}, {"David", 25}};
    
    // Stable sort by age
    std::stable_sort(users.begin(), users.end(), [](const User& a, const User& b) {
        return a.age < b.age;
    });
    
    for (const auto& user : users) {
        std::cout << user.name << " (" << user.age << ")" << std::endl;
    }
    return 0;
}