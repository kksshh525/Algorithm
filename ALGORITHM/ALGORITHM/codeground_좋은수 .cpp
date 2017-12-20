#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int Answer, N, A[5001];

int main(int argc, char** argv)
{
	int T, test_case, i;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		memset(A, 0, sizeof(A));
		cin >> N;
		for (i = 1; i <= N; i++)
			cin >> A[i];


		for (i = 2; i <= N; i++) {
			sort(A + 1, A + i - 1);
			int sum = 0;
			vector<int> v;
			for (int j = i - 1; j > 0; j--) {
				if (A[j] + sum < A[i]) {
					v.push_back(A[j]);
					sum += A[j];
					j++;	//그 숫자 다시 검사
				}
				else if (A[j] + sum == A[i]) {
					v.push_back(A[j]);
					sum += A[j];
					if (v.size() < 3) {
						if (v.size() > 0) {
							sum -= v[v.size() - 1];
							v.pop_back();
							if (j == 1) {
								sum -= v[v.size() - 1];
								v.pop_back();
								j = 2;
							}
						}
					}
					else break;
				}
				else {
					//if (v.size() > 0) {
					//	sum -= v[v.size() - 1];
					//	v.pop_back();
					//}
				}
			}
			if (v.size() == 3 && sum == A[i]) {
				Answer++;
				cout << sum << endl;
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}