/*
Given an array and an integer K, find max element for each and every contiguous subarray of size k

METHOD1
Only valid for less value of k eg given for k = 3
Time Complexity: O(n)
Space Complexity: O(1)

METHOD2

*/


// //METHOD1
// #include <stdio.h>
// #include <stdlib.h>

// int main(){

// 	int arr[] = {10,4,2,11,3,15,12,8,7,9,21,14};
// 	int length = sizeof(arr)/sizeof(arr[0]);
// 	int elm1, elm2, elm3, max;
	
// 	for(int i=0; i<length-2; i++){

// 		elm1 = arr[i];
// 		elm2 = arr[i+1];
// 		elm3 = arr[i+2];

// 		max = (elm1>elm2)?((elm1>elm3)?elm1:elm3):((elm2>elm3)?elm2:elm3);

// 		printf("%d ", max);

// 	}

// }


//METHOD1
#include <stdio.h>
#include <stdlib.h>

int main(){

	int arr[] = {10,4,2,11,3,15,12,8,7,9,21,14};
	
	

}