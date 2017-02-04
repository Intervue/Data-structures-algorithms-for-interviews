# Topic1: Introduction

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

`#define` is another preprocessor used in C discussed ahead.
`gcc -Wall -save-temps hello-world.c` is used to see all the temporary files that are created while a C program in executed and converted from high level language to assembly language to machine code and finally to the output


## Format specifiers to print different things

- `%d` prints as decimal number
- `%6d` prints as decimal number but atleast 6 characters wide 
- `%f` prints as floating point number
- `%6f` prints as floating point number in atleast 6 characters
- `%.2f` prints as floating point number but should have two characters after decimal
- `%6.2d` prints as floating point number with 6 places before decimal and 2 after decimal
- `%c` prints as ascii character

These specifiers can be used as example shown below:

```C
printf("%d",2);
```

## Character input and output in C

- 'getchar()' reads the next input character from a text stream and returns that as its value
- 'putchar()' prints a character each time it is called

### Example explained with comments:

[File here!](/programs/put-get-char.c)

```C
#include <stdio.h>

//default function that is run by C everytime
int main(void){
	//declaring a variable c that will take the input given
	int c;
	//assigning input using this function to variable c
	c = getchar();
	//this will keep printing until end of file is there
	while(c != EOF){
		//this function will print output on the screen
		putchar(c);
		//after printing the output it takes input until while loop ends
		c = getchar();
	}
}
```

# Topic2: Data Types in C

All variable start with a name which is a character and can include underscore (_). It should not start with a number or _.

- `char' - A single byte used to represent a character (numbers from 0-255 can be stored). Each decimal number is encoded as a character
- `int' - an integer (size is machine and compiler dependent) 
- `float' - A single byte (single-precision floating point number). Machine must have atleast 32 bits.
- `double' - A single byte (double-precision flaoting point number). Machine must have atleast 64 bits.

## Qualifiers that can be added to data types
- `short' - eg short int (will have a size smaller than int and long int)
- `long' - eg long int (size greater than short int and int)
- `signed' - generally used for int and char types (range -128 to 127 for int)
- `unsigned' - used for int and char (range 0 - 255 for int)

## Note:
`sizeof(int)` returns number of bytes `int` is taking in the system. Similarly char and float can be found. 
For floating point numbers larger than double `long double` can be used

## Program to find sizeof()

```C
#include <stdio.h>

int main(){
	//sizeof() can be passed any data type along with a qualifier
	//it returns the number of bytes that data type is occupying as per your system and compiler
	printf("%lu\n",sizeof(long int));

}
```

## Enumeration datatype

Type of constant which is helpful in improving the readability of the program

```C
//it will enumerate 0 as NO and 1 as YES. This can be used throughout the program
//default value of first will be zero and second will be 1 and it keeps on increasing unless some specific numbers are mentioned there
enum boolean {NO, YES};

//in this case value is specified for jan which is 1, so other values will have 2, 3 and so on values
enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC}

```

## Example using enumeration

[File here!](/programs/enumeration.c)

```C
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
```

## Type conversion

Sometimes we need to convert variable from one type to another.

For eg: when adding double to long double, we need to convert both of them to long double so that we dont loose any information. The result will be given automatically in the bigger one of all.

### Priority order for conversion is as follows:

1. long double
2. double
3. float
4. short or int
5. char

Such conversions are also done in assignments. The right hand side is always converted to the type of left hand side in that case. There will be loss in information while doing so if the right hand side is lies upper in the priority order as compared to left hand side.

## Casting

When type conversion is done explicitly, it is called casting

Eg: converting int to float to store in float variable f

`f = (float) 10`


## Constants

If the following is specified in programs, they will automatically be characterized as the corresponding datatypes 

- 1234 - int
- 1234l - long int
- 12.34 - float
- 037 - octal (3X8+7)
- 0X12 - hexadecimal 
- 0x12l - long octal
- 'x' - character constant (ascii value of character is taken if used along with int)

## Note:

`const float pi = 3.14` makes the variable pi a constant which cannot be changed. If it is changed compilter throws an error.

## Example

```C
#include <stdio.h>

int main(){
	
	int i = 17; 
	char c = 'c'; //ascii value 99
	// "c" cannot be used. only 'c' can be used as single inverted commas will convert it to ascii value

	float sum;
   	//type conversion happens here	
	sum = i + c;

	printf("%f\n",sum); //prints 116.000000

}
```

## String constants

Generally they are represented using double quotes. 

`"string"`

The above example is having 6 bytes but we need 7 character space to store it because every string constant ends with null (\0).

## Example

[File here!](/programs/count-string-constant.c)

```C
//strlen is the name of the function which is taking character as argument
int strlen(char s[]){
	
	int i = 0;
	//this loop increments i until end of string \0 is reached
	while(s[i] != '\0'){
		i = i + 1;
	}

	return i;

}
```

## Assignment Operators

`i = i + 2;` 

increment the value of i by 2 and store it in i

shorthand for this

`i += 2;`

### In general:

```
expr1 = expr1 op expr2

can be written as:

expr1 op = expr2

```

## Bit Operators 

Some bit wise operators are discussed as below:

A (60) = 00111100
B (13) = 00001101

then:

