/*
Rotate an array of n elements by d elements

METHOD1:
make a new array of d elements, store the first d elements in that
The shift the remaining elements 
Now add the d elements in the end
Time complexity: O(n)
Space complexity: O(d)

METHOD2:
take a variable and keep inserting elements to be moved to the right one by one and keep shifting elements
to the left one by one.
Here the space complexity will be comparatively less.
Time complexity: O(d X n) because we will have to shift n elements d times
Space complexity: O(1) //as we are only using 1 variable

METHOD3:
Take the GCD of size of array and number of elements to be rotated. Assume it comes out to be 2.
Now make groups of 2. Take an external variable. Put the first element into that variable. now shift
first element of each group to the new first element of the group towards its left. Eg. Grp 2 first 
element now becomes grp1 first element and so on.
There will be a place in the end that will be emptied. (last grp first element). Insert this variable
to that place.
Similarly do it for the 2nd element as well.
Time complexity: O(n) //number of movements were less
Space complexity: O(1)

METHOD4:
reverse the first d elements to be rotated. Now reverse the remaining n-d elements
Now reverse the whole array. You will get the rotated array
TIme complexity: O(d) + O(n-d) = O(n)
Space complexity: O(1)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){

	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

void rotateArrayBy(int d,int arr[], int size){

	for(int i=0; i<d; i++){
		int first = arr[0];
		for(int index=0; index<size; index++){
			arr[index] = arr[index+1];
		}
		arr[size-1]=first;	
	}
	
	printArray(arr, size);
}

int main(){
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	int elementsToBeRotated = 2;
	
	rotateArrayBy(elementsToBeRotated,arr,size);	
}

//METHOD2
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){

	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

void rotateArrayBy(int d,int arr[], int size){

	int new_arr[d];
	for(int i=0; i<d; i++){
		new_arr[i]= arr[i];
	}
	
	for(int i=0; i<size-d;i++){
		arr[i] = arr[d+i];
	}

	for(int i=0; i<d; i++){
		arr[size-d+i] = new_arr[i];
	}

	printArray(arr, size);
}

int main(){
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	int elementsToBeRotated = 2;
	
	rotateArrayBy(elementsToBeRotated,arr,size);	
}


//METHOD3
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){

	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

int findGcd(int size, int d){
	if(d==0){
		return size;
	}else{
		return findGcd(d,size%d);
	}
}

void rotateArrayBy(int d,int arr[], int size){

	int gcd = findGcd(size,d);
	int first = arr[0], second = arr[1], curr_gcd_index = 0, curr_odd_index = 1;

	for(int index=0; index<size; index++){
		if(index%gcd == 0){
			arr[curr_gcd_index] = arr[index];
			curr_gcd_index = index;
		}else{
			arr[curr_odd_index] = arr[index];
			curr_odd_index = index;
		}
	}
	arr[curr_gcd_index] = first;
	arr[curr_odd_index] = second;


	printArray(arr, size);
}

int main(){
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	int elementsToBeRotated = 2;
	rotateArrayBy(elementsToBeRotated,arr,size);	
	
}

//METHOD4
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){

	for(int i=0; i<size; i++){
		printf("%d\n", arr[i]);
	}
}

void reverseArr(int a[], int start,int size){
	int i=start, j=size-1, temp;
	while(i<=j){
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
}

void rotateArrayBy(int d,int arr[], int size){

	reverseArr(arr,0,d);
	reverseArr(arr,d,size);
	reverseArr(arr,0,size);
	printArray(arr, size);
}

int main(){
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	int elementsToBeRotated = 2;
	rotateArrayBy(elementsToBeRotated,arr,size);	
	
}

