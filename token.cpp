#include "std_lib_facilities.h"

class Token{
public:
	char kind;
	double val;
};

Token get_token();
vector<Token> tokens;

int main(){
	Token t = get_token();
	while ( t.kind != 'q'){
		tokens.push_back(t);
		t = get_token();
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
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token{'8', val};
		}
	}
}
