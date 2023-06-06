#include "xmath.h"
// #include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

void catch_error(int code) {
/// switch case Message....
	exit(code);
}

void seedrandom() {
	srand((unsigned) time(0));
}

int random(int nstart,int nend) {
	return nstart + (rand() % nend);
}

int getnumberlength(int value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

int getstringlength(const char *value) {
	int idx=0;
	while (value[idx]!='\0') idx++;
	return idx;
}

char ctoi(char source) {
	switch (source) {
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
		default:
			exit(CONV_ERR);
	}
	exit(CONV_ERR);
}

void v_reset(char *dest, int nelement) {
	for (int idx=0; idx<nelement; idx++) dest[idx]=0;
}

char *v_alloc(int nelement) {
	char *ptr = new char[nelement];
	if (!ptr) catch_error(MEMORYOVERFLOW);
	v_reset(ptr,nelement);
	return ptr;
}

void v_dealloc(char *ptr) {
	delete []ptr;
}

void v_set(char *dest,int value, int nelement) {
	int i=nelement-1;
	int temp;
	int decimalvalue=value;
	v_reset(dest,nelement);
	while(decimalvalue > 0) {
		temp = decimalvalue % 10;
		dest[i] = temp;
		decimalvalue=decimalvalue / 10;
		i--;
	}
	return;
}

void v_set(char *dest,const char *value, int nelement) {
	v_reset(dest,nelement);
	int value_length=getstringlength(value);
	int idxdest=nelement-1;
	int idxsource=value_length-1;
	for (int counter=0; counter<value_length; counter++) {
		dest[idxdest]=ctoi(value[idxsource]);
		idxdest--;
		idxsource--;
	}
	return;
}

void v_extract(char *dest, const char *source, int first, int last, int nelement) {
	v_reset(dest,nelement);
	int idxsource=last;
	int length=(last-first)+1;
	for (int idxdest=nelement-1; idxdest>=nelement-length; idxdest--) {
		dest[idxdest]=source[idxsource];
		idxsource--;
	}
	return;
}

void v_copy(char *dest, const char *source, int nelement) {
	for (int idx=0; idx<nelement; idx++) dest[idx]=source[idx];
	return;
}

int v_start(char *value, int nelement) {
	int idx=0;
	while(value[idx]==0 && idx<nelement) idx++;
	return idx;
}

int v_pivot(char *value, int nelement) {
	int idx=0;
	idx=v_start(value, nelement);
	int length= nelement-idx-1;
	return idx+(length/2);
}

void v_splitleft(char *dest, char *source, int nelement) {
	v_reset(dest,nelement);
	int start=v_start(source,nelement);
	int mid=v_pivot(source,nelement);
	v_extract(dest,source,start,mid,nelement);
	return;
}

void v_splitright(char *dest,  char *source, int nelement) {
	v_reset(dest,nelement);
	int mid=v_pivot(source,nelement);
	v_extract(dest,source,mid+1,nelement-1,nelement);
	return;
}

short v_compare( char *a, char *b, int nelement) {
	int idx;
	for (idx=0; idx<nelement; idx++) {
		if (a[idx]!=0 || b[idx]!=0) {
			if (a[idx]!=b[idx]) {
				if (a[idx]<b[idx]) return -1;
				else return 1;
			}
		}
	}
	return 0;
}

short v_compare( char *a, int b, int nelement) {
	int idx;
	char *_b=v_alloc(nelement);
	v_set(_b,b,nelement);
	for (idx=0; idx<nelement; idx++) {
		if (a[idx]!=0 || _b[idx]!=0) {
			if (a[idx]!=_b[idx]) {
				if (a[idx]<_b[idx]) {
					delete [] _b;
					return -1;
				} else {
					delete [] _b;
					return 1;
				}
			}
		}
	}
	delete [] _b;
	return 0;
}

bool v_iszero(char *value, int nelement) {
	int idx;
	for (idx=0; idx<nelement; idx++) {
		if (value[idx]!=0) return false;
	}
	return true;
}

int v_length(char *value, int nelement) {
	if (v_iszero(value, nelement)) return 0;
	int idx=0;
	while(value[idx]==0) idx++;
	return nelement-idx;
}

bool v_even_odd(char *value, int nelement) {
	if (value[nelement-1]%2==0) return true;
	else return false;
}

void v_randomize(char *dest, int digits, int nelement) {
	v_reset(dest,nelement);
	if (digits>nelement) catch_error(UNKNOW);
	for (int idx=nelement-1; idx>=nelement-digits; idx--)
		dest[idx]=random(0,9);
	return ;
}

char read_d2matrix(int r,int c) {
	const char d2_matrix[10][10]= {0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
	return d2_matrix[r][c];
}

void v_fast2div(char *result, char *value, int nelement) {
	if (v_iszero(value,nelement)) return;
	char *_value=v_alloc(nelement);
	v_copy(_value,value,nelement);
	int idx_dest=nelement-1;
	for (int idx=nelement-1; idx>=v_start(_value,nelement)-1; idx--) {
		result[idx_dest]=read_d2matrix(_value[idx-1],_value[idx]);
		idx_dest--;
	}
	v_copy(result,_value,nelement);
	delete [] _value;
	return;
}

void v_fast2div(char *value, int nelement) {
	if (v_iszero(value,nelement)) return;
	int idx_dest=nelement-1;
	for (int idx=nelement-1; idx>=v_start(value,nelement)-1; idx--) {
		value[idx_dest]=read_d2matrix(value[idx-1],value[idx]);
		idx_dest--;
	}
	return;
}

void v_fast2mul(char *result, char *value, int nelement) {
	char *res=v_alloc(nelement);
	int carry=0;
	int idx;
	v_copy(res,value,nelement);
	for (idx=nelement-1; idx>=v_start(value,nelement); idx--) {
		res[idx]=(res[idx]<<1) + carry;
		if (res[idx]>=10) {
			res[idx]-=10;
			carry=1;
		} else carry=0;
	}
	if (carry==1) {
		res[idx]=1;
	}
	v_copy(result,res,nelement);
	delete [] res;
	return;
}

void v_fast2mul(char *value, int nelement) {
	int carry=0;
	int idx;
	for (idx=nelement-1; idx>=v_start(value,nelement); idx--) {
		value[idx]=(value[idx]<<1) + carry;
		if (value[idx]>=10) {
			value[idx]-=10;
			carry=1;
		} else carry=0;
	}
	if (carry==1) {
		value[idx]=1;
	}
	return;
}

char itoc(char source) {
	switch (source) {
		case 0:
			return '0';
			break;
		case 1:
			return '1';
			break;
		case 2:
			return '2';
			break;
		case 3:
			return '3';
			break;
		case 4:
			return '4';
			break;
		case 5:
			return '5';
			break;
		case 6:
			return '6';
			break;
		case 7:
			return '7';
			break;
		case 8:
			return '8';
			break;
		case 9:
			return '9';
			break;
		default:
			exit(CONV_ERR);
	}
	exit(CONV_ERR);
}

int ins_convert(char *retstr,int value, int start) {
	char dest[1000];
	int decimalValue=value;
	int temp;
	int i_d=start;
	long i=0;
	while(decimalValue > 0) {
		temp = decimalValue % 10;
		dest[i] = itoc(temp);
		decimalValue=decimalValue / 10;
		i++;
	}
	for (i-=1; i>=0; i--) {
		retstr[i_d]=dest[i];
		i_d++;
	}
	return i_d;
}

void string_insert(char *dest, char *source, int start) {
	int idxdest=start;
	int idxsource=0;
	while (source[idxsource]!='\0') {
		dest[idxdest]=source[idxsource];
		idxsource++;
		idxdest++;
	}
	dest[idxdest]='\0';
}

char *v_print(char *value, int nelement) {
	char *ret=v_alloc(nelement);
	char *zero=v_alloc(nelement);
	int idxret=0;
	int flag=0;
	if (v_iszero(value,nelement)) {
		ret[0]='0';
		ret[1]='\0';
		delete [] zero;
		return ret;
	} else {
		if (v_compare(value,zero,nelement)<0) { /// this for print negative number... but is also implemented in xint class.
			ret[idxret]='-';
			idxret++;
		}
		for (int i=0; i<nelement; i++) {
			if (flag==0&&value[i]==00) {
			} else {
				flag=1;
				ret[idxret]=itoc(value[i]);
				idxret++;
			}
		}
	}
	ret[idxret]='\0';
	delete [] zero;
	return ret;
}

void v_add(char *result, char *op1, char *op2, int nelement) {
	char *_op1=v_alloc(nelement);
	char *_op2=v_alloc(nelement);
	v_copy(_op1,op1,nelement);
	v_copy(_op2,op2,nelement);
	v_reset(result,nelement);
	int final_index=nelement-(MAX(v_length(_op1,nelement),v_length(_op2,nelement)))-1;
	int index_dest;
	short carry=0;
	for (index_dest=nelement-1; index_dest>=final_index-2; index_dest--) {
		result[index_dest]=_op1[index_dest]+_op2[index_dest]+carry;
		if (result[index_dest]>9) {
			result[index_dest]=result[index_dest]-10;
			carry=1;
		} else carry=0;
	}
	delete [] _op1;
	delete [] _op2;
	return;
}

void v_add(char *result, char *op1, int op2, int nelement) {
	char *_op2=v_alloc(nelement);
	v_set(_op2,op2,nelement);
	v_add(result,op1,_op2,nelement);
}

void v_sub(char *result, char *op1, char *op2, int nelement) {
	char *_op1=v_alloc(nelement);
	char *_op2=v_alloc(nelement);
	v_copy(_op1,op1,nelement);
	v_copy(_op2,op2,nelement);
	v_reset(result,nelement);
	if (v_compare(_op1,_op2,nelement)==-1) catch_error(NEGATIVE);
	char carry=0;
	int final_index=nelement-MAX(v_length(_op1,nelement),v_length(_op2,nelement));
	for (int idx=nelement-1; idx>=final_index-2; idx--) {
		if (_op1[idx]-_op2[idx]-carry<0) {
			result[idx]=abs((10+_op1[idx]-carry)-_op2[idx]);
			carry=1;
		} else {
			result[idx]=abs(_op1[idx]-_op2[idx]-carry);
			carry=0;
		}
	}
	delete [] _op1;
	delete [] _op2;
	return ;
}

void v_sub(char *result, char *op1, int op2, int nelement) {
	char *_op2=v_alloc(nelement);
	v_set(_op2,op2,nelement);
	v_sub(result,op1,_op2,nelement);
}

void v_rmul(char *result,char *op1, char *op2, int nelement) {
	if (v_compare(op2,1,nelement)==0) {
		v_copy(result,op1,nelement);
		return;
	}
	char *zero=v_alloc(nelement);
	if (v_even_odd(op1,nelement)==false && v_even_odd(op2,nelement)==false) {
		v_copy(result,op2,nelement);
		return;
	}
	char *_op1=v_alloc(nelement);
	char *_op2=v_alloc(nelement);
	v_copy(_op1,op1,nelement);
	v_copy(_op2,op2,nelement);
	v_reset(result,nelement);
	while (v_compare(_op1,zero,nelement)==1) {
		if (v_even_odd(_op1,nelement)==false && v_even_odd(_op2,nelement)==true) {
			v_add(result,result,_op2,nelement);
		}
		v_fast2div(_op1,nelement);
		v_add(_op2,_op2,_op2,nelement);
	}
	delete [] zero;
	delete [] _op1;
	delete [] _op2;
	return ;
}

int v_diff(char *op1,char *op2, int nelement) {
	int l1=v_length(op1,nelement);
	int l2=v_length(op2,nelement);
	if (l1>l2) return l1-l2;
	else return l2-l1;
}

void v_pow10(char *dest,int exp,int nelement) {
	v_reset(dest,nelement);
	dest[nelement-exp-1]=1;
}

void v_cdiv(char *result,char *op1, char *op2, int nelement) {
	bool exit=false;
	char *qsum=v_alloc(nelement);
	v_set(qsum,0,nelement);
	char *o1=v_alloc(nelement);
	v_copy(o1,op1,nelement);
	char *od=v_alloc(nelement);
	v_set(od,0,nelement);
	// cout<<v_print(o1,nelement)<<endl; // debug
	char *m=v_alloc(nelement);
	char *condition=v_alloc(nelement);
	while (exit==false) {
		// int diff=v_diff(o1,op2,nelement); // debug
		v_pow10(m, v_diff(o1,op2,nelement),nelement);
		v_rmul(od,op2,m,nelement);
		while (v_compare(od,o1,nelement)==1) {
			v_fast2div(m,nelement); // not suitable for mod function
			//v_pow10(m, v_diff(o1,op2,nelement)-1,nelement); // suitable for mod function
			v_rmul(od,op2,m,nelement);
		}
		if (v_compare(m,0,nelement)==0) v_set(m,1,nelement);
		v_rmul(od,op2,m,nelement);
		if (v_compare(o1,od,nelement)==-1) exit=true;
		else {
			v_sub(condition,o1,od,nelement);
			if (v_compare(condition,0,nelement)==-1) exit=true;
			else {
				// cout<<v_print(od,nelement)<<" . "<<v_print(m,nelement)<<endl;
				v_add(qsum,qsum,m,nelement);
				v_sub(o1,o1,od,nelement);
			}
		}
		// cout<<v_print(o1,nelement)<<endl; // debug
	}
	v_copy(result,qsum,nelement);
	delete [] qsum; // divide
	delete [] o1;	// mod
	delete [] od;
	delete [] m;
	delete [] condition;
}

void v_cmod(char *result,char *op1, char *op2, int nelement) {
	bool exit=false;
	char *qsum=v_alloc(nelement);
	v_set(qsum,0,nelement);
	char *o1=v_alloc(nelement);
	v_copy(o1,op1,nelement);
	char *od=v_alloc(nelement);
	v_set(od,0,nelement);
	// cout<<v_print(o1,nelement)<<endl; // debug
	char *m=v_alloc(nelement);
	char *condition=v_alloc(nelement);
	while (exit==false) {
		// int diff=v_diff(o1,op2,nelement); // debug
		v_pow10(m, v_diff(o1,op2,nelement),nelement);
		v_rmul(od,op2,m,nelement);
		while (v_compare(od,o1,nelement)==1) {
			//v_fast2div(m,nelement);
			v_pow10(m, v_diff(o1,op2,nelement)-1,nelement);
			v_rmul(od,op2,m,nelement);
		}
		if (v_compare(m,0,nelement)==0) v_set(m,1,nelement);
		v_rmul(od,op2,m,nelement);
		if (v_compare(o1,od,nelement)==-1) exit=true;
		else {
			v_sub(condition,o1,od,nelement);
			if (v_compare(condition,0,nelement)==-1) exit=true;
			else {
				// cout<<v_print(od,nelement)<<" . "<<v_print(m,nelement)<<endl;
				v_add(qsum,qsum,m,nelement);
				v_sub(o1,o1,od,nelement);
			}
		}
		// cout<<v_print(o1,nelement)<<endl; // debug
	}
	//v_copy(result,qsum,nelement);
	v_copy(result,o1,nelement);
	delete [] qsum;
	delete [] o1;
	delete [] od;
	delete [] m;
	delete [] condition;
}

xint xc(int op) {
	xint converted(op);
	return converted;
}

xint::xint() {
	value=v_alloc(MAX_DIGITS);
	sign=POS;
}

xint::~xint() {
	delete [] value;
}

xint::xint(int op) {
	value=v_alloc(MAX_DIGITS);
	if (op<0) sign=NEG;
	else sign=POS;
	v_set(value,op,MAX_DIGITS);
}

xint::xint(char *op) {
	value=v_alloc(MAX_DIGITS);
	if (v_compare(op,0,MAX_DIGITS)==-1) sign=NEG;
	else sign=POS;
	v_set(value,op,MAX_DIGITS);
}

xint::xint(const xint &op) {
	value=v_alloc(MAX_DIGITS);
	v_copy(value,op.value,MAX_DIGITS);
	sign=op.sign;
}

void xint::setvalue(int op) {
	if (op<0) sign=NEG;
	else sign=POS;
	v_set(value,op,MAX_DIGITS);
}

void xint::setvalue(char *op) {
	if (v_compare(op,0,MAX_DIGITS)==-1) sign=NEG;
	else sign=POS;
	v_set(value,op,MAX_DIGITS);
}

void xint::setvalue(xint op) {
	v_copy(value,op.value,MAX_DIGITS);
	sign=op.sign;
}

void xint::randomize(int digits) {
	v_randomize(value,digits,MAX_DIGITS);
}

void xint::abs() {
	sign=POS;
}

void xint::pow(xint &op) {
	xint idx(1);
	xint _org(*this);
	for (; idx<op; idx.increment()) {
		xrmul(*this,*this,_org);
	}
}

void xint::increment() {
	add(1);
}
void xint::decrement() {
	sub(1);
}

void xint::pushr(char number) {
	if (number<0 || number>9) catch_error(CONV_ERR);
	int start=v_start(value,MAX_DIGITS);
	if (start==0) catch_error(OVERFLOW);
	int idx;
	for (idx=start; idx<MAX_DIGITS; idx++) value[idx-1]=value[idx];
	value[MAX_DIGITS-1]=number;
}

void xint::pushl(char number) {
	if (number<0 || number>9) catch_error(CONV_ERR);
	int idxinit=v_start(value,MAX_DIGITS);
	if (idxinit<1) catch_error(OVERFLOW);
	value[idxinit-1]=number;
}

void xint::pushr(char number, int repeat) {
	for (int idx=0; idx<repeat; idx++) pushr(number);
}

void xint::pushl(char number,int repeat) {
	for (int idx=0; idx<repeat; idx++) pushl(number);
}

void xint::add(const xint &op1, const xint &op2) {
	xadd(*this,op1,op2);
}

void xint::sub(const xint &op1, const xint &op2) {
	xsub(*this,op1,op2);
}

void xint::mul(const xint &op1, const xint &op2) {
	xrmul(*this,op1,op2);
}

void xint::div(const xint &op1, const xint &op2) {
	xcdiv(*this,op1,op2);
}

void xint::add(const xint &op) {
	xadd(*this,*this,op);
}

void xint::sub(const xint &op) {
	xsub(*this,*this,op);
}

void xint::mul(const xint &op) {
	xrmul(*this,*this,op);
}

void xint::div(const xint &op) {
	xcdiv(*this,*this,op);
}

// CONTROLLARE SEGNO E RISULTATO
void xint::sqrt() {
	const char EDGE=1;  /// 1 work..but true is  0.001
	xint rn,rn_meno1,diff;
	rn_meno1=*this;
	diff=2;
	diff.mul(EDGE);
	while(diff>EDGE) {
		//rn=(rn_meno1+x/rn_meno1)/2;
		xadd(rn,rn_meno1,*this);
		xcdiv(rn,rn,rn_meno1);
		//rn=(rn_meno1+*this/rn_meno1);
		v_fast2div(rn.value,MAX_DIGITS);
		xsub(diff,xabs(rn),xabs(rn_meno1));
		//diff=xabs(rn-rn_meno1);
		rn_meno1=rn;
	}
	rn.sign=0;
	*this=rn;
}

void xint::factorial() {
	xint f(*this);
	f.decrement();
	xint result(*this);
	for (; f>1; f.decrement()) {
		xrmul(result,result,f);
	}
	*this=result;
}

char *xint::show(int significant) {
	char *ret = new char[significant+1000];
	if (!ret) catch_error(MEMORYOVERFLOW);
	for (int i=0; i<significant+1000; i++) ret[i]=' ';
	if (v_iszero(value,MAX_DIGITS)) {
		ret[0]='0';
		ret[1]='\0';
		return ret;
	}
	int retidx;
	int idx;
	int firstidx=0;
	int e;
	idx=0;
	while (value[idx]==0 && idx<MAX_DIGITS) {
		idx++;
		firstidx++;
	}
	idx++;
	e=0;
	for (; idx<MAX_DIGITS; idx++) e++;
	ret[0]=itoc(value[firstidx]);
	ret[1]=',';
	retidx=2;
	for (idx=firstidx+1; idx<firstidx+significant; idx++) if (idx<MAX_DIGITS) {
			ret[retidx]=itoc(value[idx]);
			retidx++;
		}
	ret[retidx]='e';
	retidx++;
	retidx=ins_convert(ret,e, retidx);
	ret[retidx]='\0';
	return ret;
}

char * xint::show() {
	char *str=v_alloc(MAX_DIGITS);
	if (sign==NEG) {
		str[0]='-';
		string_insert(str,v_print(value,MAX_DIGITS),1);
	} else str=v_print(value,MAX_DIGITS);
	return str;
}

xint xint::operator+(const xint &op2) const {
	xint result;
	xadd(result, *this, op2);
	return result;
}

xint xint::operator-(const xint &op2) const {
	xint result;
	xsub(result, *this, op2);
	return result;
}

xint xint::operator*(const xint &op2) const {
	xint result;
	xrmul(result, *this, op2);
	return result;
}

xint xint::operator/(const xint &op2) const {
	xint result;
	xcdiv(result, *this, op2);
	return result;
}

xint xint::operator%(const xint &op2) const {
	xint result;
	xcmod(result, *this, op2);
	return result;
}

/// ASSIGN OPERATOR
xint &xint::operator=(const xint &op) {
	if (this == &op) return *this; // handle self assignment
	v_copy(value, op.value,MAX_DIGITS);
	sign=op.sign;
	return *this;
}

xint &xint::operator=(int op) {
	xint _op(op);
	v_copy(value, _op.value,MAX_DIGITS);
	sign=_op.sign;
	return *this;
}

bool xint ::operator==(const xint &op2) {
	switch (xcompare(*this,op2)) {
		case -1:
			return false;
			break;
		case 0:
			return true;
			break;
		case 1:
			return false;
			break;
		default:
			return false;
	}
}

bool xint::operator!=( const xint &op2) {
	if (*this==op2) return false;
	else return true;
}

bool xint::operator>=( const xint &op2) {
	if (*this==op2) return true;
	if (*this>op2) return true;
	return false;
}

bool xint::operator>( const xint &op2) {
	if (*this==op2) return false;
	if (xcompare(*this,op2)==0 && sign==1 && op2.sign==0) return false;
	if (xcompare(*this,op2)==0 && sign==0 && op2.sign==1) return true;
	if (xcompare(*this,op2)==-1 && sign==0 && op2.sign==0) return false;
	if (xcompare(*this,op2)==1 && sign==0 && op2.sign==0) return true;
	if (xcompare(*this,op2)==-1 && sign==1 && op2.sign==0) return false;
	if (xcompare(*this,op2)==1 && sign==1 && op2.sign==0) return false;
	if (xcompare(*this,op2)==1 && sign==1 && op2.sign==1) return false;
	if (xcompare(*this,op2)==-1 && sign==1 && op2.sign==1) return true;
	if (xcompare(*this,op2)==-1 && sign==0 && op2.sign==1) return true;
	if (xcompare(*this,op2)==1 && sign==0 && op2.sign==1) return true;
	return false;
}

bool xint::operator<=( const xint &op2) {
	if (*this==op2) return true;
	if (*this<op2) return true;
	return false;
}

bool xint::operator<( const xint &op2) {
	if (*this==op2) return false;
	if (xcompare(*this,op2)==0 && sign==1 && op2.sign==0) return true;
	if (xcompare(*this,op2)==0 && sign==0 && op2.sign==1) return false;
	if (xcompare(*this,op2)==-1 && sign==0 && op2.sign==0) return true;
	if (xcompare(*this,op2)==1 && sign==0 && op2.sign==0) return false;
	if (xcompare(*this,op2)==-1 && sign==1 && op2.sign==0) return true;
	if (xcompare(*this,op2)==1 && sign==1 && op2.sign==0) return true;
	if (xcompare(*this,op2)==1 && sign==1 && op2.sign==1) return true;
	if (xcompare(*this,op2)==-1 && sign==1 && op2.sign==1) return false;
	if (xcompare(*this,op2)==-1 && sign==0 && op2.sign==1) return false;
	if (xcompare(*this,op2)==1 && sign==0 && op2.sign==1) return false;
	return false;
}

xint xabs(const xint &op1) {
	xint result(op1);
	result.sign=POS;
	return result;
}

void xint::rs(const xint &op) {
	xint cmp(op);
	xint idx(0);
	if (cmp==xc(1)) v_fast2div(value, MAX_DIGITS);
	else {
		for (; idx<cmp; idx.increment()) {
			v_fast2div(value, MAX_DIGITS);
		}
	}
}

void xint::ls(const xint &op) {
	xint cmp(op);
	xint idx(0);
	if (cmp==xc(1)) v_fast2mul(value, MAX_DIGITS);
	else {
		for (; idx<cmp; idx.increment()) {
			v_fast2mul(value, MAX_DIGITS);
		}
	}
}

char xcompare(const xint &op1,const xint &op2) {
	xint _op1(op1);
	xint _op2(op2);
	if (_op1.sign==NEG && _op2.sign==POS) return -1;
	if (_op1.sign==POS && _op2.sign==NEG) return 1;
	if (_op1.sign==NEG && _op2.sign==NEG) {
		xint buffer(_op1);
		_op1=_op2;
		_op2=buffer;
	}
	long idx;
	for (idx=0; idx<MAX_DIGITS; idx++) {
		if (_op1.value[idx]!=0 || _op2.value[idx]!=0) {
			if (_op1.value[idx]!=_op2.value[idx]) {
				if (_op1.value[idx]<_op2.value[idx]) return -1;
				else return 1;
			}
		}
	}
	return 0;
}

void xadd(xint &result, const xint &op1, const xint &op2) {
	if (op1.sign==0 && op2.sign==0) {
		result.sign=0;
		v_add(result.value,op1.value,op2.value,MAX_DIGITS);
	}
	if (op1.sign==1 && op2.sign==1) {
		result.sign=1;
		v_add(result.value,op1.value, op2.value,MAX_DIGITS);
	}
	if ((op1.sign==1 && op2.sign==0 && xcompare(xabs(op1),xabs(op2))==-1)) {
		result.sign=0;
		v_sub(result.value,op2.value,op1.value,MAX_DIGITS);
	}
	if ((op1.sign==1 && op2.sign==0 &&  xcompare(xabs(op1),xabs(op2))==1)) {
		result.sign=1;
		v_sub(result.value,op1.value,op2.value,MAX_DIGITS);
	}
	if ((op1.sign==0 && op2.sign==1 &&  xcompare(xabs(op1),xabs(op2))==-1)) {
		result.sign=1;
		v_sub(result.value,op2.value,op1.value,MAX_DIGITS);
	}
	if ((op1.sign==0 && op2.sign==1 &&  xcompare(xabs(op1),xabs(op2))==1)) {
		result.sign=0;
		v_sub(result.value,op1.value,op2.value,MAX_DIGITS);
	}
}

void xsub(xint &result,const xint &op1, const xint &op2) {
	xint _op1(op1);
	xint _op2(op2);
	if (_op1.sign==0 && _op2.sign==0 && xcompare(xabs(_op1),xabs(_op2))==-1) {
		v_sub(result.value,_op2.value,_op1.value,MAX_DIGITS);
		result.sign=1;
	}
	if (_op1.sign==0 && _op2.sign==0 && xcompare(xabs(_op1),xabs(_op2))>=0) {
		v_sub(result.value,_op1.value,_op2.value,MAX_DIGITS);
		result.sign=0;
	}
	if (_op1.sign==1 && _op2.sign==0 && xcompare(xabs(_op1),xabs(_op2))<=0) {
		v_add(result.value,_op2.value,_op1.value,MAX_DIGITS);
		result.sign=1;
	}
	if (_op1.sign==1 && _op2.sign==0 &&  xcompare(xabs(_op1),xabs(_op2))>0  ) {
		v_add(result.value,_op2.value,_op1.value,MAX_DIGITS);
		result.sign=1;
	}
	if (_op1.sign==0 && _op2.sign==1 && xcompare(xabs(_op1),xabs(_op2))<0 ) {
		v_add(result.value,_op2.value,_op1.value,MAX_DIGITS);
		result.sign=0;
	}
	if (_op1.sign==0 && _op2.sign==1 && xcompare(xabs(_op1),xabs(_op2))>=0) {
		v_add(result.value,_op1.value,_op2.value,MAX_DIGITS);
		result.sign=0;
	}
	if (_op1.sign==1 && _op2.sign==1 &&xcompare(xabs(_op1),xabs(_op2))<=0) {
		v_sub(result.value,_op2.value,_op1.value,MAX_DIGITS);
		result.sign=0;
	}
	if (_op1.sign==1 && _op2.sign==1 && xcompare(xabs(_op1),xabs(_op2))>0) {
		v_sub(result.value,_op1.value,_op2.value,MAX_DIGITS);
		result.sign=1;
	}
}

void xrmul(xint &result, const xint &op1, const xint &op2) {
	v_rmul(result.value,op1.value,op2.value,MAX_DIGITS);
	if (op1.sign!=op2.sign) result.sign=NEG;
	if (op1.sign==NEG && op2.sign==NEG) result.sign=POS;
}

void xcdiv(xint &result, const xint &op1, const xint &op2) {
	v_cdiv(result.value,op1.value,op2.value,MAX_DIGITS);
	if (op1.sign!=op2.sign) result.sign=NEG;
	if (op1.sign==NEG && op2.sign==NEG) result.sign=POS;
}

void xcmod(xint &result, const xint &op1, const xint &op2) {
	v_cmod(result.value,op1.value,op2.value,MAX_DIGITS);
	if ((op1.sign==NEG && op2.sign==POS) || (op1.sign==NEG && op2.sign==NEG)) result.sign=NEG;
	else result.sign=POS;
	if (xcompare(op1,op2)==0) result.sign=POS;
}
