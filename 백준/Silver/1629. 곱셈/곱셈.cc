#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>


using namespace std;

//백준 문제 1629 : 곱셈

long long A, B, C;
long long res = 1;



// 세번째 코드 (강의 참고)
long long remainder(long long A, long long B) {
	
	if (B == 1) return A % C;
	
	res = remainder(A, B / 2);

	//res = (long long)pow(res, 2) % C;
	res = (res * res) % C;

	if (B % 2) res = (res * A) % C;
	
	return res;

}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B >> C;

	//첫번째 코드 (너무 커짐)
	//res = (long long)pow(A, B) % C;

	
	//두번째 코드 (B가 20억이라면 for문으로 하면 시간복잡도가 20억이 됨으로 시간초과)
	//for (int i = 0; i < B; i++) {
	//	res = (res *A) % C;
	//}


	cout << remainder(A,B);
	
	return 0;
	
}


	