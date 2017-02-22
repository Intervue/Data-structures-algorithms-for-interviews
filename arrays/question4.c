/*
PARTITION PROCEDURE

Time complexity: O(n)
Space complexity: O(1)

Can be remembered as partitioning everytime choosing an element
left all small, right all big
*/
#include <stdio.h>
#include <math.h>

void partition(int arr[],int p, int r){
	int key = arr[r];
	int i, j=-1, temp;
	for(i=p; i<r; i++){
		if(arr[i] < key){
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

	printf("value of new array is\n");

	for(int z=0; z<r+1;z++){
		printf("%d ", arr[z]);
	}

}


int main(){

	int a[] = {9,6,5,0,8,2,4,7};
	int length = sizeof(a)/sizeof(a[0]);

	printf("the length of the array is %d ", length);

	partition(a,0, length-1);
}