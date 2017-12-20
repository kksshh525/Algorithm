#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int C, N, M, Answer;
int arrM[10][10];
vector<bool> visited;
vector<int> path;

void dfs() {
	if (path.size() == N) {
		Answer++;
		return;
	}
	int cur;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			path.push_back(i);
			cur = i;
			break;
		}
	}
	for (int i = cur+1; i < N; i++) {
		if (!visited[i] && arrM[cur][i]) {
			visited[i] = true;
			path.push_back(i);
			dfs();
			path.pop_back();
			visited[i] = false;
		}
	}
	visited[cur] = false;
	path.pop_back();
	return;
}

int main()
{
	int C, T, tmp1, tmp2;
	freopen("Text.txt", "r", stdin);

	cin >> C;
	for (T = 0; T < C; T++) {
		for (int i = 0; i < 10; i++)
			memset(arrM[i], 0, sizeof(int) * 10);
		Answer = 0;
		cin >> N >> M;
		
		for (int i = 0; i < M; i++) {
			cin >> tmp1 >> tmp2;
			arrM[tmp1][tmp2] = arrM[tmp2][tmp1] = 1;
		}
		for(int i=0; i<N; i++)
			visited.push_back(false);
		dfs();

		//cout << "Case #" << T + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}