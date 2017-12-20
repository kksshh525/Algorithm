#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, C6[50], C1[50];

int main()
{
	int i, six, one, result, t1, t2, t3;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
		scanf("%d %d", &C6[i], &C1[i]);
	sort(C6, C6 + M);
	sort(C1, C1 + M);
	six = N / 6;
	one = N % 6;
	if (N < 6){
		if (C6[0] > C1[0] * N)
			result = C1[0] * N;
		else
			result = C6[0];
	}
	else{
		t1 = (six + 1)*C6[0];				//6set으로만 사는경우
		t2 = six*C6[0] + one*C1[0];	//섞어서 사는경우
		t3 = C1[0] * N;						//1개씩만 사는경우
		result = min(min(t1, t2), t3);
	}
	printf("%d", result);
	return 0;
}