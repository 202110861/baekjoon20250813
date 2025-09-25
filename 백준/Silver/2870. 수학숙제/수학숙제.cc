#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>


using namespace std;

//백준 문제 2870 : 수학숙제

int N;
vector<string> num_v;
string cnt_str, str[100];

void check() {
	//비어있는지 확인
	if (!cnt_str.empty()) {

		//0 1개만 있으면 
		if (cnt_str.size() == 1 && cnt_str[0] == '0') {
			cnt_str = "0";
		}
		else {
			auto it = find_if(cnt_str.begin(), cnt_str.end(), [](char c) {
				return c != '0';
				});
			
			cnt_str.erase(cnt_str.begin(), it);
		}
		//모든 수가 0이면 0 하나만!
		if (all_of(cnt_str.begin(), cnt_str.end(), [](char c) {
			return c == '0';
			})) cnt_str = "0";


		num_v.push_back(cnt_str);
		cnt_str = "";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;


	//현재 문제점 : 최대 100 글자의 숫자, 문자이므로 long long을 사용해도 100자리의 숫자를 담을 수 없음
	// 해결 방법 : string만 사용해서 정렬을 해야함..
	for (int i = 0; i < N; i++) {
		cin >> str[i];


		for (char c : str[i]) {

			//숫자인지 확인
			if (isdigit(c)) {
				cnt_str += c;
			}
			else {
				check();
			}
		}
		//마지막에 벡터 값이 비어있지 않으면
		check();
	}

	
	sort(num_v.begin(), num_v.end(), [](string& a, string& b) {
		if (a.size() != b.size()) return a.size() < b.size();
		return a < b;
		});

	for (string str : num_v) {
		cout << str << "\n";
	}
	
	return 0;

}
