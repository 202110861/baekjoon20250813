#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <queue>
#include <cstring>


using namespace std;

//백준 문제 2468 : 안전영역
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int N, ny, nx;
int a[104][104];
int visited[100][100];


void dfs(int y, int x, int h) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx<0 || ny> N || nx > N ) continue;
		if (a[ny][nx] > h && visited[ny][nx] == 0) dfs(ny, nx,h);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	int max = 0;
	int max_count=0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (max < a[i][j]) max = a[i][j];
		}
	}


	for(int h=0; h<=max; h++){
		memset(visited, 0, sizeof(visited));
		count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (a[i][j] > h && visited[i][j] == 0) {
					count++;
					dfs(i, j, h);
				}
			}
		}
		if (max_count < count) max_count = count;

	}
	cout << max_count;

	return 0;

}
