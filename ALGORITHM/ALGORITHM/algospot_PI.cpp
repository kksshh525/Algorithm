#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

#define INF 0x7ffffff0

int N, cache[10002];
string str;

int level(int s, int e) {
	bool level1 = true, level2and5 = true, level4 = true;
	for (int i = s; i < e; i++) {
		if (str[i] != str[i + 1]) {
			level1 = false;
			break;
		}
	}
	if (level1) return 1;

	int term = str[s + 1] - str[s];
	for (int i = s + 1; i < e; i++) {
		if (str[i + 1] - str[i] != term) {
			level2and5 = false;
			break;
		}
	}
	if (level2and5) return (term == 1 || term == -1) ? 2 : 5;

	for (int i = s + 1; i < e; i++) {
		if (str[i - 1] != str[i + 1]) {
			level4 = false;
			break;
		}
	}
	if (level4) return 4;
	else return 10;
}

int dfs(int start) {
	if (start == N) return 0;
	int &ret = cache[start];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 3; i <= 5; i++) {
		if (start + i <= N) {
			ret = min(ret, dfs(start + i) + level(start, start + i - 1));
		}
	}
	return ret;
}

int main() {
	freopen("Text.txt", "r", stdin);
	int C;
	cin >> C;
	getline(cin, str);
	for (int t = 0; t < C; t++) {
		memset(cache, -1, sizeof(cache));
		getline(cin, str);
		N = str.length() - 1;
		if (C == 1)N++;
		cout << dfs(0) << endl;
	}
	return 0;
}