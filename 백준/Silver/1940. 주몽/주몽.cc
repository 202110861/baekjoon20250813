#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>


using namespace std;

//백준 문제 1940: 주몽

int M, N;
int material[15000];

int check(int material[]) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i+1; j < N; j++) {
			sum = material[i] + material[j];
			if (sum == M) count++;
		}
	}
	return count;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> material[i];
	}

	cout << check(material);

	
	return 0;
	
}


	