// Function to perform merge sort
function mergeSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    // Find the middle point
    const mid = Math.floor(arr.length / 2);

    // Divide the array into two halves
    const leftHalf = arr.slice(0, mid);
    const rightHalf = arr.slice(mid);

    // Recursively sort the two halves and merge them
    return merge(mergeSort(leftHalf), mergeSort(rightHalf));
}

// Function to merge two sorted arrays
function merge(left, right) {
    let sortedArray = [];
    let i = 0, j = 0;

    // Merge elements from both arrays in sorted order
    while (i < left.length && j < right.length) {
        if (left[i] < right[j]) {
            sortedArray.push(left[i]);
            i++;
        } else {
            sortedArray.push(right[j]);
            j++;
        }
    }

    // Concatenate remaining elements (if any) from both arrays
    return sortedArray.concat(left.slice(i)).concat(right.slice(j));
}

// Example usage
const array = [12, 11, 13, 5, 6, 7];
console.log("Original Array:", array);

const sortedArray = mergeSort(array);
console.log("Sorted Array:", sortedArray);
