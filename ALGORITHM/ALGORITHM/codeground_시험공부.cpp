#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int Answer, N[200001];

int main(int argc, char** argv)
{
	int T, test_case, n,k;
	freopen("Text.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		memset(N, 0, sizeof(N));
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> N[i];
		sort(N, N + n);
		for (int i = n - 1; i >= n-k; i--)
			Answer += N[i];
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}