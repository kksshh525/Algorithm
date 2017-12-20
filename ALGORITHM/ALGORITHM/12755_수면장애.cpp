#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("Text.txt", "r", stdin);
	int N, i, n = 0;
	cin >> N;

	for (i = 1; n < N; i++)
		n += to_string(i).length();

	string str = to_string(--i);
	cout << str[str.length() - 1 - (n - N)] << endl;

	return 0;
}