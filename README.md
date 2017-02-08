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

`Difference continue and break statement is that continue will move the loop to the next iteration and skip all the statements present between continue and the end of the loop whereas break will exit the loop. Continue statement should be used wisely in for loop, eg continue statement if before the increment of the variable which is under check in while loop can make the loop infinite. Break and continue will exit the loop that contains it. If the loops are nested, it will exit or continue for the respective loop only.`

## Example

```C
int main(){
	//infinite loop as continue statement is placed at wrong place
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

## Example program:

Check whether a number is prime

*Logic*: 

`One way is to start from 2 and go till n-1 to check if a number is prime`
`Better way is if no factors are found till root of a number or half of number there wont be any factors after that. The idea is to reduce the loop iterations`

[File here!](/programs/check-prime.c)

```C
int main(){
	
	int num;

	int isPrime = 0; //assuming number is not prime

	printf("enter a number\n");
	scanf("%d", &num);

	for(int i = 2; i <=num/2; i++){ //dividing the number by two and running the loop till then

		if(num%i == 0){
			isPrime = 1;
			break;//breaking out of the loop once out check is satisfied
		}

	}

	if(isPrime == 0){
		printf("number is not prime\n");
	}else{
		printf("number is prime\n");
	}


}
```

# Example program:

Find the factorial of a number.

[File here!](/programs/factorial.c)

```C
//default function that is run by C everytime
int main(){
		
	int num;

	printf("enter a number\n");
	scanf("%d", &num);

	if(num < 0){
		printf("factorial for negative numbers does not exist\n");
	}

	//since factorial of a number if always positive it is better to use unsigned for a bigger range (0 - range)
	// and not (-range to range)
	unsigned long long fact = 1; //integer having bigger size compared to normal integer

	for(int i = 2; i <= num; i++){

		fact = fact*i;

	}

	printf("factorial is %d = %llu\n", num, fact); //llu is format specifier for long long int

	return 0;

}
```

## Note:

'To find the number of digits in an integer keep dividing it by 10'

## Example program

Check is the number is armstrong or not

Eg: 341 == 3 cube + 4 cube + 1 cube, then its armstrong

[File here!](/programs/armstrong.c)

```C
//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>
#include <math.h>

//default function that is run by C everytime
int main(){
	
	int num, result=0, originalnumber, n=0, remainder;

	printf("enter a number\n");
	scanf("%d", &num);
	originalnumber = num;

	while(originalnumber != 0){
		originalnumber = originalnumber/10;
		n++;
	}
	originalnumber = num;
	while(originalnumber != 0){
		remainder = originalnumber%10;
		result += pow(remainder, n);
		originalnumber /= 10;
	}

	if(result == num){
		printf("this is armstrong number");
	}else{
		printf("this is not an armstrong number");
	}

}
```

## Example program

Program to print star 3 pattern

[File here!](/programs/star-3.c)

```C
//pre-process fetching contents of library stdio.h which contains predefined functions in C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	
	for(int i = 0; i < 5; i++){
		
		for(int j = 5; j >=i; j--){
			printf(" ");
		}

		for(int k = 0; k <= 2*i; k++){ 
			printf("*");
		}	
		
		printf("\n");

	}	
	
	return 0;
}
```

## Example program

Program to check if the number is a palindrome or not

`Palindrome: When reverse of something is equal to that something`

[File here!](/programs/check-palindrome.c)


```C
//default function that is run by C everytime
int main(){
	//predefined function from the library which prints the output given to it
	int num, lastdigit, result = 0;
	printf("enter a number: \n");
	scanf("%d", &num);

	int originalnum = num;

	while(originalnum !=0){ //making that number in reverse
		lastdigit = originalnum%10;

		//concatenate
		result = result*10 + lastdigit; 
		//to make that number in reverse we multiply result with 10 and add remainder to it

		originalnum /= 10;
	}

	if(num == result){
		printf("number is palindrome\n");
	}else{
		printf("number is not palindrome\n");
	}

}
```

## Example program

Program to print fibonacci series

[File here!](/programs/fibonacci.c)

`Fibonacci: When sum of prev two numbers is equal to next number`


```C
#include <stdio.h>

//default function that is run by C everytime
int main(){
	//predefined function from the library which prints the output given to it
	int num, prev, last, sum;

	printf("enter a number\n");
	scanf("%d", &num);

	for(int i=0; i <=num; i++){

		if(i < 2){
			prev = 0;
			last = 1;	
		}
		
		sum = prev + last;

		printf("%d ", sum);

		prev = last;
		last = sum;



	}
	
	return 0;
}
```

# Topic4: Functions

## Introduction

If we want to reuse a functionality again and again anywhere randomly, wrap them into functions
When we want to reuse it we call that function. Eg: printf

## Example

```C
#include <stdio.h>

