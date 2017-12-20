#include <cstdio>

int A[50][3];
int N, M;

int BFS(int color, int round){
	int change, t1, t2;
	if (round == N)
		return (M - A[N-1][color]);
	if (color == 0) {
		if (round == N - 2) 
			change = BFS(1, round + 1);
		else{
			t1 = BFS(0, round + 1);
			t2 = BFS(1, round + 1);
			change = (t1 < t2) ? t1 : t2;
		}
	}
	else if (color == 1){
		if (round == N - 1)
			change = BFS(2, round + 1);
		else{
			t1 = BFS(1, round + 1);
			t2 = BFS(2, round + 1);
			change = (t1 < t2) ? t1 : t2;
		}
	}
	else
		change = BFS(2, round + 1);

	return ((M - A[round-1][color]) + change);
}

int main()
{
	char tmp;
	int i, j, result;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++){
			scanf("%c", &tmp);
			switch (tmp){
			case'\n':
				j--;
				break;
			case 'W':
				A[i][0]++;
				break;
			case 'B':
				A[i][1]++;
				break;
			case 'R':
				A[i][2]++;
				break;
			}
		}
	result = BFS(0, 1);
	printf("%d", result);
	return 0;
}