#include <iostream>
#include <string.h>
using namespace std;

#define BOARD_SIZE 100
int cache[BOARD_SIZE][BOARD_SIZE];
int board[BOARD_SIZE][BOARD_SIZE];
int N;

bool dfs(int x, int y) {
	int boardXY = board[x][y];
	bool test=false;
	if (boardXY == 0) 
		return true;
	if ((x ==0 && y == 0) && (cache[boardXY][0] == 0 && cache[0][boardXY] == 0)) 
		return false;

	if (!test && y + boardXY < N && cache[x][y + boardXY] != 0)
		test = dfs(x, y + boardXY);
	if (!test && x + boardXY < N && cache[x + boardXY][y] != 0)
		test = dfs(x + boardXY, y);
	cache[x][y] = 0;
	if (test) return true;
	else return false;
}

int main() {
	int testCase, T;
	bool Answer;
	freopen("Text.txt", "r", stdin);
	cin >> testCase;

	for (T = 0; T < testCase; T++) {
		for (int i = 0; i < BOARD_SIZE; i++) {
			memset(cache[i], -1, sizeof(cache[i]));
			memset(board[i], -1, sizeof(board[i]));
		}
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> board[i][j];
		
		Answer = dfs(0, 0);
		if (Answer) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}