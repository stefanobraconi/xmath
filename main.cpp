#include <iostream>

#include "xmath.h"

using namespace std;

int main() {
	xint a(1237);
	xint b(345);
	xint c;
	xcmod(c,a,b);
	cout<<c.show()<<endl;
	cout<<1237%345;
	return 0;
}
