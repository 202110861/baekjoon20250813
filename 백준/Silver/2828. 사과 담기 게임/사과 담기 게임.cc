#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>


using namespace std;

//백준 문제 2828 : 사과 담기 게임
int N, M, J;
int a[20];
bool check[20];

//강의보기 전 내 코드 (Stack overflow)
int app(int x) {
	int count=1;
	if (check[J - 1]) return count;
	for (int i = 0; i < J; i++) {
		if (x + M > a[i] && x <= a[i]) {
			check[i] = true;
			continue;
		}
		else if (x + M < a[i]) count = count + app(x + M);
		else if(x+M > a[i]) count = count + app(x - M);
	}
	return count;
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> J;

	int start = 1, end;
	int count=0;

	//강의 코드 (나중에 다시 풀어보자~)
	for (int i = 0; i < J; i++) {
		end = start + M - 1;
		cin >> a[i];
		if (start <= a[i] && end >= a[i]) continue;
		else {
			if (start > a[i]) {
				count += (start - a[i]);
				start = a[i];
			}
			else {
				count += (a[i] - end);
				start += (a[i] - end);
			}

		}

	}
	cout << count;
	
	
	return 0;

}
