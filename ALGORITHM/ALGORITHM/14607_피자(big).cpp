#include <iostream>
using namespace std;

class PizzaBig {
public:
	PizzaBig(int n) {
		cout << seperating(n) << endl;
	}
	long long seperating(long long currentHeight) {
		if (currentHeight == 1) return 0;
		if (currentHeight % 2 == 0) {
			int half = currentHeight / 2;
			return (long long)half*half + (long long)2*seperating(half);
		}
		else {
			int half = currentHeight / 2, halfPlusOne = currentHeight / 2 + 1;
			return (long long)half*halfPlusOne + (long long)seperating(half)
				+ (long long)seperating(halfPlusOne);
		}
	}
};

int main() {
	int N;
	cin >> N;
	new PizzaBig(N);
	return 0;
}