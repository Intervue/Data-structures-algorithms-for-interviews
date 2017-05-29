/*
Select an element in sorted rotated array

sorted rotated array means, the array was sorted and then some elements were picked and rotated.
eg: 1 2 3 4 5 6 7 8 9 10 became
7 8 9 10 1 2 3 4 5 6

and we need to search for some element in this array.

Linear search can be done. But binary search can also be applied as given below.

METHOD1:
First using binary search we need to find the place where max element is placed. (given the rotation order)
assume in the question and max number as well. Therefore we need to locate 10 as per the above eg.
Now we start from middle element and see left bound which is 7 and right bound which is 6. Now middle
element being 2 it is clear that the sequence is increasing from middle to right, hence 10 cannot be there.
Now if we see towards left, there is a higher number instead of lesser. Therefore we need to search the left
array. Therefore, again we will apply the same method on the left array. Now once 10 is located. We will have
two different increasing components with uppper and lower bounds, and we will clearly know where to search any
element using binary search again.

Time complexity: O(2logn) =  O(logn) //twice binary search will be applied 
Space complexity: O(logn) or O(1) //recursive or iterative

METHOD2:
Using binary search only but there is no need to divide the array into two components.
Therefore there will be a single array (in the question it will be mentioned whether its a increasing sequence
or not). Therefore from the middle element, one side has to be sorted and the other will not be sorted 
no matter at whatstage in the recursion we are. Always from the middle element, one side will be in the right 
order and one will be increasing to a point and then decreasing. Therefore we can find the range of middle
to right if it falls in that it exists there otherwise it exists in the other part. It can be done for 
all the sub problems.

Time complexity: O(logn) //binary search
Space complexity: O(1) or O(logn) //iterative or recursive
*/
//METHOD2
#include <stdio.h>
#include <stdlib.h>
//recursion
int search(int *arr,int start,int end, int elm){
	if(start > end) return -1;
	int mid = (start + end)/2;
	if(arr[mid] == elm) return mid;

	if(arr[mid] <= arr[end]){
		return (elm >= arr[mid] && elm <=arr[end])?search(arr,mid+1,end,elm):search(arr,start, mid-1,elm);	
	}
	return (elm >= arr[start] && elm <= arr[mid])?search(arr,start,mid-1,elm):search(arr,mid+1,end,elm);
}
//iteration
int searchIterative(int *arr, int start, int end, int elm){
	while(start <= end){
		int mid = (start + end)/2;
		if(arr[mid] == elm) return mid;
		if(arr[mid] <= arr[end]){
			start = (elm >= arr[mid] && elm <= arr[end])?mid+1:start;
			end = (elm >= arr[mid] && elm <= arr[end])?end:mid-1;
		}else{
			end = (elm >= arr[start] && elm <=arr[mid])?mid-1:end;
			start = (elm >= arr[start] && elm <=arr[mid])?start:mid+1;
		}
	}
	return -1;
}

int main(){
	int arr[] = {8,9,10,1,2,3,4,5,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int elm;
	while(1){
		printf("enter the element to be searched\n");
		scanf("%d",&elm);
		int index = searchIterative(arr,0,size-1,elm);
		if(index < 0){
			printf("element does not exist\n");
		}else{
			printf("element exists at %d\n", index);
		}
	}

	return 0;
}