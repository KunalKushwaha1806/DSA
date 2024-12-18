/*
Index Sequential Search combines the benefits of sequential search and indexing by dividing a dataset into blocks and searching within the relevant block. It is particularly useful for datasets stored on external devices where access time is significant.

1. Divide the dataset into blocks of approximately equal size.
2. Create an index that stores the maximum value and the starting position of each block.
3. Use the index to find the block where the target might be located.
4. Perform a sequential search within the identified block to locate the target.
*/

// C program for implementation of Index Sequential Search
#include <stdio.h>
#include <math.h>

// Function to perform Index Sequential Search
int indexSequentialSearch(int arr[], int n, int target) {
    int blockSize = sqrt(n); // Calculate block size
    int start = 0;
    int end = blockSize;

    // Use the index to find the block
    while (end < n && arr[end - 1] < target) {
        start = end;
        end += blockSize;
    }

    if (end > n) {
        end = n;
    }

    // Perform linear search within the block
    for (int i = start; i < end; i++) {
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
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    printf("Array: ");
    printArray(arr, n);

    int result = indexSequentialSearch(arr, n, target);
    if (result != -1) {
        printf("Element %d is present at index %d\n", target, result);
    } else {
        printf("Element %d is not present in the array\n", target);
    }

    return 0;
}

/*
Complexity Analysis of Index Sequential Search
Time Complexity:
- Best Case: O(1), if the target is found directly using the index.
- Average Case: O(\u221an) due to block-wise division and linear search within a block.
- Worst Case: O(n), if the target is at the end or not present.

Auxiliary Space: O(1) as no extra space is required beyond a few variables.
*/
/*
Advantages of Index Sequential Search
1. Faster than pure sequential search due to indexed access.
2. Suitable for large datasets where full sequential search is costly.
3. Simple to implement and uses minimal memory.
*/
/*
Disadvantages of Index Sequential Search
1. Requires sorted data, which may add overhead for preprocessing.
2. Inefficient for small datasets where sequential search suffices.
3. Less efficient compared to binary search for purely in-memory datasets.
*/
/*
Applications of Index Sequential Search
1. Used in database indexing to improve search performance.
2. Suitable for datasets stored on external devices with high access times.
3. Applicable in scenarios where balanced trade-offs between time and memory are required.
*/



/*
Frequently Asked Questions (FAQs) on Index Sequential Search

Question 1: Is Index Sequential Search suitable for unsorted datasets?
Answer: No, Index Sequential Search requires the dataset to be sorted beforehand.

Question 2: What is the time complexity of Index Sequential Search?
Answer: The average time complexity is O(\u221an) due to block-wise search.

Question 3: Does Index Sequential Search require extra memory?
Answer: No, it is an in-place searching algorithm and requires minimal additional memory.

Question 4: When is it best to use Index Sequential Search?
Answer: It is best used for large sorted datasets stored on external devices or scenarios where linear and binary searches are inefficient.
*/