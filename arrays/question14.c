/*

Given an array A, find two elements whose sum is closest to zero

METHOD1:
Sorting and then iterating with two pointers one from beginning and one from ending

NOTE:
Hash maps cannot be applied in this case as number can even be negative and it can get confusing even if normalized

Time complexity: O(nlogn)
Space complexity: O(1)
*/

//METHOD1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compar(void const *a, void const *b){
	return (*(int*)a-*(int*)b);
}

int main(){
	long unsigned int f = INFINITY;

	int a[] = {5,10,-8,2,3,-5};
	int length = sizeof(a)/sizeof(a[0]);
	qsort(a, length, sizeof(int),compar);	
	int leftIndex=0, rightIndex=length-1,minSum = a[leftIndex] + a[rightIndex], sum = f;
	int elm1 = a[leftIndex], elm2 = a[rightIndex];

	while(leftIndex < rightIndex){
		if(abs(minSum-0) > abs(sum - 0)){
			minSum = sum;
			elm1 = a[leftIndex];
			elm2 = a[rightIndex];
		}
		if(sum > 0){
			rightIndex--;
		}else{
			leftIndex++;
		}
		sum = a[leftIndex] + a[rightIndex];
	} 

	printf("min sum is %d\n", minSum);
	printf("two numbers are %d and %d \n", elm1, elm2);

}