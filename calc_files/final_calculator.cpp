#include "std_lib_facilities.h"
#include "tokens.h"
#include "vars.h"
#include <math.h>

Token_stream ts;
double expression();
double statement();
double term();
double primary();
double expon();
double trig(string s);

double statement(){
    /*grammar recognized:
    Statement:
        Var "=" Expression
        Var ";"
        Expression
    */
    Token t = ts.get();
    if(t.kind == name) {
        Token var = t;
        // cout << "Got a var with name " << var.name << endl;
        t = ts.get();
        if(t.kind == '=') {
            double d = expression();
            set_value(var.name, d);
            return d;
        }
        else if(t.kind == print) {
            ts.putback(t);
            return get_value(var.name);
        }
        ts.putback(t);
        ts.putback(var);
        return expression();
    }
    ts.putback(t);
    return expression();
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


double term() {
    double left = expon();
    Token t = ts.get();
    while(true) {
        switch (t.kind) {
            case '*':
                left *= expon();
                t = ts.get();
                break;
            case '/': {
                double d = expon();
                if (d == 0) error("divided by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%': {
                double d = expon();
                if (d == 0) error("divided by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            case '^':
                left = pow(left, expon());
                t = ts.get();
                break;
            default:
            ts.putback(t);
            return left;
        }
    }
}

double expon() {
    double left = primary();
    Token t = ts.get();
    if (t.kind == power) {
        double d = primary();
        return pow(left, d);
    }
    else {
        ts.putback(t);
        return left;
    }
}

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
    	case name:
    	    return get_value(t.name);
    	default:
    	    string s(1, t.kind);
            error("primary expected; got " + s);
	}
}

double trig(string s) {
    if(s=="sin") return sin(statement());
	else if(s=="cos") return cos(statement());
	else if(s=="tan") return tan(statement());
	// arc
	else if(s=="acos") return acos(statement());
	else if(s=="asin") return asin(statement());
	else if(s=="atan") return atan(statement());
	// hyperbolic
	else if(s=="cosh") return cosh(statement());
	else if(s=="sinh") return sinh(statement());
	else if(s=="tanh") return tanh(statement());
	return 0.0;
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
			cout << setprecision(10) << result << statement() << '\n';
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