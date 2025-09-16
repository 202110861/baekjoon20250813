#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>


using namespace std;

//백준 문제 1992 : 쿼드트리
vector<int> a[64];
int N,ny,nx;

// 강의 보기 전 코드
void quad(int N, int y, int x) {
	bool hasOne = false;
	bool hasZero = false;
	for (int i = y; i < y+N; i++) {
		for (int j = x; j < x+N; j++) {
			if (a[i][j] == 0) hasZero = true;
			else hasOne = true;
		}
	}
	if (hasZero && hasOne) {
		cout << "(";
		quad(N / 2, y, x);
		quad(N / 2, y, x+N/2);
		quad(N / 2, y+N/2, x);
		quad(N / 2, y+N/2, x+N/2);
		cout << ")";
	}
	else if (hasZero) cout << "0";
	else if (hasOne) cout << "1";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (char c : str) {
			a[i].push_back(c-'0');
		}
	}
	
	quad(N, 0, 0);
	

	
	return 0;

}
