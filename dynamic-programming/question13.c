/*
Find the longest increasing subsequence

Here indexes cannot be changed as it has to be increasing only.

METHOD:
Naive:
Since each element can either be a part of the sequence or cannot be, so there are two possibilities
and n such elements. 
Therefore, total time complexity is O(2^n)

METHOD1:
The given string can be sorted and another string can be made out of it. Then both the strings can be
compared to find Longest common subsequence in the given strings. For that we have already done an algo
Time complexity: O(n^2) + O(nlogn) = O(n^2)
Space complexity: O(n^2)

METHOD2:
In this method a bigger problem can be broken down into smaller repeating sub-problems and dynamic
programming can be applied.
Eg: an array of size n can rather be broken into n-1 and 1 such solution for n-1 can be found
and it can be seen that whether the subsequence from n-1 can be joined with the last element.
It can only be joined if last element is greater than last element of subsequence formed from n-1
elements.
Similarly for n-1 such elements n-2 + 1
for n-2 elements n-3 + 1
and so on
for 1 element: 1 + 1
In case if the element is smaller than the last element of the sequence answer would be 1.
The net answer would be max of all these which ever fits

Therefore we start from the smallest sub problem where we take array of size 1 (starting) and see
how many solutions are possible and make a separate array and store the answer for that index there

Eg: 2,  10,  13,  5,  4,  11,  12   0
sol:1,  2    3    2   2    3    4   1
at 10 result is 2 because 1+max of prev which is also 1

Therefore answer here is 4. (longest possible subsequence)

Time complexity: Since each element will be compared with its all prev elements in the newly formed
array O(n^2)
Space complexity: O(n) //table size is reduced here as compared to method1
*/

//METHOD2
#include <stdio.h>
#include <stdlib.h>

void longestIncreasingSub(int *arr, int size){
	int sol[size];
	int i,j;
	sol[0] = 1; //base solution cannot be greater than 1.
	int maxLength = 1;
	int start = 0, end = 0;
	int overallMax = 1;
	for(i=1;i<size;i++){
		int currentMax = 1;
		for(j=i-1;j>=0;j--){
			int key = 1;
			if(arr[i] > arr[j]){
				key = key + sol[j];
				if(currentMax < key){
					currentMax = key;
				}
			}
			sol[i] = currentMax;
		}
		if(overallMax < sol[i]){
			overallMax = sol[i];
			end = i;
		}
	}

	printf("total length of subsequence is: %d\n", overallMax);
	printf("subsequence is:\n");

	//for printing maybe a struct can be taken and element index for which current max
	//is computed is noted down. That will be the answer Iterate like this backwards for all		

}

int main(){
	int arr[] = {2,3,1,5,12,10,11};
	int size = sizeof(arr)/sizeof(arr[0]);

	longestIncreasingSub(arr,size);
	return 0;
}
