#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
	int N, i, j, max = 0, tmp = 0;
	int P[1000] = { 0, };

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &P[i]);
	for (i = 0; i < N - 1; i++){
		for (j = i; j < N; j++){
			if (P[j] >= P[j + 1]) break;
			tmp += P[j + 1] - P[j];
		}
		if (max < tmp) max = tmp;
		i = j;
		tmp = 0;
	}
	printf("%d", max);
	return 0;
}