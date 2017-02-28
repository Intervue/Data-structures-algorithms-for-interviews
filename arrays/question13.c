/*
Seperate even and odd numbers using partition method for separating 0's and 1's

Time complexity: O(n)
Space complexity: O(1)
*/

//METHOD1
#include <stdio.h>

int main(){

	int a[] = {2,5,1,9,6,7,3,4};
	int length = sizeof(a)/sizeof(a[0]);

	int i=0,j=length-1,temp;

	while(i<j){
		if(a[i]%2==1){
			if(a[j]%2==0){

				temp = a[j];
				a[j]=a[i];
				a[i]=temp;
				i++;

			}else{
				j--;
			}
		}else{
			i++;
		}
	}

	for(int z=0; z<length;z++){
		printf("%d", a[z]);
	}
}