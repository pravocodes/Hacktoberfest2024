#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>

// Part 1: Sorts elements in a range using the default or a custom comparison function.
void sortNumbers() {
    // Initialize the vector using an initializer list
    std::vector<int> numbers = {5, 3, 8, 1, 2};

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Print sorted numbers
    std::cout << "Sorted numbers: ";
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// User struct definition
struct User {
    std::string name;
    int age;

    User(const std::string& name, int age) : name(name), age(age) {}
};

void sortUsers() {
    // Initialize the users vector using an initializer list
    std::vector<User> users = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 30}, {"David", 25}};

    // Stable sort by age using a lambda function
    std::stable_sort(users.begin(), users.end(), [](const User& a, const User& b) {
        return a.age < b.age;
    });

    // Print sorted users
    std::cout << "Sorted users by age:" << std::endl;
    for (const User& user : users) {
        std::cout << user.name << " (" << user.age << ")" << std::endl;
    }
}

// Part 3: Adding binary search
class BinarySearch {
public:
    explicit BinarySearch(std::vector<int> v) : data(std::move(v)) {}

    int search(int target) const {
        int left = 0;
        int right = data.size() - 1;

        // Perform binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid] == target) {
                return mid; // Target found
            } else if (data[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        throw std::runtime_error("Element not found!"); // Throw error if target not found
    }

private:
    std::vector<int> data; // Sorted data for searching
};

// Function to create a BinarySearch object using a smart pointer
std::unique_ptr<BinarySearch> createBinarySearch(std::vector<int> v) {
    return std::make_unique<BinarySearch>(std::move(v));
}

class TernarySearch {
public:
    explicit TernarySearch(std::vector<int> v) : data(std::move(v)) {}

    int search(int target) const {
        int left = 0;
        int right = data.size() - 1;

        // Perform ternary search
        while (left <= right) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            if (data[mid1] == target) {
                return mid1; // Target found
            } else if (data[mid2] == target) {
                return mid2; // Target found
            } else if (data[mid1] > target) {
                right = mid1 - 1; // Search in the left third
            } else if (data[mid2] < target) {
                left = mid2 + 1; // Search in the right third
            } else {
                left = mid1 + 1;
                right = mid2 - 1; // Search in the middle third
            }
        }
        throw std::runtime_error("Element not found!"); // Throw error if target not found
    }

private:
    std::vector<int> data; // Sorted data for searching
};

// Function to create a TernarySearch object using a smart pointer
std::unique_ptr<TernarySearch> createTernarySearch(std::vector<int> v) {
    return std::make_unique<TernarySearch>(std::move(v));
}

// Function to handle errors during binary search
void handleSearchError(int target) {
    try {
        // Initialize the vector using an initializer list
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        // Create a BinarySearch object
        std::unique_ptr<BinarySearch> binarySearch = createBinarySearch(vec);
        int result = binarySearch->search(target);
        std::cout << "Element " << target << " found at index: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl; // Handle error
    }
}

int main() {
    // Execute sorting and searching functions
    sortNumbers();
    sortUsers();

    int target = 7;
    handleSearchError(target); // Successful search

    target = 15;
    handleSearchError(target); // This will throw an error as 15 is not in the list

    return 0;
}
