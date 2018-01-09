#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define MOD 1000000

class CryptoCode {
public:
	CryptoCode() {
		string str;
		getline(cin, str);
		inputLength = str.length();
		for (int i = 0; i < inputLength; i++)
			input.push_back(str[i] - '0');
		memset(dp, 0, sizeof(dp));
		cout << countCase() << endl;
	}
	int countCase() {
		if (inputLength == 1 && input[0] == 0) return 0;
		dp[0] = dp[1] = 1;
		for (int i = 1; i < inputLength; i++) {
			if (input[i - 1] > 2) {
				if (input[i] == 0) return 0;
				dp[i + 1] = dp[i];
			}
			else if (input[i - 1] == 2 && input[i] >6)
				dp[i + 1] = dp[i];
			else if (input[i] == 0) {
				if (input[i - 1] == 0) return 0;
				dp[i + 1] = dp[i - 1];
			}
			else if (input[i - 1] == 0) dp[i + 1] = dp[i];
			else dp[i + 1] = (dp[i] + dp[i - 1]) % MOD;
		}
		return dp[inputLength];
	}
private:
	vector<int> input;
	int dp[5001];
	int inputLength;
};

int main() {
	freopen("Text.txt", "r", stdin);
	new CryptoCode();
	return 0;
}