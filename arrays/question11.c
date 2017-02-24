/*
Find the number occuring odd number of times in an array of size n given that exactly one number occurs odd
number of times

METHOD1: applying for loop for every element to and counting
Time complexity: O(n^2)
Space complexity: O(1)

METHOD2: applying hash table
Time complexity: O(n)
Space complexity: O(n) //size of the hash

METHOD3: SORTING and then counting
Time complexity: O(nlogn)
Space complexity: O(1)

METHOD4: XOR operation
XOR operation can be remembered as taking the sum of the bits and then dividing the sum by two, remainder is the answer
Time complexity: O(n)
Space complexity: O(1)

*/

//METHOD1
#include <stdio.h>

int main(){

	int a[] = {1,2,1,1,2};
	int length = sizeof(a)/sizeof(a[0]);
	int index, counter, oddNum;

	for(index = 0; index < length; index++){
		counter = 0;
		int key = a[index];
		for(int j=0; j<length;j++){
			if(key == a[j]){
				counter++;
			}
		}
		
		if(counter%2 != 0){
			oddNum = key;
			printf("odd number is %d\n", oddNum);
		}
	}
}

//METHOD2
#include <stdio.h>

int findMax(int arr[], int size){
	int max = arr[0];
	for(int j=1; j<size; j++){
		if(max < arr[j]){
			max = arr[j];
		}
	}
	return max;
}

int main(){

	int a[] = {4,4,4,1,1};
	int length = sizeof(a)/sizeof(a[0]);

	int max = findMax(a,length);
	int hash[max+1];	
	int index;

	for(int i = 0; i<max+1;i++){
		hash[i]=0;
	}

	for(index = 0; index<length;index++){
		hash[a[index]]++;
	}

	for(int i = 0; i<max+1;i++){
		if(hash[i]%2 !=0 ){
			printf("Number repeating odd number of times is %d\n", i);
		}
	}
}

//METHOD3
#include <stdio.h>
#include <stdlib.h>
int compar(const void*a, const void *b){
	return (*(int*)a-*(int*)b);
}

int main(){

	int a[] = {1,3,1,3,2,8,8,4,4,4,2,2};
	int length = sizeof(a)/sizeof(a[0]);
	qsort(a,length, sizeof(int),compar);

	int num = a[0], counter = 1;	
	for(int i=1; i<length; i++){
		if(num == a[i]){
			counter++;
		}else{
			if(counter%2 !=0){
				printf("number reapeating odd number of times is %d\n", num);
			}
			num = a[i];
			counter = 1;
		}
	}
}

//METHOD4
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a[] = {1,3,1,3,2,8,8,4,4,2,2};
	int length = sizeof(a)/sizeof(a[0]);

	int xor = 0;

	for(int i=0; i<length; i++){
		xor ^= a[i];
	}	

	printf("number repeating odd number of times is %d \n", xor);
}


