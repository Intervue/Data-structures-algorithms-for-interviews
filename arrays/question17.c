/*
In an array of unknown size having all 0s at one side and all 1s at other, find the index where 1st 1 exists.

METHOD1:
We can run the loop for one iteration. If one is not found we increase the number of iteration by increasing that 
variable by 1
Time complexity: O(n) 
Space complexity: O(1)

METHOD2:
We cannot apply binary search on this as size is not given. So instead we keep checking this at indexes by 
incrementing them by the power of 2(could have been 10 also).
Time complexity: Unknown
Space complexity: O(1)
*/



// //METHOD1
// #include <stdio.h>
// int main(){
	
// 	int a[] = {0,0,0,0,1,1,1,1,1,1};
// 	int n = 1;
// 	for(int i=0; i<n;i++){
// 		if(a[i] == 1){
// 			printf("index from where 1 starts is %d\n", i);
// 			break;
// 		}else{
// 			n++;
// 		}
// 	}
// }

//METHOD2
#include <stdio.h>

int binarySearchOne(int arr[], int start, int end){

	if(start == end){
		if(arr[start] == 1){
			return start;
		}
	}

	if(start < end){
		int mid = (start + end)/2; //need to see it w/o brackets
		binarySearchOne(arr,start, mid-1);
		binarySearchOne(arr,mid,end);	
	}
}	

int findOneIndex(int a[]){
	int i = 1, start, end, prev;
	if(a[i] == 1){
		if(a[0] == 1){
			return i;
		}
		return i;
	}else{
		prev = i;
		i = 2;
	}

	while(1){
		if(a[i] == 1){
			end = i;
			start = prev;
			break;
		}else{
			prev = i;
		}
	}

	return binarySearchOne(a, start, end);

}

int main(){
	int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int index = findOneIndex(a);	
	if(index){
		printf("index where 1 appears for first time is %d\n", index);
	}else{
		printf("index not found\n");
	}
}


