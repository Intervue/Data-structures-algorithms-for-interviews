/*
Find max intervals from given intervals such that none of them are overlapping

METHOD:
we can go by three methods here but only one works fine
Greedy about duration: Thought process is to be greedy about duration and choose the one with min
duration so that probability of overlapping is less. But in this case if a short duration is
overlapping in between two big durations, we wont be able to pick the other two. So wont give us the
max output

Greedy about start time. Choose start time as early as possible. That can minimize overlapping. But
if something starts very early and ends really late, we wont be able to pick the other durations cos
of that

Greedy about end time: This is the correct method because in this case we can have max outputs.

*/
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

struct node{
	int left;
	int right;
};

int maxIntervals(struct node *arr, int size){
	int counter = 1;
	for(int i=0; i<size-1; i++){
		if(arr[i].right < arr[i+1].left){
			counter++;			
		}
	}
	if(counter == 1){
		return counter;
	}
	return counter+1;
}

int main(){
	int size = 6;
	struct node *arr = (struct node *)malloc(sizeof(struct node)*size);
	
	arr[0].right = 11;
	arr[0].left = 7;
	
	arr[1].right = 13;
	arr[1].left = 10;

	arr[2].right = 14;
	arr[2].left = 9;

	arr[3].right = 16;
	arr[3].left = 12;

	arr[4].right = 25;
	arr[4].left = 20;

	arr[5].right = 50;
	arr[5].left = 1;

	//already sorted
	int max = maxIntervals(arr,size);
	printf("max intervals are %d\n", max);
	return 0;
}