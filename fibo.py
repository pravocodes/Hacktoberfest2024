# Function to generate Fibonacci series
def fibonacci(n):
    fib_sequence = [0, 1]  # Starting with 0 and 1
    for i in range(2, n):
        next_term = fib_sequence[i - 1] + fib_sequence[i - 2]
        fib_sequence.append(next_term)
    return fib_sequence

# Input from the user
terms = int(input("Enter the number of terms in the Fibonacci series: "))

# Generate and display the Fibonacci series
if terms <= 0:
    print("Please enter a positive integer.")
elif terms == 1:
    print("Fibonacci sequence: [0]")
else:
    fib_sequence = fibonacci(terms)
    print(f"Fibonacci sequence: {fib_sequence}")
