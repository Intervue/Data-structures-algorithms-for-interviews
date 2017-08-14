/*
Merge K sorted linked lists of size N into one sorted linked list

METHOD1:
Naive approach where each linked list is merged into the other one by one
Time complexity: O(K^2 N^2)
Space complexity: O(1)

METHOD2:
USING MIN HEAP. min heap is made using the first k elements (first element of each list) and then delete min
and add the next node of that list to the heap it it exists.
Apeend the deleted node from the heap to the merged list
Keep repeating until heap becomes empty
Time complexity:
O(logk) to delete and add element. Therefore O(2logK)
total elements KN-K
heap is made out of K elements initially O(K)
Total: O(KN-K)logK
Space complexity: O(k)//size of the heap

METHOD3:
By divide and conquer. We join two lists at a time and leave the result there until all linked lists taken
two at a time are merged. We move to the second level where each linked list now has 2N elements.
Now we again take two at a time to make 4N elements and keep doing that until we reach KN elements.
By analysis it is found that the number of steps required to merge them to KN is logK
total number of work done at each step is equal to moving KN elements to the next step.
Time complexity: O(KNlogK)
Space complexity: O(1)

METHOD4:
If we use a binary search tree instead of min heap, chances are that the tree might get skewed and to add each
node further may take O(k) time. Delete may also take O(k) time
Therefore total time complexity will come out to be O(k^2 N). There using min-heap was a better option.
If time complexity in binary search tree is to be reduced, you will have to keep it balanced (so rotation is 
required). But that is costly.
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct link{
	int val;
	struct node *head;
};

struct node *newNode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct node *mergeSorted(struct node *list1, struct node *list2){

	struct node *result = NULL;

	if(!list1){
		return list2;
	}
	if(!list2){
		return list1;
	}

	if(list1->data <= list2->data){
		result = list1;
		result->next = mergeSorted(list1->next, list2);
	}else{
		result = list2;
		result->next = mergeSorted(list1, list2->next);
	}

	return result;

}

struct node *mergeAll(struct link *arr, int last){

	while(last){
		int start = 0, end = last;
		
		while(start < end){
			arr[start].head = mergeSorted(arr[start].head, arr[end].head);
			start++;
			end--;

			if(start >= end){
				last = end;
			}

		}
	}

	return arr[0].head;
}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int n;
		scanf("%d",&n);
		int j;
		struct link arr[n];
		for(j=0;j<n;j++){
			int elm;
			scanf("%d", &elm);
			int k;
			arr[j].val = elm;
			
			struct node *move = NULL;
			for(k=0;k<elm;k++){
				int val;
				scanf("%d",&val);
			
				struct node *temp = newNode(val);
				if(move){
					move->next = temp;	
					move = move->next;
				}else{
					move = temp;
					arr[j].head = move;
				}
			}
			
		}

		struct node *temp = mergeAll(arr, n-1);	

		while(temp){
			printf("%d --> ", temp->data);
			temp = temp->next;
		}

	}
	return 0;
}

