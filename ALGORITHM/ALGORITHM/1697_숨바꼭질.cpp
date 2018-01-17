#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class HideAndSeek {
public:
	HideAndSeek() {
		cin >> N >> M;
		bfs();
	}
	void bfs() {
		queue<int> q;
		//vector<bool> visited(100001,false);
		bool visited[100001] = { false, };
		q.push(N);
		int ans = 0;
		while (!q.empty()) {
			int qSize = q.size();
			while (qSize--) {
				int cur = q.front(); q.pop();
				if (cur == M) break;
				visited[cur] = true;
				int curSubOne = cur - 1;
				int curAddOne = cur + 1;
				int curMulTwo = cur + cur;
				if (curSubOne >= 0 && !visited[curSubOne])
					q.push(curSubOne);
				if (curAddOne <= 100000 && !visited[curAddOne])
					q.push(curAddOne);
				if (curMulTwo <= 100000 && !visited[curMulTwo])
					q.push(curMulTwo);
			}
			if (qSize >= 0) break;
			ans++;
		}
		cout << ans << endl;
	}
private:
	int N, M;
};

int main() {
	freopen("Text.txt", "r", stdin);
	new HideAndSeek();
	return 0;
}