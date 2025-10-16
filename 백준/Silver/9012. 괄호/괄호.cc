#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <queue>



using namespace std;

//백준 문제 9012 : 괄호
int N;
string PS;


void check(string str) {
	vector<char> str_v;
	

	for (char c : str) {
		str_v.push_back(c);
		if (str_v.size() > 1) {
			if (str_v[str_v.size()-2]=='('&& str_v[str_v.size()-1] == ')') {
				str_v.pop_back();
				str_v.pop_back();
			}
		}		 
	}

	if (str_v.size() == 0) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> PS;
		check(PS);
	}

	
	return 0;

}


