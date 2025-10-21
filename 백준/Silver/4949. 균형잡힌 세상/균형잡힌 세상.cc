#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <queue>



using namespace std;

//백준 문제 4949 : 균형잡힌 세상 

string str;

void check(string  stack) {
	if (stack.length() == 0) {
		cout << "yes\n";
	}
	else cout << "no\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string bracket = "[]()";
	
	while (getline(cin, str)) {
		if (str == ".") {
			break;
		}

		string stack;
		for (char c : str) {
			
			// 1.  "."을 기준으로 스택 초기화 및 스택 체크
			if (c == '.') {
				check(stack);
				stack.clear();
			}
			// 2. 문장 별로 대괄호, 괄호를 찾아서 스택 쌓기
			if (bracket.find(c)!=string::npos) {
				stack.push_back(c);
			}

			// 3. 짝 맞으면 삭제
			if (stack.size() > 1) {
				if ((stack[stack.size() - 2] == '[' && stack[stack.size() - 1] == ']')
					|| (stack[stack.size() - 2] == '(' && stack[stack.size() - 1] == ')')) {
					stack.pop_back();
					stack.pop_back();
				}
			}
			
		}
	}

	
	

	
	return 0;

}


