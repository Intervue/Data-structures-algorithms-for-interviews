/*
Find the duplicate in O(n) time and O(1) extra space
Only valid for numbers in range 1 to N

Method: In this we visit a number lets say its 3, we go to index 3 and make the number there
negative. Then if 3 is repeated we will again go to 3 and check if its already negative.
Time complexity: O(n)
Space complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

	int a[] = {1,2,3,5,8,1,1,2};
	int size = sizeof(a)/sizeof(a[0]);
	
	for(int i=0;i<size;i++){
		if(a[abs(a[i])] > 0){
			a[abs(a[i])] = -1*a[abs(a[i])];	
		}else{
			printf("%d\n", abs(a[i]));
		}
	}
}