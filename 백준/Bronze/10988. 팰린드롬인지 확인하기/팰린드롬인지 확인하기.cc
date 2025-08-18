#include <iostream>
#include <algorithm>

using namespace std;

//백준 문제 10988 : 팰린드롬인지 확인하기 

string s, temp;


int main() {
	cin >> s;
	temp = s;
	reverse(temp.begin(), temp.end());
	if (temp == s) cout << 1 << "\n";
	else cout << 0<<"\n";

	return 0;

	
}


	