/* Program to show enumeration datatype */

#include <stdio.h>

int main(){
	//this will interpret no as 0 and yes as 1. So these can now be used conditionally
	enum boolean {no, yes};

	if(yes){
		printf( "hello world\n");
	}else{
		printf( "nothing\n");
	}

}