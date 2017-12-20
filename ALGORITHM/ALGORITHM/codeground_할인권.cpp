#include <iostream>
#include <string.h>
using namespace std;
#define INT_MAX 0x7fffffff

int Answer;
int arrM[101][101];

void floyd_warwhall(int n) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (arrM[i][k] == INT_MAX || arrM[k][j] == INT_MAX) continue;

				if (arrM[i][j] > arrM[i][k] + arrM[k][j])
					arrM[i][j] = arrM[i][k] + arrM[k][j];
			}
}

int main(int argc, char** argv)
{
	int T, test_case, N, M, K, i, A, B, C, P, S, E;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		for (i = 0; i < 101; i++)
			memset(arrM[i], 0, sizeof(int) * 101);
		
		cin >> N >> M >> K;
		
		for (i = 0; i < M; i++) {
			cin >> A >> B >> C;
			arrM[A][B] = arrM[B][A] = C;
		}
		for (i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arrM[i][j] == 0) arrM[i][j] = INT_MAX;
			}
		}
		floyd_warwhall(N);
		cin >> P;
		for (i = 0; i < P; i++) {
			cin >> S >> E;
			if (K < arrM[S][E]) Answer++;
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}