/*
Find a majority element using linear search that occurs more than n/2 times. The array is ordered

METHOD1:
we can do a linear search for n elements and maintain a counter for each element which is reaches more than
n/2 then we will return that element.
Time complexity: O(n)
Space complexity: O(1)

METHOD2:
we can do a linear search of first n/2 elements and then see if the same element is present at ith and
i+n/2 th place. If yes then that is the required element.
Time complexity: O(n) //but overall time will be lesser still we are scanning till half
Space complexity: O(1)

METHOD3:



*/
//METHOD1
// #include <stdio.h>
// #include <stdlib.h>

// int findElm(int *arr, int size){
// 	int i,counter = 1;
// 	for(i=0;i<size-1;i++){
// 		if(arr[i] == arr[i+1]){
// 			counter++;
// 			if(counter > size/2){
// 				return arr[i];
// 			}
// 		}else{
// 			counter = 1;
// 		}
// 	}
// 	return -1;
// }

// int main(){
// 	int arr[] = {1,1,1,1,2,3,4};
// 	int size = sizeof(arr)/sizeof(arr[0]);
// 	int elm = findElm(arr,size);
// 	if(elm < 0){
// 		printf("element is not present\n");
// 	}else{
// 		printf("element is %d\n", elm);	
// 	}
	
// 	return 0;
// }
//=========================================================================================
//METHOD2
// #include <stdio.h>
// #include <stdlib.h>

// int findElm(int *arr, int size){
// 	int i=0;
// 	while(i<=size/2){
// 		if(arr[i] == arr[i+size/2]){
// 			return arr[i];
// 		}
// 		i++;
// 	}
// 	return -1;
// }

// int main(){
// 	int arr[] = {1,2,3,4,4,4,4};
// 	int size = sizeof(arr)/sizeof(arr[0]);
// 	int elm = findElm(arr,size);
// 	if(elm < 0){
// 		printf("element is not present\n");
// 	}else{
// 		printf("element is %d\n", elm);	
// 	}
	
// 	return 0;
// }
//===============================================================================================
//METHOD3
#include <stdio.h>
#include <stdlib.h>

int findElm(int *arr, int size){
	int i=0;
	while(i<=size/2){
		if(arr[i] == arr[i+size/2]){
			return arr[i];
		}
		i++;
	}
	return -1;
}

int main(){
	int arr[] = {1,2,3,4,4,4,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int elm = findElm(arr,size);
	if(elm < 0){
		printf("element is not present\n");
	}else{
		printf("element is %d\n", elm);	
	}
	
	return 0;
}



