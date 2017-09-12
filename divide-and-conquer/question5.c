/*
Count inversions in an array



Eg: inversion means if an array is in increasing order and there is  a number somewhere towards the right
of which there are 3 numbers lesser than that (rather than greater than that), then it equals 3 inversions.
Like this we need to check for each element
Eg: 7 5 1 3 4 6 has 8 inversions 

As 7 has 5 elements which are less than it and are present on its right
5 as 3 of them
Total 8


METHOD1:
Search for each element by comparing elements towards its right
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
By divide and conquer
We take the middle element and divide the array into two parts start to mid and mid+1 to end. Keep doing
this till the end until we have 1 element each in the leaf. Now we will compare components one by one and
merge as we did in the merge sort. Also we will increment the number of inversion if the elm in the left
component is greater than element in right component. Merging will be done in the sorted order.
Like this we merge all the components. Since elements are sorted while merging if first element of a component
is greater than first element of second component then it will result in inversions equal to the number of 
elements present in the first component as they are sorted and all will be greater then the first element of
second component.
Time complexity T(n)= 2T(n/2)+O(n) = O(nlogn) //same as merge sort, just that merge procedure is a bit modified
Space complexity: O(logn)//size of recursion stack
*/

//merge sort implementation
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *arr, int start, int mid,int end){
	int n1 = mid-start+1; //includes mid
	int n2 = end-mid;
	int left[n1+1],right[n2+1];
	int i,j;
	for(i=0;i<n1;i++){
		left[i]=arr[i+start];
	}
	left[n1] = INT_MAX;
	for(j=0;j<n2;j++){
		right[j] = arr[j+mid+1];
	}
	right[n2] = INT_MAX;

	int k;
	i=0;j=0;
	for(k=start;k<=end;k++){
		if(left[i] <= right[j]){
			arr[k] = left[i];	
			i++;
		}else{
			arr[k] = right[j];
			j++;
		}
	}	
}

void mergeSort(int *arr, int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);	
	}
}

int main(){
	int arr[] = {7,5,1,3,4,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	mergeSort(arr,0,size-1);

	for(int i=0;i<size;i++){
		printf("%d\n", arr[i]);
	}

	return 0;
}