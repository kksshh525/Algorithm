#include <iostream>
#include <string.h>
using namespace std;

int FENCE[20000];

int divide_conquar(int left, int right) {
	if (left == right) return FENCE[left];
	int leftSum, rightSum, subSum, mid, area, tmpH, tmpW, tmpArea, i, j;
	mid = (left + right) / 2;
	leftSum = divide_conquar(left, mid);
	rightSum = divide_conquar(mid + 1, right);
	subSum = (leftSum > rightSum) ? leftSum : rightSum;

	tmpH = (FENCE[mid] < FENCE[mid + 1]) ? FENCE[mid] : FENCE[mid + 1];
	tmpW = 2;
	area = tmpArea = tmpH*tmpW;
	for (i = tmpH; i > 0; i--) {
		tmpW = 2;
		
		for (j = 1; (mid - j >= left) && (FENCE[mid - j] >= i); j++)
			++tmpW;
		
		for (j = 1; (mid + 1 + j <= right) && (FENCE[mid + 1 + j] >= i); j++)
			++tmpW;
		tmpArea = tmpW*i;
		if (area < tmpArea) area = tmpArea;
	}

	return (subSum > area) ? subSum : area;
}

int main() {
	int testCase, T, N;
	freopen("Text.txt", "r", stdin);
	cin >> testCase;
	for (T = 0; T < testCase; T++) {
		memset(FENCE, 1, sizeof(int) * 20000);
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> FENCE[i];
		cout << divide_conquar(0, N - 1) << endl;
	}

	return 0;
}