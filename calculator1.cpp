#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
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
	void ignore(char c) {
		// c is token kind to look for

		// first check buffer
		if(full && c == buffer.kind) {
			full = false;
			return;
		}
		full = false;

		// now search input
		char ch = 0;
		while(cin >> ch)
			if(ch == c) return;
	}
private:
	bool full{false};
	Token buffer{'i'};
};

void Token_stream::putback(Token t) {
	buffer = t;
	full = true;
}

Token Token_stream::get() {
    if(full) {
        full = false;
        return buffer;
    }
	char ch;
	cin >> ch;
	switch(ch){
		case ';':
		case 'q':
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			return Token{ch};
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{'8', val};
		}
	}
}

Token_stream ts;
double expression();

double primary() {
	Token t = ts.get();
	switch (t.kind) {
        case '(': {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    	case number:
    		return t.value;
    	case '-':
    		return -primary();
    	case '+':
    		return primary();
    	default:
            error("primary expected");
	}
}
double term() {
    double left = primary();
    Token t = ts.get();
    while(true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/': {
                double d = primary();
                if (d == 0) error("divided by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%': {
                double d = primary();
                if (d == 0) error("divided by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
            ts.putback(t);
            return left;
        }
    }
}

double expression() {
	double left = term();
	Token t = ts.get();
	while(true) {
		switch(t.kind) {
			case '+':
			    left += term();
			    t = ts.get();
			    break;
			case '-':
			    left -= term();
			    t = ts.get();
			    break;
			default:
			    ts.putback(t);
			    return left;
		}
	}
}

void calculate() {
	while(cin) {
		try {
			cout << prompt;
			Token t = ts.get();
			// debug output
			// cout << "in calculate, got token: " << t.kind << " with val of " << t.value << '\n';
			while(t.kind == print) t = ts.get();
			if(t.kind == quit) return;
			ts.putback(t);
			cout << result << expression() << '\n';
		}
		catch(exception& e) {
			cerr << e.what() << '\n';
			// clean_up_mess();
		}
	}
}



int main(){
	Token_stream ts;
	try {
		calculate();
		// keep_window_open();
		return 0;
	}
	catch(...) {
		cerr << "unknown exception \n";
		return 2;
	}
}