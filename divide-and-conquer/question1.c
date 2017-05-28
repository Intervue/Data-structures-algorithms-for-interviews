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
We will do a binary search. The thing to note is that the element that is repeating the majority number
of times n/2, will alway touch the middle part of the array No matter where it starts or end.
Therefore, if we start from the middle and try to see if the left element ot the middle is equal
to that element, if yes, then we search in the left array and repeat this exercise, otherwise we assume
that the middle element is the starting element.
Once we have the starting element we can just go to index +n/2 to see if the end index is that to finalize
that the element is repeating n/2 times, otherwise elm is not repeating that many times. If the question says
that find how many times is the element repeating given it is repeating more than n/2 times, then it will
definately touch the middle, then we find its end index also using binary search as we did for start index
Time complexity: O(logn)
Space complexity: O(logn) //if recursive else O(1) if iterative

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

int findElm(int *arr, int start, int end,int size){
	
}

int main(){
	int arr[] = {1,2,2,2,2,3,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int index = findElm(arr,0,size-1, size);
	if(index < 0){
		printf("element is not present\n");
	}else{
		printf("element is %d\n", arr[index]);	
	}
	
	return 0;
}



