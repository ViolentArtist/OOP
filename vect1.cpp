#include "std_lib_facilities.h"

class vect {
	int sz;
	double* elem;
public:
	vect(int s)
		:sz{s}, elem{new double [s]} {/* */}
	~vect()
		{ delete[] elem; }
	double& operator[] (int i) { return elem[i]; }
	void set (int i, double d) { elem[i] = d; }
};

void f(int n) {
	vect v(n);
	v[2] = 2.2;
	vect v2 = v;
	v[1] = 9.9;
	v[0] = 8.8;
	cout << v[0] << ' ' << v2[1];
}

int main() {
	while (true)
		f(10);
	return 0;
}
