/*
KMP algorithm

Time complexity: O(m+n)
Space complexity: O(n)

m: length of text
n: length of pattern

Explanation

For KMP algorithm, we reduce the time by knowing if there is a mismatch then where to start the search again 
by some logical calculations rather than jumping at the start of text and pattern and comparing again
as we do in the naive approach.

For that whenever there is a mismatch, we see if there is a suffix which is also a prefix from the start 
till the point (not included) where there is a mismatch. If there is a suffix which is also a prefix
lets say it is two characters long, that means that in the text part also there was a match for this two
character long thing. Therefore we do not have to start from the first character of the pattern to start
comparing again, we can just jump to the third one as first two are already in the text pattern just before
the place where out pointer is

EG for the above is:

Text: a b c x a b c d a b x a b c d a b c d** a b c y

Pattern:   a b c d a b c y**

In the above pattern if the search fails at the very last when y is compared to d, then we know just
before d, (a b c) exists which is also true for y. Therefore in the pattern part it is a suffix of length
3 which is also a prefix. 

Hence, we do not have to compare the first three characters and we can straight away take our pointer to
d in the pattern and start comparing again. This saves us the number of iterations and thus the time
complexity.

How to calculate suffix and prefix efficiently for PATTERN string given?

For this we take an array corresponding to each letter. i and j are initialized with first two positions
of the string. Each time value in i and j is compared. j if belongs to the first cell, value in array
is taken as zero by default.

if equal: in array at place where i is we set (value at j which is zero in this case)  + 1, and then we
increment both i and j

if not equal: we just increment i.

If j is somewhere in the middle and then the alphabets are not equal, then we see the previous position
to j and see the value in array and move to that position and compare again. We repeat this cycle until
we find a match, if match is found the value at ith will be (value at j) +1. If no match till the end (or
the beginning of the string as we are decrementing j), then we will write zero at ith position and
increment i. Keep repeating these steps until end of string is reached.

Sample array applying such logic is shown below:

a b c d a b c a
0 0 0 0 1 2 3 1

a a b a a b a a a
0 1 0 1 2 3 4 5 2

Therefore whenever we compare if value does not match lets say at b from the last in the second array,
we should again start comparing from position 2 or alphabet number 3, as a character previous to b
holds that value in the array.

Thats KMP algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculatePrefixSuffixArray(int *psa, char *pattern, int size){
	
	int i=1,len=0;
	psa[0] = 0;

	while(i<size){
		if(pattern[i] == pattern[len]){
			len++;
			psa[i] = len;
			i++;
		}else{
			if(len != 0){
				len = psa[len-1];
			}else{
				psa[i] = 0;
				i++;
			}
		}
	}
}

int findIndexKmp(char *text, char *pattern){
	int plen = strlen(pattern);
	int tlen = strlen(text);
	int psa[plen];

	calculatePrefixSuffixArray(psa,pattern, plen);
	
	int i=0, j=0;
	int start = 0;
	int count = 0;

	for(int k=0;k<plen;k++){
		printf("%d ", psa[k]);
	}

	printf("\n");

	while (i < tlen && j < plen) {
		if(text[i] == pattern[j]){
			i++;
			j++;
			count++;
			if(count == plen){
				return start;
			}
		}else{
			if(j == 0){
				i++;
			}else{
				j = psa[j-1];	
			}
			start = i-j;
			count = j;
		}

	}
	
	return 0;
}

int main(){

	char text[] = "abcxabcdabxabcdabcdabcy";

	char pattern[] = "abcdabcy";

	int index = findIndexKmp(text, pattern);

	printf("pattern found starting at index %d\n", index);

	return 0;
}


