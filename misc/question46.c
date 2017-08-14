/*
http://practice.geeksforgeeks.org/problems/flip-bits/0
*/

#include <stdio.h>
#include <stdlib.h>

int maxOnes(int *arr, int size){
	int i,j;

	int ref[size];
	int totalOnes = 0;

	if(arr[0] == 1){
		ref[0] = 0;
		totalOnes++;
	}else{
		ref[0] = 1;
	}

	int max_so_far = 0;

	for(i=1;i<size;i++){
		if(arr[i] == 1){
			totalOnes++;
			if(ref[i-1] - 1 < 0){
				ref[i] = 0;	
			}else{
				ref[i] = ref[i-1] - 1;	
			}
		}else{
			ref[i] = ref[i-1] + 1;
		}

		if(max_so_far < ref[i]){
			max_so_far = ref[i];
		}

	}

	return (totalOnes + max_so_far);

}

int main(){
	int cases;
	int i;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int arr[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		printf("%d\n", maxOnes(arr, n));
	}
	return 0;
}