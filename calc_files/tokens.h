#include "std_lib_facilities.h"

const char invalid = 'i';
const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';
const char power = '^';
const string prompt = "> ";
const string result = "= ";

class Token{
public:
	char kind;
	double value;
	string name;
	Token(char ch) :kind{ch} {}
	Token(char ch, double val) :kind{ch}, value{val} {}
	Token(char ch, string n) :kind{ch}, name{n} {}
};
class Token_stream {
public:
	Token get();
	void putback(Token t);
	Token popback();
	void ignore(char c) {
		while (buffer.size() > 0) {
		    Token t = popback();
		    if (t.kind == c) return;
		}
	    char ch = 0;
	    while (cin>>ch)
	        if (ch == c) return;
	}
private:
	vector<Token> buffer;
};
