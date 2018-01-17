#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

class Maze {
private:
	int N, M;
	int mazeBoard[101][101] = { 0, };
	bool cache[101][101] = { false, };
	int offset[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };		//RDLU
public:
	Maze(int N, int M){
		this->N = N;
		this->M = M;
		string str;
		getline(cin, str);
		for (int i = 0; i < N; i++) {
			getline(cin, str);
			for (int j = 0; j < M; j++) {
				mazeBoard[i][j] = stoi(str.substr(j, 1));
			}
		}
		cout << bfs() << endl;
	}
	int bfs(void) {
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));

		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			cache[cur.first][cur.second] = true;
			for (int i = 0; i < 4; i++) {
				int dx = cur.first + offset[i][0];
				int dy = cur.second + offset[i][1];
				if (cache[dx][dy]) continue;
				if (mazeBoard[dx][dy] == 1 && (dx >= 0 && dx < N) && (dy >= 0 && dy < M)) {
					q.push(make_pair(dx, dy));
					mazeBoard[dx][dy] = mazeBoard[cur.first][cur.second] + 1;
				}
			}
		}
		return mazeBoard[N - 1][M - 1];
	}
};

int main(void) {
	freopen("Text.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	new Maze(N, M);
	return 0;
}
