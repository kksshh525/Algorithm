#include <cstdio>
#include <algorithm>
using namespace std;

int aN[500000], aM[500000];
int l, r, m, N, M;

int binarySearch(int n){
	l = 0; r = N - 1;
	while (1){
		m = (l + r) / 2;
		if (n == aN[m]) 
			return 1;
		else if (n < aN[m])
			r = m - 1;
		else
			l = m + 1;

		if (l >= r){
			if (n == aN[l]) return 1;
			else return 0;
		}
	}
}

int main()
{
	int i;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &aN[i]);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
		scanf("%d", &aM[i]);

	sort(aN, aN + N);

	for (i = 0; i < M;i++)
		printf("%d ", binarySearch(aM[i]));

	return 0;
}