#include <iostream>
#include <algorithm>

using namespace std;

//백준 문제 2979 : 트럭 주차

int price[3];
int t[100];
pair <int, int> a[3];
int sum = 0;
int n = 100;

int main() {
	cin >> price[0] >> price[1] >> price[2];
	for (int i = 0; i < 3; i++) {
		cin >> a[i].first >> a[i].second;
	}
	
	
	for (int i = 0; i < 3; i++) {
		for (int j = a[i].first; j < a[i].second; j++) {
			t[j]++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (t[i] == 1) {
			sum += price[0];
		}
		else if (t[i] == 2) {
			sum +=  price[1] * 2;
		}
		else if (t[i] == 3) {
			sum += price[2] * 3;
		}
	}
	

	
	cout << sum;
	
	return 0;

	
}
	