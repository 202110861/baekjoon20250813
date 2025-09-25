#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>


using namespace std;

//백준 문제 10709 : 가상캐스터
int H, W;
char a[100][100];
int res[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < H; i++) {
		bool hasC = false;
		int minute;
		for (int j = 0; j < W; j++) {

			//c 없으면 -1
			if (!hasC)res[i][j] = -1;
			//c 있으면 0
			if (a[i][j] == 'c') {
				hasC = true;
				minute = 0;
				res[i][j] = minute;
				
			}
			//c 다음칸에 minute 반영
			else if (hasC){
				minute++;
				res[i][j] = minute;
			}
				
			
		}

	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;

}
