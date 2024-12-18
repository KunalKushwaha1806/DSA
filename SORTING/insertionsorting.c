/*
Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list
 into its correct position in a sorted portion of the list. It is like sorting playing cards in your hands. 
 You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the 
 unsorted group and put it in the right place in the sorted group.


steps:

1.We start with second element of the array as first element in the array is assumed to be sorted.
2.Compare second element with the first element and check if the second element is smaller then swap them.spo
3.Move to the third element and compare it with the first two elements and put at its correct position
4.Repeat until the entire array is sorted.  
*/
// C program for implementation of Insertion Sort
#include <stdio.h>

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}



/*
arr = {23, 1, 10, 5, 2}  


Initial: 


 Current element is  23 
 The first element in the array is assumed to be sorted. 
 The sorted part until  0th  index is :  [23] 
 First Pass: 


 Compare  1  with  23  (current element with the sorted part). 
 Since  1  is smaller, insert  1  before  23  . 
 The sorted part until  1st  index is:  [1, 23] 
 Second Pass: 


 Compare  10  with  1  and  23  (current element with the sorted part). 
 Since  10  is greater than  1  and smaller than  23  , insert  10  between  1  and  23  . 
 The sorted part until  2nd  index is:  [1, 10, 23] 
 Third Pass: 


 Compare  5  with  1  ,  10  , and  23  (current element with the sorted part). 
 Since  5  is greater than  1  and smaller than  10  , insert  5  between  1  and  10 
 The sorted part until  3rd  index is  :  [1, 5, 10, 23] 
 Fourth Pass: 


 Compare  2  with  1, 5, 10  , and  23  (current element with the sorted part). 
 Since  2  is greater than  1  and smaller than  5  insert  2  between  1  and  5  . 
 The sorted part until  4th  index is:  [1, 2, 5, 10, 23] 
 Final Array: 


 The sorted array is:  [1, 2, 5, 10, 23] 
*/
/*Complexity Analysis of Insertion Sort :
Time Complexity of Insertion Sort
Best case: O(n) , If the list is already sorted, where n is the number of elements in the list.
Average case: O(n 2 ) , If the list is randomly ordered
Worst case: O(n 2 ) , If the list is in reverse order
Space Complexity of Insertion Sort
Auxiliary Space: O(1), Insertion sort requires O(1) additional space, making it a space-efficient sorting algorithm.
*/

/*Advantages of Insertion Sort:
Simple and easy to implement.
Stable sorting algorithm.
Efficient for small lists and nearly sorted lists.
Space-efficient as it is an in-place algorithm.
Adoptive. the number of inversions is directly proportional to number of swaps.
 For example, no swapping happens for a sorted array and it takes O(n) time only.
*/

/*
Disadvantages of Insertion Sort:
Inefficient for large lists.
Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases.*/

/*
Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
*/
/*

Frequently Asked Questions on Insertion Sort
Q1. What are the Boundary Cases of the Insertion Sort algorithm?

 Insertion sort takes the maximum time to sort if elements are sorted in reverse order. 
 And it takes minimum time (Order of n) when elements are already sorted. 


Q2. What is the Algorithmic Paradigm of the Insertion Sort algorithm?

 The Insertion Sort algorithm follows an incremental approach. 


Q3. Is Insertion Sort an in-place sorting algorithm?

 Yes, insertion sort is an in-place sorting algorithm. 


Q4. Is Insertion Sort a stable algorithm?

 Yes, insertion sort is a stable sorting algorithm. 


Q5. When is the Insertion Sort algorithm used?

 Insertion sort is used when number of elements is small. It can also be useful when the input array is almost sorted,
  and only a few elements are misplaced in a complete big array. 
*/