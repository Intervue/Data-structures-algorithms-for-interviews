/*
find a pair in an array whose sum is equal to a given number
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*METHOD1: by iterating and find suitable pairs
Time complexity: O(n^2) time
*/

int main(){
	
	int a[] = {2,5,8,1,4,5};
	int j;

	printf("pairs whose sum is 6 are\n");

	for(int i=0; i<6;i++){
		int key1 = a[i];
		
		for(j=i+1;j<6;j++){
			int key2 = a[j];
			
			if(key1+key2 == 6){
				printf("%d and %d ",key1,key2);
				printf("\n");
			}	

		}
	}

}
/*METHOD2: hash table
Insert all numbers into a hash table. O(n)
For every element a, search b in hash table such that sum is x O(1)

Time complexity: O(n) time
Space complexity: size of hash O(n) time
*/

#include <stdio.h>
#define MAX 10

void findPairs(int arr[],int size,int sum){

	int index,temp;
	int hash[MAX] = {0};

	for(index = 0; index<size; index++){

		temp = sum - arr[index];
		if(temp>=0 && hash[temp] == 1){
			printf("Pair with the given sum %d is %d and %d ", sum,temp,arr[index]);
		}
		hash[arr[index]]=1;
	}

}

int main(){
	int a[] = {2,5,8,1,4,5};

	int length = sizeof(a)/sizeof(a[0]);

	int sum = 9;

	findPairs(a,length, sum);

}
/*
METHOD3: using quick sort technique
but finding if a pair exists or not
*/
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void*a, const void*b){
	return (*(int*)a-*(int*)b);
}

int findPairs(int arr[], int size, int sum){
	int left, right;

	qsort(arr,size,sizeof(int),cmpfunc);

	left = 0;
	right = size - 1;
	while(left<right){
		if(arr[left]+arr[right]==sum){
			return 1;
		}else if(arr[left]+arr[right]<sum){
			left++;
		}else{
			right--;
		}
	}
}

int main(){
	int size, index, sum, *arr;
	printf("enter number of elements in the array\n");
	scanf("%d",&size);
	//allocate memory for array
	arr = (int *)malloc(sizeof(int)*size);
	printf("enter the elements of the array\n");
	for(index=0; index<size; index++){
		scanf("%d",&arr[index]);
	}
	printf("enter the sum value\n");
	scanf("%d",&sum);
	if(findPairs(arr,size,sum)){
		printf("Pairs found\n");
	}else{
		printf("Pairs not found\n");
	}

}
