/*
Given two words, word1 and word2, 
find min operations to convert word1 to word2 with some given set of rules:

1) insert a character
2) delete a character
3) replace a character

METHOD1:
Naive approach: This approach is to check each and every possibility on a character. EG:
Str1: data
str2: dent
We will compare the first two characters and if they are equal, if they are equal, then we
simply move on to the next character, if they are not equal we will consider all the possibilities
of deleting, replacing and inserting the element and compute the result recursively. In the end 
we check what method is taking minimum number of operations.

Time complexity: O(3^n) //n being the number of elements and there are 3 kind of operations that
can be applied for each element
Space complexity: O(1)

METHOD2:
Dynamic Programming: Here in the above method if a tree is made for each possibility of replacing,
inserting and deleting as branches we will get repeated sub problems, so in a way we can save them
in a table and rather solve them in O(1) time.

Therefore we simply create a mXn matrix 

c(i,j) = 	c(i-1,j-1) if match,
				if no match  
			min{
				1 + c(i-1,j-1) if replaced, 
				1 + c(i-1,j) if delete,  
				1 + c(i,j-1) if insert    
		 	}

Therefore, we make a matrix of size m + 1 X n+1 in case length of two strings is m X n.
Now, imagine matrix like this
	0	M 	A 	R 	C 	H
0   0	1	2	3	4	5    //the first row and column means convert C to 0 converting CA to 0 and so on
C 	1
A 	2
R 	3
T 	4

If there is a match, we simply pick the diagnal element now when traversing, if there is no match,
we take the min of top left and diagnal and add 1 to it. Its logical as if there is a match, the
size of the problem is reduced by 1 on both sides as per recursive eqn.

If there is no match, we have to compute all problems as per recursive equation which has already been
computed in the matrix

Time complexity: O(mn)
Space complexity: O(mn)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMin(int a, int b, int c){
	return (a < b)?((a<c)?a:c):((b<c)?b:c);
}

int findEditDistance(char *str1, char *str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	printf("length of two strings are %d and %d\n", len1, len2);
	int editDis[len1 + 1][len2 + 1];
	int i,j;
	for(i=0; i<=len1;i++){
		for(j=0;j<=len2;j++){
			if(i == 0){
				editDis[i][j] = j; 
			}else if(j == 0){
				editDis[i][j] = i;
			}else if(str1[i-1] == str2[j-1]){
				editDis[i][j] = editDis[i-1][j-1];
			}else{
				editDis[i][j] = 1 + findMin(editDis[i-1][j],editDis[i][j-1],editDis[i-1][j-1]);
			}
		}
	}
	return editDis[len1][len2];
}

int main(){
	char str1[] = "CART";
	char str2[] = "MARCH";

	int operations = findEditDistance(str1, str2);
	printf("min number of operations req are: %d\n", operations);

	return 0;
}
