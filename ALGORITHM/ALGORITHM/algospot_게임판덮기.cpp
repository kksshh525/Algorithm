#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int Answer, H, W, N;
int board[20][20];
int block[4][3][2] = { { { 0 , 0 } , { 0 , 1 } , { 1 , 0 } },
								{ { 0 , 0 } , { 0 , 1 } , { 1 , 1 } },
								{ { 0 , 0 } , { 1 , 0 } , { 1 , -1 } },
								{ { 0 , 0 } , { 1 , 0 } , { 1 , 1 } } };


void dfs(int x, int y, int curCount) {
	//기저사례
	if (curCount == N) {
		Answer++;
		return;
	}
	vector<int> check;		//이전에 표시한 블록의 위치를 저장
	int i,j, k,dx, dy, cnt = 0;
	for (i = 0; i < 4; i++) {
		//블록놓기
		for (j = 0; j < 3; j++) {
			dx = x + block[i][j][0];
			dy = y + block[i][j][1];
			if (board[dx][dy] == 1) {
				board[dx][dy] = 0;			//checking
				check.push_back(j);
			}
		}
		//블록을 놓을 수 있으면 다음 재귀
		if (check.size() == 3) {
			//다음 흰 칸 찾기
			for (k = x; k < H; k++) {
				for (j = 0; j < W; j++) {
					if (board[k][j] == 1) break;
				}
				if (board[k][j] == 1) break;
			}
			dfs(k, j, curCount + 1);
		}
		//체크한 블록 다시 지우기
		for (; check.size() != 0 ;) {
			cnt = check[check.size() - 1];
			check.pop_back();
			dx = x + block[i][cnt][0];
			dy = y + block[i][cnt][1];
			if(board[dx][dy] == 0)
				board[dx][dy] = 1;		//unchecking
		}
		cnt = 0;
	}
}

int main() {
	int testCase, T, cnt, i, j;
	char c;

	freopen("Text.txt", "r", stdin);
	cin >> testCase;

	for (T = 0; T < testCase; T++) {
		Answer = cnt = N = 0;
		for(i=0; i<20;i++)
			memset(board[i], -1, sizeof(int) * 20);
		
		cin >> H >> W;
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				cin >> c;
				if (c == '.') {
					board[i][j] = 1;
					cnt++;
				}
			}
		}
		N = cnt / 3;
		//3의 배수가 아닌경우 불가능
		if (cnt % 3 != 0) Answer = 0;
		else {
			//처음의 흰 칸 찾기
			for (i = 0; i < H; i++) {
				for (j = 0; j < W; j++) {
					if (board[i][j] == 1) break;
				}
				if (board[i][j] == 1) break;
			}
			dfs(i, j, 0);
		}

		cout << Answer << endl;
	}

	return 0;
}