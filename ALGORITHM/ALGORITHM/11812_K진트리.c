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
������ S ������ D
�� ���� �θ� ������ �� ���� �ɸ� Ƚ��

K�� Ʈ������ �����ؿ� �ִ��� �ƴ� �����..?

							1
			...	K-1		K		K+1 ...
K(K-1)-1, K(K-1), ...

St // Stemp
Sh // Shigh
Ss = 1 // Sh�� ���� ���� ��� ��
Sd // Ss�� ���� S���� ���ʿ��� ���°����

St = S;
for (i=0;St>0;i++)
	St -= K^i;
Sh = i	//i�� S�� ����.
for(i=0;Ss<S;i++)
	Ss += K^i;
if (S != 1) 
	Ss -= K^(i-1);

*/