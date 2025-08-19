#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//백준 문제 9996 : 한국이 그리울 땐 서버에 접속하지
int n;
string patern, paternSplit[2];
string str[101];
bool res[101];


int main() {

	cin >> n;
	cin >> patern;
	
	int starNum = patern.find("*");

	paternSplit[0] = patern.substr(0,starNum);
	paternSplit[1] = patern.substr(starNum+1);

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		//반례 때문에 필요한 코드
		if (str[i].size() < paternSplit[0].size() + paternSplit[1].size()) res[i] = false;
		else {
			if (paternSplit[0] == str[i].substr(0, paternSplit[0].size())
				&& paternSplit[1] == str[i].substr(str[i].size() - paternSplit[1].size()))
				res[i] = true;
			else res[i] = false;
		}
		
	}

	for (int i = 0; i < n; i++) {
		if (res[i]) cout << "DA" << "\n";
		else cout << "NE" << "\n";
	}
	
	return 0;

	
}


	