#include "std_lib_facilities.h"

int main() {
    double a = 0.5;
    cout << "initial value (double): " << a << "\n";
    int b = a;
    cout << "resulting value (integer): " << b << "\n";
    char c = a;
    cout << "resulting value (character): " << c << "\n";
    bool d = a;
    cout << "resulting value (bool): " << d << "\n";
    int e = 11;
    cout << "initial value (integer): " << e << "\n";
    char f = e;
    cout << "resulting value (character): " << f << "\n";
    bool g = e;
    cout << "resulting value (bool): " << g << "\n";
    char h = 'a';
    cout << "initial value (character): " << h << "\n";
    bool i = h;
    cout << "resulting value (bool): " << i << "\n";
}
