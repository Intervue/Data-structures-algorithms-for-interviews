/*
Separate 0's and 1's from a given array

METHOD1:
Counting sort
Time complexity: O(n)
Space complexity: O(1)

Partition algo swapping: two pointers will be used to traverse from opposite directions and 1's and 0's will be swapped
Time complexity: O(n)
Space complexity: O(1)

*/


//METHOD1
#include <stdio.h>

int main(){

	int a[] = {1,0,1,1,0,1,0};
	int length = sizeof(a)/sizeof(a[0]);
	int c[2];

	int i,j;	

	for(i=0; i<2; i++){
		c[i] = 0;
	}

	for(i=0; i<length; i++){
		c[a[i]] = c[a[i]] + 1;
	}
	
	for(i=1; i<2; i++){
		c[i] = c[i-1] + c[i];
	}

	for(i=0; i<length;i++){
		a[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}

	for(i=0; i<length;i++){
		printf("%d ", a[i]);
	}

}


//METHOD2
#include <stdio.h>

int main(){

	int a[] = {1,0,1,1,0,1,0};
	int length = sizeof(a)/sizeof(a[0]);
	
	int i=0,j=length-1, temp;
	
	while(i<=j){

		if(a[i] == 1){
			if(a[j]==0){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
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




