/*
Radix Sort is a non-comparison-based sorting algorithm. It processes integers by sorting digits from the least significant to the most significant using a stable sorting technique (e.g., Counting Sort) as a subroutine.

1. Find the maximum number to determine the number of digits.
2. Perform counting sort for each digit, starting from the least significant digit to the most significant digit.
*/

// C program for implementation of Radix Sort
#include <stdio.h>

// A utility function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// A function to perform counting sort based on the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Count array for digits 0-9

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count array to store cumulative counts
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to implement Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to determine the number of digits
    int max = getMax(arr, n);

    // Perform counting sort for each digit, moving from least to most significant digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

/*
Complexity Analysis of Radix Sort
Time Complexity:
- Best, Average, and Worst Case: O(nk), where n is the number of elements and k is the number of digits in the largest number.

Auxiliary Space: O(n + k), where n is the number of elements and k is the base (e.g., 10 for decimal numbers).
*/
/*
Advantages of Radix Sort
1. Efficient for sorting integers or strings with fixed ranges.
2. Stable sorting algorithm, preserving the relative order of equal elements.
3. Performs better than comparison-based algorithms for large datasets with small key ranges.
*/
/*
Disadvantages of Radix Sort
1. Requires additional memory for counting and output arrays.
2. Not suitable for datasets with variable-length keys or large ranges.
3. Inefficient for small datasets compared to algorithms like Quick Sort or Merge Sort.
*/
/*
Applications of Radix Sort
1. Sorting integers or strings with a fixed range of digits or characters.
2. Used in scenarios like phone number sorting or processing large datasets with fixed-size fields.
3. Often combined with other algorithms (e.g., Counting Sort) for specialized tasks.
*/
/*
Frequently Asked Questions (FAQs) on Radix Sort

Question 1: Is Radix Sort a stable sorting algorithm?
Answer: Yes, Radix Sort is stable as it maintains the relative order of equal elements.

Question 2: What is the time complexity of Radix Sort?
Answer: Radix Sort has a time complexity of O(nk), where n is the number of elements and k is the number of digits.

Question 3: Does Radix Sort require extra memory?
Answer: Yes, Radix Sort requires O(n + k) additional space for the counting and output arrays.

Question 4: When is it best to use Radix Sort?
Answer: Radix Sort is best used for integers or strings with fixed ranges and for datasets where stability is important.
*/

