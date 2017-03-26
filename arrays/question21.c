/*
Consider and array which contains only 0's and 1's. Find largest sub array which contains only 0's and 1's

METHOD1:
finding all sub arrays possible and maintaining an array which counts number of 1s and another which counts number
of 0s so far to avoid counting in the end.
Time complexity: O(n^2)
Space complexity: O(n)

METHOD2:
Replacing all 0s with -1 and maintaining the sumsofar in a hash. Each time if sum is repeated that means the middle
elements in b/w the repetition have contributed a sum of zero which is the subarray. To find the largest
one we need to find the min where there was a sum and max place where that sum got repeated. The subarray can also
be found if the sum is zero upto a point.
Therefore we need to store the sums in hash along with the index where is repeated itself.
Time complexity: O(n)
Space complexity: O(n)

*/

// METHOD1
#include <stdio.h>
#include <stdlib.h>

void printSubArray(int arr[],int start, int end){
	for(int i=start; i<=end; i++){
		printf("%d",arr[i]);
	}
}

int main(){

	int a[] = {1,1,1,1};
	int length = sizeof(a)/sizeof(a[0]);
	int start, end;

	int count_one[length], count_zero[length];
	int ones = 0, zeroes = 0, max_zeroes = 0, max_ones = 0, curr_max_one = 0;
	int leftIndex, rightIndex, noSubArray;
	//for counting 1s in the end
	for(int i=0; i<length;i++){
		if(a[i] == 1){
			ones++;
		}
		count_one[i] = ones;
	}
	//for counting zeroes in the end
	for(int i=0; i<length;i++){
		if(a[i] == 0){
			zeroes++;
		}
		count_zero[i] = zeroes;
	}

	for(int i=0; i<length;i++){
		start = i;
		for(int j=i+1; j<length;j++){
			end = j;
			if(start == 0){
				max_ones = count_one[end];
				max_zeroes = count_zero[end];	
			}else{
				max_ones = count_one[end] - count_one[i-1];
				max_zeroes = count_zero[end] - count_zero[i-1];
			}
			if(max_ones == max_zeroes){
				if(curr_max_one < max_ones){
					curr_max_one = max_ones;
					leftIndex = start;
					rightIndex = end;
					noSubArray = 0;
				}else{
					noSubArray = 1;
				}
			}
		}
	}
	if(noSubArray){
		printf("no sub array found\n");
	}else{
		printSubArray(a,leftIndex,rightIndex);
	}
	
}


//METHOD2
//TO BE DONE
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

void printLongestSubArray(int arr[],int size, int starts){
	
	for(int i=starts; i<size; i++){
		printf("%d",arr[i]);
	}
	
}

int main(){

	int a[] = {0,0,0,1,1,1};
	int size = sizeof(a)/sizeof(a[0]);
	
	int sum_arr[size];

	for(int i=0; i<size; i++){
		sum_arr[i] = 0;
	}

	sum_arr[0] = (a[0] == 0)?-1:1;
	int min, max = sum_arr[0];
	for(int i=1; i<size;i++){
		sum_arr[i] = sum_arr[i-1] + ((a[i] == 0)?-1:1);
		if(sum_arr[i] > max){
			max = sum_arr[i];
		}
		if(sum_arr[i] < min){
			min = sum_arr[i];
		}
	}

	printArray(sum_arr,size);
	printf("%d\n", max);
	printf("%d\n", min);


	int hash_size = max-min+1;
	int hash[hash_size];
	
	for(int j=0; j<hash_size; j++){
		hash[j] = -1;
	}	
	printArray(hash,hash_size);

	int maxSize = -1, startsWith, sumSofar;

	for(int index=0;index<size; index++){
		
		if(sum_arr[index] == 0){
			maxSize = index+1;
			startsWith = 0;
			continue;
		}
		sumSofar = sum_arr[index]-min;
		if(hash[sumSofar] == -1){
			hash[sumSofar] = index;
		}else{
			if(index - hash[sumSofar] > maxSize){
				maxSize = index - hash[sumSofar];
				startsWith = hash[sumSofar]+1;
			}
		}
		printf("starts with %d\n", startsWith);
		printf("run upto %d\n", maxSize);
	}

	if(maxSize == -1){
		printf("%s\n", "no max sub array with equal number of 1s and 0s");
	}else{
		printLongestSubArray(a, maxSize,startsWith);	
	}	
	
}






