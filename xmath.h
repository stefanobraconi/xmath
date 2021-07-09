#ifndef XMATH_H_INCLUDED
#define XMATH_H_INCLUDED

#define TRUE_DIGITS 1233 // 4096 bit integer
#define MAX_DIGITS TRUE_DIGITS*5

#define MEMORYOVERFLOW -1
#define DIVIDEBYZERO -2
#define NEGATIVE -3
#define OVERFLOW -4
#define CONV_ERR -5
#define UNKNOW -6

#define NEG 1
#define POS 0

#define MAX(a,b) ((a) > (b) ? (a) : (b))

// Error management
void catch_error(int code);
// Initialize pseudo-casual numbers generator
void seedrandom();
// Generate pseudo-casual number
int random(int nstart,int nend);
// Return number of digits of a value
int getnumberlength(int value);
// Return a length of a string terminated with '\0'
int getstringlength(const char *value);
// Convert a char '0' -> '9' to numerical 0 -> 9
char ctoi(char source);
// Reset array to 0
void v_reset(char *dest, int nelement);
// Allocate array memory
char *v_alloc(int nelement);
// Dellocate array memory
void v_dealloc(char *ptr);
// Set a numerical value in array
void v_set(char *dest,int value, int nelement);
// Convert a string to numerical array
void v_set(char *dest,const char *value, int nelement);
// Extract array number
void v_extract(char *dest, const char *source, int first, int last, int nelement);
// Copy source array on dest array
void v_copy(char *dest, const char *source, int nelement);
// Return index where array number start
int v_start(char *value, int nelement);
// Return pivot index
int v_pivot(char *value, int nelement);
// Split left part of number
void v_splitleft(char *dest, char *source, int nelement);
// Split right part of number
void v_splitright(char *dest,  char *source, int nelement);
// Compare a with b (unsigned) <: -1  =: 0  >:1
short v_compare( char *a, char *b, int nelement);
// Compare a with (int) b
short v_compare( char *a, int b, int nelement);
// Compare value to 0
bool v_iszero(char *value, int nelement);
// Return lenght of array number
int v_length(char *value, int nelement);
// Even or Odd
bool v_even_odd(char *value, int nelement);
// Randomize a number
void v_randomize(char *dest, int digits, int nelement);
// Only serve for v_fast2div function
char read_d2matrix(int r,int c);
// Fast division / 2 (1st)
void v_fast2div(char *result, char *value, int nelement);
// Fast division / 2 (2st)
void v_fast2div(char *value, int nelement);
// Fast multiplication * 2 (1st)
void v_fast2mul(char *result, char *value, int nelement);
// Fast multiplication / 2 (2st)
void v_fast2mul(char *value, int nelement);
// Convert a numerical 0-9  to '0'->'9'
char itoc(char source);
// start: dest[start]     return final idx
int ins_convert(char *retstr,int value, int start);
// Insert string from position
void string_insert(char *dest, char *source, int start);
// Print number without initial 0
char *v_print(char *value, int nelement);
// Unsigned addition
void v_add(char *result, char *op1, char *op2, int nelement);
// Unsigned addition
void v_add(char *result, char *op1, int op2, int nelement);
// Unsigned subtraction
void v_sub(char *result, char *op1, char *op2, int nelement);
// Unsigned subtraction
void v_sub(char *result, char *op1, int op2, int nelement);
// Unsigned russian method multiplication
void v_rmul(char *result,char *op1, char *op2, int nelement);
// Number of digits difference
int v_diff(char *op1,char *op2, int nelement);
// Create a 10^x
void v_pow10(char *dest,int exp,int nelement);
// Unsigned canadian division
void v_cdiv(char *result,char *op1, char *op2, int nelement);
// Unsigned canadian mod
void v_cmod(char *result,char *op1, char *op2, int nelement);

class xint {
	private:
		// Value represented in little endian mode
		char *value;
		// Sign: 0 positive, 1 negative
		char sign;

	public:
		xint();
		virtual ~xint();
		xint(int op);
		xint(char *op);
		xint(const xint &op);

		void setvalue(int op);
		void setvalue(char *op);
		void setvalue(xint op);
		void randomize(int digits);

		void add(const xint &op1, const xint &op2);
		void sub(const xint &op1, const xint &op2);
		void mul(const xint &op1, const xint &op2);
		void div(const xint &op1, const xint &op2);

		void add(const xint &op);
		void sub(const xint &op);
		void mul(const xint &op);
		void div(const xint &op);

		// Bitwise right shift
		void rs(const xint &op);
		// Bitwise left shift
		void ls(const xint &op);

		void increment();
		void decrement();

		// insert a 0-9 number
		void pushr(char number);
		void pushl(char number);
		void pushr(char number, int repeat);
		void pushl(char number, int repeat);

		// Square root
		void sqrt();

		// Factorial
		void factorial();

		// Absolute value
		void abs();

		// Exponentiation
		void pow(xint &op);

		// Show full number
		char *show();

		// Show number in scientific form
		char *show(int significant);

		// Assign operator overload
		xint &operator  =   (const xint& op);
		xint &operator  =   (int op);

		// Relational operator overload
		bool operator   ==  (const xint &op2);
		bool operator   !=  (const xint &op2);
		bool operator   >=  (const xint &op2);
		bool operator   >   (const xint &op2);
		bool operator   <=  (const xint &op2);
		bool operator   <   (const xint &op2);

		// Arithmetical operators overload
		xint operator   +   (const xint &op2) const;
		xint operator   -   (const xint &op2) const;
		xint operator   *   (const xint &op2) const;
		xint operator   /   (const xint &op2) const;
		xint operator   %   (const xint &op2) const;

		// Friend functions who need private access
		friend char xcompare(const xint &op1, const xint &op2);

		// Return a new xint with absolute (positive) value.
		friend xint xabs(const xint &op1);
		// Convert int to xint
		friend xint xc(int op);

		// Naive addiction
		friend void xadd(xint &result, const xint &op1, const xint &op2);
		// Naive subtraction
		friend void xsub(xint &result, const xint &op1, const xint &op2);
		// Russian multiplication algorithm
		friend void xrmul(xint &result, const xint &op1, const xint &op2);
		// Canadian divide algorithm
		friend void xcdiv(xint &result, const xint &op1, const xint &op2);
		friend void xcmod(xint &result, const xint &op1, const xint &op2);

};

#endif // XMATH_H_INCLUDED





