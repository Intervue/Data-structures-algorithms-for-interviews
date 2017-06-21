/*
Partition problem

Here we need to divide the array into two parts where the difference in the sum of the two parts
is minimum.

If we go by naive approach, we can either include an element or exclude it, like this total combinations
will be 2^n, which needs to be scanned Therefore time complexity is exponential

METHOD
DP: Here for two parts to have equal sum, the net sum of the array needs to be even. Therefore we first
check that.
When its even, we divide it by two and apply the subset sum method. Finding a subset in the array
whose sum is equal to a given value.

Therefore we use a 2d array in that case where columns indicate sum value from 1 to given value.
Rows indicate the values in the array
Each cell means, whether considering elements uptil that row, the column value is possible or not.
Therefore we get the final answer.

Time complexity: O(nk)
Space complexity: O(nk) //where k is the value of the sum.

This method cannnot be applied for large values of k

*/
//Naive approach
// #include <stdio.h>
// #include <stdlib.h>

// int isSubsetSum(int *arr, int size, int sum){
// 	if(!sum) 
// 		return 1;
// 	if(!size && sum) 
// 		return 0;
// 	if(arr[size-1]>sum) 
// 		return isSubsetSum(arr,size-1,sum);

// 	return isSubsetSum(arr,size-1,sum) || isSubsetSum(arr,size-1,sum-arr[size-1]);
// }

// int findPartition(int *arr,int size){
// 	int sum = 0;
// 	int i;
// 	for(i=0;i<size;i++){
// 		sum += arr[i];
// 	}
// 	if(sum%2 !=0) return 0;

// 	return isSubsetSum(arr,size,sum/2);
// }

// int main(){
// 	int arr[] = {3,1,5,9,12};
// 	int size = sizeof(arr)/sizeof(arr[0]);
// 	if(findPartition(arr,size)){
// 		printf("can be divided\n");
// 	}else{
// 		printf("cannot be divided\n");
// 	}
// 	return 0;
// }

//Better method
#include <stdio.h>
#include <stdlib.h>

int findPartition(int *arr, int size){
	int sum = 0;
	int i, j;
	for(i=0; i<size; i++){
		sum += arr[i];
	}

	if(sum%2 !=0){
		return 0;
	}

	int part[sum/2+1][size+1];

	for(i=0;i<=size;i++){
		part[i][0] = 1;
	}
	for(j=1;j<=sum/2;j++){
		part[0][j] = 0;
	}

	for(i=1;i<=size;i++){
		for(j=1;j<=sum/2;j++){
			if(arr[i-1] > j){
				part[i][j] = part[i-1][j];
			}else{
				part[i][j] = part[i-1][j] || part[i-1][j-arr[i-1]];
			}
		}
	}

	for(i=0;i<=size;i++){
		for(j=0;j<=sum/2;j++){
			printf("%d ", part[i][j]);
		}
		printf("\n");
	}

	return part[size][sum/2];

}

int main(){
	int arr[] = {3,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	if(findPartition(arr,size)){
		printf("can be divided\n");
	}else{
		printf("cannot be divided\n");
	}
	return 0;
}