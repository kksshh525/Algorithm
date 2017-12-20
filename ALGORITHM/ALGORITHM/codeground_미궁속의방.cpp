#include <iostream>
#include <string.h>
using namespace std;

int N, K, Board[2][100000];
unsigned long long Answer;

void createWall(int n){
	int i;
	Board[0][0] = 1;
	Board[1][n-1] = n*n;
	for (i = 1; i < n; i++) {
		if (i % 2 == 1) Board[0][i] = Board[0][i - 1] + 1;
		else Board[0][i] = Board[0][i - 1] + i*2;
	}
	for (i = 0; i < n-1; i++) {
		if ((i % 2) == 1) Board[1][n - 2 - i] = Board[1][n - 1 - i] - 1;
		else Board[1][n - 2 - i] = Board[1][n - 1 - i] - (i + 1) * 2;
	}
}

int roomNum(int x, int y) {
	int xy = x + y;
	int index = (xy < N) ? 0 : 1;
	bool odd = (xy % 2 == 0) ? false : true;
	int add = (odd) ? 1 : -1;
	if (!index) 
		return Board[index][xy] + (add*x);
	else
		return Board[index][xy-N+1] + (add*(N-1-y));
}

int main(int argc, char** argv)
{
	int T, test_case,  x, y;
	char c;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 1;
		x = y = 0;
		memset(Board, 0, sizeof(Board));
		cin >> N >> K;
		
		createWall(N);
		for (int i = 0; i < K; i++) {
			cin >> c;
			switch (c) {
			case 'U':
				x--; break;
			case 'D':
				x++; break;
			case 'L':
				y--; break;
			case 'R':
				y++; break;
			}
			Answer += roomNum(x, y);
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}