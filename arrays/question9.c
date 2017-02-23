/*
Given an array A of size n, find an element that occurs more than n/2 times

MOORE VOTING ALGORITHM

In this algo every element votes for itself. If a different element in encountered then the vote collected
for previous element is used to cancel out the vote for this element.
When votes is zero and new element is found voter changes
The number of votes have to be greater than or equal to 1 to satisfy the condition given in the problem
always
If it is greater than or equal to one, we loop the array again to find how many times is the voter occuring.

Time complexity:
O(n)

*/
#include <stdio.h>
#include <stdlib.h>

int main(){

	int index,voter, votes=0, counter=0;
	int a[] = {2,2,5,6,2,2};
	int length = sizeof(a)/sizeof(a[0]);
	//checking voter and votes
	for(index = 0; index<length; index++){
		if(votes == 0){
			voter = a[index];
			votes++;
		}else{
			if(voter == a[index]){
				votes++;
			}else{
				votes--;
			}
		}
	}
	//checking if that element is really repeating more than n/2 times or not
	if(votes >= 1){

		for(index=0; index<length; index++){
			if(a[index]==voter){
				counter++;
			}
		}

		if(counter > length/2){
			printf("the element that occurs more than n/2 times is %d\n", voter);
		}else{
			printf("no element found\n");
		}

	}

}