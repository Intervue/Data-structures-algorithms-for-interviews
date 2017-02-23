/*
COUNTING SORT
numbers to be sorted should be in a range eg (1-5) or (m to m+k)


Time complexity
O(n+k) k = range of numbers n= number of elemnts in input 

Space complexity = size of DS
O(k)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void count_sort(int a[], int b[], int range, int min, int length){
	int size = range+1;
	int c[size];
	int i,j;

	for(i=0;i<size;i++){
		c[i]=0;//initializing all elms in c to zero
	}
	for(i=0;i<length;i++){
		c[a[i]-min]++;
	}
	for(i=1; i<size;i++){
		c[i]=c[i-1]+c[i];
	}
	for(j=length-1;j>=0;j--){
		b[c[a[j]-min]-1]=a[j]; //-1 is done to match with 0 index
		c[a[j]-min]--;
	}
	//printing the array
	for(i=0; i<length;i++){
		printf("%d ", b[i]);
	}
}

int main(){
	int a[] = {5,6,8,5,9,5};
	int length = sizeof(a)/sizeof(a[0]);	
	int b[length];
	int range = 9-5; //max number
	int min = 5; //min number
	count_sort(a,b,range,min,length);
}