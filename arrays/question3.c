/*
MERGE SORT

Space complexity: stack O(logn) + space for merge procedure O(n)
Therefore total = O(n)

Time complexity: time taken to merge O(n) + time taken to sort by masters theorem O(nlogn)
Therefore: O(nlogn) 

*/
#include <stdio.h>
#include <math.h>

void print_array(int arr[], int n){
	printf("value of n %d\n",n);
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
}

void merge(int arr[],int p, int q, int r){
	long unsigned int f = INFINITY;
	int n1,n2,i,j;
	n1 = q-p+1;
	n2 = r-q;

	int left[n1+1],right[n2+1];
	for(i=0; i<n1;i++){
		left[i]=arr[i];
	}
	for(j=0; j<n2;j++){
		right[j]=arr[q+j+1];
	}
	left[n1]=right[n2]=f;
	i=j=0;
	for(int k=0; k<(r-p+1); k++){
		if(left[i]<right[j]){
			arr[k]=left[i];
			i++;
		}else{
			arr[k]=right[j];
			j++;
		}
	}
	print_array(arr,(r-p+1));
}

void merge_sort(int arr[],int p,int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

int main(){
	int a[6] = {5,6,9,0,2,8};
	int p = 1;
	int size = 6;
	int q = (p+size)/2;
	merge_sort(a,p,size);
}