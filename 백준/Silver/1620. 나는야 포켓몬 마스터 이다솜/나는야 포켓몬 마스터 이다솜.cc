#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>


using namespace std;

//백준 문제 1620 : 나는야 포켓몬 마스터 이다솜

int M, N;
vector<string> pkm(100001);
map <string, int> pkmNum;
string name;
string problem[100001];
int num = 0;
string resNum;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M >> N;
	
	for (int i = 1; i <= M; i++) {
		cin >> name;
		pkm[i]= name;
		pkmNum[name] = i;
		
	}

	if (N < 1 || N>100000) return 0;
	if (M < 1 || M>100000) return 0;
	if (name.size() < 2 || name.size() > 20) return 0;


	for (int i = 1; i <= N; i++) {
		cin >> problem[i];	
	}

	for (int i = 1; i <= N; i++) {
		
		num = atoi(problem[i].c_str());
		
		if (num == 0) cout << pkmNum[problem[i]] << "\n";
		else {
			//num = stoi(resNum);
			cout << pkm[num]<<"\n";
		}
	}
	
		
	return 0;

	
}


	