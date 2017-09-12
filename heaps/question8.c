/*
Given k-sorted lists, Find the minimum range to which at least one number belongs from every list

METHOD1:
Naive approach:
find all the intervals first that will be nc2 if total elements from all the k lists are n and see which
one is the min and fits the criteria
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2:
Start from all the lower elements or all the higher elements. Lets say lower. Choose the interval by picking
the least amongst the lower elements and highest amongst the lower elements. Now keep squeezing the interval
by shifting the lower bound. If at any point shifting the lower bound impacts losing a list completely, include
the next higher element from that list. Including that may increase the upper bound as well sometimes.
Repeat the steps for all the n elements. Keep track of the min interval during these steps.
Time complexity: O(kn) //for n times we will have to find the min and max from the k elements chosen by 
shifting the bound
Space complexity: O(k) //storing the k elements 
*/

//METHOD2
#include <stdio.h>
#include <stdlib.h>

void findInterval(int arr[], int k, int size){

	
	
}

int main(){
	int k, size, arr[], elm;
	printf("enter the value if k\n");
	printf("enter the size of each array\n");
	scanf("%d",size);
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		for(int i=0;i<size;i++){
			printf("enter the %d th element\n");
			scanf("%d",&elm)
			arr[i+k*size] = elm;
		}
	}

	findInterval(arr,k,size);
	return 0;
}