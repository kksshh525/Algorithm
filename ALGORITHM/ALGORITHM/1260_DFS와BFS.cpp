#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class DorBFS {
public:
	DorBFS(int N, int M) {
		this->N = N;
		this->M = M;
		cin >> V;
		initGraph();

		initDfs();
		dfs(V);
		int i, len = dfsPath.size() - 1;
		for (i = 0; i < len; i++)
			cout << dfsPath[i] << " ";
		cout << dfsPath[i] << endl;
		
		bfs(V);
	}
	void initGraph() {
		int x, y;
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			G[x][y] = G[y][x] = 1;
		}
	}
	void initDfs() {
		dfsCheck.assign(N + 1, false);
		dfsPath.push_back(V);
		dfsCheck[V] = true;
	}
	void dfs(int v) {
		for (int i = 1; i <= N; i++) {
			if (dfsCheck[i] || !G[v][i]) continue;
			dfsCheck[i] = true;
			dfsPath.push_back(i);
			dfs(i);
		}
	}
	void bfs(int v) {
		vector<bool> bfsCheck;
		vector<int> bfsPath;
		queue<int> q;

		bfsCheck.assign(N + 1, false);
		q.push(v);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (!bfsCheck[cur]) bfsPath.push_back(cur);
			bfsCheck[cur] = true;
			for (int i = 1; i <= N; i++) {
				if (!G[cur][i] || bfsCheck[i]) continue;
				q.push(i);
			}
		}
		int i, len = bfsPath.size() - 1;
		for (i = 0; i < len; i++)
			cout << bfsPath[i] << " ";
		cout << bfsPath[i];
	}
private:
	int N, M, V;
	int G[1001][1001] = { 0, };
	vector<bool> dfsCheck;
	vector<int> dfsPath;
};

int main() {
	freopen("Text.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	new DorBFS(N, M);
	return 0;
}