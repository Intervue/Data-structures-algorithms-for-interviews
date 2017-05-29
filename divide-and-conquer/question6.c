/*
Find the missing number in arithmetic progression

METHOD1:
we need to find the common difference first. For that a reliable approach is, we have the size of array
and the last term available to us and the first term also is there. Therefore by applying
a+(n-1)d we can find the cd.
Once we have cd, we can simply do a linear search by increment with cd and see which element is missing
Time complexity: O(n) //finding cd is a constant time operation.
Space complexity: O(1)

METHOD2:
We find the cd as stated in the above method. Now, we apply binary search. We find the middle element. its
index is known. BY a+(n-1)d we see whether middle element is equal to what it should be or not. If equal
search in the right array else search in the left array. Keep doing this. At one point if left array if 
no longer there then middle element index is the culprit.
Time complexity: O(logn)
Space complexity :O(1) or O(logn) //iterative or recursive
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int index;
	int elm;
};

struct node *newNode(int index, int elm){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->index = index;
	temp->elm = elm;
	return temp;
}

struct node *searchMissing(int *arr, int start, int end, int cd){
	if(start > end){
		return NULL;
	}
	int mid = (start + end)/2;
	int tmid = arr[0] + mid*cd;
	struct node *temp = NULL;
	if(mid>0 && arr[mid]-arr[mid-1] != cd){ //checking to the left and right of
		temp = newNode(mid, arr[mid-1]+cd);
		return temp;
	}
	if(arr[mid+1]-arr[mid] != cd){
		temp = newNode(mid+1,arr[mid]+cd);
		return temp;
	}
	struct node *left = NULL; struct node *right= NULL;
	if(arr[mid] == tmid){
		return searchMissing(arr,mid+1,end,cd);
	}
	return searchMissing(arr,start,mid-1,cd);
}

int findDifference(int *arr, int size){
	int temp = (arr[size-1]-arr[0])/(size-1);
}

int main(){
	int arr[] = {-2,0,4,6,8,10,12,14,16,18,20};
	int size = sizeof(arr)/sizeof(arr[0]);

	int cd = findDifference(arr,size);
	
	struct node *missing = searchMissing(arr,0,size-1,cd);
	if(missing){
		printf("missing element is %d should be at index %d\n", missing->elm,missing->index);
	}else{
		printf("no element is missing");
	}
	return 0;
}

