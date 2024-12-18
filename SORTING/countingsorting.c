/*
Counting Sort is a non-comparison-based sorting algorithm. It sorts integers by counting the occurrences of each unique value and using that information to place them in the correct position in the output array.

1. Count the frequency of each element and store it in a count array.
2. Modify the count array to store the position of elements in the output array.
3. Build the output array using the count array and input array.
4. Copy the output array back to the original array.
*/

// C program for implementation of Counting Sort
#include <stdio.h>
#include <string.h>

#define RANGE 255 // Define the range of input values (e.g., for ASCII characters)

void countingSort(int arr[], int n) {
    // Create output array to store sorted elements
    int output[n];

    // Create and initialize count array
    int count[RANGE + 1] = {0};

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update count array to store cumulative counts
    for (int i = 1; i <= RANGE; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

/*
Complexity Analysis of Counting Sort
Time Complexity: O(n + k), where:
- n is the number of elements in the input array.
- k is the range of the input.

Auxiliary Space: O(n + k), as it requires extra memory for the count and output arrays.
*/
/*
Advantages of Counting Sort
1. Linear time complexity for small range of integers.
2. Does not involve comparisons between elements.
3. Stable sorting algorithm, preserving the relative order of equal elements.
4. Suitable for sorting data with a limited range of discrete values.
*/
/*
Disadvantages of Counting Sort
1. Requires additional memory proportional to the range of the input.
2. Inefficient for large ranges or non-integer data.
3. Not a comparison-based sorting algorithm, so it cannot be used as a general-purpose sorter.
*/
/*
Applications of Counting Sort
1. Ideal for sorting integers or discrete objects (e.g., characters) with small ranges.
2. Often used as a subroutine in radix sort.
3. Suitable for tasks requiring stable sorting with known, limited input ranges.
4. Used in scenarios like sorting grades, counting votes, or organizing categorical data.
*/
/*
Frequently Asked Questions (FAQs) on Counting Sort

Question 1: Is Counting Sort a stable sorting algorithm?
Answer: Yes, Counting Sort is stable as it maintains the relative order of equal elements.

Question 2: What is the time complexity of Counting Sort?
Answer: Counting Sort has a time complexity of O(n + k), where n is the number of elements and k is the range.

Question 3: Does Counting Sort require extra memory?
Answer: Yes, Counting Sort requires O(n + k) additional space for the count and output arrays.

Question 4: When is it best to use Counting Sort?
Answer: Counting Sort is best used for integers or discrete objects with small, known ranges.
*/

