#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N, Answer;

void dfs() {
	int size = v.size();
	for (int i = 0; i < size; i++) {
		int cnt = 0;
		for (int j = 0; j < size; j++) {
			if (v[j] == i) cnt++;
			if (v[i] < cnt) return;
		}
	}
	if (size == N) {
		int tmp = 0;
		for (int i = 0; i < size; i++)
			tmp += v[i];
		if (tmp == N) {
			Answer++;
			for (int i = 0; i < size; i++)
				cout << v[i] << " ";
			cout << endl;
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		v.push_back(i);
		dfs();
		v.pop_back();
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	int testCase, i;
	cin >> testCase;
	for (int T = 0; T < testCase; T++) {
		cin >> N;
		Answer = 0;
		v.clear();
		for (int i = 1; i < N; i++) {
			v.push_back(i);
			dfs();
			v.pop_back();
		}
		cout << Answer << endl;
	}
	return 0;
}