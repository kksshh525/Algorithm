#include <cstdio>

int P[1001];
int DP[1001][1001];

int main()
{
	int N, i, j, k, l, res, tmp, max;
	float d =0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &P[i]);

	for (i = 1; i <= N; i++)
		DP[1][i] = P[1]*i;

	for (i = 2; i <= N; i++){
		for (j = 1; j <= N; j++){
			if (j%i == 0){
				tmp = P[i]*(j/i);
				DP[i][j] = (DP[i - 1][j]>tmp) ? DP[i - 1][j] : tmp;
			}
			else if(j > (i*(N/i)) && j-(i*(N/i)) < i){
				l = j - (N - i);
				max = 0;
				res = 0;
				tmp = l;
				//for (k = 1; k < l; k++)
				//	if (k%l == 0 && max < DP[k][k])
				//		max = DP[k][k];
				for (k = 1; tmp != 0; k++){
					
				}
				tmp = DP[i][j - 1] + max;
				DP[i][j] = (tmp > DP[i - 1][j]) ? tmp : DP[i - 1][j];
				continue;
			}
			else
				DP[i][j] = DP[i-1][j];
		}
	}
	
	printf("%d", DP[N][N]);

	return 0;
}