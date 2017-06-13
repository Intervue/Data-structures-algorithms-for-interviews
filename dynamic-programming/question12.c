/*
Find kth ugly number

Ugly number is a one which can be written as a product of 2,3 or 5 or a combination of these numbers. 
1 is also considered as ugly number as it is an exception.

One method that comes to mind is the brute force method where you see if the number is divisible by 
2, 3 or 5 as stated above and increment the counter till you reach the kth number. But it is
very difficult to find the time complexity in this apporach as we may have to scan 1000's of numbers
to find out 100th number lets say. Plus there are a lot of divisions also involved which may be
computationally heavy.

METHOD:
Here we know the the first ugly number is 1. Therefore, we can generate the next one by multiplying
1 with 2,3 or 5. Once we have the next number, we will repeat the same process with it. But we 
also want the minimum of these multiplications to be the next ugly number and we want only 3 numbers
to be generated at a time so that finding the min is a constant time operation. Therefore we keep
three variables at position 0 initially. Once lets say now we have 1 and 3 numbers more are to be 
generated. i is used to keep track of mul with 2, j with 3 and k with 5. Now we compare the 3 numbers
if the min one is the one with is multiplied with 2, we increment the value of i and update the
next number by multiplying the newly generated number with 2 again. Similarly in the next iteration
if min is now the one multiplied with 5, we increment k and multiply the newly generated value with 5
to generate a number which will be a part of the next three numbers to be compared. Keep doing this
until we have kth number as needed.

Time complexity: O(k) //since we do it k times and all we do is compare 3 numbers by multiplying with 
2,3 and 5 which is a constant time operation

Space complexity: O(k) //we maintain an array
*/
#include <stdio.h>
#include <stdlib.h>

int findMin(int num2, int num3, int num5){
	return (num2 < num3)?((num2<num5)?num2: num5):((num3<num5)?num3:num5);
}

int main(){
	int num;
	
	printf("enter the value of k to print the ugly number\n");
	scanf("%d", &num);
	
	int arr[num];
	arr[0] = 1;
	int i=0,j=0,k=0;
	int num2, num3, num5;
	int counter = 0;
	while(counter+2 <= num){
		num2 = arr[i]*2;
		num3 = arr[j]*3;
		num5 = arr[k]*5;
		
		int value = findMin(num2, num3,num5);
		counter++;
		arr[counter] = value;
		if(value == num2){
			i++;
		}
		if(value == num3){
			j++;
		}
		if(value == num5){
			k++;
		}
		
	}
	printf("%dth ugly number is %d\n", num,arr[counter]);
	return 0;
}