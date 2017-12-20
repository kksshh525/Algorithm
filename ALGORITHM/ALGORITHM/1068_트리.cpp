#include <iostream>
#include <queue>
using namespace std;

int A[51],B[51];

int main() {
	freopen("Text.txt", "r", stdin);
	int N, del, i, j, Answer = 0;
	queue<int> q;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0) {
			continue;
		}
		B[A[i]]++;
	}
	cin >> del;

	q.push(del);
	while(q.size()>0){
		int cur = q.front();
		q.pop();
		for (j = 0; j < N; j++) {
			if (A[j] == cur)
				q.push(j);
		}
		if (A[cur] >= 0)
			B[A[cur]]--;
		B[cur] = -2;
	}

	for (i = 0; i < N; i++) {
		if (B[i] == 0) {
			Answer++;
		}
	}
	cout << Answer << endl;
	return 0;
}