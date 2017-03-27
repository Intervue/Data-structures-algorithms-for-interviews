/*
Find the two repeating numbers in a given array
=> given n+2 elements
=> 1 < a[i]<n
=> all elements from 1 to n occur atleast once (except two numbers which occur twice)


METHOD1: Brute force
we compare every pair in this nc2 such pairs (O(n^2) time complexity)

METHOD2: if there was not space constraint
we maintain a hash table and of size n and keep incrementing the count at the respective index.
if count is greater than 1 element has repeated
Time complexity: O(n)
Space complexity: O(n)

METHOD3:
we find the sum of first n numbers
then we find the sum of whole array
subtracting these we get X+Y (assuming two numbers that are repeating to be X and Y respectively)
Then we find prod of n numbers (n factorial)
product of whole array
dividing them we find XY
then we find X-Y and finally value of X and Y respectively
Computationlly this is not a very good algo as it involves calculations and might even lead to declaration of
advanced data types. So only use it if no other method is available. Finding product everytime is always heavy.
Time complexity: O(n)

METHOD4:
we find XOR of all the elements in array with elements 1 to n. 
1 2 3 4 1 3 with 1 2 3 4, it will give us XOR of two elements that are repeating as per XOR rules.
Now we find XOR of the two numbers and based on the result (binary representation) we check from the rightmost side
when is the first 1 coming (assume its coming at the least significant bit)
To find the least significant bit we can do XY & ~(XY-1) //1's compliment
seperate the elements of the array based on the least significant bit now into two groups (one having binary
representation of the number which has least significant bit as 1 and the other dont have that)
Simillarly do the same for the numbers 1 2 3 4 and put them in respective groups and take XOR
Each group will not give the repeating number respectively.
Time complexity: O(n)
Space complexity: O(1)


METHOD5: same as done in question23.c (where we make the respective indexes value negative based on value we get
and check if they are already negative then that value is repeating)
Time complexity: O(n)
Space complexity: O(1)
*/

//METHOD4
#include <stdio.h>
#include <stdlib.h>

 
void findRepeatingNumbers(int arr[], int size){
	int n = size - 2;
	int x = 0, y= 0, set_bit, index, result = arr[0];

	for(index = 1; index<size; index++){
		result ^= arr[index];
	}
	for(index = 1; index<=n; index++){
		result ^= index;
	}

	set_bit = result & ~(result-1);

	for(index=0; index<size; index++){
		if(arr[index] & set_bit){
			x ^= arr[index];
		}else{
			y ^= arr[index];
		}
	}

	for(index=1; index<=n; index++){
		if(index & set_bit){
			x ^= index;
		}else{
			y ^= index;
		}
	}

	printf("the two repeating numbers are %d and %d\n", x, y);
}

int main(){
	int arr[] = {4, 2, 4, 5, 2, 3, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	findRepeatingNumbers(arr, size);
	return 0;
}


