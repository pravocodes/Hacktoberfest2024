def counting_sort(arr, low, high):
    hist = [0] * (high - low + 1)

    for num in arr:
        hist[num - low] += 1

    index = 0
    for i in range(len(hist)):
        for j in range(hist[i]):
            arr[index] = i + low
            index += 1

if __name__ == "__main__":
    arr = [1, 1, 5, 2, 2, 3, 0, 0, -1, 2]

    print("Unsorted array:", arr)

    counting_sort(arr, -1, 5)

    print("Sorted array:", arr)
