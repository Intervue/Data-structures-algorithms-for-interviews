/*
Program for greedy knapsack problem.

METHOD:
In this problem different weights are given along with the profit associated to each weight (if full weight
is used). Now, a bag is given with a max capacity. We have to put objects in the bag such that profit
is maximum.

The approach is to find the profit by weight ratio corresponding to each object, then sort the list.
Now from the list keep filling the bag with the object completely with the max profit by weight ratio.
Once the bag is full enough such that it cannot accomodate the next weight fully, put the fraction of
that weight such that the bag is full and add the fraction of profit to the total profit so far.

Time complexity: O(nlogn) //since sorting is the dominant term
Space complexity: O(n) //since we will be storing profit by weight ratio in array

We can also use max heap in this case and everytime we will have to delete max and max heapify n times
which will give the same time complexity
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	return 0;
}