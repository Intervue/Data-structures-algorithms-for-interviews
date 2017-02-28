/*
Find the triplet in given array that sum to given value 'x'

METHOD1:
Find all possible combinations
Time complexity: O(n^3)
Space complexity: O(1)

METHOD2:
Sorting and then fixing one number and using two pointers one at 1st position and 1 at last, and checking combinations.
If nothing found fixing the next number and trying again
Time complexity: O(nlogn) + O(n^2) which is O(n^2)
Best case:O(n^2) worst case
Worst case: O(n)
Space complexity: O(1)

*/

// METHOD1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int a[] = {4,3,6,8,2,1,0,9};		
	int length = sizeof(a)/sizeof(a[0]);
	int i,j,k, sum;

	for(i=0; i<length;i++){
		int num1 = a[i];
		for (j=i+1; j<length;j++){
			int num2 = a[j];
			for(k=j+1;k<length;k++){
				sum = num1 + num2 + a[k];

				if(sum == 10){
					printf("elements whose sum is %d are %d, %d and %d\n", 10,num1,num2,a[k]);
				}

			}
		}
	}
}

//METHOD2
#include <stdio.h>
#include <stdlib.h>

int compar(void const*a, void const *b){
	return (*(int*)a-*(int*)b);
}

int main(){
	int a[] = {4,3,6,8,2,1,0,9};
	int length = sizeof(a)/sizeof(a[0]);

	qsort(a,length,sizeof(int),compar);

	int num1, num2, num3,j,k, sum = 10;

	for(int i=0; i<length-2;i++){ //as last two will be covered in while loop always for second and third num
		num1 = a[i];
		j = i+1;
		k = length-1;
			
		while(j<k){
			num2 = a[j];
			num3 = a[k];
			if(num1 + num2 + num3 == sum){
				printf("the numbers whose sum is %d are %d, %d and %d\n", 10,num1,num2,num3);
			}
			if(num1 + num2 + num3 > sum){
				k--;
			}else{
				j++;
			}		
		}
	}

}

