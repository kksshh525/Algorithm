#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[4], b[2];
	scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &b[0], &b[1]);
	sort(a, a+4);
	sort(b, b+2);
	printf("%d", a[1] + a[2] + a[3] + b[1]);

	return 0;
}