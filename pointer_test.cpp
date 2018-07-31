#include "std_lib_facilities.h"

int main() {
	char c = 'd';
	int i = 11;
	double d = 4.2;

	char* cp = &c;
	int* ip = &i;
	double* dp = &d;

	cout << "cp = " << cp << " and its value is: " << *cp <<  '\n';
	cout << "size of c is: " << sizeof(c) << " and size of cp is: " << sizeof(cp) << '\n';
	cout << "ip = " << ip << " and its value is: " << *ip <<  '\n';
	cout << "size of i is: " << sizeof(i) << " and size of ip is: " << sizeof(ip) << '\n';
	cout << "dp = " << dp << " and its value is: " << *dp <<  '\n';
	cout << "size of d is: " << sizeof(d) << " and size of dp is: " << sizeof(dp) << '\n';
}
