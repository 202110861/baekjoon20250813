#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>


using namespace std;

//백준 문제 3986 : 좋은 단어
int N;
string str[100];

int check(string str[]) {
	int count = 0;
	string stack;
	
	for (int i = 0; i < N; i++) {
		stack.clear();
		for (char c : str[i]) {
			stack.push_back(c);
			if (stack.size() == 1) continue;
			if(stack[stack.size()-2]==stack[stack.size()-1]){
				stack.pop_back();
				stack.pop_back();
			}
			
		}
		if (stack.size() == 0) count++;
	}

	return count;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	
	cout << check(str);
	
	return 0;
	
}


	