#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	freopen("Text.txt", "r", stdin);
	int N, i, tmp;
	cin >> N;
	
	for (i = N-1; i > 0; i--) {
		if (i * 3 <= N)
			tmp =  min(dp[i * 3], min(dp[i * 2], dp[i + 1]));
		else if (i * 2 <= N)
			tmp = min(dp[i * 2], dp[i + 1]);
		else
			tmp = dp[i + 1];
		dp[i] = tmp + 1;
	}
	cout << dp[1] << endl;

	return 0;
}