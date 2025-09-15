#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>


using namespace std;

//백준 문제 2583 : 영역 구하기
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int M,N,K, ny, nx;
int a[104][104];
int visited[100][100];


// 강의 참고
// 가중치 그래프는 bfs만 사용해야하는 줄
int dfs(int y, int x) {
	visited[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny<0 || nx<0 || ny>=M || nx>=N || visited[ny][nx] == 1)continue;
		if (a[ny][nx] == 1)continue;
		ret += dfs(ny, nx);

	}
	return ret;
}


int bfs(int y, int x) {
	int size = 1;
	pair<int, int> here;
	here.first = y;
	here.second = x;
	queue<pair<int,int>> q;
	q.push(here);
	visited[y][x] = 1;
	while (!q.empty()) {
		here = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = here.first + dy[i];
			nx = here.second + dx[i];
			if (ny<0 || nx < 0 || ny >= M || nx >= N || a[ny][nx] == 1) continue;
			if (visited[ny][nx]) continue;
			size++;
			visited[ny][nx]=1;
			q.push({ ny,nx });
		}
	}

	return size;
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	vector<int> v;

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		pair<int, int> str, end;
		cin >> str.second >> str.first >> end.second >> end.first;
		for (int b = str.second; b < end.second; b++) {
			for (int c = str.first; c < end.first; c++) {
				a[b][c] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 0 && visited[i][j] == 0) {
				v.push_back(bfs(i, j));
			}
		}
	}

	
	sort(v.begin(), v.end());
	cout << v.size()<< "\n";
	for (int x : v) {
		cout << x << " ";
	}

	
	return 0;

}
