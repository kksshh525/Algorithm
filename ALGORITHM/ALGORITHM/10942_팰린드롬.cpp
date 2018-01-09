#include <iostream>
#include <string.h>
using namespace std;

class Palindrome {
public:
	Palindrome() {
		memset(inputNum, 0, sizeof(inputNum));
		for (int i = 0; i < 2001; i++)
			memset(cache[i], -1, sizeof(cache[0]));
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> inputNum[i];
		cin >> M;
		for (int i = 0; i < M; i++) {
			int s, e;
			cin >> s >> e;
			cout << question(s, e) << endl;
		}
	}
	int question(int s, int e) {
		int mid = (s + e) / 2;
		bool isOdd = ((s + e + 1) % 2 == 1) ? true : false;
		if (cache[s][e] == 1) return 1;
		else if (cache[s][e] == 0) return 0;
		int start = s, end = e;
		if (isOdd) {
			while (start<mid && end>mid) {
				cache[start][end] = 0; //지금껏 보던 구간 0
				if (inputNum[start] != inputNum[end])
					break;
				start++; end--;
			}
			if (start == end) { //s~e 구간이 팰린드롬이면 cache 대각선 1 채움
				int sSumE = s + e;
				for (int i = s; i <= mid; i++) {
					for (int j = e; j >= mid; j--) {
						if (s + e == sSumE) cache[i][j] = 1;
						else cache[i][j] = 0;
					}
				}
			}
		}
		else {
			while (start<mid && end>mid + 1) {
				cache[start][end] = 0;
				if (inputNum[start] != inputNum[end])
					break;
				start++; end--;
			}
			if (start + 1 == end) {
				int sSumE = s + e;
				for (int i = s; i <= mid; i++) {
					for (int j = e; j >= mid + 1; j--) {
						if (s + e == sSumE) cache[i][j] = 1;
						else cache[i][j] = 0;
					}
				}
			}
		}
		return cache[s][e];
	}
private:
	int N, M;
	int inputNum[2001];
	int cache[2001][2001];
};

int main() {
	freopen("Text.txt", "r", stdin);
	new Palindrome();
	return 0;
}