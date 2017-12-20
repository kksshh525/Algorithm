#include <iostream>
#include <string>
using namespace std;

char c[1000];

string recur(string::iterator &it) {
	char head = *it;
	it++;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string ul = recur(it);
	string ur = recur(it);
	string ll = recur(it);
	string lr = recur(it);

	return string("x") + ll+lr+ul+ur;
}

int main() {
	int testCase, T;
	freopen("Text.txt", "r", stdin);
	cin >> testCase;
	
	for (T = 0; T < testCase; T++) {
		scanf("%s", c);
		string input(c);
		string::iterator str(input.begin());
		cout << recur(str) << endl;
	}

	return 0;
}