/* 
function to return the maximum of two numbers supplied to it as arguments
function needs to be defined before its call so that compiler knows
in case the function needs to be defined somewhere else you atleast need to include its declaration 
above the call somewhere 

Declaration in this case
int max(int, int); ->name of the function and the type of arguments it will take

*/
int max(int x, int y){
	
	//function can return a value of expression. Expression can be evaluated and converted to return type
	return (x>y)? x: y;

}

//default function that is run by C everytime
int main(){
	
	int a = 10, b = 20, maximum;
	
	//calling the function with equal number of parameters and also the same type is important
	//in case the type of parameters supplied does not match, there will be type coercion
	maximum = max(a,b); 

	printf("%d\n",maximum);

	return 0;	
}
```

### Note

`A function can return anything but an array or another function. A function is meant to return only one thing and array is a collection of things

The arguments to the function are passed by call by value

C programming language only provides call by value (which means creating a copy)
`

## Swap two variables

```C
void swap(int *, int *); //declaration or prototype

void main(){
	int x = 10,y = 20;

	swap(&x,*y); //address of x and y are sent to function

	printf("after swapping %d %d ", a, b);
}

void swap(int *a, int *b){ //pointer to fetch the value from address 
	*a = *a + *b;
	*b = *a - *b;
	*a = *b - *a;
}
//this is how we can change actual parameters from the function call. Passing the address and accessing it from pointers
This will be call by value only. In this value of address is being passed and pointers point to it.
Still call by value only
```

##Note:

`For javascript developers: The function execution context is created for C as well and local variables are popped of from the stack as they are used.
The division of the memory in OS is as follows

- Stack (execution context) -> grows downwards
- Heap (dynamic memory allocation) -> grows upwards
- SV and GV (local variables and global variables)
- Code
`

## Example

Custom C program to implement a pow function

Logic: number raised to some power is, multiplying that number power number of times. So we can implement a loop

```C
//function to return the maximum of two numbers supplied to it as arguments
int pow(int base,int n){

	int result = 1;

    for(int i = 1; i <= n; i ++){

    	result *= base; //multiplying the base for each iteration with the base itself

    }

    //Note this can be optimized further by decreasing the number of iterations in the loop

    return result;
}

//default function that is run by C everytime
int main(){
	
	int base = 5;
	int n = 3;
	
	int result = pow(base,3); //calling the function

	printf("%d \n", result);

	return 0;	
}
```
### Practice Question

`Implement the above using optimized algo`

# Topic5: Pointers

## Introduction

In C programming language memory is accessed or visualized as one dimensional array, no matter what data structure is there. (visualize memory as one dimensional array)

The size of char, int, long depends on the implementation (platform or OS eg 32 or 64 bit). There it is not true that char is always 1 byte or int is always 2 etc. (most of them has char size 1 but it is not standard)

## Note:

- 32-bit operating system:
It can process 32 bits in parallel

- 64-bit operating system:
It can process 64 bits in parallel


The entity in memory can be accessed either by address or name. By address it can be faster by using addresses.
It is because if you access it by name, name is converted to logical address and logical address is converted to physical address.

Names are generally better readable. That is where pointers come into pictures.

They are used to access value if address is given. And dynamically assigned values that do not have a name use pointers to access them.

*Pointer*: Variable containing address of another variable. The size of pointer depends on platform.
Platforms having 16 bits addresses have pointer size of 16 bits and so on.

## Declaring a pointer

```C
int *p // p is pointer or *p is a variable of type integer`

p = &b //&b contains address of b which is assigned to p. *p will fetch value from that address
//therefore in the above case b and *p both will have the same value

//Note: you cannot get addresses of constants or expressions as they cannot be declared in memory. Only variables or other structures can have address

