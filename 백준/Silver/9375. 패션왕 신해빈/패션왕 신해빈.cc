#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>


using namespace std;

//백준 문제 9375 : 패션왕 신해빈

int testCase, N;
long long res;
string clothName, clothSort[32];
map<string, int> clothes;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {

		//변수, 배열 초기화
		res = 1;
		clothSort->clear();
		clothes.clear();

		//의상 수 N 입력
		cin >> N;

		//의상 종류별로 카운트
		for (int j = 0; j < N; j++) {
			cin >> clothName >> clothSort[j];
			clothes[clothSort[j]]++;
		}
		

		//경우의수 계산
		for (auto str : clothes) {
			res *= (long long)str.second + 1;
		}

		res--;
		
		
		cout << res<<"\n";

	}
	
	
		
	return 0;

	
}


	