#include <cstdio>

int A[100];

int main()
{
	int N, M, i, j, tmp;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 1; i <= M; i++){
		for (j = 0; j < N - 1; j++){
			if (A[j] % i > A[j + 1] % i){
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < N-1; i++)
		printf("%d \n", A[i]);
	printf("%d", A[i]);
	return 0;
}