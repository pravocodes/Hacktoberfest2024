#include <iostream>
#include <vector>

int fibonacci(int n, std::vector<int>& memo) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    
    // Check if value is already computed
    if (memo[n] != -1) {
        return memo[n];
    }

    // Calculate and store the result
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter the position of Fibonacci number to find: ";
    std::cin >> n;

    // Initialize memoization array with -1 (indicating uncomputed values)
    std::vector<int> memo(n + 1, -1);

    // Calculate Fibonacci number
    int result = fibonacci(n, memo);

    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
    return 0;
}
