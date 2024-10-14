# Function to swap two elements
def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

# Partition function to rearrange the array
def partition(arr, low, high):
    pivot = arr[high]  # Pivot element (typically the last element)
    i = low - 1        # Index of the smaller element

    for j in range(low, high):
        # If current element is smaller than or equal to pivot
        if arr[j] <= pivot:
            i += 1
            swap(arr, i, j)  # Swap smaller element with element at i

    swap(arr, i + 1, high)  # Place the pivot in its correct position
    return i + 1            # Return the partition index

# Quick Sort function
def quick_sort(arr, low, high):
    if low < high:
        # pi is the partition index
        pi = partition(arr, low, high)

        # Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Utility function to print an array
def print_array(arr):
    for i in arr:
        print(i, end=" ")
    print()

# Main function to test the quick sort
if __name__ == "__main__":
    arr = [10, 7, 8, 9, 1, 5]
    n = len(arr)

    print("Unsorted array:")
    print_array(arr)

    # Perform Quick Sort
    quick_sort(arr, 0, n - 1)

    print("Sorted array:")
    print_array(arr)
