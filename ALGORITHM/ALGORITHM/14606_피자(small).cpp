#include <iostream>
using namespace std;

class PizzaSmall {
public:
	PizzaSmall(int n) {
		cout << seperating(n) << endl;
	}
	int seperating(int currentHeight) {
		if (currentHeight == 1) return 0;
		int left = currentHeight / 2;
		int right = currentHeight - left;
		return left*right + seperating(left) + seperating(right);
	}
};

int main() {
	int N;
	cin >> N;
	new PizzaSmall(N);
	return 0;
}