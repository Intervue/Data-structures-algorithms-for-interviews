/*
Find excel column name for given excel column number

Excel column number and name relation has to do with the number system. In case of excel the number system
base is 26. Therefore numbers are from 1-26. Just that numbers in this case start from 1 and not from zero
as compared to other bases for eg 2 which has 0 and 1 and so on.
Therefore given a number we can keep dividing it by 26 until we receive a number which is less than 26 as
remainder.
Then we take the remainder and quotient from bottom to top and assign them alphabets corresponding to their
values.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 50

int GetPower(int number, int exponent)
{
  int power = 1;
  for(int i=0; i<exponent; i++)
    power *= number;
  return power;
}

void calculateNumber(char *str){
	// printf("INSIDE FUNCTION %s\n", str);
	int i;
	int length = strlen(str);
	int sum = 0;
	// printf("sum value now %d\n", sum);
	int exp = 0;
	for(i=length-1; i>=0;i--){
	 	sum += (str[i] - 'A' + 1) *  (GetPower(26, exp));
		// printf("num value now is %d\n", sum);
		exp++;
	}
	
	printf("number is %d\n", sum);
}

void calculateName(int num){
	if(num <= 26){
		printf("%c\n",'A'+num-1);
		return;
	}
	char str[MAX];
	int z = 0;
	while(num > 0){
		int rem = num%26;
		if(rem == 0){
			str[z++]='Z';
			num = (num/26)-1;
		}else{
			str[z++] = 'A' + rem - 1;
			num = num/26;
		}
		
	}	
	strrev(str);
	printf("%s\n", str);
}

int main(){
	int num, step;
	char word[256];
	while(1){
		printf("1. convert excel column number to name\n");
		printf("2. convert excel name to column number\n");
		scanf("%d",&step);
		switch(step){
			case 1: printf("enter the excel column number\n");
				scanf("%d",&num);
				calculateName(num);
				break;
			case 2: printf("Enter string for column name\n");
				scanf("%s",word);
				calculateNumber(word);	
				break;
		}
		
	}
	return 0;
}