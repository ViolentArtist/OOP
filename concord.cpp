#include "std_lib_facilities.h"

int main() {
	cout << "Enter a phrase: \n";
	vector<string> text;
	for (string temp; cin >> temp;){
		text.push_back(temp);
	}

	for (string s : text){
		cout << s << " ";
	}

	sort(text);
	int index = 0;
	string prev = text[index];
	int count = 0;
	while(index < text.size()){
		if(text[index] == prev){
			count++;
		}
		else{
			cout << prev << ": " << count << endl;
			prev = text[index];
			count = 1;
		}
		index++;
	}
	cout << prev << ": " << count << endl;

	keep_window_open();
	return 0;
}
