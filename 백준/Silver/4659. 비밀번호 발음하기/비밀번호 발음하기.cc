#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
#include <cstring>


using namespace std;

//백준 문제 4659 : 비밀번호 발음하기


string str;

string vowel = "aeiou";
bool inVawel, isThree, isTwo;


void check(string str) {
	inVawel = true;
	isThree = true;
	isTwo = true;

	int count = 0;

	//모음 하나이상 포함하는지 체크
	for (char c : vowel) {
		auto it = find(str.begin(), str.end(), c);
		if (it != str.end()) count++;
	}

	if (!count) inVawel = false;
	
	if (str.size() > 2) {
		//모음 3개 연속으로 오는지 체크
		for (int i = 0; i < str.size() - 2; i++) {
			if (any_of(vowel.begin(), vowel.end(), [&](char v) {return str[i] == v; }) && 
				any_of(vowel.begin(), vowel.end(), [&](char v) {return str[i+1] == v; }) &&
					any_of(vowel.begin(), vowel.end(), [&](char v) {return str[i + 2] == v; }))
				isThree = false;
			else if(vowel.find(str[i])==string::npos &&
				vowel.find(str[i+1]) == string::npos &&
				vowel.find(str[i+2]) == string::npos)
				isThree = false;

		}
		//자음 3개 연속으로 오는지 체크

		//같은글자 연속으로 두번 오는지 체크 (ee, oo 예외)
		for (int i = 0; i < str.size() - 1; i++) {
			if (str[i] == str[i + 1]) {
				if (str[i] != 'e' && str[i] != 'o') {
					isTwo = false;
				}
			}
		}
	}
	else if(str.size()==2){
		if (str[0] == str[1]) {
			if (str[0] != 'e' && str[0] != 'o') {
				isTwo = false;
			}
		}
	}
	
	


	if (inVawel && isThree && isTwo) {
		cout << "<" << str << "> is acceptable.\n";
	}
	else {
		cout << "<" << str << "> is not acceptable.\n";
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> str;
		if (str == "end") break;

		check(str);

	}
	
	
	return 0;

}
