# xmath
XMATH is a easy of use free c++ library for arbitrary precision integer arithmetic.

*XMATH* arbitrary precision signed integer 
release 2021.06.17
by Stefano Braconi - calico.vae@gmail.com

released under GNU GPLv3 license

0. Introduction

XMATH is a easy of use free c++ library for arbitrary precision integer arithmetic, 
operating on signed or unsigned value.
This library add a "xint" data type and you can merge with normal int data type;
is comprensive of base arithmetic operation (+,-,*,/), compare operators (==, !=, <, <=, >, >=), also include a little set of math function.
Finally, it also has functions for displaying data in normal and scientific format.

Used algorithm:
Multiplication: Russian Peasant Divide
Divide: Canadian divide (I think is also called "Nuffield" or "siciliana")

Very important:
This library is absolutely not meant to compete with GNU Math!!!!!!!!!!!!!!

1. new user data type

xint (signed & unsigned arbitrary precision integer)

2. memory allocation & digits

In xmath.h you can define computing area with:
#define TRUE_DIGITS 1233   (default 1233 digits = 4096 bit)
but actually the memory allocation is TRUE_DIGITS * 5 (default: 20480 bit) to avoid numerical overflow; you can modify this value.

3. Declaration

you can declare the variable in several ways:

xint var;
var=value;

xint var(integer value);
xint var(char *value);
xint var(xint source)

4. Using xint data type with operators

you can merge int type with xint data type in arithmetical and comparing operators:

example 1:
 xint a;
 xint b;
 xint c;
 a=10;
 b=34;
 c=(a+1)*b-10;
 
example 2:
 xint idx;
 xint var2;
 var2=100;
 for (idx=0; idx < var2+10; idx.increment()){...}

#######################################
5. XINT object functions
#######################################

** Constructor:

xint(int op);
xint(char *op);
xint(const xint &op);

void setvalue(int op);
void setvalue(char *op);
void setvalue(xint op);

void randomize(int digits);

** Arithmetical methods:

void add(const xint &op1, const xint &op2);
void sub(const xint &op1, const xint &op2);
void mul(const xint &op1, const xint &op2);
void div(const xint &op1, const xint &op2);

void add(const xint &op);
void sub(const xint &op);
void mul(const xint &op);
void div(const xint &op);

void increment();
void decrement();

** Bitwise method operators:

void rs(const xint &op);   Bitwise right shift
void ls(const xint &op);   Bitwise left shift

** Append a number (0->9) from right or left:

void pushr(char number);
void pushl(char number);
void pushr(char number, int repeat);
void pushl(char number, int repeat);

** Math function:

void sqrt();		Square root!
void factorial();	Simply.. factorial!
void abs();		Absolute value!
void pow(xint &op); 	Exponentiation!

** Show function

char *show();
char *show(int significant); Show number in scientific form


I apologize for all the mistakes i have surely made! Everything seems to work, but i will be glad if you report errors
