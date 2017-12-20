#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

vector<char> memC, fanC;
vector<int> memInt, fanInt;
unsigned int bitmaskM[6250], bitmaskF[6250];

int main() {
	int testCase, T, N, Answer, i, j;
	unsigned int bitmask;
	char c;
	string memberStr, fanStr;
	freopen("Text.txt", "r", stdin);
	cin >> testCase;
	
	for (T = 0; T < testCase; T++) {
		Answer = 0;
		memset(bitmaskM, 0, sizeof(int) * 6250);
		memset(bitmaskF, 0, sizeof(int) * 6250);
		cin >> memberStr;
		cin >> fanStr;
		int fanNum = fanStr.size(); 
		int memberNum = memberStr.size();

		int bitmaskSize = fanNum / 32;
		string::iterator memberIt(memberStr.begin());
		string::iterator fanIt(fanStr.begin());

		bitmask = 0x80000000;
		for (i = 0;i< memberNum;i++) {
			c=*(memberIt++);
			if (c == 'M') bitmaskM[i / 32] += bitmask;
			bitmask >>= 1;
			if (bitmask == 0) bitmask = 0x80000000;
		}
		bitmask = 0x80000000;
		for (i = 0; i< fanNum; i++) {
			c = *(fanIt++);
			if (c == 'M') bitmaskF[i / 32] += bitmask;
			bitmask >>= 1;
			if (bitmask == 0) bitmask = 0x80000000;
		}

		int compareCnt = fanNum - memberNum + 1;
		for (i = 0; i < compareCnt; i++) {
			j = 0;
			bool test = true;
			do {
				if ((bitmaskF[j] & bitmaskM[j]) != 0) 
					test = false;
				j++;
			} while (j < bitmaskSize);
			if (test) Answer++;
			if (bitmaskSize != 0) {
				for (j = bitmaskSize - 1; j >= 0; j--) {
					bitmaskM[j] >>= 1;
					if (j > 0 && (bitmaskM[j - 1] & 1 == 1)) bitmaskM[j] += 0x80000000;
				}
			}
			else {
				bitmaskM[0] >>= 1;
			}
		}
		cout << Answer << endl;
	}

	return 0;
}