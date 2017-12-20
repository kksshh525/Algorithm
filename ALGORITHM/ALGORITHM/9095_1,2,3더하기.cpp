#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

#define N 11
#define K 11
int binom[N][K];
int combination(int n, int k){
	int i, j;
	for (i = 0; i <= n; i++)
		for (j = 0; j < min(i, k), j++)
			if (j == 0 || j == i)
				binom[i][j] = 1;
			else
				binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
	return binom[n][k];
}

int main()
{
	int T, n, i, j, result = 1;
	scanf("%d", &T);
	for (i = 0; i < T; i++){
		scanf("%d", &n);
		for (j = 1; j < n - 1; j++){
			result += combination(n - j, j);
		}
		for (j = 1; j < n; j += 2){

		}
	}

	return 0;
}