#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int Answer, arrN[300001];

int main(int argc, char** argv)
{
	int T, test_case, N, max;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = max = 0;
		memset(arrN, 0, sizeof(int) * 300001);
		
		cin >> N;
		for (int i = 0; i < N; i++) 
			cin >> arrN[i];
		
		sort(arrN, arrN + N);
		for (int i = 0; i < N; i++) 
			if(arrN[i] + N - i > max) max = arrN[i] + N - i;

		for (int i = 0; i < N; i++) 
			if (arrN[i] +N >= max) Answer++;
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}