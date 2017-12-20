#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define INF 9999
#define CLOCK_SIZE 16
int Answer;
int sw[10][5] = { { 0,1,2,-1,-1 },{ 3,7,9,11,-1 },{ 4, 10, 14, 15,-1 },{ 0,4,5,6,7 },{ 6,7,8,10,12 } 
						,{ 0,2,14,15,-1 },{ 3,14,15,-1,-1 },{ 4,5,7,14,15 },{ 1,2,3,4,5 },{ 3,4,5,9,13 } };
int status[CLOCK_SIZE];
vector<int> path;

bool isComplete() {
	bool test = true;
	for (int i = 0; i < CLOCK_SIZE; i++) {
		if (status[i] != 12) {
			test = false;
			break;
		}
	}
	return test;
}
void pushButton(int swNum) {
	int clockNum, i;
	for (i = 0; i < 5; i++) {
		clockNum = sw[swNum][i];
		if (clockNum != -1) status[clockNum] += 3;
		if (status[clockNum] == 15) status[clockNum] = 3;
	}
}
void unDo(int swNum) {
	int clockNum, i;
	for (i = 0; i < 5; i++) {
		clockNum = sw[swNum][i];
		if (clockNum != -1) status[clockNum] -= 3;
		if (status[clockNum] == 0) status[clockNum] = 12;
	}
}

void dfs(int swNum) {
	int tmp = 0;
	if (path.size() == 10) {
		if(isComplete()){
			for (int i = 0; i < 10; i++)
				tmp += path[i];
			if (Answer > tmp) Answer = tmp;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		path.push_back(i);
		for(int j=0;j<i;j++)
			pushButton(swNum);
		dfs(swNum+1);
		path.pop_back();
		for (int j = 0; j<i; j++)
			unDo(swNum);
	}
}

int main(int argc, char** argv)
{
	int T, test_case, N;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = INF;
		memset(status, 0, sizeof(int) * 16);
		for (int i = 0; i < CLOCK_SIZE; i++) 
			cin >> status[i];
		dfs(0);
		if (Answer == INF) Answer = -1;
		cout << Answer << endl;
	}

	return 0;
}