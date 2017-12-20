#include <cstdio>

int A[50][50];
int W[50], B[50], R[50];

int main()
{
	char tmp;
	int N, M, i, j, W_ = 0, B_ = 0, R_ = 0, sum = 0;
	scanf("%d %d", &N, &M);
	
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++){
			scanf("%c", &tmp);
			switch (tmp){
			case'\n':
				j--;
				break;
			case 'W':
				A[i][j] = 1;
				break;
			case 'B':
				A[i][j] = 2;
				break;
			case 'R':
				A[i][j] = 3;
				break;
			}
		}

	for (i = 0; i < M; i++){
		if (A[0][i] != 1) sum++;
	}

	for (i = 1; i < N-1; i++){
		for (j = 0; j < M; j++){
			if (A[i][j] != 1) W_++;
			if (A[i][j] != 2) B_++;
			if (A[i][j] != 3) R_++;
		}
		W[i] = W_;
		B[i] = B_;
		R[i] = R_;
		W_ = B_ = R_ = 0;
	}
	R[1] = -1;
	W[N - 2] = -1;

	for (i = 0; i < M; i++){
		if (A[0][i] != 3) sum++;
	}

	for (i = 2; i < N - 1; i++){
		if (i != N-2)
			W[i] = W[i - 1] + W[i];
		B[i] = (B[i] + W[i - 1] > B[i] + B[i - 1]) ? B[i] + B[i - 1] : B[i] + W[i - 1];
		if (i != 2)
			R[i] = (R[i] + B[i - 1] > R[i] + R[i - 1]) ? R[i] + R[i - 1] : R[i] + B[i - 1];
		else
			R[i] = R[i] + B[i - 1];
	}
	if (B[i-1] < R[i-1]) sum += B[i-1];
	else sum += R[i-1];

	printf("%d", sum);

	return 0;
}

//정적으로 바꿀 것 : 1쨋줄 흰색, 마지막줄 빨간색, 흰색->파란색으로 바뀌는 줄 파란색.
//중간계산 : 둘쨋줄을 전부 흰색/파란색 으로 할 경우 흰/파/빨 개수
//                  셋째줄을 전부 흰색/파란색/빨간색으로 할 경우 흰/파/빨 개수