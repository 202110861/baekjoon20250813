#include <iostream>
#include <algorithm>

using namespace std;

//백준 문제 10988 : 팰린드롬인지 확인하기 

string s;
int res;

int palindrome(string str) {
	int num = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			num = 0; 
			break;
		}
		
	}
	return num;
}

int main() {
	cin >> s;
	res = palindrome(s);
	cout << res;
	return 0;
}


	