Address will always be of same size, no matter what is the size of value of it holds.
Address has some arithmetic that is done, so it is always declared as int
```

`Address is like standing at door of a house. When * is there, we enter the house. * is called as dereferencing or indirection operation`

## Example

//For address format specifier is %p. %u is format specifier for unsigned int

```C
//default function that is run by C everytime
int main(){
	
	int x = 5;
	int *y = &x;

	printf("%d\n", x); //will print 5
	printf("%p\n", &x); //will give address of x
	printf("%p\n", y); //will give address of x
	printf("%d\n", *y); //will give value of x
	printf("%p\n", &y); //will give address of y

	return 0;	
}
```

## Pointers and functions

Good example of this is the swap function we did earlier where value of addresses was passed to the function and pointers were used to access the value and modify them

## Pointers and arrays

Whatever you could do with array and suffix, can be done with pointers.

- Byte addressable: every byte will get a new address
- Word addressable: every word will get a new address. If a world is of 2 bits, every two bit has a new address and so on.

`Even though an int may occupy two addresses, whenever address of that int is talked about, always starting address is taken`

## Note:

`In case of array int a[]. Array name A is not a variable but other way of representing the address. No where in the memory name is allocated any space. Therefore array name A is just a mnemonic. So if array A starts from address 100, A is as good as writing 100`

### Address arithmatic

- Since A is nothing but starting address of A. Therefore *A is A[0]

Whenever an integer is added to an array name A or a pointer, the addition will be scaled addition.

Eg: if A represents 100, then A+1 represents next element in the array (irrespective of the size of that value stored in the address)

*Therefore if A is at 100, and each int is occupying 2 bytes, then A+1 is 102*

A+i == A+ (i* size of int in this case). It represents Ith element

A + 3 is the 3rd element starting from A[0] i.e A[3].

*(A+3) will give you value at A[3]. Therefor compilter uses pointer in the background

Therefor A+3 is nothing but address of A[3] i.e &A[3]

```C
int *p
p = &a[0] //p now contains address of array 0th element

p = p + 1 //address of a[1] is now stored in p

p = p + i //address of a[i] is now stored in p

/* 

Compiler knows how many bytes to add when you increment value of p is by the declaration
Therefore int *p, char *p is used in respective scenarios depending on the type on which pointer is used 

*/

//Therefore
*(p + 3) ==  a[3] == p[3] // true

//Above line shows that pointer can be used as array

p + 3 == p[3] == a + 3 == &a[3] //true

//There a[3] holds value and a+3 holds address
```

## Note
`Pointer name is variable and array name is just mneumonic. Whenever we pass an array to a function, we really pass the starting address of the array which is taken by a pointer in the function call. Therefore is array name A is passed to a function, function can use a pointer to get values from the array and do same functions that could be done on an array. Therefore array name and pointers both are same`

Therefore when a is array

- a = a + 1 //not valid
- a++ //not valid
- a = p //not valid

BUT the one below is valid

- p = p + 1
- p++
- p = a


## Pointer Arithmetic OR address Arithmetic

Various operations allowed on pointers

- Assignment of pointers of same type. If two pointers are of same type we can assign them to same type.

```C
int *p, *q; //pointers of same type
p=q; //valid
q=p; //valid

int *p, a[];

p = a; //valid
a = p; //not valid

//if type is not same, typecasting needs to be done

char *c;
int *p;

p = (int *)c; //typecasting can be done if c is not of type void
```

- Adding or subtracting a pointer and an int (as we did in arrays). Addition of float or double or long is not allowed. Also pointer cannot be multiplied to an integer

- Subtracting or comparing two pointers to members of same array. If p and q are two pointers pointing to the same array, then we can compare or subtract them. (if q is ahead of p then q-p will give number of elements between p and q including q). Subtraction is also scaled down. Pointer subtraction is used to see space b/w two pointers. Two pointers cannot be added or divided or left or right shift

- Assigning or comparing to zero. Assigning a value to a pointer is meaningless. Assigning a zero or comparing with a zero only is allowed. Zero is used for error case 


## Character arrays and pointers

Most of the time we deal with character arrays in C programming. Eg printf we pass string constants which is nothing but array of characters.

Eg:

```C
char a[] = "rahul"; //valid way to declare string constant or array of characters
//we can go inside the array in this and modify characters

char *p = "rahul"; //valid way to declare string constant or array of characters
//in this case we cannnot modify anything, just access the value

//Both the array above have not 5 but 6 characters as additional \0 character is there
//Basically in a string constant and array is created in the background always with a \0 character at the end
//Simple array options apply to it
//In case of pointer p will point to starting of the array i.e at 'r' and all rules apply as we discussed about pointers and array above
```

```C
//program to copy one string to another (t to s)
//before this both of these arrays need to be passed to this function. The second empty array should be declared with equal memory
void strcpy(char *s, char *t){
	while(*s++ = *t++) //copy first then increment till \0
}

