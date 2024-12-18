/*
Quick Sort is a comparison-based sorting algorithm. It uses the divide-and-conquer approach to partition the array into smaller sub-arrays, then sorts each sub-array independently.

1. Select a pivot element from the array.
2. Partition the array such that elements smaller than the pivot are on the left and elements greater than the pivot are on the right.
3. Recursively apply the above steps to the sub-arrays.
*/

// C program for implementation of Quick Sort
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Select the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

/*
Complexity Analysis of Quick Sort
Time Complexity:
- Best Case: O(n log n), when the pivot divides the array into two nearly equal halves.
- Average Case: O(n log n), with random pivots.
- Worst Case: O(n^2), when the smallest or largest element is always picked as the pivot.

Auxiliary Space: O(log n), for the recursive call stack in the best and average cases.
*/
/*
Advantages of Quick Sort
1. Efficient for large datasets.
2. In-place sorting algorithm, requiring minimal additional memory.
3. Performs well on average and best cases.
*/
/*
Disadvantages of Quick Sort
1. Worst-case time complexity of O(n^2).
2. Not a stable sorting algorithm.
3. Performance is dependent on the choice of pivot.
*/
/*
Applications of Quick Sort
1. Suitable for sorting large datasets efficiently.
2. Often used in libraries and frameworks due to its average-case efficiency.
3. Useful for problems where in-place sorting is required.
4. Used as a subroutine in other algorithms like Quickselect.
*/
/*
Frequently Asked Questions (FAQs) on Quick Sort

Question 1: Is Quick Sort a stable sorting algorithm?
Answer: No, Quick Sort is not stable as it may change the relative order of equal elements.

Question 2: What is the time complexity of Quick Sort?
Answer: Quick Sort has a time complexity of O(n log n) on average, and O(n^2) in the worst case.

Question 3: Does Quick Sort require extra memory?
Answer: Quick Sort requires O(log n) additional space for the recursive stack.

Question 4: When is it best to use Quick Sort?
Answer: Quick Sort is best used for large datasets where average-case performance is critical.
*/

