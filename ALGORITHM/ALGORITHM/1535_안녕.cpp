#include <iostream>
#include <algorithm>
using namespace std;

int A[21], B[21];
int dp[21][101];

int main() {
	freopen("Text.txt", "r", stdin);
	int N, i, j;
	
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> A[i];
	for (i = 1; i <= N; i++)
		cin >> B[i];

	for (i = 1; i <= N; i++) {
		for (j = 0; j < 100; j++) {
			if (j - A[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], B[i] + dp[i - 1][j - A[i]]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][99] << endl;
	return 0;
}