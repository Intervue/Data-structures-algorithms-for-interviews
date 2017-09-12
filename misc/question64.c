/*
http://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minJumps(int *arr, int size) {

	int i;
	int ref[size];
	for(i=0; i<size;i++) {
		ref[i] = 1;
	}

	ref[size-1] = 0;

	for(i=size-2;i>=0;i--) {

		int value = arr[i];
		int j = i;
		int min = 2000;
		while(j < size  && value) {
			j++;
			if(min > ref[j]) {
				min = ref[j];
			}
			value--;
		}
		// printf("value of min  is %d\n", min);
		ref[i] += min;
		// printf("ref[%d] is %d\n",i, ref[i]);
	}

	if(ref[0] >= 2000) {
		return -1;
	}

	return ref[0];

}

int main() {
	
	int cases;
	int i;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		int size;
		scanf("%d",&size);
		int arr[size];
		int j;
		for(j=0;j<size;j++){
			scanf("%d",&arr[j]);
		}
		printf("%d\n", minJumps(arr, size));
	}
	return 0;
}