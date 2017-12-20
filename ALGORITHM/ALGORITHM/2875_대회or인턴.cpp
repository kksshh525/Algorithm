#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int N, M, K, i;
	int n, m, tmp, result = 0;
	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i <= K; i++){
		n = N - (K - i);
		m = M - i;
		tmp = min(n / 2, m);
		if (result < tmp)
			result = tmp;
	}
	printf("%d", result);
	return 0;
}