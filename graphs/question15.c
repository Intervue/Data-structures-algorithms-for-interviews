/*
Print all jumping numbers smaller than or equal to a given value

Number is jumping if the diff between the digits of a number is 1.
90 is not a jumping number
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 150000

int queue[MAX];
int start = 0, rear= 0;

int elms = 0;

void enqueue(int data){
	queue[++rear] = data;
	elms++;
}

int dequeue(){
	elms--;
	// if(start + 1 == MAX){
	// 	start = 0, rear = 0;
	// }
	return queue[start++];
}

int isQueueEmpty(){
	return elms == 0;
}

void bfs(int limit, int index){

	enqueue(index);

	while(!isQueueEmpty()){
		int data = dequeue();
		
		if(data <= limit){
			
			printf("%d ", data);

			int last_digit = data%10;
			if(last_digit == 0){
				enqueue((data*10) + (last_digit + 1)); 
			}
			else if(last_digit == 9){
				enqueue((data*10) + (last_digit - 1));
			}else{
				enqueue((data*10) + (last_digit - 1));
				enqueue((data*10) + (last_digit + 1));
			}
		}

	}

}

void displayJumping(int limit){
	int i;
	printf("%d ",0);
	for(i=1;i<=9 && i<=limit;i++){
		bfs(limit, i);
	}

}

int main(){
	int cases;
	scanf("%d",&cases);
	int i;
	for(i=0;i<cases;i++){
		int x;
		scanf("%d",&x);
		displayJumping(x);
	}

}
