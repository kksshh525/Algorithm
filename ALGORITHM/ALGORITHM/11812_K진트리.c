#include <stdio.h>



int main()
{
	int i, j;
	int N, K, Q;
	int n1, n2;

	scanf("%d %d %d", &N, &K, &Q);

	for (i = 0; i < Q; i++){
		scanf("%d %d", &n1, &n2);
		
	}

	return 0;
}

/*
시작점 S 도착점 D
두 값의 부모가 같아질 때 까지 걸린 횟수

K진 트리에서 누구밑에 있는지 아는 방법은..?

							1
			...	K-1		K		K+1 ...
K(K-1)-1, K(K-1), ...

St // Stemp
Sh // Shigh
Ss = 1 // Sh의 가장 왼쪽 노드 값
Sd // Ss로 부터 S까지 왼쪽에서 몇번째인지

St = S;
for (i=0;St>0;i++)
	St -= K^i;
Sh = i	//i가 S의 높이.
for(i=0;Ss<S;i++)
	Ss += K^i;
if (S != 1) 
	Ss -= K^(i-1);

*/