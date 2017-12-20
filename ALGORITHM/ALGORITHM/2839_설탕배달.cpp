#include <iostream>
#include <algorithm>
using namespace std;
#define MAX  5001

int A[5001];

int main() {
	freopen("Text.txt", "r", stdin);
	int N, i;
	cin >> N;

	if (N == 3 || N == 5) {
		cout << "1" << endl;
		return 0;
	}
	else if (N < 5) {
		cout << "-1" << endl;
		return 0;
	}

	for (i = 0; i <= N; i++)
		A[i] = MAX;

	A[3] = A[5] = 1;
	for (i = 3; i <= N; i++) {
		if (A[i] == MAX) continue;
		if (i + 3 <= N) A[i + 3] = min(A[i + 3], A[i] + 1);
		if (i + 5 <= N) A[i + 5] = min(A[i + 5], A[i] + 1);
	}

	if (A[N] != MAX)
		cout << A[N] << endl;
	else
		cout << "-1" << endl;

	return 0;
}