#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>


using namespace std;

//백준 문제 3474 : 교수가 된 현우
int T, a[100000];


//강의 내용 참고
int check(long long num) {
	
	int count2 = 0, count5 = 0;
	int two = 2, five = 5;
	while (num >=two ) {
		
		count2 += num / two;
		two *= 2;
		
	}
	while (num >= five) {
		count5 += num / five;
		five *= 5;
	}

	if (count2 == count5) return count2;
	else if (count2 > count5) return count5;
	else return count2;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a[i];

	}
	for (int i = 0; i < T; i++) {
		

		cout << check(a[i]) << "\n";

 	}
	
	
	return 0;

}
