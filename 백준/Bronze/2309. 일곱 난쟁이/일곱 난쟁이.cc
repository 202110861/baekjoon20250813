#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//백준 문제 2039 : 일곱난쟁이

int a[9];
int sum = 0;
pair<int, int> ret;
vector<int> v;

void input() {
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
}
void print() {
	for (int i : v) cout << i << "\n";
}

void select() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			if (sum - a[i] - a[j] == 100) {
				ret = { i,j };
				return;
			}
		}
	}
}



int main() {
	input();
	select();
	for (int i = 0; i < 9; i++) {
		if (i == ret.first || i == ret.second) continue;
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	print();
}