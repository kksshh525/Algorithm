#include <iostream>
#include <string.h>
using namespace std;

int Answer, N, M, arrN[200][200];

int main(int argc, char** argv)
{
	int T, test_case, tmp1, tmp2;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 1;
		for (int i = 0; i < 200; i++)
			memset(arrN[i], 0, sizeof(int) * 200);

		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> tmp1 >> tmp2;
			arrN[--tmp1][--tmp2] = 1;
		}
		tmp1 = tmp2 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				tmp1 += arrN[i][j];
				if (tmp1 > 1 && arrN[i][j] == 1) {
					for (int k = i+1; k != j; k++) {
						if (arrN[k][j] == 1) {
							Answer = 0;
							break;
						}
					}
				}
				if (Answer == 0) break;
			}
			tmp1 = 0;
			if (Answer == 0) break;
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}