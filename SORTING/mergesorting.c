/*
Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves,
 and then merges the two sorted halves.

1. Divide the array into two halves until each subarray contains only one element.
2. Merge the sorted halves to produce the final sorted array.
3. The merging process ensures the resulting array remains sorted by comparing elements from both halves.
*/

// C program for implementation of Merge Sort
#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free allocated memory
    free(L);
    free(R);
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

/*
Complexity Analysis of Merge Sort
Time Complexity: O(n log n) for all cases (best, average, and worst):

- Dividing the array takes O(log n) time (logarithmic splitting).
- Merging each level takes O(n) time.
Therefore, overall time complexity = O(n log n).

Auxiliary Space: O(n), as it requires extra memory for temporary arrays.
*/
/*
Advantages of Merge Sort
1. Consistent O(n log n) time complexity, regardless of input.
2. Stable sorting algorithm, maintaining relative order of equal elements.
3. Suitable for large datasets.
4. Well-suited for linked lists as it does not require random access to elements.
*/
/*
Disadvantages of Merge Sort
1. Requires additional memory space (O(n)).
2. Slower than in-place algorithms like Quick Sort for smaller datasets.
3. Complex implementation compared to simpler algorithms like Bubble or Selection Sort.
*/
/*
Applications of Merge Sort
1. Used in external sorting where data is too large to fit into memory.
2. Suitable for sorting linked lists due to its stable behavior.
3. Often utilized in scenarios requiring stable sorting mechanisms.
4. Ideal for datasets requiring guaranteed O(n log n) performance.
*/
/*
Frequently Asked Questions (FAQs) on Merge Sort

Question 1: Is Merge Sort a stable sorting algorithm?
Answer: Yes, Merge Sort is stable as it preserves the relative order of equal elements.

Question 2: What is the time complexity of Merge Sort?
Answer: Merge Sort has a time complexity of O(n log n) in all cases.

Question 3: Does Merge Sort require extra memory?
Answer: Yes, Merge Sort requires O(n) auxiliary space for temporary arrays.

Question 4: When is it best to use Merge Sort?
Answer: Merge Sort is best used for large datasets, scenarios requiring stable sorting, or external sorting tasks.
*/

