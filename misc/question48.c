/*
http://practice.geeksforgeeks.org/problems/collecting-trees/0
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findTrees(int n){
	
	int count = 0;
	int power; //this will basically store the value and not the power
	while(n > 0){
		power = pow(2,floor(log(n)/log(2)));
		n = n - power;
		count++;
	}

	return count;
}



int main(){

	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d", &n);

		printf("%d\n", findTrees(n));
	}
}