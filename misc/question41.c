/*
http://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int index;
	int value;
};

struct hash{
	int index;
	int freq;
	int value;
};

int cmpfnc1(const void *a, const void *b){
	const struct node *p1 = a;
	const struct node *p2 = b;

	if(p1->value < p2->value){
		return -1;
	}else if(p1->value > p2->value){
		return 1;
	}else{
		return 0;
	}
}

void sortByFreq(int *arr, int size){



	struct node ref[size];
	int i;
	for(i=0;i<size;i++){
		ref[i].value = arr[i];
		ref[i].index = i;
	}	

	qsort(ref, size, sizeof(struct node), cmpfnc1);

	// for(i=0;i<size;i++){
	// 	printf("%d, %d \n", ref[i].value, ref[i].index);
	// }



	struct hash *h = (struct hash *)calloc(61, sizeof(struct hash));

	// for(i=0;i<size;i++){
	// 	h[ref[i].value]++;
	// 	h[ref[i].value].index = ref[i].index;
	// }

	// qsort(h, 61, sizeof(struct hash), cmfnc2);



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
		sortByFreq(arr,n);
	}
	return 0;
}