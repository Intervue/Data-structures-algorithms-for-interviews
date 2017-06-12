/*
Find the longest subsequence in an array such that elements are consecutive

Eg picking 10 from 2nd index 11 from 10th index and 12 from 15th index
but 10 11 12 are consecutive as natural numbers


METHOD1:
Sort the array, then traverse it once to find the longest subsequence which contains consecutive 
elements

Time complexity: O(nlogn)
Space complexity: O(1)

METHOD2:
Maintain a hash table with elements that are present marked as 1. Now scan the array again and
for the first number see all the consecutive numbers lesser than that to find the starting value
of the sequence. Once found, see numbers greater than that, that are consecutive to find out
end of sub sequence. Once numbers are visited or made part of a subsequence, mark them as processed
by maintaining a flag. Repeat this for all numbers and output a longest subsequence.

Time complexity: O(n)
//as in worst case all elements will be examined twice in the second traversal.

Space complexity: O(n)
*/
//METHOD1
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

void longestSubSeq(int *arr, int size){
	int i;
	int start,end=0,length=1;
	int maxLength = 0;
	for(i=0;i<size-1;i++){
		if(arr[i+1] - arr[i] == 1){
			length++;
			if(length > maxLength){
				maxLength = length;
				end = i;
			}
		}else{
			length = 1;
		}
	}
	end = end + 1;
	start = end-maxLength+1;
	
	//print the subsequence
	for(i=start;i<=end;i++){
		printf("%d\n", arr[i]);
	}

}

int main(){
	int arr[] = {15,14,10,4,3,11,13,5,6,12,7};

	int size = sizeof(arr)/sizeof(arr[0]);

	qsort(arr,size,sizeof(int),cmpfunc);

	longestSubSeq(arr, size);
	return 0;
}

//================================================
//METHOD2:
#include <stdio.h>
#include <stdlib.h>

struct hash{
	int data;
};

void find(int *arr, int size){
	struct hash *hashArr = (struct hash *)malloc(sizeof(struct hash)*100); //fixed size

	printf("%c\n", hashArr[0].data);

	int i;
	for(i=0; i<size;i++){
		hashArr[arr[i]].data = 1;
	}
	int key, start, prev, maxLength = 0;
	int startIndex = 0, endIndex = 0;
	
	for(i=0;i<size;i++){
		key = arr[i];
		prev = arr[i];

		if(hashArr[key].data != 2){
			while(hashArr[key].data == 1){
				hashArr[key].data == 2;
				key--;
			}
			start = key+1;
			key = prev+1;
			while(hashArr[key].data == 1){
				hashArr[key].data = 2;
				key++;
			}
			prev = --key;
			if(maxLength < prev-start+1){
				maxLength = prev-start+1;
				startIndex = start;
				endIndex = prev;
			}
		}
	}
	int j;
	for(j=startIndex; j<=endIndex;j++){
		printf("%d\n", j);
	}
}

int main(){
	int arr[] = {10,4,3,11,13,5,6,12,7};
	int size = sizeof(arr)/sizeof(arr[0]);

	find(arr,size);

	return 0;
}