#include <iostream>
#include <algorithm>
using namespace std;

int A[301];
int dp[301][2];

int main() {
	freopen("Text.txt", "r", stdin);
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];

	dp[0][0] = A[0];
	dp[0][1] = 0;
	dp[1][0] = A[0] + A[1];
	dp[1][1] = A[1];

	for (i = 2; i < N; i++) {
		dp[i][0] = dp[i - 1][1]+A[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + A[i];
	}
	cout << max(dp[N - 1][0], dp[N - 1][1]) << endl;

	return 0;
}