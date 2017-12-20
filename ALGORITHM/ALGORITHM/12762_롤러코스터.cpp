#include <iostream>
using namespace std;

int dp[1001][2], A[1001];

int main() {
	freopen("Text.txt", "r", stdin);
	int N, i, j, Answer = 0;
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> A[i];
	for (i = 1; i <= N; i++) {
		int mx = 0;
		for (j = i - 1; j >= 1; j--) {
			if (A[i] < A[j] && mx < dp[j][0]) 
				mx = dp[j][0];
		}
		dp[i][0] = mx + 1;
	}
	for (i = N; i > 0; i--) {
		int mx = 0;
		for (j = i + 1; j <= N; j++) {
			if (A[i] < A[j] && mx < dp[j][1])
				mx = dp[j][1];
		}
		dp[i][1] = mx + 1;
	}
	for (i = 1; i <= N; i++) {
		int tmp = dp[i][0] + dp[i][1];
		if (Answer < tmp)
			Answer = tmp;
	}
	cout << Answer - 1 << endl;
	return 0;
}