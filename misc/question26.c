/*
http://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits/0

Swap all odd and even bits	
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int modify(int n){
	int arr[8];

	int temp = n;

	int rem = temp%2;
	int quo;
	
	if(rem == 0){
		quo = temp/2;
	}else{
		quo = (temp-1)/2;
	}
	int i = 0;
	arr[i] = rem; 
	i++;

	while(quo > 0){
		rem = quo%2;
		arr[i] = rem;
		quo = (quo%2 == 0)? quo/2: (quo-1)/2;
		i++;
	}
	arr[i] = quo;
	int j = i;		
	for(j=i+1;i<8;i++){
		arr[i] = 0; 
	}	

	for(k=0;k<8;k++){
		int b = arr[k];
		arr[k] = arr[k+1];
		arr[k+1] = b;
		k++;
	}

	int num = 0;

	for(j=0;j<8;j++){
		num += arr[j]*pow(2,j);
	}
	
	return num;

}


int main(){
	int cases;
	scanf("%d",&cases);
	while(cases > 0){
		int n;
		scanf("%d",&n);
		printf("%d\n", modify(n));
		cases--;
	}
	return 0;
}