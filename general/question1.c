/* 
Question description:

printing nth term of arithmetic series
input: first term, common difference and value of n
output: nth and element and sum of n elements
*/

#include <stdio.h>

int main(){

	int firstterm, d, n, nth_element, sum;

	printf("enter the first term, common difference and value of n\n");
	scanf("%d %d %d", &firstterm, &d, &n);

	nth_element = firstterm + (n-1)*d;
	sum = (n/2)*(2*firstterm+(n-1)*d);

	printf("nth term of the series is: %d\n", nth_element);
	printf("and the sum of the series is: %d\n", sum);

}