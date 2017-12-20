#include <iostream>
#include <algorithm>
using namespace std;

int dpMin[100001][3];
int dpMax[100001][3];

int main(){
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dpMin[i][0] >> dpMin[i][1] >> dpMin[i][2];
		dpMax[i][0] = dpMin[i][0];
		dpMax[i][1] = dpMin[i][1];
		dpMax[i][2] = dpMin[i][2];
	}

	for (int i = 2; i <= N; i++) {
		dpMin[i][0] += min(dpMin[i - 1][0], dpMin[i - 1][1]);
		dpMin[i][1] += min(min(dpMin[i - 1][0], dpMin[i - 1][1]), dpMin[i - 1][2]);
		dpMin[i][2] += min(dpMin[i - 1][1], dpMin[i - 1][2]);
		dpMax[i][0] += max(dpMax[i - 1][0], dpMax[i - 1][1]);
		dpMax[i][1] += max(max(dpMax[i - 1][0], dpMax[i - 1][1]), dpMax[i - 1][2]);
		dpMax[i][2] += max(dpMax[i - 1][1], dpMax[i - 1][2]);
	}
	cout << max(max(dpMax[N][0], dpMax[N][1]), dpMax[N][2]) << " " << min(min(dpMin[N][0], dpMin[N][1]), dpMin[N][2]);
	return 0;
}