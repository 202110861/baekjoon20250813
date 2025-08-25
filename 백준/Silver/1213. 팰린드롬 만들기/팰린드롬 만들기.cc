#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>


using namespace std;

//백준 문제 1213: 팰린드롬 만들기


//순서 바꿔서 팰린드롬 만들기
string palindrom(string name) {
	string str;
	char mid;
	int count = 0;;
	size_t len= name.size();
	map <char, int> cnt;


	//문자 수 체크
	for (char c: name) {
		cnt[c]++;
	}
	for (int i = 'A'; i <='Z';i++) {
		//홀수 체크는 조건에 & 1 추가해도 가능
		// cnt[c] & 1
		if (cnt[char(i)] % 2 == 1) count++;
	}

	// 홀수 문자가 2개 이상이면 불가능
	if(count>=2) return "I'm Sorry Hansoo";


	// mid를 정하고 왼쪽, 오른쪽에 붙이기 (원래 문자열 순서는 상관 없음)
	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i]) {
			if (cnt[i] & 1) {
				mid = char(i);
				cnt[i]--;
			}
			for (int j = 0; j < cnt[i]; j += 2) {
				str = char(i) + str;
				str += char(i);
			}
		}
	}

	if (isalpha(mid)) str.insert(str.begin() + str.size() / 2, mid);

	return str;

	

	//내가 쓴 코드
	/*
	for (int i = 0; i < len/2; i++) {
		if (name[i] != name[len-i-1]) {
			auto it = find(name.begin()+i+1, name.end(), name[i]);
			if (it != name.end()) idx = distance(name.begin(), it);
			swap(name[len - i - 1], name[idx]);
		}

	}
	str = name;


	reverse(str.begin(), str.end());
	if (str== name) return str;
	else return "I'm Sorry Hansoo";
	*/
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//영어이름 입력
	string name;
	cin >> name;

	//사전순으로 앞서는 것 출력. 없으면 "I'm Sorry Hansoo" 출력
	cout << palindrom(name);

	return 0;
	
}


	