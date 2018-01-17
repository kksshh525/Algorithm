#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
using namespace std;

bool compare(const pair<pair<int, int>,int> &i, const pair<pair<int, int>,int> &j) {
	return i.second < j.second;
}

class MST {
public:
	MST() {
		cin >> N >> M;
		initGraph();
		//mst();
		dijkstra();
	}
	void initGraph() {
		int A, B, C;
		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;
			//v.push_back(make_pair(make_pair(A, B),C));
			G[A][B] = G[B][A] = C;
		}
	}
	/*void mst() {
		sort(v.begin(), v.end(), compare);
		int i,len = N - 2;
		cout << N - 1 << endl;
		for (i = 0; i < len; i++)
			cout << v[i].first.first << " " << v[i].first.second << endl;
		cout << v[i].first.first << " " << v[i].first.second;
	}*/
	void dijkstra() {
		visited.assign(N + 1, false);
		memset(D, 0xff, sizeof(D));
		queue<int> q;
		q.push(1);
		D[1] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			visited[cur] = true;
			for (int i = 1; i <= N; i++) {
				if (G[cur][i] && !visited[i]) {
					q.push(i);
					D[i] = min(D[i], D[cur] + G[cur][i]);
				}
			}
		}
	}
private:
	int N, M;
	//vector<pair<pair<int, int>,int>> v;
	unsigned int D[1001];
	int G[1001][1001] = { 0, };
	vector<bool> visited;
};

int main() {
	freopen("Text.txt", "r", stdin);
	new MST();
	return 0;
}