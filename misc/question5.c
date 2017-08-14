/*
TO BE DONE

http://practice.geeksforgeeks.org/problems/maximize-dot-product/0
*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long int findProduct(int n, int m int *a, int *b){
	
	unsigned long long int dp[n+1][m+1];

	memset(dp,0,sizeof(dp[0][0]));

	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%llu ", dp[i][j]);
		}
		printf("\n");
	}



}

int main(){
	int cases;
	scanf("%d", &cases);
	int i;
	int n,m;

	for(i=0;i<cases;i++){
		scanf("%d %d", &n, &m);
		int a[n];
		int b[m];
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		for(j=0;j<m;j++){
			scanf("%d",&b[j]);
		}
		
		printf("%llu\n", findProduct(n,m,a,b));
	}
	return 0;
}

// struct node{
// 	int index;
// 	int value;
// 	struct node *next;
// };


// void minHeapify(struct node *arr,int i, int size){
// 	int left = 2*i+1,right=2*i+2,smallest, heapSize = size;
// 	if(left <= heapSize-1 && arr[i].value < arr[left].value){
// 		smallest = i;
// 	}else{
// 		smallest = left;
// 	}
// 	if(right <= heapSize-1 && arr[right].value < arr[smallest].value){
// 		smallest = right;
// 	}
// 	if(smallest <= heapSize - 1 && smallest !=i){
// 		struct node *temp = (struct node *)malloc(sizeof(struct node));
// 		temp->value = arr[smallest].value;
// 		temp->index = arr[smallest].index;

// 		arr[smallest].index = arr[i].index;
// 		arr[smallest].value = arr[i].value;

// 		arr[i].value = temp->value;
// 		arr[i].index = temp->index;
// 		minHeapify(arr,smallest,size);
// 	}
// }

// int deleteMax(struct node *arr, int *size){
// 	if(*size < 1){
// 		return -1;
// 	}
// 	struct node *temp = (struct node *)malloc(sizeof(struct node));
// 	int result = arr[0].value;
// 	arr[0] = arr[*size-1];
// 	*size = *size-1;
// 	maxHeapify(arr,0,*size);
// 	return result;
// }

// unsigned long long int findProduct(int n, int m, int *a, int *b){
	
// 	int diff = n-m;
// 	unsigned long long int prod = 0;
	
// 	int index = floor(n/2);
// 	int i;

// 	struct node *copyArr[n];

// 	for(i=0;i<n;i++){
// 		copyArr[i].value = a[i];
// 		copyArr[i].index = i;
// 	}

// 	for(i = index; i>=0;i--){
// 		minHeapify(copyArr,i,size);
// 	}
	


// 	int j = 0;
// 	i = 0;	
// 	while(i < n && j < m){
// 		prod += a[j]*b[j];
// 		i++;
// 		j++;
// 	}	
	
// 	return prod;
// }

// int main(){
// 	int cases;
// 	scanf("%d", &cases);
// 	int i;
// 	int n,m;

// 	for(i=0;i<cases;i++){
// 		scanf("%d %d", &n, &m);
// 		int a[n];
// 		int b[m];
// 		int j;
// 		for(j=0;j<n;j++){
// 			scanf("%d",&a[j]);
// 		}
// 		for(j=0;j<m;j++){
// 			scanf("%d",&b[j]);
// 		}
		
// 		printf("%llu\n", findProduct(n,m,a,b));
// 	}
// 	return 0;
// }