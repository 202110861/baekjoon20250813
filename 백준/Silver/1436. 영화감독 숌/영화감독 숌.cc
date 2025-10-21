#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <queue>



using namespace std;

//백준 문제 1436 : 영화감독 숌
// 나중에 다시 풀어보자~

int N;

/*
N번째로 작은 666이 들어간 수
0666 1666 2666 3666 4666 5666
6660 6661 6662 6663 6664 6665 6666 6667 6668 6669
7666 8666 9666
10666 11666 12666 13666 14666 15666
16660 16661 16662 16663 16664 16665 16666 16667 16668 16669
17666 18666 19666 ...
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int i = 666;

	for (; ; i++) {
		if (to_string(i).find("666") != string::npos) N--;
		if (N == 0) break;
	}

	cout << i;

	
	return 0;

}


