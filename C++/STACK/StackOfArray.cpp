#include <array>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Define the type of array
    typedef array<int, 3> ArrayType;

    // Initialize two arrays
    ArrayType array1 = { 1, 2, 3 };
    ArrayType array2 = { 4, 5, 6 };

    // Create a stack of arrays
    stack<ArrayType> myStack;
    myStack.push(array1);
    myStack.push(array2);

    // Print the stack of arrays
    while (!myStack.empty()) {
        ArrayType& topArray = myStack.top();
        for (int i : topArray) {
            cout << i << " ";
        }
        cout << endl;
        myStack.pop();
    }

    return 0;
}
