#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

//백준 문제 10808 : 알파벳 개수

char s[101];
map <char, int> m;


int main() {
	cin >> s;
	for (int i = 0; i < 26; ++i) m['a' + i] = 0;

	for (char c : s) {
		m[c]++;
	}

	for (int i = 0; i < 26; ++i) {
		cout << m['a'+i] << " ";
	}
}