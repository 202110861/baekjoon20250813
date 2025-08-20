#include <iostream>
#include <algorithm>


using namespace std;

//백준 문제 2559 : 수열

int N, K;
int temp[100001];
int sum[100001];
int maxNum = -100004;

int main() {
	cin >> N >> K;

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

 	cout<<maxNum;
		
	return 0;

	
}


	