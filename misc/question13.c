#include <stdio.h>
#include <stdlib.h>
#define MAX 60

int cmpfnc(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

struct node{
	int index;
	int count;
	int value;
};

void freqSort(int *arr, int size){

	struct node ref[size];

	int i;

	for(i=0; i<)



}


int main(){
	int cases;
	scanf("%d",&cases);

	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int arr[n];
		int j;
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}

		printf("%d\n", freqSort(arr, n));

	}

}