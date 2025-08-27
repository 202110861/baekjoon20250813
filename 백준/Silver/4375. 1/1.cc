#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>


using namespace std;

//백준 문제 4375 : 1

int num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	//첫번째 코드
	/*
	while (check) {
		string str = to_string(num * i);
		int count = 0;
		for (char c : str) {
			if (c == '1') count++;
			else {
				i++;
				break;
			}
		}
		if (count == str.size()) { 
			check = false;
			cout << count << "\n"; 
		}
	}
	*/

	//두번째 코드  (시간초과 뜸)
	/*
	while (check) {

		if (i % num == 0) {
			check = false;
			cout << to_string(i).size();
		}
		else i = i * 10 + 1;
	}
	*/

	//세번째 코드 (정수론의 모듈러 연산 - 강의 참고)
	
	while (cin >> num) {
		int count = 1;
		//bool check = true;
		long long i = 1;

		while (true) {

			if (i % num == 0) {
				//check = false;
				cout << count << "\n";
				break;
			}
			else {
				count++;
				i = (i * 10 + 1) % num;
			}
		}

	}

	
	return 0;
	
}


	