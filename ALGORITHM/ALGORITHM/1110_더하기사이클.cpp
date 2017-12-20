#include <iostream>
using namespace std;

int N;

int cycle(int input) {
	int div = 0,  tmp = input;
	for (; tmp > 0; ) {
		div += tmp % 10;
		tmp /= 10;
	}
	return (input % 10)*10 + div%10;
}

int main() {
	cin >> N;
	int tmp = N, count = 0;
	for (;;) {
		if (N == 0) {
			count = 1;
			break;
		}
		tmp = cycle(tmp);
		count++;
		if (tmp == N) break;
	}
	cout << count << endl;
	return 0;
}