#include <iostream>
#include <time.h>
using namespace std;

int Z, O;
int cache[41][2];

void fibo(int n) {
	if (cache[n][0] != 0) {
		Z += cache[n][0];
		if (n==0) return;
	}
	if (cache[n][1] != 0) {
		O += cache[n][1];
		return;
	}
	fibo(n - 1);
	fibo(n - 2);
	cache[n][0] = cache[n - 1][0] + cache[n - 2][0];
	cache[n][1] = cache[n - 1][1] + cache[n - 2][1];
}

int main() {
	freopen("Text.txt", "r", stdin);
	int N;
	cin >> N;
	cache[0][0] = 1;
	cache[0][1] = 0;
	cache[1][0] = 0;
	cache[1][1] = 1;
	for (int i = 0; i < N; i++) {
		Z = 0; O = 0;
		int tmp;
		cin >> tmp;
		fibo(tmp);
		cout << Z << " " << O << endl;
	}
	return 0;
}