#include "std_lib_facilities.h"

// 1) The Token class definition from pg. 183 of the text.
// 2) A Token vector.
// 3) A get_token() function that returns the next token.
// 4) A main that uses 'for' (we used 'while' in class) loops getting tokens and pushing them on a vector until a 'q' (quit),
//    and then loops over the vector printing the contents.

class Token{
public:
	char kind;
	double val;
};

Token get_token();
vector<Token> tokens;

int main(){
	for ( Token t = get_token(); t.kind != 'q'; t = get_token() ){
		tokens.push_back(t);
	}
	for ( Token tok : tokens ){
		cout << "Token of kind: " << tok.kind << " with val " << tok.val << "\n";
	}
}

Token get_token(){
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



