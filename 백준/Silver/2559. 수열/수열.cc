#include <bits/stdc++.h>

using namespace std;

//백준 문제 2559 : 수열

int N, K;
int temp[100001];
int sum[100001];
int maxNum = -100004;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	/* 내가 한 방법 */
	/*
	for (int i = 0; i < N; i++) cin >> temp[i];
	for (int i = 0; i < N; i++){
		if (i + K <= N) {
			for (int j = i; j < i + K; j++) {
				sum[i] += temp[j];
			}
		}
		else break;
		
		if (sum[i] > maxNum) maxNum = sum[i];
		
	}

	*/

	/* 강의 방법 */
	for (int i = 1; i <=N; i++) {
		cin >> temp[i];
		sum[i] = sum[i - 1] + temp[i];
	}
	for (int i = K; i <= N; i++) {
		maxNum = max(maxNum, sum[i] - sum[i - K]);
	}
	

 	cout<<maxNum;
		
	return 0;

	
}


	