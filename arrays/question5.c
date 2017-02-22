/*
QUICK SORT

Time complexity: O(n)
Best case: O(nlogn)
Worst case: O(n^2) --- whenever pivot is at the end or beginning throughout recursion

Space complexity: 
Best case:
for balanced tree (height will be logn)
O(logn)

Worst case (height will be n):
O(n)
*/
#include <stdio.h>
#include <math.h>

int partition(int arr[],int p, int r){
	int key = arr[r];
	int i, j=p-1, temp;
	
	for(i=p; i<r; i++){
		if(arr[i] <= key){
			//swapping is small
			temp = arr[i];
			j++;
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//swapping j+1 with last element 'key'
	++j;
	arr[r]=arr[j];
	arr[j] = key;

	for(int z=0; z<r+1;z++){
		printf("%d ", arr[z]);
	}
	printf("\n");

	return j;

	printf("value of new array is\n");

	

}

void quick_sort(int arr[], int p, int r){
	int q;
	if(p<r){
		q = partition(arr,p,r);
		quick_sort(arr,p,q-1);
		quick_sort(arr,q+1,r);
	}
}
 
int main(){

	int a[] = {9,6,5,0,8,2,4,7};
	int length = sizeof(a)/sizeof(a[0]);

	printf("the length of the array is %d ", length);

	quick_sort(a,0, length-1);
}

