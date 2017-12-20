#include <iostream>
#include <algorithm>
#include <string.h>
#include <time.h>
using namespace std;

int N, T[101][101], cache[101][101];

int dfs(int x, int y) {
	int& ret = cache[x][y];
	if (ret != -1) 
		return ret;
	if (x == N - 1) return ret = T[x][y];
	return ret = (T[x][y] + max(dfs(x + 1, y), dfs(x + 1, y + 1)));
}

int main(){
	freopen("Text.txt", "r", stdin);
	time_t b, e;
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		for (int i = 0; i < 101; i++) {
			memset(T[i], 0, sizeof(T[i]));
			memset(cache[i], -1, sizeof(cache[i]));
		}
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++)
				cin >> T[i][j];
		b = clock();
		cout<<dfs(0, 0)<<endl;
		e = clock();
		cout << (double)(e - b) / CLOCKS_PER_SEC << endl;
	}
	return 0;
}