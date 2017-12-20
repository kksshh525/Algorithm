#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int N[1000], M[1000], result[1000];

bool com(const int &i, const int &j) { return i < j; }

int main()
{
	int n, m, i, j, tmp,num, mi = 1000000, sum =0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &N[i]);
	for (i = 0; i < m; i++)
		scanf("%d", &M[i]);

	sort(N, N + n, com);
	sort(M, M + m, com);

	if (n>m){
		for (i = 0; i < m; i++){
			for (j = 0; j < m; j++){
				tmp = abs(M[i] - N[j]);
				if (mi > tmp){
					mi = tmp;
					num = j;
				}
			}
			if (!result[num])
				result[num] = mi;
			mi = 1000000;
		}
		for (i = 0; i < n; i++)
			sum += result[i];
	}
	else{
		for (i = 0; i < n; i++){
			for (j = 0; j < n; i++){
				tmp = abs(N[i] - M[j]);
				if (mi > tmp){
					mi = tmp;
					num = j;
				}
			}
			if (!result[num])
				result[num] = mi;
			mi = 1000000;
		}
		for (i = 0; i < m; i++)
			sum += result[i];
	}
	
	printf("%d", sum);

	return 0;
}