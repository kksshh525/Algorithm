#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, A[501], dp[501];//,cache[501];

/*
int dfs(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = start + 1; i < N; i++) {
		if (A[start] < A[i])
			ret = max(ret, dfs(i) + 1);
	}
	return ret;
}*/

int DP(void) {
	for (int i = 0; i < N; i++) {
		int mx = 0;
		for (int j = i; j >= 0; j--) {
			if(A[i] > A[j]) mx = max(dp[j],mx);
			dp[i] = mx + 1;
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++)
		ret = max(ret, dp[i]);
	return ret;
}

int main() {
	int testCase, T;
	freopen("Text.txt", "r", stdin);
	cin >> testCase;
	for (T = 0; T < testCase; T++) {
		memset(A, 0, sizeof(A));
		//memset(cache, -1, sizeof(cache));
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) 
			cin >> A[i];
		cout << DP() << endl;
	}
	return 0;
}