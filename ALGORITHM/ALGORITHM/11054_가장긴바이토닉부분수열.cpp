#include <iostream>
#include <algorithm>
using namespace std;

int dp[1002][2];
int A[1001];

int main() {
	freopen("Text.txt", "r", stdin);
	int N, i, j;
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> A[i];
	
	for (i = 1; i <= N; i++) {
		int cnt = 0;
		for (j = i - 1; j >= 0; j--) {
			if (A[i] > A[j]) cnt = max(cnt, dp[j][0]);
		}
		dp[i][0] = cnt + 1;
	}
	for (i = N; i > 0; i--) {
		int cnt = 0;
		for (j = i+1; j <= N; j++) {
			if (A[i] > A[j]) cnt = max(cnt, dp[j][1]);
		}
		dp[i][1] = cnt + 1;
	}

	int m = 0;
	for (i = 1; i <= N; i++) {
		m = max(m, dp[i][0] + dp[i][1]);
	}
	cout << m - 1 << endl;

	return 0;
}