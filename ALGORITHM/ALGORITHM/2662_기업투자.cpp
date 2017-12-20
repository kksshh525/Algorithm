#include <iostream>
#include <algorithm>
using namespace std;

int N, M;	//N:투자금, M:기업수
int A[301][21];
int dp[301][21];

int main() {
	freopen("Text.txt", "r", stdin);
	int i, j, k;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
		for (j = 0; j <= M; j++)
			cin >> A[i][j];
	
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i][j - 1], A[i][j]);
			for (k = 1; k < i; k++)
				dp[i][j] = max(dp[i][j], A[i - k][j] + dp[k][j - 1]);
		}
	}
	cout << dp[N][M] << endl;

	return 0;
}