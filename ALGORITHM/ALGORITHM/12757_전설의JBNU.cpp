#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int index;

int binSearch(int s, int e, int val) {
	while (s <= e) {
		int m = s + e / 2;
		if (val == v[m].first)
			return v[m].first;
		else if (val < v[m].first)
			m = e - 1;
		else
			m = s + 1;
	}
	if (abs(v[s].first - val) < abs(v[s + 1].first - val)) 
		index = s;
	else 
		index = s + 1;

	return v[index].first;
}

int main() {
	freopen("Text.txt", "r", stdin);
	int N, M, K, i, key, value, command;
	cin >> N >> M >> K;
	for (i = 0; i < N; i++) {
		cin >> key >> value;
		v.push_back(make_pair(key, value));
	}
	for (i = 0; i < M; i++) {
		cin >> command;
		bool inserted = false;
		switch (command) {
		case 1:
			cin >> key >> value;
			v.push_back(make_pair(key, value));
			inserted = true;
			break;
		case 2:
			cin >> key >> value;
			if (inserted) {
				sort(v.begin(), v.end());
				inserted = false;
			}
			int binKey = binSearch(0, v.size(), key);
			if (binKey == key)
				v[index].second = value;
			break;
		case 3:
			cin >> key;
			if (inserted) {
				sort(v.begin(), v.end());
				inserted = false;
			}
			int binKey = binSearch(0, v.size(), key);
			break;
		}
	}

	return 0;
}