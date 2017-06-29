/*
Count the number of times string occured as the subsequence of the other string

METHOD1:
Naive approach, where we find all the subsequences and see whenever that subsequence is equal to the string
given. This will take exponential time

METHOD2:
We can find the LCS which will be ideally equal to the length of the string given in the second case.
If the solution is also the string that is okay otherwise the string does not repeat even once.
Now if the solution is the string we can go back and construct the total number of solutions which are
of that length (because obviously if they are of length equal to the string, it will be the string itself)
Hence we can maintain a counter for that and return its value

Time complexity: O(mn) //LCS
Space complexity: O(mn)

Rest can be done in lesser time as compared to this, hence the answer


METHOD3:
Dynamic programming but not using LCS:
Here we first try to write the recusive equations

c[i,j] = {
	c[i-1][j] + c[i-1][j-1] //if equal
	//that means we search the matched value in the remaining string as well as ignoring the matched value
	searching the rest in the remaining string

	c[i-1][j] //if the value does not match		
}

We convert it into a program and we will get the answer.
c[i,j] represents count of total number of times string till jth position occur in the string till ith position

Time complexity: O(mn)
Space complexity: O(mn)

*/
//METHOD3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findCount(char *str1, char *str2){

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int sol[len1+1][len2+1];

	int i,j;
	for(i=0;i<=len1;i++){
		sol[i][0] = 1;
	}

	for(j=1;j<=len2;j++){
		sol[0][j] = 0;
	}

	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			if(str1[i-1] == str2[j-1]){
				sol[i][j] = sol[i-1][j-1] + sol[i-1][j];
			}else{
				sol[i][j] = sol[i-1][j];
			}
		}
	}

	printf("the sol array is\n");

	for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++){
			printf("%d ", sol[i][j]);
		}
		printf("\n");
	}

	return sol[len1][len2];

}

int main(){
	char str1[] = "GeeksforGeeks";
	char str2[] = "Gks";

	int count = findCount(str1, str2);

	printf("count is %d\n", count);

	return 0;
}

