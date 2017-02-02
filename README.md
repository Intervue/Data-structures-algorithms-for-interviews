# Introduction

## Simple program to print '```hello world```' in C

[File here!](/programs/hello-world.c)

```C
#include <stdio.h>

int main(){
	printf("Hello world \n");
}

```

## Running this program

In the command line do the following (while in the file directory):

```
gcc hello-world.c

./a.out
```

## Code explanation

1. ```stdio.h``` is a standard C library to be included
2. ```main()``` is the function which is executed by C compiler each time the program in C is run. In case another function is to be called, it can be called via main. 
3. ```printf``` prints the output on the screen
4. ```gcc hello-world.c``` creates output file a.out. This command converts the high level language written in C to binary for out computer to understand it
5. ```./a.out``` is run to see the output
6. ```#include``` is the pre-processor directive which will fetch the file ```stdio.h``` for predefined functionalities of C

### Note:

`#define` is another preprocessor used in C discussed ahead
`gcc -Wall -save-temps hello-world.c` is used to see all the temporary files that are created while a C program in executed and converted from high level language to assembly language to machine code and finally to the output





