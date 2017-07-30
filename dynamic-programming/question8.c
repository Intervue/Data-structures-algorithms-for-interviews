/*
Find the maximum sum sub array

METHOD1:
We can simply find all the sub arrays. Since they are contiguous there will be O(n^2) such sub arrays.
Now, for all sub arrays we can maintain a variable and find max sum possible. Time complexity to find
max sum can be reduced by finding cumulative sum array for the main array and then just
by computing that in constant time sum can be found

Time complexity: O(n^2)
Space complexity: O(n) //in case cumulative array is used

METHOD2:
KADANE's algo
Here we maintain three variables to solve the question.
currentSum, maxSum, index. The maxSum is incremented whenever current sum bigger value is encountered.
Then the index at which it was encountered is also updated.
This algo will only work for problems where atleast one number in the array is positive. As soon as 
the current sum drops to a -ve value make it zero and start again.
Now once iterated, start from the index value in the index variable to the starting of the arr and 
see when the maxSum is encountered. That will be the sub Array.

Time complexity: O(n)
Space complexity: O(1)
*/

//METHOD2
#include <stdio.h>
#include <stdlib.h>

void maxSumSubArr(int *arr, int size){
	int currentSum=0, maxSum=0,index=-1;

	int i;
	for(i=0;i<size;i++){
		currentSum += arr[i];
		if(currentSum < 0){
			currentSum = 0;
		}
		if(currentSum > maxSum){
			maxSum = currentSum;
			index= i;
		}
	}
	int end,j;
	int sum = 0;
	printf("max sum value is: %d\n", maxSum);
	printf("given sub array is:\n");
	for(j=index;j>=0;j--){
		sum+=arr[j];
		printf("%d\n", arr[j]);
		if(sum == maxSum){
			end = j;
			break;
		}
	}	
}

int main(){
	int arr[] = {-3,10,5,-20,4,11,-5,7};
	int size = sizeof(arr)/sizeof(arr[0]);

	maxSumSubArr(arr, size);
	return 0;
}

//this will handle negative cases as well because in that case the answer will be the max number in the
//array. Also this can be done by simply comparing the negative value of curr with max and then seeing
//is the assignment should be done and later assigning 0 to curr
#include <stdio.h>
#include <stdlib.h>

void maxSumSubArray(int *arr, int size){
	int i;
	int max = arr[0];
	int curr = arr[0];
	int end = 0;

	if(curr < 0){
		curr = 0;
	}

	for(i=1;i<size;i++){
		curr += arr[i];
		
		if(max < curr){
			max = curr;
			end = i;
		}	

		if(curr < 0){
			curr = 0;
		}
	}

	printf("max is %d\n", max);
	printf("end is %d\n", end);

	int temp = end;
	int sum = 0, start;
	while(temp >=0){
		sum += arr[temp];
		if(sum == max){
			start = temp;
			break;
		}
		temp--;
	}

	for(i=start;i<=end;i++){
		printf("%d ", arr[i]);
	}

}

int main(){

	int arr[] = {-2,-3,-4,-1,-2,-1,-5,-3};

	int size = sizeof(arr)/sizeof(arr[0]);

	maxSumSubArray(arr, size);

	return 0;
}
