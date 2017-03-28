/*
Given an unsorted array of +ve integers, 
find the number of triangles that can be formed with three different elements as three sides of the triangle

A triangle can only be formed with the sum of any two sides is greater than the third side.

METHOD1: Brute force
Pick all combinations from the given number and check the condition specified
Picking combinations can be done in nc3.
Time Complexity: O(n^3)
Space Complexity: O(1)

METHOD2: 
Sort the array
Take three points i, j and k
i will be first, j will be second and k will b i+2 to start with. j will go till n-2 always
k will go until sum of i and j is less than k.
The numbers between j and k will be the total triangles for that combination.
Repeat for all i and js
Time complexity: O(n^2)
Space complexity: O(1)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>

int findTriangles(int arr[], int size){
	int total = 0;
	
	for(int i = 0; i<size-2; i++){
		int a = arr[i];
		for(int j=i+1;j<size-1;j++){
			int b = arr[j];
			for(int k=j+1; k<size;k++){
				int c = arr[k];
				if((a+b>c) && (b+c>a) && (c+a>b)){
					total++;
				}
			}
		}
	}

	return total;
}

int main(){
	int a[] = {1,3,2,10};
	int size = sizeof(a)/sizeof(a[0]);

	printf("The number of triangles that can be formed are : %d\n", findTriangles(a, size));

	return 0;
}

//METHOD2
#include <stdio.h>
#include <stdlib.h>

int findTriangles(int arr[], int size){
	int total = 0;
	int k;
	for(int i=0; i<size-2;i++){
		for(int j=i+1;j<size-1;j++){
			k = j+1;
			if(arr[i] + arr[j] > arr[k]){
				total++;
			}
		}
	}
	return total;
	
}

int compar(const void*a, const void *b){
	return (*(int*)a-*(int*)b);
}

int main(){
	int a[] = {4,1,3,2};
	int size = sizeof(a)/sizeof(a[0]);
	qsort(a,size,sizeof(int),compar);

	printf("The number of triangles that can be formed are : %d\n", findTriangles(a, size));

	return 0;
}

