/*
Design a stack such that get Minimum should be O(1)

NOTE: When stack is to be designed in order to do something the core functionalities of the stack should
still hold in that design. Eg: Pushing and popping can be done in O(1) time in a stack. This should be
true always

METHOD1:
Maintain and another stack which will store minimum so far values.
For each push into the main stack, the min is compared and if there is a different value it is pushed onto 
this stack. For every pop from the main stack if the popped off element is equal to the min, then the min is
popped off as well. If the main stack contains duplicate values, then the min so far stack should also
contain duplicate to make sure that popping off is consistent and works correctly.
Time complexity: Both pop and push in O(1)
Space complexity: O(n) //worst case

METHOD2:
Maintain a variable that will store the min value so far for every push done. For every push done,
if there is a new minimum, instead of pushing this minimum onto the stack, subtract the min so far value from
this min and push that value on the stack. Eg if minimum so far is 9 and new min is 2 push 2-9 that is -7 
on the main stack. Like this make the stack.
While popping off, each time compare the number on the stack with the min so far, if the number is bigger
pop that number else popp of the min so far value. Also update the min so far value by subtracting the smaller
value on the stack from it. Eg if the min so far was 2 (which was popped off) and value on stack was -7,
new min so far value should be 2-(-7) which is 9. This way the whole algo will work.
Time complexity: O(1)
Space complexity: O(1)
*/
//METHOD2
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 20

// void push(int arr[],int data, int *top,int *min){
// 	if(*top == MAX-1){
// 		printf("overflow\n");
// 		return;
// 	}
// 	int temp;
// 	if(*top == -1){
// 		*min = data;	
// 	}else{
// 		temp = *min;
// 		if(*min > data){
// 			*min = data;
// 			data = data-temp;
// 		}
// 	}
// 	printf("INSERTING... %d\n", data);
// 	printf("new min value... %d\n", *min);
// 	arr[++(*top)]=data;
// }

// int pop(int arr[],int *top, int *min){
// 	int result;
// 	if(*top == -1){
// 		*min = 0;
// 		return -1;
// 	}
// 	if(arr[*top]<*min){
// 		result = *min;
// 		*min = *min - arr[*top];
// 	}else{
// 		result = arr[*top];
// 	}	
// 	*top = *top - 1;
// 	printf("new top value %d\n", *top);
// 	printf("POPPING... %d\n", result);
// 	printf("updated min value... %d\n", *min);
// 	return result;	
// }

// int main(){
// 	int arr[MAX];
// 	int step,elm,result,top=-1,min;
// 	while(1){
// 		printf("1. PUSH element\n");
// 		printf("2. POP element\n");
// 		printf("3. Get Minimum\n");
// 		printf("4. EXIT \n");
// 		scanf("%d",&step);

// 		switch(step){
// 			case 1: printf("enter element to be pushed\n");
// 				scanf("%d",&elm);
// 				push(arr,elm,&top,&min);
// 				break;
// 			case 2: result = pop(arr, &top, &min);
// 				if(result < 0){
// 					printf("already empty\n");
// 				}else{
// 					printf("%d was deleted\n", result);
// 				}	
// 				break;
// 			case 3: printf("%d is the current min\n", min);
// 				break;
// 			case 4: exit(1);
// 				break;
// 		}
// 	}
// 	return 0;
// }
//===================================================================================================
//METHOD1
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void push(int arr[],int min[],int data, int *top, int *min_top){
	if(*top == MAX-1){
		printf("overflow\n");
		return;
	}
	arr[++(*top)]=data;
	if(*min_top != -1){
		if(min[*min_top]>=data){ //equal to be considered as well
			min[++(*min_top)]=data;
		}
	}else{
		min[++(*min_top)]=data;
	}
}

int pop(int arr[],int min[],int *top, int *min_top){
	if(*top == -1){
		printf("underflow\n");
		return -1;
	}
	int result = arr[*top];
	*top = *top-1;
	if(min[*min_top]==result){
		*min_top = *min_top-1;
	}
	return result;	
}

int getmin(int min[],int *min_top){
	if(*min_top == -1){
		return -1;
	}
	int result = min[*min_top];
	return result;
}

int main(){
	int arr[MAX],top=-1;
	int min[MAX],min_top=-1;
	int step,elm,result;
	while(1){
		printf("1. PUSH element\n");
		printf("2. POP element\n");
		printf("3. Get Minimum\n");
		printf("4. EXIT \n");
		scanf("%d",&step);

		switch(step){
			case 1: printf("enter element to be pushed\n");
				scanf("%d",&elm);
				push(arr,min,elm,&top,&min_top);
				break;
			case 2: result = pop(arr,min,&top,&min_top);
				if(result < 0){
					printf("already empty\n");
				}else{
					printf("%d was deleted\n", result);
				}	
				break;
			case 3:	result = getmin(min,&min_top);
				if(result >= 0){
					printf("%d is the current minimum\n", result);
				}else{
					printf("stack is empty now\n");
				}
				break;
			case 4: exit(1);
				break;
		}
	}
	return 0;
}