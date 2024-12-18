/*
Linear Search is a simple searching algorithm that checks each element in an array sequentially until the target element is found or the end of the array is reached.

1. Start from the first element of the array.
2. Compare each element with the target.
3. If a match is found, return the index of the element.
4. If the end of the array is reached without finding the target, return -1.
*/

// C program for implementation of Linear Search
#include <stdio.h>

// Function to perform Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 23, 45, 70, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 70;

    printf("Array: ");
    printArray(arr, n);

    int result = linearSearch(arr, n, target);
    if (result != -1) {
        printf("Element %d is present at index %d\n", target, result);
    } else {
        printf("Element %d is not present in the array\n", target);
    }

    return 0;
}

/*
Complexity Analysis of Linear Search
Time Complexity:
- Best Case: O(1), when the target is found at the first position.
- Average and Worst Case: O(n), when the target is near the end or not present.

Auxiliary Space: O(1) as no extra space is required.
*/
/*
Advantages of Linear Search
1. Simple and easy to implement.
2. Does not require the array to be sorted.
3. Works well for small datasets.
*/
/*
Disadvantages of Linear Search
1. Inefficient for large datasets as it requires checking each element.
2. High time complexity compared to more advanced algorithms like Binary Search.
*/
/*
Applications of Linear Search
1. Useful for unsorted or small datasets.
2. Applicable when the dataset size is unknown or changing dynamically.
3. Can be used for searching in linked lists.
*/
/*
Frequently Asked Questions (FAQs) on Linear Search

Question 1: Is Linear Search a stable searching algorithm?
Answer: Stability is not applicable to searching algorithms as it pertains to sorting algorithms.

Question 2: What is the time complexity of Linear Search?
Answer: Linear Search has a time complexity of O(n).

Question 3: Does Linear Search require extra memory?
Answer: No, Linear Search is an in-place searching algorithm and requires O(1) additional space.

Question 4: When is it best to use Linear Search?
Answer: Linear Search is best used for small datasets or unsorted data where more complex algorithms are not suitable.
*/
