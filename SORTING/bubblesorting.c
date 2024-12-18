/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements
 if they are in the wrong order. This algorithm is not suitable for large data sets as its average and
  worst-case time complexity are quite high.
steps:

1.We sort the array using multiple passes. After the first pass, the maximum element goes to 
end (its correct position). Same way, after second pass, the second largest element goes to
 second last position and so on.

2.In every pass, we process only those elements that have already not moved to correct 
position. After k passes, the largest k elements must have been moved to the last k positions.

3.In a pass, we consider remaining elements and compare all adjacent and swap if larger element is 
before a smaller element. If we keep doing this, we get the largest (among the remaining elements) 
at its correct position.
*/
//bubble sort
#include<stdio.h>
void bubblesort(int*arr,int n){
	for(int i=0;i<n-1;i++){
		int flag=0;
		for(int j=0;j<n-i-1;j++){//to make the conditons true!!
		if (arr[j] > arr[j+1]){
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			flag=1;
		}
		if (flag==0)break;
			
		}
	}
	
	
}
int main(){
	int arr[5]={8,6,4,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
		
	}
	return 0;
}
/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
/*
Advantages of Bubble Sort:
1.Bubble sort is easy to understand and implement.
2.It does not require any additional memory space.
3.It is a stable sorting algorithm, meaning that 
elements with the same key value maintain their relative order in the sorted output.
*/
/*
Disadvantages of Bubble Sort:
1.Bubble sort has a time complexity of O(n2) which makes it very slow for large data sets.
2.Bubble sort is a comparison-based sorting algorithm, which means that it requires a comparison 
operator to determine the relative order of elements in the input data set.
3. It can limit the efficiency of the algorithm in certain cases
*/
/*


What is the Boundary Case for Bubble sort? 
Bubble sort takes minimum time (Order of n) when elements are already sorted. 
Hence it is best to check if the array is already sorted or not beforehand, to avoid O(n2) time complexity.   


Does sorting happen in place in Bubble sort?
Yes, Bubble sort performs the swapping of adjacent pairs without the use of any major data structure. Hence
 Bubble sort algorithm is an in-place algorithm.


Is the Bubble sort algorithm stable?
Yes, the bubble sort algorithm is stable.
*/