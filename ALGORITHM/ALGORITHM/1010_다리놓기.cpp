#include <iostream>
#include <string.h>
using namespace std;

class Bridge {
public:
	Bridge(int N, int M) {
		if (N == 1) cout << M << endl;
		else {
			for (int i = 0; i < 31; i++)
				memset(cache[i], -1, sizeof(cache[0]));
			cout << combination(M, N) << endl;
		}
	}
	unsigned long long combination(int N, int R) {
		if (R == 0 || N == R) return 1;
		unsigned long long &ret = cache[N][R];
		if (ret != -1) return ret;
		return ret = (combination(N - 1, R - 1) + combination(N - 1, R));
	}
private:
	unsigned long long cache[31][31];
};

int main() {
	freopen("Text.txt", "r", stdin);
	int C, N, M;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> M;
		new Bridge(N, M);
	}
	return 0;
}