```

## Array of pointers and multidimensional arrays

Since pointer is a variable, we can declare an array of pointers

```C
//name is an array of pointers to character
char *name[] = {"ritu","rahul"}
//these pointers will have memory somewhere and they will be pointing to other memory locations to these string constants

name //will give address of starting of pointer array
name + 1 // will give address of second pointer in pointer array
*(name + 1)// will give value of that address which is nothing but address of "rahul"
*(name + 1) + 2 //will give address of 'a' in "rahul"
//total space is space taken by each row plus space taken by pointers

//the above can also be implemented as multidimensional array
char array[3][13]; //this will declare an array of 3 rows having 13 characters each
//Note in this case since maximum length is 13, if other rows do not have 13 characters, the space will go wasted. IN the pointer notation there was not waste in memory as each array has right memory

name[1][2] ////will give address of 'a' in "rahul"
//total space taken is space taken by array
```

Therefore in C array of pointers is more popular than multidimensional array

## Multidimensional arrays, pointers and function calls

In C we cannot pass full array at once to any function. It is always element by element. So we just have to pass the starting address of the array

```C
fun(int a[]) 
//a in this case will be considered as pointer to the argument which is the first element or the element to be considered in the array.You may are may not use * in this case
```

Passing a two dimensional array

```C
fun(int a[][6]) //the calling function can send an array with max array size as 6 and the called function 'a' is array of pointers pointing to the actual array passed.By default pointer will point to first row first element address

//above can also be written as
fun(int (*a)[6]) //a is a pointer which points to an integer array of 6 elements
fun(int *a[6]) //a is an array of pointers having 6 elements. The difference is cause of operator precedence
```

## Example:

```C
*p++ //by precendence incrementing the value of p, and then applying * to it
a = *p++ //assigning *p to a and then incrementing p

//llarly other way round for ++p
```

## Note

- *Left associativity*: Whenever two operators of same precedence are present then first take into consideration the one that is present left to the operand
- *Right associativity*: Whenever two operators of same precedence are present then first take into consideration the one that is present right to the operand 


## Example

```C
main(){
	int a[] = {10,20,30,40,50,60}; //a contains 6 elements
	int *p[] = {a,a+1,a+2, a+3, a+4, a+5}; //p is an array of pointers to integers and initialized with the values given
	
	int **pp = p; //pp is a pointer to a pointer to an integer. 
	//If p contains the address 200, then pp will have 200 as its value
	//*pp will be value in p
	//**pp will be value in a
	pp++; //will increment the value of pp and make it point to second address of p
	//subrac
	printf("%d %d %d",pp-p,*pp-a,**pp); //1, 1, 20
	*pp++; //increment pp first and then apply *
	
	printf("%d %d %d",pp-p,*pp-a,**pp); //2, 2, 30
	++*pp; //increment value pointed by pp
	
	printf("%d %d %d",pp-p,*pp-a,**pp); //2, 3, 40
	++**pp; //incrementing the value of a[3]
	
	printf("%d %d %d",pp-p,*pp-a,**pp); 2, 3, 41
}
```

## 'IMPORTANT NOTE or Golden rules for pointers and arrays':

In the above example if value of 3 element in array a was to be found, various ways of doing that

```C
a[3] = *(a+3) = *(p[3]) = **(p+3) = **(pp+3)//all will give the same value

//Therefore golden rule

a[something] //gives value
a + something //gives address

//If 'a' is assigned to a pointer p, then p++ can be done but a++ cannot be done. Remember this rule
//Subtraction b/w pointers is possible only if they are pointing to the same array

//Replace anything with 'a' and rule remains same
```

## Pointers to Functions

Even though function is not a variable C still allows you pointers to point to functions and make a call to function.
This is not widely used.

```C
int sum(int, int);

//generic pointer pointing to such functions
int (*fp)(int, int);
fp = sum //storing address of function in fp

s = sum(5,6)

//is equivalent to

s = (*fp)(5,6); //calling function via pointer

void* (*gp)(void*, void*)
//gp is a pointer to a function that contains two args which are void pointers which returns a void pointer

//typecasting to make it point to sum

gp = (void* (void*,void*))sum; //therefore generic pointer can be pointed to any by typecasting
```

## Some complex declarations

```C

//all have been evaluated using precedence table and associativity. So keep that in mind

char **argv
/*
it is useful in case of command line arguments. argv is a pointer to a pointer to a character
 */

int (* daytab)[13]
/*
daytab is a pointer to an array of 13 integers
*/

int * daytab[13]
/*
daytab is an array of 13 integers which are pointers to integers
*/ 

