#include <iostream>
#include <string.h>
using namespace std;

class Tiling {
public:
	Tiling() {
		cin >> C;
		for (int testCase = 0; testCase < C; testCase++) {
			memset(cache, -1, sizeof(cache));
			cin >> N;
			cout << dfs(N) << endl;
		}
	}
	int dfs(int n) {
		if (n <= 1) return 1;
		int &ret = cache[n];
		if (ret != -1) return ret;
		return (ret = (dfs(n - 1) + dfs(n - 2))% 1000000007);
	}
private:
	int N, C;
	int cache[101];
};

int main() {
	freopen("Text.txt", "r", stdin);
	new Tiling();
	return 0;
}