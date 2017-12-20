#include <cstdio>
int student[900];
bool path[900][900];
int out[900];
int K, N, F;
void dfs(int s, int n1, int n2, int c){
	if (out[s]==0) out[s] = 1;
	printf("s:%d n1:%d n2:%d c:%d\n", s, n1, n2, c);
	if (c == K || n2 == N) return;
	if ((student[n1] && student[n2]) && path[n1][n2])
		if (path[s][n2]){
			out[n2] = 1;
			dfs(s, n2, n2 + 1, c + 1);
		}
		else
			dfs(s, n1, n2 + 1, c);
	else
		dfs(s, n1, n2 + 1, c);
}

int main()
{
	int i, j,s1,s2, count = 0;
	scanf("%d %d %d", &K, &N, &F);
	for (i = 0; i < F; i++){
		scanf("%d %d", &s1, &s2);
		path[s1 - 1][s2 - 1] = path[s2-1][s1-1] = true;
		student[s1-1]++;
		student[s2-1]++;
	}
	//친구가 K-1명 이상인 학생 판단
	for (i = 0; i < N; i++){
		if (student[i] >= K - 1)
			student[i] = 1;
		else
			student[i] = 0;
	}

	for (i = 0; i < N; i++){
		dfs(i, i, i+1, 1);
		for (j = 0; j < N; j++)
			if (out[j] == 1) count++;
		if (count < K){
			if (i == N - 1) {
				count = 1000;
				break;
			}
			for (j = 0; j < N; j++)
				out[i] = 0;
			count = 0;
		}
		else
			break;
	}
	if (count == 1000) printf("-1");
	else{
		for (i = 0; i < N; i++)
			if (out[i])
				printf("%d\n", i + 1);
	}
	return 0;
}