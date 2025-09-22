#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
#include <cstring>


using namespace std;

//백준 문제 2910 : 빈도 정렬 (다시 풀어보기!!)

int N, C, num;
map<int,int> m, mp_first;
vector<pair<int,int>> v;
vector<int> v2;

//강의 참고
bool cmp(pair<int, int> a, pair<int, int> b) {
	//횟수 같으면 먼저 나온순
	if (a.first == b.first) {
		return mp_first[a.second] < mp_first[b.second];
	}
	//빈도 큰 순
	return a.first > b.first;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> num;
		m[num]++;
		if(mp_first[num]==0) mp_first[num]=i+1;
	
	}

	for (auto it : m) {
		v.push_back({ it.second, it.first });
	}
	sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}
	
	
	
	
	
	return 0;

}
