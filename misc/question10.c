/*
http://practice.geeksforgeeks.org/problems/the-smurfs/0
The smurfs

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkSmurfs(int rcount, int gcount, int bcount, char *str){
	int n = rcount + gcount + bcount;
	if(rcount == n || gcount == n || bcount == n){
		return n;
	}

	if(((rcount & 1) && (bcount & 1) && (gcount & 1)) || (!(rcount & 1) && !(bcount & 1) && !(gcount & 1))){
		return 2;
	}
	return 1;
}

int main(){

	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int j;
		char str[3000];
		getchar();
		int rcount = 0, gcount = 0, bcount = 0;
		for(j=0;j<2*n;j++){
			scanf("%c",&str[j]);
			if(str[j] == 'R'){
				rcount++;
			}
			if(str[j] == 'G'){
				gcount++;
			}
			if(str[j] == 'B'){
				bcount++;
			}
		}

		printf("%d\n", checkSmurfs(rcount, bcount, gcount,str));
	}

	return 0;
}