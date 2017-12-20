#include <stdio.h>

int N[100001] = { 0, };
int M[100001][2] = { { 0, } ,};

int main()
{
	int a, b, n, m;
	int i, j;
	int min = 100000000;
	int max = 0;

	/*입력값*/
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
		scanf("%d",&N[i]);
	for (i = 1; i <= m; i++)
		scanf("%d %d", &M[i][0], &M[i][1]);
	printf("\n");
	/*연산*/
	for (i = 1; i <= m; i++){
		a = M[i][0];
		b = M[i][1];
		for (j = a; j <= b; j++){
			if (min > N[j]) min = N[j];
			if (max < N[j]) max = N[j];
		}
		printf("%d %d\n", min, max);
		min = 1000000000;
		max = 0;
	}

	return 0;
}