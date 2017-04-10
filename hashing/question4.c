/*
Given an array A, Count the distinct elements in all windows of size K

METHOD1:
Naive approach: For each window, compare each element in the window with the remaining elements to see it its
repeated. comparison will take O(k^2) time for each window.
Total windows = n-k+1 (dry check)
Time complexity: O(n*k^2)
Space complexity: O(1)

METHOD2:
sort each window and scan each window
Time complexity: O(nklogk)
Space complexity: O(1)

METHOD3:
Create a hash table for each window storing count of each element and scan it and print the total non
repeating elements.
Time complexity: O(nk)
Space complexity: O(k)

METHOD4:
Using a hashtable, but this time we scan the array once, store values in hash table, as we scan, there
is a variable that keeps a check on the count of unique elements. The variable is incremented for everytime,
we encounter a 1 and decremented everytime we encounter greater or less than 1. The hash is searched as window
is moved deleting one element and adding one each time, which may decrease or increase the count
Time complexity: O(n)
Space complexity: O(1)
*/

// //METHOD1
// #include <stdio.h>
// #include <stdlib.h>

// void findUniqueWindowWise(int arr[],int limit, int size){
// 	int sum = 0, flag = 0;
// 	int i,j,k;
	
// 	for(i=0; i<size-limit+1;i++){
// 		for(j=i; j<limit+i;j++){	
// 			int temp = arr[j];
// 			for(k=i;k<limit+i;k++){
// 				if(k==j){
// 					continue;
// 				}else{
// 					if(temp == arr[k]){
// 						flag = 1;
// 					}
// 				}
// 			}
// 			if(!flag){
// 				sum++;
// 			}
// 			flag = 0;
// 		}
// 		printf("%d\n", sum);
// 		sum = 0;
// 	}
// }

// int main(){
// 	int arr[] = {10,10,20,30,30,40,10};
// 	int size = sizeof(arr)/sizeof(arr[0]);
// 	int k = 3;
// 	findUniqueWindowWise(arr,k, size);
// 	return 0;
// }

// //================================================================================================
// //METHOD2
// #include <stdio.h>
// #include <stdlib.h>

// void findUniqueWindowWise(int arr[],int limit, int size){
// 	int i,j,k, sum=0;
// 	for(i=0;i<size-limit+1;i++){
// 		for(j=i+1;j<limit+i;j++){
// 			//ASSUMING THAT IT IS SORTED
// 			int temp = arr[j];
// 			if(temp != arr[j-1]){
// 				sum++;
// 				if(sum == limit-1){
// 					sum++;
// 				}
// 			}
// 		}
// 		printf("%d\n", sum);
// 		sum = 0;
// 	}
// }

// int main(){
// 	int arr[] = {10,10,20,30,30,40,50};
// 	int size = sizeof(arr)/sizeof(arr[0]);
// 	int k = 3;
// 	findUniqueWindowWise(arr,k, size);
// 	return 0;
// }
//================================================================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>

struct node{

};

void findUniqueWindowWise(int arr[],int limit, int size){
	
}

int main(){
	int arr[] = {10,10,20,30,30,40,50};
	int size = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	findUniqueWindowWise(arr,k, size);
	return 0;
}

