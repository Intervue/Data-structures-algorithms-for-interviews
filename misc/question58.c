/*
http://practice.geeksforgeeks.org/problems/lets-play/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int start, int end, int *arr){
	int i= start, j=end;
	int temp;
	while(i<=j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

int left(int rowNum, int *temp, int rows, int cols, int arr[rows][cols], int x) {
	
	int i;
	for(i=0;i<cols;i++){
		temp[i] = arr[rowNum][i];
	}
	int size = cols;
	reverse(0, x-1, temp);
	reverse(x,size-1, temp);
	reverse(0,size-1, temp);

	for(i=0;i<cols;i++) {
		if(temp[i] != arr[rowNum][i]){
			return 0;
		}
	}

	return 1;
}

int right(int rowNum, int *temp, int rows, int cols, int arr[rows][cols], int x) {
	
	int i;
	for(i=0;i<cols;i++){
		temp[i] = arr[rowNum][i];
	}
	int size = cols;
	reverse(size-x, size-1, temp);
	reverse(0,size-x-1,temp);
	reverse(0,size-1, temp);
	
	for(i=0;i<cols;i++) {
		if(temp[i] != arr[rowNum][i]){
			return 0;
		}
	}

	return 1;
}

int isEqual(int rows, int cols, int arr[rows][cols], int x) {

	int temp[cols];

	int i,j;

	for(i=0;i<rows;i++){
		if(i%2 == 0){
			if(!right(i, temp, rows, cols, arr, x)) {
				return 0;
			}
		}else{
			if(!left(i, temp, rows, cols, arr, x)) {
				return 0;
			}
		}
	}

	return 1;
}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++) {
		int n,m,x;
		scanf("%d %d",&n,&m);
		int arr[n][m];
		int k,l;
		for(k=0;k<n;k++){
			for(l=0;l<m;l++){
				scanf("%d",&arr[k][l]);
			}
		}
		scanf("%d",&x);
		printf("%d\n", isEqual(n,m,arr,x));
	}
	return 0;
}