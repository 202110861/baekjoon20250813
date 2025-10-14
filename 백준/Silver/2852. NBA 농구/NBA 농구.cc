#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>



using namespace std;

//백준 문제 2852 : NBA 농구

int N, teamNum;
int scoreA = 0, scoreB = 0;
string m, prevTime="00:00";
pair<int, int> resA, resB;


void check(string prevTime, string m, pair<int, int> &res) {
	int min= stoi(m.substr(0, 2));
	int sec = stoi(m.substr(3, 2));


	res.first += min - stoi(prevTime.substr(0, 2));
	res.second += sec - stoi(prevTime.substr(3, 2));

}

string change(int num) {
	if (num == 0) return "00";
	if (num < 10) {
		string str = "0" + to_string(num) ;
		return str;
	}
	else return to_string(num);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> teamNum >> m;

		
		if (scoreA > scoreB) check(prevTime, m, resA); 			
		else if (scoreA < scoreB)  check(prevTime, m, resB);

		teamNum == 1 ? scoreA++ : scoreB++;
		
		prevTime = m;

	}

	if (scoreA > scoreB) check(prevTime,"48:00", resA); 
	else if (scoreA < scoreB)  check(prevTime,"48:00", resB); 


	if (resA.second >= 60) {
		int second = resA.second % 60;
		int minute = resA.second / 60;
		resA.first += minute;
		resA.second = second;
	}
	else if (resA.second < 0) {
		int second = resA.first * 60 + resA.second;
		int minute = second / 60;
		second = second % 60;
		
		resA.first = minute;
		resA.second = second;
	}
	if (resB.second >= 60) {
		int second = resB.second % 60;
		int minute = resB.second / 60;
		resB.first += minute;
		resB.second = second;
	}
	else if (resB.second < 0) {
		int second = resB.first * 60 + resB.second;
		int minute = second / 60;
		second = second % 60;

		resB.first = minute;
		resB.second = second;
	}

	cout << change(resA.first) << ":" << change(resA.second) << "\n";
	cout << change(resB.first) << ":" << change(resB.second) << "\n";
	
	return 0;

}
