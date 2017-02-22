/*
BUBBLE SORT

Elements are compared in pairs to see if they are sorted, if not they are swapped
In each iteration one greatest element moves to its correct position.
It can be remembered as in each iteration the bubble(largest element) comes to the top (last in array)

Time Complexity:
Best case: O(n)
Worst case: O(n^2)

Space Complexity:
O(1)

*/
#include <stdio.h>
#include <math.h>

int main(){

	int a[] = {9,6,5,4,0,7,3,5,11};
	int length = sizeof(a)/sizeof(a[0]);
	int swapped,i,j;
	for(i=0; i<length;i++){
		swapped = 0;
		for(j=0;j<length-i-1;j++){
			if(a[j] > a[j+1]){
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				swapped = 1;
			}
		}
		if(swapped == 0){
			break;
		}
	}

	printf("sorted array is\n");
	for(int z=0; z<length; z++){
		printf("%d ", a[z]);
	}

}