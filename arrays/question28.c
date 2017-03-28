/*
Given an array of positive numbers, find the smallest number that cannot be formed with sum
of numbers from array

METHOD1:
find all subsets (O(2^n)) and find their sum and then check if sum exists
Time complexity: greater than O(2^n)

METHOD2:
sort the array in increasing order. Now take the number not possible P = 1
Compare it with the first element of array. If first element is less than or equal to P
then update value of P as P+current element and repeat the loop. If its greater than P
P is the smallest sum that is not possible.

Time complexity: O(nlogn)
Space complexity: O(1)

Explanation:
Lets say the smallest some that is not possible in an array is N. That means all other sums like
1,2,3,....N-1 are possible.
Now lets say the next number is X. if X is equal to N, then N is possible, if X is less than N, than also
N is definately possible because X+1<=N<=X+N-1 (N will lie between the given range). That means for X all the sums
X+1, X+2...X+N-1 are possible which will include N as well. (Given X is greater than 1)
The sum that wont be possible in this case will be a number which is positive and outside the range
which is X+N
*/

//METHOD2
#include <stdio.h>
#include <stdlib.h>

int findMinNum(int arr[], int size){
	int sum = 1; //assume
	for(int i=0;i<size; i++){
		if(arr[i] <= sum){
			sum += arr[i];
		}else{
			return sum;
		}
	}
	return sum;
}

int compar(const void*a, const void*b){
	return *(int*)a-*(int*)b;
}

int main(){
	int a[] = {4,13,2,3,1};
	int size = sizeof(a)/sizeof(a[0]);
	qsort(a,size,sizeof(int),compar);
	printf("min number that cannot be formed %d\n", findMinNum(a,size));
	return 0;
}
