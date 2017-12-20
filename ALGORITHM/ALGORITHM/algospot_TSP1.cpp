#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define INF 99999

int N;
double Answer, arrN[8][8];

vector<int> path;
vector<bool> visited;

void dfs() {
	double tmp = 0;
	//종료조건
	if (path.size() == N) {
		for (int i = 0; i < N - 1; i++) {
			tmp += arrN[path[i]][path[i + 1]];
		}
		if (Answer > tmp) Answer = tmp;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		path.push_back(i);
		visited[i] = true;
		dfs();
		path.pop_back();
		visited[i] = false;
	}
}

int main() {
	int testCase, T;
	freopen("Text.txt", "r", stdin);
	cin >> testCase;

	for (T = 0; T < testCase; T++) {
		Answer = INF;
		for(int i=0;i<8;i++)
			memset(arrN[i], 0, sizeof(int)*8);
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arrN[i][j];

		for (int i = 0; i < N; i++)
			visited.push_back(false);
		dfs();
		printf("%.10f\n", Answer);
	}

	return 0;
}