#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>

// Part 1: Sorts elements in a range using the default or a custom comparison function.
void sortNumbers() {
    // Initialize the vector using push_back
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(8);
    numbers.push_back(1);
    numbers.push_back(2);

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Print sorted numbers
    std::cout << "Sorted numbers: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

// User struct definition
struct User {
    std::string name;
    int age;
};

void sortUsers() {
    // Initialize the users vector using push_back
    std::vector<User> users;
    users.push_back(User("Alice", 30));    // Using constructor
    users.push_back(User("Bob", 25));      // Using constructor
    users.push_back(User("Charlie", 30));  // Using constructor
    users.push_back(User("David", 25));    // Using constructor

    // Stable sort by age using a lambda function
    std::stable_sort(users.begin(), users.end(), [](const User& a, const User& b) {
        return a.age < b.age;
    });

    // Print sorted users
    for (size_t i = 0; i < users.size(); ++i) {
        std::cout << users[i].name << " (" << users[i].age << ")" << std::endl;
    }
}

// Part 3: Adding binary search
class BinarySearch {
public:
    BinarySearch(std::vector<int> v) : data(std::move(v)) {}

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
    return std::unique_ptr<BinarySearch>(new BinarySearch(std::move(v)));
}

// Function to handle errors during binary search
void handleSearchError(int target) {
    try {
        // Initialize the vector using push_back
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);
        vec.push_back(7);
        vec.push_back(8);
        vec.push_back(9);
        vec.push_back(10);
        
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
