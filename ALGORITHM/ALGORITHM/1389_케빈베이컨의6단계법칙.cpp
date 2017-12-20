#include <stdio.h>
#include <iostream>
using namespace std;

int fnd[5000][2] = { { 0, }, };
int n[101][101] = { { 0, }, };
int result[101][101] = { { 0, }, };
int c = 1;
int N, M;

void recur(int i,int j){
	if ((i != N && j != N) && i == j) recur(i, j + 1);
	if (c != 1 && result[i][j] > c) result[i][j] = c;
	if ((i == N && j == N) || (n[i][j] == 1)) {
		if (c == 1) {
			result[i][j] = 0;
			return;
		}
		else recur(j,1);
	}
	else if(n[i][j] == 0){
		c++;
		if (i < N) recur(i, j + 1);
		else recur(i + 1, j);
	}
}

int main()
{
	int i, j;

	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d", &fnd[i][0], &fnd[i][1]);
		n[fnd[i][0]][fnd[i][1]]++;
		n[fnd[i][1]][fnd[i][0]]++;
	}
	recur(1, 1);

	return 0;
}