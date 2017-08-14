/*
http://practice.geeksforgeeks.org/problems/chinky-and-diamonds/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxDiamonds(int size, int min, int *arr){

	int i,j;
	int sum = 0, max, index;

	for(i=0;i<min;i++){
		max = arr[0];
		index = 0;		
		for(j=1;j<size;j++){
			if(max < arr[j]){
				max = arr[j];
				index = j;
			}
		}
		// printf("adding %d to sum\n", max);
		// printf("updated array...\n");
		// int k;
		// for(k=0;k<size;k++){
		// 	printf("%d ", arr[k]);
		// }
		// printf("\n");
		// printf("--------------------\n");
		sum += max;
		arr[index] = arr[index]/2;
	}

	return sum;
}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n,k;
		scanf("%d %d",&n,&k);
		int arr[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}

		printf("%d\n", maxDiamonds(n,k,arr));

	}
	return 0;
}