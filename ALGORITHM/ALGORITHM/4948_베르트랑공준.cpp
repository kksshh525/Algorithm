#include <iostream>
#include <vector>
using namespace std;

bool A[246913];

int main() {
	freopen("Text.txt", "r", stdin);
	vector<int> v;
	int tmp, N;
	cin >> tmp;
	while (tmp != 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
	N = v.size();
	tmp = 0;
	for (int i = 0; i < N; i++)
		if (tmp < v[i]) tmp = v[i];

	N = tmp*2;

	for (int i = 2;i <= N;i++) {
		if (A[i]) continue;
		for (int j = i*2; j<=N; j += i) {
			if (!A[j]) A[j] = true;
		}
	}

	A[1] = true;
	tmp = v.size();
	for (int i = 0; i < tmp; i++) {
		int cnt = 0, j2 = v[i]*2;
		for (int j = v[i]+1; j <= j2; j++) 
			if (!A[j]) cnt++;
		cout << cnt << endl;
	}
	
	return 0;
}