void *comp()
/*
comp is a function which is return a pointer to void
*/

char(* comp)()
/*
comp is a pointer to a function which returns a character
*/

char(*(*f())[])()
/*
a is a function which returns a pointer to an array of pointers to function which returns a character
*/

char(*(*f[3])())[5]
/*
f is an array of pointers (3 elements) pointing a function returning pointer pointing to array containing characters (5 elements)
*/
```

Topic6: Arrays

Simplest data structure which are random accessed. We can access it randomly because while storing it is stored contiguously. Since size of each element is known we can access any element.

## Note
`Storing is not contiguous and only way to access it is to go through a chain or list`


## One dimensional arrays

Explained above.

`
To access A[2] if array is starting from index 0, you will have to cover 2 elements. If starting is from 100, then you have to conver 100 + 2 elements. In general to access Ith element you have to do 100 + i.
`

`
To access A[2] if array is starting from index 1, you will have to cover 1 elements. If starting is from 100, then you have to conver 100 + 2-1 elements. In general to access Ith element you have to do 100 + i-1 and so on other things can be derived
`

## Two dimensional arrays

A is a two dimensional array with size 3 X 4. It means (horizontal X vertical)

- A has 3 rows
- A has 4 columns

Now to enable random access, even this has to be stored contiguously. Therefore, to save it two-dimensional array is converted to one-dimensional array.

There are two ways

*Row major order*
1) Take each row and put it in memory (elements continous to each other, rows contiguous to rows)

### Example

```C
//starting with index 0
00 01 02 03, 10 11 12 13, 20 21 22 23

//Now whenever element 21 is to be accessed
A[2][1] //cross two rows and 2 elements i.e 2*4 (two rows having 4 elements each) + 1(element in the last row)

//therefore if array was starting with 100
// ((2*4) + 1) + 100
// ((2*4) + 1)*size of each element + 100 //number of words or exact address

//Size of A is M X N then, starting index 0, address of array for 
A[i][j] = ((i*n) + (j))*size of each element + BASE

// llarly for index 1 can be done as explained aboved
((i-1)*n + j-1)*size + BASE
```

*Column major order*

```C
00 10 20, 01 11 21, 02 12 22, 03 13 23

//Now for A[2][1]

A[2][1] = ((1*3) (1 column each having 3 elements) + 2 (total elements to be crossed in that column))*2 + 100(base address assume)

//Therefore in general A of size MXN, index 0

A[i][j] = ((j*m)+i)*size + BASE

//If index starts from 1 subtract 1 as done above
```C

## Binary addressing of two dimensional arrays

- Row major (row column size) in binary written as is
- Column major (column row size) in binary written as is

## Example program

Determine if two arrays have an element in common

```C
int isCommon(int a[], int b[], int n, int m){ //sizes are sent as we need the end of the array
		
	int i, j;
	
	for(i = 0; i<n; i++){
		for(j=0; j<m; j++){
			if(a[i]==b[j]){
				return 1; //will return from the function
			}
		}
	}

	return 0; // return 0 if full for loop executes

}
```


#Topic 6: Strings

There are a lot of built in functions for C in string.h

```C
strcat(s,t) // concatenate string t to the end of string s. It returns char * (pointer to starting address of s)
strncat(s,t) //concatenate n characters of string t to the end to string s. It returns char * (pointer to starting address of s)
strcmp(s,t) // return negative, zero or positive for s<t, s==t or s>t
//this will basically do subtraction of characters (ascii values are taken and subtracted) and string is compared
//negative or positive is the difference that comes out
strncmp(s,t,n) //same as strcmp but only in first n characters
strcpy(s,t) //copy t to s. t will be copied to s starting from beginning so chars in s may be replaced till the length of t. It will return s (that is starting address of array)
strncpy(s,t,n) //copy at most n characters of t to s
strlen(s) //return length of s
strchr(s,c) //return Pointer to first c in S or NULL if not present
strrchr(s,c) //return the Pointer to the last occurence of C and return NULL if not present
```
 
## Programs

[File here!](/programs/string-functions.c)


### strcpy()

```C
//str copy function self made
char *strcpynew(char *d, char *s){
  char *saved = d;
  while ((*d++ = *s++) != '\0');
   
  return saved; //returning starting address of s1
}
```

### strcat()

```C
char *strcatnew(char *d, char *s){

  char *saved = d;

  while(*d != '\0'){
    *d++; //finding end of d string;
  }

  while((*d++ = *s++) != '\0');
  // *d = 0; 
  return saved;

}
```

### 


