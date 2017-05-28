#include <stdio.h>
#include <stdlib.h>

int checkOperations(int *arr, int size){
	int sum = 0;
	if(size%2==0){
		int sum1 = 0;
	
		sum1 = sum1 + arr[0];
		arr[0] = 0;
		int i,j;
		for(i=1; i<=(size/2);i++){
			sum1 += (arr[i]-i);
		}
		int sub = 1;
		for(j=size-1;j>=(size/2)+1;j--){
			sum1 += (arr[j]-sub);
			sub++;
		}

		int sum2 = 0;
		sum2 = sum2 + arr[size-1];
		arr[size-1] = 0;
		int k,l;
		for(k=0; k<=(size-1)/2;k++){
			sum2 += (arr[k]-(k+1));
		}	
		int val = 1;
		for(l=(size-2);l>=(((size-1)/2)+1);l--){
			sum2 += (arr[l]-val);
			val++;
		}
		sum = (sum1 < sum2)?sum1:sum2;
		
	}else{
		int i,j;
		for(i=0; i<=(size/2);i++){
			sum += (arr[i]-(i+1));
		}
		int sub = 1;
		for(j=size-1;j>=(size/2)+1;j--){
			sum += (arr[j]-sub);
			sub++;
		}
	}
	return sum;
}


int checkOperations(int *arr, int start, int end){

	int middle = (start-end)/2;
	int size = end+1;
	int value = (size/2)+1;

	if(arr[middle] >= value || arr[middle-1] >=value){
		return calculate(arr,start, end);
	}
	int subSize;
	if(size%2==0){
		subSize = size-3;
	}else{
		subSize= size-2;
	}

	int i;
	for(i=0;i<size-subSize;i++){
		j=subSize;
		checkOperations(arr,i,j);
	}
	
}

int main(){
	int cases,blocks;
	scanf("%d",&cases);
	int i, j;
	for(i=0;i<cases;i++){
		scanf("%d",&blocks);
		int arr[blocks];
		for(j=0;j<blocks;j++){
			scanf("%d",&arr[j]);
		}
		int number = checkOperations(arr,0,blocks-1);
		printf("%d\n", number);
	}
	return 0;
}