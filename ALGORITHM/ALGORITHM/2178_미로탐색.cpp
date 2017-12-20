#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int A[101][101];
bool C[101][101];

int main() {
	freopen("Text.txt", "r", stdin);
	int D[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };		//RDLU
	int N, M, i, j, Answer = 0;
	cin >> N >> M;

	string str;
	getline(cin, str);
	for (i = 0; i < N; i++) {
		getline(cin, str);
		for (j = 0; j < M; j++) {
			A[i][j] = stoi(str.substr(j,1));
		}
	}

	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	C[0][0] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (i = 0; i < 4; i++) {
			int dx = cur.first + D[i][0];
			int dy = cur.second + D[i][1];
			if (dx>=0 && dx < N && dy>=0 && dy < M) {
				if (A[dx][dy] == 1 && !C[dx][dy]) {
					A[dx][dy] = A[cur.first][cur.second] + 1;
					q.push(make_pair(dx, dy));
				}
			}
		}
	}
	cout << A[N-1][M-1] << endl;
	return 0;
}