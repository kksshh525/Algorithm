#include <stdio.h>

int main()
{
	int A, B, N, M, cur, i, count = 0;
	scanf("%d %d %d %d", &A, &B, &N, &M);
	cur = N;
	if (N<M){
		while (1){
			if (cur*B < M) {
				cur *= B; 
				count++;
				continue;
			}
			if (cur*A < M){
				cur *= A;
				count++;
				continue;
			}
			// B배 ~ A배 사이
			if (cur*B > M && cur*A < M){
				// A배에 가까운 경우
				if (cur*B - M> M - cur*A){
					cur *= A;
					count++;
					for (i = 0; cur + B < M; i++){
						cur += B;
						count++;
					}
					
				}
				// B배에 가까운 경우
				else{
					cur *= A;
					count++;
				}
				continue;
			}
			// A배보다 적게남음
			if (cur*A > M){
				continue;
			}
		}
	}
	return 0;
}