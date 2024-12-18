/*
Binary Search is a searching algorithm used to find the position of a target element in a sorted array. It works by repeatedly dividing the search interval in half and comparing the middle element with the target.

1. Compare the target with the middle element.
2. If the target matches, return its position.
3. If the target is smaller, narrow the interval to the left half.
4. If the target is larger, narrow the interval to the right half.
5. Repeat until the target is found or the interval is empty.
*/

// C program for implementation of Binary Search
#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is smaller, search the left half
        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            // If the target is larger, search the right half
            low = mid + 1;
        }
    }

    // Target not found
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    printf("Array: ");
    printArray(arr, n);

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element %d is present at index %d\n", target, result);
    } else {
        printf("Element %d is not present in the array\n", target);
    }

    return 0;
}

/*
Complexity Analysis of Binary Search
Time Complexity:
- Best Case: O(1), when the middle element is the target.
- Average and Worst Case: O(log n), as the search space is halved in each step.

Auxiliary Space: O(1) for the iterative implementation.
*/
/*
Advantages of Binary Search
1. Much faster than linear search for sorted datasets.
2. Simple to implement and highly efficient for large datasets.
3. Requires minimal memory (O(1) space in iterative form).
*/
/*
Disadvantages of Binary Search
1. Requires the array to be sorted beforehand.
2. Not suitable for linked lists due to the lack of random access.
3. Inefficient for small datasets compared to simpler algorithms like linear search.
*/
/*
Applications of Binary Search
1. Used in searching operations in sorted arrays and lists.
2. Basis for many algorithms like lower bound, upper bound, and binary search trees.
3. Applied in problems like finding square roots, searching in rotated arrays, and more.
*/
/*
Frequently Asked Questions (FAQs) on Binary Search

Question 1: Is Binary Search a stable searching algorithm?
Answer: Stability is not applicable to searching algorithms as it pertains to sorting algorithms.

Question 2: What is the time complexity of Binary Search?
Answer: Binary Search has a time complexity of O(log n).

Question 3: Does Binary Search require extra memory?
Answer: No, the iterative version of Binary Search requires O(1) additional space.

Question 4: When is it best to use Binary Search?
Answer: Binary Search is best used when the dataset is sorted, and efficient searching is required.
*/
