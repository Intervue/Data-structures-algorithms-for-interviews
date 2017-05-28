/*
Number of railway platforms
What is the min number of railway platforms required such that all trains will stand at station w/o colliding
given train names and arrival time and departure time.

METHOD:
We will be given arrival and departures times for different trains. Basis that we need to find the min
platforms requires at any given time so that trains do not collide

One method is to find all intervals that overlap with each other and see how many trains are the maximum
at any instance of time.

Other method is to sort all given values and place them in a single array. Then see if they are arrival
or departure. If they are arrival increment counter, for departure decrement counter. Maintain a variable
to record the max value from the scan. That will be the answer

Time complexity: O(nlogn) //sorting the inputs
Space complexity: O(n) //because we will store it in structure
*/
#include <stdio.h>
#include <stdlib.h>

int calculatePlatforms(int arr[], int dep[],int size){
	int counter = 0;
	int max = 0;
	int i = 0,j=0;
	while(i < size && j < size){
		// printf("arrival is %d\n", arr[i]);
		// printf("dep is %d\n", dep[j]);
		if(arr[i]<dep[j]){
			counter++;
			i++;
		}else{
			counter--;
			j++;
		}
		if(max < counter){
			max = counter;
		}
	}
	return max;
}

int cmpfnc(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

int main(){
	int arr[] = {1000,1015,1030,1040};
	int dep[] = {1020,1400,1500,1055};

	int size = sizeof(arr)/sizeof(arr[0]);

	qsort(arr,size,sizeof(int),cmpfnc);
	qsort(dep,size,sizeof(int),cmpfnc);

	int minPlatforms = calculatePlatforms(arr,dep,size);
	printf("min platforms req are %d\n", minPlatforms);
	return 0;
}