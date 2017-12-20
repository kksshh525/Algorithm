#include <iostream>
#include <algorithm>
using namespace std;

int A[1001],dp[1001];

int main() {
	freopen("Text.txt", "r", stdin);
	int N, i, j;
	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> A[i];
		dp[i] = 1001;
	}
	dp[1] = 0;
	for (i = 1; i < N; i++) {
		if (A[i] == 0) continue;
		int jump = A[i] + i;
		for (j = i+1; j <= jump && j<=N; j++) {
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}
	if (dp[N] == 1001) cout << "-1" << endl;
	else cout << dp[N] << endl;

	for (i = 1; i <= N; i++)
		cout << dp[i] << " ";

	return 0;
}