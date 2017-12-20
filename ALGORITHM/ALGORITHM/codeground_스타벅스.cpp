#include <iostream>

using namespace std;

int Answer;
int  arrM[21];

int main(int argc, char** argv)
{
	int T, test_case, N, M, K, c_i, p_i;
	freopen("input.txt", "r", stdin);
	
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		memset(arrM, 0, sizeof(int) * 21);
		cin >> N >> M >> K;

		for (int i = 1; i <= N; i++) {
			cin >> c_i;
			arrM[c_i]++;
		}
		for (int i = 1; i <= M; i++) { //save price info
			cin >> p_i;
			arrM[i] *= p_i;
		}
		for (int i = 1; i <= M; i++)
			Answer += arrM[i];

		cout << "Case #" << test_case + 1 << endl;
		if (Answer > K) cout << "N" << endl;
		else cout << "Y" << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}