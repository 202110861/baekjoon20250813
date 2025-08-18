#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//백준 문제 11655 : ROT13

string s;

void ROT13(string str) {
	for (char c : str) {
		if (c >= 'a' && c <= 'z') {
			if (c + 13 > 'z') cout << char((c + 13) - 'z' + 'a'-1);
			else cout << char(c + 13);
		}
		else if (c >= 'A' && c <= 'Z') {
			if (c + 13 > 'Z') cout << char((c + 13) - 'Z' + 'A'-1);
			else cout << char(c + 13);
		}
		else cout << c;
	}
}

int main() {
	getline(cin, s);
	
	ROT13(s);
	
	return 0;

	
}


	