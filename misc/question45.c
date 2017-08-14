/*
http://practice.geeksforgeeks.org/problems/activity-selection/0
*/
#include <stdio.h>
#include <stdlib.h>

struct pair{
	int a;
	int b;
};

int cmpfnc(const void *a, const void *b){
	const struct pair *p1 = a;
	const struct pair *p2 = b;

	if(p1->b > p2->b){
		return 1;
	}else if(p1->b < p2->b){
		return -1;
	}else{
		return 0;
	}	

}

int maxAct(int *start, int *end, int size){
	int i;
	struct pair ref[size];
	for(i=0;i<size;i++){
		ref[i].a = start[i];
		ref[i].b = end[i];
	}
	int j;
	qsort(ref, size, sizeof(struct pair), cmpfnc);

	// printf("-------------\n");
	// for(i=0;i<size;i++){
		// printf("(%d, %d)  ", ref[i].a, ref[i].b);
	// }
	// printf("\n");


	int lis[size];
	for(i=0;i<size;i++){
		lis[i] = 1;
	}

	int max = 1;

	for(i=1;i<size;i++){
		for(j=i-1;j>=0;j--){
			if(ref[i].a > ref[j].b){

				if(lis[i] <= lis[j] + 1){
					lis[i] = lis[j] + lis[i];
				}
				if(max < lis[i]){
					max = lis[i];
				}
				// lis[i] = findMax(lis[i],1 + lis[j]);
				// printf("updating value of lis[%d] to %d\n", i, lis[i]);
				// max = findMax(lis[i], max);
			}
		}
	}
	// printf("-------------\n");
	// for(i=0;i<size;i++){
		// printf("%d ", lis[i]);
	// }
	// printf("\n");

	return max;

}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int start[n];
		int end[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&start[j]);
		}
		for(j=0;j<n;j++){
			scanf("%d",&end[j]);
		}

		printf("%d\n", maxAct(start,end, n));

	}
	return 0;
}