/*
http://practice.geeksforgeeks.org/problems/power-of-2/0
*/

#include <stdio.h>
#include <stdlib.h>

int isPower(unsigned long long int num) {
	return (num && !(num & (num - 1)));
}

int main(){
	int cases;
	int i;
	scanf("%d", &cases);
	for(i=0;i<cases;++i){
		unsigned long long int num;
		scanf("%llu", &num);

		int ans = isPower(num);
		if(ans){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}
	return 0;
}