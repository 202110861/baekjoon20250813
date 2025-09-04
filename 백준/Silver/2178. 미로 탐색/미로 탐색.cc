#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <queue>


using namespace std;

//백준 문제 2178 : 미로 탐색
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int N, M, ny, nx;
int a[104][104];
int visited[100][100];


void bfs(pair<int,int>here) {
	queue<pair<int, int>> q;
	visited[here.first][here.second] = 1;
	q.push(here);
	while (q.size()) {
		pair<int, int>here = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = here.first + dy[i];
			nx = here.second + dx[i];
			if (ny < 0 || nx < 0 || ny > N || nx > M || a[ny][nx] == 0) continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = visited[here.first][here.second] + 1;
			q.push({ ny,nx });

		}
	}

	cout << visited[N][M];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		string str_num;
		cin >> str_num;
		for (int j = 1; j <= M; j++) {
			a[i][j] = str_num[j-1]-'0';
		}
	}

	bfs({1,1});


	return 0;
	
}
