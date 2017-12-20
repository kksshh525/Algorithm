#include <iostream>

using namespace std;

int N, K;
int A[101][4];

void sort() {
	int i, j;

	for (i = 1; i <= N - 1; i++) {
		int min = i;
		for (j = i+1; j <= N; j++) {
			if (A[j][3] < A[min][3]) {
				min = j;
			}
			for (int k = 0; k < 4; k++) {
				int tmp = A[min][k];
				A[min][k] = A[i][k];
				A[i][k] = tmp;
			}
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);

	int i, a, b, c;
	cin >> N >> K;

	for (i = 1; i <= N; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
		A[i][3] = A[i][0] + A[i][1] + A[i][2];
	}

	sort();

	a=b=c=0;

	for (i = 1; i <= K; i++) {
		if (a < A[i][0]) a = A[i][0];
		if (b < A[i][1]) b = A[i][1];
		if (c < A[i][2]) c = A[i][2];
	}
	cout << a + b + c << endl;

	return 0;
}