#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n = 0;
int input[101][101];
int output[101][101];
int visit[101];

void dfs(int start, int cur){
	for (int k = 1; k <= n; k++){
		if (input[cur][k] == 1 && visit[k] != start){	//다음 위치가 갈 수 있으면서 방문하지않았으면 방문
			output[start][k] = 1;
			visit[k] = start;
			dfs(start, k);
		}
	}
}

int main()
{
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &input[i][j]);
	
	for (i = 1; i <= n;i++)
		dfs(i, i);

	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}

	return 0;
}