- A & B (AND operations) = 00001100
- A | B (OR operation) = 00111101 
- A ^ B (XOR operation = add both of them and divide by 2 and write the remainder) = 00110001
- ~A (NOT operation) = 11000011 
- A << 2 (left shift by two) = 11110000 which is equal to 240 (it is nothing but multiplying by 2 power 2)
- A >> 2 (right shift by 2) = 00001111 which is 15 (it is nothing but dividing by 2 power 2) 


## Ternary Operator

### Example:

```C
#include <stdio.h>

int main(){
	
	int num;

	printf("enter a number:\n");
	//this will take input from user and assign it to vairable num
	scanf("%d",&num);
	//ternary operator to get the output
	(num%2 == 0 )? printf("number is even\n"): printf("number is odd\n");

}
```

## Increment and decrement operator

- `++n` increments n before its value is used
-  `n++` increments n after its value is used

```C
n = 2;
X = n++; //it will assign 2 to X and then increment n to 3;
```

```C
n = 2;
X = ++n; //it will increment n to 3 and assign it to X
```

## Precedence and order of evaluation of operators

`precedence`: which ever operator has higher priority is evaluated first

`associativity`: if precedence of two operators is same, which one is evaluated first is found out using associativity

[Click here!](http://www.difranco.net/compsci/C_Operator_Precedence_Table.htm) to see the full chart


## Note:

These can be remembered from top to bottom from the chart as `u asc blac` (unary, arithmetic, shift, comparison, bitwise, logical, ternary, assignment, comma)


## Program to print Fahrenheit - Celsius Table

[File here!](/programs/fahrenheit-celsius.c)

```C
#include <stdio.h>

int main(){
	
	int fahr, celsius;

	int lower, upper, step;

	lower = 0; // this is the lower limit of temperature table
	upper = 300; // this is the upper limit of temperature table
	step = 20; //step size

	fahr = lower; //initialized with lower value

	while(fahr <= upper){

		celsius = 5*(fahr - 32)/9; //here the precedence and associativity can be seen

		//will print the result in table format
		printf("%d\t %d\n", fahr, celsius);

		fahr += step; //incrementing by step size
 
	}

}
```

## Note:

Before using any function or variable in C we need to declare it always.
If function is from library then no need to declare it


# Topic3: Flow Control

Flow control means controlling the flow of program as per need.

There are various ways to do that:

- conditional statements (`if, elseif, else`)
- switch statement
- while loop
- do while loop
- for loop
- continue and break statements


## Example

Program to check whether a given number is even or odd using if else

[File here!](/programs/even-odd.c)

```C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	int num;

	printf("enter some number: \n");
	scanf("%d", &num); //address of num will be returned when we write &num

	if(num%2 == 0){
		printf("number is even\n");
	}else{
		printf("number is odd\n");
	}

	return 0;
}
````

## Example of switch statement

```C
int main(){
	
	int weekday;	
	printf("enter weekday numbers between 1 and 6\n");
	scanf("%d",&weekday);

	switch(weekday){
		//break statement is important because if one case turns true no other case should execute
		//cases can contain expressions but only constants. No variables are allowed in cases
		// default case can be present anywhere
		case 0: printf("monday"); break; 
		case 1: printf("tuesday"); break;
		case 2: printf("wednesday"); break;
		case 3: printf("thur"); break;
		case 4: printf("fri"); break;
		case 5: printf("sat"); break;
		case 6: printf("sun"); break;
		default: printf("enter a valid weekday\n"); break;

	}

	
}
```

## Example

Simple calculator

[File here!](/programs/simple-calculator.c)

```C
#include <stdio.h>

int main(){
	
	char operator;
	double a,b;	
	printf("enter an operator (+, -, *, /)\n");
	scanf("%c",&operator);

	printf("enter two operators \n");
	//lf is the format specifier for double
	scanf("%lf %lf",&a, &b);

	switch(operator){
		//representing operators in single quotes will convert them to integers (ascii values)
		case '+': printf("additon of a and b: %lf\n", a+b); break;
		case '-': printf("subtraction of a and b: %lf\n", a-b); break;
		case '/': printf("division of a and b: %lf\n", a/b); break;
		case '*': printf("multiplication of a and b: %lf\n", a*b); break;
		default: printf("please enter a valid operator\n"); break;
	}

	
}
```

### Note:

`Difference between while and do while loop is that while loop will check the condition first and execute the body, do while will check the condition after executing the body once, the decide whether to exit the loop or not`

```C
int main(){
	
	int a = 20;
	//do has its own body following by while statement
	do{
		printf("%d\n", a);
		a++;
	} while(a<20); //output: 20. as it executes the body once

	//this is the while loop
	while(a<20){
		printf("%d\n", a);
		a++;
	} //output nothing

	//for loop
	for(int i = 1; i<a; i++){
		printf("value of i %d", i);
	}
	
	return 0;

}
```

```C
//program to probe the user until he enters a positive value
int main(){
	//do while loop is beneficial in this case	
	int num;
	do{
		printf("enter a positive integer\n");
		scanf("%d", &num);
	}while(num <= 0);
	
	printf("number now is %d\n", num);
	
}
```

### Note:

`Difference continue and break statement is that continue will move the loop to the next iteration and skip all the statements present between continue and the end of the loop whereas break will exit the loop. Continue statement should be used wisely in for loop, eg continue statement if before the increment of the variable which is under check in while loop can make the loop infinite`

## Example

```C
int main(){
	
	int sum = 0;

	while(sum < 20){

		if(sum == 0){
			continue;
		}

		sum++;
	}

	return 0;
}
```







