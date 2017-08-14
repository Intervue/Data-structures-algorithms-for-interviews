/*
N-queens problem
There is a NXN chessboard. You have to write a program to place 4 queens in such a way that
they do not attack each other.

Naive Approach:
We can place the first queen in n^2 ways,
second in n^2-1 ,third in -2 and so on.

Lets say n=4

Then in worst case we will have n^2cn total combinations of placing the queens and it will take us n^2 time
to validate each combination to see if thats the right position for the queens to not kill each other.

Time complexity: O(n^2cn)n^2

METHOD2:
Here we can restrict the queen per row. Therefore every queen will have 4 ways to select a cell
4 X 4 X 4 X 4 for all the 4 queens
Hence total ways n^n

Time complexity O(n^n)n^2 //to validate what all ways are correct

METHOD3: We can restrict the queens by row and column both. First queen will then have 4 ways, second will
have 3 ways as 1 column is also gone, third will have 2 and so on.

4 X 3 X 2 X 1.

Time complexity: O(n!)n^2

METHOD4:
Here we can use backtracking at each step to see if we are heading in the right direction.

Lets say first queen is placed at first cell (and we are going in ascending order), second will be placed in
next row in 2,3 or 4 column. In second column it cannot be placed, so we place it in third.

Now third queen cannot be placed in first or third and cannot be placed in 2nd or 4th as it will be killed by
second queen, hence we backtrack and change position of q2, and move it to 4th place. This way q3 can now
be placed in second column.

Now llarly for 4th queen it cannot be placed anywhere so we backtrack to change position of q3, which also cannot
be placed anywhere else, we backtrack to change q2, for which all positions are over, so we backtrack to change
position for q1 until we find the right match for all. 

Time complexity in this case cannot be measured as we dont know how many times will the backtracking take place
but it is definately less then O(n!)n^2 

*/
#include <stdio.h>
#include <stdlib.h>

void init(int n, int arr[n][n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			arr[i][j] = 0; //0 means cell is empty
		}
	}
}



int main(){
	int n;
	printf("enter the value of n\n");
	scanf("%d",&n);

	int arr[n][n];

	init(n,arr);

	findNQueen(n, arr);
	
	return 0;
}

