#include "std_lib_facilities.h"
#include "tokens.h"

void print_buffer(vector<Token> v) {
    cout << "v = ";
    for(Token t : v)
        cout << t.kind;
    cout << '\n';
}

void Token_stream::putback(Token t) {
	buffer.push_back(t);
//    print_buffer(buffer);
}

Token Token_stream::popback() {
    Token t = buffer.back();
    buffer.pop_back();
    return t;
}

Token Token_stream::get() {
    if(buffer.size() > 0) {
        Token t = popback();
        return t;
    }
	char ch;
	cin >> ch;
	switch(ch){
		case print:
		case quit:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		case power:
			return Token{ch};
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{number, val};
		}
		default:
		    if(isalpha(ch)) {
		        string s;
		        s +=ch;
		        while(cin.get(ch) && isalpha(ch)) s += ch;
		        cin.putback(ch);
		        return Token{name, s};
		    }
		    return Token{invalid, double(ch)};
	}
	return Token{quit};
}

/*int main() {
    vector<Token> tokens;
    Token_stream ts;

    for(Token t = ts.get(); t.kind != quit; t = ts.get()) {
    	tokens.push_back(t);
	}

	for(Token tok : tokens) {
        if(tok.kind == number)
		    cout << "A number token with val = " << tok.value << '\n';
        else if(tok.kind == invalid)
		    cout << "We received an invalid token of value "
                << char(tok.value) << '\n';
        else if(tok.kind == name)
		    cout << "A variable token with name " << tok.name << '\n';
        else
		    cout << "A token of kind " << tok.kind << '\n';
	}
    return 0;
}*/
