/*
Rearrange the string such that same characters are d distance away

The idea is to pick the characters with the highest frequency first and rearrange them.
Therefore we use a hashtable to store the frequencies of each character and build a max heap out of it.
Then we extract max one by one and place it as closer as possible given value of d in the string.
Then we keep doing that for all the freq in descending order

Time complexity: O(n) //since size of max heap is constant all operations will have cosntant time value.
Space complexity: O(1) //since 256 will be the size of hash table at max which will also be the size of
max heap and hence it is not dependent on the input
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

struct hash{
	char c;
	int count;
};

void maxHeapify(struct hash *hashTable,int i, int size){
	int left = 2*i+1;
	int right = 2*i+2;
	int largest;
	if(left < size && hashTable[left].count > hashTable[i].count){
		largest = left;
	}else{
		largest = i;
	}
	if(right < size && hashTable[right].count > hashTable[largest].count){
		largest = right;
	}

	if(largest < size && largest != i){
		int temp_count = hashTable[i].count;
		char temp_c = hashTable[i].c;
		hashTable[i].c = hashTable[largest].c; 
		hashTable[i].count = hashTable[largest].count;
		hashTable[largest].c = temp_c;
		hashTable[largest].count = temp_count;

		maxHeapify(hashTable,largest,size);
	}

}

void buildMaxHeap(struct hash *hashTable, int size){
	int index = (size/2)-1;
	int i;
	for(i=index; i>=0;i--){
		maxHeapify(hashTable,i,size);
	}
}

void maxHeap(struct hash *hashTable){
	for(int i=0;i<MAX;i++){
		printf("%c , %d\n", hashTable[i].c, hashTable[i].count);
	}
}

struct hash *extractMax(struct hash *hashTable, int *size){
	if(*size == 0){
		return NULL;
	}
	printf("extract running %d\n",hashTable[0].count);
	struct hash *temp = &hashTable[0];
	

	int count = hashTable[0].count;
	char c = hashTable[0].c;

	hashTable[0].count = hashTable[*size-1].count;
	hashTable[0].c = hashTable[*size-1].c;
	*size = *size - 1;
	maxHeapify(hashTable,0,*size);

	temp->count = count;
	temp->c = c;
	printf("value assigned is %d\n", temp->count);
	printf("char assigned is %c\n", temp->c);
	return temp;
}


void reArrange(char *arr, int d){
	int length = strlen(arr);
	int max = MAX;
	struct hash *hashTable = (struct hash *)calloc(max,sizeof(struct hash));
	int i,j;
	for(i=0;i<length;i++){
		hashTable[arr[i]].c = arr[i];
		hashTable[arr[i]].count++;
		arr[i]='\0';
	}

	buildMaxHeap(hashTable, max);

	printf("now extracting...\n");
	struct hash *temp = extractMax(hashTable, &max);
	printf("%d\n", temp->count);
	printf("-------------------------------------\n");
	temp = extractMax(hashTable, &max);
	printf("%d\n", temp->count);

	
}

int main(){
	char arr[] = "aab";
	int d = 2;

	reArrange(arr, d);
	return 0;
}