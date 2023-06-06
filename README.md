# xmath
## easy of use free c++ library for arbitrary precision integer arithmetic.

release 2021.06.17
by Stefano Braconi
released under GNU GPLv3 license

**Introduction**

XMATH is a easy of use free c++ library for arbitrary precision integer arithmetic, 
operating on signed or unsigned value.
This library add a "**xint**" data type and you can merge with normal int data type;
is comprensive of base arithmetic operation **( + , -, *, /, % )**, compare operators **( ==, !=, <, <=, >, >= )**, also include a little set of math function.
Finally, it also has functions for displaying data in normal and scientific format.

*Used algorithm:*<br/>
Multiplication:
Russian Peasant method<br/> 
Divide: Canadian method (I think is also called *"Nuffield"* or *"siciliana"*)

*Very important:*
This library is absolutely not meant to compete with GNU Math!

**new user data type**

**`xint`** (signed & unsigned arbitrary precision integer)

**memory allocation & digits**

In xmath.h you can define computing area with `#define TRUE_DIGITS 1233`  (default 1233 digits = 4096 bit) but actually the memory allocation is `TRUE_DIGITS * 5` (default: 20480 bit) to avoid numerical overflow; you can modify this value.

**Declaration**

you can declare the variable in several ways:

`xint var;`<br/>
`var = value;`<br/>

`xint var(integer value);`<br/>
`xint var(char *value);`<br/>
`xint var(xint source)`<br/>

**Using xint data type with operators**

you can merge int type with xint data type in arithmetical and comparing operators:

example 1:<br/>
 `xint a;`<br/>
 `xint b;`<br/>
 `xint c;`<br/>
 `a = 10;`<br/>
 `b = 34;`<br/>
 `c = ( a + 1 )* b - 10;`<br/>
 
example 2:<br/>
 `xint idx;`<br/>
 `xint var2;`<br/>
 `var2 = 100;`<br/>
 `for (idx = 0; idx < var2 + 10; idx.increment()){...}`<br/>


**XINT API reference**


**Constructor:**

`xint(int op);`<br/>
`xint(char *op);`<br/>
`xint(const xint &op);`<br/>

`void setvalue(int op);`<br/>
`void setvalue(char *op);`<br/>
`void setvalue(xint op);`<br/>

`void randomize(int digits);`

**Arithmetical methods:**

`void add(const xint &op1, const xint &op2);`<br/>
`void sub(const xint &op1, const xint &op2);`<br/>
`void mul(const xint &op1, const xint &op2);`<br/>
`void div(const xint &op1, const xint &op2);`<br/>

`void add(const xint &op);`<br/>
`void sub(const xint &op);`<br/>
`void mul(const xint &op);`<br/>
`void div(const xint &op);`<br/>

`void increment();`<br/>
`void decrement();`<br/>

**Bitwise method operators**:

`void rs(const xint &op);`   Bitwise right shift<br/>
`void ls(const xint &op);`   Bitwise left shift<br/>

Append a number (0->9) from right or left:

`void pushr(char number);`<br/>
`void pushl(char number);`<br/>
`void pushr(char number, int repeat);`<br/>
`void pushl(char number, int repeat);`<br/>

**Math function:**

`void sqrt();`		Square root!<br/>
`void factorial();`	Simply.. factorial!<br/>
`void abs();`		Absolute value!<br/>
`void pow(xint &op);` 	Exponentiation!<br/>

**Show function**

`char *show();`<br/>
`char *show(int significant);` Show number in scientific form<br/>


*I apologize for all the mistakes i have surely made! Everything seems to work, but i will be glad if you report errors*
