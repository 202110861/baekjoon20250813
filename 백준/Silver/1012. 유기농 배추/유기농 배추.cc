#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <queue>
#include <cstring>


using namespace std;

//백준 문제 1012 : 유기농 배추
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int T, N, M, K, ny, nx, n1, n2;
int a[104][104];
int visited[100][100];


void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (a[ny][nx] == 1 && visited[ny][nx] == 0) dfs(ny, nx);
		
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		int count = 0;
		memset(visited, 0, sizeof(visited));
		memset(a, 0, sizeof(a));

		cin >> N >> M >> K;
		for (int j = 0; j < K; j++) {
			cin >> n1 >> n2;
			a[n1][n2] = 1;
		}
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] == 1 && visited[i][j]==0) {
					count++; dfs(i,j);
				}

			}
		}
		cout << count << "\n";
	}
	

	


	return 0;
	
}
