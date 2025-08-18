#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

//백준 문제 1159 : 농구경기

string s[152];
map<char, int> player;
int num;


int main() {
	int count = 0;

	cin >> num;


	for (int i = 0; i < num; i++) {
		cin >> s[i];
		player[s[i][0]]++;
		
	}
	

	for (auto &m : player) {
		if (m.second > 4) {
			count++;
			cout << m.first;
		}
	}
	if (count == 0) cout << "PREDAJA";

	
	
	return 0;

	
}


	