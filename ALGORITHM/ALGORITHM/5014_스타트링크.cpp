#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
bool visited[1000001];

void bfs(int F, int S, int G, int U, int D) {
	visited[S] = true;
	q.push(S);
	int cnt = 0;
	bool answer = true;
	while (q.size() != 0) {
		int cur = q.front();
		if (cur == G) break;
		if (cnt > F + 1) {
			answer = false;
			break;
		}

		q.pop();
		cnt++;
		if (cur + U <= F && !visited[cur + U]) {
			q.push(cur + U);
			visited[cur + U] = true;
		}
		if (cur + D >= 1 && !visited[cur + D]) {
			q.push(cur + D);
			visited[cur + D] = true;
		}
	}
	if (answer)
		cout << cnt << endl;
	else
		cout << "use the stairs" << endl;
}

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	bfs(F, S, G, U, -D);

	return 0;
}