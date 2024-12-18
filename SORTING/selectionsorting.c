/*
Selection Sort is a comparison-based sorting algorithm.
 It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion 
 and swapping it with the first unsorted element. This process continues until the entire array is sorted.

1.First we find the smallest element and swap it with the first element. 
2.This way we get the smallest element at its correct position.
3.Then we find the smallest among remaining elements (or second smallest) and move it to its correct position by swapping.
We keep doing this until we get all elements moved to correct position.
*/
// C program for implementation of selection sort
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      
        // Assume the current position holds
        // the minimum element
        int min_idx = i;
        
        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
              
                // Update min_idx if a smaller element is found
                min_idx = j;
            }
        }
        
        // Move minimum element to its
        // correct position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
/*
Complexity Analysis of Selection Sort
Time Complexity: O(n2) ,as there are two nested loops:

One loop to select an element of Array one by one = O(n)
Another loop to compare that element with every other Array element = O(n)
Therefore overall complexity = O(n) * O(n) = O(n*n) = O(n2)
Auxiliary Space: O(1) as the only extra memory used is for temporary variables.
*/
/*
Advantages of Selection Sort
1.Easy to understand and implement, making it ideal for teaching basic sorting concepts.
2.requires only a constant O(1) extra memory space.
3.It requires less number of swaps (or memory writes) compared to many other standard algorithms.
 Only cycle sort beats it in terms of memory writes.
 Therefore it can be simple algorithm choice when memory writes are costly.
 */
/*Disadvantages of the Selection Sort
1.Selection sort has a time complexity of O(n^2) makes it slower compared to algorithms like Quick Sort or Merge Sort.
2.Does not maintain the relative order of equal elements.
3.Does not preserve the relative order of items with equal keys which means it is not stable.
*/

/*
Applications of Selection Sort
1.Perfect for teaching fundamental sorting mechanisms and algorithm design.
2.Suitable for small lists where the overhead of more complex algorithms isn’t justified.
3.Ideal for systems with limited memory due to its in-place sorting capability.
4.Used in simple embedded systems where resource availability is limited and simplicity is important.
*/
/*
Frequently Asked Questions (FAQs) on Selection Sort
Question 1: Is Selection Sort a stable sorting algorithm?

Answer: No, Selection Sort is not stable as it may change the relative order of equal elements.
Question 2: What is the time complexity of Selection Sort?

Answer: Selection Sort has a time complexity of O(n^2) in the best, average, and worst cases.


Question 3: Does Selection Sort require extra memory?

Answer: No, Selection Sort is an in-place sorting algorithm and requires only O(1) additional space.


Question 4: When is it best to use Selection Sort?

Answer: Selection Sort is best used for small datasets, educational purposes, or when memory usage needs to be minimal.
*/