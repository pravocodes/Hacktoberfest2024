#include <iostream>
using namespace std;

class arr_stack {
private:
    int capacity, top, *ptr;

public:
    arr_stack(); // Constructor
    void createstack(int cap); // Create stack with a given capacity
    void push(int data); // Push data onto the stack
    int peek(); // Get the top element
    bool isfull(); // Check if stack is full
    bool isempty(); // Check if stack is empty
    void pop(); // Remove the top element
    void display(); // Display all stack elements
    ~arr_stack(); // Destructor
};

// Constructor initializes the stack
arr_stack::arr_stack() {
    ptr = nullptr; // Initialize pointer to null
    capacity = 0;  // Initialize capacity
    top = -1;      // Initialize top index
}

// Create stack with a given capacity
void arr_stack::createstack(int cap) {
    if (cap <= 0) { // Check for valid capacity
        cout << "Capacity must be greater than 0." << endl;
        return;
    }

    capacity = cap; // Set capacity
    top = -1;       // Reset top index

    // Free any existing memory before allocating new
    delete[] ptr; 
    ptr = new int[capacity]; // Allocate new array for stack
}

// Check if the stack is full
bool arr_stack::isfull() {
    return (top == capacity - 1); // Adjusted to check for capacity correctly
}

// Check if the stack is empty
bool arr_stack::isempty() {
    return (top == -1); // Check if no elements are in the stack
}

// Push data onto the stack
void arr_stack::push(int data) {
    if (isfull()) { // Use isfull() to check
        cout << "OVERFLOW: Stack is full!" << endl; // More descriptive error message
    } else {
        ptr[++top] = data; // Increment top and assign data
    }
}

// Peek at the top element of the stack
int arr_stack::peek() {
    if (isempty()) { // Check if stack is empty
        cout << "UNDERFLOW: Stack is empty!" << endl; // More descriptive error message
        return -1; // Return a sentinel value
    }
    return ptr[top]; // Return top element
}

// Remove the top element from the stack
void arr_stack::pop() {
    if (isempty()) { // Check if stack is empty
        cout << "UNDERFLOW: Stack is empty!" << endl; // More descriptive error message
    } else {
        top--; // Decrement top index
    }
}

// Display all elements in the stack
void arr_stack::display() {
    if (isempty()) { // Check if stack is empty
        cout << "Stack is empty!" << endl; // Inform user
        return;
    }
    for (int i = 0; i <= top; i++) {
        cout << ptr[i] << " "; // Print each element
    }
    cout << endl; // New line after display
}

// Destructor to free allocated memory
arr_stack::~arr_stack() {
    delete[] ptr; // Use delete[] for array
}

// Main function to interact with the stack
int main() {
    arr_stack a; // Create stack instance
    int choice;

    while (true) { // Infinite loop until exit
        cout << "--*MENU*---" << endl;
        cout << "1. Create array" << endl;
        cout << "2. PUSH" << endl;
        cout << "3. POP" << endl;
        cout << "4. PEEK" << endl;
        cout << "5. Display" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int cap;
                cout << "Enter capacity: ";
                cin >> cap;
                a.createstack(cap); // Create stack with user-defined capacity
                break;
            }
            case 2: {
                int data;
                cout << "Enter data: ";
                cin >> data;
                a.push(data); // Push data onto the stack
                break;
            }
            case 3:
                a.pop(); // Pop top element
                break;
            case 4: {
                int save = a.peek(); // Peek at top element
                if (save != -1) { // Check if peek was successful
                    cout << "Top element: " << save << endl;
                }
                break;
            }
            case 5:
                a.display(); // Display all elements
                break;
            case 6:
                return 0; // Exit the program
            default:
                cout << "WRONG CHOICE" << endl; // Invalid choice
        }
    }
}
