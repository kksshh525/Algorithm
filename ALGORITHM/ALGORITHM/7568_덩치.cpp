#include <iostream>
using namespace std;

int x[51], y[51], A[51];

int main() {
	freopen("Text.txt", "r", stdin);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (x[i] < x[j] && y[i]<y[j])
					A[i]++;
		}
	}

	for (int i = 1; i < N; i++)
		cout << A[i]+1 << " ";
	cout << A[N]+1;
	return 0;
}